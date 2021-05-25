/* 
   [2019117662] [박수환] 저는 이 소스 코드를 다른 소스 코드를 복사하지 않고 직접 작성하였습니다. 
 */

#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
#define MAX 256	
#define INF INT_MAX	

using namespace std;

int W[MAX][MAX];

typedef struct edge *edge_pointer;
typedef struct edge {
	int u;
	int v;
	float weight;
} edgetype;

typedef vector<edge_pointer> set_of_edges;

void dijkstra(int n, int W[][MAX], set_of_edges &F) {
	int vnear, min, touch[MAX], length[MAX];
	edge_pointer e;
	F.clear(); // 𝐹 = ∅;
	for (int i = 2; i <= n; i++) {	// 시작점 v1으로 가정
		touch[i] = 1;		// 1로 초기화
		length[i] = W[1][i];
	}
	for (int k = 1; k < n; k++) {
		min = INF;
		for (int i = 2; i <= n; i++)	// 최적경로찾기
			if (0 <= length[i] && length[i] < min) {
				min = length[i];
				vnear = i;	// 최적 v저장
			}
		e = (edge_pointer)malloc(sizeof(edgetype));
		e->v = vnear;
		e->u = touch[vnear];
		e->weight = W[e->u][e->v];
		F.push_back(e);
		for (int i = 2; i <= n; i++){	// 새로운v 업뎃
			if (length[vnear] + W[vnear][i] < length[i]) {
				length[i] = length[vnear] + W[vnear][i];
				touch[i] = vnear;
			}
		}
		length[vnear] = -1;	// 지나간 v에-1부여
		for (int j = 2; j <= n; j++){
			cout << touch[j];
			if (j + 1 <= n) cout << " ";
		}
		cout << endl;
		for (int j = 2; j <= n; j++){
			if (length[j] == MAX)
				cout << "INF";
			else
				cout << length[j];
			if (j + 1 <= n) cout << " ";
		}
		cout << endl;
	}
}

int main(){

	int n, m;
	int x, y;
	set_of_edges F;

	cin >> n >> m;	

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			W[i][j] = MAX;

	for (int i = 1; i <= m; i++){
		cin >> x >> y >> W[x][y]; 
	//	W[y][x] = W[x][y];
	}

	dijkstra(n, W, F);

	for (auto loop : F)
		cout << loop->u << " " << loop->v << " "
			<< loop->weight << endl;

	return 0;
}
