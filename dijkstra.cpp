#include<bits/stdc++.h>
using namespace std;
class Graph{
    int num;
    list<int> *adjacenyList;  
    int **weight;
    bool *visited;
    public: 
     Graph(int n){
        num=n;
        adjacenyList= new list<int>[n];
        weight= new int* [n];
        for(int i=0;i<n;i++){
            weight[i]= new int[n];
            for(int j=0;j<n;j++)
                weight[i][j]=0;
        }
        visited= new bool[n];
     }
     void addEdge(int u,int v,int w);
     void printGraph();
     void dijkstra(int v);
};
void Graph:: addEdge(int u,int v,int w){
    adjacenyList[u].push_back(v);
    adjacenyList[v].push_back(u);
    weight[v][u]=w;
    weight[u][v]=w;
}
void Graph:: printGraph(){
    for(int i=0;i<num;i++){
        cout<<i;
        for(auto x: adjacenyList[i]){
            cout<<"->"<<x;
        }
        cout<<endl;
    }
}

void Graph:: dijkstra(int v){
    set <pair<int,int> > q;
    set<pair<int,int>> ::iterator qi;
    unordered_map<int,int> distance;
    map<int,int> path;
    list<int> :: iterator itr;
    int newDist;
    for(int i=0;i<num;i++){
        distance[i]=-1;
    }
    distance[v]=0;
    q.insert(make_pair(distance[v],v));
    while(!q.empty()){
        qi=q.begin();
        v=qi->second;
        qi=q.erase(q.begin());
        
        for(itr=adjacenyList[v].begin();itr!=adjacenyList[v].end();itr++){
            newDist=distance[v]+ weight[v][*itr];   
            if(distance[*itr]==-1){
                distance[*itr]=newDist;
                q.insert(make_pair(distance[*itr],*itr));
                path[*itr]=v;
            }
            else if(newDist< distance[*itr]){
                q.erase(make_pair(distance[*itr],*itr));
                 distance[*itr] =  newDist;  
                 
                q.insert(make_pair(distance[*itr],*itr)); 
                 path[*itr]=v;
        
            }             
        }
    }
    for(auto x: distance ){
        cout<<"Distance of vertex "<<x.first<<"is: "<<x.second<<endl;
    }
    for(auto x: path){
        cout<<"path of vertex "<<x.first<<" is through  :"<<x.second<<endl;
    }
}
int main(){
     Graph g(9);
    // g.addEdge(0,1,3);
    // g.addEdge(1,2,5);
    // g.addEdge(1,7,1);
    // g.addEdge(2,4,7);
    // g.addEdge(4,5,3);
    // g.addEdge(4,6,4);
    // g.addEdge(4,7,2);
    // g.addEdge(7,3,9);

    // g.addEdge(0,1,4);
    // g.addEdge(0,2,1);
    // g.addEdge(2,1,2);
    // g.addEdge(2,3,4);
    // g.addEdge(1,4,4);
    // g.addEdge(3,4,4);



     g.addEdge(0,1,4);
    g.addEdge(0,7,8);
    g.addEdge(1,7,11);
    g.addEdge(1,2,8);
    g.addEdge(7,8,7);
    g.addEdge(7,6,1);
    g.addEdge(8,2,2);
    g.addEdge(8,6,6);
    g.addEdge(6,5,2);
    g.addEdge(5,2,4);
    g.addEdge(2,3,7);
    g.addEdge(3,4,9);
    g.addEdge(4,5,10);
        g.addEdge(3,5,14);



    g.printGraph();
    //g.dfs(0);
    //g.bfs(0);
    g.dijkstra(0);


}



// void dsfUtil(bool *visited, int v);
// void dfs(int v);
// void bfs(int v);


// void Graph:: dsfUtil(bool *visited, int v){
//     visited[v]=true;
//     cout<<v;
//     list<int>:: iterator itr;
//     for(itr=adjacenyList[v].begin();itr!=adjacenyList[v].end();itr++){
//         if(!visited[*itr]){
//             dsfUtil(visited,*itr);
//         }
//     }
// }
// void Graph::dfs(int v){
//     int i=0;
//     for(i=0;i<num;i++) visited[i]=false;
//     dsfUtil(visited,v);
// }
// void Graph:: bfs(int v){
//     int i=0;int x;
//     for(i=0;i<num;i++) visited[i]=false;
//     visited[v]=true;
//     queue <int> q;
//     list<int> :: iterator itr;
//     q.push(v);
//     while(!q.empty()){
//         x=q.front();
//         cout<<x;
//         q.pop();
//         for(itr=adjacenyList[x].begin();itr!=adjacenyList[x].end();itr++){
//             if(!visited[*itr]){
//                 visited[*itr]=true;
//                 q.push(*itr);
//             }
//         }
        
//     }
// }