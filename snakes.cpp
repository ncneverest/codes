#include <bits/stdc++.h>

#define ULL unsigned long long
#define LL long long
#define endl '\n'
#define ALL(v) begin(v), end(v)
#define CONTAINS(container, value) container.find(value) != container.end()

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--){
        list<int> l[100];        
        int ladder,snakes;
        int src,dest;
        
        cin >> ladder;    
        for(int i = 0; i< ladder; i++){
            cin >> src >> dest;
            l[src-1].push_back(dest-1);
        }
        
        cin >> snakes;
        for(int i = 0; i < snakes; i++){
            cin >> src >> dest;
            l[src-1].push_back(dest-1);
        }


        queue<int> Q;
        Q.push(0);

        vector<int> parent(100,0);
        vector<bool> visited(100,false);

        visited[0] = true;
		int u;

        while(!Q.empty()){

            u = Q.front();    
            
            Q.pop();

            if(u == 99){
                cout << parent[u] << endl;
                break;
            }

            list<int>::iterator it;        

            for(int i = u+1; i <= u+6 && i < 100; i++){
                
                it = l[i].begin();
                if(it != l[i].end() && !visited[*it]){
                        Q.push(*it);
                        visited[*it] = true;
                        parent[*it] = parent[u] + 1;    
                }
                else{
                    if(!visited[i]){
                        Q.push(i);            
                        parent[i] = parent[u] + 1;
                        visited[i] = true;    
                    }
                }
            }
		}        
		if( u != 99) cout << -1 << endl;
    }    
    return 0;
}
