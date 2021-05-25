#include <stdio.h>

int location(int low, int high, int *S, int x) {
	int mid;
	if (low > high)
		return -10;
	else {
		mid = (low + high) / 2;
		if (x == S[mid])
			return mid;
		else if (x < S[mid])
			return location(low, mid - 1, S, x);
		else
			return location(mid + 1, high, S, x);
	}
}

int main(){

	int t;
	int n; 

	scanf("%d", &t);	
	int res[t];

	for(int i=0; i<t; i++){
		scanf("%d", &n);
		int s[n];
		for(int j=0; j<n; j++){ 	// n번 스캔 후 배열에 입력
			scanf("%d", &s[j]);
		}
		for(int p=0; p<n; p++){
			int loc = location(0, n, s, p);
			if(loc == p){
		 	res[i] = p;
			}else{
			res[i] = -10;
			}
		}
	}

	for(int k=0; k<t; k++){
		if(res[k] >= 0){
			printf("%d\n", res[k]);
		}else{
			printf("NONE\n");
		}
	}

}


