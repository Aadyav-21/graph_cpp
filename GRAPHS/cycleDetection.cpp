#include<iostream>
#include<unordered_map>
#include<queue>
#include<list> 
#include<set>
using namespace std;
bool isCyclicBFS(int src,unordered_map<int,bool>& visited,unordered_map<int,list<int>>&adj){
    parent[src]=-1;
    visited[src]=1;
    queue<int>q;
    q.push(src);
    while(!q.empty()){
        int fornt=q.front();
        q.pop();
        for(auto i:adj[front]){
            if(visited[i]==true && i!=parent[front])return true;
            else if(!visited[i]){
                q.push(i);
                visited[i]=1;
                parent[i]=front;
            }
        }
    }
    return false;
}
string cycleDetection(vector<vector<int>>& edges,int n,int m){
    //crete adjaceency list
    unordered_map<int,list<int>>adj;
    for(int i=0;i<m;i++){
        int u=edges[i][0];
        int v=edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    //to handle disconnected components
    unordered_map<int,bool>visited;
    for(int i=0;i<n;i++){
        if(!visited[i]){
            bool ans=isCyclicBFS(i,visited,adj);
            if(ans==1)return "Yes";
        }
    }
    return "No";
}
