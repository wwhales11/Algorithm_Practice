#include <iostream>
#define MAX 256

using namespace std;

int W[MAX][MAX];
int D[MAX][MAX];
int P[MAX][MAX];

void path (int q, int r){

	cout << q << " ";
	if(P[q][r] > 0){
		path(q, P[q][r]);
		cout << "v" << P[q][r] << " ";
		path(P[q][r], r);
	}
	cout << r << " ";
	if(D[q][r] > 0)
		cout << D[q][r] << endl;
	else 
		cout << "INF" << endl;
}

int main () {

	int n, m;
	int u, v;

	cin >> n >> m;

	for (int i=1; i<=n; i++) {
		for (int j=1; j<=n; j++) {
			if (i == j) 
				W[i][j] = 0;
			else 
				W[i][j] = MAX;
		}
	}
	for (int i=1; i<=m; i++) {		// 간선 u,v와 가중치 w
		cin >> u >> v;
		cin >> W[u][v];
	}
	cout << endl;
	cout << "입력후W배열--------------" << endl;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout << W[i][j] << " ";
		}
		cout << endl;
	}

	int i, j;
	for(i=1; i<=n; i++) 
		for(j=1; j<=n; j++)
			P[i][j]=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			D[i][j] = W[i][j];
		}
	}

	for(int k=1; k<=n; k++){
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++){
				if (D[i][k] + D[k][j] < D[i][j]){
					cout << " D[" << i << "][" << k << "] = " << D[i][k] << " D[" << k << "][" << j << "] = " << D[k][j];
					cout << " < " << " D[" << i << "][" << j << "] = " << D[i][j] << endl; 
					P[i][j] = k;
					D[i][j] = D[i][k] + D[k][j];
				}
			}
		}
	}

	cout << "D배열--------------" << endl;
	for (int i=1; i<=n; i++) {		// D행렬
		for (int j=1; j<=n; j++) {
			if (D[i][j] == 0 && i != j)
				cout << "INF ";
			else
				cout << D[i][j] << " ";
		}
		cout << endl;
	}
	cout << "P배열--------------" << endl;
	for (int i=1; i<=n; i++) {		// P행렬
		for (int j=1; j<=n; j++) {
			cout << P[i][j] << " ";
		}
		cout << endl;
	}

}
