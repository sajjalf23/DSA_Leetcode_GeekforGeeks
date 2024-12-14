#include<iostream>
#include<queue>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;
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


vector<int> leftView(Node *root)          // https://www.geeksforgeeks.org/problems/left-view-of-binary-tree
{
    vector<int> ans;      //levelordertraversal followed
    if(!root)    return ans;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        ans.push_back(q.front()->data);  // save the first most value of every level  
        int s = q.size();   // controls level
        while(s--){
            Node* temp = q.front();
            q.pop();
            if(temp->left)   q.push(temp->left);
            if(temp->right)   q.push(temp->right);
        } 
    }
    return ans;
}



void helper(Node* root,int level ,vector<int> & ans){   // helper of function below
    if(!root)   return;
    if(level == ans.size()){    // if ans.size() = 2; then the next value will be stored from the first most of next level 3
        ans.push_back(root->data);
    }
    helper(root->left,level+1,ans);   // left side first
    helper(root->right,level+1,ans);
}
vector<int> leftView_(Node *root)          // https://www.geeksforgeeks.org/problems/left-view-of-binary-tree
{
    vector<int> ans;
    if(!root)    return ans;
    helper(root,0,ans);
    return ans;
}



vector<int> rightSideView(Node* root) {        // https://www.geeksforgeeks.org/problems/right-view-of-binary-tree
    vector<int> ans;
    if(!root)    return ans;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        int s = q.size();  
        while(s--){
            Node* temp = q.front();
            if(s == 0){   // save the last most of a level
                ans.push_back(temp->data);
            }
            q.pop();
            if(temp->left)   q.push(temp->left);
            if(temp->right)   q.push(temp->right);
        } 
    }
    return ans; 
}


void helper_right_view(Node* root,int level ,vector<int> & ans){         // helper of function below 
    if(!root)   return;
    if(ans.size() == level){
        ans.push_back(root->data);
    }
    helper_right_view(root->right,level+1,ans);  // right side first as we have to save  the last most of a level
    helper_right_view(root->left,level+1,ans);
}
vector<int> right_view_(Node* root){       // https://leetcode.com/problems/binary-tree-right-side-view/
    vector<int> ans;
    if(!root)   return ans;
    helper(root,0,ans);
    return ans;
}





void h(Node* root,int &l, int &r,int position){     // helper of function below 
    if(!root)                return;
    l = min(l,position);     // to find the dept(height )of left side
    r = max(r,position);      // to find the dept(height )of right side
    h(root->left,l,r,position-1);
    h(root->right,l,r,position+1);
}
vector<int> topView(Node *root){       // https://www.geeksforgeeks.org/problems/top-view-of-binary-tree/
    int l = 0 , r = 0;
    h(root,l,r,0);
    vector<int> ans(r-l+1,0);
    vector<bool> filled(r-l+1,false);    // to make sure of saving the first most of a lavel
    queue<Node*>  q;
    queue<int>   index;
    if(!root)     return ans;
    q.push(root);
    index.push(-1*l);
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        int p = index.front();
        index.pop();
        if(filled[p]==0){
            filled[p] = 1;
            ans[p] = temp->data;
        }
        if(temp->left){
            q.push(temp->left);
            index.push(p-1);
        }
        if(temp->right){
            q.push(temp->right);
            index.push(p+1);
        }
    }
    return ans;
}





void h(Node* root,int &l,int &r,int position){    // helper of function below 
    if(!root)    return;
    l = min(l,position);
    r = max(r,position);
    h(root->left,l,r,position-1);
    h(root->right,l,r,position+1);
}
vector <int> bottomView(Node *root) {          // https://www.geeksforgeeks.org/problems/bottom-view-of-binary-tree
    queue<Node*> q;
    queue<int> index;
    int l = 0 , r = 0;
    h(root,l,r,0);
    vector<int> ans(r-l+1,0);
    if(!root)  
        return ans;
    q.push(root);
    index.push(-l);
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        int p = index.front();
        index.pop();
        ans[p] = temp->data;
        if(temp->left){
            q.push(temp->left);
            index.push(p-1);
        }
        if(temp->right){
            q.push(temp->right);
            index.push(p+1);
        }
    }
    return ans;
}


vector<int> preOrder(Node* root){ // https://www.geeksforgeeks.org/problems/preorder-traversal-iterative/
    vector<int> ans;
    if (root == NULL) return ans; 
    stack<Node*> s;
    s.push(root);
    while(!s.empty()){
        Node* temp = s.top();
        ans.push_back(temp->data);
        s.pop();
        if(temp->right)
        s.push(temp->right);
        if(temp->left)
        s.push(temp->left);
    }
    return ans;
}


vector<int> postOrder(Node* node) { // https://www.geeksforgeeks.org/problems/postorder-traversal-iterative
    vector<int> ans;
    if(!node)  return ans;
    stack<Node*> s;
    s.push(node);
    while(!s.empty()){
        Node* temp = s.top();
        ans.push_back(temp->data);
        s.pop();
        if(temp->left){
            s.push(temp->left);
        }
        if(temp->right){
            s.push(temp->right);
        }
    }
    reverse(ans.begin(),ans.end());
    return ans;
}


vector<int> inOrder(Node* root){      //https://www.geeksforgeeks.org/problems/inorder-traversal-iterative
    stack<Node*> s;
    stack<bool> check;
    vector<int> ans;
    if(!root)   return ans;
    s.push(root);
    check.push(0);
    while(!s.empty()){
        bool flag = check.top();
        check.pop();
        Node* temp = s.top();
        s.pop();
        if(!flag){
            if(temp->right){
                s.push(temp->right);
                check.push(0);
            }
            if(temp){
                s.push(temp);
                check.push(1);
            }
            if(temp->left){
                s.push(temp->left);
                check.push(0);
            }
        }
        if(flag){
            ans.push_back(temp->data);
        }
    }
    return ans;
}


int main(){
}