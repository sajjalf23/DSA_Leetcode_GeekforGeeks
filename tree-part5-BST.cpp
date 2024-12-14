#include<iostream>
#include<queue>
#include<stack>
#include<algorithm>
#include<vector>
using namespace std;                              //BINARY SEARCH TREE


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



Node* basic_insert(Node* root,int val){   // https://leetcode.com/problems/insert-into-a-binary-search-tree/
    if(!root){
        root = new Node(val);
        return root;
    }
    if(root->data > val){
        root->left = basic_insert(root->left,val);
    }
    else{
        root->right = basic_insert(root->right,val);
    }
    return root;
}



bool search(Node* root,int v){    // basic
    if(!root)  return 0;
    if(root->data == v){  // If we've found the node with the value
        return 1;
    }
    if(root->data <v){
        return search(root->left,v); // Search in the left subtree if value is smaller
    }
    else
        return search(root->right,v);  // Search in the right subtree if value is greater
}




Node* searchBST(Node* root, int val) {      // https://leetcode.com/problems/search-in-a-binary-search-tree/
    if (!root) 
        return NULL;      // Base case: if the tree is empty or we've reached a leaf node
    if (root->data == val) 
        return root;   // If we've found the node with the value
    if (root->data < val) {
        root = searchBST(root->right, val);  // Search in the right subtree if value is greater
    } 
    else {
        root = searchBST(root->left, val);   // Search in the left subtree if value is smaller
    }
    return root;  // Return the result of the search
}




bool helper(Node* root,long long min,long long max){  // https://leetcode.com/problems/validate-binary-search-tree
        if(!root) return 1;
        if(root->data <= min || root->data >=max){
            return 0;
        }
        return helper(root->left , min , root->data) && helper(root->right , root->data , max);
    }
bool isValidBST(Node* root) {
    //return helper(root,LLONG_MIN , LLONG_MAX);
}




void inorder(Node* root){
    if(!root)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}




Node* deleteNode(Node* root, int key) {   // https://leetcode.com/problems/delete-node-in-a-bst/
    if(!root )  
        return NULL;
    if(root->data < key){
        root->right = deleteNode(root->right,key);
        return root; 
    }    
    else if(root->data > key){
        root->left = deleteNode(root->left,key);
        return root;
    }
    else{
        if(!root->left && ! root->right){
            delete root;
            return NULL;
        }
        else if(!root->left){
            Node* t = root->right;
            delete root;
            return t;
        }
        else if(!root->right){
            Node* t = root->left;
            delete root;
            return t;
        }
        else{
            Node* p = root;
            Node* c = root->left;
            while(c->right){
                p = c;
                c = c->right;
            }
            if(p != root){
                p->right = c->left;
                c->right = root->right;
                c->left = root->left;
                delete root;
                return c;
            }
            else{
                c->right = root->right;
                delete root;
                return c;
            }
        }
    }
}



Node* helper1(vector<int> & a,int &index, int lower,int upper){   // https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/description/
    if(index == a.size() || a[index] < lower || a[index] > upper){
        return NULL;
    }
    Node* root = new Node(a[index++]);
    root->left = helper1(a,index,lower,root->data);
    root->right = helper1(a,index,root->data,upper);
    return root;
}
Node* constructBSTfrompreordertraversal(vector<int> preorder){
    int index=0;
    //return helper(preorder,index,INT_MIN,INT_MAX);
}




int canRepresentBST(int arr[], int N){         //https://www.geeksforgeeks.org/problems/preorder-traversal-and-bst
    stack<int> upper,lower;
    //upper.push(INT_MAX);
    //lower.push(INT_MIN);    // it is the part of code
    for(int i=0 ; i < N ; i++){
        if(arr[i]<lower.top())  return 0;
        while(arr[i]>upper.top()){
            upper.pop();
            lower.pop();
        }
        int left = lower.top();
        int right = upper.top();
        upper.pop();
        lower.pop();
        upper.push(arr[i]);
        lower.push(left);
        lower.push(arr[i]);
        upper.push(right);
    }
}


Node* lowestCommonAncestor(Node* root, Node* p, Node* q) {        //https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/description/
    if(!root)   return NULL;
    if(root->data > p->data && root->data > q->data){
        return lowestCommonAncestor(root->left,p,q);
    }
    if(root->data < p->data && root->data < q->data){
        return lowestCommonAncestor(root->right,p,q);
    }
    else 
        return root;
}




void helper3(Node* root, vector<int>& a,int low,int hight){   // https://www.geeksforgeeks.org/problems/print-bst-elements-in-given-range
        if(!root) return;
        if(root->data < low && root->data < hight){
            helper3(root->right,a,low,hight);
        }
        else if(root->data > low && root->data > hight){
            helper3(root->left,a,low,hight);
        }
        else{
            helper3(root->left,a,low,hight);
            a.push_back(root->data);
            helper3(root->right,a,low,hight);
        }
    }
vector<int> printNearNodes(Node *root, int low, int high) {
    vector<int> a;
    helper3(root,a,low,high);
        return a;
}






bool check(Node* root,int low,int high){   // https://www.geeksforgeeks.org/problems/check-whether-bst-contains-dead-end
        if(!root)  return 0;
        if(!root->left &&!root->right){
            if(root->data - low == 1 && high - root->data == 1){
                return 1;
            }
            else
                return 0;
        }
        return check(root->left,low,root->data)||check(root->right,root->data,high);
    }
bool isDeadEnd(Node *root)
{
    //return check(root,0,INT_MAX);
}




vector <int> findCommon(Node *root1, Node *root2){  // https://www.geeksforgeeks.org/problems/print-common-nodes-in-bst
    vector<int> ans;
    stack<Node*> s1,s2;
    while(root1){
        s1.push(root1);
        root1 = root1->left;
    }
    while(root2){
        s2.push(root2);
        root2=root2->left;
    }
    while(!s1.empty() && !s2.empty()){
        if(s1.top()->data == s2.top()->data){
            ans.push_back(s1.top()->data);
            root1 = s1.top()->right;
            s1.pop();
            root2 = s2.top()->right;
            s2.pop();
        }
        else if(s1.top()->data > s2.top()->data){
            root2 = s2.top()->right;
            s2.pop();
        }
        else if(s1.top()->data < s2.top()->data){
            root1 = s1.top()->right;
            s1.pop();
        }
        while(root1){
           s1.push(root1);
           root1 = root1->left;
        }
        while(root2){
           s2.push(root2);
           root2=root2->left;
        }
    }
    return ans;
}



void io(vector<int>& ans,Node* r){
        if(!r) 
              return;
        io(ans,r->left);
        ans.push_back(r->data);
        io(ans,r->right);
    }
vector<int> merge(Node *root1, Node *root2) {   //https://www.geeksforgeeks.org/problems/merge-two-bst-s
        vector<int> ans1,ans2;
        io(ans1,root1);
        io(ans2,root2);
        int i=0,j=0;
        vector<int> ans;
        while(i<ans1.size() && j<ans2.size()){
            if(ans1[i]<ans2[j])
                ans.push_back(ans1[i++]);
            else
            ans.push_back(ans2[j++]);
        }
        while(i<ans1.size()){
            ans.push_back(ans1[i++]);
        }
        while(j<ans2.size()){
            ans.push_back(ans2[j++]);
        }
        return ans;
        
}






class boxx{      // https://leetcode.com/problems/maximum-sum-bst-in-binary-tree/
    public:
    int sum;
    bool bst;
    int min,max;
    boxx(){
       sum = 0;
       bst = 1;
       min = 0;//INT_MAX;
       max = 0;//INT_MIN;
    }
 };
boxx* fun3(Node* root, int &tsum){
        if(!root) return new boxx;
        boxx* righth=fun3(root->right,tsum);
        boxx* lefth = fun3(root->left,tsum);
        if(righth->bst && lefth->bst && lefth->max < root->data && righth->min > root->data){
            boxx* head = new boxx;
            head->sum = righth->sum + lefth->sum + root->data;
            tsum=max(tsum,head->sum);
            head->min=min(root->data,lefth->min);
            head->max = max(root->data,righth->max);
            return head;
        }
        else{
             boxx* head = new boxx;
             head->bst = 0;
             return head;
        }
    }
int maxSumBST(Node* root) {
        int tsum =0;
        fun3(root,tsum);
        return tsum;
}






class box{
    public:
    int size;
    bool bst;
    int min;
    int max;
    box(){
        bst=1;
        size=0;
        //min=INT_MAX;
        //max=INT_MIN;
    }
};
box* fun(Node* root,int& tsize){
        if (!root) 
          return  new box;
            box* lefth = fun(root->left, tsize);
            box* righth = fun(root->right, tsize);
            if(lefth->bst && righth->bst && lefth->max < root->data && righth->min > root->data){
                box* head = new box;
                head->min = min(lefth->min,root->data);
                head->max = max(righth->max,root->data);
                head->bst= 1;
                head->size =lefth->size + righth->size + 1;
                tsize = max(tsize,head->size);
                return head;
            }
            else{
                box* a =new box;
                a->bst =0;
                a->size=0;
                return a;
            }
    }
int largestBst(Node *root)  //https://www.geeksforgeeks.org/problems/largest-bst
    {
    	int tsize = 0;
    	fun(root,tsize);
    	return tsize;
}





int main(){
    int arr[9]={7,9,5,2,3,4,1,8,97};
    Node* root=NULL;
    for(int i=0 ; i < 9 ;i++){
        root = basic_insert(root,arr[i]);
    }
    inorder(root);
}

