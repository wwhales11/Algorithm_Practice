#include <iostream>
#define MAX 256

using namespace std;

int W[MAX][MAX];
int D[MAX][MAX];
int P[MAX][MAX];

void path(int q, int r, int &len);

int main () {

	int n, m;
	int u, v;
	int s[MAX], d[MAX];
	int t;

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
	cin >> t;
	for (int i=0; i<t; i++)
		cin >> s[i] >> d[i];

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
					P[i][j] = k;
					D[i][j] = D[i][k] + D[k][j];
				}
			}
		}
	}

	for (int i=1; i<=n; i++) {		// D행렬
		for (int j=1; j<=n; j++) {
			if (D[i][j] == MAX)
				cout << "INF ";
			else
				cout << D[i][j] << " ";
		}
		cout << endl;
	}
	for (int i=1; i<=n; i++) {		// P행렬
		for (int j=1; j<=n; j++) {
			cout << P[i][j] << " ";
		}
		cout << endl;
	}


	for (int i=0; i<t; i++){
		int len = 0;
		cout << s[i] << " ";
		path(s[i], d[i], len);
		cout << d[i] << " ";
		if((len == MAX) || (len == 0))
			cout << "INF" << endl;
		else
			cout << len << endl;
	}
}
void path (int q, int r, int &len){
	if(P[q][r] != 0){
		path(q, P[q][r], len);
		cout << P[q][r] << " ";
		len = D[q][r];
		path(P[q][r], r, len);
	}

}
