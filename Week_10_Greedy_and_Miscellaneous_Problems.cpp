
all materials on the platform is important

/*Question 1

Given n job activities with their start time and finish time. Find
 the maximum number of activities that can be performed without 
 performing two activities at the same time.

Example:

Start = {5, 1, 3, 0, 5, 8}, end = {9, 2, 4, 6, 7, 9}  => 4
Solution Idea:

Method1: The greedy idea to solve this problem is to select the 
jobs which end earliest. So we will sort all the jobs with their 
end-time and greedily pick the jobs if it is not clashing
 with previously picked jobs. */

#include<bits/stdc++.h>
typedef long long lli;
using namespace std;
lli mod=1e9+7;

bool comp(pair<lli,lli> &a, pair<lli,lli> &b)
{
    return a.second<b.second;
}

int maxjobs(vector<pair<lli,lli> > &v)
{
    lli n=v.size(),count=0;
    lli prev_end=INT_MIN;
    for(lli i=0;i<n;i++)
    {
        if(v[i].first>=prev_end)
        {
            count++;
            prev_end=v[i].second;
        }
    }
    return count;
}

void solve()
{
    lli n;
    cin>>n;
    vector<pair<lli,lli> > v(n);
    for(lli i=0;i<n;i++)
    {
        lli start,end;
        cin>>start>>end;
        v[i] = {start,end};
    }
    sort(v.begin(),v.end(),comp);
    lli ans = maxjobs(v);
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

Given lengths of n ropes, we need to join them and make a single rope.
 Joining two ropes will make a single rope of length equal to the sum of
  both the ropes and also the cost of joining is also equal 
  to the sum of ropes that are joined.

Example:

{4,4,3,2,6} => 43
Solution Idea:

Method1: If we look closely at the problem we find that the length of rope
 which is joined first will contribute to the cost till all the ropes 
 are joined. So we should not join the highest length rope at the first.
  We will pick the minimum two ropes and join them and recursively
perform this operation for rest. For this, we will use
 min priority_queue (minheap).
*/
#include<bits/stdc++.h>
typedef long long lli;
using namespace std;
lli mod=1e9+7;

int min_cost_to_join(vector<lli> &rope)
{
    lli n=rope.size();
    priority_queue<lli,vector<lli>,greater<lli>> q;
    for(lli i=0;i<n;i++)
    {
        q.push(rope[i]);
    }
    lli cost=0;
    while(!q.empty())
    {
        lli x=q.top();
        q.pop();
        if(q.empty())
        {
            break;
        }
        lli y=q.top();
        q.pop();
        cost+= (x+y);
        q.push(x+y);
    }
    return cost;
}

void solve()
{
    lli n;
    cin>>n;
    vector<lli> rope(n);
    for(lli i=0;i<n;i++)
    {
        cin>>rope[i];
    }
    lli ans = min_cost_to_join(rope);
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

Find the maximum value of the sum of arr[i] * i of the given 
array arr when rearrangement is allowed.

Example:

{2, 7, 4, 1} => 31
Solution Idea:

Method1: We need to scale the maximum number by the maximum value
 and the minimum number by the minimum value. So we will just sort 
 the array and count the required sum.


*/
#include<bits/stdc++.h>
typedef long long lli;
using namespace std;
lli mod=1e9+7;

lli maximum_value(vector<lli> &arr)
{
    lli n=arr.size(),ans=0;
    sort(arr.begin(),arr.end());
    for(lli i=0;i<n;i++)
    {
        ans+=(arr[i]*i);
    }
    return ans;
}

void solve()
{
    lli n;
    cin>>n;
    vector<lli> arr(n);
    for(lli i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    lli ans = maximum_value(arr);
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
/* Question 4

Find the minimum product of a subset of numbers of an array.

Example:

{0, -1, 2, 1, -2} => -4
Solution Idea:

Method1: If there are even numbers of negative numbers and no zeros,
 the result is the product of all except the largest valued negative
  number. If there are an odd number of negative numbers and no zeros, 
  the result is simply the product of all. If there are zeros and positive,
   no negative, the result is 0. The exceptional case is when there
    is no negative number and all other elements positive then our 
    result should be the first minimum positive number.
*/

lli minProductSubset(vector<lli> &a, lli n)
{
    if (n == 1)
        return a[0];
    lli max_neg = INT_MIN;
    lli min_pos = INT_MAX;
    lli count_neg = 0, count_zero = 0;
    lli prod = 1;
    for (lli i = 0; i < n; i++) {
        if (a[i] == 0) {
            count_zero++;
            continue;
        }
        if (a[i] < 0) {
            count_neg++;
            max_neg = max(max_neg, a[i]);
        }
        if (a[i] > 0) {
            min_pos = min(min_pos, a[i]);
        }
        prod = prod * a[i];
    }
    if (count_zero == n || (count_neg == 0 && count_zero > 0))
        return 0;
    if (count_neg == 0)
        return min_pos;
    if (!(count_neg & 1) && count_neg != 0) {
        prod = prod / max_neg;
    }
    return prod;
}
/*Question 5

Find the maximum sum of the array after performing k negations of elements.

Example:

{5, -2, -4, 1, -1}, k=2 => 11
{2, -3, 0, 4, 1}, k=3 => 10
Solution Idea:

Method1: We need to negate the minimum numbers in the current array 
and this operation is performed k times or till the minimum number is
 zero. We will use a priority queue for finding the minimum number
  in the array.
*/
#include<bits/stdc++.h>
typedef long long lli;
using namespace std;
lli mod=1e9+7;

lli maximum_sum(vector<lli> &arr,lli k)
{
    lli n=arr.size(),ans=0;
    priority_queue<lli, vector<lli>, greater<lli> >q;
    for(lli i=0;i<n;i++)
    {
        q.push(arr[i]);
    }
    for(lli i=0;i<k;i++)
    {
        lli p = q.top();
        q.pop();
        if(p==0)
            break;
        p = -p;
        q.push(p);
    }
    while(!q.empty())
    {
        ans+=q.top();
        q.pop();
    }
    return ans;
}

void solve()
{
    lli n,k;
    cin>>n>>k;
    vector<lli> arr(n);
    for(lli i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    lli ans = maximum_sum(arr,k);
    cout<<ans<<endl;
}

signed main()
{
    lli t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0; 
}  



/*Find the minimum number of operations that can be performed on 
elements of the array such that the gcd of the array becomes equal 
or multiple of k. In one operation you can pick any element and
 increment or decrement its value by 1.

Example:

{2, 3, 4} , k=4 => 3
{5, 3, 7} , k=3 => 2
Solution Idea:

Method1: We need to make each element equal to k or the nearest 
multiple of k in order to make gcd multiple of k. For each element
 in the array, we will find remainder by dividing it with k and 
 adding the number of operations as remainder or (k-remainder) based 
 on minimum value. Since these are the number of
  decrements or increments required.
*/
#include<bits/stdc++.h>
typedef long long lli;
using namespace std;
lli mod=1e9+7;

lli minimum_operation(vector<lli> &arr,lli k)
{
    lli n=arr.size(),ans=0;
    for(lli i=0;i<n;i++)
    {
        if(arr[i]!=1 and arr[i]>k)
        {
            ans+=min(arr[i]%k,k-arr[i]%k);
        }
        else ans+=(k-arr[i]);
    }
    return ans;
}

void solve()
{
    lli n,k;
    cin>>n>>k;
    vector<lli> arr(n);
    for(lli i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    lli ans = minimum_operation(arr,k);
    cout<<ans<<endl;
}

signed main()
{
    lli t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0; 
}
/*Question 2 ( Very Imp )

Given the stock prices of n consecutive days. You are allowed to
 perform as many transactions as you want. Find the maximum profit 
 that can be obtained by buying and selling the stocks.

Example:

{1,2,3,4} => 3
{5,4,3,2} => 0
{4,2,7,1,5} => 9
Solution Idea:

Method1: We will do transactions between consecutive local minimum 
and local maximum. We will buy stocks at local minimum and sell the
 stocks at local maximum. This is the best possible way to get
  maximum profit.
*/
#include<bits/stdc++.h>
typedef long long lli;
using namespace std;
lli mod=1e9+7;

lli max_profit(vector<lli>& prices) {
    lli maxprofit = 0;
    for (lli i = 1; i < prices.size(); i++) {
        if (prices[i] > prices[i - 1])
            maxprofit += prices[i] - prices[i - 1];
    }
    return maxprofit;
}

void solve()
{
    lli n;
    cin>>n;
    vector<lli> arr(n);
    for(lli i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    lli ans = max_profit(arr);
    cout<<ans<<endl;
}

signed main()
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

Given a number in the form of a string and an integer k. Remove 
k digits from string to make it as smallest as possible.

Example:

“20” , k=1 => “0”
“1313562” , k=2 => “11352”
Solution Idea:

Method1: If there are two consecutive digits in which the first one is
 bigger than the second then it is optimal to remove the first digit.
  We will remove all the digits till k is positive if it is greater 
  than the next digit. So our answer string should contain the digits
   in increasing order. We will use the stack for this problem.
*/
string remove_k_digits(string num, int k) {
    int n=num.length();
    string ans;
    stack<char> res;
    int i;
    for(i=0;i<n;i++)
    {
        while(!res.empty() and res.top()>num[i] and k>0)
        {
            k--;
            res.pop();
        }
        res.push(num[i]);
    }
    while(!res.empty())
    {
        ans.push_back(res.top());
        res.pop();
    }
    reverse(ans.begin(),ans.end());
    while(k--)
        ans.pop_back();
    i=0;
    while(i<n and ans[i]=='0')
        i++;
    ans = ans.substr(i);
    if(ans.empty())
        return "0";
    return ans;
}
/*Question 4

Given a binary array of zeros and ones and an integer k. Find the number
 of flip operations that can be performed on k consecutive elements 
 of the array such that the final array does not contain 0 or
  else return -1.

Example:

{0,1,0,1,1,0} , k=2 => -1
{0,1,0,1,1,0} , k=1 => 3
Solution Idea:

Method1: We will traverse from left to right and if we found 0
 then we need to flip this digit. Consider changing of k consecutive
  digits as an event then if any element is 0 it should fall under 
  an odd number of overlapping events else if any element is 1 it 
  should fall under an even number of overlapping events. For this,
   we will use a queue to store the ending points of events.
*/
int minimum_flips(vector<int>& A, int K) {
    queue<int> flips;
    int res=0;
    for (auto i = 0; i < A.size(); ++i) {
        if (A[i] != (flips.size() % 2 ? 0 : 1)) {
            ++res;
            flips.push(i + K - 1);
        }
        if (!flips.empty() && flips.front() <= i) flips.pop();
    }
    return flips.empty() ? res : -1;
}
/*Question 5

Given two integers x and y. We need to find the minimum number of 
operations required to convert x to y. We can perform two operations
 such as multiplying the number by 2 or subtracting the number by 1.

Example:

x = 4, y = 5 => 3
x = 4, y = 9 => 5
Solution Idea:

Method1: We will move backwards i.e. convert y to x and operations 
are dividing by 2 or adding 1. 
*/
int solve(int X, int Y) {
    if(X>=Y)
        return X-Y;
    int ans=0;
    int temp=Y;
    while(temp>X)
    {
        if(temp%2)
            temp++;
        else temp/=2;
        ans++;
    }
    ans+=X-temp;
    return ans;  
}


/*Minimum Operation Conversion ⭐

Time-Limit: 5 sec Score: 75.00/100
Difficulty : ***
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

You are given a number X, you can perform two operations:

Double: Multiply the number on the display by 2, or;
Decrement: Subtract 1 from the number on the display.
Return the minimum number of operations needed to convert number X to Y.


Input Format

The first line contains an integer T (number of test cases), 1 ≤ T ≤ 10^6.

The next T lines contain 2 space-separated integers X, Y where 1 ≤ X,Y ≤ 10^18.


Output Format

For each test case print the minimum number of operations required in a new line.


Constraints

1 ≤ T ≤ 10^6.
1 ≤ X,Y ≤ 10^18

Sample Input 1

3
10 15
21 14
10 22

Sample Output 1

4
7
7

Note

TEST CASE 1: X=10 Y=15

MOVES : 10 → 9 → 8 → 16 → 15     #Moves = 4
 

TEST CASE 2: X=21 Y =14

MOVES : 21 → 20 → 19 → 18 → 17 → 16 → 15 → 14    # moves = 7
 

TEST CASE 3: X=10 Y=22

MOVES : 10 → 9 → 8 → 7 → 6 → 12 → 11 → 22 # moves = 7*/


void solve(){
    
    ll x,y;
    cin>>x>>y;
    
    ll steps_cnt=0;
    
    // if(x>y){
        
    //  //   steps_cnt=x-y;
    //     cout<<x-y<<nl;
    //     return;
    // }
    
    while(y){
        
        
        if(y<x){
        
       steps_cnt+=x-y;
       // cout<<x-y<<nl;
       y=x;
        
    }
         if(y==x){
             
              
             // return;
             break;
         }
        
       if(y%2==0){
           steps_cnt++;
           y=y/2;
           
       } else if(y%2==1){
           steps_cnt++;
           y=y+1;
           
           
       }
       
    }
    
   cout<<steps_cnt<<nl;

}

/*approach
The greedy approach to this problem would be to consider how to make x
 from y (instead of y from x ). So the moves become y → y/2 and y → y+1.

This is due to the fact that we always greedily divide by two. 

Consider 2 scenarios : 

For y = even, then if we perform 2 additions and one division, we could 
instead perform one division and one addition for less operations 
[(Y+2) / 2 vs Y/2 + 1].

y → y+1 → y+2 → (y+2)/2= y/2+1

y → y/2 → y/2+1

For y=odd   then if we perform 3 additions and one division, we could 
instead perform 1 addition, 1 division, and 1 addition for less 
operations [(Y+3) / 2 vs (Y+1) / 2 + 1].

y → y+1 → y+2 →y+3 → (y+3)/2= (y+1)/2+1

y → y+1 →(y+1)/2 → (y+1)/2+1

Clearly, in both cases, we see that dividing by 2  requires a minimum
 number of steps to reach the same value than the addition of 1.*/




/*Permute the Arrays

Time-Limit: 1 sec Score: 100.00/100
Difficulty : *
 Memory: 256 MB Accepted Submissions: 100
Description

There are two arrays of size n, A [a1, a2 … an] and B [b1, b2 … bn]. 
You can permute the elements in both the arrays any way you want.

Your goal is to minimize the sum of the absolute differences between 
corresponding elements of the arrays i.e. sum of |ai-bi| for i from 1 to n.

Find this minimum sum.


Input Format

First line of input contains T, number of test cases.

First line of each test case contains n, size of the arrays.

Second line contains n integers a1, a2 … an .

Third line contians n integers b1, b2 … bn .

 

 


Output Format

For each test case print a single integer in a new line: Minimum sum of
 the absolute differences between corresponding elements of the arrays.


Constraints

T ≤ 10

1 ≤ n ≤ 105

0 ≤ |ai|,|bi| ≤ 106


Sample Input 1

1

3

1 2 1

2 1 1


Sample Output 1

0


Note

Arrange elements in B as [1, 2, 1].

Sum = |1-1| + |2-2| + |1-1| = 0*/


void solve(){
    
    ll n;
    cin>>n;
    arr.resize(n);
    brr.resize(n);
    
  for(ll i=0;i<n;i++){
      
      ll x;
      cin>>x;
      arr[i]=x;
      
  }
  
   for(ll i=0;i<n;i++){
      
      ll y;
      cin>>y;
      brr[i]=y;
      
  }
  
  sort(arr.begin(),arr.end());
  sort(brr.begin(),brr.end()); 
  
  ll ans=0;
  
  for(ll i=0;i<n;i++){
      
      ans+=abs(arr[i]-brr[i]);
      
  }
  
  
  cout<<ans<<nl;
  
}


/*Meet at a Point⭐

Time-Limit: 2 sec Score: 100.00/100
Difficulty : **
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

There are 
n friends in a 2D plane who want to meet at some
  common point. Each of their position is given to you as 
x & y coordinates.

The distance a person covers to go from position (x1,y1)to (x2,y2)
 is the Manhattan distance, i.e., |x1−x2|+|y1−y2|.

They choose the meeting point such that the sum of distances covered 
by each of them to reach it is minimum. Find this minimum sum of distances.


Input Format

The first line of input contains 
T
, the number of test cases.
The first line of each test case contains 
n
.Each of the next n lines contains two integers (x,y).
Output Format

For each test case output one integer: The minimum sum of 
distances covered by them.


Constraints

1≤T≤10

1≤n≤105

0≤x,y≤106

Sample Input 1

1
3
0 4
4 0
2 2

Sample Output 1

8

Note

Point 
(2,2)is the optimal meeting point in this case.*/


void solve(){
    
    
    ll n;
    cin>>n;
    
    xrr.resize(n);
   yrr.resize(n);

    
for(ll i=0;i<n;i++){
    
  ll x,y;
  cin>>x>>y;
  
  xrr[i]=x;
    yrr[i]=y;
}

sort(xrr.begin(),xrr.end());
sort(yrr.begin(),yrr.end());




ll midian_x=xrr[n/2];
ll midian_y=yrr[n/2];

//cout<<midian_x<<"  "<<midian_y<<nl;

ll dist_x=0;
ll dist_y=0;
for(ll i=0;i<n;i++){
    
    dist_x+=abs(midian_x-xrr[i]);
    
    //cout<<dist_x<<nl;
    dist_y+=abs(midian_y-yrr[i]);
    
   // cout<<dist_y<<nl;
}
    
ll ans=dist_x+dist_y;

cout<<ans<<nl;
    
    
    
}



/*Substring Removal ⭐

Time-Limit: 1 sec Score: 1.00/100
Difficulty : ***
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

You are given a string s and two integers x and y. You can perform two types of operations any number of times.

Remove substring "ab" and gain x points.

For example, when removing "ab" from "cabxbae" it becomes "cxbae".

Remove substring "ba" and gain y points.

For example, when removing "ba" from "cabxbae" it becomes "cabxe".

Return the maximum points you can gain after applying the above operations on s.


Input Format

The first line contains an integer T (number of test cases), 1 ≤ T ≤ 10^5.

The next T lines contain a string S and 2 space-separated integers S, X, Y where 1 ≤ X,Y ≤ 10^9, 1 ≤ |S| ≤ 10^6.

Sum of |S| across all test cases ≤ 10^7.


Output Format

For each test case print the maximum point possible in a new line.


Constraints

1 ≤ T ≤ 10^5
1 ≤ X,Y ≤ 10^9
1 ≤ |S| ≤ 10^5.
Sum of |S| across all test cases ≤ 10^6.

Sample Input 1

4
abdsbab 23 50
babababa 45 32
ujaabba 4 5
cxbaeab 17 9

Sample Output 1

73
167
9
26

Sample Input 2

20
ab 7 4
aaba 10 8
baba 6 4
ba 4 8
baabbbb 5 6
aaabab 1 7
babaaba 8 10
b 1 8
abbaaa 2 7
b 5 6
aa 7 4
bbbaa 8 4
bbbba 7 6
babba 8 7
bababbab 3 1
baa 6 9
babbba 3 6
aa 9 2
baababaaba 10 8
bbbbbbaab 3 6

Sample Output 2

7
10
10
8
11
8
30
0
14
0
0
8
6
15
9
9
12
0
38
12

Note

For the first sample input:

TEST CASE 1: 

S = abdsbab x=23  y=50

Remove “ba”  Points = 50 S =  “abdsb”.
Remove “ab”  Points = 50+23 = 73 S =  “dsb”.
Nothing else to remove ,  so total points is 73.

TEST CASE 2: 

S = babababa x=45  y=32

Remove “ab”  Points = 45 S =  “bababa”.
Remove “ab”  Points = 45+45 = 90 S =  “baba”
      3.   Remove “ab”  Points = 90+45 = 135 S =  “ba”

      4.   Remove “ba”  Points = 135+32 = 167 S = “ ”

Nothing else to remove ,  so total points is 167.

TEST CASE 3. 

S = ujaabba x=4  y=5

Remove “ba”  Points = 5 S =  “ujaab”.
Remove “ab”  Points = 5+4 = 9 S =  “uja”
      

Nothing else to remove ,  so total points is 9.

TEST CASE 4. 

S = cxbaeab x=17  y=9

Remove “ab”  Points = 17 S =  “cxbae”.
Remove “ba”  Points = 17+9 = 26 S =  “cxe”
Nothing else to remove ,  so total points is 26*/

void solve(){
    
string s;
ll x,y;

cin>>s>>x>>y;
stack<char>st;

string ab="ab";
string ba="ba";


if(y>x){
    swap(x,y);
    swap(ab,ba);
}

ll ans=0;
for(ll i=0;i<s.size();i++){
if(!st.empty()&&st.top()==ab[0]&&s[i]==ab[1]){


st.pop();
ans+=x;
    
}
else {st.push(s[i]);}

}
string reduced;

while(!st.empty()){
    reduced+=st.top();
    
    st.pop();
    
}

reverse(reduced.begin(),reduced.end());

for(ll i=0;i<reduced.size();i++){
    
    if(!st.empty()&&st.top()==ba[0]&&reduced[i]==ba[1]){
        
        st.pop();
        ans+=y;
        
    }else{
        st.push(reduced[i]);
    }
    
}

cout<<ans<<nl;

}


/*Make it smooth ⭐

Time-Limit: 1 sec Score: 50.00/100
Difficulty : *
 Memory: 256 MB Accepted Submissions: 100
Description

You are given an array A of size N. In one operation you can select
 any non-decreasing subarray and increment all the elements in the 
 subarray by one. Your goal is to make the whole array
  non-decreasing in minimum operations.

 


Input Format

First line of input contains T, number of test cases.

First line of each test case contains n.

Next line contains n integers of array A.

 


Output Format

For each test case print a single integer in a new line: 
Minimum number of operations.


Constraints

T ≤ 10

1 ≤ n ≤ 105

0 ≤ Ai ≤ 109


Sample Input 1

2

4

5 3 2 5

3

1 1 1


Sample Output 1

3

0*/

vector<ll>arr;
void solve(){
    
  ll n;
  cin>>n;
  
  arr.resize(n);
  for(ll i=0;i<n;i++){
      
      ll x;
      cin>>x;
      
      arr[i]=x;
      
  }
  ll ans=0;
  for(ll i=1;i<n;i++){
      
      
      if(arr[i]<arr[i-1]){
          
          ans+=(arr[i-1]-arr[i]);
          
      }
  }
  
  cout<<ans<<nl;
  
  
}

/*Selling cookies ⭐

Time-Limit: 1 sec Score: 1.00/100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Description

A shop makes n types of cookies. Number of cookies of type i is Ci

The shop only sells cookies as a pair. Moreover the two 
cookies in a pair must be of different types.

Your job is to sell as many pairs as possible and find the
 minimum number of cookies that remain at the end.

 

 


Input Format

First line of input contains T, number of test cases.

First line of each test case contains n.

The next line contains n integers, Ci for i from 1 to n.

 


Output Format

For each test case output one integer: Remaining cookies.


Constraints

T ≤ 10

1 ≤ n ≤ 105

1 ≤ Ci ≤ 109


Sample Input 1

1
3
2 1 3

Sample Output 1

0

Sample Input 2

1
3
3 4 5

Sample Output 2

0

Note

Explanation 1:
We can make the following 3 pairs of cookie types : (1,3), (1,3), (2,3)
 resulting in 0 remaining cookies.

Explanation 2:
Let types of cookies be 1, 2, 3 with count 3, 4, 5 respectively. 
Pairs: (1, 3), (1, 2), (1, 3), (2, 3), (2, 3), (2, 3).
0 cookies left behind.*/

void solve(){
    ll n;
    cin>>n;
    arr.resize(n);
    
    ll ans=0;
    for(ll i=0;i<n;i++){
        
        ll x;
        cin>>x;
        arr[i]=x;
        ans+=arr[i];
    }
    
   
   sort(arr.begin(),arr.end());
   
   ans-=arr[n-1];
   
   
   if(arr[n-1]>=ans){
       ans=arr[n-1]-ans;
       
   }else{
       
       
       ans=(ans-arr[n-1])%2;
   }
  
cout<<ans<<nl;

}

/*approach

Each cookie needs to be paired with a different cookie. Consider all possible
 pairs of cookies to get the minimum answer. But this will lead to TLE. 
 Think in a greedy way.


It is observed clearly that it is optimum to remove cookies from the highest
 cookie stack present at every step. Try to merge cookies based on this idea ,
  however again to consider all possible combinations you will get a TLE. Now 
  think of the possibilities of the number of cookies left when all possible 
  pairs are sold. 


The highest cookie stack is removed first. Is it always possible to remove all 
the cookies from the highest cookie stack? No. It is possible only when the number
 of cookies in the highest stack is less than or equal to the sum of all other 
 cookies present. Once the highest stack is reduced to zero, the remaining cookies 
 can be paired in between themselves such that there will be either 0 or 1 cookie left.

But if the number of cookies in the highest stack is more than all other cookies 
present, then all the other cookies will pair with cookies from the highest stack.
 Now remaining cookies in the highest stack cannot be paired anymore, so its answer
  will be the remaining number of cookies in the highest stack.

EXAMPLE RUN : 

1

2 4 6 9

The highest number of cookies is 9 and the sum of all other cookies = 2+4+6=12

So the highest stack can be reduced to zero. So from these 12 cookies, 9 will pair 
with 9 cookies of the highest stack. The remaining 3 cookies can be of any combination
 of cookies of the 3 smaller stacks. They will pair with themselves optimally to 
 leave only 1 cookie unpaired. So the answer is 1.


*/

/*Fast Solving

Time-Limit: 2 sec Score: 1.00/100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Description

There are N problems in a contest and the ith problem has a rating Ri. 
They are posted in an order top to bottom as given in input.

Each problem requires at least 1 minute to solve. You also know that if 
a problem P has a higher rating than a problem just above or just below it, 
then P must take strictly more time to solve than that problem. 

Find the minimum possible time required to solve all the problems.

 


Input Format

First line of input contains T, number of test cases.

First line of each test case contains N.

Second line contains N integers, Ri for i from 1 to N.

 


Output Format

For each test case output one integer: The minimum possible time in
 which all problems could be solved.


Constraints

T ≤ 10

1 ≤ n ≤ 105

1 ≤ Ri ≤ 109


Sample Input 1

1

3

2 1 3


Sample Output 1

5


Note

Time for Problem 1 : 2 minutes

Time for Problem 2 : 1 minutes

Time for Problem 3 : 2 minutes

This satisfies the restriction and yields minimum time which is 2+1+2=5 */

vector<ll>ratings;
void solve(){
  
ll n;
cin>>n;

ratings.resize(n+2);

for(ll i=1;i<=n;i++){
    
    ll r;
    cin>>r;
    ratings[i]=r;
}

ratings[0]=ratings[n+1]=1e9+10;
 vector<pair<int,int>>v;
 
 for(ll i=1;i<=n;i++){
     
     v.pb({ratings[i],i});
 }

sort(v.begin(),v.end());

vector<ll> minutes(n + 2, 0);
ll ans=0;

for(auto it:v){
    
    int idx=it.s;
    
    ll give=1;
    if(ratings[idx]>ratings[idx-1]){
        
        give=max(give,minutes[idx-1]+1);
        
    }
     if(ratings[idx]>ratings[idx+1]){
        
        give=max(give,minutes[idx+1]+1);
    }
    
     minutes[idx] = give;
            ans += give;
    
}

cout<<ans<<nl;

}

/*approach
If the problem above takes time x and has a rating lesser than the current
 problem and the problem below takes time y and has a rating greater than
  the current problem, then the current problem should take time max(x,y)+1.


Can we sort it and do something?


You can sort all the problems according to their rating, you need to store the
 index as well while doing this. Then you just need to check for each problem, 
 its rating compared to the problems above and below it. If they are lesser then 
 the time taken for the current problem should be atleast one more than it.

Time Complexity per test case: O(N log N) [for sorting]


*/


/*Square sum

Time-Limit: 1 sec Score: 1.00/100
Difficulty : *
 Memory: 256 MB Accepted Submissions: 100
Description

You are given an array A of n non-negative integers.

Define function F = Summation of |Ai-X|2 for all i from 1 to n.

Find the minimum value of the function F by choosing an appropriate integer X.

 


Input Format

First line of input contains T, number of test cases.

First line of each test case contains n .

Second line contains n integers, Ai , the array A.


Output Format

For each test case print the minimum value of F.


Constraints

T ≤ 10

1 ≤ n ≤ 105

0 ≤ Ai ≤ 106


Sample Input 1

1

3

2 2 3


Sample Output 1

1*/

vector<ll>arr;
void solve(){
    
 ll n;
 cin>>n;
 arr.resize(n);
 ll ans=0;
 for(ll i=0;i<n;i++){
     
   ll x;
   cin>>x;
   arr[i]=x;
   ans+=arr[i];
   
   
     
 }
 
 
 double mean=(ans/(double)n);
 
 ll f=floor(mean);
 ll c=ceil(mean);
 
 
 ll result1=0;
 
 ll result2=0;
 for(ll i=0;i<n;i++){
     
     result1+=((arr[i]-c)*(arr[i]-c));
     result2+=((arr[i]-f)*(arr[i]-f));
     
 }
 
 
 cout<<min(result1,result2)<<nl;
 
}


/*approach
You can start the solution by taking examples for N=2 and N=3 and then 
generalise the solution for N.


It can be either of the 2 extremes, either all in one or equally distributed.


*/

/*Destroying intervals ⭐

Time-Limit: 1 sec Score: 100.00/100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Description

There are n intervals. The ith interval covers range [li,ri] 
 including points l and r.

You can destroy intervals by choosing some points. Suppose a point x 
is chosen, then any interval that covers x will be destroyed.

Find the minimum number of points to be selected to destroy all intervals.

 

 


Input Format

First line of input contains T, number of test cases.

First line of each test case contains n, the number of intervals.

Each of n next lines contain two integers , li and ri .

 


Output Format

For each testcase print a single integer, minimum points required.


Constraints

T ≤ 20
0 ≤ n ≤ 105
0 ≤ li ≤ ri ≤ 109


Sample Input 1

1
3
1 4
2 6
7 10

Sample Output 1

2

Note

You can choose point 3 which destroys interval 1 & 2, and point 7 to destroy interval 3.*/

struct intrvl{
    
    ll l,r;
};

bool cmp(intrvl a, intrvl b){
    
    return a.r<b.r;
    
}



void solve(){
  
ll n;
cin>>n;


//vector<intrvl>arr(n); or

intrvl arr[n];

for(ll i=0;i<n;i++){
    
   cin>>arr[i].l>>arr[i].r;
  
}


sort(arr,arr+n,cmp);

ll cnt=0;

ll prev_end=INT_MIN;

for(ll i=0;i<n;i++){
    
    if(prev_end<arr[i].l){
        cnt++;
      prev_end=arr[i].r;  
        
    }
    
    
    
}

cout<<cnt<<nl;

}


/*Fibonacci Breakdown

Time-Limit: 1 sec Score: 1.00/100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Description

Given a number k, find the minimum number of fibonacci numbers

whose sum is equal to k. You can use any of the fibonacci numbers  

any number of times.

Fibonacci Numbers:

F(1) = 1

F(2) = 1

F(n) = F(n-1) + F(n-2) : for n>=3

 


Input Format

First line of input contains T, number of test cases.

The only line of each test case contains an integer k.

 


Output Format

For each test case output one integer: The minimum number of fibonacci numbers needed.


Constraints

T ≤ 100

1 ≤ k ≤ 109

 


Sample Input 1

1

7


Sample Output 1

2


Note

7 can be formed using 2 + 5, where 2, 5 are fibonacci numbers.*/


void solve(){
    
    ll k;
    cin>>k;
    
    
    ll fibo[50];
    
    fibo[1]=fibo[2]=1;
    
    
    for(ll i=3;i<50;i++){
        
        
        fibo[i]=fibo[i-1]+fibo[i-2];
    }
    
    
    
    int terget=49;
    
    ll ans=0;
    while(k){
        
        if(k>=fibo[terget]){
            
            k-=fibo[terget];
            
            ans++;
        }
        terget--;
        
    }
    
cout<<ans<<nl;

}
/*approach

There are less than 50 Fibonacci numbers upto 10^9.


Zeckendorf’s theorem states that every positive integer has a unique 
representation as a sum of Fibonacci numbers such that no two numbers
 are equal or consecutive Fibonacci numbers.


The problem can be solved greedily by taking the maximum Fibonacci 
number ≤ current number and subtracting this number from the current number.
 Repeat this till the current number reaches 0.

We don’t take adjacent Fibonacci numbers because, F[i] = F[i-1] + F[i-2]
 and we don’t take duplicate Fibonacci numbers because, 2*F[i] = F[i+1] + F[i-2].

Time Complexity per test case: O(log K)


*/


/*Dearrange

Time-Limit: 2 sec Score: 1.00/100
Difficulty : **
 Memory: 256 MB Accepted Submissions: 100
Description

You are given an array A of n integers. You can perform as many swap operations 
as you want. In a swap operation you can swap the elements at any two positions. 

Define score as number of indices i such that after all the operations, Ai is 
different from the original value of Ai. Print the maximum score possible.


Input Format

First line of input contains T, number of test cases.

First line of each test case contains n.

Second line contains n integers, ith integer is Ai .

 


Output Format

For each testcase print the maximum score possible in a new line.


Constraints

T ≤ 10

1 ≤ n ≤ 105

1 ≤ Ai ≤ 106


Sample Input 1

1

3

1 2 3


Sample Output 1

3*/

bool cmp(pair<ll,ll>&a,pair<ll,ll>&b){
    
    return a.s>b.s;
    
    
}
void solve(){

ll n;
cin>>n;
unordered_map<ll,ll>mp;
//vector<pair<ll,ll>>arr(0);
for(ll i=0;i<n;i++){
    
    ll x;
    cin>>x;
    if(mp.find(x)==mp.end()){
        mp[x]=1;
    }else{
        mp[x]++;
    }
}

ll mxcnt=0;
for(auto& it:mp){
    mxcnt=max(mxcnt,it.s);
   
}

//sort(arr.begin(),arr.end(),cmp);

//cout<<mxcnt<<nl;

if(mxcnt<=n/2){cout<<n<<nl;}
else{
    ll x=n-mxcnt;
    ll ans=mxcnt-x;
    ans=n-ans;
    
    cout<<ans<<nl;
    
    
}

}

/*If the original array is A and the new array is B, we want to maximise 
the values of i such that A[i] ≠ B[i]. This hints us about making a frequency map.


Try to use the strategy to merge 2 elements from the highest 2 frequencies 
available at each step. Of course, this will TLE if you simulate. You need 
to observe when will this be able to finish all, or when is not possible.


Let the maximum frequency be x and the sum of frequencies of all other elements 
be y = n-x. If we have x ≥ y, here we can swap y pair of numbers to get the answer as 2*y.
 Otherwise, it would always be possible to swap numbers such that no position
  will have the original number, and the answer would be n.


*/


/*Jobs

Time-Limit: 2 sec Score: 1.00/100
Difficulty : ****
 Memory: 256 MB Accepted Submissions: 100
Description

You are given n jobs. The ith job has a duration Li and a deadline Di.
 Duration is the amount of time it takes to complete the job. Jobs must 
 be completed on or before their deadline. 

You can start completing jobs at time 0. Only one job can be taken up at a time.
 Any job when taken up must be completed fully without switching to any other job.  

If you finish a job at time t then you may start another job at t.

Find maximum number of jobs that can be completed from the n given jobs.


Input Format

First line of input contains T, number of test cases.

First line of each test case contains n, the number of jobs.

Second line contains n integers, Di , deadline of the ith job.

Third line contains n integers, Li , duration of the ith job.

 


Output Format

For each test case print a single integer in a new line: 
Maximum number of jobs that you can complete.


Constraints

T ≤ 100
n ≤ 20,000
1 ≤ Di, Li ≤ 10^9
Sum of n over all test cases is ≤ 10^5

Sample Input 1

2
2
2 4
2 2
2
3 4
3 3
 


Sample Output 1

2
1

Note

In test case 1,  start job 1 at t=0 and job 2 at t=2 .

In test case 2, both the jobs cannot be completed together.*/

int main()
{
    int t, i, n;

    cin >> t;
    while (t--)
    {
        cin >> n;
        vector<pair<int,int>> jobs(n); // deadline, duration
        for(i=0;i<n;i++) cin>>jobs[i].first;
        for(i=0;i<n;i++) cin>>jobs[i].second;
        jobs.push_back({0,0}); // dummy job

        sort(jobs.rbegin(), jobs.rend()); // sort in decreasing order of deadlines

        int ans=0;
        priority_queue<int> min_heap; // push negatives of durations;

        min_heap.push(-jobs[0].second);
        for(i=1;i<jobs.size();i++)
        {
            int interval = jobs[i-1].first - jobs[i].first;
            // use this time to find out how much of the minimum 
            // duration job in the heap could have been completed.
            while(interval>0 and !min_heap.empty())
            {
                int duration = -min_heap.top();
                min_heap.pop();
                int spend_time = min(interval, duration);
                interval-=spend_time;
                duration -= spend_time;
                if(duration>0) min_heap.push(-duration); // push remaining job time back
                else ans++; //job can be completed
            }

            // push this new job into heap
            min_heap.push(-jobs[i].second);
        }

        cout<< ans<<'\n';
    }
}


/*Hard Problem

Time-Limit: 6 sec Score: 1.00/100
Difficulty : *
 Memory: 256 MB Accepted Submissions: 100
Description

You are given a string S with length N. Each character is assigned a cost 
for removing it. Find the minimum cost for removing characters such that 
it does not contain any subsequence ‘hard’.


Input Format

The first line of the input contains one integer T - 
the number of test cases. Then T test cases follow.

The first line of each test case contains one integer N -
 the length of the array. 

The second line of each test case contains a string S.

The third line of each test case contains N space-separated integers -
 the cost of removing a character.


Output Format

For each test case, print the minimum cost for removing characters such 
that it does not contain any subsequence ‘hard’.


Constraints

1≤ T ≤ 1000

1≤ N ≤ 10^5

1≤ Ai ≤ 10^9


Sample Input 1

3
4
abcd
1 2 3 4
10
hhhaaarrdd
1 2 3 4 1 2 3 4 2 3
4
hard
2 1 4 6


Sample Output 1

0
5
1*/

ll n;
string str;
ll cost[100100];

ll dp[100100][5];

string t="hard";    // form 1
ll rec(ll level,ll match){  
// matching and removing  characters of "hard" from [level,......n-1] with min cost;
    
    // pruning
    
    if(match==4)return 1e18;
     
    // basecase
        
        if(level==n){
            return 0;
            
        }
    
    // cache checked
        if(dp[level][match]!=-1)return dp[level][match];
    
    // compute
        
        ll ans=1e18;
        
        ans=min(ans,cost[level]+rec(level+1,match));
        
        if(str[level]==t[match]){
            
            ans=min(ans,rec(level+1,match+1));
        }else ans=min(ans,rec(level+1,match));
    
    // save and return 
    return dp[level][match]=ans;
    
    
}
 
void solve(){
    
    cin>>n;
    
    cin>>str;
    
    
    for(ll i=0;i<n;i++){
        cin>>cost[i];
    }
    
    memset(dp,-1,sizeof(dp));
    cout<<rec(0,0)<<nl;  
}


/*
approach
Define DP array, DP[4] where DP[i] denotes the cost of not being 
able to form a prefix of length i of ‘hard’.


Iterate through the given string, if we encounter any character of ‘hard’,
 we have two choices, remove the current character or remove the previous 
 character (in case of ‘h’, there is no previous character).


Iterate through the given string, if we encounter any character j of ‘hard’,
 we have two choices and we take the minimum of the two. You can remove the 
 current character, which will make your cost DP[j] + A[i] or you can remove the 
 previous character, which will make your cost DP[j-1].

Time Complexity per test case: O(N)


*/

//editorial code 

signed main() {
   IOS
   int t;
   cin >> t;
   while(t--) {
       int n;
       string s;
       cin >> n >> s;
       int a[n];
       for (int i = 0; i < n; ++i) {
           cin >> a[i];
       }
       int dp[4] = {0};
       for (int i = 0; i < n; ++i) {
           if(s[i] == 'h') dp[0] += a[i];
           else if (s[i] == 'a') dp[1] = min(dp[0], dp[1] + a[i]);
           else if (s[i] == 'r') dp[2] = min(dp[1], dp[2] + a[i]);
           else if (s[i] == 'd') dp[3] = min(dp[2], dp[3] + a[i]);
       }
       cout << dp[3] << "\n";
   }
   return 0;
}

