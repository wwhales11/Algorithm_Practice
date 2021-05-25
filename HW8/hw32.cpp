/* 
 * [2019117662] [박수환] 저는 이 소스 코드를 다른 소스 코드를 복사하지 않고 직접 작성하였습니다. 
 */
#include <iostream>
#include <algorithm>
#define MAX 256	

using namespace std;

bool m_coloring(int i);
bool promising();

int n, path;
int maxColor = 4;
int m = 4;
bool W[MAX][MAX];
int vcolor[MAX];

bool m_coloring(int i) {
	int color;
	if (i == n){
		if (promising()){
			int cnum = 0;
			for (int i = 1; i <= n; i++){
				cout << vcolor[i] << " ";
				if (vcolor[i] > cnum) cnum = vcolor[i];
			}
			cout << "\ncnum = " << cnum << endl;
			if (cnum < m) m = cnum;

			return true;
		}
		return false;
	}

	for (color = 1; color <= maxColor; color++) {
		vcolor[i + 1] = color;

		if(m_coloring(i + 1))
			return true;
	}
	return false;
}
bool promising() {
	for (int i = 1; i <= n; i++){
		for (int j = i+1; j <= n; j++)
			if (W[i][j] && vcolor[i] == vcolor[j])
				return false;
	}
	return true;
}
int main(){

	int i, j;

	cin >> n >> path;

	for (int i = 1; i <= n; i++)
		vcolor[i] = 0;

	for (int k = 1; k <= path; k++){
		cin >> i >> j;
		W[i][j] = 1;
	}

	m_coloring(0);

	cout << m << endl;

	return 0;
}

