#include <iostream>
#include<map>
#include<vector>
#include<queue>
#define MAX 1001
using namespace std;

vector<int> adj[MAX];


int build_tree(int arr[],int n){

	int root_index=0;

	for (int i = 0; i < n; ++i)
	{
		if (arr[i]==-1){

		root_index=i;
		
		}
		else{
		
			adj[i].push_back(arr[i]);
		
			adj[arr[i]].push_back(i);
		}	
	}

	return root_index;
}


int BFS(int start){

	std::map<int, int> map;

	queue<pair<int,int>> que;

	int max_level_reached=0;

	que.push({start,0});

	pair<int,int> p;


	while(!que.empty()){

		p=que.front();

		map[p.first]=1;

		max_level_reached=max(max_level_reached,p.second);

		que.pop();

		for (int i = 0; i < adj[p.first].size(); i++)
			if(!map[adj[p.first][i]])que.push({adj[p.first][i],p.second+1});
		
		
	}

	return max_level_reached;

}


int main(int argc, char const *argv[])
{
	 int parent[] = { -1, 0, 1, 2, 3 }; 
  
    // Number of nodes in tree 
    int n = sizeof(parent) / sizeof(parent[0]); 
  
    int root_index = build_tree(parent, n); 
  
    int ma = BFS(root_index); 
    cout << "Height of N-ary Tree=" << ma; 
    return 0; 

}





