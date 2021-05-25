/* [2019117662] [박수환] 저는 이 소스 코드를 다른 소스 코드를 복사하지 않고 직접 작성하였습니다. 
 */

#include <iostream>
#include <climits>
#include <algorithm>
#define MAX 88888

using namespace std;

int B[MAX][MAX];

int bin0 (int n, int k) {
	if (k == 0 || k == n)
		return 1;
	else {
		B[n-1][k-1] = (B[n-1][k-1] == 0) ? bin0(n-1, k-1) : B[n-1][k-1];
		B[n-1][k] = (B[n-1][k] == 0) ? bin0(n-1, k) : B[n-1][k];
		return (B[n-1][k-1] + B[n-1][k]) % 100000;
	}
}

int bin (int n, int k) {
	for (int i = 0; i <= n; i++){
		for( int j = 0; j <= min(i, k); j++){
			if (j == 0 || j == i){
				B[i][j] = 1;
			}
			else 
				B[i][j] = ((B[i - 1][j - 1] + B[i - 1][j]) %100000);
		}
	}
	return B[n][k];
}
int main() {

	int t, k;
	int n;
	int res[MAX];

	cout << "테스트케이스 : ";
	cin >> t;	// N 개수 입력

	for (int i=0; i<t; i++) {
		cin >> n >> k;
		res[i] = bin0(n, k);
	}
	for (int i=0; i<t; i++)
		cout << res[i] << endl;

	return 0;
}
