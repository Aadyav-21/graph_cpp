#include<iostream>
#include<unordered_map>
#include<queue>
#include<list> 
#include<set>
using namespace std;
//using Kosaraju's algo find stronglu component
void dfs(int node,unordered_map<int,bool>&vis,stack<int>&st,unordered_map<int,list<int>adj){
    vis[node]=true;
    for(auto nbr:adj[node]){
        if(!vis[nbr])dfs(nbr,vis,st,adj);
    }
    //topo logic
    st.push(node);
}
void revdfs(int node,unordered_map<int,bool>&vis,unordered_map<int,list<int>>&adj){
    vis[node]=true;
    for(auto nbr:adj[node]){
        if(!vis[nbr])revdfs(nbr,vis,adj);
    }
}
int SCC(int v,vector<vector<int>>&edges){
    //adj
    unordered_map<int,list<int>>adj;
    for(int i=0;i<edges.size();i++){
        int u=edges[i][0];
        int v=edges[i][1];
        adj[u].push_back(v);
    }
    //topo sort
    stack<int>st;
    unordered_map<int,bool>vis;
    for(int i=0;i<v;i++){
        if(!vis[i])dfs(i,vis,st,adj);
    }
}
//transpose graph
unordered_map<int,list<int>>transpose;
for(int i=0;i<v;i++){
    vis[i]=0;
    for(auto nbr:adj[i]){
        transpose[nbr].push_back(i);
    }
}
//dfs call on transpose
int count=0;
while(!st.empty()){
    int top=st.top();
    st.pop();
    if(!vis[top]){
        count++;
        revdfs(top,vis,transpose);
    }
}
return count;