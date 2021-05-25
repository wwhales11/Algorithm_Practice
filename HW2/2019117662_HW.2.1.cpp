#include <iostream>
#include <vector>

using namespace std;


int main(){

	int t, n; 

	cin >> t;

	vector<int> res;
	vector<int> s;

	for(int i=1; i<=t; i++){

		cin >> n;

		for(int j=0; j<n; j++){ 	// n번 스캔 후 배열에 입력
			cin >> s.at(j);
			if(s[j] != j){
				res.at(i) = -1;
			}else{
			res.at(i) = s.at(j);
			}
		}
	}

	for(vector<int>::size_type k=1; k<=res.size(); k++){
		if(res[k] >= 0){
			cout << res[k] << endl;
		}else{
			cout << "NONE" << endl;
		}
	}
	return 0;
}


