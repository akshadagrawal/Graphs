#include<bits/stdc++.h>
using namespace std;
class Graph{
    int num;
    list<int> *adjacencyList;
    int **weight;
    public:
        Graph(int n){
            num=n;
            adjacencyList=new list<int>[n];
            weight=new int*[n];
            for(int i=0;i<n;i++){
                weight[i]=new int[n];
                for(int j=0;j<n;j++)
                    weight[i][j]=0;
            }
        }
        void addEdge(int u,int v,int w);
        void printGraph();
        void belmanFord(int v);
};
void Graph:: addEdge(int u,int v,int w){
    adjacencyList[u].push_back(v);
    adjacencyList[v].push_back(u);
    weight[u][v]=w;
    weight[v][u]=w;
}
void Graph:: printGraph(){
    for(int i=0;i<num;i++){
        cout<<i;
        for(auto x:adjacencyList[i]){
            cout<<"->"<<x;
        }
        cout<<endl;
    }
}
void Graph:: belmanFord(int v){
    list<int>::iterator itr;
    int temp=0;
    map<int ,int> freq;
    map<int,int> path;
    queue<int> q;
    unordered_map< int,int > distance;
    int newDistance;
    for(int i=0;i<num;i++){
        distance[i]=INT_MAX;
    }
    distance[v]=0;
    q.push(v);
    while(!q.empty()){
        v=q.front();
        q.pop();
        if(freq[v] > num-1) {
            temp=1;
            break;
        }
        for(itr=adjacencyList[v].begin();itr!=adjacencyList[v].end();itr++){
             newDistance=distance[v]+weight[v][*itr];
             if(newDistance<distance[*itr]){
                 distance[*itr]=newDistance;
                 q.push(*itr);
                 path[*itr]=v;
                 freq[*itr]++;
             }          
        }

    }
  
    if(temp==1) cout<<"Negative cucle present";
    else {
            for(auto x: distance ){
                cout<<"Distance of vertex "<<x.first<<"is: "<<x.second<<endl;
            }
            for(auto x: path){
                cout<<"path of vertex "<<x.first<<" is through  :"<<x.second<<endl;
            }
    }

}
int main(){
    Graph g(9);

    // g.addEdge(0,1,4);
    // g.addEdge(0,2,2);
    // g.addEdge(1,3,2);
    // g.addEdge(1,2,3);
    // g.addEdge(1,4,3);
    // g.addEdge(2,1,1);
    // g.addEdge(2,4,5);
    // g.addEdge(2,3,3);
    // g.addEdge(4,3,-5);

    // g.addEdge(0,1,10);
    // g.addEdge(0,5,8);
    // g.addEdge(1,3,2);
    // g.addEdge(2,1,1);
    // g.addEdge(3,2,-2);
    // g.addEdge(4,3,-1);
    // g.addEdge(4,1,-4);
    // g.addEdge(5,4,1);
  


    // g.addEdge(0,1,4);
    // g.addEdge(0,2,5);
    // g.addEdge(1,2,5);
    // g.addEdge(2,3,3);
    // g.addEdge(3,1,-10);

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
    g.belmanFord(0);



}



