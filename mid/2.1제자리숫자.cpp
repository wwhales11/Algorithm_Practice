//제자리숫자

#include <iostream>
#include <vector>
#define MAX 256

using namespace std;

int main(){

	int t, n; 
	int ans[MAX];

	cout << "숫자입력 횟수 : ";
	cin >> t;

	for(int i=0; i<t; i++){
		ans[i] = -1;

		cout << "배열갯수 : ";
		cin >> n;

		int s[MAX];

		cout << "배열리스트 입력 : ";
		for(int j=0; j<n; j++){ 	// n번 스캔 후 배열에 입력
			cin >> s[j];
			if (s[j] == j) 
				ans[i] = j;
		}
	}

	cout << "= 제자리숫자 =\n";
	for (int i = 0; i < t; i++){
		if(ans[i] >= 0){
			cout << ans[i] << endl;
		}else{
			cout << "NONE" << endl;
		}
	}

	return 0;
}


