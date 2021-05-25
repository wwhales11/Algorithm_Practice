/* 
 * [2019117662] [박수환] 저는 이 소스 코드를 다른 소스 코드를 복사하지 않고 직접 작성하였습니다. 
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

#define SIZE 10		// 배열최고값 10

using namespace std;

void sumArr(int L[], int R[], int sum[]){	// 차소값 차대값 배열 두개 합산 함수
	int loopIndex, supp = 0;
	for(loopIndex = 0;loopIndex<SIZE;loopIndex++){
		sum[loopIndex] = L[loopIndex] + R[loopIndex] + supp;

		if (sum[loopIndex] > 9){
			sum[loopIndex] -= 10;
			supp = 1;
		}
		else{
			supp = 0;
		}
	}
	for(int i=loopIndex-1; i>=0; i--){	// 합산(sum) 배열 높은자리수부터 출력
		cout << sum[i];
	}

}

int main(){

	int count;
	unsigned long long sSmall, sLarge;

	cin >> count;	// N 개수 입력

	vector<unsigned long long> v(count);

	int vArr1[] = {0}, vArr2[] = {0}, s[] = {0};	// 정수형 벗어난 덧셈값 배열로 구현


	for(unsigned int i=0; i < v.size(); i++){
		cin >> v.operator[](i);
	}
	if(count>5 && count<1000){

		sort(v.begin(), v.end());	// 순서 정렬
		sSmall = v[1];
		sLarge = v[count-2];	

		cout << sSmall << " " << sLarge << " " ;	// 차소값, 차대값 먼저 출력


		if(sSmall + sLarge < pow(2, 64)){	// 합산이 정수형 범위에 들어올 경우
			cout << sSmall + sLarge << endl;
		}else{				// 합산이 정수형 범위를 초과할 경우 (배열로 전환 후 배열로 30자리까지 표현)

			for(int i=0; i<SIZE; i++){	// 차소값 vArr1배열에 입력 (역순)
				vArr2[i] = sSmall % 10;
				sSmall /= 10;
			}

			for(int j=0; j<SIZE; j++){	// 차대값 vArr2배열에 입력 (역순)
				vArr2[j] = sLarge % 10;
				sLarge /= 10;
			}

			sumArr(vArr1, vArr2, s);	// 차소값 차대값 배열 합산 
		}
	}
	return 0;
}
