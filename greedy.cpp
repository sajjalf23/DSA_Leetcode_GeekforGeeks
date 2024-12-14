#include<iostream>
#include<vector>              // GREEDY ALGORITHM
#include<algorithm>           // LEETCODE + GEEKFORGEEKS
#include<queue>
#include<math.h>
using namespace std;


    /*
    int helper( int n ){
        vector<int> a = { 1, 2, 5, 10, 20, 50, 100, 200, 500, 2000 };
        for(int i = 0 ; i < a.size() ; i++){
            if(n < a[i])
               return a[i-1];
            if(n == a[i])
               return a[i];
        }
        return -1;
    }                                      // not optimized solution
    vector<int> min(int n){                // minimum number of coins  at   geekforgeeks
        vector<int> ans;
        int t = 0;
        while(n>0){
           t = helper(n);
           cout<<t<<endl;
           ans.push_back(t);
           n = n - t;
        }
        if(n == 0)
           return ans;
    }
    */


    vector<int> minimum_number_of_coins(int n){                // minimum number of coins  & geekforgeeks
        vector<int> ans;
        vector<int> a = { 1, 2, 5, 10, 20, 50, 100, 200, 500, 2000 };   //optimized
        for(int i = a.size()-1 ; i >= 0 ; i--){
            if(n / a[i] != 0 ){
                int t = n / a[i];
                n = n - (t*a[i]);
                while(t){
                ans.push_back(a[i]);
                t--;
                }
            }
            if(n == 0)
                return ans;
        }
    }


    vector<int> candyStore( vector<int> candies, int N, int K){          //https://www.geeksforgeeks.org/problems/shop-in-candy-store1145/1?
    sort(candies.begin(),candies.end());
    vector<int> ans;
    int min = 0 ;
    int i = 0, j = candies.size()-1;
        while( i <= j ){
            min += candies[i];
            j -= K;
            i++;
        }
    ans.push_back(min);
    int max = 0 ;
    j = candies.size() - 1 , i = 0;
        while( i <= j ){
            max += candies[j];
            i += K;
            j--;
        }
    ans.push_back(max);
        return ans;
    }                       


    int assignMiceHoles(int N , int M[] , int H[]) {          // https://www.geeksforgeeks.org/problems/assign-mice-holes3053/0
        sort(M,M+N);
        sort(H,H+N);
        
        int ans = 0;
        
        for(int i = 0 ; i < N ; i++){
            int dummy = (abs(M[i]-H[i]));
            if(ans < dummy){
                ans = dummy;
            }
        }
        return ans;
    }


    
    bool comparator(const std::pair<int,int> & a,const std::pair<int,int> & b){    //https://www.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1
        return a.second<b.second;
    }
    int maxMeetings(int n, int start[], int end[]) {
        vector<pair<int,int>> meeting;
        for(int i = 0 ; i < n ; i++){
            meeting.push_back({start[i],end[i]});
        }
        sort(meeting.begin(),meeting.end(),comparator);
        int last = meeting[0].second;
        int ans = 1;
        for(int i = 1 ; i < n ; i++){
            if(last < meeting[i].first){
                last = meeting[i].second;
                ans++;
            }
        }
        return ans;
    }


    int rotationCount(long long R, long long D)         // https://www.geeksforgeeks.org/problems/minimum-rotations-to-unlock-a-circular-lock1001/0
    {
        int dummy1 , dummy2 ;
        int ans;
        
        while(R){
            dummy1 = R % 10;
            dummy2 = D % 10;
            R/=10;
            D/=10;
            
            int b = (10 - abs(dummy1 - dummy2));
            int a = abs(dummy1 - dummy2);
            if( a < b ){
                ans += a;
            }
            else
                ans += b;
        }
        return ans;
    }


    /* 
    bool comparator(Job a, Job b){
        return a.profit > b.profit;
    } 
                                                      // not optimized solution
    vector<int> JobScheduling(Job arr[], int n) {        // https://www.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1
        sort(arr,arr+n,comparator);
        int deadline = 0;
        for(int i = 0 ; i < n ;i++){
            deadline = max(deadline,arr[i].dead);
        }
        vector<bool> DONE(deadline+1,0);
        vector<int> ans(2,0);
        for( int i = 0 ; i < n ; i++){
            for( int j = arr[i].dead ; j > 0; j--){
                if(DONE[j] == 0){
                    DONE[j] = 1;
                    ans[0]++;
                    ans[1]+=arr[i].profit;
                    break;
                }
            }
        }
        return ans;
    } 
    */
    
    /*
    int find(int num , vector<int> & DONE){
        if(DONE[num] != num){
            return DONE[num] = find(DONE[num] , DONE);
        }
        return DONE[num];
    }                                                     // optimized
    vector<int> JobScheduling(Job arr[], int n) {        // https://www.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1
        sort(arr,arr+n,comparator);
        int deadline = 0;
        for(int i = 0 ; i < n ;i++){
            deadline = max(deadline,arr[i].dead);
        }
        vector<int> DONE(deadline+1,0);
        for(int i = 0 ; i < deadline+1 ;i++){
            DONE[i] = i;
        }
        vector<int> ans(2,0);
        for( int i = 0 ; i < n ; i++){
            int slot = find(arr[i].dead,DONE);
            if(slot > 0){
                ans[0]++;
                ans[1]+=arr[i].profit;
                DONE[slot] = slot - 1;
            }
        }
        return ans;
    } 
    */

    vector<int> getOrder(vector<vector<int>>& tasks) {        // https://leetcode.com/problems/single-threaded-cpu/
    vector<int> ans;
    int n = tasks.size();
    for(int i = 0 ; i < n ; i++){
        tasks[i].push_back(i);
    }  
    sort(tasks.begin(),tasks.end());
    long long timer = tasks[0][0];
    int i = 0 ;
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
    while(i < n || !pq.empty()){
        while(i<n && timer>=tasks[i][0]){
            pq.push({tasks[i][1],tasks[i][2]});
            i++;
        }
        if(pq.empty()){
            timer = tasks[i][0];
        }
        else{
            ans.push_back(pq.top().second);
            timer+=pq.top().first;
            pq.pop();
        }
    }  
    return ans;
    }

    /*                  
    bool comparator(Item a, Item b) {           //https://www.geeksforgeeks.org/problems/fractional-knapsack
        double x = (double)a.value / a.weight;
        double y = (double)b.value / b.weight;
        return x > y;
    }
    
    double fractionalKnapsack(int w, Item arr[], int n) {
        sort(arr, arr + n, comparator);
        double profit = 0;
        for (int i = 0; i < n; ++i) {
            if (w >= arr[i].weight) {
                profit += arr[i].value;
                w -= arr[i].weight;
            } else {
                double temp = (double)arr[i].value / arr[i].weight;
                profit += temp * w;
                break;
            }
        }
        return profit;
    }
     */

    
    bool comp(vector<int> a,vector<int> b){
    return a[1] < b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) { //https://leetcode.com/problems/non-overlapping-intervals/
    int remove = 0;
    sort(intervals.begin(),intervals.end(),comp);
    int end = -64774;
    for(int i = 0 ; i< intervals.size() ; i++){
        if(end <= intervals[i][0]){
           end = intervals[i][1];
        }
        else{
            remove++;
        }
    }
    return remove;
    }


    int leastInterval(vector<char>& tasks, int n) {    //https://leetcode.com/problems/task-scheduler/description/
    vector<int>frequency (26,0);
    int count = 0;
    for(int i = 0 ; i < tasks.size() ; i++ ){
        frequency[tasks[i]-'A']++;
        count = max(count,frequency[tasks[i]-'A']);
    } 
    int ans = (count-1)*(n+1);
    for(int i = 0 ; i<26 ; i++ ){
        if(frequency[i] == count){
            ans++;
        }
    }
    int size = tasks.size();
    ans = max(ans,size);
    return ans;
    }



int main(){

    //vector<int>ans = min(43);                        //minimum number of coins  & geekforgeeks
    // ans = minimum_number_of_coins(143);
    // for(int i = 0 ; i< ans.size() ;i++){
    //     cout<<ans[i]<<" ";, 
    // }


    /*
    vector<int> candies={1,3,4,5,6};                     //shop-in-candy-store1145
    vector<int>ans = candyStore(candies,1,2);
    for(int i = 0 ; i< ans.size() ;i++){
        cout<<ans[i]<<" ";
    }
    */

}