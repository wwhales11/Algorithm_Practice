/* 
 * [2019117662] [박수환] 저는 이 소스 코드를 다른 소스 코드를 복사하지 않고 직접 작성하였습니다. 
 */

#include <iostream>
#include <algorithm>
#include <math.h>
#define MAX 256

using namespace std;
int S[MAX];
int cnt = 0;

int location(int low, int high, int x){	// 차소값 차대값 배열 두개 합산 함수
	cnt++;
	int mid = (low + high) / 2;
	if (low > high) return 0;
	
	if (x == S[mid]) return mid;
	else if (x < S[mid]) return location(low, mid-1, x);
	else
		return location(mid+1, high, x);
}
int main(){

	int n, x, t;

	cout << "개수입력 : ";
	cin >> n;	// N 개수 입력

	cout << "배열입력 : \n";
	for (int i = 1; i <= n; i++)
		cin >> S[i];

	cout << "테스트케이스 : ";
	cin >> t;

	cout << "찾는숫자 : ";
	for (int i = 1; i <= t; i++){
	cin >> x;
	cout << "X 위치 = " <<	location(1, n, x) << endl;
	cout << "location() 호출횟수 : " << cnt << endl;
	cnt = 0;
	}


	return 0;
}
