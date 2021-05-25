#include <stdio.h>

int main(){

	int t;
	int n; 

	scanf("%d", &t);	

	for(int i=0; i<t; i++){
		scanf("%d", &n);
		int s[n];
		int x = 0;
		for(int j=0; j<n; j++){ 	// n번 스캔 후 배열에 입력
			scanf("%d", &s[j]);
		}
		for(int j=0; j<n; j++){		// 배열 탐색 
			if(j == s[j]){
			printf("%d\n", j);
			x = 1;
			break;		// 첫번째 제자리수만 추출
			}
		}
		if(!x) printf("NONE\n");
	}

}


