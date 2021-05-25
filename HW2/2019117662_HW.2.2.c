#include <stdio.h>

int main(){

	int n =0, m=0, t=0;

	scanf("%d %d", &n, &m);

	int tarr[n][m];

	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			scanf("%d", &tarr[i][j]);
		}
	}

	scanf("%d", &t);

	int tc[t];

	for(int i=0; i<t; i++){
		scanf("%d", &tc[i]);
	}

	for(int k=0; k<t; k++){
		int x =0;

		for(int i=0; i<n/2; i++){		// 1분면 탐색
			for(int j=0; j<m/2; j++){
				if(tc[k] == tarr[i][j]){
					printf("%d %d\n", i, j);
					x=1;
				}
			}
		}
		for(int i=n/2; i<n; i++){		// 2분면 탐색
			for(int j=0; j<m/2; j++){
				if(tc[k]== tarr[i][j]){
					printf("%d %d\n", i, j);
					x=1;
				}
			}
		}
		for(int i=0; i<n/2; i++){		// 3분면 탐색
			for(int j=m/2; j<m; j++){
				if(tc[k]== tarr[i][j]){
					printf("%d %d\n", i, j);
					x=1;
				}
			}
		}
		for(int i=n/2; i<n; i++){		// 4분면탐색
			for(int j=m/2; j<m; j++){
				if(tc[k]== tarr[i][j]){
					printf("%d %d\n", i, j);
					x=1;
				}
			}
		}
		if(!x) printf("NONE\n");
	}

}

