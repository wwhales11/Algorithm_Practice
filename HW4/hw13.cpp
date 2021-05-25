/* [2019117662] [박수환] 저는 이 소스 코드를 다른 소스 코드를 복사하지 않고 직접 작성하였습니다. 
 */

#include <iostream>
#include <climits>
#define MAX 256

using namespace std;

int res[MAX];	
int B[MAX];

int bin (int n, int k) {
	if (k == 0 || k == n){
		B[n] = 1;
		return 1;
	}
	else {
		B[n-k] = (B[n-k] == 0) ? bin(n-1, k) : B[n-k];
		B[n-k-1] = (B[n-k-1] == 0) ? bin(n-1, k-1) : B[n-k-1];
		B[n-k] = (B[n-k] + B[n-k-1]) % 100000000;

		return (B[n-k] + B[n-k-1]) % 100000000;
	}
}
int main() {

	int t, k;
	int n[50001];

	cin >> t;	// N 개수 입력

	for (int i=0; i<t; i++) {
		cin >> n[i] >> k;
		if (n[i] == 0) {
			B[k] = 1;
			n[i] = 1;
		}
		if (n[i] != n[i-1]){
		for (int r=0; r<=n[i]; r++)
			for (int g=0; g<=r; g++)
				bin(r, g);
		}
		res[i] = B[k];	
	}
	for (int i=0; i<t; i++) {
		cout << res[i] << endl;
	}

	return 0;
}
