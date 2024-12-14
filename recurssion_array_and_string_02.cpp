#include<stack>
#include<iostream>
#include<algorithm>  
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;

          //RECURSSION ARRAY + STRING

          //homeworks of DSA https://drive.google.com/drive/folders/1N9UUtFHRe5a8h1vq3iEVEyvXM5sZDRHv




void print_array(int a[] , int size , int index = 0 ){     // 1)- print_array
    if( index == size){
        return;
    }
    cout << a[index] << " ";
    print_array(a,size,index+1);
}





int sum_of_whole_array(int a[] , int size , int index = 0 ){    // 2)- sum_of_whole_array
    if( index == size){
        return 0;
    }
    return a[index] + sum_of_whole_array(a,size,index + 1);
}




void print_reverse_array(int a[] , int index ){      // 3)- print_reverse_array
    if( index < 0){
        return;
    }
    cout << a[index] << " ";
    print_reverse_array(a , index - 1);
}






int max_of_array(int a[] , int size , int index = 0 ){   // 4)- max_of_array
    if( index == size - 1){
        return a[index];
    }
    return max(a[index],max_of_array(a , size , index + 1));
}





int min_of_array(int a[] , int size , int index = 0 ){    // 5)- min_of_array
    if( index == size - 1){
        return a[index];
    }
    return min(a[index],min_of_array(a , size , index + 1));
}





// number of even elemnets in an array

bool palindrome(string a , int start , int end){     // 6)- palindrome
    if(start >= end)
        return 1;
    if(a[start] != a[end])
        return 0;
    return palindrome(a , start + 1, end - 1);
}






int count_vowels(string a ,int index){     // 7)- count_vowels
    if(index < 0)
        return 0;
    if( a[index] == 'a' || a[index] == 'e' || a[index] == 'i' || a[index] == 'o' || a[index] == 'u')
        return 1 + count_vowels(a , index -1);
    return count_vowels(a , index -1);

}






void print_reverse_string(string a ,int index){     // 8)- print_reverse_string
    if(index < 0)
        return;
    cout << a[index] <<" ";
    return print_reverse_string(a , index - 1);
}






void reverse_string(string &a , int start , int end){     // 9)- reverse_string
    if(start >= end)
        return;
    swap(a[start],a[end]);
    return reverse_string(a , start + 1, end - 1);
}






                                                           // 10)- reverse_string_and_return_a_new_reversed_string

string reverse_string_and_return_a_new_reversed_string(string a ,int index){    
    if(index < 0)
        return "";
    return a[index] + reverse_string_and_return_a_new_reversed_string(a , index - 1);
}






void lower_case_to_upper(string &a ,int index){     // 11)- lower_case_to_upper_case_string
    if(index < 0)
        return;
    if (a[index] >= 'a' && a[index] <= 'z') {
        a[index] = a[index] - 32;
    }
    lower_case_to_upper(a , index - 1);
}

//Calculate the Length of a String
//Print a Pattern of Stars
//copy one string to another using recursion
//first capital letter in a string 

int main(){
    // int a[8] = { 1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 };

    // print_array(a , 8 , 0);

    // cout << "\n" << sum_of_whole_array(a , 8 , 0) << endl;

    // print_reverse_array(a, 7);

    // cout << "\n" << max_of_array(a, 8, 0) << endl;

    // cout << min_of_array(a, 8, 0) << endl;

    string a ="object oriented programming";

    // cout << palindrome(a , 0 , a.size() - 1);

    // reverse_string(a , 0 , a.size() - 1);
    // cout <<" reversed_string : " << a << endl;
 
    // cout << count_vowels(a,a.size()-1); 

    // cout << reverse_string_and_return_a_new_reversed_string(a, a.size()-1) << endl;

    lower_case_to_upper(a , a.size()-1);
    cout << a << endl;

    return 0;
}