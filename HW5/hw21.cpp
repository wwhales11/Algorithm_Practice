/* 
 * [2019117662] [박수환] 저는 이 소스 코드를 다른 소스 코드를 복사하지 않고 직접 작성하였습니다. 
 */

#include <iostream>
#include <algorithm>
#include <climits>
#define MAX 256	

using namespace std;

typedef struct node *node_pointer;
typedef struct node {
	int key;
	node_pointer left;
	node_pointer right;
} nodetype;

int A[MAX][MAX];	// 최적 횟수
int P[MAX][MAX];	// 루트노드
int K[MAX];		// 리스트 
int p[MAX]; 		// 검색빈도

/*
node_pointer tree(int i, int j) {
	int k;
	node_pointer p;
	k = P[i][j];
	if (k == 0)
		return NULL;
	else {
		p = (node_pointer)malloc(sizeof(nodetype));
		p->key = K[k];
		p->left = tree(i, k - 1);
		p->right = tree(k + 1, j);
		return p;
	}
}
void search(node_pointer tree, int keyin, node_pointer& p) {
	bool found;
	p = tree;
	found = false;
	while (!found) {
		if (p->key == keyin)
			found = true;
		else if (keyin < p->key)
			p = p->left;
		else
			p = p->right;
	}
}
*/
int sum(int i, int j){		// 루트노드까지의 빈도 합산
	int sum = 0;
	for ( ; i <= j; i++)
		sum += p[i];
	return sum;
}
void opTree(int n) { 			// 리스트의 최적탐색 횟수, 경로저장
	int i, j, diagonal;
	for (i = 1; i <= n; i++) {
		A[i][i] = p[i]; A[i][i - 1] = 0;
		P[i][i] = i;
		P[i][i - 1] = 0;
	}
	A[n + 1][n] = 0;
	P[n + 1][n] = 0;
	for (diagonal = 1; diagonal <= n - 1; diagonal++)
		for (i = 1; i <= n - diagonal; i++) {
			j = i + diagonal;
			int min = A[i][i-1] + A[i+1][j] + sum(i, j);
			for (int k = i; k <= j; k++) {
				if ((min >= A[i][k-1] + A[k+1][j] + sum(i, j))){
					min = A[i][k-1] + A[k+1][j] + sum(i, j);
					P[i][j] = k;
				}
			}
			A[i][j] = min;
		}
}
/*
int min(int i, int j) { 	// 최소 검색횟수 비교 후 전송
	int minV = INT_MAX;
	for (int k = i; k <= j; k++) {
		int value = A[i][k-1] + A[k+1][j] + sum(i, j);
		if (minV > value) {
			minV = value;
			root = k;
		}
	}
	return minV;
}
*/
int main(){

	int n;

	cin >> n;	// N 개수 입력
	for (int i=1; i <= n - 1; i++)	
		cin >> K[i];
	for (int i=1; i <= n - 1; i++)	
		cin >> p[i];

	opTree(n);

	for (int i=1; i <= n; i++){		// A배열 출력
		for (int j = i; j <= n; j++){
			if (A[i][j] != 0){
				cout << A[i][j];
				if ((j+1) <= n) cout << " ";
			}
		}
		cout << endl;
	}
	for (int i=1; i <= n; i++){		// P배열 출력
		for (int j = i; j <= n; j++){
			if (A[i][j] != 0){
				cout << P[i][j];
				if ((j+1) <= n) cout << " ";
			}
		}
		cout << endl;
	}
	return 0;
}
