#include<iostream>
#include<unordered_map>
#include<queue>
#include<list> 
#include<set>
#include<algorithm>
using namespace std;
//finding MST by union by rank and path compression method
bool cmp(vector<int>&a,vector<int>&b){
    return a[2]<b[2];
}
void makeSet(vector<int>&parent,vector<int>&rank,int n){
    for(int i=0;i<n;i++){
        parent[i]=i;
        rank[i]=0;
    }
}
int find(vector<int>&parent,int node){
    if(parent[node]==node)return node;
    return parent[node]=find(parent,parent[node]);
}
void union(int u,int v,vector<int>&parent,vector<int>&rank){
    u=find(parent,u);
    v=find(parent,v);
    if(rank[u]<rank[v])parent[u]=v;
    else if(rank[v]<rank[u])parent[v]=u;
    else {
        parent[v]=u;
        rank[u]++;
    }
}
int MST(vector<vector<int>>&edges,int n){
    sort(edges.begin(),edges.end());
    vector<int>parent(n);
    vector<int>rank(n);
    makeSet(parent,rank,n);
    for(int i=0;i<edges.size();i++){
        int u=find(parent,edges[i][0]);
        int v=find(parent,edges[i][1]);
        int wt=edges[i][2];
        if(u!=v){
            minWeight+=wt;
            union(u,v,parent,rank);
        }
    }
    return minWeight;
}
//kruskal's algo to find MST

