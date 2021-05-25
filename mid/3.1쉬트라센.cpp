/* 
* [2019117662] [박수환] 저는 이 소스 코드를 다른 소스 코드를 복사하지 않고 직접 작성하였습니다. 
*/

#include <stdio.h>
#include <iostream>
#include <math.h>
#define MAX 128 

using namespace std;

int a[MAX][MAX], b[MAX][MAX], c[MAX][MAX];
int count = 0;
int mul = 0;
const int threshold = 4;

void madd(int n, int a[][MAX], int b[][MAX], int c[][MAX]);
void msub(int n, int a[][MAX], int b[][MAX], int c[][MAX]);
void mmult(int n, int a[][MAX], int b[][MAX], int c[][MAX]);
void partition(int n, int a[][MAX], int a11[][MAX], int a12[][MAX], int a21[][MAX], int a22[][MAX]);
void combined(int n, int a[][MAX], int a11[][MAX], int a12[][MAX], int a21[][MAX], int a22[][MAX]);
void strassen(int n, int a[][MAX], int b[][MAX], int c[][MAX]);

int main(){

	int n;

	cout << "행렬크기 : ";
	scanf("%d", &n);

	cout << "행렬 A, B : \n";
	for(int i=0; i<n; i++){			// a배열 입력
		for(int j=0; j<n; j++){
			scanf("%d", &a[i][j]);
		}
	}
	for(int i=0; i<n; i++){			// b배열 입력
		for(int j=0; j<n; j++){
			scanf("%d", &b[i][j]);
		}
	}

	strassen(n, a, b, c);			// 쉬트라센 함수실행

	cout << "strassen() 호출횟수 : ";
	printf("%d\n", count);

	cout << mul <<endl;
/*	cout << "행렬 C(곱) : \n";
	for(int i=0; i<n; i++){			// c배열 출력
		for(int j=0; j<n; j++){
			printf("%d ", c[i][j]);
		}
		printf("\n");
	}
	*/
	return 0;
}


void strassen(int n, int a[][MAX], int b[][MAX], int c[][MAX]){
	int a11[MAX][MAX], a12[MAX][MAX], a21[MAX][MAX], a22[MAX][MAX];
	int b11[MAX][MAX], b12[MAX][MAX], b21[MAX][MAX], b22[MAX][MAX];
	int c11[MAX][MAX], c12[MAX][MAX], c21[MAX][MAX], c22[MAX][MAX];
	int m1[MAX][MAX], m2[MAX][MAX], m3[MAX][MAX], m4[MAX][MAX], m5[MAX][MAX], m6[MAX][MAX], m7[MAX][MAX]; 
	int l[MAX][MAX], r[MAX][MAX];

	++count;		// 쉬트라센 함수 실행횟수 증가

	if (n <= threshold) { 	// threshold 입구컷
		mmult(n, a, b, c);
		mul++;
	}
	else {
		if (n & (n - 1)) {		// 거듭제곱이 아닌 수
			for (int k=2; k<=7; k++){	// 128까지 비교 후 0채움 
				if (n > pow(2, (k-1)) && n < pow(2, k)){
					for (int i=0; i<(n+(pow(2, k)-n)); i++){
						for (int j=0; j<(n+(pow(2, k)-n)); j++){
							if (i > n || j > n){
								a[i][j] = 0;
							}
						}
					}
				}
			}
			++n;
		}
		int m = n / 2;

		partition(n, a, a11, a12, a21, a22);
		partition(n, b, b11, b12, b21, b22);

		madd(m, a11, a22, l);
		madd(m, b11, b22, r);
		strassen(m, l, r, m1);
		
		cout << "m1 = "	<< endl;
		for(int i=0; i<m; i++){
			for(int j=0; j<m; j++)
				cout << m1[i][j] << " ";
		cout << endl;
		}

		madd(m, a21, a22, l);
		strassen(m, l, b11, m2);

		cout << "m2 = "	<< endl;
		for(int i=0; i<m; i++){
			for(int j=0; j<m; j++)
				cout << m2[i][j] << " ";
		cout << endl;
		}
		msub(m, b12, b22, r);
		strassen(m, a11, r, m3);

		cout << "m3 = "	<< endl;
		for(int i=0; i<m; i++){
			for(int j=0; j<m; j++)
				cout << m3[i][j] << " ";
		cout << endl;
		}
		msub(m, b21, b11, r);
		strassen(m, a22, r, m4);

		cout << "m4 = "	<< endl;
		for(int i=0; i<m; i++){
			for(int j=0; j<m; j++)
				cout << m4[i][j] << " ";
		cout << endl;
		}
		madd(m, a11, a12, l);
		strassen(m, l, b22, m5);

		cout << "m5 = "	<< endl;
		for(int i=0; i<m; i++){
			for(int j=0; j<m; j++)
				cout << m5[i][j] << " ";
		cout << endl;
		}
		msub(m, a21, a11, l);
		madd(m, b11, b12, r);
		strassen(m, l, r, m6);

		cout << "m6 = "	<< endl;
		for(int i=0; i<m; i++){
			for(int j=0; j<m; j++)
				cout << m6[i][j] << " ";
		cout << endl;
		}
		msub(m, a12, a22, l);
		madd(m, b21, b22, r);
		strassen(m, l, r, m7);

		cout << "m7 = "	<< endl;
		for(int i=0; i<m; i++){
			for(int j=0; j<m; j++)
				cout << m7[i][j] << " ";
		cout << endl;
		}
		// making c[]	

		madd(m, m1, m4, l);
		msub(m, l, m5, r);
		madd(m, r, m7, c11);

		madd(m, m3, m5, c12);

		madd(m, m2, m4, c21);

		madd(m, m1, m3, l);
		msub(m, l, m2, r);
		madd(m, r, m6, c22);

		combined(n, c, c11, c12, c21, c22);
	}
}

void madd(int n, int a[][MAX], int b[][MAX], int c[][MAX]){
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			c[i][j] = a[i][j] + b[i][j];
		}
	}
}
void msub(int n, int a[][MAX], int b[][MAX], int c[][MAX]){
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			c[i][j] = a[i][j] - b[i][j];
		}
	}
}
void mmult(int n, int a[][MAX], int b[][MAX], int c[][MAX]){
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			c[i][j] = 0;
			for(int k=0; k<n; k++){
				c[i][j] += a[i][k] * b[k][j];
			}
		}
	}
}

void partition(int n, int a[][MAX], int a11[][MAX], int a12[][MAX], int a21[][MAX], int a22[][MAX]){
	int m = n / 2;
	for (int i=0; i<m; i++){
		for (int j=0; j<m; j++){
			a11[i][j] = a[i][j];
			a12[i][j] = a[i][j + m];
			a21[i][j] = a[i + m][j];
			a22[i][j] = a[i + m][j + m];
		}
	}
}
void combined(int n, int a[][MAX], int a11[][MAX], int a12[][MAX], int a21[][MAX], int a22[][MAX]){
	int m = n / 2;
	for (int i=0; i<m; i++){
		for (int j=0; j<m; j++){
			a[i][j] = a11[i][j];
			a[i][j + m] = a12[i][j];
			a[i + m][j] = a21[i][j];
			a[i + m][j + m] = a22[i][j];
		}
	}
}


