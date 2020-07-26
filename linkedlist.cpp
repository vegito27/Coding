#include <iostream>
using namespace std;

class LinkedList{
	
	public :
	      class Node{
	
	public:
		int data;

		Node* next;
	}; 


	int size;
	
	Node* head;
	
	Node* tail;

	void handlewhensize0(int data){
		Node* nn=new Node();
		
		nn->data=data;

		nn->next=NULL;
		
		size=1;
		
		head=tail=nn;
	}

	int handlewhensize1(){
		int temp=head->data;
		delete head;
		head=tail=NULL;
		return temp;
	}

	Node* getNodeAt(int idx){
	
	    Node* temp=head;
	
	    for (int i = 0; i < idx; i++) temp=temp->next;
	
	    return temp;

	}

	void  reverse(Node* node){

		if(node==NULL) return ;

		reverse(node->next);

		cout<<node->data<<" ";

	}

	void display(){

		for (Node* temp = head; temp!=NULL  ; temp=temp->next)
		{
			cout<<temp->data<<" ";
		}
		cout<<endl;
	}


	int getsize(){

		return size;
	}

	bool isEmpty(){

		return size==0;
	}


	void addFirst(int data){

		Node* nn=new Node();

		nn->data=data;
		
		nn->next=NULL;

		nn->next=head;

		head=nn;
		
		size++;

	}

	void addLast(int data){
		if(size==0) handlewhensize0(data);
		else{
			Node* node=new Node();
			node->data=data;

			node->next=NULL;

			tail->next=node;
			tail=tail->next;
			size++;
		}
	}

	void addAt(int idx,int data){

		if(idx>size || idx<0){ return ;}

		else if(idx==0){addFirst(data);}

		else if(idx==size){ addLast(data);}

		else{

			Node* first=getNodeAt(idx-1);

			Node* second=first->next;

			Node* mid=new Node();

			mid->data=data;

			first->next=mid;
			mid->next=second;
			size++;
		}

	}

	int getFirst(){
		if(size==0) return -1;
		else return head->data;
	}

	int getLast(){
		if(size==0) return -1;
		else return tail->data;
	}

	int getAt(int idx){
		if(idx<0 || idx> size) return -1;
		else{

			Node* node=getNodeAt(idx);
			return node->data;
		}
	}


	int removeFirst(){

		if(size==0) return -1;

		else if(size==1) return handlewhensize1();

		else{
			Node* first=head;
			
			head=head->next;
			
			int data=first->data;

			delete first;
			
			size--;

			return data; 
		}
	
	}

	int removeLast(){
		if(size==0) return -1;
		else if(size==1) return handlewhensize1();
		else{
			Node* secondlast=getNodeAt(size-1);

			Node* last=secondlast->next;

			secondlast->next=NULL;
			tail=secondlast;
			int data=last->data;
			size--;
			delete last;

			return data;
		}
	}

	int removeAt(int idx){

		if(idx>size || idx<0) return -1;

		else if(size==1) return removeFirst();

		else if(idx==size-1) return removeLast();

		else{
			Node* previous=getNodeAt(idx-1);
			Node* mid=previous->next;

			Node* next=mid->next;

			previous->next=next->next;
			int data=mid->data;
			mid->next=NULL;
			delete mid;
			size--;
			return data;

		}

	}

	Node* midNode(Node* node){
		Node* slow=node;
		Node* fast=node;

		while(fast!=NULL and slow!=NULL){
			slow=slow->next;
			fast=fast->next->next;
		}
		return slow;
	}

	int midElement(){
		Node* nn=midNode(head);
		return nn->data;
	}

public:
	LinkedList(){

	head=NULL;
	tail=NULL;
	
	size=0;



	}

	~LinkedList(){

		Node* t=head;
		while(t!=NULL){
			Node* t1=t;
			t=t->next;
			delete t;

		}
	}

	void reversePointerRecursivelyUtil(Node* node){
		if(node->next ==NULL ) return ;
		
		reversePointerRecursivelyUtil(node->next);

		node->next->next=node;

		//node->next->next   isme ye hai ki jab stack base case par pahunch jayega tab ek step niche ake girega jo niche wala node hoga 
		//wo upar wale ko point kar rha hoga or upar wala next ko jo ki null hai.Ab usi null ko point karwana hai jahan mai gira hoon 
		//jispe mai gira hoon usko null kar doonga 

	}

	void reversePointerRecursively(){
        
		reversePointerRecursivelyUtil(head);
		
		Node* temp=head;
		
		head=tail;
		
		tail=temp;

		tail->next=NULL;


	}
	void reversePointerIteratively(){

		Node* previous=NULL;
		Node* current=head;
		Node* next=current->next;

		while(current!=NULL){

			current->next=previous;
			previous=current;
			current=next;
			if(next!=NULL)next=next->next;

		}

		Node* temp=head;
		head=tail;
		tail=temp;
	}




	// void reverseDataRecursivelyUtil(Node** left,Node* right,int floor){


	// 	if(right==NULL) return ;

	// 	reverseDataRecursivelyUtil(left,right,floor+1);

	// 	if(floor>=size/2){
              
 //             Node* rleft= *left;

	// 		int temp = rleft->data;

	// 		rleft->data = right->data;
			
	// 		right->data = temp;

	// 		*left=rleft->next;
	// 	}
	// }

	// void reverseDataRecursively(){
	// 	Node* left=head;

	// 	Node* right=head;
		
	// 	reverseDataRecursivelyUtil(&left,right,0);
	// }

	void reverseDataIteratively(){
		int low=0;
		int high=size-1;

		while(low<=high){
			Node* left=getNodeAt(low);
			Node* right=getNodeAt(high);

			int temp=left->data;
			left->data=right->data;
			right->data=temp;
			
			low++;
			high--;
		 
		 }
	}


	bool isPalindromeUtil(Node** left,Node* right){

		if(right==NULL) return 0;

		bool rr=isPalindromeUtil(left,right->next);
		bool mr=(rr==true) && ((*left)->data==right->data);

		*left=(*left)->next;

		return mr;
	}

	bool isPalindrome(){
		Node* left=head;
		Node* right=head;
		return isPalindromeUtil(&left,right);
	}


	void fold(Node** left,Node* right,int floor){

		if(right==NULL)return ;

		fold(left,right->next,floor+1);

		if(floor>size/2){
		
			right->next=(*left)->next;
		
			(*left)->next=right;
		
			(*left)=right->next;
		
		}else if(floor==size/2){
		
			tail=right;
		
			tail->next=NULL;
		}
	}


	void fold(){
		Node* left=head;
		Node* right=head;

		fold(&left,right,0);
	}


	void unfold(Node* t1){
		if(t1->next==NULL){
			head=tail=t1;
			return;
		}
		else if(t1->next->next==NULL){
			head=t1;
			tail=t1->next;
			return;
		}

		Node* t2=t1->next;
		
		unfold(t1->next->next);

		t1->next=head;
		head=t1;

		tail->next=t2;
		tail=t2;
		tail->next=NULL;
	
	}

	void unfold(){
		unfold(head);
	}

	void clear(LinkedList* l){
		l->head=NULL;
		l->tail=NULL;
		l->size=0;

	}

	// void removeDuplicates(){

	// 	LinkedList n1;

	// 	while(this->size>0){

	// 		int temp=this->removeFirst();

	// 		if(n1.size==0 || n1.tail->data!=temp){

	// 			n1.addLast(temp);
			
	// 		}

	// 		this->head=n1.head;
	// 		this->tail=n1.tail;
	// 		this->size=n1.size;

	// 		clear(&n1);
	// 	}
	// }

	// void oddEven(){

	// 	LinkedList odd;
	// 	LinkedList even;

	// 	while(this->size>0){
	// 		int temp=this->removeFirst();

	// 		if(temp%2==0) even.addLast(temp);

	// 		else odd.addLast(temp);

	// 	}

	// 	if(odd.size==0){
		
	// 		this->head=even.head;
	// 		this->tail=even.tail;
	// 		this->size=even.size;
		
	// 	}
		
	// 	else if(even.size==0){

	// 		this->head=odd.head;
	// 		this->tail=odd.tail;
	// 		this->size=odd.size;
		
	// 	}
	// 	else{

	// 		odd.tail->next=even.head;
	// 		this->head=odd.head;
	// 		this->tail=even.tail;
	// 		this->size=odd.size+even.size;
	// 	}
	// 	clear(&odd);
	// 	clear(&even);

	// }

	// void Kreverse(int k){
	// 	LinkedList acc;

	// 	while(this->size>0){
	// 		LinkedList temp;

	// 		for (int i = 0; i <k && this->size>0 ; ++i)
	// 		{
	// 			temp.addFirst(this->removeFirst());
	// 		}

	// 		if(acc.size==0) acc=temp;
	// 		else{
	// 			acc.tail->next=temp.head;
				
	// 			acc.tail=temp.tail;

	// 			acc.size+=temp.size;
	// 		}
	// 		clear(&temp);
	// 	}
	// 	this->head=acc.head;
	// 	this->tail=acc.tail;
	// 	this->size=acc.size;

	// 	acc.display();

	// 	clear(&acc);

	// }

	int KthfromLast(int k){
		Node* slow=head;
		Node* fast=head;

		for (int i = 0; i < k; i++)fast=fast->next;

			while(fast!=NULL){
				slow=slow->next;
				fast=fast->next;

			}

			return slow->data;
		}

	void mergeTwoSortedList(LinkedList& ll1,LinkedList& ll2){

		Node* n1=ll1.head;
		Node* n2=ll2.head;

		while(n1!=NULL &&  n2!=NULL){

			if(n1->data < n2->data){
				this->addLast(n1->data);
				n1=n1->next;
			}else{
				this->addLast(n2->next);
				n2=n2->next;
			}
		}

		while(n1!=NULL){
			this->addLast(n1->data);
			n1=n1->next;
		}

		while(n2!=NULL){
			this->addLast(n2->data);
			n2=n2->next;
		}
	}	

	LinkedList* mergeSort(Node* start,Node* end){
		if(start==end){

			LinkedList* br=new LinkedList();
			br->addLast(sp->data);
			return br;
        }
        Node* mid=midNode(sp,ep);

        LinkedList* first_half=mergeSort(start,mid);
        LinkedList* second_half=mergeSort(mid->next,end);

        LinkedList* mr=new LinkedList();

        mr->mergeTwoSortedList(*first_half,*second_half);

        delete first_half;
        delete second_half;

        return mr;

	}

	LinkedList* mergeSort(){
		LinkedList* res=mergeSort(this->head,this->tail);

		return res;
	
	}












};

int main(){

	LinkedList ll;

	ll.addLast(10);ll.addLast(20);ll.addLast(30);

	LinkedList ll2;

	ll2.addLast(10);ll2.addLast(20);ll2.addLast(30);


	//ll.display();
	cout<<endl;

	LinkedList ::Node* n=ll.head;

	

	ll.addAt(1,40);
	//ll.display();
	
 //    ll.display();
	// ll.reversePointerIteratively();
	// ll.display();

	// ll.reverseDataIteratively();
	// ll.display();

	// cout<<ll.isPalindrome();

//	ll.reverseDataRecursively();
	// ll.display();
	// cout<<endl;

	// ll.fold();
	// ll.display();
	// cout<<endl;

	//ll.unfold();

	

	//ll.removeDuplicates();

	//ll.display();

	//ll.oddEven();
	// ll.display();

	// ll.Kreverse(3);
	
	 ll.display();

	//cout<<ll.KthfromLast(3)<<endl;

	 cout<<endl;

	 mergeTwoSortedList(ll,ll2);

	 ll.display();


	



	
return 0;
}
















