#include<iostream>
#include<queue>
#include<stack>
#include<algorithm>
#include<vector>
using namespace std;                              //BINARY TREE


class Node{
    public:
        int data;
        Node* left;
        Node* right;
    Node(int x){
        data = x;
        left = right = NULL;
    }
};


/*
int main(){
    int root_val , right_val , left_val;                        // BINARY TREE LEVEL ORDER FORMATION
    cout << " ENTER ROOT ";
    cin >> root_val;
    queue<Node*> q;
    Node* root = new Node(root_val);
    q.push( root );
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        cout << " ENTER LEFT OF " << temp->data;
        cin >> left_val;

        if( left_val != -1){
            temp->left = new Node(left_val);
            q.push(temp->left);
        }
        
        cout << " ENTER RIGHT OF " << temp->data;
        cin >> right_val;

        if( right_val != -1){
            temp->right = new Node(right_val);
            q.push(temp->right);
        }
    }
}
*/

Node* BT(){                                       // preorder Binary tree formation
    int x;
    cin >> x;
    if( x == -1 ){
        return NULL;
    }
    Node * temp = new Node(x);
    temp->left = BT();
    temp->right = BT();
    return temp;
}


void preorder(Node * temp){            // preorder traverse
    if(temp == NULL){
        return;
    }
    cout << temp->data << " ";
    preorder(temp->left);
    preorder(temp->right);
}


void postorder(Node * temp){            // postorder traverse
    if(temp == NULL){
        return;
    }
    postorder(temp->left);
    postorder(temp->right);
    cout << temp->data << " ";
}


void inorder(Node * temp){            // inorder traverse
    if(temp == NULL){
        return;
    }
    inorder(temp->left);
    inorder(temp->right);
    cout << temp->data << " ";
}



vector<int> LO(Node* root){              // levelorderd traverse using 1D vector
    vector<int> ans;
    queue<Node*> q;
    q.push(root);
    Node* temp;
    while(!q.empty()){
        temp = q.front();
        q.pop();
        ans.push_back(temp->data);
        if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }
    }
    return ans;
}


vector<vector<int>> levelOrder(Node* root) {           //102. Binary Tree Level Order Traversal  leetcode  & using 2D vector
    vector<vector<int>> ans;
    queue<Node*> q;
    q.push(root);
    if(!root){
        return ans;
    }
    while(!q.empty()){
        int s = q.size();
        vector<int> dummy;
        for(int i = 0 ; i <s ; i++){
            Node* temp = q.front();
            q.pop();
            dummy.push_back(temp->data);
            if(temp->left)   
                q.push(temp->left);
            if(temp->right)   
                q.push(temp->right);
        }
        ans.push_back(dummy);
    }
    return ans;
}


int getSize(Node* node) {        //https://www.geeksforgeeks.org/problems/size-of-binary-tree
    queue<Node*> q;
    if(!node)   return 0;
    q.push(node);
    int count = 0;
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        count++;
        if(temp->left)   q.push(temp->left);
        if(temp->right)   q.push(temp->right);
    }
    return count;
}


int getSize( Node* node ) {        // size & easy
    if(node == NULL )   return 0;
    return 1 + getSize(node->left ) + getSize(node->right );
}


int countLeaves(Node* root)              // https://www.geeksforgeeks.org/problems/count-leaves-in-binary-tree
{
 queue<Node*> q;
    if(!root)   return 0;
    q.push(root);
    int count = 0;
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        if(temp->left)   q.push(temp->left);
        if(temp->right)   q.push(temp->right);
        if(!temp->right && !temp->left)  count++;
    }
    return count;
}




void helper(Node* root , int &count){    //helper for count leaves
    if(!root)    return;
    if(!root->left && !root->right){
       count++;
       return;
    }
    helper(root->left,count);
    helper(root->right,count);
}
int countLeaves(Node* root){       // count leaves
    int count = 0;
    helper(root ,count);
    return count;
}




int countNonLeafNodes(Node* root) {      //https://www.geeksforgeeks.org/problems/count-non-leaf-nodes-in-tree
    if(!root)  return 0;
    queue<Node*> q;
    q.push(root);
    int count = 0;
    while(!q.empty()){
        Node* temp = q.front();
        if(temp->left || temp->right)  count++;
        q.pop();
        if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }
    }
    return count;
}



void helper(Node* root , int &count){    //helper for count nonleaves (written below)
    if(!root)    return;
    if(root->left || root->right){
       count++;
    }
    helper(root->left,count);
    helper(root->right,count);
}
int countnonLeaves(Node* root){       // count nonleaves
    int count = 0;
    helper(root ,count);
    return count;
}



vector<int> findSpiral(Node *root){                // https://www.geeksforgeeks.org/problems/level-order-traversal-in-spiral-form
    stack<Node*> s1;   // R to L                  // https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/
    stack<Node*> s2; // L to R
    vector<int> ans;                 // https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/solutions/5662167/cpp-solution-two-stack/
    s1.push(root);
    while(!s1.empty() || !s2.empty()){
        while(!s1.empty()){
            Node* temp = s1.top();
            s1.pop();
            ans.push_back(temp->data);
            if(temp->left)
                s2.push(temp->left);
            if(temp->right)
                s2.push(temp->right);
        }
        while(!s2.empty()){
            Node* temp1 = s2.top();
            s2.pop();
            ans.push_back(temp1->data);
            if(temp1->right)
                s1.push(temp1->right);
            if(temp1->left)
                s1.push(temp1->left);
        }
    }
    return ans;
}


int height(struct Node* node){        //https://www.geeksforgeeks.org/problems/height-of-binary-tree/
        queue<Node*> q;
        if(!node)   return 0;
        q.push(node);
        int count = 0;
        while(!q.empty()){
            int s  = q.size();
            count++;
            for(int i = 0 ; i < s ;i++){
                Node* temp = q.front();
                q.pop();
                if(temp->left)  q.push(temp->left);
                if(temp->right)  q.push(temp->right);
            }
        }
        return count;
}


int height(struct Node* node){        //https://www.geeksforgeeks.org/problems/height-of-binary-tree/
    if(!node)   return;
    return 1 + max(height(node->left),height(node->right));
}



vector<int> largestValues(Node* root)     // https://www.geeksforgeeks.org/problems/largest-value-in-each-level
    {
    queue<Node*> q;
    vector<int> dummy;
    q.push(root);
    if(!root){
        return dummy;
    }
    while(!q.empty()){
        int s = q.size();
        int max_val = 0;
        for(int i = 0 ; i < s ; i++){
            Node* temp = q.front();
            q.pop();
            max_val = max(max_val , temp->data);
            if(temp->left)   
                q.push(temp->left);
            if(temp->right)   
                q.push(temp->right);
        }
        dummy.push_back(max_val);
    }
    return dummy; 
}




void t(Node* node ,long int & sum){    // for sum function (written below)
    if(!node)  return ;
    sum+=node->data;
    t(node->left,sum);
    t(node->right,sum);
}
long int sumBT(Node* root){      // sum   https://www.geeksforgeeks.org/problems/sum-of-binary-tree
    long int sum = 0;
    t(root,sum);  
    return sum;
}




bool issame(Node* r1, Node* r2){      // https://leetcode.com/problems/same-tree/description/
    if(!r1 && !r2){
        return 1;
    }
    if((r1 && !r2)|| (!r1 && r2)){
       return 0;
    }
    if(r1->data != r2->data){
        return 1;
    }
    return issame(r1->left,r2->left)&&issame(r1->right,r2->right);
}

          
void mirror(Node* p){               // https://www.geeksforgeeks.org/problems/mirror-tree
    if(!p)  return;
    Node* temp = p->left;
    p->right = p ->left;
    p->left = temp;
    mirror(p->left);
    mirror(p->right);
}



int helper(Node* root, bool &valid){        //helper to balanced tree function (written below)
    if( !root )  
        return 0;
    int a = helper(root->left,valid);
    int b = helper(root->right,valid);
    if(abs(a-b) > 1)  
        valid = 0;
    return 1 + max(a,b);
}
bool isBalanced(Node* root) {                   //https://leetcode.com/problems/balanced-binary-tree/
    bool valid = 1;
    return  helper(root,valid);
}





bool parent(Node* root, int x, int y){                       // helper
    if(!root)     return 0;
    if(root->left && root->right){
        if(root->left->data == x && root->right->data== y){
            return 1;
        }
        if(root->left->data == y && root->right->data== x){
            return 1;
        }
    }
    return parent(root->left,x,y) || parent(root->right,x,y);
}   
bool isCousins(Node* root, int x, int y) {               //https://leetcode.com/problems/cousins-in-binary-tree/
    queue<Node* > q;
    if(!root)  return 0;
    int l1=-1, l2=-1,level = -1;
    q.push(root);
    while(!q.empty()){
        int s= q.size();
        while(s--){
           Node* temp = q.front();
           q.pop();
           if(temp->left)
           q.push(temp->left);
           if(temp->right)
           q.push(temp->right);
           if(temp->data == x)   l1 = level;
           if(temp->data == y)   l2 = level;
        }
        level++;
        if(l1!=l2){
            return 0;
        }
        if(l1!=-1 && l2!=-1){
            break;
        }
    }
    return !parent(root,x,y);
}





int main(){

    Node* root = BT();      // preorder Binary tree formation

    // 10preorder(root);         // preorder traverse

    // postorder(root);             // postorder traverse

    
    vector<int> ans = LO(root);                      // level order traverse
    for(int i = 0 ; i < ans.size() ; i++){
        cout << ans[i] << " ";
    }
 
    return 0;
}

