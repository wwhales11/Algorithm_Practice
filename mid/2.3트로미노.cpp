#include <stdio.h>
#include <math.h>
#include <limits.h>
#define MAX 10000 

int b[MAX][MAX];
int cnt = 0;

void tromino(int m, int row, int col, int filled_row, int filled_col){

	++cnt;	// 출력 번호 증가 

	int r=row, c=col, rmid, cmid, fr1, fr2, fr3, fr4, fc1, fc2, fc3, fc4;

	if(m == 2){		// m이 2와 같을 때 채움 (가장 작은 단위)

		fr1 = r, fc1 = c;		// 채울 자리 지정
		fr2 = r, fc2 = c+1;
		fr3 = r+1, fc3 = c;
		fr4 = r+1, fc4 = c+1;

		if(filled_row == fr1 && filled_col == fc1){		// 채워진자리 1분면에 위치
			b[fr2][fc2] = b[fr3][fc3] = b[fr4][fc4] = cnt;
			fr1 = filled_row, fc1 = filled_col;
		}
		else if(filled_row == fr2 && filled_col == fc2){		// 2분면에 위치
			b[fr1][fc1] = b[fr3][fc3] = b[fr4][fc4] = cnt;
			fr2 = filled_row, fc2 = filled_col;
		}
		else if(filled_row == fr3 && filled_col == fc3){		// 3분면에 위치
			b[fr1][fc1] = b[fr2][fc2] = b[fr4][fc4] = cnt;
			fr3 = filled_row, fc3 = filled_col;
		}
		else if(filled_row == fr4 && filled_col == fc4){		// 4분면에 위치
			b[fr1][fc1] = b[fr2][fc2] = b[fr3][fc3] = cnt;
			fr4 = filled_row, fc4 = filled_col;
		}

	}else{

		rmid = (m / 2) + r;	// 중간값 지정 
		cmid = (m / 2) + c; 

		fr1 = rmid-1, fc1 = cmid-1;		// 채울 자리 지정
		fr2 = rmid-1, fc2 = cmid;
		fr3 = rmid, fc3 = cmid-1;
		fr4 = rmid, fc4 = cmid;

		if(filled_row <= fr1 && filled_col <= fc1){		// 채워진자리 1분면에 위치
			b[fr2][fc2] = b[fr3][fc3] = b[fr4][fc4] = cnt;
			fr1 = filled_row, fc1 = filled_col;
		}
		if(filled_row <= fr2 && filled_col >= fc2){		// 2분면에 위치
			b[fr1][fc1] = b[fr3][fc3] = b[fr4][fc4] = cnt;
			fr2 = filled_row, fc2 = filled_col;
		}
		if(filled_row >= fr3 && filled_col <= fc3){		// 3분면에 위치
			b[fr1][fc1] = b[fr2][fc2] = b[fr4][fc4] = cnt;
			fr3 = filled_row, fc3 = filled_col;
		}
		if(filled_row >= fr4 && filled_col >= fc4){		// 4분면에 위치
			b[fr1][fc1] = b[fr2][fc2] = b[fr3][fc3] = cnt;
			fr4 = filled_row, fc4 = filled_col;
		}

		tromino(m/2, r, c, fr1, fc1);	// 1분면 탐색
		tromino(m/2, r, cmid, fr2, fc2);	// 2분면 탐색
		tromino(m/2, rmid, c, fr3, fc3);	// 3분면 탐색
		tromino(m/2, rmid, cmid, fr4, fc4);	// 4분면 탐색

	}
}

int main(){

	int n, er, ec;
	printf("행렬숫자 입력(2^n) : ");
	scanf("%d", &n);
	printf("0의 위치입력 (er, ec) : ");
	scanf("%d %d", &er, &ec);

	printf("\n\n");

	int m = (int)pow(2, n);

	tromino(m, 0, 0, er, ec);

	for(int i=0; i<m; i++){
		for(int j=0; j<m; j++){
			if (b[i][j] < 10) printf(" ");
			if (b[i][j] < 100) printf(" ");
			printf("%d ", b[i][j]);
		}
		printf("\n\n");
	}

	printf("\ntromino() 출력횟수 : %d\n", cnt); 
}

