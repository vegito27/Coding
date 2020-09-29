#include<iostream>
#include <cmath>
using namespace std;



void split(int arr[],int size,int workers){

int sum=0;

for(int i=0;i<size;i++){
    sum=sum+arr[i];

}


int index[workers-1];
int l=0;

int mean_value=sum/workers;

int i=0;

while(i<size){

    if(mean_value-arr[i]>0){

    mean_value -=arr[i];

    i++;
       
    }
    else{

        int v1=mean_value;
        int v2=mean_value-arr[i];

        if(abs(sum-v1)/workers>abs(v2-sum)/workers){
            mean_value=sum/workers;
            index[l]=i;
            i++;
            
        }else{
            index[l]=i+1;

            mean_value=sum/workers;

            i+=2;
            
        }





    }

}










}




int main(){




    return 0;

}