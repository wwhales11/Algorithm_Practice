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
		B[k] = 1;
		return 1;
	}
	else {
		B[k] = (B[k] == 0) ? bin(n-1, k) : B[k] + B[k-1];
		B[k-1] = (B[k-1] == 0) ? bin(n-1, k-1) : B[k-1] + B[k-2];
		return (B[k] + B[k-1]) % 100000000;
	}
}
int main() {

	int t, k;
	int n;

	cin >> t;	// N 개수 입력

	for (int i=0; i<t; i++) {
		cin >> n >> k;
		res[i] = bin(n, k);
		for (int i=0; i<9; i++) 
			cout << B[i] << " ";
		cout << endl;
	}
	for (int i=0; i<t; i++) {
		cout << res[i] << endl;
	}

	return 0;
}
