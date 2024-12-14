#include<stack>
#include<iostream>
#include<algorithm>  //RECURSSION ON SUBSEQUENCES  & PERMUTATION
#include<vector>
#include<math.h>
#include<ctype.h>
#include<string>
using namespace std;
                                                    
                                                     // subsequence arrays + (78. Subsets) leetcode problem
                                                      // https://leetcode.com/problems/subsets/solutions/5601407/cpp-solution-recurssion/
void subsequence(int a[] , int index , int n , vector<int> &temp , vector<vector<int>> & ans){ 
    if( index == n ){                                                               
        ans.push_back(temp);
        return;
    }
    subsequence( a , index + 1 , n , temp , ans);
    temp.push_back(a[index]);
    subsequence( a , index + 1 , n , temp , ans);
    temp.pop_back();
}







                                                       // subset of strings
void subset_strings(string a, int index, int n, vector<char> dummy, vector<vector<char>> &subset) {
    if (index == n) {
        subset.push_back(dummy);
        return;
    }
    subset_strings(a, index + 1, n, dummy, subset);
    dummy.push_back(a[index]);
    subset_strings(a, index + 1, n, dummy, subset);
    dummy.pop_back();
}







                                                       // generate parenthesis
                                                       //https://leetcode.com/problems/generate-parentheses/description/
void generate_parenthesis(int n, int left, int right , string &dummy, vector<string> &parenthesis) {
    if ( left + right == 2 * n ) {
        parenthesis.push_back(dummy);
        return;
    }
    if( left < n ){
        dummy.push_back('(');
        generate_parenthesis( n , left+1 , right , dummy , parenthesis);
        dummy.pop_back();
    }
    if( right < left ){
        dummy.push_back(')');
        generate_parenthesis( n , left , right+1 , dummy , parenthesis);
        dummy.pop_back();
    }
}








void generate_binary_string( int n , int i , string & temp , vector<string> &ans , bool prev){   // 3211. Generate Binary Strings Without Adjacent Zeros
    if( i == n ){                                                    // https://leetcode.com/problems/generate-binary-strings-without-adjacent-zeros/description/
        ans.push_back(temp);
        return;
    }
    if( prev != 0 ){
        temp+='0';
        generate_binary_string( n , i+1 , temp , ans , 0);
        temp.pop_back();
        temp+='1';
        generate_binary_string( n , i+1 , temp , ans , 1);
        temp.pop_back();
    }
    if( prev == 0 ){
        temp+='1';
        generate_binary_string( n , i+1 , temp , ans , 1);
        temp.pop_back(); 
    }
}









void subset_sum(int a[] , int index , int n , int sum ){        // subset_sum 
    if( n == index){
        cout << sum << endl;
        return;
    }
    subset_sum(a , index + 1 , n, sum);
    subset_sum(a , index + 1 , n , sum + a[index] );
}








bool target_sum(int a[] , int index , int n , int target){          // target sum
    if( target == 0 ){
        return 1;
    }
    if( index == n || target < 0){
        return 0;
    }
    return target_sum( a, index +1 , n , target) || target_sum( a, index +1 , n , target - a[index]);
}









int perfect_sum( int a[] , int index , int n , int target ){          // perfect sum
    if( index == n ){                                                // good for 0 in array
        return ( target == 0 );
    }
    return perfect_sum( a , index + 1 , n , target ) + perfect_sum( a , index + 1 , n , target - a[index] );
}











int target_sum_repeat_it_on( int a[] , int index , int n , int target ){      //target_sum_repeat_it_on
    if( target == 0 ){                                                             // bad for 0 in array
        return 1;
    }
    if( index == n || target < 0 ){
        return 0;
    }
    return target_sum_repeat_it_on( a , index + 1 , n , target ) + target_sum_repeat_it_on( a , index , n , target - a[index] );
}










void permutation( int a[] , vector<int> &temp , vector<bool> &visited , vector<vector<int>> &ans){
    if( visited.size() == temp.size() ){
        ans.push_back(temp);
        return ;
    }
    for( int i = 0 ; i < visited.size() ; i++ ){
        if(visited[i] == 0){
            visited[i] == 1;
            temp.push_back(a[i]);
            permutation ( a , temp , visited , ans);
            visited[i] = 0;
            temp.pop_back();
        }
    }
}










void advance_permutation( vector<int> &a ,  vector<vector<int>> &ans , int index ){
    if(index == a.size()){
        ans.push_back(a);
        return ;
    }
    for ( int i = index ; i < a.size() ; i++){
        swap( a[index] , a[i] );
        advance_permutation( a , ans , index + 1 );
        swap( a[index] , a[i] );
    }
}








void permutation_two(vector<int> &array , vector<vector<int>> & ans , int index ){        //permutation 2 leetcode
    if( index == array.size()){
        ans.push_back(array);
        return;
    }
        vector<bool> check(21,0);
        for(int i = index ; i < array.size() ; i++){
            if(check[array[i]+10] == 0){
            swap(array[i] , array[index]);
            permutation_two(array , ans, index+1);
            swap(array[i] , array[index]);
            check[array[i]+10] = 1;
            }
        }
}









void towerOfHanoi(int n, char source, char helper, char destination) {
    // Base case: If there is only one disk, move it from source to destination
    if (n == 1) {
        cout << "Move disk 1 from rod " << source << " to rod " << destination << endl;
        return;
    }

    // Move n-1 disks from source to helper using destination as an helper rod
    towerOfHanoi(n - 1, source, destination, helper);

    // Move the nth disk from source to destination
    cout << "Move disk " << n << " from rod " << source << " to rod " << destination << endl;

    // Move the n-1 disks from helper to destination using source as an helper rod
    towerOfHanoi(n - 1, helper, source, destination);
}








int main(){

    /*
    int a[] = {1,2,3};
    vector<int> temp;                                    // for subsequences function
    vector<vector<int>> ans;
    subsequence(a,0,3,temp,ans);
    for(int i = 0 ; i < ans.size() ; i++){
        cout << "{" ;
        for(int j = 0 ; j < ans[i].size() ; j++){
            cout << ans[i][j] ;
        }
        cout << "}" <<endl;
    }   
    */


    /*
    string b = "abs";
    vector<char> dummy;                                     // for subset_strings function
    vector<vector<char>> subset;
    subset_strings( b ,  0 ,b.size() ,dummy , subset);
    for(int i = 0 ; i < subset.size() ; i++){
        cout << "{" ;
        for(int j = 0 ; j < 
        subset[i].size() ; j++){
            cout << subset[i][j] ;
        }
        cout << "}" <<endl;
    } 
    */

    /*                                                    // for parenthesis function
    string dummy;
    vector<string>  parenthesis;
    generate_parenthesis(3 , 0 , 0 , dummy , parenthesis);
    cout << "{" ;
    for(int j = 0 ; j < parenthesis.size() ; j++){
            cout << parenthesis[j] << ",";
    }
    cout << "}" <<endl;
    */    
   

    /*                                                     // for generate_binary_string
    string dummy;
    vector<string>  binary_string;
    generate_binary_string(3 , 0 , dummy , binary_string , 1);
    cout << "{" ;
    for(int j = 0 ; j < binary_string.size() ; j++){
            cout << binary_string[j] << ",";
    }
    cout << "}" <<endl;
     */ 


    // int alpha[] = {1 , 2 , 3};
    // subset_sum( alpha , 0 , 3, 0 );
    // cout << target_sum( alpha , 0 , 3 , 6 );                   //target_sum
    // cout << perfect_sum( alpha , 0 , 2, 1 );                   // perfect_sum
    // cout << target_sum_repeat_it_on( alpha , 0 , 2, 1 );       //target_sum_repeat_it_on

    /*
    int a[] = {1,2,3};
    vector<int> temp;                                    // for permutation
    vector<vector<int>> ans;
    vector<bool> visited;
    permutation(a,temp,visited, ans);
    for( int i = 0 ; i < ans.size() ; i++ ){
        for( int j = 0 ; j < ans[i].size() ; j++ ){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    */

    /*
    vector<int> a ={1,2,3};              //advance_permutation
    vector<vector<int>> ans;
    advance_permutation(a , ans, 0);
    for( int i = 0 ; i < ans.size() ; i++ ){
        for( int j = 0 ; j < ans[i].size() ; j++ ){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    */

    
    // vector<int> a ={-1,-1,3};              //permutation_two
    // vector<vector<int>> ans;
    // permutation_two(a , ans, 0);
    // for( int i = 0 ; i < ans.size() ; i++ ){
    //     for( int j = 0 ; j < ans[i].size() ; j++ ){
    //         cout << ans[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    towerOfHanoi(3, 'S', 'H', 'D'); // 'A' is the source rod, 'B' is the auxiliary rod, and 'C' is the destination rod
}