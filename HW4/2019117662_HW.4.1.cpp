/* [2019117662] [박수환] 저는 이 소스 코드를 다른 소스 코드를 복사하지 않고 직접 작성하였습니다. 
 */

#include <iostream>
#include <climits>
#define MAX 256

using namespace std;

int res[MAX];	
int B[MAX];

/*
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
 */
int bin (int n, int k) {
	if (k == 0 || k == n){
		B[n] = 1;
		return 1;
	}
	else {
		B[n-k] = (B[n-k] == (B[n-k] + B[n-k-1])) ? bin(n-1, k) : B[n-k];
		B[n-k-1] = (B[n-k-1] == B[n-k-1] + B[n-k-2]) ? bin(n-1, k-1) : B[n-k-1];
//		B[n-k] = (B[n-k] + B[n-k-1]) % 100000000;
		return (B[n-k] + B[n-k-1]) % 100000000;
	}
}
int main() {

	int t, k;
	int n[50001];
	int arr[100][100];
	int brr[100][100];

	cin >> t;	// N 개수 입력

	for (int i=0; i<t; i++) {
		cin >> n[i] >> k;
		if (n[i] == 0) {
			B[k] = 1;
			n[i] = 1;
		}
		if (n[i] != n[i-1]){
			for (int r=0; r<=n[i]; r++){
				B[n[i]-r] = bin(n[i], r);
				for (int j=0; j<6; j++)
					brr[r][j] = B[j];
			}
		}
		for (int j=0; j<6; j++)
			arr[i][j] = B[j];
		res[i] = B[k];	
	}
	for (int i=0; i<t; i++) {
		cout << res[i] << endl;
		for (int r=0; r<6; r++){
			for (int j=0; j<6; j++){
				cout << brr[r][j] << " ";
			}
		cout << endl;
		}
		for (int j=0; j<6; j++)
			cout << arr[i][j] << " ";
		cout << endl;
	}

	return 0;
}
