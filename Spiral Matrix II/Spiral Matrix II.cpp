/*
作者：unclechen
博客：http://blog.csdn.net/nought03/article/details/39783509
 
Spiral Matrix, 旋转数组变种：输入n,输出一个二维矩阵,由内向外每一层的元素值从1->n. 

输入：
3
输出： 
3 3 3 3 3
3 2 2 2 3
3 2 1 2 3
3 2 2 2 3
3 3 3 3 3
要求：
空间复杂度为O(1) 

思路：将矩阵从外向内（内向外） 分层（level）,每一层的元素可以赋值为n-level;
也就是说从外向内,第0层的元素赋值为3,第1层赋值为2,第2层赋值为1. 
问题的关键点在于如何给一个元素a[i][j]划分层次(level),
那么对于a[i][j]而言，如何根据i和j来确定a[i][j]的层次呢？我们观察一下，二维数组的各个元素下标(i,j)。

(0, 0) (0, 1) (0, 2) (0, 3) (0, 4)
(1, 0) (1, 1) (1, 2) (1, 3) (1, 4)
(2, 0) (2, 1) (2, 2) (2, 3) (2, 4)
(3, 0) (3, 1) (3, 2) (3, 3) (3, 4)
(4, 0) (4, 1) (4, 2) (4, 3) (4, 4)

仔细观察发现，第0层（从外向内算的第一圈元素，共有上、下、左、右四条边）中:
上边的元素行号都为i = 0；
右边的元素列号都为j = 4，（5 - 1 - 4 = 0）；
下边的元素行号为i = 4（5 - 1 - 4 = 0）；
左边的元素列号为j = 0。
所以将矩阵分为右上、左下两部分，可以看出在右上的元素中，层次level由i和2n-1-1-j（2n-1在这里是二维矩阵的边长）中较小的值确定，在左下的元素中，level由2n-1-1-i和j中较小的值确定。

所以，对于二维矩阵中任一位置a[i][j], a[i][j]所处的层的计算公式为：
level = min(i, n - 1 - j) (i<=j时);
level = min(j, n - 1 - i) (i>j时)。
*/ 

#include <iostream>
#include <cmath>
using namespace std;

void printSpiralMatrixII(int n) {
	int w = 2*n-1; // 矩阵的边长2n-1，level从1->n
	for (int i = 0; i < w; ++i) {
		for (int j = 0; j < w ; ++j) {
			int level;
			if (i <= j) {
				level = min(i, w-j-1);
			}	
			else {
				level = min(j, w-i-1);
			}
			cout << n-level << " ";
		}
		cout << endl;
	} 
	
}

int main() {
	int n;
	cin >> n;
	printSpiralMatrixII(n);
	
	return 0;
}
