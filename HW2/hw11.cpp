#include <iostream>
#include <limits.h>
#include <vector>

using namespace std;

vector<int> s;

long unsigned int location(int low, int high, int x) {
	int mid;
	if (low > high)
		return 0;
	else {
		mid = (low + high) / 2;
		if (x == s[mid])
			return mid;
		else if (x < s[mid])
			return location(low, mid - 1, x);
		else
			return location(mid + 1, high, x);
	}
}
int main(){

	int t, n; 

	cin >> t;

	vector<int> res;

	for(int i=1; i<=t; i++){
		cin >> n;
		for(int j=1; j<=n; j++){ 	// n번 스캔 후 배열에 입력
			cin >> s[j];
		}

		if(s[0] == 0){
			res[0] = 0;
		}
		else{
			res[0] = 1;
		}

		for(vector<int>::size_type r=1; r<=s.size(); r++){
			if(r == location(1, n, r)){
				res[i] = r;
			}else{
				res[i] = 0;
			}
		}
		s.clear();
	}


	if(res[0] == 0){
		cout << 0 << endl;
	}

	for(vector<int>::size_type k=1; k<=res.size(); k++){
		if(res[k] > 0){
			cout << res[k] << endl;
		}else{
			cout << "NONE" << endl;
		}
	}
	return 0;
}


