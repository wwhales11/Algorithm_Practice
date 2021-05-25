/* 
 * [2019117662] [박수환] 저는 이 소스 코드를 다른 소스 코드를 복사하지 않고 직접 작성하였습니다. 
 */

#include <iostream>
#include <algorithm>

#define MAX 257	

using namespace std;

int P[MAX][MAX];

void knapsack2(int n, int W, int w[], int p[], int P[][MAX]) {
	for (int i = 1; i <= n; i++)
		P[i][0] = 0;
	for (int j = 1; j <= W; j++)
		P[0][j] = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= W; j++)
			P[i][j] = (w[i] > j) ? P[i - 1][j] :
				max(P[i-1][j], p[i] + P[i-1][j-w[i]]);
}
int main(){

	int n, W;
	int t;
	int w[MAX], p[MAX];
	int maxP[MAX], pw1[MAX], pw2[MAX];

	cin >> n;	// N 개수 입력
	for(int i = 1; i <= n; i++)
		cin >> w[i];
	for(int i = 1; i <= n; i++)
		cin >> p[i];

	cin >> t;

	for(int i = 1; i <= t; i++){
		cin >> W;
		knapsack2(n, W, w, p, P); 
		maxP[i] = P[n][W];
		pw1[i] = P[n-1][W];
		pw2[i] = P[n-1][W - w[n]];
	}
	for(int k = 1; k <= t; k++){
		cout << maxP[k] << " ";
		cout << pw1[k] << " ";
		cout << pw2[k] << endl;
	}

	return 0;
}

