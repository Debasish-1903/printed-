/*Question 1

Given n job activities with their start time and finish time. Find the maximum 
number of activities that can be performed without performing two activities at
 the same time.

Example:

    Start = {5, 1, 3, 0, 5, 8}, end = {9, 2, 4, 6, 7, 9}  => 4

Solution Idea:

Method1: The greedy idea to solve this problem is to select the jobs which end 
earliest. So we will sort all the jobs with their end-time and greedily pick 
the jobs if it is not clashing with previously picked jobs. 
*/
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
Joining two ropes will make a single rope of length equal to the sum 
of both the ropes and also the cost of joining is also equal to the sum of 
ropes that are joined.

Example:

    {4,4,3,2,6} => 43

Solution Idea:

Method1: If we look closely at the problem we find that the length of rope which
 is joined first will contribute to the cost till all the ropes are joined.
  So we should not join the highest length rope at the first. We will pick the 
  minimum two ropes and join them and recursively perform this operation for rest.
   For this, we will use min priority_queue (minheap).
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

Find the maximum value of the sum of arr[i] * i of the given array arr when 
rearrangement is allowed.

Example:

    {2, 7, 4, 1} => 31

Solution Idea:

Method1: We need to scale the maximum number by the maximum value and the minimum 
number by the minimum value. So we will just sort the array and count the required sum.
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

/*Question 4

Find the minimum product of a subset of numbers of an array.

Example:

    {0, -1, 2, 1, -2} => -4

Solution Idea:

Method1: If there are even numbers of negative numbers and no zeros, 
the result is the product of all except the largest valued negative 
number. If there are an odd number of negative numbers and no zeros, 
the result is simply the product of all. If there are zeros and positive,
 no negative, the result is 0. The exceptional case is when there is no 
 negative number and all other elements positive then our result should be
  the first minimum positive number.
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

Method1: We need to negate the minimum numbers in the current array and this 
operation is performed k times or till the minimum number is zero. We will 
use a priority queue for finding the minimum number in the array.
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


/*Question 1

Find the minimum number of operations that can be performed on elements
 of the array such that the gcd of the array becomes equal or multiple 
 of k. In one operation you can pick any element and increment or decrement
  its value by 1.

Example:

    {2, 3, 4} , k=4 => 3
    {5, 3, 7} , k=3 => 2

Solution Idea:

Method1: We need to make each element equal to k or the nearest multiple 
of k in order to make gcd multiple of k. For each element in the array,
 we will find remainder by dividing it with k and adding the number of 
 operations as remainder or (k-remainder) based on minimum value. Since 
 these are the number of decrements or increments required.
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
 perform as many transactions as you want. Find the maximum profit that can 
 be obtained by buying and selling the stocks.

Example:

    {1,2,3,4} => 3
    {5,4,3,2} => 0
    {4,2,7,1,5} => 9

Solution Idea:

Method1: We will do transactions between consecutive local minimum and 
local maximum. We will buy stocks at local minimum and sell the stocks at 
local maximum. This is the best possible way to get maximum profit.
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

Given a number in the form of a string and an integer k. Remove k digits
 from string to make it as smallest as possible.

Example:

    “20” , k=1 => “0”
    “1313562” , k=2 => “11352”

Solution Idea:

Method1: If there are two consecutive digits in which the first one is
 bigger than the second then it is optimal to remove the first digit.
  We will remove all the digits till k is positive if it is greater than
   the next digit. So our answer string should contain the digits in increasing order. 
   We will use the stack for this problem.
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
 of flip operations that can be performed on k consecutive elements of the 
 array such that the final array does not contain 0 or else return -1.

Example:

    {0,1,0,1,1,0} , k=2 => -1
    {0,1,0,1,1,0} , k=1 => 3

Solution Idea:

Method1: We will traverse from left to right and if we found 0 then we 
need to flip this digit. Consider changing of k consecutive digits as an event 
then if any element is 0 it should fall under an odd number of overlapping 
events else if any element is 1 it should fall under an even number of overlapping 
events. For this, we will use a queue to store the ending points of events.
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

Given two integers x and y. We need to find the minimum number of operations
 required to convert x to y. We can perform two operations such as multiplying
  the number by 2 or subtracting the number by 1.

Example:

    x = 4, y = 5 => 3
    x = 4, y = 9 => 5

Solution Idea:

Method1: We will move backwards i.e. convert y to x and operations are 
dividing by 2 or adding 1. 
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



/* Like Stocks

    Time-Limit: 1 sec Score: 0.00/100

Difficulty :

    Memory: 256 MB Accepted Submissions: 100

Description

You are given an array A of n integers and a value k. You can select zero or more non-empty subarrays A[l..r] such that no two subarrays have any index in common, i.e., no two subarrays should overlap. For each chosen subarray A[l..r] add the value A[r]-A[l]-k to your score which is initially zero. Print the max score possible.

Input Format

First line of input contains T, number of test cases.

First line of each test case contains two integers n and k.

Second line contains n integers, Ai , the array A.

Output Format

For each test case print the max score possible in a new line.

Constraints

T ≤ 100

1 ≤ n ≤ 2*105

0 ≤ Ai , k ≤ 109

Sum of n over all test cases is ≤ 2*105

Sample Input 1

2

6 2

4 2 3 7 5 6

6 0 

4 2 3 7 5 6

Sample Output 1

3

6

Note

t=1: Chosen subarrays= ((2,4))  [1 indexed]

t=2: Chosen subarrays= ((2,4), (5,6))  [1 indexed]

*/

/*At each step i, let's maintain two values - done(i) and in_progress(i)

.

done(i)
- For the subarray [0...i]

, we've partitioned them into subarrays such that the value is maximum.

in_progress(i)
- For the subarray [0...i], we've partitioned them into subarray, and the last subarray is still incomplete, i.e., no closing r is found for the last l

.

How to populate done(i)

? We have two options.

    Do nothing, i.e., do not select i

-th element in any subarray → done(i−1)
.
Complete the open subarray at i
-th element → in_progress(i−1)+A[i]−k

    .

done(i)=max(done(i−1),in_progress(i−1)+A[i]−k)

How to populate in_progress(i)

? We have two options.

    Do nothing, i.e., keep the i

-th within the current open subarray → in_progress(i−1)
.
Start a new open subarray with the current element as starting one →
done(i−1)−A[i]

    .

in_progress(i)=max(in_progress(i−1),done(i−1)−A[i])

The final answer will be done(n−1)

.

#include 
using namespace std;

#define ll long long

signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        int a[n];
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        vector done(n), in_progress(n);
        done[0] = 0;
        in_progress[0] = - a[0];

        for (int i = 1; i < n; ++i) {
            done[i] = max(done[i - 1], a[i] + in_progress[i - 1] - k);
            in_progress[i] = max(in_progress[i - 1], done[i - 1] - a[i]);
        }

        cout << done[n - 1] << "\n";
    }
    return 0;
}

*/

//aryan goyenka:
#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        int a[n];
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        int ans = 0, cur = a[0];
        for (int i = 1; i < n; ++i) {
            if(a[i] < cur) {
                cur = a[i];
            }
            else if(a[i] > cur + k) {
                ans += a[i] - cur - k;
                cur = a[i] - k;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}

//harsh kumar:
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int mod=1e9+7;
void solve()
{
    int n,k;
    cin>>n>>k;
    int a[n],b[n];
    int mx=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
       // b[i]=a[i];
    }
   // sort(b,b+n);
    int min=a[0];
    int ans=0;
    for(int i=1;i<n;i++){
        if(a[i]<min){
            min=a[i];
           // cout<<min<<endl;
        }else{
           if(a[i]>min+k){
            ans+=(a[i]-min-k);
            min=a[i]-k;
           }

        }
    }
    cout<<ans<<endl;
}

signed main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);
  int _t=1;
  cin>>_t;
while(_t--){
   solve();
}
}

//arsh agarwal:
#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n, k; cin>>n>>k; int a[n]; for(int i = 0; i < n; i++) cin>>a[i];
    int done = 0, progress = -a[0];
    for(int i = 1; i < n; i++){
        int  prevdone = done;
        done = max(prevdone, progress+a[i]-k);
        progress = max(progress, prevdone - a[i]);
    }
    cout << done << '\n';
}   


signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //solve();
    int t; cin >> t; for(int i = 0; i < t; i++) solve();
    return 0;
}


/* Palindrome swaps ⭐

    Time-Limit: 1 sec Score: 0.00/100

Difficulty :***

    Memory: 256 MB Accepted Submissions: 100

Description

X wants to transform a given string s into a palindrome. 

X can interchange the position of any two adjacent characters of the string. X can do this as many time as it wants.
What is the minimum number of times it must do this to get a palindrome. In case it's impossible, output -1.

Input Format

First line of input contains T, number of test cases.

First line of each test case contains n, size of string .

Second line contains the string s.

Output Format

For each test case if it's possible to trasnform s to a palindrome print the minimum number of swaps, else print -1.

Constraints

T ≤ 20

n ≤ 100

s consists of lowercase alphabets.

Sample Input 1

2

4

aabb

3

abc

Sample Output 1

2

-1

*/

/*If the length of string is even, frequency of each character should be
 even and if the length of string is odd, frequency of exactly one character
  should be odd and for others it should be even.

You can proceed to the complete solution.

We take two pointers at the front and back of the string, say L and R, if 
they are equal then there is no need to swap them. Otherwise we can either 
make S[R] to be equal to S[L] or we can make S[L] to be equal to S[R]. So 
we need to find another character between L and R such that it is equal to 
the character S[L]/S[R]. Since we need to minimise the number of swaps, we 
should change S[L]/S[R] depending on where the smaller moves would be there.

Time Complexity per test case: O(N^2)

#include &lt;bits/stdc++.h&gt;
using namespace std;
int main()
{
    int t, n, i, j;

    cin&gt;&gt;t;
    while(t--)
    {
        cin&gt;&gt;n;
        string s;
        cin&gt;&gt;s;

        int cnt[26]={0};
        for(auto z:s) cnt[z-'a']++;

        int l=0, r=s.size()-1;
        int swaps=0;
        bool ok=1;
        while(l&lt;r)
        {
            pair&lt;int,int&gt; cost={1e9,-1};
            for(int letter=0;letter&lt;26;letter++)
            {
                if(cnt[letter]&lt;2) continue;
                int costL=0, costR=0;
                for(i=l;;i++)
                {
                    if(s[i]-'a'==letter) break;
                    costL++;
                }
                for(i=r;;i--)
                {
                    if(s[i]-'a'==letter) break;
                    costR++;
                }
                cost=min(cost,{costL+costR,letter});
            }
            if(cost.second==-1)
            {
                ok=0;break;
            }
            swaps+=cost.first;

            cnt[cost.second]-=2;
            for(i=l;;i++)
            {
                if(s[i]-'a'==cost.second)break;
            }
            while(i&gt;l)
            {
                swap(s[i],s[i-1]);
                i--;
            }
            for(i=r;;i--)
            {
                if(s[i]-'a'==cost.second)break;
            }
            while(i&lt;r)
            {
                swap(s[i],s[i+1]);
                i++;
            }
            l++,r--;
        }
        if(!ok) cout&lt;&lt;"-1\n";
        else cout&lt;&lt;swaps&lt;&lt;'\n';
    }

}

*/

//karan wadha:
#include <bits/stdc++.h>
using namespace std;
 
int minSwap(string s)
{
    unordered_map<char, int> unmp;
    int odd = 0, left = 0, right = s.size() - 1, result = 0;
 
    for (char ch : s)
        unmp[ch]++;
 
    for (auto i : unmp)
        if (i.second % 2 == 1)
            odd++;
 
    if (odd > 1)
        return -1;
 
    while (left < right) {
        int l = left, r = right;
        while (s[l] != s[r])
            r--;
        if (l == r) {
 
           
            swap(s[r], s[r + 1]);
            result++;
            continue;
        }
        else {
            
            while (r < right) {
                swap(s[r], s[r + 1]);
                result++;
                r++;
            }
        }
        left++, right--;
    }
    return result;
}
 

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        cout<<minSwap(s)<<'\n';
    }
    
}

//arsh agarwal:
#include <bits/stdc++.h> 
using namespace std;
#define int long long

void solve(){
    int n; string s; cin>>n>>s;
    int ans = 0;
    for(int i = 0; i < n/2; i++){
        int left = -1;
        for(int j = i; j < n-i-1; j++){
            if(s[j]!=s[n-i-1]) continue;
            left = j-i;
            break;
        }

        int right = -1;
        for(int j = n-i-1; j > i; j--){
            if(s[i]!=s[j]) continue;
            right = n-i-1-j;
            break;
        }

        if(left==-1 and right==-1) {cout << -1 << '\n'; return;}
        if(left==-1) left = 1e9;
        if(right==-1) right = 1e9;
        if(left>right){
            for(int j = n-i-1-right; j < n-i-1; j++) swap(s[j], s[j+1]), ans++;
        }else{
            for(int j = i+left; j > i; j--) swap(s[j], s[j-1]), ans++;
        }
    }
    cout << ans << '\n';
}   

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //solve();
    int t; cin >> t; for(int i = 0; i < t; i++) solve();
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
 
int minSwap(string s)
{
    unordered_map<char, int> unmp;
    int odd = 0, left = 0, right = s.size() - 1, result = 0;
 
    for (char ch : s)
        unmp[ch]++;
 
    for (auto i : unmp)
        if (i.second % 2 == 1)
            odd++;
 
    if (odd > 1)
        return -1;
 
    while (left < right) {
        int l = left, r = right;
        while (s[l] != s[r])
            r--;
        if (l == r) {
 
           
            swap(s[r], s[r + 1]);
            result++;
            continue;
        }
        else {
            
            while (r < right) {
                swap(s[r], s[r + 1]);
                result++;
                r++;
            }
        }
        left++, right--;
    }
    return result;
}
 

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        cout<<minSwap(s)<<'\n';
    }
    
}


/* Light em up

    Time-Limit: 2 sec Score: 0.00/100

Difficulty :****

    Memory: 256 MB Accepted Submissions: 100

Description

There are n light bulbs in a row. Each bulb is either on or off given in input as 1 or 0 respectively.

In one operation you can select any k consecutive bulbs and flip their switches, that is, if a bulb was off it becomes on and vice versa.

Find minimum number of operations to turn all the bulbs on. If it's impossible to do so print -1.

Input Format

First line of input contains T, number of test cases.

First line of each test case contains n and k.

Second line contains n integers, ith integer si represents the state of the ith bulb.

 

Output Format

For each testcase if its possible to turn all the bulbs on, print the minimum operations required, else print -1.

Constraints

T ≤ 1000

0 ≤ k ≤ n ≤ 2*105

si = {0,1}

Sum of n over all test cases is less than 2*105.

Sample Input 1

1

5 2

0 1 0 1 1

Sample Output 1

2

Note

Perform the operation on the subarrays(1 indexed): [1..2] and [2..3] to get 1 1 1 1 1 .

*/

/*If A[0] = 0, there is only one way to flip the switches, i.e. from 0 to K-1.

When you are at index i, you need to ensure that all index j (j < i) are equal to 1.
 So if A[i] = 0, you just need to flip the switches from i to i+K-1.

Traverse through the given array, if you get A[i] = 1, flipping the switch here 
would only increase the answer, so we skip this. If you get A[i] = 0, you need
 to flip the switches from i to i+K-1. If i+K-1 is outside the given array then 
 there is no possible way to flip the switches and so the answer is -1.

Even flips result in the same configuration and odd flips change it. To flip the
 switches from i to i+K-1 efficiently, we can use the xor properties, since they 
 are similar to flipping the switches. You can flip the current switch, i and the 
 switch, i+K and simultaneously maintain another variable which would maintain the 
 xor of the array in the run. When you take xor of this number with i+K, the flip
  would be nullified since it would be done twice.

Time Complexity per test case: O(N)

#include &lt;bits/stdc++.h&gt;
using namespace std;

int main()
{
    int t, i, j;

    cin &gt;&gt; t;
    while (t--)
    {
        int k,n;
        cin&gt;&gt;n&gt;&gt;k;
        vector&lt;int&gt; A(n);
        bool zero=0;
        for(i=0;i&lt;n;i++) 
        {
            cin&gt;&gt;A[i];
            if(A[i]==0) zero=1;
        }

        if(k==0)
        {
            if(zero) cout&lt;&lt;"-1\n";
            else cout&lt;&lt;"0\n";
            continue;
        }

        vector&lt;bool&gt; change(n + 1, 0);
        int ans = 0;
        bool flip = 0, ok = 1;

        for (i = 0; i &lt; n; i++)
        {
            flip ^= change[i];
            if ((A[i] ^ flip) == 0)
            {
                if (i + k - 1 &lt; n)
                {
                    ans++;
                    flip ^= 1;
                    change[i + k] = change[i + k] ^ 1;
                }
                else
                    ok = 0;
            }
        }

        if(!ok) ans=-1;
        cout&lt;&lt;ans&lt;&lt;"\n";
    }
}
*/
//shreya sing:
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define nl "\n";
#define mod 1000000007
#define inf 1e18
#define int long long

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> vec(n+1); 
    for(int i =0; i<n; i++)
    {
        cin>>vec[i]; 
    } 
    int ans =0; 
    if(k==0)
    {
        int cnt =0; 
        for(int i =0; i<n; i++)
        {
            cnt+= vec[i]; 
        }
        if(cnt==n)
        {
            ans =0; 
        }
        else
        {
            ans = -1; 
        }
        cout<<ans<<'\n'; 
        return; 
    }
    vector<int> pre(n+1,0); 
    int cur =0; 
    for(int i =0; i<(n-k+1); i++)
    {
        cur+= pre[i]; 
        if((vec[i]+cur)%2==0)
        {
            ans++; 
            cur++;
            if((i+k)<n)
            {
                pre[i+k]--; 
            }
        }
    }
    for(int i = (n-k+1); i<n; i++)
    {
        cur+=pre[i]; 
        if((vec[i]+cur)%2==0)
        {
            ans = -1; 
        }
    }
    cout<<ans<<'\n'; 
    return; 
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    cout << fixed << setprecision(0);
    int test = 1;
    cin >> test;
    while (test--)
    {
        solve();
    }
    return 0;
}

//lakshay saptal:
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin>>n>>k;
    int arr[n];
    for(int i = 0; i < n; i++) {
        cin>>arr[i];
    }
    int ans = 0;
    for(int i = 0; i < n; i++) {
        if (arr[i] == 0 && (i+k-1) < n) {
            ans++;
            for(int j = i; j <= i+k-1; j++) {
                arr[j] = !arr[j];
            }
        }
    }
    
    int allone = true;
    for(int i = 0; i < n; i++) {
        if (arr[i] == 0) allone = false;
    }
    if (allone) {
        cout<<ans<<endl;
    } else {
        cout<<-1<<endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin>>t;
    while(t--) solve();
}

//arsh agarwal:
#include<bits/stdc++.h>
using namespace std;
#define ll long long int

void solve(){
    int n, k; cin >> n >> k; int a[n]; for(int i = 0; i < n; i++) cin >> a[i];
    if(k==0){
        int sum = 0; for(int i = 0; i < n; i++) sum += a[i];
        if(sum==n) cout << 0 << '\n';
        else cout << -1 << '\n';
        return;
    }
    int ans = 0;
    int val[n]; memset(val, 0, sizeof(val));
    int cur = 0;
    for(int i = 0; i < n-k+1; i++){
        cur += val[i];
        if((a[i]+cur)%2 == 0){
            ans++; if(i+k < n) val[i+k]--; cur++;
        }
    }
    for(int i = n-k+1; i < n; i++){
        cur += val[i];
        if((a[i]+cur)%2 == 0) {cout << -1 << '\n'; return;}
    }
    cout << ans << '\n';
}
 
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //solve();
    int t; cin >> t; while(t--) solve();
    return 0;
}


/* Kill Monsters ⭐

    Time-Limit: 1 sec Score: 0.00/100

Difficulty :**

    Memory: 256 MB Accepted Submissions: 100

Relevant For:

Description

There are N monsters in front of you. To defeat the i-th of them you need an army of Ai soldiers, Bi of which will be killed during the battle.
Now you want to know the minimal number of soldiers you need to recruit in order to kill all the monsters.
You don't care about the order of battles: the only thing that matters is that none of the monsters will be left alive.

Input Format

The first line contains a number T (1 ≤ T ≤ 105) - the number of test cases. Then T lines follow.
The first line of each test cases contains single integer N (1 ≤ N ≤ 105) - the number of monsters.
Each of the next N lines contains two space-separated integers: Ai and Bi (1 ≤ Bi ≤ Ai ≤ 109) - the number of soldiers you need to defeat the i-th monster,  and the number of soldiers that will be killed in the battle against him.
It is guaranteed that the sum of N over all test cases doesn't exceed 5 x 105.

Output Format

For each test case, output a single integer on a new line — the minimal number of soldiers that is sufficient to kill all the monsters.
Sample Input 1

2
2
7 4
5 1
3
4 1
6 4
5 3
Sample Output 1

8
10

Note

Explanation 1:
You need a minimum of 8 soldiers. First, you send 5 soldiers to defeat 2nd monster, after this battle you now have 7 soldiers.
Send them to battle with 1st monster.
Note that if you try to defeat monsters in order 1 - 2, then you will require 9 soldiers.

Explanation 2:
There are 3! = 6 order (of monsters) in which you can battle with monsters.
1. 1 - 2 - 3 : In this order, you will require, minimum of 10 soldiers.
2. 1 - 3 - 2 : In this order, you will require, minimum of 10 soldiers.
3. 2 - 1 - 3 : In this order, you will require, minimum of 10 soldiers.
4. 2 - 3 - 1 : In this order, you will require, minimum of 11 soldiers.
5. 3 - 1 - 2 : In this order, you will require, minimum of 10 soldiers.
6. 3 - 2 - 1 : In this order, you will require, minimum of 11 soldiers.
The minimum number of soldiers require is 10.

*/

/*solution approach*/
/*Among all the monsters which are still remaining to defeat, which one is better to defeat first?
Yes, the one which has the highest value of Ai - Bi.

Sort all the monsters with respect to Ai - Bi. This is the order in which you are sending the soldiers.

The monster which has the highest value of Ai - Bi, is always better to battle first. Because this monster will leave us the maximum number of soldiers alive.
So that we can use these soldiers in the next battle.
Sort all the monsters with respect to Ai - Bi. This is the order in which you are sending the soldiers.
Now iterate over all monsters in this order, and find the minimum soldiers that will require to defeat them all.

See the solution code.

Time complexity: O(NlogN)
Space complexity: O(N) extra space

#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define LD long double

const int N = 100010;

int inf = 1e9;
int mod = 1e9 + 7;

signed main()
{
    //freopen("IN", "r", stdin);
    //freopen("OUT", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int T; cin >> T;
    while(T--) {
        int n;
        cin >> n;
        pair<int,int> monster[n];
        for(int i = 0; i < n; i++) {
            cin >> monster[i].first >> monster[i].second;
        }

        sort(monster, monster + n, [&](pair<int,int> &a, pair<int,int> &b) {
            return a.first - a.second > b.first - b.second;
        });

        ll ans = 0, cur = 0;

        for(int i = 0; i < n; i++) {
            ans += max(0LL, monster[i].first - cur);
            cur = max(1LL * monster[i].first, cur);
            cur -= monster[i].second;
        }

        cout << ans << "\n";
    }

    return 0;
}

*/
//lakshay saptal:
#include <bits/stdc++.h>
using namespace std;

#define int long long

bool comp(pair<int, int> &m1, pair<int, int> &m2) {
    return m1.first-m1.second > m2.first-m2.second;
}

void solve() {
    int n;
    cin>>n;
    vector<pair<int, int> > arr; 
    for(int i = 0; i < n; i++) {
        int a, b;
        cin>>a>>b;
        arr.push_back({a, b});
    }
    sort(arr.begin(), arr.end(), comp);
    int ans = 0;
    for(int i = 0; i < n; i++) {
        if (i == n-1) ans += arr[i].first;
        else ans += arr[i].second;
    }
    cout<<ans<<endl;

}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin>>t;
    while(t--) solve();
}

//arsh agarwal:
#include<bits/stdc++.h>
using namespace std;
#define ll long long int

bool cmp(pair<ll, ll> a, pair<ll, ll> b) {
    return a.first-a.second < b.first - b.second;
}

void solve(){
    int n; cin >> n;
    pair<ll,ll> a[n]; for(int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
    sort(a, a+n, cmp);
    ll ans = 0; ll rem = 0;
    for(int i = n-1; i >= 0; i--){
        if(rem < a[i].first) ans+=a[i].first-rem, rem += a[i].first-rem;
        rem -= a[i].second;
    }
    cout << ans << '\n';
}
 
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //solve();
    int t; cin >> t; while(t--) solve();
    return 0;
}

/* Minimizing Dot Problem

    Time-Limit: 1 sec Score: 0.00/100

Difficulty :***

    Memory: 256 MB Accepted Submissions: 100

Relevant For:

Description

You have given two vectors in N-dimension space, let it be V and W.
V = <V1, V2, ..., VN>
W = <W1, W2, ..., WN>

The dot product is defined as V.W = V1 * W1 + V2 * W2 + ... + VN * WN.

Now you are allowed to permute numbers in vectors, in order to minimize the dot product. Find the minimum dot product that you can get.

See sample test cases for more explanation.

Input Format

The first line contains a number T (1 ≤ T ≤ 105) - the number of test cases. Then T lines follow.
The first line of each test cases contains single integer N (1 ≤ N ≤ 105) - the number of dimensions.
The second line contains N space-separated integers V1, V2, ..., VN (0 ≤ |Vi| ≤ 105) - the vector V.
The third line contains N space-separated integers W1, W2, ..., WN (0 ≤ |Wi| ≤ 105) - the vector W.
It is guaranteed that the sum of N over all test cases doesn't exceed 5 x 105.

Output Format

For each test case, output a single integer on a new line — the minimum dot product that you can obtain.
Sample Input 1

2
2
2 3
-1 4
3
2 4 -2
5 0 -7
Sample Output 1

5
-38

Note

Explanation 1:
Consider all possible combinations.

    V = <2, 3>, W = <-1, 4>: V.W = 10
    V = <2, 3>, W = <4, -1>: V.W = 5
    V = <3, 2>, W = <-1, 4>: V.W = 5
    V = <3, 2>, W = <4, -1>: V.W = 10

The minimum dot product that we can get is 5.

Explanation 2:
We can get minimum dot product when V = <2, 4, -2> and W = <0, -7, 5>, i.e., V.W = -38.

*/


/*solution approach:
Try to think in a greedy way. Observe that we don't need to permute V vector, we only need to permute on W vector. And we have to match each element of V to elements in W such that the dot product is minimized.

Let consider two vectors V = <V1, V2>, W = <W1, W2>. Without loss of generality assume that V1 < V2 and W1 < W2.
So now by considering Hint 1, we only have to see two scenarios here.
1. V = <V1, V2>, W = <W1, W2> : V.W = V1 * W1 + V2 * W2
2. V = <V1, V2>, W = <W2, W1> : V.W = V1 * W2 + V2 * W1
Can you prove that the 2nd one is better than the first?

Observe that we don't need to permute V vector, we only need to permute on W vector. And we have to match each element of V to elements in W such that the dot product is minimized.

Let V = <V1, V2, ..., VN> and W = <W1, W2, ..., WN>.
Without loss of generality, assume that V1 ≤ V2 ≤ ... ≤ VN. Suppose there exist two indices i and j, such that i < j and Wi < Wj. We try to see the result when we swap these two indices.

    V = <V1, V2, ..., VN>, W = <W1, W2, ..., Wi, ..., Wj, ..., WN>. V.W = V1 * W1 + ... + Vi * Wi + ... + Vj * Wj + ... + VN * WN.
    V = <V1, V2, ..., VN>, W = <W1, W2, ..., Wj, ..., Wi, ..., WN>. V.W = V1 * W1 + ... + Vi * Wj + ... + Vj * Wi + ... + VN * WN.

Compare these two dot-products. Vi * Wi + Vj * Wj > Vi * Wj + Vj * Wi.
We can conclude that 2nd one is better. That means when we swap i and j, we get better results.

If we apply this result inductively, we get the following algorithm.

    Sort all Vis in ascending order.
    Sort all Wis in descending order.
    Find the dot-product. It's the minimum one.

See the solution code.

Time complexity: O(NlogN)
Space complexity: O(N) extra space

#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define LD long double

const int N = 100010;

int inf = 1e9;
int mod = 1e9 + 7;

signed main()
{
    //freopen("IN", "r", stdin);
    //freopen("OUT", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int T; cin >> T;
    while(T--) {
        int n; cin >> n;

        int v[n], w[n];

        for(int i = 0; i < n; i++) cin >> v[i];
        for(int i = 0; i < n; i++) cin >> w[i];

        sort(v, v + n);
        sort(w, w + n);

        ll ans = 0;

        for(int i = 0, j = n - 1; i < n; i++, j--)
            ans += 1LL * v[i] * w[j];

        cout << ans << "\n";
    }
    return 0;
}

*/
//arsh agarwal:
#include<bits/stdc++.h>
using namespace std;
#define ll long long int

void solve(){
    int n; cin >> n; ll a[n], b[n]; for(int i = 0; i < n; i++) cin>>a[i]; for(int i = 0; i < n; i++) cin>>b[i];
    sort(a,a+n), sort(b,b+n);
    ll ans = 0;
    for(int i = 0; i < n; i++) ans += a[i]*b[n-1-i];
    cout << ans << '\n';
}
 
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //solve();
    int t; cin >> t; while(t--) solve();
    return 0;
}

//laksay saptal:
#include <bits/stdc++.h>
using namespace std;

#define int long long

bool comp(int &a, int &b) {
    return a > b;
}

void solve() {
    int n;
    cin>>n;
    vector<int> v(n), w(n);
    for(int i = 0; i < n; i++) {
        cin>>v[i];
    }
    for(int i = 0; i < n; i++) {
        cin>>w[i];
    }
    sort(w.begin(), w.end());
    sort(v.begin(), v.end(), comp);
    
    int ans = 0;
    for(int i = 0; i < n; i++) {
        ans += v[i]*w[i];
    }
    cout<<ans<<endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin>>t;
    while(t--) solve();
}

/* Array Inversions

    Time-Limit: 2 sec Score: 0/100

Difficulty :***

    Memory: 256 MB Accepted Submissions: 100

Relevant For:

Description

You have given M binary strings, S1, S2, ..., SM. Let T = Sp_1 + Sp_2 + ...+Sp_M, where p is a permutation of {1, 2, ..., M}.
Your task is to find the minimum value of inversion count in T among all M! possible combinations.
The inversion count is the number of pairs (i, j) in T such that i < j and Ti > Tj.

Input Format

The first line of input contains T - the number of test cases.
The first line of each test case contains M - the number of binary strings.
Each of the next M lines contains a binary string Si. 

Output Format

Print the minimum value of inversion possible in T in a new line for each test case.

Constraints

1 ≤ T ≤ 105
1 ≤ M ≤ 105
1 ≤ |Si| ≤ 105
It is guaranteed that sum of all |Si|s over all test cases doesn't exceed 5 x 105
Sample Input 1

2
3
0010
111  
00
2
111 
0

Sample Output 1

1
0

Note

Explanation 1:
The optimal way is to concatenate string in the order 3, 1, 2. T = 000010111.

Explanation 2:
The optimal way is to concatenate string in the order 2, 1. T = 0111.

*/

/*approach and solution:
Consider two strings S1 and S2. Try to think of the condition on which you decide the order of their concatenation.

It's better to put string first which has cnt1/cnt0, here cnt0 and cnt1 are the count of 0s and 1s respectively in the string.

Consider two strings S1 and S2. Let S1 contains cnts10 number of 0s and cnts11 the number of 1s. Similarly, let S2 contains cnts20 number of 0s and cnts21 the number of 1s.

Suppose inversion count in S1 is I1 and in S2 is I2.
Let T1 = S1 + S2 and T2 = S2 + S1.

Inversion count in T1 = I1 + I2 + cnts11 * cnts20
Inversion count in T2 = I1 + I2 + cnts21 * cnts10

If we compare these two equations, we get that it is better to put S1 before S2 iff cnts11 * cnts20 is lesser than cnts21 * cnts10, and vice-versa.

This gives us the result that in the compare function sort the strings according to cnt1/cnt0 condition. And append them. That will be the string T with minimum Inversions.

Time complexity: O(M*logM + N) where N = sum of the length of all Sis.

#include<bits/stdc++.h>
using namespace std;

#define ll long long int

signed main() 
{
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);   

    int T; cin >> T;

    while(T--) {
        int m; cin >> m;

        string s[m];
        for(int i = 0; i < m; i++) {
            cin >> s[i];
        }

        ll cnt[m][2];
        memset(cnt, 0LL, sizeof(cnt));

        for(int i = 0; i < m; i++) {
            for(char c : s[i]) {
                if(c == '0') cnt[i][0]++;
                else cnt[i][1]++;
            }
        }

        vector<int> id(m);
        for(int i = 0; i < m; i++) {
            id[i] = i;
        }

        sort(id.begin(), id.end(), [&](int x, int y) {
            return cnt[x][1] * cnt[y][0] < cnt[x][0] * cnt[y][1];
        });

        ll ans = 0;
        ll one = 0;

        for(int i : id) {
            for(char c : s[i]) {
                if(c == '0') {
                    ans += one;
                }
                else {
                    one++;
                }
            }
        }

        cout << ans << "\n";

    }
}



}*/

//arsh agrarwal:
#include<bits/stdc++.h>
using namespace std;
#define ll long long int

bool cmp(string a, string b){
    ll cnt1 = 0; for(int i = 0; i < a.length(); i++) cnt1 += a[i]-'0';
    ll cnt2 = 0; for(int i = 0; i < b.length(); i++) cnt2 += b[i]-'0';
    ll z1=a.length()-cnt1;
    ll z2=b.length()-cnt2;
    return z2*cnt1 < z1*cnt2;
}

void solve(){
    int n; cin >> n; string a[n]; for(int i = 0; i < n; i++) cin>>a[i];
    sort(a,a+n, cmp);
    ll ans = 0;
    string t; for(int i = 0; i < n; i++) t += a[i];
    ll cnt = 0;
    //cout << t << '\n';
    for(auto it: t){
        if(it=='0') ans += cnt;
        else cnt++;
    }
    cout << ans << '\n';
}
 
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //solve();
    int t; cin >> t; while(t--) solve();
    return 0;
}

//pigeon hole principle:
watch on youtube or google;
//idias based on fraction:


/* Pair Products ⭐

    Time-Limit: 2 sec Score: 0.00/100

Difficulty :

    Memory: 256 MB Accepted Submissions: 100

Relevant For:

Description

You have given an array of n numbers and a positive integer m. Lets define c(i, j) = |ai - aj|.
Your task is to find the product of c(i, j) for all 1 ≤ i < j ≤ n. Since this product can be very large, print it with modulo m.

Input Format

The first line contains two integers n, m (2 ≤ n ≤ 2 x 105, 1 ≤ m ≤ 1000) — number of numbers and modulo.
The second line contains n integers a1, a2, …, an (0 ≤ ai ≤ 109).

Output Format

Output a single integer.
Sample Input 1

2 10
8 5

Sample Output 1

3

Sample Input 2

3 12
1 4 5

Sample Output 2

0

Note

In the first sample, |8 − 5| = 3 ≡ 3 mod 10.
In the second sample, |1 − 4| ⋅ |1 − 5| ⋅ |4 − 5| = 3 ⋅ 4 ⋅ 1 = 12 ≡ 0 mod12.

*/
/*approach and editorial:
Look at the constraints, especially at the range of m.

If n < m, then O(n2) solution will pass, but what about when n > m?

Let's consider 2 cases.

    n ≤ m. Then we can calculate this product directly in O(n2).
    n > m. Note that there are only m possible remainders under division by m, so some 2 numbers of n have the same remainder. Then their difference is divisible by m, so the entire product is 0 mod m.

#include <bits/stdc++.h>

using namespace std;

int p;

int mul(int a, int b) {
    return (1LL * a * b) % p;
}

int sub(int a, int b) {
    int s = (a+p-b);
    if (s>=p) s-=p;
    return s;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n;
    cin>>n>>p;
    assert(n > 0 && n <= 200000 && p > 0 && p <= 1000);
    if (n>p) {cout<<0; return 0;}
    vector<int> a(n);
    for (int i = 0; i<n; i++) {
        cin>>a[i];
        assert(a[i] >= 0 && a[i] <= 1000000000);
    }
    int res = 1;
    for (int i = 0; i<n; i++)
        for (int j = i+1; j<n; j++) res = mul(res, abs(a[i] - a[j])%p);
    cout<<res;
}

*/

//arsh agarwal:
#include<bits/stdc++.h>
using namespace std;
#define ll long long int

void solve(){
    ll n, m; cin >> n >> m;
    ll a[n]; for(int i = 0; i < n; i++) cin >> a[i];
    if(n > m){cout << 0 << '\n'; return;}

    ll ans = 1LL;
    for(ll i = n-1; i > 0; i--){
        for(ll j = 0; j < i; j++){
            (ans *= abs(a[i]-a[j]))%=m;
        }
    }
    cout << ans << '\n';
}
 
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    solve();
    //int t; cin >> t; while(t--) solve();
    return 0;
}

/* Find the Subset ⭐

    Time-Limit: 1 sec Score: 0.00/100

Difficulty :*

    Memory: 256 MB Accepted Submissions: 100

Relevant For:

Description

You are given a multiset of N integers. Check whether there exists a nonempty subset of it such that the sum of the subset's elements is divisible by N. Otherwise, state that this subset doesn't exist.

Input Format

The first line of the input contains an integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test consists of a single integer N - the size of the multiset.
The second line of each test contains N single space-separated integers - the multiset's elements.

Output Format

For each test case, print 'YES' if such a subset exists, otherwise print 'NO'.

Constraints

1 ≤ T ≤ 10
1 ≤ N ≤ 105
1 ≤ Ai ≤ 109
Sample Input 1

1
3
4 6 10

Sample Output 1

YES

Note

We can pick {6} as the subset, then its sum is 6 and this is divisible by 3 - the size of the initial multiset.

*/

/*approach and editorial:
Subarrays are also the subset. Try to think in the direction of subarrays.

Apply Pigeon Hole Principle.

The answer is always YES irrespective of the array.
Consider the pref[i] = (A1 + A2 + ... + Ai) mod N. Base conditions pref[0] = 0.
Observe that there are N + 1 values in the pref array (pref[0], pref[1], ...., pref[N]), but the remainder can take in total N values only (0, 1, ..., N - 1). That means, there exists at least one pair in the pref array which has the same entries.  
Suppose pref[j] == pref[k], and k > j. Then we can conclude that (Aj+1 + ... + Ak) is divisible by N.
Hence, the answer is always YES.

#include <bits/stdc++.h>
using namespace std;

#define ll long long int


signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while(T--) {
        int n; cin >> n;
        int a[n];
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }

        cout << "YES\n";
    }

    return 0;
}

*/

//aarsh agarwal:
#include<bits/stdc++.h>
using namespace std;
#define ll long long int

void solve(){
    int n; cin >> n; int a[n]; for(int i = 0; i < n; i++) cin>>a[i]; cout << "YES\n";
}
 
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //solve();
    int t; cin >> t; while(t--) solve();
    return 0;
}
