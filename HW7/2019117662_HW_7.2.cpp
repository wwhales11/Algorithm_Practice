/* 
 * [2019117662] [박수환] 저는 이 소스 코드를 다른 소스 코드를 복사하지 않고 직접 작성하였습니다. 
 */

#include <iostream>
#include <vector>
#include <queue>
#define MAX 30 	

using namespace std;

int f1 = 0;
typedef struct node *node_pointer;
typedef struct node {
	char symbol;
	int frequency;
	node_pointer left;
	node_pointer right;
} nodetype;

struct compare {
	bool operator()(node_pointer p, node_pointer q) {
		if (p->frequency > q->frequency)
			return true;
		return false;
	}
};
node_pointer create_node(char symbol, int frequency) {
	node_pointer node = (node_pointer)malloc(sizeof(nodetype));
	node->symbol = symbol;
	node->frequency = frequency;
	node->left = node->right = NULL;
	return node;
}
void preorder(node_pointer p) {
	if (p) {
		f1++;
		if(p->left == NULL && p->right == NULL){
			if(f1 != 1) cout << " ";
			cout << p->symbol;
		}
		else {
			if(f1 != 1) cout << " ";
			cout << p->frequency;
		}
		preorder(p->left);
		preorder(p->right);
	}
}
void inorder(node_pointer p) {
	if (p) {
		inorder(p->left);
		f1++;
		if(p->left == NULL && p->right == NULL){
			if(f1 != 1) cout << " ";
			cout << p->symbol;
		}
		else {
			if(f1 != 1) cout << " ";
			cout << p->frequency;
		}
		inorder(p->right);
	}
}
node_pointer huffman(int n, priority_queue<node_pointer, vector<node_pointer>, compare> PQ){
	for (int i = 1; i <= n - 1; i++) {
		node_pointer p = PQ.top();
		PQ.pop();
		node_pointer q = PQ.top();
		PQ.pop();
		node_pointer r = new nodetype;
		r->left = p;
		r->right = q;
		r->frequency = p->frequency + q->frequency;
		PQ.push(r);
	}
	node_pointer r = PQ.top();
	return r;
}
int main(){

	int n, frequency[MAX];
	char symbol[MAX];
	priority_queue<node_pointer, vector<node_pointer>, compare> PQ;

	cin >> n;	// N 개수 입력
	for (int i=0; i < n; i++)	
		cin >> symbol[i];
	for (int i=0; i < n; i++)	
		cin >> frequency[i];

	for (int i = 0; i < n; i++)
		PQ.push(create_node(symbol[i], frequency[i]));

	preorder(huffman(n, PQ));
	cout << endl;
	f1 = 0;
	inorder(huffman(n, PQ));
	cout << endl;

	return 0;
}

