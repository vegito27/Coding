#include <iostream>
using namespace std;


int solve(int arr[],int size){
    
    int max_left=arr[0];
    int min_right=arr[size-1];
    int start=1;
    int end=size-2;
    
    while(start<size-1){
        if(arr[start]>max_left) {
            max_left=arr[start];
            break;
        }
        max_left=arr[start];
        start++;

    }
  

    while(end>1){
        if(arr[end]>min_right){
            min_right=arr[end];
            break;
        }
        min_right=arr[end];
        --end;
    }
     


    if(start-end>=0) return arr[start];


    return -1;
  
    
}



int main()
 {

	 int arr[]={4,2,5,7};
	 cout<<solve(arr,4);

	return 0;
}