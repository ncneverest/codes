#include <bits/stdc++.h>

using namespace std;
typedef pair<int,long long int> mypair;
#define endl '\n'
    
int main(){
    
        ios_base::sync_with_stdio(0);
        cin.tie(0);
    
        int t;
        int v,e;
        int src,dest,start;
        long long int wt;
    
        cin >> t;
        while(t--){        
            cin >> v >> e;
            
            list<mypair> l[v];
            
            for(int i = 0; i < e; i++){
                cin >> src >> dest >> wt;                   
                l[src-1].push_back(make_pair(dest-1,wt));
                l[dest-1].push_back(make_pair(src-1,wt));                
            }
            
            cin >> start;
            start--;
            
            vector<long long int> key(v,INT_MAX);
            key[start] = 0;
    
            vector<bool> visited(v,false);        
    
            priority_queue<mypair,vector<mypair>, greater<mypair> > pq;
    
            pq.push(make_pair(0,start));
    
            while(!pq.empty()){
                int u = pq.top().second;
                visited[u] = true;

                pq.pop();

                for(list<mypair>::iterator it = l[u].begin(); it != l[u].end(); it++){
                    if(key[u] + it->second < key[it->first]){
                        key[it->first] = key[u] + it->second;
                        pq.push(make_pair(key[it->first],it->first));
                    }
                }
            }
    
            vector<long long int> result;
            for(int i = 0; i < v; i++){
                if(i != start){
                    if(key[i] != INT_MAX)
                        result.push_back(key[i]);
                    else result.push_back(-1);
                }        
            }       

            for (int i = 0; i < result.size(); i++) {
                cout << result[i];

                if (i != result.size() - 1) {
                    cout << " ";
                }
            }
            cout << endl;
        }    
    return 0;
}
