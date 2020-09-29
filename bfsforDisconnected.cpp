#include<iostream>
#include<vector>
#include<list>
using namespace std;

void addEdge(vector<int> adj[],int u,int v){

	adj[u].push_back(v);
}

void BFSUtil(int u,vector<int> adj[],vector<bool>& visited){
	
	list<int> que;
    
	visited[u]=true;
    
	que.push_back(u);
    
	while(!que.empty()){
	
		u=que.front();

		cout<<u<<" ";

		que.pop_front();

		for(int i=0;i<adj[u].size();i++){
			if(!visited[adj[u][i]]){
				visited[adj[u][i]]=true;
				que.push_back(adj[u][i]);
			}
		}
	}
}

void BFS(vector<int> adj[],int V){
	vector<bool> visited(V,false);
	for (int i = 0; i < V; ++i)
		if(visited[i]==false) BFSUtil(i,adj,visited);
}


int main(int argc, char const *argv[])
{
	
    int V = 5; 
    vector<int> adj[V]; 
  
    addEdge(adj, 0, 4); 
    addEdge(adj, 1, 2); 
    addEdge(adj, 1, 3); 
    addEdge(adj, 1, 4); 
    addEdge(adj, 2, 3); 
    addEdge(adj, 3, 4); 
    BFS(adj, V); 

    return 0; 
	return 0;
}


