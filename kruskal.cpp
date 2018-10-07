#include<bits/stdc++.h>
using namespace std;

int find(int src,int parent[]){
	if(parent[src] == src) return src;
	parent[src] = find(parent[src],parent);
	return parent[src];
}

void Union(int src,int dest,int parent[]){
	src = find(src,parent);
	dest = find(dest,parent);
	parent[src] = dest;
}

void krusk(pair<int,pair<int,int> > p[],int v,int e){
	int parent[v];
	for(int i = 0; i < v; i++){
		parent[i] = i;		
	}	

	for(int i = 0; i < e; i++){

		int src = p[i].second.first;
		int dest = p[i].second.second;
		int wt = p[i].first;

		if(find(src,parent) != find(dest,parent)){
			Union(src,dest,parent);
			cout << src << " -- " << dest << " : " << wt << endl;
		}
		
	}

}

int main(){
	int v,e;
	cin >> v >> e;
	pair<int,pair<int,int> > p[v];
	for(int i = 0; i < e; i++){
		int a,b,c;
		cin >> a >> b >> c;
		p[i] = make_pair(c,make_pair(a,b));
	}
	sort(p,p+e);
	cout << "sorted" << endl;

	for(int i = 0; i < e ; i++){
		cout << p[i].second.first << " " << p[i].second.second << " : " << p[i].first << endl;
	}

	krusk(p,v,e);
	return 0;
}
