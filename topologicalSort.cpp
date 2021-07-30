//can be used to detect cycled as well
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, m;
    cin>>n>>m;
    vector<vector<int> > arr(n);
    vector<int> indegree(n, 0);
    for(int i=0 ;i<  m;i ++) {
        int x, y;
        cin>>x>>y;
        arr[x].push_back(y);
        indegree[y]++;
    }
    queue<int> q;
    for(int i= 0;i < n ;i ++) {
        if(indegree[i] == 0) q.push(i);
    }
    while(!q.empty()) {
        int x = q.front();
        cout<<x<<" ";
        q.pop();
        for(int i=0; i< arr[x].size(); i++){
            indegree[arr[x][i]]-- ;
            if(indegree[arr[x][i]] == 0) q.push(arr[x][i]);
        }
    }
}