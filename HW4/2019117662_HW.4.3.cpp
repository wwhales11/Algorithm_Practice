/* [2019117662] [박수환] 저는 이 소스 코드를 다른 소스 코드를 복사하지 않고 직접 작성하였습니다. 
 */

#include <iostream>
#include <climits>
#define MAX 129 

using namespace std;

int res[MAX];	
int B[MAX];

int bin (int n, int k) {
	if (k == 0 || k == n)
		return 1;
	else {
		D[n][k] = (A[n-1][k-1] > A[n-1][k-2]) ? bin(n-1, k-1) : bin(n-1, k-2);

		P[n][k] = (B[n-1][k] == 0) ? bin(n-1, k) : B[n-1][k];

		return bin(n-1, k-1);
	}
}
void floyd2 (int n) {
	for(int i=1; i<=n; i++) 
		for(int j=1; j<=n; j++)
			P[i][j]=0;
	swap(n, W, D);

	for(int k=1; k<=n; k++)
		for(int i=1; i<=n; i++) 
			for(int j=1; j<=i; j++)
				if (A[i][k] + A[k][j] < A[i][k+1] + A[k+1][j]){
					P[i][j] = k;
					D[i][j] = D[i][k] + D[k][j];
				}else{
					P[i][j] = k+1;
					D[i][j] = D[i][k+1] + D[k+1][j];
				}
}
void path (int q, int r, int &len){
	if(P[q][r] != 0){
		path(q, P[q][r], len);
		cout << P[q][r] << " ";
		len = D[q][r];
		path(P[q][r], r, len);
	}
}

int main() {

	int n;
	int len;
	int A[]

		cin >> n;	// N 개수 입력

	for (int i=1; i<=n; i++) 
		for (int j=1; j<=i; j++) 
			cin >> A[i][j];

	cout << len << endl;
	for (int i=1; i<=n; i++) 
		cout << path() << endl;

	return 0;
}
