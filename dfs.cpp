#include<bits/stdc++.h>
using namespace std;
class Graph{
    int numOfVertex;
    list<int> *arr;
    bool *visited;
    public:
        Graph(int v){
            numOfVertex=v;
            arr=new list<int>[v];
            visited= new bool[v];
            for(int i=0;i<v;i++) visited[i]=false;
        }
        void addEdge(int u,int v);
        void printGraph();
        void dfs(int v);
};
void Graph:: addEdge(int u,int v){
    arr[u].push_front(v);
    //arr[v].push_back(u);
}
void Graph:: printGraph(){
     for(int i=0;i<numOfVertex;i++){
        cout<<i;
        for(auto x : arr[i] ){
            cout<<"->"<<x;
        }
        cout<<endl;
    }
}
void Graph:: dfs(int v){
    visited[v]= true;
    cout<<v;
    list<int>:: iterator itr;
    for(itr=arr[v].begin();itr!=arr[v].end();itr++){
        if(!visited[*itr]){
            dfs(*itr);
        }
    }

}
int main(){
    Graph g(8);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(1,7);
    g.addEdge(2,3);
    g.addEdge(2,4);
    g.addEdge(4,5);
    g.addEdge(4,6);
    g.addEdge(4,7);
    g.printGraph();
    g.dfs(0);
}