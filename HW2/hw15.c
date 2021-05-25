#include <stdio.h>

long long stay(long long n, long long *s){
	 
	for(int i=0; i<n; i++){
		if(i == s[i]){
		return i;
		}
	}
	return -10;
}
int main(){

	int t;
	long long n; 

	scanf("%d", &t);	
	long long res[t];

	for(int i=0; i<t; i++){
		scanf("%lld", &n);
		long long s[n];
		for(int j=0; j<n; j++){ 	// n번 스캔 후 배열에 입력
			scanf("%lld", &s[j]);
		}
		res[i] = stay(n, s);
	}

/*	for(int l=0; l<t; l++){
	printf("%d\n", res[l]);
	}
*/
	for(int k=0; k<t; k++){
		if(res[k]>=0){
			printf("%lld\n", res[k]);
		}else{
			printf("NONE\n");
		}
	}
}


