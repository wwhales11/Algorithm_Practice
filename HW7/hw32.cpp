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
map<char, vector<int>> cmap;

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
void findE(node_pointer root){
	if (root->left == NULL || root->right == NULL){
		cmap.insert(pair<char, vector<int>>(root->symbol, decode));
		decode.pop_back();
		return;
	}
	if (root->left != NULL){
		decode.push_back(0);
		findE(root->left);
	}
	if (root->right != NULL){
		decode.push_back(1);
		findE(root->right);
	}
	decode.pop_back();
}
int main(){

	int n, e, d, e1[MAX], d1[MAX];
	int frequency[MAX], D[MAX][MAX];
	char symbol[MAX], E[MAX][MAX];
	vector<int> d1map;
	priority_queue<node_pointer, vector<node_pointer>, compare> PQ;

	cin >> n;	// N 개수 입력
	for (int i=0; i < n; i++)	
		cin >> symbol[i];
	for (int i=0; i < n; i++)	
		cin >> frequency[i];

	cin >> e;
	for (int i=0; i < e; i++){
		cin >> e1[i];
		for (int j=0; j < e1[i]; j++){
			cin >> E[i][j];
		}
	}
	cin >> d;
	for (int i=0; i < d; i++){
		cin >> d1[i];
		for (int j=0; j < d1[i]; j++)	
			cin >> D[i][j];
	}

	for (int i = 0; i < n; i++){
		PQ.push(create_node(symbol[i], frequency[i]));
	}

	node_pointer root = huffman(n, PQ);

	findE(root);	

	for (int i = 0; i < e; i++){
		for (int j=0; j < e1[i]; j++){
			auto itr = cmap.find(E[i][j]);
			for (vector<int>::iterator it = itr->second.begin(); it != itr->second.end(); it++){
				cout << *it;
				if(it != itr->second.end()) cout << " ";
			}
		}
		cout << endl;
	}
	for (int i = 0; i < d; i++){
		for (int j=0; j < d1[i]; j++){
			d1map.push_back(D[i][j]);
			map<char, vector<int>>::iterator itr;
			for (itr = cmap.begin(); itr != cmap.end(); ++itr) 
				if(itr->second == d1map){
					cout << itr->first;
					if(j < d1[i]) cout << " ";
					d1map.clear();
				}
		}
		d1map.clear();
		cout << endl;
	}

	return 0;
}

