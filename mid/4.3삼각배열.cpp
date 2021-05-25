/* [2019117662] [박수환] 저는 이 소스 코드를 다른 소스 코드를 복사하지 않고 직접 작성하였습니다. 
 */

#include <iostream>
#include <algorithm>
#include <climits>
#define MAX 129 

using namespace std;

int n;	
int A[MAX][MAX];
int D[MAX][MAX];
int E[MAX];
int P[MAX];

int trip(int i, int j) {
	if(i==0 && j==0){
//		E[i] = 1;
		return D[0][0];
	}

	if(i==0) {
		D[i][j] = (D[0][j-1] != 0) ? (D[0][j-1] + A[0][j]) : (trip(0, j-1) + A[0][j]);
		return D[i][j];
	}

	if(j==0) {
		D[i][j] = (D[i-1][0] != 0) ? (D[i-1][0] + A[i][0]) : (trip(i-1, 0) + A[i][0]);
		return D[i][j];
	}

	int T = (D[i-1][j] != 0) ? (D[i-1][j]) : (trip(i-1, j));
	int R = (D[i-1][j-1] != 0) ? (D[i-1][j-1]) : (trip(i-1, j-1));
	D[i][j] = max(T, R) + A[i][j];
//	E[j] = T > R ? 1 : 2;
	return D[i][j];
}

int main() {

	int len = INT_MAX;

	cout << "삼각배열 높이 : ";
	cin >> n;	// N 개수 입력

	cout << "삼각배열 입력 : \n";
	for (int i=0; i<n; i++) 
		for (int j=0; j<=i; j++) 
			cin >> A[i][j];

	D[0][0] = A[0][0];

	int x, y;
	for (int i=0; i<n; i++){
		if(trip(n, i) <= len){
			len = D[n][i];
			x = n;
			y = i;
			}
	}
	cout << "\nD배열 : \n";

	for (int i=0; i<n; i++){ 	// D배열
		for (int j=0; j<=i; j++){
			cout << D[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl << "최대쏘길이 = " << len << endl;

	for (int i = n - 1; i > 0; i--){
		if (D[x][y] - A[x][y] == D[x-1][y]) x--;
		else if (D[x][y] - A[x][y] == D[x-1][y-1]){ x--; y--; }
		P[i] = A[x][y];
	}
	cout << "\n경로 : ";
	P[0] = A[0][0];
	for (int i = 0; i < n; i++)
		cout << P[i] << " ";

	cout << endl;
	return 0;
}
