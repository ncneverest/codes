#include <bits/stdc++.h>

#define ULL unsigned long long
#define LL long long
#define endl '\n'
#define ALL(v) begin(v), end(v)
#define CONTAINS(container, value) container.find(value) != container.end()

using namespace std;

void bellman(vector<vector<int> > &g,int src){
	int v = g.size();

	vector<int> dist(v,INT_MAX);
	vector<int> parent(v,-1);

	dist[src] = 0;

	for(int i = 0; i < v-1; i++){
		for(int u = 0; u < v; u++){
			for(int j = 0; j < v; j++){
				if(g[u][j] != 0 && dist[u] + g[u][j] < dist[j]){
					dist[j] = dist[u] + g[u][j];
					parent[j] = u;
				}
			}
		}
	}

	for(int i = 1; i < v; i++){
		cout << i+1 << " - " << parent[i]+1 << " : "  << dist[i] << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int v,e;
	cin >> v >> e;
	vector<vector<int> > graph(v,vector<int>(v,0));
	int a,b,c;

	for(int i = 0; i < e; i++){
		cin >> a >> b >> c;
		graph[a-1][b-1] = c;
	}
	
	int src;
	cout << "Enter the source vertex" << endl;
	cin >> src;

	bellman(graph,src-1);
		
	return 0;
}

