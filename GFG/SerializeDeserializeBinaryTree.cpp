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
Node* helper(vector<int>& preorder,int i,int j,vector<int>& inorder,int ii,int jj)
{
   if(i >= j || ii >= j)
        return NULL;
    int mid = preorder[i];
    auto f = find(inorder.begin() + ii,inorder.begin() + jj,mid);
    int dis = f - inorder.begin() - ii;
    Node* root = newNode(mid);
    root -> left = helper(preorder,i + 1,i + 1 + dis,inorder,ii,ii + dis);
    root -> right = helper(preorder,i + 1 + dis,j,inorder,ii + dis + 1,jj);
    return root;
}
Node *binaryTree(vector<int> &preorder,vector<int> &inorder)
{
    return helper(preorder,0,preorder.size(),inorder,0,inorder.size());
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
