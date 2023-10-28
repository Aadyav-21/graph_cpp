#include<iostream>
#include<unordered_map>
#include<queue>
#include<list> 
#include<set>
using namespace std;
void topo(int node,unordered_map<int,bool>&visited,stack<int>&s,unordered_map<int,list<int>){
    visited[node]=1;
    for(auto i:adj[node]){
        if(!visited[i])topo(i,visited,s,adj);
    }
    s.push(node);
}
vector<int> sort(vector<vector<int>>& edges,int v,int e){
    //create adj list
    unordered_map<int,list<int>>adj;
    for(int i=0;i<e;i++){
        int u=edges[i][0];
        int v=edges[i][1];
        adj.push_back(v);
    }
    //call dfs topological sort util function for all components
    unordered_map<int,bool>visited;
    stack<int>s;
    for(int i=0;i<v;i++){
        if(!visited[i])topo(i,visited,s,adj);
    }
    vector<int>ans;
    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}