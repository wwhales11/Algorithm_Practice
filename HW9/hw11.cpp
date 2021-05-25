/* 
 * [2019117662] [박수환] 저는 이 소스 코드를 다른 소스 코드를 복사하지 않고 직접 작성하였습니다. 
 */

#include <iostream>
#include <algorithm>
#include <queue>
#define MAX 256	

using namespace std;
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
		cout << "compare : " << p->unit_profit << " < " << q->unit_profit << endl;
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
		cout << "total_weight = " << total_weight << endl;
		total_profit += i->profit;
		if (PQ.empty() || total_weight >= W) {
			if(total_weight > W){
				total_weight -= i->weight;
				total_profit -= i->profit;
			}
			cout << "i->weight = " << i->weight << endl;
			int diff = W - total_weight;
			int profit = total_profit + diff * i->unit_profit;
			if(total_weight < W){
				total_weight = W;
				profit = total_profit;
			}

			cout << "maxWeight = " << total_weight << " maxProfit = " << profit << endl;
			break;
		}
		cout << "id = " << i->id << " weight = " << i->weight << " profit = " << i->profit << " unit_profit = " << i->unit_profit << endl;
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

	return 0;
}
