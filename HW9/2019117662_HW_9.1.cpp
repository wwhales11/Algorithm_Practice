/* 
 * [2019117662] [박수환] 저는 이 소스 코드를 다른 소스 코드를 복사하지 않고 직접 작성하였습니다. 
 */

#include <iostream>
#include <algorithm>
#include <queue>
#define MAX 256	

using namespace std;

int maxW[MAX], maxP[MAX];
int k = 1;

typedef struct item *item_pointer;
typedef struct item {
	int id;
	int weight;
	int profit;
	float unit_profit;
} itemtype;
struct compare {
	// 내림차순
	bool operator()(item_pointer p, item_pointer q) {
		if (p->unit_profit < q->unit_profit)
			return true;
		return false;
	}
};
void initialize(priority_queue<item_pointer, vector<item_pointer>, compare> &PQ, int n, int w[], int p[]){

	for (int i = 1; i <= n; i++) {
		item_pointer item = (item_pointer)malloc(sizeof(itemtype));
		item->id = i;
		item->weight = w[i];
		item->profit = p[i];
		item->unit_profit = (float)p[i] / (float)w[i];
		PQ.push(item);
	}
}
void knapsack1(int n, int W, int w[], int p[]) {

	priority_queue<item_pointer, vector<item_pointer>, compare> PQ;
	initialize(PQ, n, w, p);
	int total_weight = 0;
	int total_profit = 0;
	while (!PQ.empty()) {
		item_pointer i = PQ.top();
		PQ.pop();
		total_weight += i->weight;
		total_profit += i->profit;
		if (PQ.empty() || total_weight >= W) {
			int diff = 0;
			if(total_weight > W){
				total_weight -= i->weight;
				total_profit -= i->profit;
				diff = W - total_weight;
				total_weight = W;
			}

			int profit = total_profit + diff * i->unit_profit;

			maxW[k] = total_weight; 
			maxP[k] = profit;
			k++;
			break;
		}
	}
}
int main(){

	int n, W;
	int t;
	int w[MAX], p[MAX];

	cin >> n;	// N 개수 입력
	for(int i = 1; i <= n; i++)
		cin >> w[i];
	for(int i = 1; i <= n; i++)
		cin >> p[i];

	cin >> t;

	for(int i = 1; i <= t; i++){
		cin >> W;
		knapsack1(n, W, w, p); 
	}
	for(k = 1; k <= t; k++){
		cout << maxW[k] << " ";
		cout << maxP[k] << endl;
	}

	return 0;
}
