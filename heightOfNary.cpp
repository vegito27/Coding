#include <iostream>
using namespace std;

int fillHeight(int p[],int node,int visited[],int height[]){

	if(p[node]==-1){

		visited[node]=1;
		
		return 0;
	}

	if(visited[node]) return height[node];


	visited[node]=1;


	height[node]=1+fillHeight(p,p[node],visited,height);

	return height[node];

}


int findHeight(int parent[],int n){

	int ma=0;

	int visited[n];


	int height[n];

	memset(visited,0,sizeof(visited));

	memset(height,0,sizeof(height));

	for (int i = 0; i < n; ++i)
	{
		if(!visited[i])height[i]=fillHeight(parent,i,visited,height);


		ma=max(ma,height[i]);
		
	}

    return ma;

}

int main(int argc, char const *argv[])
{
	int parent[]={-1,0,0,3,1,1,2};
	int n=sizeof(parent)/sizeof(parent[0]);


	cout<<"Height of N-ary tree is = "<<findHeight(parent,n);

	cout<<endl;

	return 0;

}









