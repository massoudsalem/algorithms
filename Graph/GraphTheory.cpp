#include <bits/stdc++.h>
using namespace std;
int dis [2000+5]; //distance array
bool vis[2000+5]; //visited array
vector<int> AdjList[100000+5];
vector<int> ToboSort;//topological sort vector
int n,e,u,v; //n is nodes //e is edges //u is perent //v is child
void CreatingAdjListGraph(){
		cin>>n>>e;
		for(int i=0;i<e;++i){
			cin>>u>>v;
			AdjList[u].push_back(v);
			//AdjList[v].push_back(u); //undirected graph
		}
}
void PreGraph(){	//Graph preparation
	//memset(dis,-1,sizeof(dis));  //BFS distance array preparation
	//memset(vis,0,sizeof(vis));	//DFS visited array preparation
}
void DFSRec(int root){	//Recursive
		vis[root]=1;
		for(auto v:AdjList[root]){
			if(!vis[v]) DFSRec(v);
		}
		//ToboSort.push_back(root); //topological sort
}
void DFSItr(int root){	//Iterative
		stack<int> stk;
		stk.push(root);
		vis[root]=1;
		while(!stk.empty()){
			u=stk.top();
			stk.pop();
			for(auto v:AdjList[u]){
				if(!vis[v]){
					stk.push(v);
					vis[v]=1;
				}
			}
		}
}
void BFS(int root){
    queue<int> qu;
    qu.push(root);
    dis[root]=0;
    while(!qu.empty()){
        u=qu.front();
        qu.pop();
        for(auto v:AdjList[u]){
            if(dis[v]==-1){
                dis[v]=dis[u]+1;
                qu.push(v);
            }
        }
    }
}
int main(){
		CreatingAdjListGraph();
 		BFS(0);
}
