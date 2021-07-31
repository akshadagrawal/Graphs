//check if graph is 2-colorable, i.e adjacent vertives must have same color
#include<bits/stdc++.h>
using namespace std;
void giveColor(vector<vector<int> > arr, bool visited[], int color [], int v, int shade, bool & flag) {
    if(color[v] != -1 and color[v]!= shade) {
        flag = false;
        return ;
    }
    color[v] = shade;
    if(visited[v]) return;
    visited[v] = true;

    for(int i= 0; i< arr[v].size(); i++) {
        giveColor(arr,visited,color,arr[v][i],!shade, flag);
    }

}
int main(){
    int n ,m;
    cin>>n>>m;
    vector<vector<int > > arr(n);
    for(int i=0;i <m ;i ++) {
        int x,y;
        cin>>x>>y;
        arr[x].push_back(y);
        arr[y].push_back(x);
    }

    bool visited[n], bipartite=true;
    int color[n];
    memset(visited, 0, sizeof(visited));
    memset(color, -1, sizeof(color));

    for(int i=0 ;i< n; i++) {
        if(!visited[i] )
            giveColor(arr,visited,color, i, 0, bipartite);
    }

    if(bipartite) cout<<"Bipartite graph";
    else cout<<"Not bipartite ";
}