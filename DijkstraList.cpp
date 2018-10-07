#include<bits/stdc++.h>
using namespace std;


int min_key(list<pair<int,int> > g[],vector<bool> &visited,vector<int> &key){
	int min_idx = -1, min_val = INT_MAX;
	for(int i = 0; i < visited.size(); i++){
		if(!visited[i] && key[i] < min_val){
			min_val = key[i];
			min_idx = i;
		}
	}
	return min_idx;
}

void dijks(list<pair<int,int> >lists[],int v){
	int start = 0;

	vector<bool> visited(v,false);
	vector<int> parent(v);
	vector<int> key(v,INT_MAX);

	parent[start] = -1;
	key[start] = 0;

	for(int i = 0; i < v; i++){
		int u = min_key(lists,visited,key);
		visited[u]  = true;

		list<pair<int,int> >::iterator it;

		for(it = lists[u].begin(); it != lists[u].end(); it++){
			if(!visited[it->first] && key[u] + it->second < key[it->first]){
				key[it->first] = key[u] + it->second;
				parent[it->first] = u;
			}	
		}

	}
	
	cout << endl << "node," << " parent " << " and " << " wt from index 1 : " << endl;
	for(int i = 1; i < v; i++){
		cout << i << "-> " << parent[i] << " : " << key[i] << endl;
	}

}

int main(){
	int v,e;
	cin >> v >> e;
	list<pair<int,int> > list[v];
	int src,dest,wt;
	for(int i = 0; i < e; i++){
		cin >> src >> dest >> wt;
		list[src].push_back(make_pair(dest,wt));
//		list[dest].push_back(make_pair(src,wt)); if not undirected
	}

	dijks(list,v);
	return 0;
}
