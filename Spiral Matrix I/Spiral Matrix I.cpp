/*
作者：unclechen
博客：http://blog.csdn.net/nought03/article/details/39814195 
Spiral Matrix,旋转数组I：输入n,输出一个二维矩阵,顺/逆时针由内向外每一层的元素值从1->n. 

case:
输入
9
输出
1 2 3
8 9 4
7 6 5

逆时针输出：
1 8 7
2 9 6
3 4 5
--------------------------------------------------------------
以顺时针为例 
思路1：模拟操作法，O(n*n)的空间复杂度
 
思路2：找规律法，O(1)的空间复杂度 
--------------------------------------------------------------- 
*/ 
#include <iostream>
#include <cmath>
using namespace std;
/*
思路1-1：开辟一个二维矩阵，然后采用边界夹逼的方法来给二维矩阵中每一个元素赋值，在lee,剑指offer中出现过多次。 
第0层（此处为最外面一层）的边界： 
beginX=0; endX=n-1; 
beginY=0; endY=n-1;
此后不断增加beginX和beginY，不断减小endX和endY知道begin和end相遇为止。
*/
void printSpiralMatrixOutsideToInsideI(int n) {
	if (0 == n) return;
	int **a; // 动态分配二维数组的内存，声明一个指向数组的指针  
	a = new int*[n];
	for (int i = 0; i < n; ++i) {
		a[i] = new int[n];
	}
	int beginX = 0;
	int endX = n-1;
	int beginY = 0;
	int endY = n-1;
	int val = 1; 
	while (true) {
		for (int i = beginX; i <= endX; ++i) {
			a[beginY][i] = val++;
		}
		if (++beginY > endY) {
			break;
		}
		for (int i = beginY; i <= endY; ++i) {
			a[i][endX] = val++;
		}
		if (--endX < beginX) {
			break;
		}
		for (int i = endX; i >= beginX; i--) {
			a[endY][i] = val++;
		}
		if (--endY < beginY) {
			break; 
		} 
		for (int i = endY; i >= beginY; i--) {
			a[i][beginX] = val++;
		}
		if (++beginX > endX) {
			break;
		}
	}
	// 打印出二维数组 
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << a[i][j] << "\t";
		}
		cout << endl; 
	}
	// 释放二维数组的内存 
	for(int i = 0; i < n; ++i)  
    	delete[] a[i];  
	delete[] a;
} 
// 思路1-2：另一种是模拟坐标移动(x, y) 
void printSpiralMatrixOutsideToInsideII(int n) {
	if (0 == n) return;
	int **a; // 动态分配二维数组的内存，声明一个指向数组的指针  
	a = new int*[n];
	for (int i = 0; i < n; ++i) {
		a[i] = new int[n];
	}
	int x = 0; // 从外向内打印时的初始坐标 
	int y = 0;
	int val = 1; // val从1递增到n*n，对应着每一个元素的值 
	a[x][y] = val; // 摆放第一个元素1 
	int width = n-1; // 记录当前方向应该走过的步数,其实也是螺旋矩阵中每一层元素的边长,初识的width很重要 
	int count = 0; // 记录当前方向已经走过的步数 
	int dir = 0; // 记录当前移动的方向 
	int dir_change_count = -1; // 记录方向改变的次数，当它为2的倍数时，width要增减1;但此处的width初始值不算在方向改变中 
	while (val < n * n) {
		switch(dir) {
			case 0: // 向右 
				++y;
				break;
			case 1: // 向下 
				++x;
				break;
			case 2: // 向左 
				--y;
				break;
			case 3: // 向上 
				--x;
				break;
		}
		a[x][y] = ++val;
		if (++count == width) { // 走完了一个方向上的坐标，count重置 
			count = 0;
			dir = (dir + 1) % 4; // dir+=1，说明改变了一次方向
			if(++dir_change_count!=0 && dir_change_count % 2 == 0) { // 改变方向次数是2的倍数时，需要修改width边长 
				--width;
			}  
		}
	}
	// 打印出二维数组 
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << a[i][j] << "\t";
		}
		cout << endl; 
	}
	// 释放二维数组的内存 
	for(int i = 0; i < n; ++i)  
    	delete[] a[i];  
	delete[] a;
}

// 思路2 找规律 
/*
将矩阵从外向内（内向外） 分层（level）,每一层中的元素是一个顺时针的递增序列。
确定这一圈元素的起始值begin，然后逐个计算出一圈中的每一个元素值。 
需要用到以下几个参数：
层次level：i<=j时,level = min(i,w-1-j); i<j时,level=min(j,w-1-i) 
每一层的边长width：width = n-2*level
每一层的起始元素的值：begin = 4*level*(n-level)+1,  4*level*(n-level)是第level层之外的层次（0->level-1）的元素个数的和
这个值的计算由，4*width-4（计算0->level-1层的所有元素之和得到，其实就是一个等差数列的求和） 

因此：对于每一圈的元素而言，上边、右边、下边、左边的元素值计算公式为：
上：i <= j && level = i : a[i][j] = begin + j - level
右：i <= j && level = n-1-j : a[i][j] = begin + (width-1) + i - level
下：i > j && level = n-1-i : a[i][j] = begin + 2*(width-1) + (n - 1 - level - j)
左：i > j && level = j : a[i][j] = begin + 3*(width-1) + (n - 1 - level - i)
*/ 
void printSpiralMatrixOutsideToInsideIII(int n) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			int level;
			if (i <= j) {
				level = min(i, n-j-1);
			}	
			else {
				level = min(j, n-i-1);
			}
			
			int width = n - 2 * level;
			int begin = 4 * level * (n - level) + 1;
			int val;
			if (i <= j && level == i) { // 上边 
				val = begin + j - level;
			} 
			if (i <= j && level == n-1-j) { // 右边 
				val = begin + (width-1) + i - level;
			}
			if (i > j && level == n-1-i) { // 下边 
				val = begin + 2*(width-1) + (n - 1 - level - j);
			}
			if (i > j && level == j) { // 左边 
				val = begin + 3*(width-1) + (n - 1 - level - i);
			} 
			cout << val << "\t";
		}
		cout << endl;
	} 
	
}
// 变种：从内到外打印
/*
以顺时针为例
7     8    9   10
6     1    2   11
5     4    3   12
16   15   14   13

思路1：模拟从内向外螺旋打印的过程，这里就不能再用像从外向内的那种边界夹逼的方法，因为四个参数不好控制边界。
应该用坐标移动的思想，二维数组看成一个坐标轴，(0,0)是原点，x轴方向向右，y轴方向向下。 
设置一个direction参数，int dir = (0, 1, 2, 3)%4, 代表向右，向下，向左和向上四个方向。 

关键点：通过观察规律，发现在每一个方向上，x或者y坐标（只有其中之一移动）移动的步数为1, 1, 2, 2, 3, 3, 4, 4 ...
把每个方向上可以前进的步数用width表示，每当dir改变两次是，width就增加1（1,1,2,2,3,3,4,4...） 

代码很好写： 
初始状态是坐标 x,y=(n-1)/2, a[x][y]=1; dir = 0, width = 1; 

思路2：还是O(1)的空间复杂度，这里需要做一点变化，思路还是要找到一个begin（层数为双数时在左下角，单数时在右上角）
begin的计算还是通过计算（这里是该层以内的所有层出现了一共多少个元素，也是一个等差数列求和） 
然后通过判断元素a[i][j]在不同的边上（上、下、左、右），来推算该元素a[i][j]的值。 这里就不计算了 
 
*/ 
// 思路1代码实现 
void printSpiralMatrixInsideToOutside(int n) {
	if (0 == n) return;
	int **a; // 动态分配二维数组的内存，声明一个指向数组的指针  
	a = new int*[n];
	for (int i = 0; i < n; ++i) {
		a[i] = new int[n];
	}
	int x = (n - 1) / 2; // 从内向外打印时的初始坐标 
	int y = (n - 1) / 2;
	int val = 1; // val从1递增到n*n，对应着每一个元素的值 
	a[x][y] = val; // 摆放第一个元素1 
	int width = 1; // 记录当前方向应该走过的步数,其实也是螺旋矩阵中每一层元素的边长 
	int count = 0; // 记录当前方向已经走过的步数 
	int dir = 0; // 记录当前移动的方向 
	int dir_change_count = 0; // 记录方向改变的次数，当它为2的倍数时，width要增加1 
	while (val < n * n) {
		switch(dir) {
			case 0: // 向右 
				++y;
				break;
			case 1: // 向下 
				++x;
				break;
			case 2: // 向左 
				--y;
				break;
			case 3: // 向上 
				--x;
				break;
		}
		a[x][y] = ++val;
		if (++count == width) { // 走完了一个方向上的坐标，count重置 
			count = 0;
			dir = (dir + 1) % 4; // dir+=1，说明改变了一次方向
			if(++dir_change_count % 2 == 0) { // 改变方向次数是2的倍数时，需要修改width边长 
				++width;
			}  
		}
	}
	// 打印出二维数组 
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << a[i][j] << "\t";
		}
		cout << endl; 
	}
	// 释放二维数组的内存 
	for(int i = 0; i < n; ++i)  
    	delete[] a[i];  
	delete[] a;
}

// 这道题目的顺时针和逆时针变种没有什么难度，仅仅将坐标移动的方向做一下修改即可实现。 

// 测试用例 
int main() {
	int n;
	cout << "请输入一个数字n：" << endl; 
	cin >> n;
	
	cout << "从外向内，顺时针打印螺旋矩阵（思路1-1：边界控制法，O(n*n)的空间复杂度内）" << endl; 
	printSpiralMatrixOutsideToInsideI(n); 
	cout << endl;
	
	cout << "从外向内，顺时针打印螺旋矩阵（思路1-2：坐标模拟法，O(n*n)的空间复杂度内）" << endl; 
	printSpiralMatrixOutsideToInsideII(n); 
	cout << endl;
	
	cout << "从外向内，顺时针打印螺旋矩阵（思路2：推算法，O(1)的空间复杂度内）" << endl; 
	printSpiralMatrixOutsideToInsideIII(n); // 从外向内，顺时针 
	cout << endl;
	
	cout << "从内向外，顺时针打印螺旋矩阵（内向外变种：坐标模拟法，O(n*n空间复杂度内)）" << endl; 
	printSpiralMatrixInsideToOutside(n); // 从内向外，顺时针 
	
	return 0;
}
