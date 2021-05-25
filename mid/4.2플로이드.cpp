#include <iostream>
#define MAX 256

using namespace std;
int W[MAX][MAX];
int D[MAX][MAX];
int P[MAX][MAX];
void swap(int n, int W[][MAX], int D[][MAX]){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			D[i][j] = W[i][j];
		}
	}
}
void floyd2 (int n) {
	for(int i=1; i<=n; i++) 
		for(int j=1; j<=n; j++)
			P[i][j]=0;
	swap(n, W, D);

	for(int k=1; k<=n; k++){
		for(int i=1; i<=n; i++)
			for(int j=1; j<=n; j++)
				if (D[i][k] + D[k][j] < D[i][j]){
					P[i][j] = k;
					D[i][j] = D[i][k] + D[k][j];
				}
		cout << "D" << k << " 행렬 : \n";
		for (int i=1; i<=n; i++) {		// D행렬
			for (int j=1; j<=n; j++) {
				if (D[i][j] == MAX)
					cout << "INF ";
				else
					cout << D[i][j] << " ";
			}
			cout << endl;
		}
	cout << endl;
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
int main () {

	int n, m, cho, edge, t;
	int u, v;
	int s[16257], d[16257];

	cout << "행과 열 입력 : ";
	cin >> n >> m;

	for (int i=1; i<=n; i++) {
		for (int j=1; j<=m; j++) {
			if (i == j)
				W[i][j] = 0;
			else 
				W[i][j] = MAX;
		}
	}
	cout << "[1 : 간선개수] OR [2 : W 배열입력]? : ";
	cin >> cho;

	if (cho == 1){
		cout << "간선 개수 : ";
		cin >> edge;
		cout << "간선 두개 가중치 : \n";
		for (int i=1; i<=edge; i++) {		// 간선 u,v와 가중치 w
			cin >> u >> v;
			cin >> W[u][v];
		}
	}else if(cho == 2){
		cout << "W 배열 전체입력 : \n";
		for (int i=1; i<=n; i++) 
			for (int j=1; j<=m; j++){
				cin >> W[i][j];
				if (W[i][j] == -1) W[i][j] = MAX;
			}
	}

	cout << "테스트케이스 : ";
	cin >> t;
	cout << "출발|| 도착 : \n";
	for (int i=1; i<=t; i++) {		// 출발 s, 도착 d
		cin >> s[i] >> d[i];
	}

	floyd2(n);

	cout << "D행렬 : \n";
	for (int i=1; i<=n; i++) {		// D행렬
		for (int j=1; j<=n; j++) {
			if (D[i][j] == MAX)
				cout << "INF ";
			else
				cout << D[i][j] << " ";
		}
		cout << endl;
	}
	cout << "P행렬 : \n";
	for (int i=1; i<=n; i++) {		// P행렬
		for (int j=1; j<=n; j++) {
			cout << P[i][j] << " ";
		}
		cout << endl;
	}
	cout << "경로 : \n";
	for (int i=1; i<=t; i++){
		int len = 0;
		cout << s[i] << " ";
		path(s[i], d[i], len);
		cout << d[i] << " ";
		cout << "최종경로 = ";
		if((len == MAX) || (len == 0))
			cout << "INF" << endl;
		else
			cout << len << endl;
	}
}
