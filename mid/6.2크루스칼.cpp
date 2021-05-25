/* 
 * [2019117662] [박수환] 저는 이 소스 코드를 다른 소스 코드를 복사하지 않고 직접 작성하였습니다. 
 */

#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
#define MAX 256	

using namespace std;

typedef struct edge *edge_pointer;
typedef struct edge {
	int u;
	int v;
	int weight;
} edgetype;
typedef vector<edge_pointer> set_of_edges;

int U[MAX];

bool compare(edge_pointer a, edge_pointer b){
	if (a->weight != b->weight) 
		return (a->weight < b->weight);
	return 0;
}

void initial(int n){
	for (int i = 1; i <= n; i++)
		U[i] = i;
	cout << "초기화 : ";
	for (int i = 1; i <= n; i++)
		cout << U[i] << " ";
	cout << endl << endl;
}
int find(int i) {
	if (U[i] == i) return i;
	return find(U[i]);
}
bool equal(int p, int q) {
	return (p == q) ? true: false;
}
void merge(int p, int q) {
	if (p < q)
		U[q] = p;
	else
		U[p] = q;
}
void kruskal(int n, set_of_edges E, set_of_edges &F) {
	int p, q;
	sort(E.begin(), E.end(), compare);
	F.clear(); // 𝐹 = ∅;
	initial(n);
	vector<edge_pointer>::iterator iter = E.begin();
	while (F.size() < (long unsigned int)n - 1) {
		edge_pointer e = *iter++;
		p = find(e->u);
		q = find(e->v);
		if (!equal(p, q)) {
			merge(p, q);
			F.push_back(e);

			cout << "U 배열 : ";
			for (int i = 1; i <= n; i++)
				cout << U[i] << " ";
			cout << endl;
		}
	}
}
int main(){

	int n, m;
	edge_pointer e;

	set_of_edges F;
	set_of_edges E;

	cout << "정점개수 : ";
	cin >> n;
	cout << "간선개수 : ";
	cin >> m;	

	cout << "간선 두개 가중치 : \n";
	for(int i = 1; i <= m; i++){
		e = (edge_pointer)malloc(sizeof(edgetype));
		cin >> e->u >> e->v >> e->weight; 
		E.push_back(e);
	}
	cout << endl;

	kruskal(n, E, F);

	cout << "\nF : 경로u - 경로v - 가중치\n";
	for (auto loop : F){
		cout << loop->u << " " << loop->v << " "
			<< loop->weight << endl;
	}
	return 0;
}

