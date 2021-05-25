/* 
 * [2019117662] [박수환] 저는 이 소스 코드를 다른 소스 코드를 복사하지 않고 직접 작성하였습니다. 
 */

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <climits>
#include <iterator>

#define MAX 1000	
#define INF INT_MAX 	

using namespace std;

typedef vector<int> ordered_set;
typedef struct node *node_pointer;
typedef struct node {
	int level;
	ordered_set path;
	int bound;
} nodetype;
struct compare {
	// 내림차순
	bool operator()(node_pointer p, node_pointer q) {
		if (p->bound > q->bound)
			return true;
		return false;
	}
};

int n, pLen = 1;
int W[MAX][MAX];

void travel2(ordered_set &opttour, int &minlength);
node_pointer create_node(int level, ordered_set path);
int length(ordered_set path);
int bound(node_pointer v);
int remain(ordered_set path);
bool isIn(int v, ordered_set path);
bool hasOutgoing(int v, ordered_set path);
bool hasIncoming(int v, ordered_set path);

int main(){

	int m, i, j, minlength;
	ordered_set opttour;

	cin >> n >> m;
	for(int k = 1; k <= m; k++){
		cin >> i >> j >> W[i][j];
	}

	travel2(opttour, minlength);

	vector<int>::iterator it;
	for (it = opttour.begin(); it != opttour.end(); it++){
		cout << *it;
		if(it != opttour.end() - 1) cout << " ";
	}
	cout << endl << minlength << " " << pLen << endl;

	return 0;
}
void travel2(ordered_set &opttour, int &minlength){

	priority_queue<node_pointer, vector<node_pointer>, compare> PQ;
	node_pointer v, u;
	minlength = INF;

	v->level = 0; v->path.push_back(1); v->bound = bound(v);
	PQ.push(v);

	while (!PQ.empty()) {
		v = PQ.top();
		PQ.pop();
		if (v->bound < minlength) {
			for (int i = 2; i <= n; i++) {
				// for all i such that i is not in v.path
				if (isIn(i, v->path)) continue;
				u = create_node(v->level + 1, v->path);
				u->path.push_back(i);
				if (u->level == n - 2) {
					// put the only vertex not in v.path
					u->path.push_back(remain(u->path));
					u->path.push_back(1); // make first vertex last one
					if (length(u->path) < minlength) {
						minlength = length(u->path);
						opttour.clear();
						copy(u->path.begin(), u->path.end(), back_inserter(opttour));
					}
				}
				else {
					u->bound = bound(u);
					if (u->bound < minlength){
						PQ.push(u);
						pLen++;
					}
				}
			}
		}
	}
}
node_pointer create_node(int level, ordered_set path) {
	node_pointer t = (node_pointer)malloc(MAX);
	t->level = level;
	copy(path.begin(), path.end(), back_inserter(t->path));
	return t;
}
int length(ordered_set path) {
	vector<int>::iterator it;
	int len = 0;
	for (it = path.begin(); it != path.end() - 1; it++){
		len += W[*it][*(it+1)];
	}
	return len;
}
int bound(node_pointer v) {
	// start from the length of path
	int lower = length(v->path);
	for (int i = 1; i <= n; i++) {
		if (hasOutgoing(i, v->path)) continue;
		int min = INF;
		for (int j = 1; j <= n; j++) {
			// Do not include self-loop
			if (i == j) continue;
			// Do not include an edge to which i cannot return
			if (j == 1 && i == v->path[v->path.size() - 1]) continue;
			// Do not include edges already in the path
			if (hasIncoming(j, v->path)) continue;
			// A lower bound (minimum) on the cost of leaving i
			if (min > W[i][j]) min = W[i][j];
		}
		lower += min;
	}
	return lower;
}
int remain(ordered_set path) {
	vector<int>::iterator it;
	int i;
	for (i = 2; i <= n; i++){
		bool flag = 0;
		for (it = path.begin(); it != path.end(); it++){
			if (*it == i){
				flag = 0;
				break;
			}
			flag = 1;
		}
		if (flag == 1) break;
	}
	return i;
}
bool isIn(int v, ordered_set path) {
	vector<int>::iterator it;
	for (it = path.begin(); it != path.end(); it++)
		if (*it == v) return true;
	return false;
}
bool hasOutgoing(int v, ordered_set path) {
	vector<int>::iterator it;
	for (it = path.begin(); it != path.end() - 1; it++)
		if (*it == v) return true;
	return false;
}
bool hasIncoming(int v, ordered_set path) {
	vector<int>::iterator it;
	for (it = path.begin() + 1; it != path.end(); it++)
		if (*it == v) return true;
	return false;
}
