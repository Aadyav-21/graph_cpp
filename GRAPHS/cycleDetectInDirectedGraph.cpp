#include<iostream>
#include<unordered_map>
#include<queue>
#include<list> 
#include<set>
using namespace std;
bool check(int node,unordered_map<int,bool>&visited,unordered_map<int,bool>&dfsVisited,unordered_map<int,list<int>>adj){
    visited[node]=true;
    dfsVisited[node]=true;
    for(auto i:adj[node]){
        if(!visited[i]){
            bool cycle=check(i,visited,dfsVisited,adj);
            if(detect)return true;
        }
        else if (dfsVisited[i])return true;
    }
    dfsVisited[node]=false;
    return false;
}
int detect(int n,vector<pair<int,int>>& edges){
    //create adj list
    unordered_map<int,list<int>>adj;
    for(int i=0;i<edges.size();i++){
        int u=edges[i].first;
        int v=edges[i].second;
        adj[u].push_back(v);
    }
    //call dfs for all componenets
    unordered_map<int,bool>visited;
    unordered_map<int,bool>dfsVisited;
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            bool cycle=check(i,visited,dfsVisisted,adj);
            if(cycle)return true;
        }
    }
    return false;
}