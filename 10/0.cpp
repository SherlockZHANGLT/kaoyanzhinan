//节点定义
struct TreeNode{
    ElementType data;
    TreeNode *leftChild;
    TreeNode *rightChild;
};

//前序遍历
void PreOrder(TreeNode* root){
    if(root==NULL) return;
    Visit(root->data);
    PreOrder(root->leftChild);
    PreOrder(root->rightChild);
    return;
}

//中序遍历
void InOrder(TreeNode* root){
    if(root==NULL) return;
    InOrder(root->leftChild);
    Visit(root->data);
    InOrder(root->rightChild);
    return;
}

//后序遍历
void PostOrder(TreeNode* root){
    if(root==NULL) return;
    PostOrder(root->leftChild);
    PostOrder(root->rightChild);
    Visit(root->data);
    return;
}

//层次遍历
void LevelOrder(TreeNode* root){
    queue<TreeNode*> myQueue;
    if(root!=NULL) myQueue.push(root);
    while(!myQueue.empty){
        TreeNode* current=myQueue.front();
        myQueue.pop();
        visit(current->data);
        if(current->leftChild!=NULL) myQueue.push(current->leftChild);
        if(current->rightChild!=NULL) myQueue.push(current->rightChild);
    }
    return;
}