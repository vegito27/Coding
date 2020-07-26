#include <iostream>
using namespace std;


bool isPossible(int m,int n,int k,int r,vector<int> X,vector<int> Y){

	int rect[m][n]=0;

	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j)
			for (int p = 0; p < k; ++p)
			    if(sqrt(pow(X[p]-1-i),2)+pow(Y[p]-1-j)<=r)
			         rect[i][j]=-1;



	if(rect[0][0]=-1) return false;

	vector<vector<int>> que;

	rect[0][0]=1;

	que.push_back({0,0});

	while(!que.empty()){

		
	}



	
	




}
