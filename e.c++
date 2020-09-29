#include<iostream>
#include<algorithm>

using namespace std;


int main(int argc, char const *argv[])
{


	int arr[]={1,2,0,4,0,0,7,0,9,0};

	//1,2,4,


	int ctr1=0;
	int ctr2=0;
	int n=sizeof(arr)/sizeof(arr[0]);

	for (int i = 0; i < n; ++i)
	{
		if(arr[ctr1]!=0 and arr[ctr2]!=0 and ctr1==ctr2){
			ctr1++;
			ctr2++;
		}
		else if(arr[ctr1]==0 and arr[ctr2]==0){
			ctr2++;
		}

		else if(arr[ctr1]==0 and arr[ctr2]!=0){
			swap(arr[ctr1],arr[ctr2]);
			ctr1++;
			ctr2++;
		}

	}

	for (int i = 0; i < n; ++i)
	{

		cout<<arr[i]<<" ";
		}





	
	return 0;
}