#include <iostream>
#include <cstdio>
using namespace std;

struct TreeNode{
    int data;
    TreeNode* leftChild;
    TreeNode* rightChild;
    TreeNode(int x): data(x), leftChild(NULL), rightChild(NULL){}
};

TreeNode* Insert(TreeNode* root, int x, int father){
    if(root==NULL){
        root=new TreeNode(x);
        printf("%d\n", father);
    }
    else if(x<root->data) root->leftChild=Insert(root->leftChild, x, root->data);
    else root->rightChild=Insert(root->rightChild, x, root->data);
    return root;
}

int main(){
    int n;
    while(scanf("%d", &n) !=EOF){
        TreeNode* root=NULL;
        for(int i=0; i<n; ++i){
            int x;
            scanf("%d", &x);
            root=Insert(root, x, -1);
        }
    }
    return 0;
}