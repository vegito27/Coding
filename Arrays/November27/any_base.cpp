#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int src_to_decimal(int num,int base){
    
    int power=0;
    int sum=0;
    int remainder;   
    
    while(num!=0){
    
        remainder=num%10;
       
        num=num/10;
        
        sum+=remainder*pow(base,power);
       
        power++;
        
    }

    return sum;
}

int src_to_decimal2(string ch1,int base){
    
    int  toadd;
   // int len=sizeof(ch1)/sizeof(ch1[0]);
    int sum=0;
    int power=0;
    
    for(int i=ch1.size()-1;i>=0;i--){
        
        if(ch1[i]>='A' && ch1[i]<='F')
        {
            toadd=(int)ch1[i]-'A'+10;
           
          //  cout<<toadd<<endl;
           sum=sum+toadd*pow(base,power);
            
        power++;
        
        }
        if(ch1[i]>='0' && ch1[i]<='9'){
            
            toadd=(int)ch1[i]-'0';
           // cout<<toadd<<endl;
            
            sum=sum+toadd*pow(base,power);
            
            power++; 
        } 
    }
   
    return sum;
}

string deci_to_base(int num,int base2){
    
    string res="";
    
    while(num!=0){

        int remainder=num%base2;
        
        res=res+to_string(remainder);
        
        num=num/base2;
    }
    
    return res;
}

string deci_to_base2(int num,int base3){
    
    char val;
    
    string res="";
    while(num!=0){
        
        int remainder=num%base3;
        
        if(remainder==10) val='A';
        
        else if(remainder==11) val='B';
        
        else if(remainder==12) val='C';
        
        else if(remainder==13) val='D';
        
        else if(remainder==14) val='E';
        
        else if(remainder==15) val='F';
        
        else{
            
           val=remainder+'0';
        }
        num=num/base3; 
        res+=val;  
    }
    
  return res;  
    
}

string reverse(string s){
    
    int end=s.size()-1;
    int start=0;
    
    while(start<end){
        
        char ch=s[start];
        
        s[start]=s[end];
        
        s[end]=ch;
        
        start++;
        end--;   
    }
    
    return s;
}

int main() {

    string s;
    int basex,basey;
    
    cin>>s;
    cin>>basex;
    cin>>basey;
    
  //  string val =decitobase(37,8);
   // cout<<val<<endl;
    //string finalval=reverse(val);
    //cout<<finalval<<endl;
    
    char ch2[]="77"; 
    
    int val3=src_to_decimal2(ch2,basex);
     
   // cout<<val3<<endl;
    
    string val4=deci_to_base2(val3,basey);
    
    cout<<val4<<endl;
    
    //string finalval2=reverse(val4);
    
   // cout<<finalval2<<endl;
    
    return 0;
}
