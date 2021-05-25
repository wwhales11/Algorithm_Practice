/* [2019117662] [박수환] 저는 이 소스 코드를 다른 소스 코드를 복사하지 않고 직접 작성하였습니다. 
 */

#include <iostream>
#include <climits>
#define MAX 256

using namespace std;

int res[MAX];	
int B[MAX];

/*
   int bin0 (int n, int k) {
   if (k == 0 || k == n)
   return 1;
   else {
   B[n-1][k-1] = (B[n-1][k-1] == 0) ? bin(n-1, k-1) : B[n-1][k-1];
   B[n-1][k] = (B[n-1][k] == 0) ? bin(n-1, k) : B[n-1][k];
   return (B[n-1][k-1] + B[n-1][k]) % 100000000;
   }
   }
 */
/*
int bin (int n, int k) {
	if (k == 0 || k == n){
		return 1;
	}
	else {
		B[n-k-1] = (B[n-k-1] == 0) ? bin(n-1, k-1) : B[k];
		B[n-k] = (B[n-k] == 0) ? bin(n-1, k) : B[k-1];

		for (int i=0; i<k; i++)
			cout << B[i] << " ";
		cout << endl;
		return (B[n-k-1] + B[n-k]) % 100000000;
	}
}
*/
int bin (int n, int k) {
	if (k == 0 || k == n){
		return 1;
	}
	else {
		B[k] = (B[k] == 0) ? bin(n-1, k-1) : B[k-1];
		B[k-1] = (B[k-1] == 0) ? bin(n-1, k) : B[k];

		return (B[k-1] + B[k]) % 100000000;
	}
}
int bin2(int n, int k) {
	for (int i=0; i<=n; i++) {
		for (int j = k; j >= 0; j--) {
			if (j == 0 || j == i) 
				B[j] = 1;
			else
				B[j] = (B[j-1] + B[j]) % 100000000;
		}
	}
	return B[k];
}
int main(){

	int t, k, n;

	cin >> t;	// N 개수 입력

	for (int i=0; i<t; i++) {
		cin >> n >> k;
		res[i] = bin2(n, k);
	}
	for (int i=0; i<t; i++) 
		cout << res[i] << endl;

	return 0;
}
