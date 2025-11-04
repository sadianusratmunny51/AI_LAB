#include<bits/stdc++.h>
using namespace std;

bool isSafe(int col, vector<int>&color,vector<vector<int>>&graph,int node){
    for(auto i=0;i<graph[node].size();i++){
        if(color[i]==col)return false;
    }
    return true;
}
bool func(int node,int n,int m,vector<vector<int>> &graph,vector<int>&color){

    if(node==n+1){
        return true;
    }
    for(int col=1;col<=m;col++){
        if(isSafe(col,color,graph,node)){
           color[node]=col;
           if(func(node+1,n,m,graph,color)==true){
            return true;
           }
           else{
            color[node]=0;
           }
        }
    }
    return false;
}

int32_t main(){
     

     int n,m;
    cin>>n>>m;
    vector<int>color(n+1,0);
    vector<vector<int>> graph(n+1);

    for(int i=1; i<=m;i++){
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    int col; cin>>col;
    if(func(1,n,col,graph,color)==true){
       cout<<"YES"<<endl;
    }
    else {
        cout<<"NO"<<endl;
    }






    return true;

}