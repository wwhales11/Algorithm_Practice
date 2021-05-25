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
		return 1;
	}
	else {
		B[n-k] = (B[n-k] == 0) ? bin(n-1, k) : B[n-k];
		B[n-k-1] = (B[n-k-1] == 0) ? bin(n-1, k-1) : B[n-k-1];
		return (B[n-k] + B[n-k-1]) % 100000000;
	}
}
int main(){

	int t;
	int k, n;
	int arr[100][100];
	int brr[100][100];

	cin >> t;	// N 개수 입력

	for (int i=0; i<t; i++) {
		cin >> n >> k;
		res[i] = bin(n, k);
		for (int j=0; j<6; j++)
			arr[i][j] = B[j];
		if (k == 0 || k == n)
			B[n] = 1;
		else
			B[n-k] = (B[n-k] + B[n-k-1]) % 100000000;
		for (int j=0; j<6; j++)
			brr[i][j] = B[j];
	}
	for (int i=0; i<t; i++) {
		cout << res[i] << endl;
		for (int j=0; j<6; j++)
			cout << arr[i][j] << " ";
		cout << endl;
		for (int j=0; j<6; j++)
			cout << brr[i][j] << " ";
		cout << endl;
		cout << "++++++++++++++++" << endl;
	}

	return 0;
}
