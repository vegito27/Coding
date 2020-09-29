#include<iostream>
using namespace std;

int solve(int n,int m,int a){
	int ans=0;

	if(n%a==0){
		ans +=n/a;
	}else if(n%a<0){
		ans +=n/a+1;
	}

	if(m%a==0){
		ans +=m/a;
	}else if(m%a<0){
		ans +=m/a+1;
	}

	return ans;
}


int main(int argc, char const *argv[])
{
	

		int m,n,a;

		cin>>m>>n>>a;

		int ans=solve(m,n,a);

		cout<<ans;

	     return 0;
}