// Given the binary Tree of and two-node values. Check whether the two-node values are cousins of each other or not.
bool isCousins(Node* root, int x, int y) {
  queue<Node*> q, q1;
  bool cousin = false;
  bool siblings = false;
  q.push(root);
  while (!q.empty() && !cousin) {
    while (!q.empty()) {
      auto n = q.front();
      q.pop();
      if (n == nullptr) siblings = false;
      else {
        if (n->data == x || n->data == y) {
          if (!cousin) cousin = siblings = true;
          else return !siblings;
        }
        q1.push(n->left), q1.push(n->right), q1.push(nullptr);
      }
    }
    swap(q, q1);
  }
  return false;
}
------------------------------------------------------------------------------------------
int level(Node* root, int a, int h){
    if(!root)return 0;
    if(root->data==a) return h;
    int l=level(root->left, a, h+1);
    if(l!=0){
        return l;
    }
    l=level(root->right,a,h+1);
    return l;
}
bool issibling(Node*root, int a, int b){
    if(!root || !a || !b)return false;
    return ((root->left->data==a && root->right->data==b)||(root->left->data==b && root->right->data==a)||issibling(root->left, a,b) || issibling(root->right,a,b));
}
// Returns true if the nodes with values 'a' and 'b' are cousins. Else returns false
bool isCousins(Node *root, int a, int b)
{
   //add code here.
   if(!root || !a || !b)return false;
   int h1=1, h2=1;
   h1=level(root, a, h1);
   h2=level(root, b, h2);
//   cout<<h1 <<h2;
   if(h1!=h2)return false;
   return !issibling(root, a,b);
   
}