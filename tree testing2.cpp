#include <iostream>
using namespace std;
class node{
public:
	int data ;
	node* left;
	node* right;
};
node* root=NULL;
//
node* insert(node* root,int key){
   
	 if (root==NULL) {
		node* temp=new node();
		temp->data=key;
		temp->left=NULL;
		temp->right=NULL;
		return temp;
	    }else if (key<root->data){
	    	root->left=insert(root->left,key);
		}else {
	    	root->right=insert(root->right,key);
		}
    
}
//
void inorder(node* node){
	if(node==NULL){
		return;
	}
	inorder(node->left);
	cout<<node->data<<" ";
	inorder(node->right);
}

void preorder(node* node){
	if(node==NULL){
		return;
	}
	cout<<"preorder: \t"<<node->data<<" ";
	inorder(node->left);
	//cout<<node->data<<" ";
	inorder(node->right);
}

void min(node* root){
	node*	temp=root;
	if(root==NULL){
	    cout<<"empty tree\n";
		return ;
	}
	while(temp->left!=NULL){
		temp=temp->left;
	}
	cout<<"\nmin: \t"<<temp->data;
	return;
}

//recursse 
void max(node* root){
	if(root==NULL){
		cout<<" empty tree"<<endl;
		return ;
	}
	else if(root->right==NULL){
		cout<<"\nmax: \t"<<root->data;
		return;
	}
	else max(root->right);
}

int main(){
	int n,key;
	cout<<"enteer no of nodes: ";
	cin>>n;
	while(n--){
		cout<<"\nNODE->DATA: ";
		cin>>key;
		root=insert(root,key);
	}
	cout<<"inorder:\t";
	inorder(root);
	cout<<"\n";
	preorder(root);
	min(root);
	max(root);
}



