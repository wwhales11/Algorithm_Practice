/* 
 * [2019117662] [박수환] 저는 이 소스 코드를 다른 소스 코드를 복사하지 않고 직접 작성하였습니다. 
 */
#include <iostream>
#include <algorithm>
#define MAX 256	

using namespace std;

void sum_of_subsets(int i, int weight, int total);
bool promising(int i, int weight, int total);

int n, W;
int w[MAX];
int cnt = 0;
bool include[MAX];

void sum_of_subsets(int i, int weight, int total) {
	if (promising(i, weight, total)) {
		if (weight == W){
			for (int k = 1; k <= n; k++){
				if (include[k] == true) cout << w[k] << " ";
			}
			cout << endl;
			cnt++;
		}
		else {
			include[i + 1] = true;
			sum_of_subsets(i + 1, weight + w[i + 1], total - w[i + 1]);
			include[i + 1] = false;
			sum_of_subsets(i + 1, weight, total - w[i + 1]);
		}
	}
}
bool promising(int i, int weight, int total) {
	return (weight + total >= W) && (weight == W || weight + w[i + 1] <= W);
}

int main(){

	int total = 0;
	cin >> n >> W;

	for (int i = 1; i <= n; i++){
		cin >> w[i];
		total += w[i];
	}

	sort(w + 1, w + n);	
	for (int i = 1; i <= n; i++)
		cout << w[i] << " ";
	cout << endl;

	sum_of_subsets(0, 0, total);

	cout << "cnt = " << cnt << endl;

	return 0;
}
