/*
Spiral Matrix,��ת����I������n,���һ����ά����,˳/��ʱ����������ÿһ���Ԫ��ֵ��1->n. 

case:
����
9
���
1 2 3
8 9 4
7 6 5

��ʱ�������
1 8 7
2 9 6
3 4 5

��˳ʱ��Ϊ�� 
˼·1��O(n*n)�Ŀռ临�Ӷ�
����һ����ά����Ȼ����ñ߽�бƵķ���������ά������ÿһ��Ԫ�ظ�ֵ����lee,��ָoffer�г��ֹ���Ρ� 

˼·2��O(1)�Ŀռ临�Ӷ� 
������������ڣ������⣩ �ֲ㣨level��,ÿһ���е�Ԫ����һ��˳ʱ��ĵ������С�
ȷ����һȦԪ�ص���ʼֵbegin��Ȼ����������һȦ�е�ÿһ��Ԫ��ֵ�� 
��Ҫ�õ����¼���������
���level��i<=jʱ,level = min(i,w-1-j); i<jʱ,level=min(j,w-1-i) 
ÿһ��ı߳�width��width = n-2*level
ÿһ�����ʼԪ�ص�ֵ��begin = 4*level*(n-level)+1,  4*level*(n-level)�ǵ�level��֮��Ĳ�Σ�0->level-1����Ԫ�ظ����ĺ�
���ֵ�ļ����ɣ�4*width-4������0->level-1�������Ԫ��֮�͵õ�����ʵ����һ���Ȳ����е���ͣ� 

��ˣ�����ÿһȦ��Ԫ�ض��ԣ��ϱߡ��ұߡ��±ߡ���ߵ�Ԫ��ֵ���㹫ʽΪ��
�ϣ�i <= j && level = i : a[i][j] = begin + j - level
�ң�i <= j && level = n-1-j : a[i][j] = begin + (width-1) + i - level
�£�i > j && level = n-1-i : a[i][j] = begin + 2*(width-1) + (n - 1 - level - j)
��i > j && level = j : a[i][j] = begin + 3*(width-1) + (n - 1 - level - i)
*/ 

#include <iostream>
#include <cmath>
using namespace std;
// ˼·1, O(n*n),�߽���� 
 
// ˼·2, O(1),�ҹ��� 
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
			if (i <= j && level == i) { // �ϱ� 
				val = begin + j - level;
			} 
			if (i <= j && level == n-1-j) { // �ұ� 
				val = begin + (width-1) + i - level;
			}
			if (i > j && level == n-1-i) { // �±� 
				val = begin + 2*(width-1) + (n - 1 - level - j);
			}
			if (i > j && level == j) { // ��� 
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
