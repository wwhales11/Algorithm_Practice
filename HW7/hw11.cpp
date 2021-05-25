/* 
 * [2019117662] [박수환] 저는 이 소스 코드를 다른 소스 코드를 복사하지 않고 직접 작성하였습니다. 
 */

#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 17	

using namespace std;
typedef vector<int> sequence_of_integer;
int deadline[MAX], profit[MAX];

void profitSort(int n);
void schedule(int n, int deadline[], sequence_of_integer &J); 
bool is_feasible(sequence_of_integer K, int deadline[]); 


int main(){

	int n, res = 0;
	vector<int> J;

	cin >> n;	// job 개수

	// deadline input
	for (int i = 1; i <= n; i++)
		cin >> deadline[i];
	// profit input
	for (int i = 1; i <= n; i++)
		cin >> profit[i];

	// profit sort
	profitSort(n);

	cout << "Profit = ";
	for (int i = 1; i <= n; i++)
		cout << profit[i] << " ";
	cout << endl;
	cout << "Deadline = ";
	for (int i = 1; i <= n; i++)
		cout << deadline[i] << " ";
	cout << endl;

	schedule(n, deadline, J);

	for (vector<int>::iterator it = J.begin(); it != J.end(); it++)
		res += profit[*it];

	cout << res << endl;

	return 0;
}
void profitSort(int n){
	for (int i = 1; i <= n; i++)
		for (int j = i+1; j <= n; j++)
			if(profit[i] < profit[j]){
				swap(profit[i], profit[j]);
				swap(deadline[i], deadline[j]);
			}
}
void schedule(int n, int deadline[], sequence_of_integer &J) {
	sequence_of_integer K;
	J = {1};
	cout << "초기화 J배열 = ";
	for (auto x : J)
		cout << x << " ";
	cout << endl;

	for (int i = 2; i <= n; i++) {
	//	K = J;
		K.resize(J.size());
		copy(J.begin(), J.end(), K.begin());

		vector<int>::iterator it = K.begin();
		while (deadline[*it] <= deadline[i]){
			if (i <= *it) break;
			it++;
		}
		if (it > K.end())
			K.push_back(i);
		else
			K.insert(it, i);

		cout << "K배열 = ";
		for (vector<int>::iterator it = K.begin(); it != K.end(); it++)
			cout << *it << " ";
		cout << endl;

		if (is_feasible(K, deadline)) {
			// J = K
			J.resize(K.size());
			copy(K.begin(), K.end(), J.begin());
		}
		cout << "J배열 = ";
		for (vector<int>::iterator it = J.begin(); it != J.end(); it++)
			cout << *it << " ";
		cout << endl;

	}
}
bool is_feasible(sequence_of_integer K, int deadline[]) {
	vector<int>::iterator it = K.begin();
	for (int i = 1; it != K.end(); it++, i++)
		if (i > deadline[*it])
			return false;
	return true;
}
