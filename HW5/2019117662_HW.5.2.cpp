/* 
 * [2019117662] [박수환] 저는 이 소스 코드를 다른 소스 코드를 복사하지 않고 직접 작성하였습니다. 
 */

#include <iostream>
#include <vector>
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
int K[17];		// 리스트 
int p[17]; 		// 검색빈도
int n;
vector<int> pre;
vector<int> in;

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
void preorder(node_pointer p) {
	if (p) {
		pre.push_back(p->key);
		preorder(p->left);
		preorder(p->right);
	}
}
void inorder(node_pointer p) {
	if (p) {
		inorder(p->left);
		in.push_back(p->key);
		inorder(p->right);
	}
}
int sig(int i, int j){		// 루트노드까지의 빈도 합산
	int sum = 0;
	for (int t=i; t <= j; t++)
		sum += p[t];
	return sum;
}

int min(int i, int j, int *k) { 	// 최소 검색횟수 비교 후 전송
	int minV = INT_MAX;
	for (int key = i; key <= j; key++) {
		int value = A[i][key-1] + A[key+1][j];
		if (minV > value) {
			minV = value;
			*k = key;
		}
	}
	return minV;
}
void opTree(int n) { 			// A배열, P배열 저장
	int i, j, k, diagonal;
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
			A[i][j] = min(i, j, &k) + sig(i, j);
			P[i][j] = k;
		}
}

int main(){

	cin >> n;	// N 개수 입력
	for (int i=1; i <= n; i++)	
		cin >> K[i];
	for (int i=1; i <= n; i++)	
		cin >> p[i];

	opTree(n);

	for (int i=1; i <= n; i++){		// A배열 출력
		for (int j = 0; j <= n; j++){
			if (A[i][j] != 0){
				cout << A[i][j];
				if ((j+1) <= n) cout << " ";
			}
		}
		cout << endl;
	}
	for (int i=1; i <= n; i++){		// P배열 출력
		for (int j = 0; j <= n; j++){
			if (A[i][j] != 0){
				cout << P[i][j];
				if ((j+1) <= n) cout << " ";
			}
		}
		cout << endl;
	}

	preorder(tree(1, n));
	for (auto i = pre.begin(); i != pre.end(); ++i){
		cout << *i;
		if (i+1 != pre.end())
			cout << " ";
	}
	cout << endl;
	inorder(tree(1, n));
	for (auto i = in.begin(); i != in.end(); ++i){
		cout << *i;
		if (i+1 != in.end())
			cout << " ";
	}
	cout << endl;

	return 0;
}
