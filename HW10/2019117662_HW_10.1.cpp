/* 
 * [2019117662] [박수환] 저는 이 소스 코드를 다른 소스 코드를 복사하지 않고 직접 작성하였습니다. 
 */

#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#define MAX 256	

using namespace std;

int n, W, maxprofit, maxweight, maxBound, maxCnt, cnt = 0;
int w[MAX], p[MAX];

typedef struct node *node_pointer;
typedef struct node {
	int level;
	int weight;
	int profit;
	float bound;
} nodetype;

struct compare {
	bool operator()(node_pointer u, node_pointer v) {
		if (u->bound < v->bound)
			return true;
		return false;
	}
};
typedef priority_queue<node_pointer, vector<node_pointer>, compare> priority_queue_of_node;

void init();
void swap(int i, int j, int a[]);
node_pointer create_node(int level, int weight, int profit);
float bound(node_pointer u);
void knapsack6();

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

node_pointer create_node(int level, int weight, int profit) {
	node_pointer v = (node_pointer)malloc(sizeof(nodetype));
	v->level = level;
	v->weight = weight;
	v->profit = profit;
	v->bound = bound(v);
	return v;
}
float bound(node_pointer u) {
	int j, k, totweight; float result;
	if (u->weight >= W)
		return 0;
	else {
		result = u->profit;
		j = u->level + 1;
		totweight = u->weight;
		while (j <= n && totweight + w[j] <= W) {
			totweight += w[j];
			result += p[j];
			j++;
		}
		k = j;
		if (k <= n)
			result += (W - totweight) * ((float)p[k] / w[k]);
		return result;
	}
}
void knapsack6() {
	priority_queue_of_node PQ; node_pointer u, v;
	maxprofit = 0;
	PQ.push(create_node(0, 0, 0));
	while (!PQ.empty()) {
		v = PQ.top();
		PQ.pop();
		if (v->bound > maxprofit) {
			u = create_node(v->level + 1, v->weight + w[v->level + 1], v->profit + p[v->level + 1]);
			if (u->weight <= W && u->profit > maxprofit){
				maxprofit = u->profit;
				maxweight = u->weight;
				maxBound = u->bound;
				//if(cnt < n) maxBound += (W - u->weight) * ((float)p[cnt + 1] / w[cnt + 1]);
			}
			if (u->bound > maxprofit){
				PQ.push(u);
				cnt++;
			}

			u = create_node(v->level + 1, v->weight, v->profit);
			if (u->bound > maxprofit){
				PQ.push(u);
				cnt++;
			}
		}
	}
	maxCnt = cnt + 1;
}
int main(){

	int t;
	int maxP[MAX], maxW[MAX], maxB[MAX], maxC[MAX];

	cin >> n;	// N 개수 입력
	for(int i = 1; i <= n; i++)
		cin >> w[i];
	for(int i = 1; i <= n; i++)
		cin >> p[i];

	init();

	cin >> t;

	for(int i = 1; i <= t; i++){
		cin >> W;
		knapsack6(); 
		maxP[i] = maxprofit;
		maxW[i] = maxweight;
		maxB[i] = maxBound;
		maxC[i] = maxCnt;
		cnt = 0;
	}
	for(int i = 1; i <= t; i++){
		cout << maxP[i] << " ";
		cout << maxW[i] << " ";
		cout << maxB[i] << " ";
		cout << maxC[i] << endl;
	}

	return 0;
}

