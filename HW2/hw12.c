#include <stdio.h>

int main(){

	int t = 101;
	int n = 100001; 

	scanf("%d", &t);	
	int s[t][n];

	for(int i=0; i<t; i++){
		scanf("%d", &n);
		for(int j=0; j<n; j++){
			scanf("%d", &s[i][j]);
		}
	}
	for(int i=0; i<t; i++){
		int x=0;
		for(int j=0; j<100001; j++){
			if(s[i][j] == j){
				printf("%d\n", j);
				x = 1;
			}
		}
		if(!x) printf("NONE\n");
	}
}


