//double pointers
// int * arr = new int[n]     ==simple array
// int **arr = new int* [n]   ==2d array of array, also each individual array needs to be allocated space 
//for(i=0;i<n;i++) arr[i]= new int [n]    == now a 2d array is declared

#include<bits/stdc++.h>
using namespace std;
class Graph {
    int  numberOfVertices;
    int numberOfEdges;
    int **matrix;
    public:
        Graph(int v){
            numberOfVertices=v;
            numberOfEdges=0;
            matrix=new int*[v];
            for(int i=0;i<v;i++){
                matrix[i]= new int[v];
                for(int j=0;j<v;j++)
                    matrix[i][j]=0;
            }
        }
        void addEdge(int u,int v);
        void printGraph();
};
void Graph::addEdge(int u,int v){
    matrix[u][v]=1;
    matrix[v][u]=1;
    numberOfEdges++;
}
void Graph:: printGraph(){
    for(int i=0;i<numberOfVertices;i++){
        for(int j=0;j<numberOfVertices;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"Total number of edges: "<<numberOfEdges;
}
int main(){
    Graph g(5);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,3);
    g.addEdge(2,4);
    g.addEdge(1,2);
    g.addEdge(0,4);

    g.printGraph();


}