/*
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

以顺时针为例 
思路1：O(n*n)的空间复杂度
开辟一个二维矩阵，然后采用边界夹逼的方法来给二维矩阵中每一个元素赋值，在lee,剑指offer中出现过多次。 

思路2：O(1)的空间复杂度 
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

#include <iostream>
#include <cmath>
using namespace std;
// 思路1, O(n*n),边界控制 
 
// 思路2, O(1),找规律 
void printSpiralMatrixI(int n) {
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

int main() {
	int n;
	cin >> n;
	printSpiralMatrixI(n);
	
	return 0;
}
