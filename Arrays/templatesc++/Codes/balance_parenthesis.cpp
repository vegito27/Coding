#include<iostream>
#include<string>
#include<stack>


using namespace std;

bool balance_parenthesis(string s){
    
    stack<char> stc;
    

    for(int i=0;i<s.size();i++){
        
        cout<<"character ->"<<s[i]<<endl;
        
        if(stc.empty())stc.push(s[i]);
        
        
        if((stc.top()=='(' && s[i]==')') || (stc.top()=='[' && s[i]==']') || (stc.top()=='{' && s[i]=='}')) stc.pop();
       
       
        if(stc.top()==')' or stc.top()==']' or stc.top()=='}') stc.push(s[i]);
        
        cout<<"top ->"<<stc.top()<<endl;

       
    
    }
    cout<<stc.top()<<endl;
    
   if (stc.empty()) return true;
   
   return false;
    
}



int main()
 {
     
	bool answer=balance_parenthesis("{{{}}}");
	
	cout<<answer;
	
	return 0;
}