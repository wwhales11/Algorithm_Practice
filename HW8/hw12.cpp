/* 
 * [2019117662] [박수환] 저는 이 소스 코드를 다른 소스 코드를 복사하지 않고 직접 작성하였습니다. 
 */

#include <iostream>
#include <algorithm>

#define MAX 10	

using namespace std;

void queens(int i); 
bool promising(int i); 
int n, g = 1;
int col[MAX];
int res[MAX];
int inCol[MAX];

void queens(int i) {
	if (promising(i)){ 
		if (i == n){
			int sum = 0;
			for (int i = n; i > 0; i--){
				sum += col[i];
				if (i-1 > 0) sum *= 10;
			}
			res[g] = sum;
			g++;
		}
		else
			for (int j = 1; j <= n; j++) {
				col[i+1] = j;
				queens(i + 1);
			}
	}
}
bool promising(int i) {
	int k = 1;
	bool flag = true;
	while (k < i && flag) {
		if ((col[i] == col[k]) || (abs(col[i] - col[k]) == i - k))
			flag = false;
		k++;
	}
	return flag;
}
int main(){

	int t;
	int input;
	int path[MAX];

	cin >> n;
	queens(0);

	cin >> t;
	for (int k = 1; k <= t; k++){
		cin >> input;

		bool sflag = 0;
		for (int i = 1; i < g; i++){
			if(res[i] == input){
			sflag = 1;
			break;
			}
		}
		path[k] = sflag;
	}
	for (int i = 1; i <= t; i++){
		if (path[i]) cout << "YES\n";
		else cout << "NO\n";
	}

	return 0;
}
