#include<bits/stdc++.h>
#define COUNT 10
using namespace std;

struct Node{
	int key;
	struct Node *left,*right;
};
void print2DUtil(Node *root, int space)
{
    // Base case
    if (root == NULL)
        return;
 
    // Increase distance between levels
    space += COUNT;
 
    // Process right child first
    print2DUtil(root->right, space);
 
    // Print current node after space
    // count
    cout<<endl;
    for (int i = COUNT; i < space; i++)
        cout<<" ";
    cout<<root->key<<"\n";
 
    // Process left child
    print2DUtil(root->left, space);
}
 
// Wrapper over print2DUtil()
void print2D(Node *root)
{
    // Pass initial space count as 0
    print2DUtil(root, 0);
}
Node* newNode(int value)
{
	Node* temp=new Node;
	temp->key=value;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}
Node* search(Node* root,int target)
{
	cout<<"Inside search function call"<<endl;
	cout<<"searching started for target: "<<target<<endl;
	if(root==NULL){
		cout<<"WARNING-Cannot search in EMPTY BST TREE!";
		return root;
	}
	Node* currNode=root;
	while(true){
		int data=currNode->key;
		if(target==data){
			cout<<"Wow target found";
			return currNode;
		}
		else if(target>data){
			cout<<"Hmm target is greater than currNode key value, searching in right subtree"<<endl;
			if(currNode->right==NULL){
				cout<<"Bad luck target not found right subtree is empty"<<endl;
				return currNode;
			}
			else{
				cout<<"Moving to next right node"<<endl;
				currNode=currNode->right;
			}			
		}
		else if(target<data){
				cout<<"Hmm target is less than currNode key value, searching in left subtree"<<endl;
			if(currNode->right==NULL){
				cout<<"Bad luck target not found left subtree is empty"<<endl;
				return currNode;
			}
			else{
				cout<<"Moving to next left node"<<endl;
				currNode=currNode->left;
			}			
		}
	}
	
	
}
Node* insert(Node* root,int data)
{
	cout<<"Inside insert function call"<<endl;
	if(root==NULL)
	{
	    root=newNode(data);
		root->key=data;
		cout<<data<<" inserted as root in BST"<<endl;
	    return root;
	}
	Node* currNode=root;
	Node* prevNode=root;
	while(true)
	{
		int temp=currNode->key;
		if(data>=temp)//move right
		{
			if(currNode->right==NULL){
				Node* node=newNode(data);
			currNode->right=node;
			cout<<data<<" inserted on right subtree in BST"<<endl;
			break;
			}
			else{
				cout<<"Moving right of subtree";
				currNode=currNode->right;
			}	
		}
		else if(data<temp)//move left
		{
			if(root->left==NULL){
				Node* node=newNode(data);
			currNode->left=node;
			cout<<data<<" inserted on left subtree in BST"<<endl;
			break;
			}
			else{
				cout<<"Moving right of subtree";
				currNode=currNode->left;
			}
		}		
	}
	return root;
}

int main()
{
	Node* root=NULL;
	cout<<"inserting 10 in BST";
root=insert(root,10);
	cout<<"inserting 20 in BST";
 root=insert(root,20);
	insert(root,5);
	print2D(root);	
	search(root,50);
	search(NULL,10);
	search(root,5);
}
