#include<iostream>
#include<unordered_map>
#include<queue>
#include<list> 
#include<set>
using namespace std;
void dfs(int node,unordered_map<int,bool>&vivisted,unordered_map<int,list<int>>&adj,vector<int>&comp){
    comp.push_back(node);
    visited[node]=true;
    //hr connected node k liye recursive call
    for(auto i:adj[node]){
        if(!visited[i])dfs(i,visited,adj,comp);
    }
}
vector<vector<int>> DFS(int v,int e,vector<vector<int>> &edges){
    //prepare adjlist
    unordered_map<int,list<int>>adj;
    for(int i=0;i<edges.size();i++){
        int u=edges[i][0];
        int v=edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<vector<int>>ans;
    unordered_map<int,bool>visited;
    for(int i=0;i<v,i++){
        if(!visited[i]){
            vector<int>comp;
            dfs(i.visited,adj,comp);
            ans.push_back(comp);
        }
    }
    return ans;
}