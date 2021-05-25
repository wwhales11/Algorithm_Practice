/* 
 * [2019117662] [박수환] 저는 이 소스 코드를 다른 소스 코드를 복사하지 않고 직접 작성하였습니다. 
 */
#include <iostream>
#include <algorithm>
#define MAX 100	

using namespace std;

void m_coloring(int i);
bool promising(int i);

int n, path;
int maxColor = 4;
int m = 4;
bool W[MAX][MAX];
int vcolor[MAX];

void m_coloring(int i) {
	int color;
	if (promising(i)){
		if (i == n){
			int m1, m2, m3, m4, lm;
			m1 = m2 = m3 = m4 = 0;
			for (int i = 1; i <= n; i++){
				if (vcolor[i] == 1) m1 = 1;
				if (vcolor[i] == 2) m2 = 1;
				if (vcolor[i] == 3) m3 = 1;
				if (vcolor[i] == 4) m4 = 1;
			}
			lm = m1 + m2 + m3 + m4;
			if (lm < m) m = lm;
		}
		else
			for (color = 1; color <= maxColor; color++) {
				vcolor[i + 1] = color;
				m_coloring(i + 1);
			}
	}
}
bool promising(int i) {
	int j = 1;
	bool flag = true;
	while (j < i && flag) {
		if (W[i][j] && vcolor[i] == vcolor[j])
			flag = false;
		j++;
	}
	return flag;
}
int main(){

	int i, j;

	cin >> n >> path;

	for (int i = 1; i <= n; i++)
		vcolor[i] = 0;

	for (int k = 1; k <= path; k++){
		cin >> i >> j;
		W[i][j] = 1;
		W[j][i] = 1;
	}

	m_coloring(0);

	cout << m << endl;

	return 0;
}

