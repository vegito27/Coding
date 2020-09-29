#include<iostream>
using namespace std;


long gcd(long long a,long long b){

	if(a==0) return b;

	return gcd(b%a,a);
}


long solve(long long x,long long y)
{
return (x*y)/gcd(x,y);
}



int main(int argc, char const *argv[])
{
	int test;

	cin>>test;

for (int i = 0; i < test; ++i)
{
		int x,y;

		cin>>x>>y;

		cout<<solve(x,y)<<endl;
	}



	return 0;
}