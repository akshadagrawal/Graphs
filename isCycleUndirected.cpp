//detect cycles in undirected graphs
#include<bits/stdc++.h>
using namespace std;
bool isCycle(int v, vector<vector<int> > arr, bool visited[],int parent ){
    visited[v] =true;
    for(int i=0 ;i< arr[v].size(); i++) {
        if( parent  != arr[v][i] ){
            if(visited[arr[v][i]]) return true;
            if(!visited[arr[v][i]] and isCycle(arr[v][i], arr, visited, v)) return true; 
        }
    }
    return false;
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int> > arr(n);

    for(int i=0; i< m ;i ++) {
        int x, y;
        cin>>x>>y;
        arr[x].push_back(y);
        arr[y].push_back(x);
    }

    bool cycle = false;
    bool visited[n];
    memset(visited, 0, sizeof(visited));

    for(int i=0 ;i< n; i++)  {
        if(!visited[i] and isCycle(i , arr, visited, -1)){
            cycle = true;
        }
    }
    if(cycle) cout<<"Cycle is present";
    else cout<<"Cycle not present";

    

}