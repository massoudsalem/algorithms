#include <bits/stdc++.h>
using namespace std;
int dis [2000+5]; //distance array
bool vis[2000+5]; //visited array
vector<int> AdjList[100000+5];
vector<int> ToboSort;//topological sort vector
int n,e,u,v; //n is nodes //e is edges //u is perent //v is child
int shortestPath[100000+5];//shortest path array
bool relaxed[100000+5];//relaxed array
vector<pair<int,int>> djiAdjList[100000+5];//djikstra graph
int shortest,minDis;//shortest child,minimum distance
int CC=0;
void CreatingAdjListGraph(){
		cin>>n>>e;
		for(int i=0;i<e;++i){
			cin>>u>>v;
			AdjList[u].push_back(v);
			//AdjList[v].push_back(u); //undirected graph
		}
}
void PreGraph(int n=0){	//Graph preparation
	//memset(dis,-1,sizeof(dis));  //BFS distance array preparation
	//memset(vis,0,sizeof(vis));	//DFS visited array preparation
	// memset(relaxed, 0, sizeof(relaxed)); //djikstra relaxed array preparation
	// fill(shortestPath,shortestPath+n, 1e9);	//djikstra shortestPath array preparation
}
void djikstra_k(int root){ //O(nlogn) cuz of priority_queue
	priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	shortestPath[root]=0;
	relaxed[root]=1;
	for(auto v:djiAdjList[root]){
		shortestPath[v.first]=v.second;
		pq.push({v.second,v.first});
	}
	while(!pq.empty()){
		minDis=pq.top().first,shortest=pq.top().second;
		pq.pop();
		if(!relaxed[shortest]){
			relaxed[shortest]=1;
			for(auto v:djiAdjList[shortest]){
				if(shortestPath[v.first]>shortestPath[shortest]+v.second){
					shortestPath[v.first]=v.second;
					pq.push({v.second,v.first});
				}
			}
		}
	}
}
void dijkstra(int root){
	priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	fill(shortestPath,shortestPath+n, 1e9);
	shortestPath[root]=0;
	pq.push({0,root});
	while(!pq.empty()){
		minDis=pq.top().first,shortest=pq.top().second;
		pq.pop();
		if(minDis>shortestPath[shortest])continue;
		for(auto v:djiAdjList[shortest]){
			if(shortestPath[v.first]>shortestPath[shortest]+v.second){
				shortestPath[v.first]=shortestPath[shortest]+v.second;
				pq.push({shortestPath[v.first],v.first});
			}
		}
	}
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
int Connectedcomponents(){  //counting number of connectedcomponents
	for(int i=1;i<=n;++i){
    if(!vis[i]){
      DFSItr(i);
      CC++;
    }
  }
  return CC;
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
