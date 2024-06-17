vector<int> diagonal(Node *root)
{
   queue<Node*> q;
   vector<int> ans;
   q.push(root);
   while(!q.empty()){
       Node* temp  = q.front();
       q.pop();
       while(temp){
           ans.push_back(temp->data);
           if(temp->left!=NULL){
                q.push(temp->left);
           }
           temp = temp->right;
       }
   }
   return ans;
}
