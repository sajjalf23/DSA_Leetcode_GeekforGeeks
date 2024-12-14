#include<stack>
#include<iostream>
#include<algorithm>  //RECURSSION BINARY SEARCH
#include<vector>
#include<math.h>
using namespace std;

bool linear_search(int a[] , int size , int index ,int val){ // 1)-  is val(element) present in array
    if(index > size){
        return 0;
    }
    if(a[index] == val)
        return 1;
    return linear_search(a , size , index + 1 , val);
}







int linear_search_return_index(int a[] , int size , int index ,int val){   // 2)- search an element in an array  geekforgeeks  and return index
    if(index > size){
        return -1;
    }
    if(a[index] == val)
        return index;
    return linear_search_return_index(a , size , index + 1 , val);
}






bool binary_search(int a[] ,int size , int start , int end ,int val){   // 3)-  is val(element) present in array by binary
    if(start > end)                                                     // only for increasing or decreasing array 
       return 0;
    int mid = start + (end - start)/2;
    if(a[mid] == val)
        return 1;
    else if(a[mid] < val)
        return  binary_search(a, size , mid+1 , end, val);
    else if(a[mid] > val)
        return  binary_search(a, size , start, mid-1 , val);
}






int binary_search_return_index(int a[] ,int size , int start , int end ,int val){   // 4)- searching an elemnt in a sorted array  geekforgeeks  and return index
    if(start > end)
       return -1;
    int mid = start + (end - start)/2;
    if(a[mid] == val)
        return mid;
    else if(a[mid] < val)
        return  binary_search_return_index(a, size , mid+1 , end, val);
    else if(a[mid] > val)
        return  binary_search_return_index(a, size , start, mid-1 , val);
}




int main(){
    int a[8] = { 1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 };

    // cout << linear_search(a ,8 , 0 , 80);

    // cout << linear_search_return_index(a ,8 , 0 , 8);

    //cout << binary_search(a,8,0,8,6);

    cout << binary_search_return_index(a,8,0,8,6);
}