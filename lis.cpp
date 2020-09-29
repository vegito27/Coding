#include<iostream>
#include<vector>
#include<map>
#include<string>
using namespace std;

int solve(string s){

     map<char, int> mp;

	int length=0;
	int max_length=0;


	for (int i = 0; i < s.size(); ++i)
	{

		if(mp.find(s[i])!=mp.end()){

			length=max(length,i-mp[s[i]]+1S);

			cout<<length<<" ";

			max_length=max(max_length,i-length+1);

		}

		mp[s[i]]=i;

		cout<<s[i]<<"->"<<mp[s[i]]<<" "<<endl;

	}

return max_length;


}


int main(int argc, char const *argv[])
{
	cout<<solve("execute")<<endl<<endl;
	cout<<solve("abcabcbb");
	


	return 0;
}
