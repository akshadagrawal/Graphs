#include<bits/stdc++.h>
using namespace std;
const int n = 1e5 + 9;
vector<int> parent (n);
vector<int> size (n);
void make_set(int v) {
    parent[v] = v;
    size[v] = 1;
} 
int find_parent(int v) {
    if( v == parent[v] ) return v;
    return parent[v] = find_parent(parent[v]); //path compression
}
void union_sets(int a, int b) {
    a = find_parent(a);
    b = find_parent(b);
    if(a != b) {
        if(size[a] > size[b]) swap(a,b);  //generalising that a is always greater than b
        parent[b] = a; // chota wala bade ko jod dia
        size[a] += size[b];
    }
}
int main(){
    for(int i=0 ;i< n; i++) make_set(i);

    int v, m;
    cin>>v>>m;
    vector< vector< int > > edges;
    for(int i=0 ;i< m; i++) {
        int x, y;
        cin>>x>>y;
        vector<int> z;
        z.push_back(x);
        z.push_back(y);
        edges.push_back(z);
    }
    bool cycle= false;
    for(int  i =0 ;i< edges.size(); i++) {  
        int a= edges[i][0], b= edges[i][1];
        if(find_parent(a) == find_parent(b)) cycle = true;
        else union_sets(a, b);
    }

    if(cycle) cout<<"Cycle is presnt";
    else cout<<"Cycle is not present";

}