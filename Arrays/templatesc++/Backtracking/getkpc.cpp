#include<iostream>
#include<vector>

using namespace std;

string codes[]={";","abc","def","ghi","jkl","mno","pqrs","tuv","wx","yz"};

vector<string> kpc(string s){
    if(s.size()==0){
        vector<string> br;
        br.push_back("");
        return br;
    }
    char ch=s[0];
    string ros=s.substr(1);

    vector<string> rr=kpc(ros);
    vector<string> mr;

    string code=codes[ch-'0'];

    for(int i=0;i<rr.size();i++){
        for (int j = 0; j < code.size(); j++)
        {
            mr.push_back(code[j]+rr[i]);
        }
    }
    return mr;
}

vector<string> gcs(int n){

    if(n==0){
        vector<string> br;
        br.push_back(" ");
        return br;

    }
    if(n<0){
        vector<string> br;
        return br;
    }

    vector<string> pfnm1=gcs(n-1);
    vector<string> pfnm2=gcs(n-2);
    vector<string> pfnm3=gcs(n-3);

    vector<string> mr;

    for(int i=0;i<pfnm1.size();i++)mr.push_back("1"+pfnm1[i]);
    
    for(int i=0;i<pfnm2.size();i++)mr.push_back("2"+pfnm2[i]);
    
    for(int i=0;i<pfnm3.size();i++)mr.push_back("3"+pfnm3[i]);
    
    return mr;

}

vector<string> gmp(int cr,int cc,int dr,int dc){
    if(cr==dr && cc==dc) {
        vector<string> bpath;
        bpath.push_back(" ");
        return bpath;
    }

    if(cr>dr || cc>dc){
        vector<string> bpath;
        return bpath;
    } 

    vector<string> hpaths=gmp(cr,cc+1,dr,dc);
    vector<string> vpaths=gmp(cr+1,cc,dr,dc);

    vector<string> mpaths;

    for(int i=0;i<hpaths.size();i++)mpaths.push_back('h'+hpaths[i]);
    
    for(int i=0;i<vpaths.size();i++)mpaths.push_back('v'+vpaths[i]);

    return mpaths;

}

//Not running
/*vector<string> gmpm(int cr,int cc,int dr,int dc){

    if(cr==dr and cc==dc){
        vector<string> bpath;
        bpath.push_back(" ");
        return bpath;
    }

    vector<string> mpath;

    for(int i=1; cc+i<= dc; i++){

        vector<string> hpath=gmpm(cr,cc+i,dr,dc);

        for(auto hpaths=hpath.begin();hpaths!=hpath.end();hpaths++){

            mpath.push_back("h"+to_string(i)+*hpaths);
        }
    }

    for (int i = 0; cr+i <= dr; i++)
    {
        vector<string> vpaths=gmpm(cr+i,cc,dr,dc);

        for(int j=0;j<vpaths.size();j++){

            mpath.push_back("v"+to_string(i)+vpaths[j]);
        }
    }

    for(int i=1; cr+i<=dr && cc+i<=dc ; i++){

        vector<string> dpaths=gmpm(cr+i,cc+i,dr,dc);

        for(int j=0;j<dpaths.size();j++){

            mpath.push_back("d"+to_string(i)+dpaths[j]);
        }
    }

    return mpath;
}
*/

void printsubsequences(string ques,string ans)
{
    if(ques.length()==0){
        cout<<ans<<" ";
        return;
    }
    char ch=ques[0];
    string roq=ques.substr(1);

    printsubsequences(roq,ans+ch);
    printsubsequences(roq,ans+'-');

}

void printkpc(string ques,string asf){

    if(ques.size()==0){
        cout<<asf<<" ";
        return;
    }
    char ch=ques[0];
    string roq=ques.substr(1);

    for(int i=0;i<codes[ch-'0'].size();i++){
        printkpc(roq,asf+codes[ch-'0'][i]);
    }


}

void printstairs(int n,string asf){
    if(n==0 ){
        cout<<asf<<endl;
        return ;
    }

    for(int s=1;s<=3 && n-s>=0 ;s++){
        printstairs(n-s,asf+to_string(s));
    }
}

void printmazes(int cr,int cc,int dr,int dc,string asf){

    if(cr==dr && cc==dc){
        cout<<asf<<endl;
        return ;
    }

    if(cr>dr ||cc>dc) return ;

    printmazes(cr+1,cc,dr,dc,asf+"h");
    printmazes(cr,cc+1,dr,dc,asf+"v");

}

int counter=0;

void printmazes2(int cr,int cc,int dr,int dc,string asf){

    if(cr==dr and cc==dc){
        cout<<"->"<<asf<<endl;
        counter++;
        return ;
    }

    for(int s=1;s<=dc-cc;s++){

        printmazes2(cr,cc+s,dr,dc,asf+" h"+to_string(s));

    }

    for (int i = 1; i <=dr-cr; i++)
    {
        printmazes2(cr+i,cc,dr,dc,asf+" v"+to_string(i));
    }

    for(int j=1;j<=dr-cr && j<=dc-cc;j++){

        printmazes2(cr+j,cc+j,dr,dc,asf+" d"+to_string(j));
    }

}
//Not working
void ffr(int cr,int cc,int dr,int dc,vector<vector<int> >& arr,string psf){

    if(cr==dr && cc==dc){
        cout<<psf<<endl;
        return ;   
    }

    if(cr<0 || cc<0 || cr>dr || cc<dc || arr[cr][cc]==1 || arr[cr][cc]==2) return ;

    arr[cr][cc]=2;

    ffr(cr-1,cc,dr,dc,arr,psf+"t");
    ffr(cr,cc-1,dr,dc,arr,psf+"l");
    ffr(cr+1,cc,dr,dc,arr,psf+"d");
    ffr(cr,cc+1,dr,dc,arr,psf+"r");

    arr[cr][cc]=0;

}

void permutation(int cq,int boxbm,string asf,int tq,int tb){

    if(cq>tq){
        cout<<asf<<endl;
        return;
    }
    for (int b = 0; b < tb; b++)
    {
        if((boxbm & (1<<b)) == 0){

            boxbm ^=(1<<b);

            permutation(cq+1,boxbm,asf+"q"+to_string(cq)+"b"+to_string(b)+"+",tq,tb);

            boxbm ^=(1<<b);

        }
    }
}

void printpermute(int cq,bool boxes[],string ans,int tq,int tb){

    if(cq>tq){
        cout<<ans<<endl;
        return;
    }

    for(int b=0;b<tb;b++){
        if(boxes[b]==false){
            boxes[b]=true;
            printpermute(cq+1,boxes,ans+"q"+to_string(cq)+"b"+to_string(b)+" ",tq,tb);
            boxes[b]=false;
        }
    }




}

void printcomb(int cb,int cq,int tb,int tq,string asf){

    if(cb==tb){
        if(cq==tq) cout<<asf<<endl;
        return;
    }

    printcomb(cb+1,cq+1,tb,tq,asf+"q"+to_string(cq)+"b"+to_string(cb)+"+");

    printcomb(cb+1,cq,tb,tq,asf);

}
//not working
vector<vector<int> >* gts(int arr[],int tar,int sp,int n){

    if(sp==n){
        vector<vector<int> >* bsets=new vector<vector<int> >();

        if(tar==0){
            vector<int> br;
            bsets->push_back(br);
        }
        return bsets;
    }
    vector<vector<int> > *isets=gts(arr,tar-arr[sp],sp+1,n);
    
    vector<vector<int> > *esets=gts(arr,tar,sp+1,n);
    
    vector<vector<int> > *msets=new vector<vector<int> >(); 

    for(int i=0;i<isets->size();i++){

        (*isets)[i].push_back(arr[sp]);
        msets->push_back((*isets)[i]);
    }

    for(int i=0;i<isets->size();i++){

        msets->push_back((*esets)[i]);
    }

      delete isets;

      delete msets;

    return msets;
}
//____________________________________________________________//
void combdiv(int bm,int cq,int lqwp,string asf,int tq,int tb){
    if(cq==tq){
        cout<<asf<<endl;
        return;
    }
    for(int cb=lqwp+1;cb<tb;cb++){

        if((bm&(1<<cb))==0) bm=bm^(1<<bm);

        combdiv(bm,cq+1,cb,asf+"q"+to_string(cq)+"b"+to_string(cb)+"",tq,tb);

        bm=bm^(1<<bm);
    }
    bm|=(1<<bm);

}

void comb2n(int cb,int qpsf,int tq,int tb,string asf){

    if(cb==tb){
        if(qpsf==tq) cout<<asf<<endl;
        return;
    }

    comb2n(cb+1,qpsf+1,tq,tb,asf+"q"+to_string(qpsf)+"b"+to_string(cb)+" ");
    comb2n(cb+1,qpsf,tq,tb,asf);
}

vector<vector<int> >* tarsum(int arr[],int tar,int sp,int n){

    if(sp==n){
        vector<vector<int> >* bsets=new vector<vector<int> >();

        if(tar==0){
            vector<int> br;
            bsets->push_back(br);
        }
        return bsets;
    }
    vector<vector<int> >* isets=gts(arr,tar-arr[sp],sp+1,n);
    
    vector<vector<int> >* esets=gts(arr,tar,sp+1,n);
    
    vector<vector<int> >* msets=new vector<vector<int> >(*esets); 

    for(int i=0;i<isets->size();i++){

        (*isets)[i].push_back(arr[sp]);
        msets->push_back((*isets)[i]);
    }


      delete isets;

      delete msets;

    return msets;

}

int main(){

    // string s="682";

    // vector<string> words=kpc(s);

    // int counter=0;

    // for(int i=0;i<words.size();i++){

    //     cout<<words[i]<<" ";
    //     counter++;
    // }



    // vector<string> val=gcs(5);
    // cout<<endl;

    // for(int j=0;j<val.size();j++) cout<<val[j]<<" ";

    // cout<<endl;

    // vector<string> mazepaths=gmp(0,0,4,4);
    // cout<<mazepaths.size()<<endl;

    // for(int i=0;i<mazepaths.size();i++){
    //     cout<<mazepaths[i]<<" ";
    // }
    // cout<<endl;

    // printsubsequences("abc","");

    // cout<<endl;

    // printkpc("682","");
    // cout<<endl;

    //printstairs(5,"");

    //printmazes(0,0,4,4,"");

   // printmazes2(0,0,1,1,"");
    //cout<<counter;




   // ffr(0,0,3,3,,,);

   //permutation(0,1,"",2,4);
   

//   bool boxes[4]={false};

  // printpermute(0,boxes,"",1,4);


  //printcomb(0,0,3,2,"");

   int arr[]={1,2,3,4,5,6,7,8,9};

  vector<vector<int> >* tres=tarsum(arr,15,0,8);

  for(int i=0;i<tres->size();i++){
      for(int j=0;j<(*tres)[i].size();j++){

          cout<<(*tres)[i][j]<<" ";

      }
      cout<<endl;
 }

 //combdiv()

 comb2n(0,0,3,4,"");



}