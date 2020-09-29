#include<iostream>
#include<vector>
using namespace std;

int minpathSum(vector<int> grid[]){

    for(int i=0;i<grid->size();i++){
        for(int j=0;j<grid[0].size();j++){

            if(i==0 and j!=0){
                grid[i][j] +=grid[i][j-1];
            }else if (i!=0 and j==0)
            {
                grid[i][j] +=grid[i-1][j];
            }else if(i==0 and j==0){
                grid[i][j]=grid[i][j];
            }else{
                grid[i][j]=max(grid[i][j-1],grid[i-1][j]);
            }
        }
    }

    return grid[grid->size()-1][grid[0].size()-1];

}

 int main(int argc, char **argv)
{
  


  

    return 0;
}
