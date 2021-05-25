/* 
 * [2019117662] [박수환] 저는 이 소스 코드를 다른 소스 코드를 복사하지 않고 직접 작성하였습니다. 
 */

#include <iostream>
#include <vector>
#include <queue>
#include <map>
#define MAX 30 	

using namespace std;

int f1 = 0;
vector<int> decode;

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
void findE(node_pointer root, node_pointer key){
	if (root == NULL || root->symbol == key->symbol){
		return;
	}
	if (root->frequency < key->frequency){
		findE(root->right, key);
		decode.push_back(1);
	}
	if (root->frequency > key->frequency){
		findE(root->left, key);
		decode.push_back(0);
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
int main(){

	int n, e, d, e1, d1, frequency[MAX], D[11];
	char symbol[MAX], E[11];
	priority_queue<node_pointer, vector<node_pointer>, compare> PQ;
	map<char, vector<int>> cmap;

	cin >> n;	// N 개수 입력
	for (int i=0; i < n; i++)	
		cin >> symbol[i];
	for (int i=0; i < n; i++)	
		cin >> frequency[i];

	cin >> e;
	for (int i=0; i < e; i++){
		cin >> e1;
		for (int j=0; j < e1; j++)	
			cin >> E[j];
	}
	cin >> d;
	for (int i=0; i < d; i++){
		cin >> d1;
		for (int j=0; j < d1; j++)	
			cin >> D[j];
	}

	for (int i = 0; i < n; i++){
		PQ.push(create_node(symbol[i], frequency[i]));
	}

	node_pointer root = huffman(n, PQ);

	inorder(huffman(n, PQ));
	cout << endl;

	for (int i = 0; i < n; i++){
	findE(root, PQ.top());	
	for (vector<int>::iterator it = decode.begin(); it != decode.end(); it++)
		cout << *it << " ";
	cout << endl;
	cmap.insert(pair<char, vector<int>> (PQ.top()->symbol, decode));
	PQ.pop();
	decode.clear();
	}
	map<char, vector<int>>::iterator itr;
	cout << "KEY\tELEMENT\n";
	for (itr = cmap.begin(); itr != cmap.end(); ++itr) {
	cout << itr->first << '\t';
		for (vector<int>::iterator it = itr->second.begin(); it != itr->second.end(); it++)
			cout << *it << " ";
		cout << endl;
	}

	cout << endl;

	return 0;
}

