#include<iostream>
#include<vector>
#include <string>

using namespace std;

vector<string>* getss(string str,int i){

	if(i==-1){
		std::vector<string>* bres=new std::vector<string>() ;

		bres->push_back("-");

		return bres;

	}
	char ch=str[i];

	std::vector<string>* rres=getss(str,i-1);

	std::vector<string>* mres=new std::vector<string>() ;

	for(auto rstr=rres->begin();rstr!=rres->end();rstr++) mres->push_back(*rstr);


	for(auto rstr=rres->begin();rstr!=rres->end();rstr++){
		string* mstr=new string(*rstr);

		mstr->push_back(ch);

		mres->push_back(*mstr);
	}


    return mres;

}


int	main(int argc, char **argv)

{

	string value="abc";



    std::vector<string>* ans= getss(value,5);

    for(auto sol=ans->begin();sol!=ans->end();sol++) cout<<*sol<<",";


    return 0;
}
