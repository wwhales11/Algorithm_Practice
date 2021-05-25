/* 
 * [2019117662] [박수환] 저는 이 소스 코드를 다른 소스 코드를 복사하지 않고 직접 작성하였습니다. 
 */

#include <iostream>
#include <algorithm>
#include <cstring>
#define MAX 256	

using namespace std;
void init(int n, int w[], int p[]);
void swap(int i, int j, int a[]);
void knapsack4(int i, int profit, int weight);
bool promising(int i, int profit, int weight);

int n, W, maxprofit, maxweight, maxBound;
int w[MAX], p[MAX];
int include[MAX], bestset[MAX];

void init(){
	for (int k = 1; k < n; k++){
		int maxUprofit = (float)p[k] / (float)w[k];
		int maxI = k;
		for (int i = k + 1; i <= n; i++) {
			if(maxUprofit < (float)p[i] / (float)w[i]){
				maxUprofit = (float)p[i] / (float)w[i];
				maxI = i;
			}
		}
		swap(k, maxI, p);
		swap(k, maxI, w);
	}
}
void swap(int i, int j, int a[]){
	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}
void knapsack4(int i, int profit, int weight) {
	if (weight <= W && profit > maxprofit) {
		maxprofit = profit;
		maxweight = weight; 
		maxBound = profit;
		if(i < n) maxBound += (W - weight) * ((float)p[i + 1] / w[i + 1]);
		memcpy(include, bestset, 100); 
	}
	if (promising(i, profit, weight)) {
		include[i + 1] = 1;
		knapsack4(i + 1, profit + p[i + 1], weight + w[i + 1]);
		include[i + 1] = 0;
		knapsack4(i + 1, profit, weight);
	}
}
bool promising(int i, int profit, int weight) {
	int j, k, totweight;
	float bound;
	if (weight >= W)
		return false;
	else {
		j = i + 1;
		bound = profit;
		totweight = weight;
//		maxBound = profit + (W - totweight) * ((float)p[k] / w[k]);
//		cout << maxBound << endl; 
		while (j <= n && totweight - w[j] <= W) {
			totweight += w[j];
			bound += p[j];
			j++;
		}
		k = j;
		if (k <= n)
			bound += (W - totweight) * ((float)p[k] / w[k]);
		return bound > maxprofit;
	}
}
int main(){

	int t;
	int maxP[MAX], maxW[MAX], maxB[MAX];

	cin >> n;	// N 개수 입력
	for(int i = 1; i <= n; i++)
		cin >> w[i];
	for(int i = 1; i <= n; i++)
		cin >> p[i];

	init();
/*
	for(int i = 1; i <= n; i++)
		cout << w[i] << " ";
	cout << endl;
	for(int i = 1; i <= n; i++)
		cout << p[i] << " ";
	cout << endl;
	*/

	cin >> t;

	for(int i = 1; i <= t; i++){
		cin >> W;
		maxprofit = 0;
		maxweight = 0;
		maxBound = 0;
		knapsack4(0, 0, 0); 
		maxP[i] = maxprofit;
		maxW[i] = maxweight;
		maxB[i] = maxBound;

		/*
		for (int i = 1; i <= n; i++)
			if (bestset[i]) cout << i << ":" << p[i] << " ";
		cout << endl;
		*/
	}
	for(int i = 1; i <= t; i++){
		cout << maxP[i] << " ";
		cout << maxW[i] << " ";
		cout << maxB[i] << endl;
	}

	return 0;
}

