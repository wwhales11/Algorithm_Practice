/* 
 * [2019117662] [박수환] 저는 이 소스 코드를 다른 소스 코드를 복사하지 않고 직접 작성하였습니다. 
 */
#include <iostream>
#include <algorithm>
#include <climits>

#define MAX 256	

using namespace std;

int d[MAX];
int P[MAX][MAX];
int M[MAX][MAX];

int minmult (int n);
int min(int i, int j, int &minK);
void order(int i, int j); 

int minmult (int n) {
	int i, j, k, diagonal;
	for (i = 1; i <= n; i++)
		M[i][i] = 0;
	for (diagonal = 1; diagonal <= n - 1; diagonal++)	//대각선방향 이동
		for (i = 1; i <= n - diagonal; i++) {
			j = i + diagonal;
			M[i][j] = min(i, j, k);
			P[i][j] = k;
		}
	return M[1][n];
}
int min(int i, int j, int &minK) {	// 최소횟수탐색
	int minV = INT_MAX;
	for (int k = i; k < j; k++) {
		int value = M[i][k] + M[k+1][j] + d[i-1]*d[k]*d[j];
		if (minV > value) {
			minV = value;
			minK = k;
		}
	}
	return minV;
}
void order(int i, int j) {
	if (i == j)
		cout << "A" << i;
	else {
		int k = P[i][j];
		cout << "(";
		order(i, k);
		order(k + 1, j);
		cout << ")";
	}
}
int main(){

	int n;

	cout << "행렬개수: ";
	cin >> n;	// N 개수 입력

	cout << "d[i] 입력 : ";
	for (int i=0; i<=n; i++) 	// N+1 개 d[i]개 입력 받음
		cin >> d[i]; 

	minmult(n);

	cout << "\nP배열 : \n";
	for (int i=1; i <= n - 1; i++){		// P배열 출력
		for (int j = 2; j <= n; j++){
			//if (P[i][j] != 0){
				cout << P[i][j]; 
				if ((j+1) <= n) cout << " "; 
		//	}
		}
		cout << endl;
	}
	cout << "\nM배열 : \n";
	for (int i=1; i <= n - 1; i++){		// M배열 출력
		for (int j = 2; j <= n; j++){
		//	if (M[i][j] != 0){
				cout << M[i][j]; 
				if (M[i][j] < 10) cout << " ";
				if (M[i][j] < 100) cout << " ";
				if ((j+1) <= n) cout << " "; 
		//	}
		}
		cout << endl;
	}
	
	cout << "\nORDER : \n";
	order(1, n);
	cout << endl;
}
