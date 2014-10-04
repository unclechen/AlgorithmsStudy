/*
Spiral Matrix,��ת����I������n,���һ����ά����,��������ÿһ���Ԫ��ֵ��1->n. 
���룺
3
����� 
3 3 3 3 3
3 2 2 2 3
3 2 1 2 3
3 2 2 2 3
3 3 3 3 3
Ҫ��
�ռ临�Ӷ�ΪO(1) 
˼·��������������ڣ������⣩ �ֲ㣨level��,ÿһ���Ԫ�ؿ��Ը�ֵΪn-level;
Ҳ����˵��������,��0���Ԫ�ظ�ֵΪ3,��1�㸳ֵΪ2,��2�㸳ֵΪ1. 
*/ 
#include <iostream>
#include <cmath>
using namespace std;

void printSpiralMatrix(int n) {
	int w = 2*n-1; // ����ı߳�2n-1��level��1->n
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
