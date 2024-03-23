/* Remove K integers

    Time-Limit: 1 sec Score: 0.00/100

Difficulty :****

    Memory: 256 MB Accepted Submissions: 100

Relevant For:201,202,301

Description

Given an array N integers in nondecreasing order. Remove K integers such that the maximum difference between two consecutive elements is minimized.

Input Format

The first line contains T, the number of test cases (1<=T<=10).

The first line of each test case contains two integers N and K, 3<=N<=3*10^5, 1<=K<=N-2.

The second line of each test case contains N space-separated integers, -1e9<=A[I]<=1e9.

Output Format

For each test case print a single integer, representing the minimum-maximum difference between two consecutive elements after removing K integers in a new line.
Sample Input 1

2
5 1
1 5 6 8 9
5 2
1 5 6 7 1000

Sample Output 1

2
1

Note

For the first test case → remove 1.

For the second test case → remove 1 and 1000.

*/
/*  approach and editorial
It is not optimal to remove ith element while keeping i-1 the element and i+1 element, as the difference initially was A[i]-A[i-1] and A[i+1]-A[i] but removing A[i] makes the difference A[i+1]-A[i-1] which will be greater than equal to previous differences.

 It is optimal to remove some prefix of A and sum suffix of A, such that the length of prefix removed + length of suffix removed = k.

Create a difference array which store, X[i] = A[i+1]-A[i], then problem reduce to finding a subarray of length N-K-1 in this array X, in a way that minimizes the maximum value. So we have to find the maximum value of all subarray of length N-k-1 and take the minimum one. This can be done in O(N) by Deque.

#include <bits/stdc++.h>
using namespace std;
signed main()
{
   ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
   int testcases;
   cin>>testcases;
   while(testcases--){
       int n,k;
       cin>>n>>k;
       int arr[n];
       int diff[n-1];
       for(int i=0;i<n;i++)
           cin>>arr[i];
       for(int i=1;i<n;i++)
           diff[i-1] = arr[i]-arr[i-1];
       int ans = 2e9;
       int window = n-k-1;
       deque < int > q;
       for(int i=0;i<n-1;i++){
           while(!q.empty() and i-q.front()+1>window)
               q.pop_front();
           while(!q.empty() and diff[i]>=diff[q.back()])
               q.pop_back();
           q.push_back(i);
           if(i>=window-1)
               ans = min(ans,diff[q.front()]);
       }
       cout<<ans<<"\n";
   }
}

*/

//shreya singh's code:
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define nl "\n";
#define mod 1000000007
#define inf 1e18
#define int long long

int n, k; 
int arr[300010]; 

void solve()
{
    cin>>n>>k; 
    vector<int> v; 
    for(int i =0; i<n; i++)
    {
        cin>>arr[i]; 
        if(i)
        v.push_back(arr[i]-arr[i-1]); 
    }
    multiset<int> mt; 
    int w_len = n-k-1; 
    for(int i =0; i<w_len; i++)
    {
        mt.insert(v[i]); 
    }
    ll ans = inf; 
    for(int i = w_len ; i<n; i++)
    {
        auto it = mt.end(); 
        it--; 
        ans = min(ans, *it); 
        mt.erase(mt.find(v[i-w_len])); 
        mt.insert(v[i]); 
    }
    cout<<ans<<'\n'; 
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
    ll t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}

//lakshya mittal's code:
#include <bits/stdc++.h>
#define int long long
using namespace std;

struct monotoneDQ{
    deque<int> dq;

    void insert(int x){
        while(!dq.empty() && dq.back() < x) dq.pop_back();
        dq.push_back(x);
    }

    void remove(int x){
        if(dq.front() == x) dq.pop_front();
    }

    int getMax(){
        return dq.front();
    }
};

void solve(){
    int n, k; cin >> n >> k;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    monotoneDQ dq;
    vector<int> diff;
    for(int i=1; i<n; i++) diff.push_back(arr[i] - arr[i-1]);
    for(int i=0; i<n-1-k; i++){
        dq.insert(diff[i]);
    }
    int ans = dq.getMax();
    for(int i=n-1-k; i<n-1; i++){
        dq.insert(diff[i]);
        dq.remove(diff[i - (n-1-k)]);
        ans = min(ans, dq.getMax());
    }
    cout << ans << "\n";

}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int _t; cin >> _t; while(_t--)
    solve();
    
    return 0;
}

//aryan goyenka's code :
// Enter your code below 
#include<bits/stdc++.h>
using namespace std;
using lli = long long;

#define endl '\n'
#define IOS ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);

using ld = long double;
const lli mod = 1e9 + 7;

bool check(int arr[], int n, int k, int x){
    int start = 0;
    int end = n-1;

    for(int i=1; i<=end; i++){
        if((arr[i] - arr[i-1]) > x){
            if(k >= (end - i + 1)){
                // pruning i to end, means whole array checked.
                break;
            }else if((i - start) <= k){
                k -= (i - start);
                start = i;
            }
            else{
                return 0;
            }
        }
    }

    return 1;
}

void solve(){
    int n, k;
    cin >> n >> k;

    int arr[n];
    int maximum = 0;
    for(int i=0; i<n; i++){
        cin >> arr[i];

        if(i) maximum = max(maximum, arr[i] - arr[i-1]);
    }

    int lo = 0, hi = maximum;
    int ans = hi;

    while(lo <= hi){
        int mid = (lo + hi)/2;

        if(check(arr, n, k, mid)){
            ans = mid;
            hi = mid - 1;
        }
        else{
            lo = mid + 1;
        }
    }

    cout << ans << endl;
}

signed main(){
    IOS

    int T; cin >> T; while(T--)
    solve();
}

//arsh's agarwal's code:
#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve(){
    ll n, k; cin >> n >> k;
    ll a[n]; for(int i = 0; i < n; i++) cin >> a[i];
    ll ans = a[n-1]-a[0];
    multiset<ll> s; for(int i = 0; i < n-2-k; i++) s.insert(a[i+1]-a[i]);
    for(int i = n-2-k; i < n-1; i++){
        s.insert(a[i+1]-a[i]);
        ans = min(ans, *s.rbegin());
        s.erase(s.find(a[i-n+3+k]-a[i-n+2+k]));
    }
    cout << ans << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t; while(t--) solve();
    return 0;
}

/* Distinct Integers

    Time-Limit: 2 sec Score: 0.00/100

Difficulty :***

    Memory: 256 MB Accepted Submissions: 100

Relevant For:

Description

Given an array A of N integers and an integer K, a subarray of A is good if the number of distinct integers present in the subarray is exactly K. Find the number of good subarrays.

Input Format

The first line of the input contains a single integer T denoting the number of test cases, (1<=T<=100000).

The first line of each test case contains two space-separated integers N, K (1<=N<=100000), (1<=K<=10^6).

The second line contains N space-separated integers A1,A2,…,AN, (0<=Ai<=10^6).

Sum of N overall test case <=10^6.

Output Format

For each test case output in a new line the number of good subarrays.
Sample Input 1

5
5 2
1 2 3 4 5
6 3
1 2 3 2 4 2
10 4
1 2 2 3 2 4 1 3 1 2
10 5
1 2 3 4 1 2 3 4 1 2
10 5
1 2 3 4 1 5 2 5 2 6 

Sample Output 1

4
6
21
0
12

 

Note

For the 1st test case, good subarrays are - {1,2},{2,3},{3,4},{4,5}

For the 2nd test case, good subarrays are - {1,2,3}, {1,2,3,2}, {2,3,2,4}, {2,3,2,4,2}, {3,2,4}, {3,2,4,2}.

*/

//lakshay mittal's code:
/****************************************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl "\n"
#define pb push_back
#define pob pop_back
#define um unordered_map
#define us set
#define heap priority_queue
#define pll pair<ll,ll>
#define pcl pair<char,ll>  
#define for0() for(ll i=0; i<n; i++)
#define for1() for(ll i=1; i<=n; i++)
#define tc ll t; cin>>t; while(t--)
#define nc ll n; cin>>n;
#define vl vector<ll>
#define nk ll n,k; cin>>n>>k
#define vc vector<char>
#define vvc vector<vector<char>>
#define vvl vector<vector<ll>>
#define all(x) (x).begin(), (x).end()
#define ret return
#define ff first
#define ss second
#define tos to_string
#define findMid (low + high)/2
#define debug(a) for(auto it:a){cout<<it<<" ";}cout<<endl;
ll min(ll a,ll b){if(a<b)return a;else return b;}
ll max(ll a,ll b){if(a>b)return a;else return b;}
/****************************************************************************************************************/
int mp[1001001];
ll findAns(ll n, ll k, vector<ll> &arr){
    ll head=-1, tail=0, ans=0, cnt=0;
   //  unordered_map<ll,ll> mp;
    while(tail < n) {
        while(head+1<n && (cnt < k || mp[arr[head+1]] > 0)) {
            head++;
            mp[arr[head]]++;
            if(mp[arr[head]] == 1) cnt++;
        }
        ans += head-tail+1;
        if(head >= tail) {
            mp[arr[tail]]--;
            if(mp[arr[tail]] == 0) cnt--;
            tail++;
        }
        else {
            tail++;
            head = tail-1;
        }
    }
    return ans;
}

void solve() {
    ll n, k; cin>>n>>k;
    vector<ll> arr(n);
    for(ll i=0; i<n; i++) {
        cin >> arr[i];
    }
    ll ans1 = findAns(n, k, arr);
    ll ans2 = findAns(n, k-1, arr);
    cout << ans1-ans2 << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    ll t; cin>>t;
    while(t--) {
        solve();
    }
}
//pawan's agarwal's code :
#include<bits/stdc++.h>

using namespace std;
#define endl "\n"
#define ll long long
ll a[1000001],m[1000001];

ll two_pointer(ll k,ll n)
{
     ll head=-1,tail=0,ans=0;
     ll curr_dist = 0;
    //  map<int,int> m;
     while(tail < n)
     {
         
         while(head+1 < n && ((m[a[head+1]] && curr_dist <= k) || (m[a[head+1]]== 0 && curr_dist < k) ))
         {
             head++;
             if(m[a[head]]== 0 )
             curr_dist++;
             
             m[a[head]]++;
           
         }
         
         ans += head-tail+1;
        
         if(head>=tail)
         {
             m[a[tail]]--;
             
             if(m[a[tail]] == 0)
             curr_dist--;
             
             tail++;
         }
         else
         {
             tail++;
             head = tail-1;
         }
     }
     
     return ans;
}


void solve()
{
     ll n,k;
     cin>>n>>k;
     

     for(ll i=0;i<n;i++)
     cin>>a[i];
     
     ll ans = two_pointer(k,n) - two_pointer(k-1,n);
     
     cout<<ans<<endl;
} 

signed  main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

  int _t;cin>>_t;while(_t--)
  solve();
}


//arsh agarwal's code:
#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int freq[1000100];

void solve(){
    ll n, k; cin >> n >> k;
    ll a[n]; for(int i = 0; i < n; i++) cin >> a[i];
    ll dis = 0, last = -1;
    ll ans = 0;
    for(ll i = 0; i < n; i++){
        while(last < n-1 and (dis < k or (dis==k and freq[a[last+1]]!=0))){
            last++; freq[a[last]]++; if(freq[a[last]]==1) dis++;
        }
        ans += (last-i+1LL);
        freq[a[i]]--; if(freq[a[i]]==0) dis--;
    }

    for(int i = 0; i < n; i++) freq[a[i]]=0;
    dis = 0; last = -1;
    for(ll i = 0; i < n; i++){
        while(last < n-1 and (dis < k-1 or (dis==k-1 and freq[a[last+1]]!=0))){
            last++; freq[a[last]]++; if(freq[a[last]]==1) dis++;
        }
        ans -= (last-i+1LL);
        freq[a[i]]--; if(freq[a[i]]==0) dis--;
    }

    for(int i = 0; i < n; i++) freq[a[i]]=0;
    cout << ans << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    memset(freq, 0, sizeof(freq));
    int t; cin >> t; while(t--) solve();
    return 0;
}
/*approach and editorial code :
Try to find the number of subarrays with at most K distinct integers. It can be easily done using two-pointer. Can you get the number of subarray with exactly K distinct integers?

 

Number of subarray with exactly K distinct integers = number of subarray with at most K distinct integers - number of subarray with at most K-1 distinct integers.

One of the important observation - if subarray(i,j) have >K distinct integers, then subarrays(i,j'), j'>=j, definitely have >K distinct integers. So if for j, calculate the smallest index i such that subarray(i,j) have atmost K distinct integers, then for j', the value of the smallest index such that subarray(index, j') have atmost K integers will be greater than equal to i.  

Using two pointer approach you can calculate the number of subarray with atmost K distinct integers. Maintain a head pointer and a tail pointer. For each tail pointer, maintain the smallest head pointer such that subarray(head, tail) have atmost K distinct integers. So the number of subarray with atmost K distinct integers and ending at tail = tail-start+1.

If the number of distinct integers>K in the current subarray(start, tail), then keep on incrementing start till it's value is <=tail and distinct integers>K.

Now to check distinct integers in a subarray(i,j), maintain a frequency[] array in which frequency[i] = number of times 'i' is present in the current subarray(i,j), and a variable 'cnt' which counts the number of distinct integers present in the subarray(i,j). Before adding an integer A[tail] in the subarray check the value of frequency[A[tail]], if value = 0 implies a new distinct element is added, increase the value of 'cnt'. While removing an integer, decrease the value of frequency[A[head]], check if frequency[A[head]] = 0, then no integer with value exist in the current subarray, so decrease the value of 'cnt'. Keep on removing the element from the head till the value of head<=tail and cnt>K. Finally, the correct head is found for the given tail and update the answer.

Do not use Map for the frequency, keep an array, if you see properly, then you will find that the frequency array is updated only for integers present in the array. So you can iterate the array and update the frequency[A[I]] = 0. So you don't have to clear the frequency every time.  

Number of subarray with exactly K distinct integers = number of subarray with atmost K distinct integers - number of subarray with atmost K-1 distinct integers.

#include <bits/stdc++.h>
using namespace std;
int frequency[1000001];
long long countAtmostK(int n, int arr[], int k){
   long long ans = 0;
   int head = 0;
   int tail = 0;
   int cnt =  0;
   while(tail<n){
       if(!frequency[arr[tail]])
           cnt++;
       frequency[arr[tail]]++;
       while(head<=tail and cnt>k)
       {
           frequency[arr[head]]--;
           if(!frequency[arr[head]])
               cnt--;
           head++;
       }
       ans+=(tail-head+1);
       tail++;
   }
   return ans;
}
signed main()
{
   ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
   int testcases;
   cin>>testcases;
   while(testcases--){
       int n,k;
       cin>>n>>k;
       int arr[n];
       for(int i=0;i<n;i++)
           cin>>arr[i];
       long long ans = countAtmostK(n,arr,k);
       for(int i=0;i<n;i++)
           frequency[arr[i]] = 0;
       ans-=countAtmostK(n,arr,k-1);
       for(int i=0;i<n;i++)
           frequency[arr[i]] = 0;
       cout<<ans<<"\n";
   }
}

*/



/* K Odd Number

    Time-Limit: 2 sec Score: 0.00/100

Difficulty :***

    Memory: 256 MB Accepted Submissions: 100

Relevant For:

Description

Given an array of N integers, find a subarray with at most K odd numbers and the total sum is maximum but not more than D. If no such subarray exists print "IMPOSSIBLE" without double-quotes.

Input Format

The first line contains T, the number of test cases (1<=T<=10).

The first line contains two space separated integers N, K, D where 1<=N<=10^5,  0<=K<=10^5, -1e9<=D<=1e9.

Next line contains N space-separated integers (-1e4<=Ai<=1e4).

Output Format

For each test case print the sum of subarray with at most K odd numbers and the total sum is maximum, but not more than D in a newline. If no subarray is possible then print "IMPOSSIBLE" without double-quotes.
Sample Input 1

6
3 2 5
1 2 3
3 1 2
-3 -1 -3
5 2 8
-1 2 3 4 -5
7 0 -2
1 -4 1 0 1 0 2
10 3 14
1 0 -7 1 -10 4 -2 10 -1 3
3 0 1000
-101 201 -301

Sample Output 1

5
-1
8
-4
14
IMPOSSIBLE

Note

For the first test case, the optimal subarray - (2,3) → number of odd number is 1<=2 and sum is 5<=5.

For the second test case, the optimal subarray - (-1) → number of odd number is 1<=2 and sum is -1<=2.

For the third test case, the optimal subarray - (-1,2,3,4) → number of odd number is 2<=2 and sum is 8<=8.

For the fourth test case, the optimal subarray - (-4) → number of odd number is 0<=0 and sum is -4<=-2.

*/

//lakshay mittal's code :
#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n, k, d; cin >> n >> k >> d;
    vector<int> arr(n+1), prefix(n+1);
    for(int i=1; i<=n; i++){
        cin >> arr[i];
        prefix[i] = prefix[i-1] + arr[i];
    }
    int head = 0, tail = 1, odds = 0;
    multiset<int> ms;
    int ans = -1e10;
    while(tail <= n){
        while(head+1<=n && ((arr[head+1]%2==0?0:1) + odds <= k)){
            head++;
            if(arr[head]%2 != 0) odds++;
            ms.insert(prefix[head]);
        }
        if(head>=tail){
            auto it = ms.upper_bound(prefix[tail - 1] + d);
            if(it != ms.begin()){
                it--;
                ans = max(ans, *it - prefix[tail - 1]);
            }
            if(arr[tail]%2 != 0) odds--;
            ms.erase(ms.find(prefix[tail]));
            tail++;
        }else{
            tail++;
            head = tail - 1;
        }
    }
    if(ans == -1e10){
        cout << "IMPOSSIBLE\n";
        return;
    }
    cout << ans << "\n";
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int _t; cin >> _t; while(_t--)
    solve();
    
    return 0;
}
//arsh agarawal's code:
#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve(){
    ll n, k, d; cin >> n >> k >> d;

	ll a[n+1]; for(int i = 1; i <= n; i++) cin >> a[i]; a[0] = 0;

	ll pre[n+1]; pre[0] = 0; for(int i = 1; i <= n; i++) pre[i] = pre[i-1]+a[i];

	multiset<ll> s = {0}; 

	ll odd = 0, last = 0, ans = -1e18;
	for(ll i = 1; i <= n; i++){
		while(last < n and (a[last+1]%2==0 or odd<k)){
			last++; if(a[last]%2) odd++;
			auto it = s.lower_bound(pre[last]-d);
			if(it!=s.end()) ans = max(ans, pre[last]-*it);
			//for(auto temp: s) cout << temp << ' '; cout << '\n';
			s.insert(pre[last]);
		}
	
		//for(auto it: s) cout << it << ' '; cout << '\n';
		if(last >= i) {
			s.erase(s.find(pre[i-1])); 
			if(a[i]%2) odd--;
		}else{
			odd = 0, last = i;
			s.clear(); 
			s.insert(pre[i]);
		}
	}
	if(ans==-1e18) cout << "IMPOSSIBLE\n";
	else cout << ans << '\n';
}

/*
1
3 1 2
-3 -1 -3
*/

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t; while(t--) solve();
	return 0;
}

//solution approach and editorial code :
/*If a subarray from index L to R has number of distinct odd elements at most K, then all subarrays from index X to R (L < X) will also have number of distinct odd elements at most K. Note that the sum of the subarray won’t follow a similar rule since negative elements are also present in the array.

We would be using two pointers to solve this problem. We start both the pointers from the beginning i.e. L = 0 and R = 0. While traversing, we would keep the count of the number of distinct odd elements from L to R. We start from the beginning of the array and keep increasing the right pointer, R till the number of distinct elements is less than or equal to K. We need to check if the current subarray sum is ≤ D. We would use prefix sum and multiset for finding this. Sum of the subarray can be given by prefix[R] - prefix[L-1]. So for a fixed R, we need to find L such that the number of distinct odd elements is at most K and prefix[R] - prefix[L-1] ≤ D ⇒ prefix[L-1] ≥ prefix[R] - D. Since prefix[R] - prefix[L-1] would be maximum, prefix[L-1] would be minimum. In the multiset, we need to keep prefix[L-1] for all L such that the subarray from L to R has at most K distinct odd elements. We can use lower_bound(prefix[R] - D) to find the smallest such prefix[L-1].

Check the solution approach.

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
signed main()
{
   ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
   ll testCases;
   cin>>testCases;
   while(testCases--)
   {
     ll n,k,s;
     cin>>n>>k>>s;
     ll arr[n+1];
     ll prefix[n+1];
     prefix[0] = 0;
     ll ans = -1e18;
     for(ll i=1;i<=n;i++){
       cin>>arr[i];
       prefix[i]=prefix[i-1]+arr[i];
     }
     ll cntOdd = 0;
     multiset < ll > currWindowPrefixSum;
     currWindowPrefixSum.insert(0);
     ll prev = 1;
     for(ll i=1;i<=n;i++){
       cntOdd+=(abs(arr[i])%2);
       if(cntOdd>k){
           while(prev<=i){
               currWindowPrefixSum.erase(currWindowPrefixSum.find(prefix[prev-1]));
               if(abs(arr[prev])%2){
                   prev++;
                   cntOdd--;
                   break;
               }
               prev++;
           }
       }
       if(!currWindowPrefixSum.empty()){
           auto itr = currWindowPrefixSum.lower_bound(prefix[i]-s);
           if(itr!=currWindowPrefixSum.end()){
               ans = max(ans,prefix[i]-(*itr));
           }
       }
       currWindowPrefixSum.insert(prefix[i]);
     }
     if(ans==-1e18){
       cout<<"IMPOSSIBLE\n";
       continue;
     }
     cout<<ans<<"\n";
 }

}

*/

/* Median of Subarray Sum

    Time-Limit: 2 sec Score: 0.00/100

Difficulty :***

    Memory: 256 MB Accepted Submissions: 100

Relevant For:

Description

Given an array of N integers A. The score of a subarray is the sum of all integers in the subarray. Mr.X calculated the score of all N*(N+1))/2 subarray. Mr.X wants you to find the median of the array containing the score of all the subarray.

 

Note: The median of a sequence is the value that is in the middle when the sequence is sorted. If the length of the sequence is even, there are two values in the middle and the median is the smaller of these values (or either when they are equal).

Input Format

The first line contains an integer T, the number of test cases (1<=T<=10000).

The first line of each test case contains an integer N where (1<=N<=10^5).

Next line contains N space-separated integers (0<=Ai<=1e9).

Sum of N across all test cases ≤ 10^6.

Output Format

For each test case output the median of the array containing the score of all the subarray in a new line.
Sample Input 1

5
3
1 2 3
1
5
2
1 5
10
1 2 2 3 3 4 5 4 6 7
15
100 222 333 511 555 232 444 555 777 888 999 1000 1112 12345 123456

Sample Output 1

3
5
5
13
3629

 

Note

1st test case:
Subarray and score:
1 -> 1
1,2 -> 3
1,2,3 -> 6
2 -> 2
2,3 -> 5
3 -> 3
New array = {1,2,3,3,5,6}, median = 3

2nd test case:
Subarray and Score:
5 -> 5
New array = {5}, median = 5

3rd test case:
Subarray and score
1 -> 1
1,5 -> 5
5 -> 5
New array = {1,5,5}, median = 5.

*/

//shreya sing:
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define nl "\n";
#define mod 1000000007
#define inf 1e18
#define int long long

int n;
int arr[100010];

int check(ll mid)
{
    int head = -1, tail = 0;
    ll sum = 0;
    ll cnt = 0;
    ll m = n * (n + 1) / 2;
    m = (m + 1) / 2;
    while (tail < n)
    {
        while ((head + 1 < n) && ((sum + arr[head + 1]) <= mid))
        {
            head++;
            sum += 1LL * arr[head];
        }
        cnt += 1LL * (head - tail + 1);
        if (head >= tail)
        {
            sum -= 1LL * arr[tail];
            tail++;
        }
        else
        {
            tail++;
            head = tail - 1;
        }
    }
    return cnt >=(m);
}

void solve()
{
    cin >> n;
    ll lo = inf, hi = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        lo = min(lo, 1LL * arr[i]);
        hi += 1LL*arr[i];
    }
    ll ans = 0;
    while (lo <= hi)
    {
        ll mid = (lo + hi) / 2;
        if (check(mid))
        {
            ans = mid;
            hi = mid - 1;
        }
        else
        {
            lo = mid + 1;
        }
    }
    cout <<ans << '\n';
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
    ll t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}


//lakshay saptal:
#include <bits/stdc++.h>

using namespace std;

#define int long long

bool check(int arr[], int N, int X) {
	int curr = 0;
	int head = -1, tail = 0;
	int ans = 0;
	while (tail < N)
	{
		while (head + 1 < N && (curr + arr[head + 1] <= X)) {
			head++;
			curr += arr[head];
		}
		ans += head - tail + 1;

		if (head >= tail) {
			curr -= arr[tail];
			tail++;
		} else {
			tail++;
			head = tail - 1;
		}
	}
	return ans >= (N * (N + 1) + 3) / 4;
}

void solve() {
	int N;
	cin>>N;

	int arr[N], lo = INT_MAX, hi = 0;
	for (int i = 0; i < N; i++)
	{
		cin>>arr[i];
		hi += arr[i];
		lo = min(lo, arr[i]);
	}

	int ans = 0;
	while (lo <= hi)
	{
		int mid = (lo + hi) / 2;
		if (check(arr, N, mid)) {
			ans = mid;
			hi = mid - 1;
		} else {
			lo = mid + 1;
		}
	}
	cout<<ans<<endl;
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t;
	cin>>t;
	while (t--) solve();
}

//aryan goenka
#include<bits/stdc++.h>
using namespace std;
using lli = long long;

#define endl '\n'
#define IOS ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);

using ld = long double;
const lli mod = 1e9 + 7;

bool check(int arr[], int n, lli m, lli x){
    lli count = 0;
    int head = -1, tail = 0;
    lli sumtemp = 0;

    while(tail < n){
        // head++
        while(head+1 < n && (sumtemp + arr[head+1]) <= x){
            head++;

            sumtemp += arr[head];
        }

        // update
        count += (head - tail + 1);

        // tail++
        if(head < tail){
            tail++;
            head = tail - 1;
        }else{
            sumtemp -= arr[tail];
            tail++;
        }
    }

    return ( count >= ((m+1)/2) );
}

void solve(){
    int n;
    cin >> n;

    int arr[n];
    lli sum = 0;
    for(int i=0; i<n; i++){
        cin >> arr[i];
        sum += arr[i];
    }

    lli m = 1LL*n*(n+1)/2;

    lli lo = 0, hi = sum;
    lli ans = 0;
    while(lo <= hi){
        lli mid = (lo + hi)/2;

        if(check(arr, n, m, mid)){
            ans = mid;
            hi = mid - 1;
        }else{
            lo = mid + 1;
        }
    }

    cout << ans << endl;
}

signed main(){
    IOS

    int T; cin >> T; while(T--)
    solve();
}
/*approach and editorial code :
If X is a possible value of the median of the new array, then it should exist in the array and it should have (M+1)/2 elements lesser than or equal to X in the array. Here, M is the size of the new array, i.e. M = N*(N+1)/2.

If we get the number of elements lesser than or equal to X as ≥ (M+1)/2. The possible value of median could X or any value lesser than X. Otherwise, it would be greater than X. This is a monotonic function and hence we can use binary search in this problem. Here M = N*(N+1)/2.

We would be doing binary search on the possible values of the median. Here, we would be using the array which has the subarray sums of the original array. We take the left pointer as L = 0 or L = minimum value present in the new array and we take the right pointer as R = sum of all the numbers in the original array. We take mid = (L+R)/2. We need to find the number of values ≤ mid.

It would not be possible to create the new array since N ≤ 105 and the new array would be of size N*(N+1)/2. To avoid making the new array, we will use two pointers to calculate the subarray sums. If a sum from i to j is ≤ mid, that means all sums from i to (values than j) is ≤ mid.

If the number of values ≤ mid is greater than or equal to (M + 1)/2, that means mid can be a possible value of the median or it would be lesser than mid, so we continue binary search on L to R = mid - 1. Otherwise, the value of median would be > mid and so we continue binary search on L = mid+1 to R. Here, M = N*(N+1)/2.

Time Complexity per test case: O(N * log2(ΣAi))

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
ll arr[100001];
ll func(ll x){ // count number of subarray with sum<=x
   ll cnt = 0;
   ll currSum = 0;
   ll start = 0;
   ll current = 0;
   while(current<n){
       currSum+=arr[current];
       while(start<=current and currSum>x){
           currSum-=arr[start];
           start++;
       }
       cnt+=(current-start+1);
       current++;
   }
   return cnt;
}
signed main()
{
   ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
   int testcases;
   cin>>testcases;
   while(testcases--){
       cin>>n;
       ll low = 0,high = 0;
       for(ll i=0;i<n;i++){
           cin>>arr[i];
           high+=arr[i];
       }
       ll ans = -1;
       ll total = (n*(n+1))/2;
       ll median = (total+1)/2;
       while(low<=high){
           ll mid = (low+high)/2;
           ll cntSub = func(mid);
           if(cntSub>=median)
               high = mid-1,ans = mid;
           else
               low = mid+1;
       }
       cout<<ans<<"\n";
   }
}

*/



/* Count Unique Char in Substrings

    Time-Limit: 2 sec Score: 0.00/100

Difficulty :

    Memory: 256 MB Accepted Submissions: 100

Relevant For:

Description

Given a string S consisting of the lowercase character of length N. Score of a string is the number of unique characters present in the string( characters which are only present once in the string). Like score of "character" is 3 {h,t,e}.

Find the sum of the score of all substring of S.

Input Format

The first line contains T, the number of test cases (1<=T<=10).

The first line of each test case contains an integers N, size of the string, 1<=N<=10^5.

The second line of each test case contains a string S of length N.

Output Format

For each test case print the sum of the score of all substring of S in a newline.
Sample Input 1

5
2
ac
3
aac
5
abode
5
aaaaa
10
jdnbfjdhzw

Sample Output 1

4
6
35
5
194

Note

For the 1st test case:
Substring and score = ("a",1), ("c",1) ("ac",2).
Total score = 4

For the 2nd test case:
Substring and score = ("a",1), ("aa",0), ("aac",1), ("a",1), ("ac",2), ("c",1).
Total score = 6

*/

/*approach and editorial:
Since the strings are made of only lowercase alphabets, we can calculate the contribution of each letter from ‘a’ to ‘z’ to the final answer.

We need to calculate the contribution of each letter from ‘a’ to ‘z’ to the final answer. For the answer, we will consider the case for ‘a’, you need to do the same for each letter from ‘a’ to ‘z’. For a particular ‘a’ to contribute to the final answer, it should exist only once in the subarray (that is how it will become unique). So to calculate the number of subarrays having that ‘a’ only once, we can find its closest left ‘a’ and its closest right ‘a’. The left point of the subarray should be between the closest left ‘a’ and the current ‘a’ and similarly, the right point of the subarray should be between the current ‘a’ and the closest right ‘a’. To find the number of subarrays including current ‘a’, we can multiply the possible values of the left and right points. Do this for each character ‘a’ present in the string and then the same for each character from ‘a’ to ‘z’.

Time Complexity per test case: O(N)

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
signed main(){
   ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);;
   ll testcases;
   cin>>testcases;
   while(testcases--){
       ll n;
       cin>>n;
       string s;
       cin>>s;
       vector < ll >  occurence[26];
       for(ll i=0;i<26;i++)
           occurence[i].push_back(-1);
       for(ll i=0;i<n;i++)
           occurence[s[i]-'a'].push_back(i);
       for(ll i=0;i<26;i++)
           occurence[i].push_back(n);
       ll ans = 0;
       for(ll i=0;i<26;i++){
           for(ll j=1;j<(int)occurence[i].size()-1;j++){
               ans+=(occurence[i][j]-occurence[i][j-1])*(occurence[i][j+1]-occurence[i][j]);
           }
       }
       cout<<ans<<"\n";
   }
}

*/
//shreya singh's code:

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define nl "\n";
#define mod 1000000007
#define inf 1e18

int n; string s; 

void solve()
{
    cin>>n>>s; 
    vector<ll> occ[27]; 
    for(int i =0; i<26; i++)
    {
        occ[i].push_back(-1); 
    }
    for(int i =0; i<s.length(); i++)
    {
        occ[s[i]-'a'].push_back(i); 
    }
    for(int i =0; i<26; i++)
    {
        occ[i].push_back(n); 
    }
    ll ans =0; 
    for(int i = 0; i<26; i++)
    {
        for(int j =1; j<occ[i].size()-1; j++)
        {
            ans += 1LL*(occ[i][j]-occ[i][j-1])*(occ[i][j+1]-occ[i][j]); 
        } 
    }
    cout<<ans<<'\n'; 
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
    ll t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}


//lakshay mittal's code:
#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    vector<vector<int>> pos(26);
    for(int i=0; i<26; i++) pos[i].push_back(-1);
    for(int i=0; i<n; i++) pos[s[i] - 'a'].push_back(i);
    for(int i=0; i<26; i++) pos[i].push_back(n);
    int ans = 0;
    for(auto v: pos){
        for(int i=1; i<(int)v.size() - 1; i++) ans += (v[i+1] - v[i]) * (v[i] - v[i-1]);
    }
    cout << ans << "\n";
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int _t; cin >> _t; while(_t--)
    solve();
    
    return 0;
}


/* Count Distinct Char in Substrings

    Time-Limit: 2 sec Score: 0.00/100

Difficulty :***

    Memory: 256 MB Accepted Submissions: 100

Relevant For:

Description

Given a string S consisting of the lowercase character of length N. Score of a string is the number of distinct characters present in the string. Like the score of "character" is 6.

Find the sum of the score of all substring of S.

Input Format

The first line contains T, the number of test cases (1<=T<=10).

The first line of each test case contains an integers N, size of the string, 1<=N<=10^5.

The second line of each test case contains a string S of length N.

Output Format

For each test case print the sum of the score of all substring of S in a newline.
Sample Input 1

5
2
ac
3
aac
5
abode
5
aaaaa
10
jdnbfjdhzw

Sample Output 1

4
8
35
15
207

Note

For the 1st test case:
Substring and score = ("a",1), ("c",1) ("ac",2).
Total score = 4

For the 2nd test case:
Substring and score = ("a",1), ("aa",1), ("aac",2), ("a",1), ("ac",2), ("c",1).
Total score = 8

*/

/*approach and editorial code :
Since the strings are made of only lowercase alphabets, we can calculate the contribution of each letter from ‘a’ to ‘z’ to the final answer.

We need to calculate the contribution of each letter from ‘a’ to ‘z’ to the final answer. For the answer, we will consider the case for ‘a’, you need to do the same for each letter from ‘a’ to ‘z’. If the count of ‘a’ is anything more than 0 in a subarray, it would contribute 1 to the final answer (since we are taking count of distinct characters). So, we can first add the total number of subarrays, N*(N+1)/2 to the final answer and then subtract those subarrays which don’t have the character ‘a’ in it. This would give us the contribution for ‘a’ in the final answer. Do the same for all characters from ‘a’ to ‘z’.

Time Complexity per test case: O(N)

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);;
    ll testcases;
    cin>>testcases;
    while(testcases--){
        ll n;
        cin>>n;
        string s;
        cin>>s;
        ll prev[26];
        for(ll i=0;i<26;i++)
            prev[i] = -1;
        long long ans = 26*((n*(n+1))/2);
        for(ll i=0;i<n;i++){
            ll lenNotWithChar = i - prev[s[i]-'a']-1;
            ans = ans - ((lenNotWithChar*(lenNotWithChar+1))/2);
            prev[s[i]-'a'] = i;
        }
        for(ll i=0;i<26;i++){
            ll lenNotWithChar = n - prev[i]-1;
            ans = ans - ((lenNotWithChar*(lenNotWithChar+1))/2);
        }
        cout<<ans<<"\n";
    }

}*/

//arsh agarwal's code :
#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve(){
	ll n; string s; cin >> n >> s;
	vector<ll> freq[26]; for(int i = 0; i < 26; i++) freq[i].push_back(-1);
	for(ll i = 0; i < n; i++){
		freq[s[i]-'a'].push_back(i);
	}
	for(ll i = 0; i < 26; i++) freq[i].push_back(n);
	ll ans = 0;
	for(int i = 0; i < 26; i++){
		ll temp = 0;
		for(int j = 1; j < freq[i].size(); j++){
			temp += (freq[i][j]-freq[i][j-1])*(freq[i][j]-freq[i][j-1]-1LL)/2LL;
		}
		ans += n*(n+1LL)/2LL-temp;
	}
	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t; while(t--) solve();
	return 0;
}

//laksay saptal:
#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve() {
	int N;
	cin>>N;
	
	string s;
	cin>>s;

	int ans = 0;

	vector<int> occurences[26];
	for (int i = 0; i < 26; i++)
	{
		occurences[i].push_back(-1);
	}
	for (int i = 0; i < N; i++)
	{
		occurences[s[i] - 'a'].push_back(i);
	}
	for (int i = 0; i < 26; i++)
	{
		occurences[i].push_back(N);
	}

	for (int i = 0; i < 26; i++)
	{
		int sum = 0;
		for (int j = 1; j < occurences[i].size(); j++) {
			int len = occurences[i][j] - occurences[i][j - 1] - 1;
			sum += (len * (len + 1) / 2);
		} 
		ans += ((N * (N + 1) / 2)) - sum;
	}

	cout<<ans<<endl;
}

signed main() {
	int t;
	cin>>t;
	while (t--) solve();
}



/* Minimum Penalty

    Time-Limit: 1 sec Score: 0.00/100

Difficulty :**

    Memory: 256 MB Accepted Submissions: 100

Relevant For:

Description

Given an array of N integers and an integer D. Consider all subarray with length D, the penalty of the subarray is the number of distinct elements present in the subarray. Find a subarray of length D with minimum penalty. Print the minimum penalty.

Input Format

The first line contains T, the number of test cases (1<=T<=10000).

The first line contains two space-separated integers N, D where 1<=N<=10^6, 1<=D<=N.

Next line contains N space-separated integers (0<=Ai<=1e6).

The Sum of N across all test cases ≤ 5*10^6.

Output Format

For each test case print the minimum penalty in a newline.
Sample Input 1

5
6 3
0 1 1 2 2 2
5 3
1 0 1 2 3
5 5
1 1 2 3 4
5 1
1 2 3 4 5
7 3
1 2 1 2 3 4 2

Sample Output 1

1
2
4
1
2

 

Note

For first test case all the subarray with length = 3 and minimum element ->
0,1,1 - 2
1,1,2 - 2
1,2,2 - 2
2,2,2 - 1
So minimum penalty = 1

*/


/*approach and editorial
Use the sliding window technique to consider all subarray of length D. Suppose you have an answer for index 1 to index D. Then next step you will remove the element at index 1 and add the element at index D+1 to get the subarray of length D starting at 1. Next step remove the element at index 2 and add the element at index D+2

. Think about how you will calculate the distinct number.

Just keep a frequency array, when you add a number increase the frequency, when you delete a number decrease the frequency. Suppose the number you are adding has frequency=0
, which means it is added the first time, so you should increase your count of the distinct element. Similarly after deleting a number if it's frequency=0

, then you should decrease the count of your distinct element.

Try to do it in O(n)
. For clearing the frequency array for each test case, notice that only the frequency of the number present in the array can change. So iterate over the array and initialize the frequency of number present int the array=0. So overall you will do O(n)

transition.

Whenever possible use a frequency array instead of a map . Here we can use frequency array because each element is lesser than 106
. By this we reduced the time complexity of searching distinct elements from O(logn) to O(1)

.

Also its better to use a global frequency array instead of every time defining a vector of size O(106)
becasue that would require O(T∗106) time complexity. Rather define a global array of size 106

and every time just use it.

#include <bits/stdc++.h>
using namespace std;
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int testcases;
    cin >> testcases;
    int freq[1000001] = {0};
    while (testcases--)
    {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        int ans = k;
        int start = 0;
        int current = 0;
        int currSum = 0;
        while (current < n)
        {
            if (freq[arr[current]] == 0)
                currSum++;
            freq[arr[current]]++;
            if (current >= k)
            {
                freq[arr[current - k]]--;
                if (freq[arr[current - k]] == 0)
                    currSum--;
            }
            if (current >= k - 1)
                ans = min(ans, currSum);
            current++;
        }
        for (int i = n - k; i < n; i++) // only the frequency of last d element is set, so for next testcase making it zero.
            freq[arr[i]]--;
        cout << ans << "\n";
    }
}

*/

//aryan goenka:
#include<bits/stdc++.h>
using namespace std;
using lli = long long;

#define endl '\n'
#define IOS ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);

using ld = long double;
const lli mod = 1e9 + 7;

int distinct = 0;
int freq[1000100];

void solve(){
    int n, k;
    cin >> n >> k;

    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    int head = k-1;
    int tail = 0;
    lli sum = 0;

    for(int i=0; i<k; i++){
        if(freq[arr[i]] == 0) distinct++; 
        freq[arr[i]]++;
    }
    int minimum = distinct;

    while(tail < n){
        // head++
        if(head+1 < n){
            head++;

            if(freq[arr[head]] == 0){
                distinct++;
            }
            freq[arr[head]]++;
        }

        // tail++
        if(head< tail){
            tail++;
            head = tail - 1;
        }else{
            freq[arr[tail]]--;
            if(freq[arr[tail]] == 0) distinct--;

            tail++;
        }
        
        //update
        if( (head - tail + 1) == k) {
            minimum = min(minimum, distinct);
        }
    }

    cout << minimum << endl;
}

signed main(){
    IOS

    int T; cin >> T; while(T--)
    solve();
}

//lakshay saptal:
#include <bits/stdc++.h>

using namespace std;

int mp[1000100];

void solve() {
	int N, D;
	cin>>N>>D;

	int arr[N];
	for (int i = 0; i < N; i++)
	{
		cin>>arr[i];
	}

	int head = -1, tail = 0;
	int distinct = 0;
	int ans = INT_MAX;
	while (tail < N)
	{
		while ((head + 1 < N) && ((head - tail + 1) < D)) {
			head++;
			if (mp[arr[head]] == 0) distinct++;
			mp[arr[head]]++;
		}
		ans = min(distinct, ans);
		if (head == N - 1) break;
		if (head >= tail) {
			mp[arr[tail]]--;
			if (mp[arr[tail]] == 0) distinct--;
			tail++;
		} else {
			tail++;
			head = tail - 1;
		}
	}
	cout<<ans<<endl;
	for (int i = 0; i < N; i++)
	{
		mp[arr[i]] = 0;
	}
	
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t;
	cin>>t;
	while (t--) solve();
}

//arsh agarwal:
#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int freq[1000001];

void solve(){
    int n, d; cin >> n >> d; int a[n]; for(int i = 0; i <n ; i++) cin >> a[i];
    int ans = 1e9, dis = 0;;
    for(int i = 0; i < d-1; i++) {if(freq[a[i]]==0) dis++; freq[a[i]]++;}
    for(int i = d-1; i < n; i++){
        freq[a[i]]++;
        if(freq[a[i]]==1) dis++;

        ans = min(ans, dis);

        freq[a[i-d+1]]--;
        if(freq[a[i-d+1]]==0) dis--;
    }
    for(int i = 0; i < n; i++) freq[a[i]] = 0;
    cout << ans << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    memset(freq, 0, sizeof(freq));
    int t; cin >> t; while(t--) solve();
    return 0;
}