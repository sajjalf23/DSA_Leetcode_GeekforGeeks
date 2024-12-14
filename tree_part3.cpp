#include<iostream>
#include<stack>
#include<algorithm>
#include<vector>
#include<queue>
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




int find(int in[],int start,int end,int target){
    for(int i = start; i <= end ; i++){
        if(in[i] == target)
            return i;
    }
    return -1;
}
Node* build(int in[],int pre[],int start,int end,int index){
    if(start>end){
        return NULL;
    }
    Node* temp = new Node(pre[index]);
    int p = find(in,start,end,pre[index]);
    temp->left = build(in,pre,start,p-1,index+1);
    temp->right = build(in,pre,p+1,end,index+1+(p-start));
    return temp;
}                                       //// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/solutions/5667915/cpp-solution-recurssion/
Node* buildTree_pre_in(int in[],int pre[], int n){    // https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
    Node* ans = build(in,pre,0,n-1,0);          
    return ans;
}






Node* m(int in[],int post[],int start,int end, int index){  //https://www.geeksforgeeks.org/problems/tree-from-postorder-and-inorder/1
    if(start>end)   return NULL;          // https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/solutions/5668050/cpp-solution/
    Node* temp = new Node(post[index]);
    int p = find(in,start,end,post[index]);
    temp->right = m(in,post,p+1,end,index-1);
    temp->left = m(in,post,start,p-1,index-1-(end-p));
    return temp;
}
Node *buildTree_post_in(int n, int in[], int post[]) {
    return m(in,post,0,n-1,n-1);
}





void h(Node* root, int p, int& l, int& r) {
        if (!root) return;
        l = min(l, p);
        r = max(r, p);
        h(root->left, p - 1, l, r);
        h(root->right, p + 1, l, r);
    }
vector<int> verticalOrder(Node *root){    // https://www.geeksforgeeks.org/problems/print-a-binary-tree-in-vertical-order/1
    int l =0,r =0;
    h(root,0,l,r);
    vector<int> ans;
    if (!root) return ans;
    vector<vector<int>> negative(abs(l)+1);
    vector<vector<int>> positive(r+1);
    queue<Node*> q;
    q.push(root);
    queue<int> index;
    index.push(0);
    while(!q.empty()){
        
        Node* temp = q.front();
        q.pop();
        int p = index.front();
        index.pop();
        if(p<0){
            negative[abs(p)].push_back(temp->data);
        }
        else{
            positive[p].push_back(temp->data);
        }
        if(temp->left){   q.push(temp->left); index.push(p-1);}
        if(temp->right){   q.push(temp->right); index.push(p+1);}
    }
    reverse(negative.begin(),negative.end());
    for(int i = 0 ; i < negative.size();i++){
        for(int j = 0 ; j < negative[i].size();j++ ){
            ans.push_back(negative[i][j]);
        }
    }
    for(int i = 0 ; i < positive.size();i++){
        for(int j = 0 ; j < positive[i].size();j++ ){
            ans.push_back(positive[i][j]);
    }
    }
    return ans;  
}





void find_l(Node* root,int &l,int position){
    if(!root)   return;
    l = max(l,position);
    find_l(root->left,l,position+1);
    find_l(root->right,l,position);
}
void helper(vector<vector<int>> &ans, int position,Node* root){
    if(!root)  return;
    ans[position].push_back(root->data);
    helper(ans,position+1,root->left);
    helper(ans,position,root->right);
}
vector<int> diagonal(Node *root){   // https://www.geeksforgeeks.org/problems/diagonal-traversal-of-binary-tree/1
    int l = 0;
    find_l(root,l,0);
    vector<vector<int>> dummy(l+1);
    vector<int> ans;
    if(!root)  return ans;
    helper(dummy,0,root);
    for(int i = 0 ; i <dummy.size() ; i++){
        for(int j = 0 ; j<dummy[i].size();j++){
            ans.push_back(dummy[i][j]);
        }
    }
    return ans;
}   



vector<vector<int>> levelOrderBottom_2(Node* root) {  // https://leetcode.com/problems/binary-tree-level-order-traversal-ii
    vector<vector<int>> ans;    // https://leetcode.com/problems/binary-tree-level-order-traversal-ii/solutions/5672052/cpp-solution-queue/
    if(!root)   return ans;
    queue<Node*> q;
    q.push(root);
    int j = 0 ;
    while(!q.empty()){
        vector<int> dummy;
        int s = q.size();
        for(int i = 0 ; i < s; i++){
            Node* temp = q.front();
            q.pop();
            dummy.push_back(temp->data);
            if(temp->left)  q.push(temp->left);
            if(temp->right)  q.push(temp->right);
        }
        j++;
        ans.push_back(dummy);
    }
    reverse(ans.begin(),ans.end());
    return ans;
}





void find_deep_leave(Node* root, int &l,int p){
        if(!root)  return;
        l=max(l,p);
        find_deep_leave(root->left,l,p+1);
        find_deep_leave(root->right,l,p+1);
    }  
void sum_f(Node* root,int l,int p,int sum){
        if(!root)  return;
        if(!root->left && !root->right){
            if(p == l){
                sum+=root->data;
            }
        }
        sum_f(root->left,l,p+1,sum);
        sum_f(root->right,l,p+1,sum);
    }   
int deepestLeavesSum(Node* root) {//https://leetcode.com/problems/deepest-leaves-sum/
    int sum = 0; //https://leetcode.com/problems/deepest-leaves-sum/solutions/5672210/cpp-solution-recurssion/
    if(!root)  return sum;
    int l = 0;
    find_deep_leave(root,l,0);
    sum_f(root,l,0,sum);
    return sum;
}





void l(Node* root,vector<int> &ans){
        if(!root ||( !root->left && !root->right)){
            return;
        }
        ans.push_back(root->data);
        if(root->left)
        l(root->left,ans);
        else if(root->right)
        l(root->right,ans);
    }
void r(Node* root,vector<int> &b){
        if(!root ||(!root->left && !root->right)){
            return;
        }
        b.push_back(root->data);
        if(root->right)
        r(root->right,b);
        else if(root->left)
        r(root->left,b);
    }
void leaf(Node* root,vector<int> &ans){
        if(!root)  return;
        if(!root->left && !root->right){
            ans.push_back(root->data);
        }
        leaf(root->left,ans);
        leaf(root->right,ans);
    }
vector <int> boundary(Node *root){  // https://www.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1
        vector<int> ans;
        vector<int> b;
        if(!root)  return ans;
        ans.push_back(root->data);
        if(root->left)                             //         1
        l(root->left,ans);                        //        /  \                    ans = 1,2,4,5,4,5,4,3,1
        if(root->left || root->right)            //       2    3   
        leaf(root,ans);                         //       / \    \      
                                               //       4   5    4
        if(root->right)r(root->right,b);       //        \
                                                     //   5
        reverse(b.begin(), b.end());              //       \
                                                        // 4
        ans.insert(ans.end(), b.begin(), b.end());  
        return ans;
}




void flatten(Node* root) { //https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
    while(root){
        if(!root->left){
                root = root->right;
        }
        else{
            Node* curr = root->left;
                while(curr->right){
                    curr=curr->right;
                }
            curr->right = root->right;
            root->right = root->left;
            root->left = NULL;
            root = root->right;
        }
    }
}




void p(Node* root , int a , int &b){
        if(!root)
            return;
        if(root->data > a){
            if(b == -1){
                b = root->data;
            }
            if(root->data < b){
                b = root->data;
            }
        }
        p(root->left,a,b);
        p(root->right,a,b);
    }
int findSecondMinimumValue(Node* root) { // https://leetcode.com/problems/second-minimum-node-in-a-binary-tree/
        int a = root->data , b = -1;
        p(root,a,b);
        return b;
}



Node* getTargetCopy(Node* original, Node* cloned,Node* target) {  //https://leetcode.com/problems/find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree/
    if(!original)  return NULL;
        if(original == target){;
            return cloned;
        }
        Node* l = getTargetCopy(original->left,cloned->left,target);
        if(l)  return l;
        return getTargetCopy(original->right,cloned->right,target);
    }


bool evaluateTree(Node* root) {   //https://leetcode.com/problems/evaluate-boolean-binary-tree/
        if(!root) return 0; 
    bool a= evaluateTree(root->left);
    bool b = evaluateTree(root->right);
    if(root->data == 2){
       return a || b;
    } 
    else if(root->data == 3){
        return a && b;
    } 
    else
    return root->data;
}


 int minDepth(Node* root) {  // https://leetcode.com/problems/minimum-depth-of-binary-tree/
    if(!root) return 0;
    queue<Node*> q;
    int count = 0;
    bool flag = 0;
    q.push(root);
    while(!q.empty()){
        int size = q.size();
         count++;
        while(size--){
        Node* a= q.front();
        q.pop();
        if(!a->left && !a->right){
            flag = 1;
            break;
        }if(a->left)
        q.push(a->left);
        if(a->right)
        q.push(a->right);
        }
        if(flag ==1){
            return count;
        }
    }
    return count;
}



void l(vector<int> &a,Node* b){ // https://leetcode.com/problems/leaf-similar-trees/
        if(!b)  return;
        if(!b->left && !b->right)  a.push_back(b->data);
        l(a,b->left);
        l(a,b->right);
    }
bool leafSimilar(Node* root1, Node* root2) {
        if(!root1 || !root2)   return 0;
        vector<int> a,b;
        l(a,root1);
        l(b,root2);
        if(a.size()!=b.size()) return 0;
        for(int i = 0 ; i < a.size();i++){
            if(a[i] != b[i])
               return 0;
        }
    return 1;
}



Node* mergeTrees(Node* root1, Node* root2) {   // https://leetcode.com/problems/merge-two-binary-trees
    if(!root1)   return root2;
    if(!root2)    return root1;
    Node* merged = new Node(root1->data + root2->data);
    merged->left= (mergeTrees(root1->left,root2->left));
    merged->right= (mergeTrees(root1->right,root2->right));
    return merged;   
}


Node* invertTree(Node* root) {
        if(!root) return root;
       queue<Node*> q;
       q.push(root); 
       while(!q.empty()){
        int s = q.size();
        while(s--){
            Node* a = q.front();
            q.pop();
            Node* temp = a->left;
            a->left = a->right;
            a->right= temp;
            if(a->left)
            q.push(a->left);
            if(a->right)
            q.push(a->right);
        }
       }
       return root;
}

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