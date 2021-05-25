/* [2019117662] [박수환] 저는 이 소스 코드를 다른 소스 코드를 복사하지 않고 직접 작성하였습니다. 
 */

#include <iostream>
#include <algorithm>
#define MAX 129 

using namespace std;

int n;	
int A[MAX][MAX];
int cost[MAX][MAX];
int cache[MAX][MAX];

/*
   int bin (int n, int k) {
   if (k == 0 || k == n)
   return 1;
   else {
   D[n][k] = (A[n-1][k-1] > A[n-1][k-2]) ? bin(n-1, k-1) : bin(n-1, k-2);

   P[n][k] = (B[n-1][k] == 0) ? bin(n-1, k) : B[n-1][k];

   return bin(n-1, k-1);
   }
   }
   void find (int n) {

   D[0][0] = A[0][0];

   for(int i=1; i<=n; i++) 
   for(int j=1; j<=n; j++)
   P[i][j]= -1;

   for(int i=1; i<=n; i++)
   for(int j=0; j<i; j++)
   if (j == 0){
   D[i][j] = D[i-1][j] + A[i][j];
   P[i][j] = j;
   }else if(i == j){
   D[i][j] = D[i-1][j-1] + A[i][j];
   P[i][j] = j;
   }else {
   D[i][j] = max(D[i-1][j-1] + A[i][j], D[i-1][j] + A[i][j]);
   if (D[i-1][j-1] + A[i][j] == D[i-1][j] + A[i][j])
   D[i][j] = D[i-1][j-1] + A[i][j];
   P[i][j] = j;
   }
   }
   void path (int n, int x){
   for(int j=0; j<n; j++)
   cout << P[j][x] << " ";
   }
 */
int main() {

	//int x;
/*	int len = 0;
	int D[MAX][MAX];
	int P[MAX][MAX];
*/
	cin >> n;	// N 개수 입력

	for (int i=0; i<n; i++) 
		for (int j=0; j<=i; j++) 
			cin >> A[i][j];
	cost(n)
	/*

	D[0][0] = A[0][0];
	P[0][0] = A[0][0];
	//	find(n);
	for(int i=1; i<n; i++){
		for(int j=0; j<=i; j++){
			if (j == 0){
				D[i][j] = D[i-1][j] + A[i][j];
				P[i][j] = j;
			}else if(i == j){
				D[i][j] = D[i-1][j-1] + A[i][j];
				P[i][j] = j-1;
			}else {
				D[i][j] = max(D[i-1][j-1] + A[i][j], D[i-1][j] + A[i][j]);
				P[i][j] = (D[i-1][j-1] >= D[i-1][j]) ? j-1 : j;
			}
		}
	}
	for (int i=0; i<n; i++){
		if(D[n-1][i] >= len){
			len = D[n-1][i];
			//x = i;
		}
	}
	cout << len << endl;

	//	path(n, x);
	for(int i=0; i<n; i++){
		for(int j=0; j<=i; j++)
			cout << D[i][j] << " ";
		cout << endl;
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<=i; j++)
			cout << P[i][j] << " ";
		cout << endl;
	}
	*/

	return 0;
}
