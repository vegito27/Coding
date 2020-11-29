#include <iostream>
#include<string>
#include<cmath>
#include <unordered_map>
using namespace std;


void digits_count(long long number,int n){}
void any_base_to_any_base(string n,int cb,int rb){}


bool isPrime(int number){

    for (int i = 2; i*i <number; i++)
    {
        if(number%i==0) return false;       
    }
    
   return true;}

void primeTillN(int n){

    bool isPrime;

    for (int i = 2; i < n; i++)
    {
        isPrime=true;

        for (int j = 2; j*j <= i; j++)
        {
          if(i%j==0){
              isPrime=false;
              break;
          }
          else continue;

        }

        if(isPrime) cout<<i<<" ";
    }}

void reverse_number(int number){

    int num=number;
    int sum=0;
   
    while(num!=0){

        int rem=num%10;

        sum=sum+rem;

        sum=sum*10;
        
        num=num/10;
    }

    cout<<sum/10<<" ";}

int gcds(int num1,int num2){

    //can be solved with euclids method

    //breakings of euclid for gcd(600,136)
    //600=136*4+56
    //136=56*2+22
    //..so on

    int rem=num1%num2;

    if(rem==0) return num2;

   else return gcds(num2,rem);}

void fibonacci(int n){

    int previous=0,current=1 ,next;

    for (int i = 0; i <= n; i++)
    {
        cout<<previous<<" ";

        next=previous+current;

        previous=current;

        current=next;
       
    }}

void fibonacciTillN(int upto){

    int previous=0,current=1,next;

    while(previous<=upto){

        cout<<previous<<" ";

        next=previous+current;

        previous=current;

        current=next;

    }}

void p1(int n){
    for (int i = 1; i <=n; i++)
    {
        for (int j = 1; j <=i; j++)
        {
            cout<<"* ";
        }

        cout<<endl;

    }}

void p2(int n){

    int star=1,space=n/2;

    for (int i = 1; i <=n; i++)
    {
        for(int j=1;j<=space;j++)cout<<" ";
        
        for (int j = 1; j <=star; j++)cout<<"*";

        if(i<=n/2){
            space--;
            star+=2;

        }else{
            space++;
            star-=2;
        }

        cout<<endl;
    }}

void p3(int n){
    int star=n/2+1,space=1;

    for (int i = 1; i <= n; i++)
    {

        for (int j = 1; j <=star; j++)cout<<"*";

        for (int j = 1; j<=space; j++)cout<<" ";

        for (int j = 1; j <=star; j++)cout<<"*";

        if(i<=n/2){
            star--;
            space+=2;

        }else{
            star++;
            space-=2;

        }
        cout<<endl;
    }}

void p4(int n){

    int start=1,peak=n;

    for(int i=1;i<=n;i++){

        for (int j = 1; j <= n; j++)
        {
            if(j==start || j==peak){ 
                cout<<"*";

            }else{
                
                cout<<" ";
            }
        } 

        start++;
           peak--; 

        cout<<endl;
    }}

void p5(int n){

    int number=1;

    for (int i = 1; i <=n ; i++)
    {
       for (int j = 1; j <= i; j++)
       {
           cout<<number<<" "; 
           number++;        
       }

       cout<<endl;
       
    }}

void p6(int n){

    int previous=0,current=1,next;

    for(int i=1;i<=n;i++){

        for (int j = 1; j <=i; j++)
        {

            cout<<previous<<" ";

            next=current+previous;
            previous=current;
            current=next;
            
        }

        cout<<endl;

    }}

void p7(int n){

    for (int i = 0; i <=n ; i++)
    {
         int num=1;

        for (int j = 0; j <=i ; j++)
        {
            cout<<num<<" ";

            num=num*(i-j)/(1+j);

        }
        cout<<endl;          
    }}

void p8(int n){

     int space=n-1;
     int number;
   
     for (int i = 1; i <= n; i++)
     {
        number=i;
        
        for (int j = 1; j <= space; j++)
        {
            cout<<" ";   
        }

        for(int j=1; j<=2*i-1; j++){

            if(j<i){
                cout<<number;
                number++;
            }
            else if(j==i){
                cout<<number;
            }
            else{
                number--;
                cout<<number;            
            }
        }

        space--;
        cout<<endl;}}

void p9(int n){

    int space=n/2;
    int number=1;
    int var;

    for (int i = 1; i <= n; i++)
    {
        if(i<=n/2){
            number=i;
            var=number;
        }else{
            number=n-i+1;
            var=number;
        }

        for (int j = 1; j <=space ; j++)
        {
            cout<<" ";            
        }

        for (int j = 1; j <=2*var-1 ; j++)
        { 

            if(j<var){

                cout<<number;
                number++;

            }else if(j==var){
                cout<<number;


            }else{
                number--;

                cout<<number;
            }
 

        }

        if(i<=n/2){
            space--;

        }else{
            space++;
        }

        cout<<endl;
    
    
    }}

void p10(int n){

    int number=1,space;

    for (int i = 1; i <=n; i++)
    {
        number=1;

        if(i<n){
            space=2*n-2*i-1;
        }
        else{
            space=0;
        }


        for (int j = 1; j <=i ; j++)
        {
            cout<<number;
            number++;
            
        }
        for (int j = 1; j <=space ; j++)
        {
            cout<<" ";
            
        }

        if(i<n){
       

        for (int j = 1; j <=i ; j++)
        {
            number--;
            cout<<number;
            
           }    
        }else{
            number--;

            for (int j = 1; j <i ; j++)
            {
            number--;
            cout<<number;
            }    


        }



        cout<<endl;
        
    }}

void deci_binary(int n){

    string ans="";

    while(n!=0){

        int rem=n%2;

        ans+=to_string(rem);

        n=n/2;

    }

    reverse(ans.begin(),ans.end());

    cout<<ans;}

void deci_hex(int n){


    string ans="";

    while(n!=0){

        int rem=n%16;


        if(rem>=10){

            int val=rem-10;

            char ch='A'+val;

            ans=ch+ans;

        }else {

            ans=to_string(rem)+ans;


        }

        n=n/16;


    }

    cout<<ans;}

void binary_deci(int n){

    int multiplier=1;
    int ans=0;

    while(n!=0){

    int rem=n%10;

    int val=rem*multiplier;

    ans+=val;

    multiplier*=2;

    n=n/10;
    
    }

    cout<<ans;}

void octal_to_deci(int n){

    int ans=0;

    int multiplier=1;

    while(n!=0){

        int rem=n%10;

        ans+=rem*multiplier;

        multiplier*=8;

        n=n/10;


    }

    cout<<ans;}

int lcm(int num1,int num2){

    if(num1<0 || num2 <0) return 0;

    // 52=13x4
    // 60=15x4

    // gcd=4
    // lcm=num1*num2/gcd

    return (num1*num2)/gcds(num1,num2);}

int factorial(int n){

    if(n==0 || n==1) return 1;

    return n*factorial(n-1);}

int npr(int n,int r){

    return factorial(n)/factorial(n-r);}

int ncr(int n,int r){

    return npr(n,r)/(factorial(r)*factorial(n-r));}

void series(int a,int r,int d,int n){

    int Anth=a+(n-1)*d;

    int Gnth=a*pow(r,n-1);

    int AGP=Anth*Gnth/a;

    int SAP=0,SGP=0,SAGP=0;

    int l=1;


    while(l<=n){

        int p=a+(l-1)*d;

        SAP+=p;


        int q=a*pow(r,l-1);

        SGP+=q;

        int final=p*q;


        SAGP+=final;

        l++;;


    }


    cout<<"Anth->"<<Anth<<"\n"<<"Gnth=>"<<Gnth<<"\n"<<"AGP->"<<AGP<<"\n"<<"SAP->"<<SAP<<"\n"<<"SGP->"<<SGP<<"\n"<<"SAGP->"<<SAGP/a<<"\n"; }

bool armstrong(int n){

    int sum=0,digits=0;

    int val=n;

    while(val){

        digits++;
        val=val/10;

    }

    int number=n;

    while(number){

        int rem=number%10;

        int saved=pow(rem,digits);

        sum+=saved;

        number=number/10;

    }

    if(sum==n)return true;

    return false;}

void armstrong_range(int s,int e){

    for(int i=s;i<=e;i++){

        bool isArmStrong=armstrong(i);

        if(isArmStrong) cout<<i<<" ";

    }}    

void rotate_number(long long number,int n){

    int digits=0;
    long long val=number;

    if(n>number){
        n=n%number;
    }
    
    long long final_answer=0; 

    while(val){
        digits++;
        val/=10;
    }

    long long part2=number % (long long)pow(10,digits-n);

    long long part1=(number-part2)/(long long)pow(10,digits-n);

    final_answer=part2*(int)pow(10,n)+part1;

    cout<<final_answer;}

bool is_mirror_inverse(int arr1[],int arr2[],int n){
    
    for (int i = 0; i < n; ++i)
        if(arr1[i]!=arr2[i]) return false;
    
    return true;   }

void mirror_inverse(int arr[],int n){

    int arr2[n];

    for (int i = 0; i <n; ++i)arr2[arr[i]]=i;

    for (int i = 0; i < n; ++i)cout<<arr2[i]<<" ";
    
    cout<<endl;
    
    bool ans =is_mirror_inverse(arr,arr2,n);
    
    cout<<boolalpha<<ans;}

void XOR(int n){
    int ans=0;

    for (int i = 1; i <= n; ++i) ans=ans^i;

    cout<<ans;}

void arrays_intersection(int arr1[],int arr2[],int n1,int n2){

    unordered_map<int,int> map;


    for (int i = 0; i < n1; ++i)
    {
        map[arr1[i]]++;
    }



    sort(arr2,arr2+n2);

    for (int i = 0; i < n2; ++i)
    {
        if(map.find(arr2[i])==map.end()){

            cout<<arr2[i]<<" ";

        }
    }}

void bubbleSort(int arr[],int n){

/*

Previous version

4 1 2 1 2 3 1 
1 4 2 1 2 3 1 
1 2 4 1 2 3 1 
1 1 2 4 2 3 1 
1 1 2 2 4 3 1 
1 1 2 2 3 4 1 
1 1 1 2 2 3 4 
1 1 1 2 2 3 4 [Finished in 1.8s]


1 2 1 2 3 1 4 
1 1 2 2 1 3 4 
1 1 2 1 2 3 4 
1 1 1 2 2 3 4 
1 1 1 2 2 3 4 
1 1 1 2 2 3 4 
1 1 1 2 2 3 4 [Finished in 1.1s]


*/

    int i,j;

    for ( i = 0; i < n-1; ++i)
    {

        for ( j = 0; j < n-i-1; ++j)
        {

            if(arr[j]>arr[j+1]){

                 int temp=arr[j];

                arr[j]=arr[j+1];

                arr[j+1]=temp;

            }

        }

         for (int i = 0; i < n; ++i)
        {
            cout<<arr[i]<<" ";
        }

        cout<<endl;

    }

     for (int i = 0; i < n; ++i)
        {
            cout<<arr[i]<<" ";
        }
        

}


int main(int argc, char const *argv[])
{
    // cout<<isPrime(5);

    // cout<<true;

    // primeTillN(12);

    // reverse_number(23444);

    //cout<<gcds(20,45);

    // fibonacci(10);

    // fibonacciTillN(96);

    // p1(5);

    // p2(5);

    // p3(23);

    // p4(5);

    // p5(4);

    //  p6(4);
    
    // p7(5);

    // p8(4);

    //  p9(7);
    
    // p10(4);

    // deci_binary(80);

    // cout<<endl;

    // binary_to_deci(1010000);

    // char ch='A'+0;

    // cout<<ch;

    // deci_hex(16);

    // octal_to_deci(1567);

    // cout<<lcm(17,15);

    // cout<<factorial(8)<<"\n"<<npr(7,5)<<"\n"<<ncr(7,5)<<"\n";

    // series(10,2,5,5);

     // armstrong_range(103,999);

    // rotate_number(867359869785769756,3);

    // int arr[]={1,2,3,0};

    // mirror_inverse(arr,4);

    // digits_count(66666666,6);

    // XOR(10);

    int arr1[]={1,2,3,1,2,4,1};

    int arr2[]={2,1,3,1,5,2,2};


    // arrays_intersection(arr1,arr2,7,7);

    bubbleSort(arr1,7);












    return 0;
}
