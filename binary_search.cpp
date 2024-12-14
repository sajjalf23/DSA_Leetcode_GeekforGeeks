#include<iostream>
#include<vector>
using namespace std;
                      
                    // inary serach practice problems



                                //  https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
vector<int> searchRange(vector<int>& nums, int target) {    
    std::vector<int> ans = {-1, -1};            // Default result if target is not found
    int n = nums.size();
    if (n == 0) return ans;
    int start = 0,end=nums.size()-1;
    while(start <= end){
        int mid = start+(end - start) / 2 ;
        if(nums[mid] == target){
            if (mid == 0 || nums[mid - 1] != target) {
                ans[0]=mid;
                break;
            }
            end = mid - 1;
        } else if (nums[mid] > target) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    } 
    if(ans[0]==-1) return ans;
    start = 0,end=nums.size()-1;
    while(start <= end){
        int mid = start+(end - start) / 2 ;
        if(nums[mid] == target){
            if (mid == n-1 || nums[mid + 1] != target) {
                ans[1]=mid;
                break;
            }
             start = mid + 1;
        } else if (nums[mid] > target) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
            
    } 
    return ans; 
    }




int searchInsert(vector<int>& nums, int target) {  //https://leetcode.com/problems/search-insert-position/
    int start = 0, end = nums.size()-1 , mid =0;
    while(start <= end ){
        mid = start +((end-start)/2);
        if(nums[mid] == target){
            return mid;
        }
        else if(nums[mid] > target){
            end = mid - 1;
        }
        else{
            start = mid + 1;
        }
    } 
    return start;
    }




int mySqrt(int x) {            //https://leetcode.com/problems/sqrtx/
    int  start = 0, end = x ;
    int ans=0; 
    while(start <= end){
        long long  mid = start+((end -start)/2);
        if((mid* mid)>x){
            end = mid-1;
        }
        else if((mid*mid)< x){
            ans=mid;
            start=mid+1;
        }
        else{
            ans = mid;
            return ans;
        }
    }
    return ans;
    }





int findKthPositive( vector<int>& arr, int k ) {    //https://leetcode.com/problems/kth-missing-positive-number/
    int start = 0 , end = arr.size()-1 , mid = 0;
    int missing = 0;
    while(start <= end){
        mid = start + ((end - start) / 2);
        missing = arr[mid] - (mid + 1);
        if(missing < k){
            start = mid + 1;
        }
        else{
            end = mid-1;
        }
    }   
    return (start+k);
    }







int countZeroes(vector<int> &arr) {               //https://www.geeksforgeeks.org/problems/count-the-zeros
        int start = 0, end = arr.size()-1, mid =0,s=-1;
        while(start <= end){
            mid = start +((end-start)/2);
            if(arr[mid] == 0){
                if(mid == 0 || arr[mid-1] != 0){
                    s=mid;
                    break;
                }
                end = mid - 1;
            }
            else
                start = mid + 1;
        }
        
        return  ((arr.size())-s);
    }






int cubeRoot(int N) {         //https://www.geeksforgeeks.org/problems/cube-root-of-a-number
        int start=0,end=N,ans=0;
        long long mid=0;
        while(start<=end){
            mid=start+((end-start)/2);
            if((mid*mid*mid) > N){
                end = mid-1;
            }
            else if((mid*mid*mid) < N){
                ans = mid;
                start = mid +1;
            }
            else{
                return mid;
            }
        }
        return ans;
    }





int count(int arr[], int n, int x) {   //https://www.geeksforgeeks.org/problems/number-of-occurrence
	    int start = 0,end=n,mid=0,s=-1,e=-1;
	    while(start<=end){
	        mid= start+((end-start)/2);
	        if(arr[mid] == x){
	            if(mid==0 || arr[mid-1]!=x){
	                s=mid;
	                break;
	            }
	            end=mid-1;
	        }
	        else if(arr[mid]<x){
	            start = mid+1;
	        }
	        else{
	            end=mid-1;
	        }
	    }
	    start = 0,end=n,mid=0;
	    while(start<=end){
	        mid = start + (( end - start ) / 2);
	        if(arr[mid] == x){
	            if(mid == n || arr[ mid + 1 ]!=x){
	                e=mid;
	                break;
	            }
	            start=mid+1;
	        }
	        else if(arr[mid]<x){
	            start = mid+1;
	        }
	        else{
	            end=mid-1;
	        }
	    }
	      if(s==-1 && e==-1) return 0;
	    return (e-s+1);
	}





   int findKthPositive( vector<int>& arr, int k ) {  //https://leetcode.com/problems/kth-missing-positive-number/
    int start = 0 , end = arr.size()-1 , mid = 0;
    int missing = 0;
    while(start <= end){
        mid = start + ((end - start) / 2);
        missing = arr[mid] - (mid + 1);
        if(missing < k){
            start = mid + 1;
        }
        else{
            end = mid-1;
        }
    }   
    return (start+k);
    }



    
int main(){
}