#include<iostream>
#include<unordered_map>
#include<list> 
using namespace std;
class graph{
    public:
        unordered_map<int,list<int>>adj;
        void addEdge(int u,int v,bool direction){
            //direction=0->undirected
            //direction=1->directed graph
            //create an edge from u to v
            adj[u].push_back(v);
            if(direction==0)adj[v].push_back(u);
        }
        void print(){
            for(auto i:adj){
                cout<<i.first<<"->";
                for(auto j:i.second){
                    cout<<j<<",";
                }
                cout<<endl;
            }
        }
};
//representation in form of 2d vectors
 vector<vector<int>> printAdj(int n,int m,vector<vector<int>>& edges){
    vector<int>ans[n];
    //ans array will store all adjacent nodes
    for(int i=0;i<m;i++){
        int u=edges[i][0];
        int v=edges[i][1]
        ans[u].push_back(v);
        ans[v].push_back(u);
    }
    vector<vector<int>>adj;
    for(int i=0;i<n;i++){
        adj[i].push_back(i);
        //entering neighbours
        for(int j=0;j<ans[i].size();j++){
            adj[i].push_back(ans[i][j]);
        }
    }
    return adj;
 }
int main(){
    int n;
    cout<<"enter the number of nodes"<<endl;
    cin>>n;
    int m;
    cout<<"enter the number of edges"<<endl;
    cin>>m;
    graph g;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        //creating an undirected graph
        g.addEdge(u,v,0);
    }
    //printing graph
    g.print();
    return 0;
}