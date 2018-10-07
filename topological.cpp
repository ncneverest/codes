#include<bits/stdc++.h>
using namespace std;

void topo(vector<vector<int> > &g,int start,vector<bool> &visited,stack<int> &s){
	visited[start] = true;
	for(int i = 0; i < g.size(); i++){
		if(!visited[i] && g[start][i] == 1){
			topo(g,i,visited,s);
		}
	}
	s.push(start);
}

int main(){
	int v,e;
	cin >> v >> e; 
	vector<vector<int> > graph(v,vector<int>(v,0));
	for(int i = 0; i < e; i++){
		int a,b;
		cin >> a >> b;
		graph[a][b] = 1;
	}
	
	vector<bool> visited(v,false);
	stack<int> s;	
	
	for(int i = 0; i < v; i++)
		if(!visited[i])
			topo(graph,i,visited,s);

	while(!s.empty()){
		cout << s.top() << " ";
		s.pop();		
	}

	return 0;
}
