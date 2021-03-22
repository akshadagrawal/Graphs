#include<bits/stdc++.h>
using namespace std;
class Graph{
    int num;
    list<int> *adjacenyList;
    int ** weight;
    public:
        Graph(int v){
            num=v;
            adjacenyList=new list<int> [v];
            weight=new int*[v];
            for(int i=0;i<v;i++){
                weight[i]=new int[v];
                for(int j=0;j<v;j++)
                    weight[i][j]=0;
            }
        }
        void addEdge(int u,int v,int w);
        void printGraph();
        void prims(int s);
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


void Graph:: prims(int v){
    unordered_map <int,int> distance;
    map<int,int> path;
    set<pair<int,int>> q;
    set<pair<int,int>> ::iterator qitr;
    list<int> :: iterator itr;
    bool visited[num];
    int newDistance;
    for(int i=0;i< num;i++){
        distance[i]=-1;
        visited[i]=false;
    }
    distance[v]=0;
    q.insert(make_pair(distance[v],v));
    while(!q.empty()){
        
        qitr=q.begin();
        v=qitr->second;
        visited[v]=true;
        qitr=q.erase(q.begin());
        for(itr=adjacenyList[v].begin();itr!=adjacenyList[v].end();itr++){
            newDistance=weight[v][*itr];
            if(distance[*itr]==-1){
                distance[*itr]=weight[v][*itr];
                q.insert(make_pair(distance[*itr],*itr));
                path[*itr]=v;
            }
            else if(newDistance < distance[*itr] && !visited[*itr]){
                q.erase(make_pair(distance[*itr],*itr));
                distance[*itr]=weight[v][*itr];
                q.insert(make_pair(distance[*itr],*itr));
                path[*itr]=v;
            }

        }
        
    }

    for(auto x: distance){
        cout<<"Value of vertex "<<x.first<<" is: "<<x.second<<endl;
    }
    for(auto x: path){
        cout<<"path of vertex "<<x.first<<" is through  :"<<x.second<<endl;
    }



    
}
int main(){
    Graph g(9);

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
    g.prims(0);


}