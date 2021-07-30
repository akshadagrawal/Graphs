//find connected components and its size
#include<bits/stdc++.h>
using namespace std;
int get_size(int v, bool visited[], vector< vector<int> > arr) {
    if(visited[v]) return 0;
    visited[v] = true;
    int count = 1;
    for(int i=0 ;i< arr[v].size(); i++) {
        if(!visited[arr[v][i]])
        {
            count += get_size(arr[v][i], visited, arr);
        }
    }
    return count;
}
int main() {
    int n,m;
    cin>>n>>m;
    vector<vector<int> > arr(n);
    vector<int> components ; 

    for(int i=0; i< m ;i ++) {
        int x, y;
        cin>>x>>y;
        arr[x].push_back(y);
        arr[y].push_back(x);
    }
    bool visited[n];
    memset(visited, 0, sizeof(visited));

    for(int i=0 ;i<n ;i++) {
        if(!visited[i]) components.push_back(get_size(i, visited, arr));
    }

    for(auto x: components) cout<<x<<endl;

}