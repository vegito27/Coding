#include<iostream>
#include<vector>
#include<string>
using namespace std;


class Node
{
public:
	int data;
	Node* left;
	Node* right;

public:
	Node(int data){
		this->data=data;
		left=right=NULL;
	} 
};

vector<string> ans;



void Path(Node* root,string path){


	if(root->left==NULL && root->right==NULL){
		 path +="->"+to_string(root->data);

		 ans.push_back(path);
		

		path="";

		return ;
	}

	 path +="->"+to_string(root->data);


   if(root->left!=NULL and root->right==NULL){
	
	  Path(root->left,path);
    }

    else if(root->left==NULL and root->right!=NULL){
	    Path(root->right,path);
    
    }
    else{

    Path(root->left,path);

    Path(root->right,path);

    }


}

int dia=0;

// int diameter(Node* root){

// 	if(root==NULL) return;

// 	while(root->left!=NULL and root->right!=NULL){
    
//     dia++;
	
// 	root=root->left;
    
//     }

// }



void display(Node* root){

	if(!root) return ;

	cout<<root->data<<" ";


    display(root->left);

	display(root->right);
      
}


 int rangetSumOfBST(Node* root,int L,int R){

 	if(!root) return 0;
 	



 }











int main(int argc, char const *argv[])
{

	Node* root =new Node(10);

	 root->left=new Node(5);
	 root->right=new Node(15);
	 root->left->left=new Node(3);

	 root->left->right=new Node(7);
	 root->right->right=new Node(18);

	 display(root);






	 // Path(root,"");

	 // for (int i = 0; i < ans.size(); ++i)
	 // {
	 // 	cout<<ans[i]<<" ";
	 // }
	





	
	return 0;
}