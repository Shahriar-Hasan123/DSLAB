#include <bits/stdc++.h>
#include<stdlib.h>
using namespace std;
#define ll long long int
#define ld long double
#define fixed(x) cout << fixed << setprecision(x)
#define endl '\n'
class BST{
    public:
        int data;
        BST *left, *right;
};
BST *newNode(int data)
{
        BST *node = (BST *)malloc(sizeof(BST));
        node->data = data;
        node->left = NULL;
        node->right = NULL;
        return node;
}
BST *insert(BST *root,int value)
{
   if(root==NULL){
       root = newNode(value);
       return root;
   }
    else if(root->data<=value)
       root->right = insert(root->right, value);
    else
       root->left = insert(root->left, value);
    return root;
}
void inOrder(BST *root)
{
  if(root==NULL)
       return;

  inOrder(root->left);
  cout << root->data << " ";
  inOrder(root->right);
}
bool searchItem(BST* root,int data)
{
  if(root==NULL)
    return false;
  if(root->data==data)
    return true;
  else
  {
    if(root->data>data)
      searchItem(root->left,data);
    else
      searchItem(root->right,data);
  }
}
BST* minValueOfNode(BST *root)
{
	BST *current=root;
	while(current&&current->left!=NULL)
		current=current->left;
	return current;

}
BST *deleteNode(BST *root,int data)
{
	if(root==NULL)
		return root;
	else if(data>root->data)
		root->right=deleteNode(root->right,data);
	else if(data<root->data)
		root->left=deleteNode(root->left,data);
	else
	{
		if(root->left==NULL)
		{
			BST *tmp=root->right;
			free(root);
			return tmp;
		}
		else if(root->right==NULL)
		{
			BST *tmp=root->left;
			free(root);
			return tmp;
		}
		BST *tmp=minValueOfNode(root->right);
		root->data=tmp->data;
		root->right=deleteNode(root->right,tmp->data);
	}
	return root;
}
void PrintTree(BST *root,int space)  //reverse of inorder
{
    if(root==NULL)
    	return;
    space=space+10;

    PrintTree(root->right,space);

    cout<<endl;
    for(int i=10;i<space;i++)
    	cout<<" ";
    cout<<root->data<<endl;

    PrintTree(root->left,space);
}
int main()
{
        BST *root = NULL;
        int a[]={15,10,30,5,10,25,20};

        //Insert an item
        for(int i=0;i<7;i++)
          root=insert(root,a[i]);
      //PrintTree................
        PrintTree(root,0);

        //Print item
        	inOrder(root);
        cout<<endl;

        //Search an item
        bool check=searchItem(root,10);
        if(check)cout<<"The item "<<10<<" is founded"<<endl;
        else cout<<"The item "<<10<<" is not founded"<<endl;

        //Delation in tree
        root=deleteNode(root,158);
        //PrintItem.......
        cout<<"After Delation: "<<endl;
        PrintTree(root,0);



        return 0; 
}
