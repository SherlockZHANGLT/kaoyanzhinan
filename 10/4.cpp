#include <iostream>
#include <cstdio>
using namespace std;

struct TreeNode{
    int data;
    TreeNode* leftChild;
    TreeNode* rightChild;
    TreeNode(int x): data(x), leftChild(NULL), rightChild(NULL){}
};

TreeNode* Insert(TreeNode* root, int x){
    if(root==NULL) root=new TreeNode(x);
    else if(x<root->data) root->leftChild=Insert(root->leftChild, x);
    else root->rightChild=Insert(root->rightChild, x);
    return root;
}

void PreOrder(TreeNode* root){
    if(root==NULL) return;
    printf("%d ", root->data);
    PreOrder(root->leftChild);
    PreOrder(root->rightChild);
    return;
}

void InOrder(TreeNode* root){
    if(root==NULL) return;
    InOrder(root->leftChild);
    printf("%d ", root->data);
    InOrder(root->rightChild);
    return;
}

void PostOrder(TreeNode* root){
    if(root==NULL) return;
    PostOrder(root->leftChild);
    PostOrder(root->rightChild);
    printf("%d ", root->data);
    return;
}

int main(){
    int n;
    while(scanf("%d", &n) !=EOF){
        TreeNode* root=NULL;
        for(int i=0; i<n; ++i){
            int x;
            scanf("%d", &x);
            root=Insert(root, x);
        }
        PreOrder(root); cout<<endl;
        InOrder(root); cout<<endl;
        PostOrder(root); cout<<endl;
    }
    return 0;
}