/* 
 * [2019117662] [박수환] 저는 이 소스 코드를 다른 소스 코드를 복사하지 않고 직접 작성하였습니다. 
 */

#include <iostream>
#include <algorithm>

#define MAX 10	

using namespace std;

void queens(int i); 
bool promising(int i); 
int n;
char col[MAX];

void queens(int i) {
	if (promising(i)){ 
	if (i == n){
		for (int i = 1; i <= n; i++) 
			cout << col[i] << " ";
		cout << endl;
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

	cin >> n;
	queens(0);

	return 0;
}
