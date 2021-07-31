#include<bits/stdc++.h>
using namespace std;
void addEdge(vector<int> arr[], int u, int v) {
    arr[u].push_back(v);
    arr[v].push_back(u);
}
void printGraph(vector<int> arr[], int n){
    for(int i=0;i < n; i++) {
        cout<<i;
        for(int j=0; j< arr[i].size(); j++) {
            cout<<"->"<<arr[i][j];
        }
        cout<<endl;
    }
}
void bfs(vector<int> arr[], int n){
    bool visited[n];
    memset(visited, 0, sizeof(visited));
    queue<int> q;
    q.push(0);
    visited[0] = 1;
     while(!q.empty()) {
         int x = q.front();
         q.pop();
         cout<<x<<" ";
         for(int i=0; i< arr[x].size(); i++) {
             if(!visited[arr[x][i]]){
                visited[arr[x][i]] =1;
                q.push(arr[x][i]);
             }
         }
     }
}
void dsfUtil(vector<int> arr[], int n, bool visited[], int v) {\
    visited[v]= 1;
    //cout<<v<<" "; //preorder
    for(int i=0 ;i< arr[v].size(); i++) {
        if(!visited[arr[v][i]]) {
            dsfUtil(arr, n, visited, arr[v][i]);
        }
    }
    cout<<v<<" ";
}
void dfs(vector<int> arr[], int n){
    bool visited[n];
    memset(visited, 0, sizeof(visited));
    dsfUtil(arr, n, visited, 0);
}
int main(){
    int n= 5 ;
    vector<int> arr[n]; 
    addEdge(arr,0,1);
    addEdge(arr,0,3);
    addEdge(arr,0,4);
    addEdge(arr,1,2);
    addEdge(arr,1,4);
    addEdge(arr,2,4);
    printGraph(arr,n);
    cout<<endl;
    bfs(arr,n);
    cout<<endl;
    dfs(arr,n);
}