#include<stack>
#include<iostream>
#include<algorithm>  //RECURSSION BASIC
#include<vector>
#include<math.h>
using namespace std;


void print_happy_birthday(int days){           // 1)- print_how_many_days_r_left_till_my_happy_birthday
    if(days == 0){
        cout<<"it's ur happy birthday !"<<endl;
        return;
    }
    cout<<days<<" days left"<<endl;
    print_happy_birthday(days-1);
}





void print_only_even_numbers(int num){   // 2)- print_only_even_numbers_from_num_till_0
    if(num == -1){
        cout<<endl;
        return;
    }
    if(num %2 == 0) 
        cout<<num<<" ";
    print_only_even_numbers(num - 1);
}




void print_N_to_1(int n){        // 3)- print_N_to_1_decreasingly
    if(n == 0){
        cout<<endl;
        return;
    }
    cout<<n<<" ";
    print_N_to_1(n - 1);
}




void print_x_till_y(int x ,int y){       // 4)- print_x_till_y_increasingly
    if(x == y){
        cout<<x<<endl;
        return;
    }
    cout<<x<<" ";
    print_x_till_y( x + 1, y);
}




void print_table(int table , int x){        // 5)- print table
    if(x == 0){
        return;
    }
    cout<<table<<" * "<< x <<" = "<<table * x<<endl;
    print_table(table , x-1);
}




int factorial(int x){        // 6)- FACTORIAL of x
    if(x == 1){
        return 1;
    }
    return x * (factorial(x-1));
}




int sum_till_n(int n){       // 7)- sum till n
    if(n == 0){
        return 0;
    }
    return n + sum_till_n(n-1);
}




void decimal_to_binary(int num){      // 8)-  decimal to binary conversion
    if(num == 0){
        return;
    }
    int remainder = num % 2;
    decimal_to_binary(num/2);
    cout<< remainder <<" ";
}




int sum_of_square_of_n_number(int n){           // 9)- sum_of_squares_of_all_numbers_till_n_number
    if(n == 1){
        return 1;
    }
    return pow(n,2) + sum_of_square_of_n_number(n-1);
}





int nth_power_of_two(int n){             // 10)- nth_power_of_two
    if(n == 1){
        return 2;
    }
    return 2 * nth_power_of_two(n-1);
}





int nth_power_of_x(int n , int x){           // 11)- nth_power_of_x
    if(n == 1){
        return x;
    }
    return x * nth_power_of_two(n-1);
}





int fibonacii(int n ){           // 12)- fibonacii + leetcode  https://leetcode.com/problems/fibonacci-number/description/
    if(n <= 1){
        return n;
    }
    return fibonacii(n-1) + fibonacii(n-2);
}






int climbStairs(int n){               // 13)- Climbing Stairs + leetcode + count number of HOOPs   &&   https://leetcode.com/problems/climbing-stairs/description/ 
    if(n <= 1){
        return 1;
    }
    return climbStairs( n - 1 ) + climbStairs( n - 2 );
}





int climbStairs_optimized(int n){     // 14)- Climbing Stairs + leetcode + optimized
    if(n <= 1)                         // count number of HOOPs
        return 1;
    
    vector<int> a (n+1 , 0);
    a[0] = 1;
    a[1] = 1;

    for(int i = 2 ; i <= n ; i++){
        a[i] = a[i-1] + a[i-2];
    }

    return a[n];
}





int gcd(int a , int b){                         // 15)- gcd + geekforgeeks
    if( a == 0 ){
        return b;
    }
    return gcd( b % a , a);
}






int lcm(int a, int b){                     // 16)-  Least Common Multiple (LCM)
    return (a*b) / gcd(a,b);
}






void print_digits(int a){                 // 17)- print_digits
    if( a == 0) 
       return;
    print_digits( a / 10 );
    cout<< a % 10 <<" ";
}





int Compute_the_Sum_of_Digits(int a){       // 18)- Compute the Sum of Digits
    if(a == 0)
        return 0;
    return (a % 10) + Compute_the_Sum_of_Digits( a / 10 );
}





int count_digits_in_a_number(int a){        // 19)- count digits in a number
    if(a == 0)
        return 0;
    return 1 + count_digits_in_a_number(a / 10);
}






bool isPoweroffour(int a){    //20)- power of four    https://leetcode.com/problems/power-of-four/description/
    if( a == 0 ){
        return 0;
    }
    if( a == 1 ){
        return 1;
    }
    return (a % 4 == 0) && isPoweroffour( a / 4 );
}




 
bool ispoweroftwo(int num){    // 21)- power_of_two    https://leetcode.com/problems/power-of-two/description/
    if(num == 0)
       return 0;
    if(num == 1)
       return 1;
    return (num % 2 == 0) && ispoweroftwo(num/2);
}





bool ispowerofthree(int num){   // 22)- is power of three    https://leetcode.com/problems/power-of-three/description/
    if(num == 0)
       return 0;
    if(num == 1)
       return 1;
    return (num % 3 == 0) && ispowerofthree(num / 3);
}





bool check_prime(int num, int i = 2)      //  23)-  a number is prime or not
{
    if (num <= 1)
        return false;
    else if (num <= 3)
        return true;
    else if (num % 2 == 0)
        return false;
    if (num % i == 0)
        return false;
    if (i * i > num)
        return true;
    return check_prime(num, i + 1);
}








bool perfect_sq(int num, int i = 2)    //    24)- a no is perfect sq or not
{
    if (i * i > num)
        return false;
    if (i * i == num)
        return true;
    return perfect_sq(num, i + 1);
}







//Hailstone Sequence of a given number up to 1.


int main(){

    // print_happy_birthday(5);

    // print_only_even_numbers(10);

    // print_N_to_1(5);

    // print_x_till_y(10,15);

    // print_table(8,10);

    // cout<<factorial(5)<<endl;

    // cout<<sum_till_n(6)<<endl;

    // decimal_to_binary(120);

    // cout<<sum_of_square_of_n_number(5)<<endl;

    // cout<<nth_power_of_two(5)<<endl;

    // cout<<nth_power_of_x(2,2)<<endl;

    // cout<<fibonacii(4)<<endl;

    // cout << climbStairs(5) << endl;

    // cout<< climbStairs_optimized(5)<<endl;

    // cout << gcd(48,18) << endl;

    // print_digits(150) ;

    // cout << Compute_the_Sum_of_Digits(38) ;

    // cout << count_digits_in_a_number(353008) ;

    // cout<< isPoweroffour(24) <<endl;

    // cout<< ispoweroftwo(16) <<endl;
    
    // cout << ispowerofthree(9) <<endl;

    cout << lcm(12,24) << endl;
     
    return 0;
}