#include<bits/stdc++.h>
using namespace std;

int minkey(int key[],bool visited[],int v, int e){
	int min = 100000, min_idx = -1;
	for(int i = 0; i < v; i++){
		if(!visited[i] && key[i]  < min){
			min = key[i];
			min_idx = i;
		}
	}
	return min_idx;
}

void dijikstra(vector<vector<int> > &graph,int v, int e){

	bool visited[v];
	fill(visited,visited+v,false);

	int parent[v];
	
	int key[v];
	for(int i = 0; i < v; i++) key[i] = 100000;
	key[0] = 0;

	parent[0] = -1;

	for(int i = 0; i < v; i++){
		int u = minkey(key,visited,v,e);
		visited[u] = true;
		for(int j = 0; j < v; j++){
			if(graph[u][j] != -1 && key[u] +  graph[u][j] < key[j] && !visited[j]){
				parent[j] = u;
				key[j] = graph[u][j] + key[u];
			}
		}
	}
		
	for(int i = 1 ; i < v; i++){
		cout << i << " - " << parent[i] << " : " << key[i] << endl;
	}

}

int main(){
	int v,e;
	cin >> v >> e;

	vector< vector<int> > graph(v,vector<int> (v,-1));

	for(int i= 0; i < e; i++){
		int src,dest,wt;
		cin >> src >> dest >> wt;
		graph[src][dest] = wt;
		graph[dest][src] = wt;
	}

	dijikstra(graph,v,e);

	return 0;
}
