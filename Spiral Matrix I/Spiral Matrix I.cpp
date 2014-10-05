/*
���ߣ�unclechen
���ͣ�http://blog.csdn.net/nought03/article/details/39814195 
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
--------------------------------------------------------------
��˳ʱ��Ϊ�� 
˼·1��ģ���������O(n*n)�Ŀռ临�Ӷ�
 
˼·2���ҹ��ɷ���O(1)�Ŀռ临�Ӷ� 
--------------------------------------------------------------- 
*/ 
#include <iostream>
#include <cmath>
using namespace std;
/*
˼·1-1������һ����ά����Ȼ����ñ߽�бƵķ���������ά������ÿһ��Ԫ�ظ�ֵ����lee,��ָoffer�г��ֹ���Ρ� 
��0�㣨�˴�Ϊ������һ�㣩�ı߽磺 
beginX=0; endX=n-1; 
beginY=0; endY=n-1;
�˺󲻶�����beginX��beginY�����ϼ�СendX��endY֪��begin��end����Ϊֹ��
*/
void printSpiralMatrixOutsideToInsideI(int n) {
	if (0 == n) return;
	int **a; // ��̬�����ά������ڴ棬����һ��ָ�������ָ��  
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
	// ��ӡ����ά���� 
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << a[i][j] << "\t";
		}
		cout << endl; 
	}
	// �ͷŶ�ά������ڴ� 
	for(int i = 0; i < n; ++i)  
    	delete[] a[i];  
	delete[] a;
} 
// ˼·1-2����һ����ģ�������ƶ�(x, y) 
void printSpiralMatrixOutsideToInsideII(int n) {
	if (0 == n) return;
	int **a; // ��̬�����ά������ڴ棬����һ��ָ�������ָ��  
	a = new int*[n];
	for (int i = 0; i < n; ++i) {
		a[i] = new int[n];
	}
	int x = 0; // �������ڴ�ӡʱ�ĳ�ʼ���� 
	int y = 0;
	int val = 1; // val��1������n*n����Ӧ��ÿһ��Ԫ�ص�ֵ 
	a[x][y] = val; // �ڷŵ�һ��Ԫ��1 
	int width = n-1; // ��¼��ǰ����Ӧ���߹��Ĳ���,��ʵҲ������������ÿһ��Ԫ�صı߳�,��ʶ��width����Ҫ 
	int count = 0; // ��¼��ǰ�����Ѿ��߹��Ĳ��� 
	int dir = 0; // ��¼��ǰ�ƶ��ķ��� 
	int dir_change_count = -1; // ��¼����ı�Ĵ���������Ϊ2�ı���ʱ��widthҪ����1;���˴���width��ʼֵ�����ڷ���ı��� 
	while (val < n * n) {
		switch(dir) {
			case 0: // ���� 
				++y;
				break;
			case 1: // ���� 
				++x;
				break;
			case 2: // ���� 
				--y;
				break;
			case 3: // ���� 
				--x;
				break;
		}
		a[x][y] = ++val;
		if (++count == width) { // ������һ�������ϵ����꣬count���� 
			count = 0;
			dir = (dir + 1) % 4; // dir+=1��˵���ı���һ�η���
			if(++dir_change_count!=0 && dir_change_count % 2 == 0) { // �ı䷽�������2�ı���ʱ����Ҫ�޸�width�߳� 
				--width;
			}  
		}
	}
	// ��ӡ����ά���� 
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << a[i][j] << "\t";
		}
		cout << endl; 
	}
	// �ͷŶ�ά������ڴ� 
	for(int i = 0; i < n; ++i)  
    	delete[] a[i];  
	delete[] a;
}

// ˼·2 �ҹ��� 
/*
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
// ���֣����ڵ����ӡ
/*
��˳ʱ��Ϊ��
7     8    9   10
6     1    2   11
5     4    3   12
16   15   14   13

˼·1��ģ���������������ӡ�Ĺ��̣�����Ͳ���������������ڵ����ֱ߽�бƵķ�������Ϊ�ĸ��������ÿ��Ʊ߽硣
Ӧ���������ƶ���˼�룬��ά���鿴��һ�������ᣬ(0,0)��ԭ�㣬x�᷽�����ң�y�᷽�����¡� 
����һ��direction������int dir = (0, 1, 2, 3)%4, �������ң����£�����������ĸ����� 

�ؼ��㣺ͨ���۲���ɣ�������ÿһ�������ϣ�x����y���ֻ꣨������֮һ�ƶ����ƶ��Ĳ���Ϊ1, 1, 2, 2, 3, 3, 4, 4 ...
��ÿ�������Ͽ���ǰ���Ĳ�����width��ʾ��ÿ��dir�ı������ǣ�width������1��1,1,2,2,3,3,4,4...�� 

����ܺ�д�� 
��ʼ״̬������ x,y=(n-1)/2, a[x][y]=1; dir = 0, width = 1; 

˼·2������O(1)�Ŀռ临�Ӷȣ�������Ҫ��һ��仯��˼·����Ҫ�ҵ�һ��begin������Ϊ˫��ʱ�����½ǣ�����ʱ�����Ͻǣ�
begin�ļ��㻹��ͨ�����㣨�����Ǹò����ڵ����в������һ�����ٸ�Ԫ�أ�Ҳ��һ���Ȳ�������ͣ� 
Ȼ��ͨ���ж�Ԫ��a[i][j]�ڲ�ͬ�ı��ϣ��ϡ��¡����ң����������Ԫ��a[i][j]��ֵ�� ����Ͳ������� 
 
*/ 
// ˼·1����ʵ�� 
void printSpiralMatrixInsideToOutside(int n) {
	if (0 == n) return;
	int **a; // ��̬�����ά������ڴ棬����һ��ָ�������ָ��  
	a = new int*[n];
	for (int i = 0; i < n; ++i) {
		a[i] = new int[n];
	}
	int x = (n - 1) / 2; // ���������ӡʱ�ĳ�ʼ���� 
	int y = (n - 1) / 2;
	int val = 1; // val��1������n*n����Ӧ��ÿһ��Ԫ�ص�ֵ 
	a[x][y] = val; // �ڷŵ�һ��Ԫ��1 
	int width = 1; // ��¼��ǰ����Ӧ���߹��Ĳ���,��ʵҲ������������ÿһ��Ԫ�صı߳� 
	int count = 0; // ��¼��ǰ�����Ѿ��߹��Ĳ��� 
	int dir = 0; // ��¼��ǰ�ƶ��ķ��� 
	int dir_change_count = 0; // ��¼����ı�Ĵ���������Ϊ2�ı���ʱ��widthҪ����1 
	while (val < n * n) {
		switch(dir) {
			case 0: // ���� 
				++y;
				break;
			case 1: // ���� 
				++x;
				break;
			case 2: // ���� 
				--y;
				break;
			case 3: // ���� 
				--x;
				break;
		}
		a[x][y] = ++val;
		if (++count == width) { // ������һ�������ϵ����꣬count���� 
			count = 0;
			dir = (dir + 1) % 4; // dir+=1��˵���ı���һ�η���
			if(++dir_change_count % 2 == 0) { // �ı䷽�������2�ı���ʱ����Ҫ�޸�width�߳� 
				++width;
			}  
		}
	}
	// ��ӡ����ά���� 
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << a[i][j] << "\t";
		}
		cout << endl; 
	}
	// �ͷŶ�ά������ڴ� 
	for(int i = 0; i < n; ++i)  
    	delete[] a[i];  
	delete[] a;
}

// �����Ŀ��˳ʱ�����ʱ�����û��ʲô�Ѷȣ������������ƶ��ķ�����һ���޸ļ���ʵ�֡� 

// �������� 
int main() {
	int n;
	cout << "������һ������n��" << endl; 
	cin >> n;
	
	cout << "�������ڣ�˳ʱ���ӡ��������˼·1-1���߽���Ʒ���O(n*n)�Ŀռ临�Ӷ��ڣ�" << endl; 
	printSpiralMatrixOutsideToInsideI(n); 
	cout << endl;
	
	cout << "�������ڣ�˳ʱ���ӡ��������˼·1-2������ģ�ⷨ��O(n*n)�Ŀռ临�Ӷ��ڣ�" << endl; 
	printSpiralMatrixOutsideToInsideII(n); 
	cout << endl;
	
	cout << "�������ڣ�˳ʱ���ӡ��������˼·2�����㷨��O(1)�Ŀռ临�Ӷ��ڣ�" << endl; 
	printSpiralMatrixOutsideToInsideIII(n); // �������ڣ�˳ʱ�� 
	cout << endl;
	
	cout << "�������⣬˳ʱ���ӡ����������������֣�����ģ�ⷨ��O(n*n�ռ临�Ӷ���)��" << endl; 
	printSpiralMatrixInsideToOutside(n); // �������⣬˳ʱ�� 
	
	return 0;
}
