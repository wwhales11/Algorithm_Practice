/* [2019117662] [박수환] 저는 이 소스 코드를 다른 소스 코드를 복사하지 않고 직접 작성하였습니다. 
 */

#include <iostream>
#include <algorithm>
#define MAX 129 

using namespace std;

int n;	
int A[MAX][MAX];
int D[MAX][MAX];
int P[MAX];


int trip(int i, int j) {
	if(i==0 && j==0){
		P[i] = 1;
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
	P[i] = T > R ? 1 : 2;
	return D[i][j];
}

int main() {

	int len = 0;
	int y=0;

	cin >> n;	// N 개수 입력

	for (int i=0; i<n; i++) 
		for (int j=0; j<=i; j++) 
			cin >> A[i][j];

	D[0][0] = A[0][0];

	for (int i=0; i<n; i++){
		if(trip(n, i) >= len){
			len = D[n][i];
		}
	}
	cout << len << endl;
	for (int i=0; i<n; i++) 
		cout << P[i] << " ";
	cout << endl;

	cout << A[0][0] << " ";

	for (int i=1; i<n; i++){
			if (P[i] == 1)
				cout << A[i][y] << " ";
			else if (P[i] == 2) {
				y += 1;
				cout << A[i][y] << " ";
			}
	}
	cout << endl;

	return 0;
}
