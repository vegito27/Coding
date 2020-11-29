#include<iostream>
using namespace std;

void trappingRain(int arr[],int size){

    int left[size];
    int right[size];

    left[0]=arr[0];
    int left_max=arr[0];

    right[size-1]=arr[size-1];
    int right_max=arr[size-1];



    for(int i=1;i<size;i++){

        if(arr[i]>left_max){
            left_max=arr[i];
        }
        left[i]=left_max;
    
    }

    for(int j=size-1;j>=0;j--){

        if(arr[j]>right_max){
            right_max=arr[j];
        }
        right[j]=right_max;
    }



for (int i = 0; i < size; i++)
{
cout<<left[i]<<" ";
}

cout<<endl;

for (int i = 0; i < size; i++)
{
cout<<right[i]<<" ";
}

cout<<endl;

for(int i=0;i<size;i++){

int number=min(left[i],left[i]);

cout<<arr[i]-number<<" ";

}




}

int main(){

    int arr[]={2,3,1,5,6,5};

    trappingRain(arr,6);

    return 0;
}