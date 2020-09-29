#include<iostream>
#include<vector>

using namespace std;

int main(int argc, char const *argv[])
{
	vector<int> arr={1,2,4,3,6,2,7};

	int ans=0;


	
	for (int i = 0; i < arr.size(); ++i)
	{
		int left=i-1;

		cout<<left<<endl;

		int right=i+1;

		int value=arr[i];

		while(left>=0 or right< arr.size()){

			if(value>arr[left] and left>=0){

				ans+=arr[left];
				left--;

			}

			if(value>arr[right] and right<arr.size()){

				ans+=arr[right];
				right++;

			}
		}

	}


	cout<<ans;

	return 0;



}










