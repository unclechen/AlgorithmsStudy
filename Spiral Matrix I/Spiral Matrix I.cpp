/*
Spiral Matrix,旋转数组I：输入n,输出一个二维矩阵,由内向外每一层的元素值从1->n. 
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
*/ 
#include <iostream>
#include <cmath>
using namespace std;

void printSpiralMatrix(int n) {
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
	printSpiralMatrix(n);
	
	return 0;
}
