#include<iostream>
#include<queue>
#include<stack>
#include<algorithm>
#include<vector>
#include<math.h>
using namespace std;                              // HEAP part 2;  13 problems

struct Node {
    int data;
    Node *left, *right;
};

int heapHeight(int N, int arr[]){   // https://www.geeksforgeeks.org/problems/height-of-heap
    if(N==1) return 1; //for 2 ki power 0 is 1
          // if there is 1 element only
        int height = 0;
        while(N>1){   
            height++;
            N=N/2;
        }
    return height;
}






long long minCost(vector<long long>& arr) { //https://www.geeksforgeeks.org/problems/minimum-cost-of-ropes
        std::priority_queue<long long, std::vector<long long>, std::greater<long long>> p;
        for(long long i=0 ; i < arr.size() ;i++){
            p.push(arr[i]);
        }
        long long cost=0;
        while(p.size()>1){
            long long rope=p.top();;
            p.pop();
            rope += p.top();
            p.pop();
            cost+=rope;
            p.push(rope);
        }
    return cost;
}







long long magician_and_chocolate(std::vector<long long>& arr, int a) {
    std::priority_queue<long long> p;

    // Fill the priority queue with initial chocolate amounts
    for (long long chocolate : arr) {
        p.push(chocolate);
    }

    long long ans = 0;
    while (a > 0 && !p.empty()) {
        long long n = p.top(); // Get the largest chocolate amount
        p.pop();              // Remove it from the queue
        ans += n;            // Add it to the total

        // Push half back into the queue if it's greater than zero
        if (n > 1) {
            p.push(n / 2);
        }
        a--; // Decrement the number of operations
    }
    return ans;
}






int lastStoneWeight(vector<int>& stones) {      // https://leetcode.com/problems/last-stone-weight
    std::priority_queue<long long> p;

    for(int s:stones){
        p.push(s);
    }

    while(p.size()>1){
        int a = p.top();
        p.pop();
        int  b = p.top();
        p.pop();
        p.push(abs(a-b));
    }

    return p.top();
}






long long pickGifts(vector<int>& gifts, int k) {    //https://leetcode.com/problems/take-gifts-from-the-richest-pile/
    std::priority_queue<int> p;
    for(int i:gifts){
        p.push(i);
    }
    while(k--){
        int a = p.top();
        p.pop();
        //p.push(sqrt(a));
    }
    long long ans = 0;
    while(!p.empty()){
        ans += p.top();
        p.pop();
    }
    return ans;
}







int maximize_profit(vector<int> arr,int k) {    
    std::priority_queue<long long> p;

    for(int s:arr){
        p.push(s);
    }

    long long ans = 0;

    while(k && !p.empty()){
        int a = p.top();
        p.pop();

        if(a-1)
           p.push(a-1);
        ans += a;

        k--;
    }

    return ans;
}



int kthSmallest(vector<vector<int>>& matrix, int k) {  // https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/

    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>p ;

        for(int i=0 ; i < matrix.size() ; i++){
            p.push({matrix[i][0],{i,0}});
        }

        pair<int,pair<int,int>> element;
        int ans,i,j;
        while(k--){
            element = p.top();
            p.pop();
            ans=element.first;
            i=element.second.first;
            j=element.second.second;

            if(j+1 < matrix.size()){
                p.push({matrix[i][j+1],{i,j+1}});
            }
        }
    return ans;
}



int findKthLargest(vector<int>& nums, int k) {       // https://leetcode.com/problems/kth-largest-element-in-an-array/
    std::priority_queue<int, std::vector<int>, std::greater<int>> p;
    for(int i=0 ; i < k;i++){
        p.push(nums[i]);
    }  
    for(int i=k;i<nums.size();i++){
        if(p.top() < nums[i]){
            p.pop();
            p.push(nums[i]);
        }
    }
    return p.top();
    }





void heapify(vector<int>& a,int index, int size){
        
        int big = index;
        int left = (2*index) + 1;
        int right = (2*index) + 2;
        
        if(left < size && a[left] > a[big]){
            big = left;
        }
        
        if(right < size && a[right] > a[big]){
            big = right;
        }
        
        if(big != index){
            swap(a[index], a[big]);
            heapify(a,big,size);
        }
    }
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {    // https://www.geeksforgeeks.org/problems/merge-two-binary-max-heap
        
        vector<int> ans;
        
        for(int i=0 ; i < a.size();i++){
            ans.push_back(a[i]);
        }
        
        for(int i=0 ; i < b.size();i++){
            ans.push_back(b[i]);
        }
        
        for(int i=(ans.size()/2)-1 ; i >= 0 ; --i )
           heapify(ans,i,ans.size());
           
        return ans;
    }





    void inorder(Node* root,vector<int> & ans){
       if(!root)  return;
       inorder(root->left,ans);
       ans.push_back(root->data);
       inorder(root->right,ans);
   }
   void postorder(Node* root,vector<int> &ans,int &index){
       if(!root)  return;
       postorder(root->left,ans,index);
       postorder(root->right,ans,index);
       root->data = ans[index];
       index++;
   }
    void convertToMaxHeapUtil(Node* root)   //https://www.geeksforgeeks.org/problems/bst-to-max-heap/
    {
        int index=0;
        vector<int> ans;
        inorder(root,ans);
        postorder(root,ans,index);
        
    }    



int size(Node* root){
      if(!root) return 0;
      return 1+size(root->left)+size(root->right);
  }
   bool cbt(Node* root,int index,int size){
         if(!root)  return 1;
         if(index >= size){
             return 0;
         }
         return cbt(root->left,(2*index)+1,size) && cbt(root->right,(2*index)+2,size);
   }
   bool heap(Node* root){
       if(root->left){
           if(root->data < root->left->data){
               return 0;
           }
           else{
               if(!heap(root->left))
               return 0;
           }
       }
       if(root->right){
           if(root->data < root->right->data){
               return 0;
           }
           else{
               return heap(root->right);
           }
       }
       return 1;
   }
    bool isHeap(struct Node* tree) {    // https://www.geeksforgeeks.org/problems/is-binary-tree-heap/
        int a=size(tree);
        bool check = cbt(tree,0,a);
        if(!check){
            return 0;
        }
        return heap(tree);
    }



class KthLargest {   //https://leetcode.com/problems/kth-largest-element-in-a-stream
private:
    std::priority_queue<int, std::vector<int>, std::greater<int>> p; // Min-heap
    int k; // The number of largest elements to track

public:
    KthLargest(int k, vector<int>& nums):k(k){
        for(int i=0 ; i < nums.size() ;i++){
            add(nums[i]);
        }
    }
    
    int add(int val) {
    p.push(val);

    if(p.size() > k){
        p.pop();
    }

    return p.top();
    }
};









class MedianFinder {
private:

    std::priority_queue<int> maxHeap; 
        // max-heap for the lower half
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
         // min-heap for the upper half

public:
    MedianFinder() {   //https://leetcode.com/problems/find-median-from-data-stream/
        
    }
    
    void addNum(int num) {
        maxHeap.push(num);
        if(!minHeap.empty() && maxHeap.top() > minHeap.top()){
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }

        if(maxHeap.size() > minHeap.size()+1){
           minHeap.push(maxHeap.top());
            maxHeap.pop();
        }else if(maxHeap.size() < minHeap.size()){
           maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        if(maxHeap.size() > minHeap.size()){
            return maxHeap.top();
        }
        else{
            return (maxHeap.top()+minHeap.top())/2.0;
        }
        return -1;
    }
};






int main(){

}