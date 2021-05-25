#include <stdio.h>

int s[100000];
int res[100];

int location(int low, int high, int x) {
	int mid;
	if (low > high)
		return -2;
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

	int t;
	int n; 

	scanf("%d", &t);	

	for(int i=0; i<t; i++){
		scanf("%d", &n);
		for(int j=0; j<n; j++){ 	// n번 스캔 후 배열에 입력
			scanf("%d", &s[j]);
		}
		for(int r=0; r<n; r++){
			if(r != location(0, n, r)){
				res[i] = -1;
			}else{
				res[i] = r;
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
	return 0;
}


