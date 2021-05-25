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
	int n[50001];
	int arr[100][100];

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
		for (int j=0; j<6; j++)
			arr[i][j] = B[j];
		res[i] = B[k];	
	}
	for (int i=0; i<t; i++) {
		cout << res[i] << endl;
		for (int j=0; j<6; j++)
			cout << arr[i][j] << " ";
		cout << endl;
	}

	return 0;
}
