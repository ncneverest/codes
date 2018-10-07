//representing the 2d maze graph into matrix adjacency list.

#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n,m,num;
	cin >> n >> m;

	int nodes = (n * m);
	cout << "no of nodes " << nodes << endl;

	list<int> g[nodes];
	
	char c;
	vector<char> cv(nodes);

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> c;
			num = m*i+j;

			cv[num] = c;
			if(c == '.'){
				if(m*(i-1)+j >= 0){
					if(cv[m*(i-1)+j] == '.'){
						g[m*i+j].push_back(m*(i-1)+j);
						g[m*(i-1)+j].push_back(m*i+j);
					}
				}
				if((m*i+j)%m != 0){
					if(cv[m*i+(j-1)] == '.'){
						g[m*i+j].push_back(m*i+(j-1));
						g[m*i+(j-1)].push_back(m*i+j);
					}
				}
			}

		}
	}

	for(int i = 0; i < nodes; i++){
		list<int>::iterator it;
		cout << i << "-> ";
		for(it = g[i].begin(); it != g[i].end(); it++){
			cout << *it << " ";
		}
		cout << endl;
	}
		
	return 0;
}

