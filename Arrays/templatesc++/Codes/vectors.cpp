#include<vector>
#include<iostream>
#include <string>

using namespace std;


void practice_vectors(vector<int>& list){


   vector<int>* mylist = &list ;

   for(auto a:  *mylist ) cout<<"->"<<a;

//    for(int i=0;i < mylist.size();i++){


//    }


}

 int  main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    int n=100;
    
    //initialise the vector with size n and initial value 1;

    vector<int> list(n,1);

    //enhance for loop 

   // for(int v:list) cout<<v<<" ";

   vector<string> my_vector{ "h1","h2","h3" };

   for (size_t i = 0; i < my_vector.size(); i++)
   {
       cout<<my_vector[i]<<" ";
   }
   




    practice_vectors(list);






    


    
    return 0;
}


