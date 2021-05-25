/* [2019117662] [박수환] 저는 이 소스 코드를 다른 소스 코드를 복사하지 않고 직접 작성하였습니다. 
 */

#include <iostream>
#include <vector>

using namespace std;


unsigned long long res[3] = {0, 0, 1};		// 결과 배열 {0 = 이전결과 | 1 = 현재결과 | 2 = 반복횟수 누적}

unsigned long long fib(unsigned long long n, unsigned long long itr, unsigned long long fone, unsigned long long ftwo){	// n = 기존입력, itr = 반복횟수, ftwo = 이전결과, fone = 현재결과 

	unsigned long long a = 0, b = 1, c, i;
	int turn =0 ;		// 함수 내부 반복횟수 

	if(itr > 1){		// 처음반복이 아닐 경우 이전값 대입 (연결) 
		a = ftwo, b = fone;
	}

	for (i=itr; i <= n+1 ; i++ ){ 

		if ( i <= 1 ) 
			c = i; 
		else 
		{ 
			c = (a + b) % 1000000; 
			res[0] = b;	// 이전입력 기록 b
			a = b; 
			b = c; 
		} 
		turn++;		// 반복횟수 기록
	}
	res[2] += turn;		// 기존반복에 새롭게 반복횟수 추가 (누적 반복횟수 기록)
	res[1] = c;

	return *res; 
}

int main(){

	unsigned long long count;

	cin >> count;	// N 개수 입력

	vector<unsigned long long> v(count);		// 숫자입력 백터

	for(unsigned int i=0; i < v.size(); i++){	// 숫자입력
		cin >> v.operator[](i);
	}

	for(unsigned int i=0; i < v.size(); i++){	

		fib(v[i], res[2], res[1], res[0]);

		cout << res[1] << "\n";			// 결과값 출력	

	}

	return 0;
}
