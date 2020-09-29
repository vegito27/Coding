#include<iostream>
#include<vector>
using namespace std;

int main(int argc, char const *argv[])
{
	std::vector<int> arr={1,2,4,3,6,2,7};


	for(int i=0;i<arr.size();i++){
		int left=i;
		int right=i;
		int number=arr[i];
		int ans=arr[i];
		cout<<" i ="<<i<<" ,";
		

		while(left>=0){

			if(arr[left-1]>=number){

			 ans+=arr[i];
			
			left--;
		    
		    }
		    else break;
		}


		while(right<=arr.size()-1){

			if(arr[right+1]>=number){
				ans+=arr[i];
			    right++;
		    }

		  else break;
        }

        cout<<left<<" "<<right<<" ";

        int width=right-left+1;

        cout<< "width-> "<<width<<endl;


        n=max(n,ans);

	}


cout<<n;


	return 0;
}