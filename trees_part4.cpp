#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>
#include<math.h>
#include<utility>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};





void g(TreeNode*  a,vector<long long> &b,long long ans){
        if(!a) return;
        ans = ans*10 + a->val;
        if(!a->left && !a->right){
            b.push_back(ans);
        }
        g(a->left,b,ans);
        g(a->right,b,ans);
}
long long bin_to_d(long long a){
        long long ans = 0;
        long long s= 1;
        while(a){
           ans += (a%10)*s;
           s*=2;
           a = a/10;
        }
        return ans;
}
int sumRootToLeaf(TreeNode* root) {  // not an optimized code (optimized code is given below) but good for understanding
    if(!root) return 0;       // https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/
    vector<long long> dummy;
    g(root,dummy,0);
    long long s=0;
    for(int i = 0 ; i <dummy.size();i++){
        s+=bin_to_d(dummy[i]);
    }
    return s;
}





void g(TreeNode*  a,long long &b,long long dummy){  // optimized version is here
        if(!a) return;         
        dummy = (dummy <<1) | a->val;    // This BITWISE OR operation (| a->val;) sets the least significant bit  of the new value.
        if(!a->left && !a->right){     // (dummy <<1)  convert to decimal  // multiplies the current value by 2 in decimal.
            b+=dummy;                 // do chat gpt and have more details about <<(leftshift) and | (OR)operators
        }
        g(a->left,b,dummy);
        g(a->right,b,dummy);
}
int sumRootToLeaf(TreeNode* root) {
    if(!root) return 0;
    long long s=0;
    g(root,s,0);
    return s;
}





void helper(vector<vector<int>>& a,vector<int> b,TreeNode* root){
        if(!root)   return;
        b.push_back(root->val);
        if(!root->left && !root->right){
            a.push_back(b);
        }
        else{
        helper(a,b,root->left);
        helper(a,b,root->right);
        }
}
vector<string> binaryTreePaths(TreeNode* root) {   // good for understanding but memory used can be improved (//  (optimized code is given below) )
    vector<string> ans;                 // https://leetcode.com/problems/binary-tree-paths/
    if(!root)  return ans;
    vector<int> b;
    vector<vector<int>> a;
    helper(a,b,root);
    for(int i = 0 ; i <a.size();i++){
        string s="";
        s+=to_string(a[i][0]);
        for(int j= 1 ; j < a[i].size();j++){
            s+="->";
            s+=to_string(a[i][j]);
        }
        ans.push_back(s);
    }
    return ans;
}





void helper(vector<string>& a,vector<int> b,TreeNode* root){
        if(!root)   return;
        b.push_back(root->val);
        if(!root->left && !root->right){
            string s="";
            s+=to_string(b[0]);
            for(int j= 1 ; j < b.size();j++){
                s+="->";
                s+=to_string(b[j]);
            }
            a.push_back(s);
        }
        else{
        helper(a,b,root->left);
        helper(a,b,root->right);
        }
    }
vector<string> binaryTreePaths(TreeNode* root) {  // optimized version is here
        vector<string> ans;
        if(!root)  return ans;
        vector<int> b;
        helper(ans,b,root);
    return ans;
}





pair<int,int> h(TreeNode* root,int &n){ // https://leetcode.com/problems/count-nodes-equal-to-average-of-subtree
        if (root == nullptr) return {0,0};
        auto[ln,ls] = h(root->left,n); // #include<utility>
        auto[rn,rs] = h(root->right,n); // https://leetcode.com/problems/count-nodes-equal-to-average-of-subtree/solutions/5687809/cpp-solution-explained-dry-run/
        int sum = ls + rs + root->val;
        int t = ln + rn + 1;
        int average = sum / t;
        if(average==root->val){
            n++;
        }
        return {t,sum};
    }
int averageOfSubtree(TreeNode* root) {
        if(!root)  return 0;
        int n= 0;
        h(root,n); 
        return n;
}


int main(){

}