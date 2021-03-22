#include<bits/stdc++.h>
using namespace std;
void merge(vector<int> &arr, int left,int right,int mid){       //merge function to conquer left and right array
    vector<int> leftArray;
    vector<int> rightArray;
    int n1,n2;
    n1=mid-left+1;
    n2=right-mid;
    int i,j,k;
    for(i=0;i<n1;i++){
        leftArray.push_back(arr[i+left]);
    }
    for(i=0;i<n2;i++){
        rightArray.push_back(arr[i+mid+1]);
    }
    i=0;j=0,k=left;
    while(i<n1 && j<n2){
        if(leftArray[i]<rightArray[j]){
            arr[k]=leftArray[i];
            i++;k++;
        }
        else{
            arr[k]=rightArray[j];
            j++;k++;
        }
    }
    while(i<n1){
        arr[k]=leftArray[i];
        i++;k++;
    }
    while(j<n2){
        arr[k]=rightArray[j];
        j++;k++;
    }
}
void mergeSort(vector<int>& arr,int left,int right){    //mergeSort divides array in left and right
    int mid= (left+right)/2;
    if(left<right){
        mergeSort(arr,left,mid);
        mergeSort(arr,mid+1,right);
        merge(arr,left,right,mid);
    }
    else return;
}
int main(){
     int m,n,x,L,i,j;
    vector<int> arr;
    cout<<"Enter number of tapes: ";
    cin>>m;
    cout<<"Enter length of each tape: ";
    cin>>L;
    cout<<"Enter number of programmes: ";
    cin>>n;
    cout<<"Enter length of each programme: "; // pushing the lebgths of programmes in vector
    for(int i=0;i<n;i++){
        cin>>x;
        arr.push_back(x);
    }
    mergeSort(arr,0,n-1);                   // sorting the vector to implement greedy approach
    // for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    vector<int> tapes[m];           //array of vectors to store tapes
    float MRT[m];float MRT1;        //array to store MTR of each tape
    for(int i=0;i<m;i++){
        tapes[i].push_back(L);      //assign first element of each individual tape to be the max length of tape
    }
    j=0;
    for(i=0;i<n;i++){
        if(j==m) j=0;
        if(arr[i]<=tapes[j][0]){
            tapes[j].push_back(arr[i]); //writing programnes on the tape if length is less than total length
            tapes[j][0]-=arr[i];        //update the totallength of that tape
            j++;
        }
        else break;
    }
    if(i!=n){               // if no sufficient storage on the tape print programes that cant be printed
        cout<<endl<<"---------------------------------------------------------------------"<<endl;
        cout<<endl<<"No sufficient storage for programme with length:  ";
        for(int j=i;j<n;j++) cout<<arr[j]<<" ";
        cout<<endl;
    }
    MRT1=0;
    for(i=0;i<m;i++) MRT[i]=0;
    for(i=0;i<m;i++){
        int tempSize= tapes[i].size();
        for(j=1;j<tempSize;j++){
            MRT[i]+=(tempSize-j)*tapes[i][j];   //finding MRT of each tape
        }
        MRT[i]=MRT[i]/(tempSize-1);
        MRT1+= MRT[i];      //finding the average MTR
    }
    cout<<endl<<"---------------------------------------------------------------------"<<endl;

    for(i=0;i<m;i++){
        cout<<endl<<i+1<<"th tape: ";
        for(j=1;j<tapes[i].size();j++){
            cout<<"|"<<tapes[i][j]<<" ";        //printing the tapes and programes on them
        }
        cout<<"|MRT: "<<MRT[i];     //printing MRT
        cout<<endl;
    }
    cout<<endl<<"---------------------------------------------------------------------"<<endl;
    cout<<endl<<"MTR(average): "<<MRT1/m<<endl;  //printing Average MRT
    cout<<endl<<"---------------------------------------------------------------------"<<endl;


    
}