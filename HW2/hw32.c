#include <stdio.h>
#include <math.h>
#include <limits.h>
#define MAX sizeof(int) 

int b[MAX][MAX];
int cnt = 0;

void tromino(int mr, int mc, int row, int col, int filled_row, int filled_col){

	++cnt;	// 출력 번호 증가 

	int r=row, c=col, rmid, cmid, fr1, fr2, fr3, fr4, fc1, fc2, fc3, fc4;

	rmid = (mr / 2) + (r / 2);	// 중간값 지정 
	cmid = (mc / 2) + (c / 2); 

	fr1 = rmid-1, fc1 = cmid-1;		// 채울 자리 지정
	fr2 = rmid-1, fc2 = cmid;
	fr3 = rmid, fc3 = cmid-1;
	fr4 = rmid, fc4 = cmid;

	if(filled_row < rmid && filled_col < cmid){		// 채워진자리 1분면에 위치
		b[fr2][fc2] = b[fr3][fc3] = b[fr4][fc4] = cnt;
		fr1 = filled_row, fc1 = filled_col;
	}
	else if(filled_row <= rmid && filled_col > cmid){		// 2분면에 위치
		b[fr1][fc1] = b[fr2][fc2] = b[fr4][fc4] = cnt;
		fr2 = filled_row, fc2 = filled_col;
	}
	else if(filled_row > rmid && filled_col <= cmid){		// 3분면에 위치
		b[fr1][fc1] = b[fr2][fc2] = b[fr4][fc4] = cnt;
		fr3 = filled_row, fc3 = filled_col;
	}
	else if(filled_row >= rmid && filled_col >= cmid){		// 4분면에 위치
		b[fr1][fc1] = b[fr2][fc2] = b[fr3][fc3] = cnt;
		fr4 = filled_row, fc4 = filled_col;
	}

	if(mr >= 2 && mc >= 2){
	tromino(mr/2, mc/2, r, c, fr1, fc1);	// 1분면 탐색

	tromino(mr/2, mc, r, cmid, fr2, fc2);	// 2분면 탐색

	tromino(mr, mc/2, rmid, c, fr3, fc3);	// 3분면 탐색

	tromino(mr, mc, rmid, cmid, fr4, fc4);	// 4분면 탐색
	}

}
int main(){

	int n, er, ec;
	scanf("%d", &n);
	scanf("%d %d", &er, &ec);

	int m = (int)pow(2, n);

	for(int i=0; i<m; i++){		// 배열 초기화
		for(int j=0; j<m; j++){
			b[i][j] = 0;
		}	
	}

	tromino(m, m, 0, 0, er, ec);

	for(int i=0; i<m; i++){
		for(int j=0; j<m; j++){
			printf("%d ", b[i][j]);
		}
		printf("\n");
	}
}

