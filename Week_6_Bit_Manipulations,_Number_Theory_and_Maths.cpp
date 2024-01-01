//reading materials

/*Question 1

Print the binary representation of the given non-zero integer.

 

Example:

7 => 111
4 => 100
Solution Idea:

Method 1: (Iterative) Consider each bit of unsigned int and check if a 
bit is set or not and print 1 or 0 accordingly. */

#include<bits/stdc++.h>
typedef long long lli;
using namespace std;

int main()
{
    unsigned int x = 7; 
    for(int i=31;i>=0;i--) // looping through each digit from MSB to LSB
    {
        if(x&(1<<i))       // checking current bit is set or not
        {
            cout << '1';
        }
        else cout << '0';
    }
    cout<<endl;
    return 0; 
}
/*Method 2: (Recursive) For the given number print all the bits except
 the LSB(least significant bit) recursively then print the LSB. */

#include<bits/stdc++.h>
typedef long long lli;
using namespace std;

void printbin(unsigned int x)
{
    if(x>1)
    {
        printbin(x/2);    // recursive call to rest of the bits
    }
    cout<<(x%2);          // print the last bit
}

int main()
{
    unsigned int x = 4; 
    printbin(x);
    return 0; 
}


/*Question 1

Given an array where every element occurs three times, except one element 
which occurs only once. Find the element that occurs once.

 

Example:

{23, 5, 23, 4, 23, 4, 5, 3, 5, 4} => 3
{15, 12, 15, 9, 15, 9, 9} => 12
Solution Idea:

Method 1: Loop through each bit of all the elements and find the sum of 
bits at each place. If the sum of bits at each position is not divisible by 3,
 then the required answer has the bit set at that position.
*/
#include<bits/stdc++.h>
typedef long long lli;
using namespace std;
lli mod=1e9+7;

int find_single_occurence(vector<int> &arr)
{
    int n=arr.size();
    int ans=0;
    for(int i=0;i<32;i++)   // looping through each digit
    {
        int sum=0;
        for(int j=0;j<n;j++) // looping through each element
        {
            sum+=(arr[j] & (1<<i));
        }
        if(sum%3)           
        {
            ans|=(1<<i);    // set the bit in answer
        }
    }
    return ans;   
}

void solve()
{
    vector<int> arr={23, 5, 23, 4, 23, 4, 5, 3, 5, 4};
    int ans = find_single_occurence(arr);
    cout<<ans<<endl;
}

int main()
{
    lli t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0; 
}
/*Question 2

Given an array where every element occurs an even number of times, except 
one element which occurs an odd number of times. Find the element that
 occurs an odd number of times.

Example:

{23, 15, 23, 4, 23, 4, 15, 4, 23, 15, 15} => 4
{15, 19, 12, 15, 19, 19, 19} => 12
Solution Idea:

Method 1: Simple way to find the element which occurs an odd number of times 
is to do XOR of all the elements in the array. Since XOR of two same numbers 
is zero so XOR of even occurrences of number will be zero. */

#include<bits/stdc++.h>
typedef long long lli;
using namespace std;
lli mod=1e9+7;

int find_odd_occurence(vector<int> &arr)
{
    int n=arr.size();
    int ans=0;
    for(int i=0;i<n;i++)   // looping through each element
    {
        ans = ans^arr[i];  // XOR of all the elements
    }
    return ans;   
}

void solve()
{
    vector<int> arr={23, 15, 23, 4, 23, 4, 15, 4, 23, 15, 15};
    int ans = find_odd_occurence(arr);
    cout<<ans<<endl;
}

int main()
{
    lli t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0; 
}
/*Question 3

Given an array where every element occurs twice, except two elements which 
occur only once. Find both the elements which occur only once.

Example:

{23, 23, 4, 3, 5, 3, 15, 15} => 4,5
{15, 10, 12, 10, 19, 19} => 12,15
Solution Idea:

Method 1: Suppose two numbers are a and b. First find the XOR of all the 
elements in the array to obtain a^b. Now any bit set in this a^b is set either in 
a or in b. Divide all the elements in two groups based on the bit set at the 
same position of the set bit of a^b. In this way a and b will be in two separated 
groups. Finally find the xor of each group separately to find a and b. */


#include<bits/stdc++.h>
typedef long long lli;
using namespace std;
lli mod=1e9+7;

void find_two_numbers(vector<int> &arr, int *a, int *b)
{
    int n=arr.size();
    *a=0;
    *b=0;
    int x=0;
    for(int i=0;i<n;i++)    // find xor of all the elements
    {
        x^=arr[i];
    }
    int set_bit = (x)&(~(x-1));// find the set bit of xor
    for(int i=0;i<n;i++)
    {
        if(set_bit&(arr[i]))   // if bit is set put in first group
        {
            *a = *a ^ arr[i];
        }
        else *b = *b ^ arr[i]; // else in another group
    }
    return;
}

void solve()
{
    vector<int> arr={15, 10, 12, 10, 19, 19};
    int *a = new int[sizeof(int)];
    int *b = new int[sizeof(int)];
    find_two_numbers(arr,a,b);
    cout<<*a<<" "<<*b<<endl;
}

int main()
{
    lli t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0; 
}
/*Question 4

Find the XOR of numbers from 1 to n.

Example:

12 => 12
15 => 0
Solution Idea:

Method 1: The XOR of numbers from 1 to any number just before
 multiple of 4 is 0(i.e. 3,7,11).  */

#include<bits/stdc++.h>
typedef long long lli;
using namespace std;
lli mod=1e9+7;

int find_xor_upto_n(int n)
{
    int rem=n%4;
    switch(rem)
    {
        case 0: return n;
        case 1: return 1;
        case 2: return n+1;
        case 3: return 0;
    }
    return 1;
}
void solve()
{
    int n=14;
    int ans = find_xor_upto_n(n);
    cout<<ans<<endl;
}

int main()
{
    lli t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0; 
}
/*Question 5

One number is missing from the list of integers from 1 to n. 
Find that missing number.

Example:

{1, 2, 5, 6, 3, 7}  => 4
{2, 4, 6, 5, 1} => 3
Solution Idea:

Method 1: The simple way to find the missing number is to find the xor 
of numbers from 1 to n and then find the xor of this answer with the xor 
of all the elements of the given list. */


#include<bits/stdc++.h>
typedef long long lli;
using namespace std;
lli mod=1e9+7;

int find_missing_number(vector<int> &arr)
{
    int m = arr.size();
    int n=m+1;
    int ans=0;
    for(int i=1;i<=n;i++) // find the xor from 1 to n
    {
        ans = ans^i;
    }
    for(int i=0;i<m;i++) // find xor from a[0] to a[n-2]
    {
        ans = ans^arr[i];
    }
    return ans;
}

void solve()
{
    vector<int> arr = {1, 2, 5, 6, 3, 7};
    int ans = find_missing_number(arr);
    cout<<ans<<endl;
}

int main()
{
    lli t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0; 
}
/*Question 6

Given a positive integer n, find the count of positive integers i 
such that 0 <= i <= n and n+i=n^i.

Example:

10 => 4
18 => 8
Solution Idea:

Method 1: For any integer i if n+i = n^i, then n&i=0. So we will count 
the number of zero bits in n and calculate how many numbers can be formed
 using these bits as set bits. */

#include<bits/stdc++.h>
typedef long long lli;
using namespace std;
lli mod=1e9+7;

int calculate(int n)
{
    int count_unset=0;
    while(n>0)
    {
        if((n&1)==0)    // count number of zero bits
            count_unset++;
        n>>=1;
    }
    return (1<<count_unset);// There can be 2^count numbers
}

void solve()
{
    int n=18;
    int ans = calculate(n);
    cout<<ans<<endl;
}

int main()
{
    lli t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0; 
}
/*Question 7

Given an array of integers, find the xor of elements of all 
the subarrays possible.

Example:

{12,15,6,7,9,14,18} => 17
{2,5,6,8,7,12} => 0
Solution Idea:

Method 1: Find the frequency of occurrence of each element in all the subarrays. 
Only elements whose frequency is odd will contribute to the final answer. 
The frequency of element at ith index is (i+1)(n-i). */


#include<bits/stdc++.h> 
typedef long long lli;
 using namespace std;
  lli mod=1e9+7;
 int find_xor_of_subarrays(vector<int> &arr) {  
   int n=arr.size();  
     int ans=0;   
      for(int i=0;i<n;i++)    {        int freq=(i+1)*(n-i); 
       
            if(freq%2)        {            ans = ans^arr[i];  
                  }    }    return ans; 
              } 
              
              
              void solve() {  
                vector<int> arr={12,15,6,7,9,14,18}; 
                  
                 int ans=find_xor_of_subarrays(arr);
                  
                    cout<<ans<<endl;
                     }
                    
                    
                    
                     int main() {   
                      lli t;  
                       cin>>t;  
                       
                         while(t--) {      
                         
                           solve();    
                       
                       }   
                        return 0; 
                    }

Method 2: It can be observed that if the size of the array is even then 
frequency of each element is even else if number of elements is odd then
 elements at even position have odd frequency and elements at odd position 
 have even frequency. So elements at odd positions will contribute to the final answer.

#include<bits/stdc++.h> 
 typedef long long lli; 
 using namespace std; lli mod=1e9+7;
 
 int find_xor_of_subarrays(vector<int> &arr) {  
   int n=arr.size();  
     int ans=0;   
      if(n%2==0)      
        return 0;    
    for(int i=0;i<n;i+=2){      
      ans^=arr[i];
          
  }   
   return ans; 
} 
void solve() {  
  vector<int> arr={12,15,6,7,9,14,18}; 
     int ans=find_xor_of_subarrays(arr);  
     
    cout<<ans<<endl; } 
    int main() {    
    	lli t;    
    	cin>>t;   
    	 while(t--)   
    	  {      
    	    solve();   
    	     }   
    	      return 0;
    	       }

/*Question 8

Suppose f(X,Y) = number of positions in binary representation where bits differ.
 Given an array of integers, find the sum of f(ai,aj) for every possible i and j
  in range 1 to n. Find answer modulo 109+7.

Example:

{2, 3, 7, 6, 4} => 32
{1,5,12,7,14,16} => 76
Solution Idea:

Method 1: If at any position in binary representation there are x numbers with
 bit set and y numbers with bit unset then this position will contribute 2x*y 
 to the answer. Since all bits will act as independent in this question so we 
 will add answers for each bit individually to the final answer.
*/
#include<bits/stdc++.h>
typedef long long lli;
using namespace std;
lli mod=1e9+7;

int func(vector<int> &A) {
    int n=A.size();
    int ans=0;
    for(int i=0;i<31;i++)   // loop through each bit
    {
        long long int cnt1=0,cnt2=0;
        for(int j=0;j<n;j++)    // loop through each element
        {
            cnt1+= ( (A[j]&(1<<i)) > 0 ); // count number of set bits
        }
        cnt2=n-cnt1;        // number of unset bits
        cnt1%=mod;
        cnt2%=mod;
        ans = (ans%mod +cnt1*cnt2)%mod;
    }
    return (ans+ans)%mod; // double the answer for every pair
}

void solve()
{
    vector<int> arr={2, 3, 7, 6, 4};
    int ans=func(arr);
    cout<<ans<<endl;
}

int main()
{
    lli t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0; 
}
/*Question 9

Given an array of integers, find the minimum xor of a pair of 
elements of the array.

Example:

{2, 3, 7, 6, 4} => 1
{2, 5, 4, 2, 6, 8, 9} => 0
Solution Idea:

Method 1: Sort the array in increasing order. Then minimum xor will be xor
 of ai and ai+1 for some i. This can be easily proved by contradiction.
*/
#include<bits/stdc++.h>
typedef long long lli;
using namespace std;
lli mod=1e9+7;

int minimum_xor(vector<int> &A) {
    int n=A.size();
    int res=INT_MAX;
    sort(A.begin(),A.end());
    for(int i=1;i<n;i++)
    {
        res=min(res,A[i]^A[i-1]);
    }
    return res;
}

void solve()
{
    vector<int> arr={2, 3, 7, 6, 4};
    int ans=minimum_xor(arr);
    cout<<ans<<endl;
}

int main()
{
    lli t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0; 
}
/*Question 10

Find the total number of set bits of all the numbers from 0 to n.

Example:

4 => 5
5 => 7
Solution Idea:

Method 1:  It is observed that any bit at ith position from right
 gets inverted after 2i numbers. So we can consider a group of 
 size 2i+1 for each i where first 2i numbers have bit 0 and another 
 2i numbers have bit 1 at ith position. Now we will count how many 
 groups are perfectly there upto n, we can count this by dividing n
  by size of group i.e. n/(2i+1). Next we will count if any group is
   partially there upto n, we can count this by taking modulo of n under 
   group size i.e. n%(2i+1). If the last partially included group has 
   size more than half of the original group size then only 1 bits will be
    included in the answer. We can count how many one bits are there.
*/

#include<bits/stdc++.h>
typedef long long lli;
using namespace std;
lli mod=1e9+7;

int solve(int A)
{
    int sz=2;               // size of group
    int ans=0;
    for(int i=0;i<31;i++)
    {
        if((1<<i) > A)      // break if no bits are there
        {
            break;
        }
        long long int k=A/sz;// count of perfectly included groups
        long long int temp = (k*(sz/2))%mod; // count of 1s
        ans = (ans+temp)%mod;
        k=A%sz;             // amount of partial group
        int p=sz/2;
        if(k>=p)
        {
            k=k-p+1;        // count of 1s in partial group
            ans = (ans+k)%mod;
        }
        sz=sz*2;            // increase size by 2 for next bit
    }
    return ans%mod;
}

void solve()
{
    int n=5;
    int ans=solve(n);
    cout<<ans<<endl;
}

int main()
{
    lli t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0; 
}





/*Bit Magic I

Time-Limit: 1 sec Score: 1.00/100
Difficulty :* 
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

A state with n flags of ON or OFF can be represented by a sequence of bits
 where 0,1,...,n−1 -th flag corresponds to 1 (ON) or 0 (OFF). The state can
  be managed by the corresponding decimal integer because the sequence of 
  bits is a binary representation where each bit is 0 or 1.

Given a sequence of bits with 60 flags that represent a state, perform the 
following operations. Note that each flag of the bits is initialized by OFF.

test(i): Print 1 if ith flag is ON, otherwise 0.
set(i): Set ith flag to ON
clear(i): Set ith flag to OFF
flip(i): Inverse ith flag
all: Print 1 if all flags are ON, otherwise 0
any: Print 1 if at least one flag is ON, otherwise 0
none: Print 1 if all flags are OFF, otherwise 0
count: Print the number of ON flags
val: Print the decimal value of the state

Input Format

The input is given in the following format.

q
query1
query2
:
queryq
Each query queryj is given in the following format: either only t  or  t  i  , 
where t is the query type.

The first digit t = 1, 2, 3 ,...,8, 9 represents the operation test(i), set(i),
 clear(i), flip(i), all, any, none, count or val respectively.


Output Format

Print the result in a line for each test, all, any, none, count and val operation.


Constraints

1 ≤ q ≤ 200,000
0 ≤ i < 60

Sample Input 1

14
2 0
2 1
2 2
3 1
1 0
1 1
1 2
1 3
4 3
5
6
7
8
9

Sample Output 1

1
0
1
0
0
1
0
3
13*/

void solve(){

ll num=0;
ll q;
cin>>q;
while(q--){
    int t;
   cin>>t;
   if(t==1){
      int i;
      cin>>i;
      cout<<((num>>i)&1)<<nl;  
   }else if(t==2){
       
       int i;
       cin>>i;
       
      num|=(1ll<<i);
       
   }else if(t==3){
       
       int i;
       cin>>i;
       
      num&=(~(1ll<<i));
       
       
   }else if(t==4){
       
       int i;
       cin>>i;
       
      num^=(1ll<<i);
       
   }else if(t==5){
       
       if(__builtin_popcountll(num)==60) cout<<1<<nl;
       else cout<<0<<nl;
   }else if(t==6){
       if(__builtin_popcountll(num)>=1) cout<<1<<nl;
       else cout<<0<<nl;
       
   }else if(t==7){
       if(__builtin_popcountll(num)==0) cout<<1<<nl;
       else cout<<0<<nl;
       
   }else if(t==8){
     
     
     cout<<__builtin_popcountll(num)<<nl;
   }else if(t==9){
       cout<<num<<nl;
      
   }    
}
	
}
//approach//

/*We can represent the state of the flags as a binary number, where each bit of 
the number corresponds to the state of a flag. To perform the required operations, 
we can use the following bit manipulation operations:

To test if the i-th flag is ON, we can use the bitwise AND operation with a mask that
has only the i-th bit set to 1. If the result is non-zero, then the i-th flag is ON, 
otherwise it is OFF.

To set the i-th flag to ON, we can use the bitwise OR operation with a mask that has 
only the i-th bit set to 1.

To set the i-th flag to OFF, we can use the bitwise AND operation with a mask that 
has only the i-th bit set to 0.

To flip the state of the i-th flag, we can use the bitwise XOR operation with 
a mask that has only the i-th bit set to 1.

To check if all flags are ON, we can use the __builtin_popcountll() function, 
which returns the number of 1 bits in a 64-bit integer. If the result is equal
 to 60, then all flags are ON.

To check if at least one flag is ON, we can use the __builtin_popcountll() function 
again. If the result is greater than or equal to 1, then at least one flag is ON.

To check if all flags are OFF, we can use the __builtin_popcountll() function again. 
If the result is equal to 0, then all flags are OFF.

To count the number of ON flags, we can use the __builtin_popcountll() function again.

To get the decimal value of the state, we can simply print the value of the
 binary number as a decimal number.

Time Complexity:
The time complexity of the solution is O(q), where q is the number of queries.
 This is because each query requires only constant time operations.

*/

/*Bit Magic II

Time-Limit: 3 sec Score: 1.00/100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

Given an integer t - the number of test cases. For each test case, 
read an integer n and answer the following 6 queries in the given order in a new line -:

Output the 64 bit binary representation of number n.
Output the position of the most significant bit ( MSB ) or the leftmost
 set bit of n ( 0- indexed ). If n=0, output -1.
Output the position of the rightmost set bit of n ( 0- indexed ). If n=0, output -1.
Output 1 if n  is a power of 2 i.e n==2X , x > 0, else output 0.
Output the biggest power of 2, that is the divisor of n. i.e biggest 2K 
such that n%2K == 0, k ≥ 0. If n=0, output -1. 
Output the smallest power of 2, which is not smaller than n, i.e 
smallest 2K such that 2K ≥ n, k>0.

Input Format

First-line contains an integer t -  number of test cases.

Each next t lines contain an integer n.


Output Format

For each test case, answer the 6 queries in the given order in a new line.


Constraints

1 ≤ t ≤ 105
- 1018 ≤ n ≤ 1018 

Sample Input 1

10
-3
-2
-1
0
1
2
3
4
5
6

Sample Output 1

1111111111111111111111111111111111111111111111111111111111111101
63
0
0
1
2
1111111111111111111111111111111111111111111111111111111111111110
63
1
0
2
2
1111111111111111111111111111111111111111111111111111111111111111
63
0
0
1
2
0000000000000000000000000000000000000000000000000000000000000000
-1
-1
0
-1
2
0000000000000000000000000000000000000000000000000000000000000001
0
0
0
1
2
0000000000000000000000000000000000000000000000000000000000000010
1
1
1
2
2
0000000000000000000000000000000000000000000000000000000000000011
1
0
0
1
4
0000000000000000000000000000000000000000000000000000000000000100
2
2
1
4
4
0000000000000000000000000000000000000000000000000000000000000101
2
0
0
1
8
0000000000000000000000000000000000000000000000000000000000000110
2
1
0
2
8*/

void solve(){
    
    ll n;
    cin>>n;
    
    for(int i=63;i>=0;i--){
        
        if(n&(1ll<<i))cout<<1;
        else cout<<0;  
    }
    cout<<nl;
    if(n==0)cout<<-1<<nl;
    else{ll leading_zeros=__builtin_clzll(n);
    cout<<63-leading_zeros<<nl;}
    
    if(n==0)cout<<-1<<nl;
    else{ll trailing_zeros=__builtin_ctzll(n);
    cout<<trailing_zeros<<nl;}
    
    if(n==1)cout<<0<<nl;
    else{
        
        ll powr_two_or_not=__builtin_popcountll(n);
        
        if(powr_two_or_not==1)cout<<1<<nl;
        else cout<<0<<nl;
    }
    
    if(n==0)cout<<-1<<nl;
    else{
        cout<<(1ll<<__builtin_ctzll(n))<<nl;
    }
    
    if(n<=1)cout<<2<<nl;
    else{
        cout<<(1ll<<(64-__builtin_clzll(n-1)))<<nl;
    }
}


/*Bilkul ricks nhi lena ka

Time-Limit: 1 sec Score: 1.00/100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

Baburao Ganpatrao Apte a.k.a “Babu Bhaiya” created a new strong password 
for his locker, to save his money from Raju, who is promising to double
 his money in 21 days! :P

The new password z is a positive integer of at most 19 digits. Babu Bhaiya is
 bad at remembering passwords and doesn't want to take risks ( as he says “ 
 bilkul ricks nhi lena ka ” ), so he divided his integer password into 2 positive 
 integers a and b, such that z = a + b, and wrote down a&b and a|b values in his diary.

As expected, he forgot his password after a few days. Help him to retrieve his password z. 

It is given that a&b should be a sub-mask of a|b.


Input Format

The input contains a single line having a&b and a|b values.


Output Format

Output a single integer z, the password. 


Constraints

z is a positive integer of at most 19 digits and less than LLONG_MAX.
a&b should be a sub-mask of a|b.

Sample Input 1

1 7

Sample Output 1

8

Note

Explanation: Since  a&b =1 and a|b = 7, then a=3 and b=5, therefore z = a + b = 8.*/

#include <bits/stdc++.h>
using namespace std;

#define ll int64_t
#define endl '\n'

void solve() {
    ll x, y;
    cin >> x >> y;
    cout << x + y << endl;
}
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    // int i = 1;
    // cin >> t;
    while (t--) {
        // cout << "Case #" << i << ": ";
        solve();
        // i++;
    }
    return 0;
}

/*approach
Can you retrieve a and b values from a&b and a|b values?   


Try to write a&b and a|b values for some a and b, and try to observe some relationship b/w them.


Identity:  a&b + a|b = a + b ( Observation )

using above identity, we get z = a&b + a|b.

Time Complexity: O(1)


*/




/*XOR and AND

Time-Limit: 3 sec Score: 1.00/100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

Given an array of N integers, find the sum of XOR of all pairs of 
numbers in the array, sum of XOR of all subset of numbers in the array, 
sum of AND of all pairs of numbers in the array, sum of AND of all subset 
of numbers in the array. Calculate it %1000000007. 
For pair you should select two index i, j such that i<j.


Input Format

The first line of the input contains a single integer T denoting the 
number of test cases, (1<=T<=100).

The first line of each test case contains a single integer N, (2<=N<=100000).

The second line contains N space-separated integers A1,A2,…,AN, (1<=Ai<=10^9).

Sum of N over all test cases does not exceed 10^6.


Output Format

For each test case output, 4 space-separated integers in a new line in the 
order the sum of XOR of all pairs of numbers in the array, sum of XOR of 
all subset of numbers in the array, sum of AND of all pairs of numbers in 
the array, sum of AND of all subset of numbers in the array. Since these n
umbers may be very large, compute them modulo 1000000007 (10^9+7)


Sample Input 1

6
5
1 2 3 4 5
5
1 1 2 3 5
3
1 2 3
4
1 2 2 4
10
989098 987656790 989098765 234543 3456543 234567543 1234567 5678 56789 8909876
10
123 1234543 2345 6776 8787 8765467 234567 98765444 1234 4561

Sample Output 1

42 112 9 25
32 112 8 25
6 12 3 9
23 56 2 11
378768679 755809533 328561458 769714220
962949537 271171227 9132543 118419489

Note

1st test case: all pairs and corresponding XOR and AND value:
(1,2) - 3, 0
(1,3) - 2, 1
(1,4) - 5, 0
(1,5) - 4, 1
(2,3) - 1, 2
(2,4) - 6, 0
(2,5) - 7, 0
(3,4) - 7, 0
(3,5) - 6, 1
(4,5) - 1, 4
Sum of XOR of all pairs = 42, Sum of AND of all pairs = 9

3rd test case: all subset XOR and AND values:
(1) - 1, 1
(1,2) - 3, 0
(1,3) - 2, 1
(2,3) - 1, 2
(2) - 2, 2
(3) - 3, 3
(1,2,3) - 0, 0
Sum of XOR of all subset =  12, Sum of AND of all subset = 9 */


typedef long long ll;
#define mod 1000000007
const ll N = 100001;
const ll BITS = 31;

ll addMod(ll a,ll b){
   a = a+b;
   if(a>=mod)
       a-=mod;
   return a;
}
ll nc2(ll x){
   return ((x*(x-1))/2)%mod;
}
signed main()
{
   ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
   ll powerOfTwo[N];
   powerOfTwo[0] = 1;
   for(ll i=1;i<N;i++){
       powerOfTwo[i] = addMod(powerOfTwo[i-1],powerOfTwo[i-1]);
   }

   ll testCase;
   cin>>testCase;
   while(testCase--){
       ll n;
       cin>>n;
       ll arr[n];
       for(ll i=0;i<n;i++)
           cin>>arr[i];

       ll sumPairXor = 0;
       ll sumSubsetXor = 0;
       ll sumPairAnd = 0;
       ll sumSubsetAnd = 0;

       for(ll i=0;i<BITS;i++){
           ll cnt = 0;
           for(ll j=0;j<n;j++){
               if(arr[j]&(1LL<<i))  
                   cnt++;
           }

           sumPairXor = addMod(sumPairXor , (1LL<<i)*cnt%mod*(n-cnt)%mod);
           if(cnt)
               sumSubsetXor = addMod(sumSubsetXor, (1LL<<i)*powerOfTwo[n-1]%mod);

           sumPairAnd = addMod(sumPairAnd, (1LL<<i)*nc2(cnt)%mod);
           sumSubsetAnd = addMod(sumSubsetAnd, (1LL<<i)*(powerOfTwo[cnt]-1+mod)%mod);

       }
       cout<<sumPairXor<<" "<<sumSubsetXor<<" "<<sumPairAnd<<" "<<sumSubsetAnd<<"\n";
   }

}

/*approach
Try to calculate the contribution of every bit of a number. In how many possible pairs or
 subset the bit is set. If ith bit is set in 'x' possible pair or subset then the 
 contribution of this bit in the total answer will be x*(1LL<<i).

So find the contribution of every bit, then sum it.


Property of XOR, 1^1 = 0, 1^1^1 = 1, 1^1^1^1 = 0, 1^1^1^1^1 = 1.

For ith bit to be set while taking XOR, ith bit should be set an odd number of times. 
So when you take a pair of numbers then in one of the numbers the ith bit should be
 set and in the other number it should be unset. So calculate in how many numbers 
 ith bit is set (cnt), then the total number of pairs with ith bit set in the XOR 
 of the pair is cnt*(n-cnt).

So total contribution if ith bit = cnt(n-cnt)(1LL<<i).

For AND, the bit should be set in both the numbers. So if ith bit is set in 'cnt'
 numbers, then the total possible pair in which ith bit will be set after doing 
 AND is cntC2 = (cnt(cnt-1))/2, choosing any two number with ith bit set. 
 So contribution of ith bit = (1LL<<i) * ((cnt(cnt-1))/2).

Now try to solve for all the subset.


If ith bit is set in 'cnt' numbers, then choosing 1 or 3 or 5..... basically
 odd numbers from cnt in the subset and any number from the 'n-cnt' in the subset,
  then after doing XOR of the subset we will have ith bit set. So total number of 
  subset which will have ith bit set = (cntC1 + cntC3 + cntC5 + ….)) * (2^(n-cnt)).
   You can simplify the summation of (cntC1 + cntC3 + cntC5 + ….)) = 2^(cnt-1), 
   if cnt>0 otherwise 0. So total contribution of ith bit  = (1LL<<i) * 2^(n-1),
    if cnt>0.

For AND, the ith bit is set if and only if all the numbers in the subset have
 ith bit set. So the total number of subset with ith bit set after doing AND 
 of all the numbers in the subset = (2^cnt)-1. So total contribution of ith
  bit  = (1LL<<i) * ((2^cnt)-1).

Take % properly and check for overflow.


*/


/*Max AND Subsequences

Time-Limit: 2 sec Score: 1.00/100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

Given an array A of N positive integers, find the maximum of bitwise ANDs of all subsequences of A with length equal to X.


Input Format

The first line of the input contains a single integer T denoting the number of test cases, (1<=T<=100).

The first line of each test case contains two space-separated integer N, X, (2<=N<=100000), (1<=X<=N).

The second line contains N space-separated integers A1,A2,…,AN, (1<=Ai<=10^9).

 

Sum of N over all test cases does not exceed 10^6.


Output Format

For each test case print the maximum of bitwise ANDs of all subsequences of A with length equal to X.


Sample Input 1

6
5 2
1 2 3 4 5
5 3
2 4 4 2 4
3 2
1 2 3
4 3
1 2 2 4
10 3
989098 987656790 989098765 234543 3456543 234567543 1234567 5678 56789 8909876
10 2
123 1234543 2345 6776 8787 8765467 234567 98765444 1234 4561

Sample Output 1

4
4
2
0
147862020
8454144

Note

1st test case - all subsequence of length X and AND value:
(1,2) - 0
(1,3) - 1
(1,4) - 0
(1,5) - 1
(2,3) - 2
(2,4) - 0
(2,5) - 0
(3,4) - 0
(3,5) - 1
(4,5) - 4
Maximum AND value of all subsequences with length X = 4 */

signed main()
{
   ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

   int testCase;
   cin>>testCase;
   while(testCase--){
       int n,x;
       cin>>n>>x;
       vector < int > arr(n);
       for(int i=0;i<n;i++)
           cin>>arr[i];
       int ans = 0;
       for(int i=29;i>=0;i--){
           vector < int > elementBitSet;
           for(auto v:arr){
               if(v&(1LL<<i))
                   elementBitSet.push_back(v);
           }
           if(elementBitSet.size()>=x){
               ans+=(1LL<<i);
               arr = elementBitSet;
           }
       }
       cout<<ans<<"\n";
   }

}

/*approach

Check whether a subsequence of length X with the most significant bit 
set is present or not. If it is present then it is always optimal to consider
that subsequence as 2^(highestBit set) > (2^0+2^1+2^2......2^(highestBit-1)).


Take all the numbers with highestBit set if the count is >=X. 
Add 1<<(highestBit) in your answer. Now your problem reduces to the array 
of elements with highestBit set and highestBit-1 be the next 
bit to be considered. If the subsequence of length X is not present 
then calculate the answer for the same array with highestBit-1 as 
the new highestBit possible.*/


/*Bitwise Operations

Time-Limit: 2 sec Score: 1.00/100
Difficulty : ***
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

Given an array of N positive integers. You can perform this operation any number 
of times, choose two indices x and y. If array[x] = a and array[y] = b, 
then after the operation

1. array[x] = a OR b, array[y] = a AND b.

Perform the operations optimally such that ∑array[i]*array[i] for all 1<=i<=n is maximum. 
Print the largest sum of squares you can get after performing the 
operations greater than equal to zero times.


Input Format

The first line of the input contains a single integer T denoting the number
 of test cases, (1<=T<=100).

The first line of each test case contains a single integer N, (2<=N<=100000).

The second line contains N space-separated integers A1,A2,…,AN, (1<=Ai<=10^6).

Sum of N over all test cases does not exceed 10^6.


Output Format

For each test case output a single integer representing the largest possible 
sum of squares that can be achieved after several (possibly zero) operations.


Sample Input 1

5
2
2 5
3
1 2 3
5
1 2 3 4 5
1
1234
10
2 5 234 3454 3423 34545 65433 654345 9876 76567

Sample Output 1

49
18
99
1522756
448865876262*/


signed main()
{
   ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

   int testcases;
   cin>>testcases;
   while(testcases--){

       vector < ll > bit[20];
       ll n;
       cin>>n;
       vector < ll > arr(n);
       for(int i=0;i<n;i++)cin>>arr[i];
       vector < ll > done(n+1,0);
       for(int i=0;i<n;i++){
           for(int j=0;j<20;j++){
               if(arr[i]&(1<<j))
                   bit[j].push_back(i);  
                   // push in bit[i] all the index which have ith bit on.
           }
       }
       ll k = 19;  
       while(k>=0){   // Greedily increasing the value of every number,
       // starting from the most significant digit
           if(bit[k].size()){
               ll x = bit[k][bit[k].size()-1];
                
// taking a element which may or may not have the kth bit set as it might be changed.
               
               bit[k].pop_back();
               if(done[x] or !((1<<k)&arr[x]))
               
                // if it is already done or bit is not set then continue
                   continue;
               done[x] = 1;  
               
               // trying to increase the value as much as I can using the lower bits.
               
               for(int i = 0;i<k+1;i++){
                   if(arr[x]&(1<<i)) 
                   // it bit is already set then continue
                   	
                   	
                       continue;
                   while(bit[i].size()){  
 // find a index which has this bet set, then apply the operation to increase the value of x.
                      
                       ll y = bit[i][bit[i].size()-1];
                       bit[i].pop_back();
                       if(done[y] or !((1<<i)&arr[y]))
                           continue;

                       ll temp = arr[y];
                       arr[y] = arr[y]&arr[x]; 
                       
             // because of this operation the set bit of arr[y] can be unset.
                       arr[x]|=temp;
                       break;
                   }
               }
           }
           else
               k--;

       }
       ll ans=0;
       for(int i=0;i<n;i++)ans+=arr[i]*arr[i];
       cout<<ans<<"\n";
   }
}



/*approach

Observe the operations, after the operation, a + b = a XOR b + 2*(a AND b)
as well as a + b = a OR b + a AND b. So the sum is constant even
 after performing the operation.


If the sum is constant and you have to maximize the sum of squares, 
then it is always optimal to increase the largest value as much as you can, 
then increase the 2nd largest value and so on.*/


/*XOR AND OR Query

Time-Limit: 4 sec Score: 1.00/100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

Given an array of N integers and Q queries. In each query, 
you are given two parameters L and R; you have to find the following:

1. Smallest integer X1 such that the value of 
(AL XOR X1) + (AL+1 XOR X1) + ... + (AR XOR X1) is maximum possible.

2. Smallest integer X2 such that the value of 
(AL OR X2) + (AL+1 OR X2) + ... + (AR OR X2) is maximum possible.

3. Smallest integer X3 such that the value of 
(AL AND X3) + (AL+1 AND X3) + ... + (AR AND X3) is maximum possible.

Range of X1, X2, X3 allowed → 0 <= X1, X2, X3 < 2^31.

Print the sum of X1, X2, X3 for each query in a newline.


Input Format

The first line of the input contains a single integer
 T denoting the number of test cases, (1<=T<=100).

The first line of each test case contains a single integer N, (2<=N<=100000).

The second line contains N space-separated 
integers A1,A2,…,AN, (1<=Ai<=10^9).

The third line contains an integer Q, (1<=Q<=10^5).

The next Q lines contain two space-separated integers L, R (1<=L<=R<=N).

Sum of Q over all test cases does not exceed 10^6.


Output Format

For each query print the value of X1  + X2 + X3  in a new line.

 


Sample Input 1

5
5
1 2 3 4 5
5
1 5
2 5
3 4
2 4
3 3
3
1 2 2
3
1 2
2 3
1 3
4
1 2 2 4
5
1 2
2 3
3 4
2 4
3 4
10
123 234565 3456765 3456 09888 433534 908767 125698 545676 23456
10
1 4
1 6
1 9
1 10
3 7
3 9
4 7
6 9
4 9
7 9
10
23456 3456 987 8765 3456 34565 9876 654555 234566 87654344
10
1 8
1 6
1 9
1 10
2 7
2 9
4 7
8 9
9 9
7 9

Sample Output 1

4294967300
4294967294
4294967294
4294967299
4294967291
4294967294
4294967292
4294967295
4294967294
4294967292
4294967294
4294967298
4294967294
4298580736
4298580736
4299121201
4299120657
4298857985
4299120753
4295712255
4295106335
4295958639
4295222095
4295618668
4295028860
4295751805
4382781565
4295010408
4295751784
4295002150
4294863804
4294732728
4295640583*/


#include <bits/stdc++.h>
using namespace std;
int prefSum[1000001][31];
int main()
{
   ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
   int testcases;
   cin>>testcases;
   while(testcases--)
   {
       int n,q;
       int i;
       cin>>n;
       for(i=0;i<=n;i++)
         for(int j = 0;j<31;j++)
           prefSum[i][j]=0;
       for(i=1;i<=n;i++)
       {
         int a;
         cin>>a;
         int cnt = 0;
         while(a>0)
         {
           prefSum[i][cnt]=a%2;
           a/=2;
           cnt++;
         }
       }
       for(i=1;i<=n;i++)
       {
         for(int j=0;j<31;j++)
           prefSum[i][j]+=prefSum[i-1][j];
       }
       cin>>q;
       while(q--)
       {
         int l,r;
         cin>>l>>r;
         double total=(r-l+1.0)/(2);
         long long x1 = 0,x2 = 0,x3 = 0;
         for(i=0;i<31;i++)
         {
           int p = prefSum[r][i]-prefSum[l-1][i];
           if(p<total)
             x1+=(1LL<<i);
           if(p!=(r-l+1))
             x2+=(1LL<<i);
           if(p)
             x3+=(1LL<<i);
         }
         long long ans = x1+x2+x3;
         cout<<ans<<"\n";
       }
   }
}


/*approach

Always remember that BIT EXPRESSIONS ARE SUM INDEPENDENT ON EACH BIT.

If ith bit is set in X1,then ith bit will be set in Ai
XOR X1, if ith bit is not set in Aiand,ith
 bit will not be set in Ai XOR X1, if ith bit is set in Ai.So if the 
 ith bit is set in less than (R−L+1)2 numbers then ith bit should be 
 set in X1 otherwise not. So try to think when  ith bit will be set in the X1.
If ith bit is set in 'cntSet' numbers and not set in 'cntNotSet' 
numbers in the range [L,R], then -
ith
 bit is set in X1
then contribution of ith
bit = cntNotSet*(1LL<< i).
ith
bit is not set in X1
 then contribution of ith
bit = cntSet*(1LL<< i).

So according to the value of cntSet and cntNotSet, ith
bit is decided. If cntSet = cntNotSet, then ith
bit should not be set as the minimum value of X1is required.

Value of cntSet and cntNotSet can be found for every query in O(1) using prefix sum.


X2- If the ith bit is set in all the numbers in the range [L, R], then 
it must not be set in the X2. Otherwise, it must be set.
 X3- If the ith
 bit is not set in all the numbers in the range[L, R], then it must 
 not be set in the X3. Otherwise, it must be set.


*/


/*Euler's Phi Function

Time-Limit: 1 sec Score: 1.00/100
Difficulty : **
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

For given integer n, count the totatives of n, that is, the positive
 integers less than or equal to n that are relatively prime to n.


Input Format

The only line of input contains an integer n.


Output Format

Print the answer on a new line.


Constraints

1 ≤ n ≤ 1012


Sample Input 1

6

Sample Output 1

2

Sample Input 2

1000000

Sample Output 2

400000*/

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll n;
    cin >> n;

    ll ans = n;

    for(ll i = 2; i * i <= n; i++) {
        bool is = false;
        while(n % i == 0) {
            n /= i;
            is = true;
        }
        if(is) {
            ans /= i;
            ans *= (i - 1);
        }
    }

    if(n > 1) {
        ans /= n;
        ans *= (n - 1);
    }

    cout << ans << "\n";
}

/*approach
If we know the prime factors, can we use a direct formula for Euler's totient?

We know we can factorize the numbers in O(sqrt(N)).


Since we have to find only one number we use the following formula:


See the Euler Totient function. https://en.wikipedia.org/wiki/Euler%27s_totient_function


*/


/*Paired Cubes

Time-Limit: 2 sec Score: 1.00/100
Difficulty : **
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

You have given n positive integers A1, A2, …, An. Your task is to 
find the number of pairs (i, j) such that Ai * Aj is a cube number.


Input Format

The first line of input contains n - the size of the array.
The second line of input contains n space-separated integers A1, A2, …, An.


Output Format

Print the answer on a new line.


Constraints

1 ≤ n ≤ 105
1 ≤ Ai ≤ 106


Sample Input 1

5
1 2 4 8 27

Sample Output 1

4

Note

The pairs are (1, 8), (2, 4), (1, 27), (8, 27).*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


signed main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);

   int n; cin >> n;

   map <ll,int> M;

   ll ans = 0;

   for(int i = 0; i < n; i++) {
      int x; cin >> x;
      ll norm = 1;
      ll tar = 1;
      for(int j = 2; j * j <= x; j++) {
         int cnt = 0;
         while(x % j == 0) {
            x /= j;
            cnt++;
         }
         cnt %= 3;
         for(int k = 0; k < cnt; k++) {
            norm *= j;
         }
         if(cnt) {
            for(int k = 0; k < 3 - cnt; k++) {
               tar *= j;
            }
         }
      }
      if(x > 1) {
         norm *= x;
         tar *= (x * x);
      }
      ans += M[tar];
      M[norm]++;
   }

   cout << ans << "\n";
}


/*approach

Consider the number n = p1a1  p2a2  p3a3  ….  pmam. Lets define normal 
value of n as norm(n) = p1a1%3  p2a2%3  p3a3%3  ….  pmam%3 and inverse-normal 
of n as invnorm(n) = p1(3 - a1%3) % 3  p2(3 - a2%3) % 3  ….  pm(3 - am%3) % 3. 

Observe that if products of two numbers x and y is a cube number iff norm(x * y) = 1.
 That means all powers of prime numbers in xy is multiple of 3. Again observe
  that norm(n) * invnorm(n) is a cube number.
Using these properties we can conclude that the norm(x) = invnorm(y) OR norm(y) = 
invnorm(x). Se if we maintain the count of norm(x) for all values, to find the 
number of numbers when multiply by y gives a cube number is basically the count 
of invnorm(y) in the count table. 

These mathematical notations might be confusing, but the main motive behind is 
to make all powers of prime numbers to a multiple of 3.

For more clarification, see the editorial code.*/
