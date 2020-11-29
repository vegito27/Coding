#include<iostream>
using namespace std;



void printprimes(int upto){

for (int i = 2; i < upto; ++i)
{

	bool isprime=true;

	for (int j = 2; j*j <=i; ++j)
	{
		if(i%j==0){ 

			isprime=false;

			break;

		}

		else
			continue;

	}

	if(isprime) cout<<i<<" ";

	}

}




int main(int argc, char const *argv[])
{
	printprimes(100);
	
	return 0;
}
