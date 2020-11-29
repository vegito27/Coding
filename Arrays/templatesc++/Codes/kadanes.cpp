#include <iostream>
#include <climits>
#include<algorithm>

using namespace std;

int Kadanes(int arr[],int size){
    
    int max_sum=INT_MIN;

    int current_sum=arr[0];


    for(int i=0;i<size;i++){

        if(current_sum+arr[i]>arr[i]){

            current_sum+=arr[i];
          

        }else{
            current_sum=arr[i];
        }

        if(current_sum>max_sum) max_sum=current_sum;


    }

    return max_sum;

}


int triplets(int arr[],int size){
    
    sort(arr,arr+size);
    int count=0;
    int start=0;
    int end=size-1;


    
    
    for(int i=0;i<size-1;i++){
        int v1=arr[start];
        int v2=arr[end];
        int number=v1+v2;
        
        if(binary_search(arr+start,arr+end,number)) count++;
        
        end--;    
    }

    return count;    
}


int main(){


    int arr[]={-1,-2,-3,-4};

//    cout<<Kadanes(arr,4);

cout<<triplets(arr,4);


    return 0;

}
