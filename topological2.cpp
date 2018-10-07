#include <bits/stdc++.h>

#define ULL unsigned long long
#define LL long long
#define endl '\n'
#define ALL(v) begin(v), end(v)
#define CONTAINS(container, value) container.find(value) != container.end()

using namespace std;

void topo_sort(list<int> graph[],int src,stack<int> &st,vector<bool> &visited){
	visited[src] = true;
	for(list<int>::iterator it = graph[src].begin(); it != graph[src].end(); it++){
		if(!visited[*it]) topo_sort(graph,*it,st,visited);
	}
	st.push(src);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int v,e;
	cin >> v >> e;
	list<int> graph[v];
	
	int src,dest;
	for(int i = 0; i < e; i++){
		cin >> src >> dest;
		graph[src].push_back(dest);
	}
	
	stack<int> s;
	vector<bool> visited(v,false);

	for(int i = 0; i < v; i++)
		if(!visited[i])
			topo_sort(graph,i,s,visited);

	while(!s.empty()){
		cout << s.top() << " ";
		s.pop();
	}

	cout << endl;
		
	return 0;
}

