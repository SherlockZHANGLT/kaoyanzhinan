#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

struct TreeNode{
    char data;
    TreeNode* leftChild;
    TreeNode* rightChild;
    TreeNode(char c): data(c), leftChild(NULL), rightChild(NULL){}
};

TreeNode* Build(int& position, string str){
    char c=str[position++];
    if(c=='#') return NULL;
    TreeNode* root=new TreeNode(c);
    root->leftChild=Build(position, str);
    root->rightChild=Build(position,str);
    return root;
}

void InOrder(TreeNode* root){
    if(root==NULL) return;
    InOrder(root->leftChild);
    printf("%c ", root->data);
    InOrder(root->rightChild);
    return;
}

int main(){
    string str;
    while(getline(cin, str)){
        int position=0;
        TreeNode* root=Build(position, str);
        InOrder(root);
        printf("\n");
    }
    return 0;
}