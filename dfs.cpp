//dfs using list ...

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void dfs(list<int> l[],int start,bool visited[]){
	cout << start << " ";
	visited[start] = true;

	list<int>::iterator it;
	for(it = l[start].begin(); it != l[start].end(); it++){
		if(!visited[*it])
		dfs(l,*it,visited);
	}
}

int main(){	
	int v,e;
	cin >> v >> e;
	list<int> l[v];
	for(int i = 0; i < e; i++){
		int a,b;
		cin >> a >> b;
		l[a].push_back(b);
		l[b].push_back(a);
	}
	
	bool visited[v];
	fill(visited,visited+v,false);
	visited[0] = true;

	dfs(l,0,visited);

	return 0;

}
