#include <stdio.h>

int main(){

	int t, n; 

	scanf("%d", &t);
	int res[t];

	for(int i=0; i<t; i++){

		scanf("%d", &n);
		int s[n];
		int x = -1;

		for(int i=0; i<n; i++){
			scanf("%d", &s[i]);
			if(s[i] == i){
				x = i;
			}

		}
		res[i] = x;
	}

	for(int i=0; i<t; i++){
	
		if(res[i] >= 0){
			printf("%d\n", res[i]);
		}else{
			printf("NONE\n");
		}
	}
}
