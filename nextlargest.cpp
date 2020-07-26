#include <iostream>
#include<stack>

using namespace std;
/*
1) Push the first element to stack.
2) Pick rest of the elements one by one and follow the following steps in loop.
….a) Mark the current element as next.
….b) If stack is not empty, then pop an element from stack and compare it with next.
….c) If next is greater than the popped element, then next is the next greater element for the popped element.
….d) Keep popping from the stack while the popped element is smaller than next.next becomes the next greater element for all such popped elements
….e) Finally, push the next in the stack.
3) After the loop in step 2 is over, pop all the elements from stack and print -1 as next element for them.
*/

void nextLargest(int arr[],int size){

    stack<int> stc;

    int max_so_far=arr[size-1];

    stc.push(arr[0]);

    for(int i=i;i<size;i++){

        int next=arr[i];

        int val=stc.top();

        stc.pop();

        if(next>val){
            cout<<next<<" ";
        }
    }
}

int main(){



    return 0; 
}
