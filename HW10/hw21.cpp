/* 
 * [2019117662] [박수환] 저는 이 소스 코드를 다른 소스 코드를 복사하지 않고 직접 작성하였습니다. 
 */

#include <iostream>
#include <algorithm>
#include <cmath>

#define MAX 100	
#define INF 1000 

using namespace std;

void travel(int n, int W[][MAX], int P[][MAX], int &minL);
int count(int A);
bool isIn(int i, int A);
int minimum(int n, int i, int &minJ, int A, int W[][MAX], int D[][MAX]);
int diff(int A, int j);
void tour(int v, int A, int P[][MAX]);

int W[MAX][MAX], P[MAX][MAX], D[MAX][MAX];
int subset_size;

int main(){

	int n, m, i, j, minL;

	cin >> n >> m;
	for(int k = 1; k <= m; k++){
		cin >> i >> j >> W[i][j];
	}

	cout << "\nW배열 :\n" << endl;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(W[i][j] == 0 && i != j) W[i][j] = INF; 
			cout << W[i][j] << " ";
		}
		cout << endl;
	}

	subset_size = pow(2, n - 1);

	travel(n, W, P, minL);

	cout << "\n1 ";
	tour(1, subset_size - 1, P);
	cout << minL << endl;

	cout << "\nD배열 :\n" << endl;
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < subset_size; j++)
			cout << D[i][j] << " ";
		cout << endl;
	}
	cout << "\nP배열 :\n" << endl;
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < subset_size; j++){
			cout << P[i][j];
			if(j + 1 < subset_size) cout << " ";
		}
		cout << endl;
	}

	return 0;
}
void travel(int n, int W[][MAX], int P[][MAX], int &minL) {
	int i, k, minJ;

	// A = 공집합(지나온 경로 X) v1 = 0
	for (i = 0; i <= n; i++)
		D[i][0] = W[i][1];

	cout << "\n초기화 D배열 :\n" << endl;
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < subset_size; j++)
			cout << D[i][j] << " ";
		cout << endl;
	}
	for (k = 1; k <= n - 2; k++)
		for (int A = 0; A < subset_size; A++) {
			if (count(A) != k) continue;
			for (i = 2; i <= n; i++) {
				if (isIn(i, A)) continue;
				D[i][A] = minimum(n, i, minJ, A, W, D);
				P[i][A] = minJ;
			}
			cout << "\n변경후 D배열 :\n" << endl;
			for(int i = 1; i <= n; i++){
				for(int j = 0; j < subset_size; j++)
					cout << D[i][j] << " ";
				cout << endl;
			}
			cout << "\n변경후 P배열 :\n" << endl;
			for(int i = 1; i <= n; i++){
				for(int j = 0; j < subset_size; j++)
					cout << P[i][j] << " ";
				cout << endl;
			}
		}
	D[1][subset_size - 1] = minimum(n, 1, minJ, subset_size - 1, W, D);
	P[1][subset_size - 1] = minJ;
	minL = D[1][subset_size - 1];

}
int count(int A) {
	int cnt = 0;
	for (; A != 0; A >>= 1)
		if (A & 1) cnt++;
	return cnt;
}
bool isIn(int i, int A) {
	return (A & (1 << (i - 2))) != 0;
}
int minimum(int n, int i, int &minJ, int A, int W[][MAX], int D[][MAX]) {
	int minV = INF;
	for (int j = 2; j <= n; j++) {
		if (!isIn(j, A)) continue;
		int value = W[i][j] + D[j][diff(A, j)];
		if (minV > value) {
			minV = value;
			minJ = j;
		}
	}
	return minV;
}
int diff(int A, int j) {
	return (A & ~(1 << (j - 2)));
}
void tour(int v, int A, int P[][MAX]) {
	if (A == 0)
		cout << "1 ";
	else {
		cout << P[v][A] << " ";
		tour(P[v][A], diff(A, P[v][A]), P);
	}
}
