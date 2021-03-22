#include<bits/stdc++.h>
using namespace std;
void addEdge(vector<int> arr[],int u,int v){
    arr[u].push_back(v);
    arr[v].push_back(u);
}
void printGraph(vector<int> arr[],int n){
    for(int i=0;i<n;i++){
        cout<<i;
        for(int j=0;j<arr[i].size();j++){
            cout<<"->"<<arr[i][j];
        }
        cout<<endl;
    }
}
int main(){
    int n;
    cout<<"Enter number of vertices: ";
    cin>>n;
    vector<int> arr[n];
    addEdge(arr,0,1);
    addEdge(arr,0,3);
    addEdge(arr,0,4);
    addEdge(arr,1,2);
    addEdge(arr,1,4);
    addEdge(arr,2,4);
    printGraph(arr,n);

}