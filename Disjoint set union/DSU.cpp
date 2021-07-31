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

    //your code goes here
}