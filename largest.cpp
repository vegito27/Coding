#include <iostream>
using namespace std;


int solve(int arr[],int size){
    
    int max_left=arr[0];
    int min_right=arr[size-1];
    int start=1;
    int end=size-2;
    int answer;
    
    while(start<end){
        if(arr[start]>max_left) {
            max_left=arr[start];
            break;
        }
        start++;

    }

    while(end<start){
        if(arr[end]>min_right){
            min_right=arr[end];
            break;
        }
        end--;
    }

    cout<<start<<endl<<end;
    
  
    
}



int main()
 {

	 int arr[]={4,3,2,7,8,9};
	 cout<<solve(arr,6);
	return 0;
}