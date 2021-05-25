/* 
 * [2019117662] [박수환] 저는 이 소스 코드를 다른 소스 코드를 복사하지 않고 직접 작성하였습니다. 
 */
#include <iostream>
#include <algorithm>
#define MAX 256	

using namespace std;

void m_coloring(int i);
bool promising(int i);

int n, path;
int m;
int cnum = 0;
bool W[MAX][MAX];
int vcolor[MAX];

void m_coloring(int i) {
	int color;
	if (promising(i)){
		if (i == n){
			for (int i = 1; i <= n; i++)
				cout << vcolor[i] << " ";
			cout << endl;
			cout << "cnum = " << cnum << endl;
		}
		else
			for (color = 1; color <= m; color++) {
				vcolor[i + 1] = color;
				if(cnum < color) cnum = color;
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

	for (int i = 0; i < n; i++)
		vcolor[i] = 0;

	for (int k = 1; k <= path; k++){
		cin >> i >> j;
		W[i][j] = 1;
	}
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++)
			cout << W[i][j] << " ";
		cout << endl;
	}

	m = 4;
	m_coloring(0);

	return 0;
}
