//detect cycles in directed graphs
#include<bits/stdc++.h>
using namespace std;
bool isCycle(int v, vector<vector<int> > arr, bool visited[],bool stack[] ){
    stack[v] = true;
    if(!visited[v]){
        visited[v] = true;
        for(int i=0 ;i< arr[v].size(); i++) {
            if(!visited[arr[v][i]] and isCycle(arr[v][i], arr, visited, stack)) return true; 
            if(stack[arr[v][i]]) return true;
        }
    }
    stack[v] = false;
    
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
    }

    bool cycle = false;
    bool visited[n];
    bool stack[n];
    memset(visited, 0, sizeof(visited));
    memset(stack, 0, sizeof(stack));


    for(int i=0 ;i< n; i++)  {
        if(!visited[i] and isCycle(i , arr, visited, stack)){
            cycle = true;
        }
    }
    if(cycle) cout<<"Cycle is present";
    else cout<<"Cycle not present";

    

}