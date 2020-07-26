#include<iostream>
using namespace std;

void merge(int arr[],int l,int m,int r){

	int i,j,k;
	int n1=m-l+1;
	int n2=r-m;

	int L[n1],R[n2];

	for (int i = 0; i < n1; ++i) L[i]=arr[l+i];

	for (int i = 0; i < n2; i++)R[j]=arr[m+1+j];

	i=0;k=0;k=l;
while(i<n1 && j<n2){

	if(L[i]<=R[j]){
		arr[k]=L[i];
		i++;
	}

	else{
		arr[k]=R[j];
		j++;
	}
}

while(i<n1){
	arr[k]=L[i];
	i++;
	k++;
}

while(j<n2){
	arr[k]=R[j];
	j++;
	k++;

 }
}


void mergeSort(int arr[],int l,int r){

	if(l<r){

	int mid=l+(r-l)/2;

	mergeSort(arr,0,mid);
	
	mergeSort(arr,mid+1,r);

	merge(arr,l,mid,r); 
    
    }

}











int main(int argc, char const *argv[])
{
	int arr[] = {10, 7, 8, 9, 1, 5};

	 mergeSort(arr,0,6);

	 for (int i = 0; i < 6; i++) 
        printf("%d ", arr[i]); 



	return 0;
}




















