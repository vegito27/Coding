#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int arr[]={-1,-1,0,9,9,9,8,9,0,1,1,2,2,2,2,3,3,3,4,5};

int start=0;


for (int ptr = 0; ptr < sizeof(arr)/sizeof(arr[0]);ptr++ )
{
	if(arr[ptr]==arr[ptr+1])continue;
	else{

		start++;
	}



}

cout<<start;

	return 0;
}