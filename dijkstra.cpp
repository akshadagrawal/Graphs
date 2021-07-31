// djkistras algorithm
#include<bits/stdc++.h>
using namespace std;
const int inf = 1e9;
int main(){
    int n, m;
    cin>>n>>m;
    vector<int> distance (n,inf);
    vector<bool > visited(n, 0) ;
    vector<vector< pair<int, int> > > arr(m);

    for(int i=0 ;i< m; i++ ) {
        int u,v,w;
        cin>>u>>v>>w;
        arr[u].push_back(make_pair(v, w));
        arr[v].push_back(make_pair(u, w));
    }

    int source;
    cin>>source;
    distance[source] = 0;
    set <pair <int, int> > s;
    s.insert(make_pair(distance[source], source));

    while(!s.empty()) {
        pair<int, int> p = *(s.begin());
        s.erase(p);
        int v = p.second;
        for(int i=0 ;i< arr[v].size(); i++) {
             pair<int, int> curr = arr[v][i];
            int newDistance = distance[v] + curr.second;
           
            if(distance[curr.first] > newDistance ) {
                s.erase(make_pair(distance[curr.first], curr.first));
                distance[curr.first] = newDistance;
                s.insert(make_pair(newDistance, curr.first));
            }
        }
    }

    for(int i=0;i< n; i++) {
        if(distance[i] != inf) cout<<distance[i]<<" ";
        else cout<<-1<<" ";
    }


}
