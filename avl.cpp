#include<iostream>
#include<vector>
#include<string>
using namespace std;

class AVLTree{

class Node
{
public:
	Node* left;
	Node* right;
	int data;
	int height;
	int balancefactor;

};

public :
Node* root;
int size;


AVLTree(vector<int> arr){
	this->root=construct(arr,0,arr.size()-1);
}


Node* construct(vector<int> arr,int low,int high){

	if(low>high) return NULL;

	int mid=low+(high-low)/2;

	Node* root;
	
	this->size++;

	root->data=arr[mid];

	construct(arr,0,mid-1);
	construct(arr,mid+1,high);

	return root;
}

int height(Node* root){
	if(root==NULL) return -1;

	int lh=-1;
	
	int rh=-1;

	if(root->left!=NULL) lh=root->left->height;

	if(root->right!=NULL) rh=root->right->height;

	return max(lh,rh)+1;
}

int balancefactor(Node* root){ 

	return height(root->left)-height(root->right);
}


void display(){
	display(this->root);
}


void display(Node* root){

	if(root==NULL) return;

	string str=root->left!=NULL ? to_string(root->left->data)+"<=":".<=";

	str+=to_string(root->data)+"["+to_string(root->balancefactor)+" "+to_string(root->height)+"";

	str+=root->right!=NULL ? to_string(root->right->data) + "" : "=>.";

	cout<<str;

	display(root->left);
	display(root->right);

}
};






int main(int argc, char const *argv[])
{

	std::vector<int> v={12,25,37,50,62,75,87};
	
	AVLTree* avl=new AVLTree(v);

	avl->display();


	
	return 0;
}