#include <stdio.h>

int main(){

	int t;
	long long n; 
	long long s[100000];
	long long res[100];

	scanf("%d", &t);	

	for(int i=0; i<t; i++){
		scanf("%lld", &n);
		for(long long j=0; j<n; j++){ 	// n번 스캔 후 배열에 입력
			scanf("%lld", &s[j]);
		}

		for(long long e=0; e<n; e++){		// 배열 탐색 
			if(e == s[e]){
				res[i] = e;
				break;
			}else{
			res[i] = -1;
			}
		}
	}

	for(int k=0; k<t; k++){
		if(res[k] >= 0){
			printf("%lld\n", res[k]);
		}else{
			printf("NONE\n");
		}
	}
	return 0;
}


