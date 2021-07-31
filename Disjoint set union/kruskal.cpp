//kruskal algorithm

#include<bits/stdc++.h>
using namespace std;
const int N= 1e5 + 9;
vector<int> parent(N), size(N);
void make_set(int v) {
    parent[v] = v;
    size[v]=1;
}
int find_parent(int v) {
    if(v == parent[v])  return v;
    return parent[v] = find_parent(parent[v]);  //path compression
}
void make_union(int a, int b) {
    a = find_parent(a);
    b = find_parent(b); 
    if(a != b) {
        if(size[a] < size[b]) swap(a, b);  //generalisaing a is always greater than b
        parent[b] = a;      //chote wala ka bap bada wala assign kia
        size[a] += size[b]; //update the size of bada set
    }
}
int main(){
    for(int i=0 ;i< N; i++) make_set(i);

    int n, m, cost =0 ;
    cin>>n>>m;
    vector< vector<int > >edges;
    for(int i=0 ;i< m;i++) {
        int u,v,w;
        cin>>u>>v>>w;
        vector<int> x;
        x.push_back(w);
        x.push_back(u);
        x.push_back(v);
        edges.push_back(x);
    }
    sort(edges.begin(), edges.end());

    for(int i=0 ;i < m; i++) {
        int w= edges[i][0], u= edges[i][1], v= edges[i][2];
        if(find_parent(u) == find_parent(v)) continue;
        else {
            cout<<u<<" "<<v<<endl;
            cost += w;
            make_union(u,v);
        }
    }

    cout<<"Cost :" <<cost;

}