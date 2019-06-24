
void preorder(Node *root,vector<int> &A) {
    if(root==NULL)
     return;
    A.push_back(root->data);
    preorder(root->left,A);
    preorder(root->right,A);
}
void inorder(Node *root,vector<int> &A) {
    if(root==NULL)
     return;
    inorder(root->left,A);
    A.push_back(root->data);
    inorder(root->right,A);
}
Node* help(vector<int>& preorder, int pstart, vector<int>& inorder, int istart, int iend){
    if(istart>iend)
        return NULL;
    Node* root = newNode(preorder[pstart]);
    int k;
    for(int i=istart; i<=iend; i++){
        if(inorder[i] == root->data){
            k = i;
            break;
        }
    }
    root->left = help(preorder, pstart+1, inorder, istart, k-1);
    root->right = help(preorder, pstart+k-istart+1, inorder, k+1, iend);
    return root;
}

Node* binaryTree(vector<int>& preorder, vector<int>& inorder) {
    return help(preorder, 0, inorder, 0, inorder.size()-1);
}
void serialize(Node *root,vector<int> &A) {
    preorder(root,A);
    A.push_back(INT_MIN);
    inorder(root,A);
}
Node *deSerialize(vector<int> &A){
    vector<int> pre,in;
    int i,f=0;
    for(i=0;i<A.size();i++){
        if(A[i]==INT_MIN){
            f = 1;
            continue;
        }
        if(f == 0)
          pre.push_back(A[i]);
        else 
          in.push_back(A[i]);
    }
    Node *root = binaryTree(pre,in);
    return root;
}
