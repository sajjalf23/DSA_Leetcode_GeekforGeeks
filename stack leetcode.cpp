#include <iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;



int evaluateReversePolishNotation(vector<string>& tokens) {
    stack<int> st;
    for(int i=0;i<tokens.size();i++){
        if(tokens[i]!="+"&&tokens[i]!="*"&&tokens[i]!="/"&&tokens[i]!="-"){
            st.push(stoi(tokens[i]));
        }
        else{
            int a=st.top();
            st.pop();
            int b=st.top();
            st.pop();
            int dummy;
            if(tokens[i]=="+")
                dummy=b+a;
            else if(tokens[i]=="*")
               dummy=b*a;
            else if(tokens[i]=="/")
                dummy=b/a; 
            else
                dummy=b-a;
            st.push(dummy);
        }
    }
    return st.top();    
}


void cpystackbyrecurssion(stack<int> &st,stack<int> & ans){
    if(st.empty()){
        return;
    }
    int curr = st.top();
    st.pop();
    cpystackbyrecurssion(st,ans);
    ans.push(curr);
}


stack<int> cpystack(stack<int> &st){
    stack<int> helpingst;
    stack<int> temp;
    while(!st.empty()){
        helpingst.push(st.top());
        st.pop();
    }
    while(!helpingst.empty()){
        temp.push(helpingst.top());
        helpingst.pop();
    }
    return temp;
}


void insertatbottom(stack<int> &st , int x){
    stack<int> temp;
    while(!st.empty()){
        int curr = st.top();
        st.pop();
        temp.push(curr);
    }
    st.push(x);
    while(!temp.empty()){
        int curr = temp.top();
        temp.pop();
        st.push(curr);
    }
}


void print(stack<int> st){
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
}


void insertatbottombyrecurssion(stack<int> &st , int x){
    if(st.empty()){
        st.push(x);
        return;
    }
    int curr = st.top();
    st.pop();
    insertatbottombyrecurssion(st,x);
    st.push(curr);
}


void insertatlocation(stack<int> & st ,int x,int location){
    stack<int> temp;
    int n=st.size();
    for(int i=0 ;i<n-location;i++){
        temp.push(st.top());
        st.pop();
    }
    st.push(x);
    while(!temp.empty()){
        int curr = temp.top();
        temp.pop();
        st.push(curr);
    }
}


void deleteatbottom(stack<int> &st ){
    stack<int> temp;
    while(st.size()!=1){
        int curr = st.top();
        st.pop();
        temp.push(curr);
    }
    st.pop();
    while(!temp.empty()){
        int curr = temp.top();
        temp.pop();
        st.push(curr);
    }
}


void reverse(stack<int> &st){
    if(st.empty())
        return;
    int curr = st.top();
    st.pop();
    reverse(st);
    insertatbottom(st,curr);
}


bool balancesimplebracket(string s){
    stack<char> st;
    for(char ch : s){
        if(ch == '(')
           st.push(ch);
        else{
            if(ch == ')'){
                st.pop();
            }
            else
                return 0;
        }
    }
    return st.empty();
}


bool balancebracket(string s){
    stack<char> st;
    for(char ch : s){
        if(ch == '(' || ch == '{'|| ch == '[')
           st.push(ch);
        else{
            if(ch == ')' && !st.empty() && st.top()=='('){
                st.pop();
            }
            else if(ch == '}' && !st.empty() && st.top()=='{'){
                st.pop();
            }
            else if(ch == ']' && !st.empty() && st.top()=='['){
                st.pop();
            }
            else
                return 0;
        }
    }
    return st.empty();
}


vector<int> nextgreaterelementfromrightside(vector<int> nums) {
    vector<int> ans(nums.size(), -1);
    stack<int> st;

    for (int i = 0; i < nums.size(); i++) {
        while (!st.empty() && nums[i] > nums[st.top()]) {
            ans[st.top()] = nums[i];
            st.pop();
        }
        st.push(i);
    }

    // Elements left in the stack do not have a greater element to their right,
    // so they remain -1 which is already initialized.

    return ans;
}

vector<int> nextgreaterelementfromleftside(vector<int> nums) {
    vector<int> ans(nums.size(), -1);
    stack<int> st;

    for (int i =nums.size()-1; i >= 0; i--) {
        while (!st.empty() && nums[i] > nums[st.top()]) {
            ans[st.top()] = nums[i];
            st.pop();
        }
        st.push(i);
    }
    while (!st.empty()) {
        ans[st.top()] = -1;
        st.pop();
    }
    return ans;
}


vector<int> nextGreaterelement2(vector<int> nums) {
    vector<int> ans(nums.size(), -1);
    stack<int> st;
    int n = nums.size();
    
    for (int i = 0; i < 2 * n; i++) {
        while (!st.empty() && nums[i % n] > nums[st.top()]) {
            ans[st.top()] = nums[i % n];
            st.pop();
        }
        if (i < n) {
            st.push(i);
        }
    }
    return ans;
}


int histogrammaxarea(vector<int> nums) {
    int ans = 0; // Initialize ans to 0.
    stack<int> st;
    
    // Traverse through all bars of the histogram.
    for (int i = 0; i < nums.size(); i++) {
        // While the stack is not empty and the current bar is lower than the bar at stack top
        while (!st.empty() && nums[i] < nums[st.top()]) {
            int height = nums[st.top()]; // The height of the bar at stack top
            st.pop(); // Remove the bar from the stack
            
            // Calculate the width of the rectangle with height = height
            int width = st.empty() ? i : i - st.top() - 1;
            ans = max(ans, height * width); // Update the maximum area
        }
        st.push(i); // Push the current bar's index onto the stack
    }
    
    // Process any remaining bars in the stack
    while (!st.empty()) {
        int height = nums[st.top()];
        st.pop();
        int width = st.empty() ? nums.size() : nums.size() - st.top() - 1;
        ans = max(ans, height * width);
    }
    
    return ans;
}


vector<int> printbracketnumber(string s){
    vector<int> ans;
    stack<int> st;
    int count=0;
    int close=0;
    for(char ch : s){
        if(ch == '('){
           count++;
           st.push(count);
           ans.push_back(st.top());
        }
        if( ch == ')'){
            ans.push_back(st.top());
            st.pop();
        }
    }
    return ans;
}


vector<int> getminimumatpop(vector<int> s){
    vector<int> ans;
    stack<int> st;
    int min=s[0];
    for(auto it :s){
        if(min>it)
            min=it;
        st.push(min);
    }
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}


vector<int> nextsmallerelementfromrightside(vector<int> nums) {
    vector<int> ans(nums.size(), -1);
    stack<int> st;

    for (int i = 0; i < nums.size(); i++) {
        while (!st.empty() && nums[i] < nums[st.top()]) {
            ans[st.top()] = nums[i];
            st.pop();
        }
        st.push(i);
    }

    // Elements left in the stack do not have a greater element to their right,
    // so they remain -1 which is already initialized.

    return ans;
}

vector<int> nextsmallerelementfromlefttside(vector<int> nums) {
    vector<int> ans(nums.size(), -1);
    stack<int> st;

    for (int i = nums.size()-1; i >=0; i--) {
        while (!st.empty() && nums[i] < nums[st.top()]) {
            ans[st.top()] = nums[i];
            st.pop();
        }
        st.push(i);
    }

    // Elements left in the stack do not have a greater element to their right,
    // so they remain -1 which is already initialized.

    return ans;
}
vector<int> stock(vector<int> nums) {
    vector<int> ans(nums.size(), 1);
    stack<int> st;

    for (int i = nums.size()-1; i >=0; i--) {
        while (!st.empty() && nums[i] > nums[st.top()]) {
            ans[st.top()] = st.top()-i;
            st.pop();
        }

        st.push(i);
    }

    // Elements left in the stack do not have a greater element to their right,
    // so they remain 1 which is already initialized.

    return ans;
}


string removeStars(string s) {
    string a;
    for(char ch:s){
        if( ch == '*'){
            a.pop_back();
        }
        else
            a+=(ch);
    }
    return a;  
}

int maxDepth(string s) {
    stack<int>  st;
    int n=0;                     //()(())((()())) //ans=3
    for(char ch : s){
        if(ch == '('){
            st.push(ch);
            if(!st.empty()){
                if(st.size()>n)
                   n=st.size();
            }
        }
        else if( ch== ')' && st.top() == '('){
            st.pop();
        }
    }   
    return n;
}

string smallestNumber(string pattern) {
    stack<int> st;
    string ans;
    int n=1;
    for(char ch : pattern){
        if(ch == 'D')
            st.push(n);
        else if(ch == 'I'){
            ans+=to_string(n);
            while(!st.empty()){
               ans+=to_string(st.top());
               st.pop();
            }
        }
        n++;
    } 
    st.push(pattern.length()+1);  
    while(!st.empty()){
        ans+=to_string(st.top());
        st.pop();
    }
    return ans;
}


int main(){
    // stack<int> st;
    // for(int i=0;i<5;i++){
    //    st.push(i);
    // }
    // print(st);
    
    vector<int> s={100,80,60,75,80,60,65,70,75,80};
    vector<int> ans=stock(s);
    for(int i=0 ;i<ans.size();i++){
        cout<<ans[i];
    }
    

    return 0;
}