/* D-Magic Number

    Time-Limit: 5 sec Score: 0/100

Difficulty :*

    Memory: 256 MB Accepted Submissions: 100

Description

A number N is said to be D-Magic if digit D appears in the decimal representation of the number on only even positions. You have to tell the number of D-Magic numbers in the range A to B(both inclusive) that are multiple of M. Since the answer can be large, print the number of integers modulo 109 + 7.

It is given that the number of digits in A and B is the same and A ≤ B.

 

Input Format

The first line of the input contains one integer T - the number of test cases. Then T test cases follow.

The first line of each test case contains two space-separated integers M and D.

The second line of each test case contains one integer A.

The third line of each test case contains one integer B.

Output Format

Print single integer denoting the number of D-Magic numbers in the range A to B(both inclusive) that are multiple of M, modulo 109 + 7.

Constraints

1 ≤ T ≤ 5

1 ≤ M ≤ 2000

0 ≤ D ≤ 9

1 ≤ A ≤ B ≤ 102000

Sample Input 1

3
2 4
10
90
3 9
200
300
2 1
10 
90

Sample Output 1

7
3
0

Note

For the first test case, the following are the 12 numbers between 10 and 90 which are 2-Magic Numbers: 14, 24, 34, 54, 64, 74, 84.

For the second test case, the following are the 7 numbers between 200 and 300 which are 9-Magic Numbers: 291, 294, 297.

For the third test case, there are no 1-Magic Numbers between 10 and 90.

*/



//approach:
/*Make DP array, DP[index][sum][smaller_already] - the number of ways to 
choose digits so far such that the ‘sum’ tells if the number is divisible 
by M(gives modulo M) and ‘smaller_already’ says whether we have already
 chosen some digits smaller than the corresponding digit in K.

You should not subtract A by 1. That would only make your implementation tougher.

Stress on the given condition that the number of digits in A and B is the same.

For each possible digit in the i-th position of the given number, the DP 
transition will be:

DP[i][sum][smaller] += DP[i+1][(10*sum+digit)%M][smaller||(digit<t] where t
 is the corresponding digit in K.

Time Complexity: O(NM20) where N is the number of digits in A and B.(equal)

*/

#include <bits/stdc++.h>
#include <cmath>
using namespace std;
#define ll long long int
#define ld long double
#define endl '\n'
#define yes cout<<"Yes"<<endl 
#define no cout<<"No"<<endl 
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const ll mod2 = 998244353;
const ll mod = 1e9+7;
const int N = 200100;
const int INF = 1e9;

ll m, d, len;
string L, R;

// Returns the number of numbers such that sum of digits in 
// base 10 is a Multiple of m
ll dp[2020][2][2][2020];

// curRem -> remainder till now

ll rec(int level, int tlo, int thi, int curRem){
    if(level == len){
        if(curRem == 0) return 1;
        else return 0;
    }

    if(dp[level][tlo][thi][curRem] != -1){
        return dp[level][tlo][thi][curRem];
    }

    ll ans = 0, l=0, r =9;

    if(tlo){
        l = L[level]-'0';
    }
    if(thi){
        r = R[level]-'0';
    }

    for(int i=l; i<=r; i++){
        if(level%2 == 0 && i == d) continue;
        if(level%2 && i != d) continue;

        int ntlo = 0, nthi = 0;
        if(tlo == 1 && i == l) ntlo = 1;
        if(thi == 1 && i == r) nthi = 1;

        ll newRem = (curRem*10 + i)%m;

        ans = (ans + rec(level+1, ntlo, nthi, newRem))%mod;

    }

    return dp[level][tlo][thi][curRem] = ans%mod;
}

void solve(){
    cin>>m>>d;
    cin>>L>>R;
    len = R.length();

    memset(dp, -1, sizeof(dp));

    cout<<rec(0, 1, 1, 0)<<endl;
}

int main(){
    fast
    int t=1;
    cin>>t;

    while(t--){
        solve();
    }
}


/* The Larger String

    Time-Limit: 5 sec Score: 0/100

Difficulty :*

    Memory: 256 MB Accepted Submissions: 100

Description

String P is given, consisting of uppercase alphabets. You have to find the number of strings Q, such that string Q is lexicographically larger than string P and reverse of string Q is lexicographically larger than the reverse of string P. Since the answer can be large, print the number of integers modulo 109 + 7.

Input Format

The first line of the input contains one integer T - the number of test cases. Then T test cases follow.

The first line and only line of input contain string P.

Output Format

For each test case, print the number of strings Q.

Constraints

1 ≤ T ≤ 100

1 ≤ |P| ≤ 105 where |P| is the length of string P.

It is guaranteed that the sum of |P| for all test cases is not greater than 105.

Sample Input 1

3
YZY
XY
ZZZZ

Sample Output 1

28
5
0

Note

For the first test case, Q will be valid when Q is YZZ or ZZY. 
Other 26 cases will be ZAZ to ZZZ.

For the second test case, the valid strings are XZ, YY, YZ, ZY, ZZ.

For the third test case, no string is greater than ZZZZ.

*/

#include<bits/stdc++.h>
using namespace std;

const int mod = 1000000007;

string s;

int tt;// current test-case
int testcase[100010][2][2]; // which testcase dp array is storing for


int dp[100010][2][2]; // dp cache array.

// t1 -> tight for same as Q from start or not. 
// t2 -> tight for larger or same as Q from end or not.
int rec(int pos,int t1,int t2){
    if(pos==s.length()){
        if(t2==0 && t1==0)
            return 1;// 1 valid string found.
        else
            return 0;
    }
    if(testcase[pos][t1][t2]==tt){ // check if the saved value is relevant for this testcase.
        return dp[pos][t1][t2];
    }
    int ans = 0;
    for(char dig = 'A'; dig<='Z'; dig++){
        if(t1==1&&dig<s[pos])continue;

        int nt1 = t1;
        if(t1==1&&dig>s[pos]) nt1 = 0;

        int nt2;
        if(dig==s[pos]){
            nt2 = t2;
        }else if(dig>s[pos]){
            nt2 = 0;
        }else{
            nt2 = 1;
        }

        ans =(ans + rec(pos+1,nt1,nt2))%mod;
    }
    testcase[pos][t1][t2] = tt;
    return dp[pos][t1][t2]=ans;
}

int main(){
    int t;cin>>t;
    for(tt=1;tt<=t;tt++){
        cin>>s;
        cout<<rec(0,1,1)<<endl;
    }
}

// approach and editorial code :

/*Make DP array DP[index][t1][t2] - the number of ways to choose
 characters so far such that t1=0 denotes that the first index-1 characters 
 of T match the corresponding characters of S and t1=1 means that T is
  larger than S. t2 = 0 denotes that the last index-1 characters of T 
  match the corresponding characters of S and t2=1 means that reversed 
  T is larger than reversed S.

For each possible character in the i-th position of the given string, 
the DP transitions can be divided into three cases: when character is more,
 less and equal than the corresponding character in given number. 
 When it is greater, t1=1 and t2=1 and when it is equal, t1 and t2 
 remain the same as before. When it is lesser and t1=1, t1=1, t2=0.

Time Complexity per test case: O(|P| * 2 * 2* 26) 

where |P| is the length of string P.

#include<bits/stdc++.h>
using namespace std;

const int mod = 1000000007;

string s;

int tt;// current test-case
int testcase[100010][2][2]; // which testcase dp array is storing for


int dp[100010][2][2]; // dp cache array.

// t1 -> tight for same as Q from start or not. 
// t2 -> tight for larger or same as Q from end or not.
int rec(int pos,int t1,int t2){
    if(pos==s.length()){
        if(t2==0 && t1==0)
            return 1;// 1 valid string found.
        else
            return 0;
    }
    if(testcase[pos][t1][t2]==tt){ // check if the saved
     value is relevant for this testcase.
        return dp[pos][t1][t2];
    }
    int ans = 0;
    for(char dig = 'A'; dig<='Z'; dig++){
        if(t1==1&&dig<s[pos])continue;

        int nt1 = t1;
        if(t1==1&&dig>s[pos]) nt1 = 0;

        int nt2;
        if(dig==s[pos]){
            nt2 = t2;
        }else if(dig>s[pos]){
            nt2 = 0;
        }else{
            nt2 = 1;
        }

        ans =(ans + rec(pos+1,nt1,nt2))%mod;
    }
    testcase[pos][t1][t2] = tt;
    return dp[pos][t1][t2]=ans;
}

int main(){
    int t;cin>>t;
    for(tt=1;tt<=t;tt++){
        cin>>s;
        cout<<rec(0,1,1)<<endl;
    }
}

*/


/* Maximum XOR

    Time-Limit: 5 sec Score: 0/100

Difficulty :*

    Memory: 256 MB Accepted Submissions: 100

Description

You are given two integers L and R. You have to pick any two 
integers(they may be the same) in the range L to R(both inclusive)
 such that the xor of those two integers is maximum.

Input Format

The first line of the input contains one integer T - the number of test cases.
 Then T test cases follow.

The first and only line of each test case contains two space-separated integers L and R.

Output Format

For each test case, print the maximum value of xor of two integers in 
the range L to R(both inclusive) on a separate line.

Constraints

1 ≤ T ≤104

1 ≤ L ≤ R ≤ 1018
Sample Input 1

3
1 3
3 8
5 10

Sample Output 1

3
15
15

Note

For the first test case, 1 and 2 give the maximum xor, which is 3.

For the second test case, 7 and 8 give the maximum xor, which is 15.

For the third test case, 5 and 10, 6 and 9, 7 and 8 give the maximum xor, which is 15.

*/


/*editorial code :
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define fi first
#define sec second
typedef long long int  ll;
typedef long double  ld;
#define pii pair<ll,ll>
#define pic pair<ll,char>
#define vi vector< ll >
#define vvi vector< vi >
#define vpi vector< pii a>
#define vvpi vector< vpi >
#define st  set <ll, greater <ll> >
#define mst  multiset <ll, greater <ll> >
#define in insert
#define sz size
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define mapp  unordered_map <ll, ll>
#define ppii pair< pii, pii >
#define que queue< ll >
#define deq queue< ll >
#define mpit unordered_map<ll, ll> :: iterator
#define mpins(x,y) insert(pair <ll, ll> (x, y))
#define test(t) ll t;cin>>t;while(t--)
#define inarr(n) ll arr[n];for(ll i=0;i<n;i++)cin>>arr[i];
#define ingra(m) vvi arr(100005);for(ll i=0;i<m;i++){ll u,v;cin>>u>>v;arr[u].pb(v);arr[v].pb(u);}
#define mem(a,b) memset(a,b,sizeof(a))
#define inn freopen("input.txt", "r", stdin)
#define outt freopen("output.txt", "w", stdout)
string s1,s2;
ll dp[64][2][2][2][2];
ll func(ll ind,ll ar,ll al,ll br,ll bl)
{
 if(ind==s1.size())
   return 0;
 if(dp[ind][ar][al][br][bl]!=-1)
   return dp[ind][ar][al][br][bl];
 ll mina=0,maxa=1;
 if(al==0 and s1[ind]=='1')
   mina=1;
 if(ar==0 and s2[ind]=='0')
   maxa = 0;
 ll maxb=1,minb=0;
 if(br==0 and s2[ind]=='0')
   maxb=0;
 if(bl==0 and s1[ind]=='1')
   minb = 1;

 ll i,j,val = 0;
 for(i=mina;i<=maxa;i++)
 {
   for(j=minb;j<=maxb;j++)
   {

     ll temp = (1LL<<(s1.size()-ind-1))*(i^j);
     ll nar,nal,nbr,nbl;
     if(ar==0 and i==s2[ind]-'0')
       nar=0;
     else
       nar=1;
     if(al==0 and i==s1[ind]-'0')
       nal=0;
     else
       nal=1;
     if(br==0 and j==s2[ind]-'0')
       nbr=0;
     else
       nbr=1;
     if(bl==0 and j==s1[ind]-'0')
       nbl=0;
     else
       nbl=1;
     val=max(val,temp+func(ind+1,nar,nal,nbr,nbl));
   }
 }
 return dp[ind][ar][al][br][bl]=val;
}
string getbin(ll num)
{
       string res="";
       while (num)
       {
               res+=((num&1)+'0');
               num/=2;
       }
       reverse(res.begin(),res.end());
       return res;
}
int main()
{
 int t;
 cin>>t;
 while(t--){
     ll l,r;
     cin>>l>>r;
     s1=getbin(l);
     s2=getbin(r);
     while(s1.size()!=s2.size())
       s1='0'+s1;
     mem(dp,-1);
     cout<<func(0,0,0,0,0)<<"\n";
 }

}*/

#include <bits/stdc++.h>

using namespace std;

string L,R;

long long dp[70][2][2][2][2];

long long rec(int level,int L1,int R1,int L2,int R2) {
    if(level == 64) {
        return 0;
    }
    
    if(dp[level][L1][R1][L2][R2]!=-1) return dp[level][L1][R1][L2][R2];
    
    // range for first number
    int left1 = 0;
    int right1 = 1;
    
    if(L1 == 1) {
        left1 = L[level]-'0';
    }
    
    if(R1 == 1) {
        right1 = R[level]-'0';
    }
    
    // range for second number 
    int left2 = 0;
    int right2 = 1;
    
    if(L2 == 1) {
        left2 = L[level]-'0';
    }
    
    if(R2 == 1) {
        right2 = R[level]-'0';
    }
    
    long long ans = -1e18;
    
    for(int i=left1;i<=right1;i++) {
        for(int j=left2;j<=right2;j++) {
            // for first number
            int nL1 = L1;
            int nR1 = R1;
            
            if(i != L[level]-'0') {
                nL1 = 0;
            }
            
            if(i != R[level]-'0') {
                nR1 = 0;
            }
            
            //  for second number
            int nL2 = L2;
            int nR2 = R2;
            
            if(j != L[level]-'0') {
                nL2 = 0;
            }
            
            if(j != R[level]-'0') {
                nR2 = 0;
            }
            
            long long XOR = (i^j);
            long long val = ( XOR<<(63-level) );
            
            ans = max(ans,val + rec(level+1,nL1,nR1,nL2,nR2));
            
        }
    }
    
    return dp[level][L1][R1][L2][R2] = ans;
    
}

void solve() {
    long long A,B;
    cin>>A>>B;
    
    L.clear();
    R.clear();
    
    memset(dp,-1,sizeof(dp));
    
    for(int i=63;i>=0;i--) {
        int bit = ((A>>i)&1);
        L.push_back(bit+'0');
    }
    
    for(int i=63;i>=0;i--) {
        int bit = ((B>>i)&1);
        R.push_back(bit+'0');
    }
    
    cout<<rec(0,1,1,1,1)<<"\n";
    
}

int main() {
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t;
    cin>>t;
    
    while(t--) {
        solve();
    }
    
    return 0;
}


// day 2: standered:

/* Lucifer Number

    Time-Limit: 5 sec Score: 0/100

Difficulty :*

    Memory: 256 MB Accepted Submissions: 100

Description

A number N is said to be Lucifer Number if the difference between the sum of digits at even location and sum of digits at odd location is a prime number and greater than zero. You will be given T queries, each asking the number of Lucifer numbers between L and R(inclusive).

Example - 12345671

Digits at odd position - 1 6 4 2

Digits at even position - 7 5 3 1

Sum of digits at even position - sum of digits at odd position = 7+5+3+1-1-6-4-2 = 3 which is a prime number.

Input Format

The first line of the input contains one integer T - the number of test cases. Then T test cases follow.

The first line of each test case contains two space-separated integers L and R.

Output Format

For each query, print an integer denoting the number of Lucifer numbers between L and R(inclusive) on a separate line.

Constraints

1 ≤ T ≤ 100

0 ≤ L ≤ R ≤ 109
Sample Input 1

4
0 40
40 80
80 120
120 160

Sample Output 1

3
12
8
6

Note

For the first test case, following are the required numbers: 20, 30, 31

For the second test case, following are the required numbers: 41, 42, 50, 52, 53, 61, 63, 64, 70, 72, 74, 75.

For the third test case, following are the required numbers: 81, 83, 85, 86, 92, 94, 96, 97.

For the fourth test case, following are the required numbers: 130, 140, 141, 151, 152, 160.

*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
ld pi = acos(-1.0);
string l, r;
ll len;
ll dp[10][2][2][100][100];
bool isprime(int x)
{
    if (x < 2)
        return 0;
    for (int i = 2; i * i <= x; ++i)
        if (x % i == 0)
            return 0;
    return 1;
}
ll rec(ll level, ll tlo, ll thi, ll sum_even, ll sum_odd)
{
    // cout << level << endl;
    // base
    if (level == len)
    {
        ll diff = sum_even - sum_odd;
        if (diff <= 0)
            return 0;
        return isprime(diff);
    }
    // cache
    if (dp[level][tlo][thi][sum_even][sum_odd] != -1)
        return dp[level][tlo][thi][sum_even][sum_odd];
    // transition
    ll lo = 0, hi = 9;
    if (tlo == 1)
        lo = l[level] - '0';
    if (thi == 1)
        hi = r[level] - '0';
    ll ans = 0;
    for (int i = lo; i <= hi; i++)
    {
        int newtlo = tlo, newthi = thi;
        if (i != lo)
            newtlo = 0;
        if (i != hi)
            newthi = 0;

        if ((len - level) % 2)
        {
            ans += rec(level + 1, newtlo, newthi, sum_even, sum_odd + i);
        }
        else
        {
            ans += rec(level + 1, newtlo, newthi, sum_even + i, sum_odd);
        }
    }
    // save and return
    return dp[level][tlo][thi][sum_even][sum_odd] = ans;
}
void solve()
{
    cin >> l >> r;
    if (l.length() != r.length())
    {
        string temp;
        ll diff = r.length() - l.length();
        while (diff--)
        {
            temp += "0";
        }
        l = temp + l;
    }
    len = r.length();
    // cout << l << " " << r << endl;
    memset(dp, -1, sizeof(dp));
    cout << rec(0, 1, 1, 0, 0) << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // isprime[2] = isprime[3] = isprime[5] = isprime[7] = isprime[11] = isprime[13] = isprime[17] = isprime[19] = isprime[23] = isprime[29] = isprime[31] = isprime[37] = isprime[41] = isprime[43] = isprime[47] = isprime[53] = isprime[59] = isprime[61] = isprime[67] = isprime[71] = isprime[73] = isprime[79] = isprime[83] = isprime[89] = isprime[97] = 1;
    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}



/*approach:
Make DP array, DP[index][sum(add for even, subtract for odd)][smaller_already] - the number of ways to choose digits so far such that the ‘sum’ is difference between the sum of digits at even location and sum of digits at odd location and ‘smaller_already’ says whether we have already chosen some digits smaller than the corresponding digit in K.

You have to take care of which position will be even/odd. It will be different for numbers that have different parity of the number of digits.

For each possible digit in the i-th position of the given number, the DP transition will be: 

DP[i][sum][smaller] += DP[i+1][(sum ± digit)%D][smaller||(digit<t] where t is the corresponding digit in K.

Time Complexity per test case: O(log10(B) * 81 * 2)

1

*/



/* Special Numbers

    Time-Limit: 5 sec Score: 0/100

Difficulty : *

    Memory: 256 MB Accepted Submissions: 100

Description

A special number is a number that is not divisible by any of its digits and contains only odd digits like 37, 97. 
Given 3 integers l, r, k. Find the kth special number in the range [l, r]. If there are less than k special numbers in the range [l, r], print -1.

Input Format

The first line of the input contains one integer T - the number of test cases. Then T test cases follow.

The first line of each test case contains three space-separated integers l, r, k.

Output Format

For each test case print the kth special number in the range[l,r]. If there is no such number print -1.

Constraints

1 ≤ T ≤ 100

1 ≤ k ≤ 1018

1 ≤ l ≤ r ≤ 1018

Sample Input 1

5
809413639541111178 990478623187862163 198319173
781230985575483624 960687113325922577 888260952
852510258802402389 902417680494790958 287616546
270648712169631094 879050278468700431 4434617504
204246334829947014 446614786270492285 1504285513

Sample Output 1

933579733797735937
795979555979777979
-1
375759999793599353
339533977575579557

*/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

string a, b;
ll l, r, k;
int n;
ll dp[20][2][2][16][63];



ll rec(int i, int tlo, int thi, int mask, int rem) {
    if (i == n) {
        if (((mask >> 0) & 1) && ((rem % 3) == 0)) {
            return 0;
        }
        
        if (((mask >> 2) & 1) && ((rem % 7) == 0)) {
            return 0;
        }
        
        if (((mask >> 3) & 1) && ((rem % 9) == 0)) {
            return 0;
        }
        
        return (mask != 0);
    }

    auto &ans = dp[i][tlo][thi][mask][rem];

    if (ans != -1) {
        return ans;
    }

    ans = 0;

    int lo = (tlo ? a[i] - '0': 0);
    int hi = (thi ? b[i] - '0' : 9);

    for (int d = lo; d <= hi; d++) {
        int ntlo = (tlo && (d == lo));
        int nthi = (thi && (d == hi));

        if (mask == 0 && d == 0) {
            ans += rec(i + 1, ntlo, nthi, mask, rem);
        } else if (i + 1 == n && d == 5) {
            continue;
        } else if ((d & 1) && (d > 1)) {
            int pos = (d / 2) - 1;
            ans += rec(i + 1, ntlo, nthi, mask | (1 << pos), (10 * rem + d) % 63);
        }
    }

    return ans;
}

bool check(ll mid) {
    a = to_string(l);
    b = to_string(mid);
    
    n = b.length();

    a = string(n - a.length(), '0') + a;

    memset(dp, -1, sizeof(dp));

    return rec(0, 1, 1, 0, 0) >= k;
}

void solve() {
    cin >> l >> r >> k;

    ll lo = l, hi = r;
    ll ans = -1;

    while (lo <= hi) {

        ll mid = (lo + hi) / 2;
        if (check(mid)) {
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }

    return 0;
}


/* Number of pairs

    Time-Limit: 5 sec Score: 0/100

Difficulty :

    Memory: 256 MB Accepted Submissions: 100

Description

F(x) = sum of digits of number x.

Given a number N, find the number of pairs (x,y) such that -
→ 0 ≤ x < y ≤ N
→ F(x) < F(y)
→ F(x) + F(y) is prime.

Input Format

First-line contains a number N. ( 1 ≤ N ≤ 1050)

Output Format

Print the number of pairs %109+7
Sample Input 1

73088299797285479383890143725418999721354734

Sample Output 1

432632403

*/
//shreya sing's code:

#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
// const int mod = 998244353;

string r; 
int n; 
int dp[55][2][2][460][460]; 

bool isPrime(int x)
{
    if(x==1) return 0; 
    for(int i = 2; i*i<=x; i++)
    {
        if((x%i)==0) return 0; 
    }
    return 1; 
}

long long rec(int ind, int h1, int h2, int sum1, int sum2)
{
    if(ind==n)
    {
        if((sum1<sum2) && isPrime(sum1+sum2))
        {
            return 1; 
        }
        return 0; 
    }

    if(dp[ind][h1][h2][sum1][sum2] != -1)
    {
        return dp[ind][h1][h2][sum1][sum2]; 
    }

    int lo1 =0, lo2 =0, hi1 = 9, hi2 =9; 
    
    if(h2) hi2 = r[ind] - '0'; 

    long long ans =0; 

    for(int i = lo1; i<=hi1; i++)
    {
        for(int j = lo2; j<=hi2; j++)
        {
            int cur1 = h1, cur2 = h2; 
            if(h1 && i>j) continue;
            if(i!=j) cur1=0; 
            if(j!=hi2) cur2=0; 
            (ans += rec(ind+1, cur1, cur2, sum1+i, sum2+j))%=mod; 
        }
    }
    return dp[ind][h1][h2][sum1][sum2] = ans; 
}

// 432632403

void solve()
{
    cin>>r;
    n = r.size(); 
    memset(dp,-1,sizeof(dp)); 
    cout<<rec(0,1,1,0,0); 
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    // int t; cin >> t; while(t--) solve();
    return 0;
}

//arsh agarwal code:
#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll dp[51][2][2][452][452];
int n;
string r;
set<int> primes;
ll mod = 1e9+7;
ll rec(int level, int right, int join, int lsum, int rsum){
    //cout << level << ' ' << right << ' ' << join << ' ' << lsum << ' ' << rsum << '\n';
    if(level==n){
        if(lsum<rsum and primes.find(lsum+rsum)!=primes.end() and join==0) return 1;
        else return 0;
    }
    if(dp[level][right][join][lsum][rsum]!=-1) return dp[level][right][join][lsum][rsum];

    ll ans = 0;
    int hi = 9;
    if(right) hi = r[level]-'0';
    for(int i = 0; i < 10; i++){
        for(int j = 0; j <= hi; j++){
            if(join and i > j) continue;
            (ans += rec(level+1, right and j==hi?1:0, join and i==j ? 1 : 0, lsum+i, rsum+j))%=mod;
        }
    }
    return dp[level][right][join][lsum][rsum] = ans;
}

void solve(){
    cin>>r;
    n = r.length();
    memset(dp, -1, sizeof(dp));
    cout << rec(0, 1, 1, 0, 0) << '\n';
}

void pre(){
    int done[1000]; memset(done, false, sizeof(done));
    for(int i = 2; i < 1000; i++){
        if(done[i]) continue;
        primes.insert(i);
        for(int j = i*i; j < 1000; j+=i) done[j]=true;
    }
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    pre();
    solve();
    //int t; cin >> t; for(int i = 0; i < t; i++) solve();
    return 0;
}


/* Palindromic Number

    Time-Limit: 5 sec Score: 0/100

Difficulty :

    Memory: 256 MB Accepted Submissions: 100

Description

A number is said to be a palindrome if it remains the same when it is read backward. A number is called special-palindromic if it contains a palindrome with an odd length greater than 1 and an even palindrome of length greater than 1 as a substring.

For example, the number 8857775 is special-palindromic because it contains the palindrome of odd length 57775 and even length 88. The number 111 is a special-palindrome as it contains the palindrome of odd length 111 and even length 11.
You are given two numbers l, r. Find the number of special-palindromic numbers in the range [l,r].

Input Format

The first line of the input contains one integer T - the number of test cases. Then T test cases follow.

The first line of each test case contains two space-separated integers l, r.

Output Format

For each test case output the number of special-palindrome in the range [l,r] in a new line.

Constraints

1 ≤ T ≤ 100

100 ≤ l ≤ r ≤ 1018
Sample Input 1

5
318661263196762255 862815711794150362
81911993087269085 451708830417250256
533442590027279954 541470499312103755
53352857120044807 479628472267433970
763787750602078367 838624921227800849

Sample Output 1

365535445019098517
249116249428192823
5271193801698071
285832399729012956
50869536601549418

*/

// arsh's agarwal code:
#include<bits/stdc++.h>
using namespace std;
#define ll long long int

string l, r;
int n;
ll dp[20][2][2][10][10][3][2][2];
ll rec(int level, int left, int right, int last, int slast, int nz, int ed, int od){
    if(level==n) return ed and od ? 1 : 0;
    if(dp[level][left][right][last][slast][nz][ed][od]!=-1) return dp[level][left][right][last][slast][nz][ed][od];
    ll ans = 0;
    int lo = 0, hi = 9;
    if(left) lo = l[level]-'0';
    if(right) hi = r[level]-'0';
    for(int i = lo; i <= hi; i++){
        int temp;
        if(nz==0){
            temp=i==0?0:1;
        } else{
            temp=2;
        }

        ans += rec(level+1, left and i==lo?1:0, right and i==hi?1:0, i, last, temp, ed or (nz>0 and i==last)?1:0, od or (nz>1 and i==slast) ? 1 : 0);
    }
    return dp[level][left][right][last][slast][nz][ed][od]=ans;
}

void solve(){
    ll a, b; cin>>a>>b; a++; l = to_string(a), r = to_string(b);
    while(l.length() < r.length()) l='0'+l;
    n = l.length();
    memset(dp, -1, sizeof(dp));
    cout << rec(0, 1, 1, 0, 0, 0, 0, 0) << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //solve();
    int t; cin >> t; for(int i = 0; i < t; i++) solve();
    return 0;
}





/**********BITMASK DP*************/

//Applications:

// day 3 minimal:

/* Students Happiness

    Time-Limit: 2 sec Score: 0/100

Difficulty :***

    Memory: 256 MB Accepted Submissions: 100

Description

There are N Ranks and M students in a class. Each student has a happiness value for the rank in the class he gets. The i th Student gets happy[i][j] on getting a rank j. It's ok to not keep all students in the ranks (They get 0 happiness). At most one student can be assigned to a rank. The total happiness of the assignment can be calculated as Sum of Happiness of each of the students in the class. Find the best way to calculate.

Input Format

The first line contains an integer T (1 ≤ T ≤ 200) - the number of testcases.

The first line of each test case contains two space-separated integers N, M. 1 ≤ N ≤ 10, 1 ≤ M ≤ 50.

The next M lines contain N integers, 0 ≤ happy[i][j] ≤ 10^5.

Output Format

For each test case print the maximum sum of happiness possible in a new line.
Sample Input 1

4
6 11
49 78 23 100 29 2
11 28 39 27 77 45
24 52 18 45 84 41
85 88 75 21 98 100
59 24 27 21 94 90
88 0 0 16 89 54
63 24 100 23 18 75
26 34 54 14 28 11
68 61 40 14 67 14
16 62 17 70 29 52
97 53 0 98 90 75 
1 2
8
6 
5 9
6 0 7 9 3
10 0 1 1 4
0 2 4 6 1
7 1 5 5 10
0 3 3 1 10
9 8 6 9 1
0 10 6 0 2
4 9 2 4 9
4 10 10 3 7 
4 5
10 2 4 0
10 1 6 7
6 3 2 0
2 3 5 1
10 4 7 6 

Sample Output 1

564
8
49
27

*/

#include <bits/stdc++.h>
using namespace std;
using lli = long long;
using ii = pair<int, int>;
using ll = pair<lli, lli>;
using mii = map<int, int>;
using mii = map<int, int>;
using mll = map<lli, lli>;
const int mod = 1e9 + 7;
#define int long long

int n, m;
vector<vector<int>> happiness, dp;

int rec(int level, int mask)
{
    if (level == m)
        return 0;
    if (dp[level][mask] != -1)
        return dp[level][mask];
    int ans = rec(level + 1, mask);
    for (int i = 0; i < n; i++)
    {
        if (((mask >> i) & 1 )== 0)
        {
        // cout << "ans " << ((mask >> i) & 1) << "\n";
            ans = max(ans, happiness[level][i] + rec(level + 1, mask | 1 << i));
        }
    }
    return dp[level][mask] = ans;
}

// Solve here
void solve()
{
    cin >> n >> m;
    happiness.assign(m, vector<int>(n));
    dp.assign(m, vector<int>(1 << n, -1));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> happiness[i][j];
        }
    }
    cout << rec(0, 0) << "\n";
}
signed main()
{
    // Fast IO
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // Number of test cases
    int t = 1;
    // Comment if number of test case is 1
    cin >> t;
    while (t--)
    {
        // Call the Solve
        solve();
    }
}

/*approach and editorial:

The brute force approach would be to find the answer for every possible solution. 
Since one student can be assigned only one rank, the first student will have
 M choices, the second student will have (M-1) choices and so on. The time 
 complexity would be O(M*(M-1)*..(M-N+1)) when N <= M. Otherwise it would be O(M!).

While assigning the ranks to the students starting from 1 to i, it can be noticed 
that the happiness of the i+1-th rank is independent of the ranks assigned to 
the first i persons. So we can use DP with bit masking in this problem. We would be
 iterating on the list of students (M) and make a set to store the ranks (N)
  which have already been assigned.

We would make the DP array as DP[pos][vis] which denotes the maximum happiness 
that can be made by taking pos number of students and vis is the subset of 
ranks assigned. The subset of ranks assigned can be stored by using bit masking 
by using 2^N possible cases. For student pos, there can be two cases: we
 can either assign a rank to him, for this case we would iterate through all 
 the possible ranks, that have not been assigned earlier and perform a 
 recursive solution by adding the happiness for student pos with the particular
  rank and add it to the subset. For the second case, we don’t have to assign
   any rank to the student and just perform the recursive solution for the next 
   student. Note that you need to use memoization otherwise the answer will 
   result in TLE. The base case would be when we have processed all the M students,
    the happiness would be 0 in this case.

Time Complexity per test case: O(M * N * 2^N)

#include <bits/stdc++.h>
using namespace std;

#define int long long

int happy[50][10];
int dp[50][(1<<10)];
int n, m;

int dfs(int pos, int vis) {
    if(pos == m) {
        return 0;
    }
    if(dp[pos][vis] != -1) {
        return dp[pos][vis];
    }
    int ans = dfs(pos+1, vis);
    for (int i = 0; i < n; ++i) {
        if((vis & (1<<i)) == 0) {
            int temp = happy[pos][i] + dfs(pos+1, vis | (1<<i));
            ans = max(ans, temp);
        }
    }
    dp[pos][vis] = ans;
    return ans;
}

signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        cin >> n >> m;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < (1<<n); ++j) {
                dp[i][j] = -1;
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> happy[i][j];
            }
        }
        cout << dfs(0, 0) << "\n";
    }
    return 0;
}

*/


/* TSP

    Time-Limit: 1 sec Score: 0/100

Difficulty :***

    Memory: 256 MB Accepted Submissions: 100

Description

Most basic question.
Given a set of cities and the distance between every pair of cities, the problem is to find the shortest possible route that visits every city exactly once and returns to the starting point.

Input Format

The first line contains an integer T (1 ≤ T ≤ 50) - the number of testcases.

The first line of each test case contains an integer N. 1 ≤ N ≤ 15.

The next N lines contains N space-separated integers, dis[i][j] which denotes distance between city i and city j is dis[i][j], 1 ≤ dis[i][j] ≤ 10^5.
dis[i][i] = 0, dis[i][j]=dis[j][i].

Output Format

Print the shortest distance that needs to be traveled to visit every city exactly once and returns to the starting point in a new line.
Sample Input 1

10
6
0 9 9 10 3 7
9 0 6 7 1 8
9 6 0 7 10 3
10 7 7 0 4 7
3 1 10 4 0 7
7 8 3 7 7 0
3
0 8 6
8 0 8
6 8 0
1
0
7
0 8 6 5 2 9 8
8 0 1 5 5 1 7
6 1 0 2 6 1 6
5 5 2 0 10 6 3
2 5 6 10 0 4 8
9 1 1 6 4 0 1
8 7 6 3 8 1 0
6
0 5 6 2 5 6
5 0 9 10 4 3
6 9 0 5 3 9
2 10 5 0 4 10
5 4 3 4 0 10
6 3 9 10 10 0
5
0 6 6 8 5
6 0 10 5 2
6 10 0 9 4
8 5 9 0 4
5 2 4 4 0
10
0 7 8 3 5 9 7 2 6 6
7 0 2 7 6 5 3 4 7 8
8 2 0 9 9 7 10 3 4 10
3 7 9 0 7 9 5 2 3 8
5 6 9 7 0 9 10 6 9 3
9 5 7 9 9 0 6 6 6 7
7 3 10 5 10 6 0 8 4 3
2 4 3 2 6 6 8 0 2 10
6 7 4 3 9 6 4 2 0 2
6 8 10 8 3 7 3 10 2 0
4
0 10 3 2
10 0 6 9
3 6 0 2
2 9 2 0
11
0 5 2 1 6 3 4 7 8 10 3
5 0 10 7 9 7 3 5 6 7 5
2 10 0 10 2 8 5 8 6 4 6
1 7 10 0 5 5 6 8 4 1 1
6 9 2 5 0 6 1 3 1 9 8
3 7 8 5 6 0 5 7 7 8 2
4 3 5 6 1 5 0 2 4 8 2
7 5 8 8 3 7 2 0 3 3 6
8 6 6 4 1 7 4 3 0 4 7
10 7 4 1 9 8 8 3 4 0 9
3 5 6 1 8 2 2 6 7 9 0
10
0 2 2 9 4 10 5 5 2 4
2 0 5 9 2 2 1 8 6 1
2 5 0 10 3 7 5 7 1 1
9 9 10 0 5 10 7 10 3 10
4 2 3 5 0 2 3 9 2 2
10 2 7 10 2 0 8 6 6 4
5 1 5 7 3 8 0 5 4 6
5 8 7 10 9 6 5 0 5 9
2 6 1 3 2 6 4 5 0 3
4 1 1 10 2 4 6 9 3 0

Sample Output 1

28
22
0
18
23
25
35
20
26
28

*/

#include <bits/stdc++.h>    
using namespace std;    
#define int long long    
#define endl '\n'    
    

int n,m;
vector<vector<int>> v;

int dp[(1<<16) + 100][15+2];
//15 15 1<<15 50
int rec(int mask,int curr,int parr){
    if(mask == ((1<<(n)) - 1)){
        return v[curr][parr];
    }
    if(dp[mask][curr] != -1)return dp[mask][curr]; 
    int ans = 1e18;
    for(int i  = 0;i<n;i++){
        if(((mask>>(i)) & 1 )== 0){
            ans = min(ans,v[curr][i] + rec( (mask|(1<<(i))) ,i,parr));
        }
    }
    return dp[mask][curr] = ans;
}
void solve(){
    cin>>n;
    
    v = vector<vector<int>>(n,vector<int>(n,0));
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            cin>>v[i][j];
            // cout<<v[i][j]<<" ";
        }          
        // cout<<endl;          
    }          
    int ans = 1e18;
    for(int j = 0;j<=((1<<(n+1)) + 9 );j++){
            for(int k = 0;k<=n;k++){
                dp[j][k] = -1;
            }
        }
    
    cout<<rec(1,0,0)<<endl;
   }



signed main() {
    int t=1;
    
    cin >> t;
    
    while (t--) {
        solve();
    }

    return 0;
}

/*The brute force approach would be to calculate all permutations and find the smallest possible answer. Time Complexity for this will be O((N-1)!). There would be overlapping subproblems in this, for example if you want to visit some city j and there would be some subset of cities already visited. So you can optimise the brute force solution using dynamic programming with bitmasking.

Without loss of generality, let's start the tour from vertex 1. We define the DP array as DP[i][j] which is the length of the shortest path from node i while going through all the vertices in j and ending at 1.

DP[1][S - {1}] would be the optimal answer. Here, S-{1} is the set of all the vertices except vertex 1. The transitions can be defined as: DP[i][S] = min(D[i][j] + DP[j][S-{j}]), for all i does not belong to S and j belongs to S. This way we are adding the distance between i and j and the answer for the set S-{j} connecting to j. 

Time Complexity: O(N^2 * 2^N)

#include <bits/stdc++.h>
using namespace std;

#define int long long

int d[15][15];
int dp[(1<<15)][15];

int dfs(int vis, int pos, int n) {
    if(vis == (1<<n)-1) {
        return d[pos][0];
    }
    if(dp[vis][pos]) {
        return dp[vis][pos];
    }
    int ans = 2e18;
    for (int i = 0; i < n; ++i) {
        if((vis & (1<<i)) == 0) {
            int temp = d[pos][i] + dfs(vis | (1<<i), i, n);
            ans = min(ans, temp);
        }
    }
    dp[vis][pos] = ans;
    return ans;
}

signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> d[i][j];
            }
        }
        cout << dfs(1, 0, n) << "\n";
    }
    return 0;
}#include <bits/stdc++.h>
using namespace std;

#define int long long

int d[15][15];
int dp[(1<<15)][15];

int dfs(int vis, int pos, int n) {
    if(vis == (1<<n)-1) {
        return d[pos][0];
    }
    if(dp[vis][pos]) {
        return dp[vis][pos];
    }
    int ans = 2e18;
    for (int i = 0; i < n; ++i) {
        if((vis & (1<<i)) == 0) {
            int temp = d[pos][i] + dfs(vis | (1<<i), i, n);
            ans = min(ans, temp);
        }
    }
    dp[vis][pos] = ans;
    return ans;
}

signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> d[i][j];
            }
        }
        cout << dfs(1, 0, n) << "\n";
    }
    return 0;
}

*/


/* Chess And GCD

    Time-Limit: 5 sec Score: 0/100

Difficulty :***

    Memory: 256 MB Accepted Submissions: 100

Relevant For:

Description

There are 2*N Chess players and N Boards in a chess tournament. The rating of the Chess Player is given by array A. Every player can play only with one player. N board pairing to be done, and if you match Player i and Player j in the board K, then the Happiness Score increases by K*abs(A[i]-A[j])*gcd(A[i],A[j]). Find the Maximum Happiness score you can make by designing an ideal pairing. Every player should play a match.

 

Input Format

The first line contains an integer T (1 ≤ T ≤ 2) - the number of test cases.

The first line of each test case contains an integer N. 1 ≤ N ≤ 10.

The next line contains 2*N space-separated integers, 1 ≤ A[i] ≤ 10^6.

Output Format

For each test case print the output in a new line.
Sample Input 1

3
3
55 86 61 8 9 39 
7
35 68 51 23 66 61 85 34 2 65 64 6 7 32 
3
2 10 1 6 4 8

Sample Output 1

654
19318
85

Note

Third test case - Optimal pairing is (2,10),(4,8),(1,6).

*/

#include<bits/stdc++.h>
using namespace std;
#define int long long

int n;

int A[21];

int dp[11][1<<21];
int rec(int board,int mask)
{
    if(board == n)
    {
        return 0;
    }

    if(dp[board][mask] != -1)
    {
        return dp[board][mask];
    }
    int ans = 0;

    for(int i=0;i<2*n;i++)
    {
        if(mask & (1<<i)) continue;
        for(int j=i+1;j<2*n;j++)
        {
            if(mask & (1<<j)) continue;

            int sc = (board+1)*(abs(A[i]-A[j])*(__gcd(A[i],A[j])));
            ans = max(ans,rec(board+1,(mask | (1<<i) | (1<<j)))+(sc));
            
        }
    }

    return dp[board][mask] = ans;
}


void solve()
{
    cin>>n;

    for(int i=0;i<2*n;i++)
    {
        cin>>A[i];
    }

    int k = 2*n;

  
    memset(dp,-1,sizeof(dp));
    int ans = rec(0,0);

    cout<<ans<<endl;


}



signed main()
{
    int t;
    cin>>t;

    while(t--)
    {
        solve();
    }
}


/*Can we use Bitmask DP in some way?

We would make the DP array as DP[pos][vis] which denotes the maximum happiness that could be achieved by taking pos number of chess boards and vis is the subset of people assigned any chess board. Any board would be assigned to two people, this can be done by taking a nested loop and assigning two people, who have not been assigned a board yet. The base case would be when all the boards have been assigned. But this solution would result in TLE as it is O(N^3 * 2^(2*N)). Can you optimise the solution by removing ‘pos’ from the DP array?

It can be seen that any chess board is assigned to exactly two people, so the number of chess boards would be equal to half of the subset of people who have been assigned a chess board. Doing this optimisation would reduce the time complexity from O(N^3 * 2^(2*N)) to O(N^2 * 2^(2*N)). Note that you need to use memoization otherwise the answer will result in TLE.

Time Complexity per test case: O(N^2 * 2^(2*N))

#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/stack:200000000")
#define mod 1000000007
#define pb emplace_back
#define mp make_pair
#define fi first
#define sec second
typedef long long int ll;
typedef long double  ld;
#define pii pair<ll,ll> 
#define vi vector< ll > 
#define vvi vector< vi > 
#define vpi vector< pii > 
#define vvpi vector< vpi > 
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define test(t) ll t;cin>>t;while(t--)
#define mem(a,b) memset(a,b,sizeof(a))
#define inn freopen("input.txt", "r", stdin)
#define outt freopen("output.txt", "w", stdout)
#define all(arr) arr.begin(),arr.end()
#define fr(i,n) for(ll i=0;i<(n);++i)
#define rep(i,a,b) for(ll i=a;i<=b;++i)
#define per(i,a,b) for(ll i=a;i>=b;i--)
#define remin(a,b) (a=min((a),(b)))
#define remax(a,b) (a=max((a),(b)))
#ifndef ONLINE_JUDGE
#define debarr(a,n)cerr<<#a<<":";for(ll i=0;i<n;i++)cerr<<a[i]<<" ";cerr<<endl;
#define debmat(mat,row,col)cerr<<#mat<<":\n";for(ll i=0;i<row;i++){for(ll j=0;j<col;j++)cerr<<mat[i][j]<<" ";cerr<<endl;}
#define pr(...)dbs(#__VA_ARGS__,__VA_ARGS__)
template<class S,class T>ostream &operator<<(ostream &os,const pair<S,T> &p){return os<<"("<<p.first<<","<<p.second<<")";}
template<class T>ostream &operator<<(ostream &os,const vector<T> &p){os<<"[";for(auto&it:p)os<<it<<" ";return os<<"]";}
template<class T>ostream &operator<<(ostream &os,const set<T>&p){os<<"[";for(auto&it:p)os<<it<<" ";return os<<"]";}
template<class T>ostream &operator<<(ostream &os,const multiset<T>&p){os<<"[";for(auto&it:p)os<<it<<" ";return os<<"]";}
template<class S,class T>ostream &operator<<(ostream &os,const map<S,T>&p){os<<"[";for(auto&it:p)os<<it<<" ";return os<<"]";}
template<class T>void dbs(string str,T t){cerr<<str<<":"<<t<<"\n";}
template<class T,class...S>void dbs(string str,T t,S... s){ll idx=str.find(',');cerr<<str.substr(0,idx)<<":"<<t<<",";dbs(str.substr(idx+1),s...);}
#else
#define pr(...){}
#define debarr(a,n){}
#define debmat(mat,row,col){}
#endif
ll power(ll x,ll y){ll res = 1;while(y){if(y&1) res = (res*x)%mod;y=y/2,x=(x*x)%mod;}return res%mod;}
ll dp[1<<20];
vvi pre_bits(1<<20);
ll pre_gcd[20][20];
ll arr[20];
ll n;
ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b); 

}
ll func(ll mask){
    if(mask==((1<<n)-1)){
        return 0;
    }
    ll &ret = dp[mask];
    if(ret!=-1)return ret;
    ret = 0;
    ll k = (n-pre_bits[mask].size())/2+1;
    fr(i,pre_bits[mask].size()){
        rep(j,i+1,pre_bits[mask].size()-1){
            ret = max(ret,k*abs(arr[pre_bits[mask][i]]-arr[pre_bits[mask][j]])*pre_gcd[pre_bits[mask][i]][pre_bits[mask][j]] + func(mask|(1<<pre_bits[mask][i])|(1<<pre_bits[mask][j])));
        }
    }
    return ret;
}
signed main()
{
    fast;
    test(t){
        cin>>n;
        n*=2;
        fr(i,(1<<n)){
            pre_bits[i].clear();
            fr(j,n){
                if(i&(1<<j))continue;
                pre_bits[i].pb(j);
            }
        }
        fr(i,n)cin>>arr[i];
        mem(dp,-1);
        fr(i,n)fr(j,n)pre_gcd[i][j] = gcd(arr[i],arr[j]);
        cout<<func(0)<<"\n";
    }
}

*/


/* Cycles in a graph

    Time-Limit: 5 sec Score: 0/100

Difficulty :****

    Memory: 256 MB Accepted Submissions: 100

Description

Given a simple graph, output the number of simple cycles in it. A simple cycle is a cycle with no repeated vertices or edges.

Input Format

The first line of input contains two integers n and m (1 ≤ n ≤ 20, 0 ≤ m) – respectively the number of vertices and edges of the graph. Each of the subsequent m lines contains two integers a and b, (1 ≤ a, b ≤ n, a ≠ b) indicating that vertices a and b are connected by an undirected edge. There is no more than one edge connecting any pair of vertices.

Output Format

Print the number of simple cycles.
Sample Input 1

7 16
1 2
1 3
1 5
1 7
2 3
2 4
2 6
3 4
3 5
3 6
3 7
4 5
4 6
4 7
5 6
6 7

Sample Output 1

214

*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1e9+7;




ll add(ll a, ll b)
{
    return (a%mod + b%mod)%mod ;
}

class montone_dq
{
public:    
    deque<ll>dq;
    void insert(ll a)
    {
        while (!dq.empty() and dq.back() > a) {
            dq.pop_back();
        }
        dq.push_back(a);
    }
    void remove(ll a)
    {
        if (!dq.empty() and dq.front() == a)
        {
            dq.pop_front();
        }
    }
    
    ll mini()
    {
        if (!dq.empty())
        {
            return dq.front();
        }
        return 1e18;
    }
};

ll dp[20][1<<20];

ll rec(ll root, ll node, ll mask, vector<vector<bool>> &isedge, ll cnt)
{
    if(dp[node][mask] != -1)
        return dp[node][mask] ;

    ll ans = {};
    if(cnt > 2 && isedge[node][root])
        ans++;
    for(ll child = root; child < isedge.size(); child++)
    {
        if(mask & (1 << child))
            continue;
        if(isedge[node][child])
        {
            ans += rec(root, child, mask | (1 << child), isedge, cnt+1);
        }
    }

    return dp[node][mask] = ans;
}



int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    
    ll t ;
    t = 1 ;

    
    // cin >> t;
    while(t--)
    {
        ll n, m;
        cin >> n >> m;
        vector<vector<bool>> isedge(n+1, vector<bool>(n+1, 0));
        for(int i = 0; i < m; i++){
            ll u, v;
            cin >> u >> v;
            u--;
            v--;
            isedge[u][v] = isedge[v][u] = 1; 
        }
        
        
        ll ans = 0;

        for(ll node = 0; node < n; node++)
        {
            
            memset(dp, -1, sizeof(dp));
            ll mask = (1 << node) ;
            ans += rec(node, node, mask, isedge, 1); 
        }
        cout << ans/2 << "\n";
        
        

    }

    return 0;
}

/*approach and editorial code :

The brute force approach would be to find the answer for every possible solution by taking each subset of n and then adding it to the final answer if it's a simple cycle. The time complexity would be O(N * N!) and would result in TLE. Can you optimise it?

We make a DP array DP[i][j] which denotes the count of simple paths from i to the smallest set bit in j and it contains only vertices from the set j.

We will find the value of DP[i][j] and then check if there exists an edge between i and the smallest set bit in j. If it is, then its a simple cycle

and we add this to the final answer. For the subset of visited vertices, j we need to iterate on all the vertices which have not been visited and are greater than the smallest set bit in j. Then we need to find the neighbours of i and if there is an edge, add that to the answer recursively. We need to divide the final answer by 2 since it is an undirected graph and we have counted each cycle twice.

Time Complexity per test case: O(N^2 * 2^N)

#include <bits/stdc++.h>
using namespace std;

#define int long long

int dp[20][(1<<20)];
bool isEdge[20][20];
int n, m;
int cur;

int dfs(int pos, int vis, int sz) {
    if(dp[pos][vis] != -1) {
        return dp[pos][vis];
    }
    int ans = 0;
    if(sz > 2 && isEdge[pos][cur]) {
        ans++;
    }
    for (int i = cur; i < n; ++i) {
        if((vis & (1<<i))) continue;
        if(isEdge[pos][i]) {
            ans += dfs(i, (vis | (1<<i)), sz+1);
        }
    }
    return dp[pos][vis]=ans;
}

signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        isEdge[a][b] = isEdge[b][a] = 1;
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        cur = i;
        memset(dp, -1, sizeof(dp));
        ans += dfs(i, (1<<i), 1);
    }
    cout << ans/2;
    return 0;
}

*/



/* Red Blue Green

    Time-Limit: 2 sec Score: 0/100

Difficulty :***

    Memory: 256 MB Accepted Submissions: 100

Relevant For:

Description

You are given a string S of length N. You have to find the minimum number of characters you should change in S so that there will be a substring of length K in S that is also a substring of the infinite string "RGBRGBRGB ...".

Input Format

The first line of the input contains one integer T - the number of test cases. Then T test cases follow.

The first line of each test case contains two space-separated integers N, K.

The second line of each test case contains one string S.

Sum of N across all test cases ≤10^6.

Output Format

For each test case, print the minimum number of characters you should change in S so that there will be a substring of length K in S that is also a substring of the infinite string "RGBRGBRGB ...".

Constraints

1≤ T ≤ 100

1 ≤ K≤ N ≤ 2*105

Sum of N across all test cases ≤10^6.

Sample Input 1

3
4 1
BRRG
4 4
BBBG
2 2
GR

Sample Output 1

0
2
1

Note

For the first test case, any substring of length 1 is also a substring of "RGBRGBRGB …”

For the second test case, change the given string BBBG to GBRG, you change 2 characters.

For the second test case, change the given string GR to GB, you change 1 character.

*/


//arsh agarwal's code:
#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int n, k;
int a[200100];
int dp[200100][3];

int rec(int index, int last){
    if(index<0) return 0;
    if(dp[index][last]!=-1) return dp[index][last];
    int req = (last+2)%3;
    return dp[index][last] = rec(index-1, req) + (a[index]==req ? 0 : 1);
}

void solve(){
    string s; cin>>n>>k>>s; for(int i =0 ; i < n; i++) {
        if(s[i]=='R') a[i]=0;
        else if(s[i]=='G') a[i]=1;
        else if(s[i]=='B') a[i]=2;
        else a[i]=3;
    }

    memset(dp, -1, sizeof(dp));
    int mini = k-1;
    for(int i = k-1; i < n; i++){
        for(int j = 0; j < 3; j++){
            int temp = rec(i, j) - rec(i-k, ((j-k)%3+3)%3);
            mini = min(mini, temp);
        }
    }
    cout << mini << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //solve();
    int t; cin >> t; for(int i = 0; i < t; i++) solve();
    return 0;
}

//shreya singh's code :
#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
// const int mod = 998244353;

int n, k; 
string s; 
int l1, l2; 
int diff[100002][4];

void com(string &t1, string &t2, int id)
{
    for(int i =0; i<t1.size(); i++)
    {
        if((t1[i]!=t2[i]))
        {
            diff[i+1][id]++; 
        }
    }
}

void solve()
{
    cin>>n>>k;   
    cin>>s;
    memset(diff,0,sizeof(diff)); 
    string tmp1, tmp2, tmp3; 
    string str1, str2, str3; 
    tmp1 = "RGB"; 
    tmp2 = "GBR"; 
    tmp3 = "BRG"; 
    int n = s.length(); 
    int q = n/3; 
    int r = n%3; 
    for(int i =0; i<q; i++)
    {
        str1 += tmp1; 
        str2 += tmp2; 
        str3 += tmp3;
    }
    for(int i =0; i<r; i++)
    {
        str1+=tmp1[i]; 
        str2+=tmp2[i]; 
        str3+=tmp3[i]; 
    }
    // cout<<str1<<" "<<str2<<" "<<str3<<'\n'; 
    com(str1, s, 1); 
    com(str2, s, 2); 
    com(str3, s, 3); 

    for(int i =1; i<=n; i++)
    {
       diff[i][1] += diff[i-1][1]; 
       diff[i][2] += diff[i-1][2]; 
       diff[i][3] += diff[i-1][3]; 
    }
    int lft = 0, rgt = k; 
    int ans =1e9; 
    while(rgt<=n)
    {
        ans = min(ans, diff[rgt][1]-diff[lft][1]); 
        ans = min(ans, diff[rgt][2]-diff[lft][2]); 
        ans = min(ans, diff[rgt][3]-diff[lft][3]); 
        lft++, rgt++; 
    } 
    cout<<ans<<'\n'; 
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // solve();
    int t; cin >> t;  while (t--) solve();
    return 0;
}


//another code :

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1e9+7;




ll add(ll a, ll b)
{
    return (a%mod + b%mod)%mod ;
}

class montone_dq
{
public:    
    deque<ll>dq;
    void insert(ll a)
    {
        while (!dq.empty() and dq.back() > a) {
            dq.pop_back();
        }
        dq.push_back(a);
    }
    void remove(ll a)
    {
        if (!dq.empty() and dq.front() == a)
        {
            dq.pop_front();
        }
    }
    
    ll mini()
    {
        if (!dq.empty())
        {
            return dq.front();
        }
        return 1e18;
    }
};

ll dp[20][1<<20];

ll rec(ll root, ll node, ll mask, vector<vector<bool>> &isedge, ll cnt)
{
    if(dp[node][mask] != -1)
        return dp[node][mask] ;

    ll ans = {};
    if(cnt > 2 && isedge[node][root])
        ans++;
    for(ll child = root; child < isedge.size(); child++)
    {
        if(mask & (1 << child))
            continue;
        if(isedge[node][child])
        {
            ans += rec(root, child, mask | (1 << child), isedge, cnt+1);
        }
    }

    return dp[node][mask] = ans;
}

ll f(string &t, string &s, ll k)
{
    ll n = s.size();
    vector<ll> a(n, 0);

    for(int i = 0; i < n; i++)
        if(s[i] != t[i])
            a[i] = 1;

    
    ll cnt = 0;
    int i = 0;
    for( ; i < k; i++)
        cnt += a[i] ;
    ll ans = cnt; 
    int j = 0;
    while(i < n)
    {
        cnt -= a[j] ;
        cnt += a[i] ;
        j++;
        i++;
        ans = min(ans, cnt) ;
    }     
    return ans ;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    
    ll t ;
    t = 1 ;

    
    cin >> t ;
    while(t--)
    {
        ll n, k;
        cin >> n >> k ;
        string s ;
        cin >> s ;
        string a = "RGB";
        string b = "GBR";
        string c = "BRG";
        string aa,bb,cc;
        for(int i = 0; i < n; i++)
        {
            aa.push_back(a[i%3]);
            bb.push_back(b[i%3]);
            cc.push_back(c[i%3]);
        }

        ll ans = f(aa, s, k);
        ans = min(ans, f(bb, s, k));
        ans = min(ans, f(cc, s, k));
        cout << ans << "\n" ;
    
       
        
        

    }

    return 0;
}

/*editorial code and approach:*/

/*Each substring should be made as: "RGBRGB ..." or "GBRGBR ..." or "BRGBRG...".

For the given string, check for each character whether it is it equal to the corresponding character of the string "RGBRGB ..." or "GBRGBR ..." or "BRGBRG...".

You can use prefix sum after checking if the corresponding characters are equal. Find the minimum answer for all substrings of length K.

Time Complexity per test case: O(N)

#include &lt;bits/stdc++.h&gt;
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long

signed main() {
    IOS
    int t;
    cin &gt;&gt; t;
    while (t--) {
        int n, k;
        cin &gt;&gt; n &gt;&gt; k;
        string str;
        cin&gt;&gt;str;
        string s[3];
        for (int i = 1; i &lt;= n; ++i) {
            if(i%3 == 1) s[0]+='R';
            else if(i%3 == 2) s[0]+='G';
            else s[0]+='B';
        }
        for (int i = 1; i &lt;= n; ++i) {
            if(i%3 == 1) s[1]+='G';
            else if(i%3 == 2) s[1]+='B';
            else s[1]+='R';
        }
        for (int i = 1; i &lt;= n; ++i) {
            if(i%3 == 1) s[2]+='B';
            else if(i%3 == 2) s[2]+='R';
            else s[2]+='G';
        }
        int ans = 1e18;
        for (int j = 0; j &lt;= 2; ++j) {
            int a[n];
            for (int i = 0; i &lt; n; ++i) {
                a[i] = 0;
                if(str[i] != s[j][i]) a[i] = 1;
            }
            for (int i = 1; i &lt; n; ++i) {
                a[i] += a[i-1];
            }
            ans = min(ans, a[k-1]);
            for (int i = k; i &lt; n; ++i) {
                ans = min(ans, a[i] - a[i-k]);
            }
        }
        cout &lt;&lt; ans &lt;&lt; "\n";
    }
    return 0;
}*/






 /*Enjoy Products

    Time-Limit: 5 sec Score: 0.00/100

Difficulty :*

    Memory: 256 MB Accepted Submissions: 100

Description

Given three integers l, r and k. Consider an integer x valid, that satisfies these conditions:

→ x is a multiple of k, i.e. x%k=0

→ ∀di ∃dj (di%dj=0) where 0≤i<j≤len(x)−1, where len(x) denotes the number of digits in decimal representation of x and di denotes the i-th most significant digit. d0 is the most significant digit while dlen(x)−1 is the least significant digit of x.

In simple terms, for each digit except dlen(x)−1, there must exist a digit dj to the right of di such that dj divides di.

→ x uses only non-zero digits.

Let Product(n) be a function that returns the product of digits of n.

Among all valid x in the range [l, r], you have to find x with maximum possible positive Product(x). If many such x exist, find the smallest such x.

Input Format

The first line of the input contains one integer T - the number of test cases. Then T test cases follow.

The first line of each test case contains three space-separated integers l, r, k.

Output Format

For each test case print two integers - Product(x) and x. If there is no such x, print a single integer -1.

Constraints

1 ≤ T ≤ 5

1 ≤ k ≤ 100

1 ≤ l ≤ r ≤ 1018

Sample Input 1

5
159921445099135603 233682204968165551 63
667321851270492152 878457389026263720 82
280717917593468408 696531322454635758 68
339298162629998972 847460707432092007 75
357628567816161563 394215645030664983 94

Sample Output 1

1464114717117504 189999989999999991
1424967069597696 686668888888888882
2251799813685248 488848888888888884
-1
-1

*/


//arsh agarwal;s code 
#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll dp[20][100][2][2][1<<10][2]; // flag 0 means no non zero integer has been taken yet
int back[20][100][2][2][1<<10][2];
int n, k;
string l, r;
ll rec(int level, int sum, int left, int right, int mask, int flag){
    if(level==n) return sum==0 and mask==0 ? 1LL : 0LL;
    if(dp[level][sum][left][right][mask][flag]!=-1) return dp[level][sum][left][right][mask][flag];
    ll ans = 0LL;
    if(flag==0 and l[level]=='0'){
        ans = rec(level+1, 0, 1, right and r[level]=='0', 0, 0);
        back[level][sum][left][right][mask][flag] = 0;
    }
    int lo = 1, hi = 9;
    if(left and l[level]!='0') lo = l[level]-'0';
    if(!(right and r[level]=='0')){
        if(right) hi = r[level]-'0';
        for(int i = lo; i <= hi; i++){
            int nmask = mask;
            for(int j = i; j <= 9; j+=i){
                if((nmask>>j)&1) (nmask^=(1<<j));
            }
            if(level!=n-1) nmask|=(1<<i);
            ll temp = i*rec(level+1, (10*sum+i)%k, left and l[level]==i+'0', right and r[level]==i+'0', nmask, 1);
            if(temp > ans) ans = temp, back[level][sum][left][right][mask][flag] = i;
        }
    } 
    return dp[level][sum][left][right][mask][flag] = ans;
}

void solve(){
    cin>>l>>r>>k; while(l.length() < r.length()) l = '0' + l;
    n = l.length();
    memset(dp, -1, sizeof(dp));
    ll pdt = rec(0, 0, 1, 1, 0, 0);
    if(pdt==0) {cout << -1 << '\n'; return;}
    cout << pdt << ' ';

    int sum = 0, flag = 0, left = 1, right = 1, mask = 0;
    string ans;
    for(int i = 0; i < n; i++){
        int val = back[i][sum][left][right][mask][flag];
        if(val==0){
            left = left and l[i]=='0' ? 1 : 0;
            right = right and r[i]=='0' ? 1 : 0;
            continue;
        }
        ans += char(val+'0');
        flag = 1;
        sum = (10*sum+val)%k;
        left = left and l[i]==val+'0' ? 1 : 0;
        right = right and r[i]==val+'0' ? 1 : 0;
        for(int j = val; j < 10; j+=val){
            if((mask>>j)&1) mask^=(1<<j);
        }
        mask|=(1<<val);
    }
    cout << ans << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //solve();
    int t; cin >> t; for(int i = 0; i < t; i++) solve();
    return 0;
}


// another one :
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int k, n;
string l, r;
string ans;
ll dp[20][2][2][2][100][(1<<9)];
int bk[20][2][2][2][100][(1<<9)];

ll rec(int level, bool tlo, bool thi, bool prev, int cur, int mask)
{
    if(level == n)
    {
        if(__builtin_popcount(mask)==1 && cur==0)
            return dp[level][tlo][thi][prev][cur][mask] = 1;
        return dp[level][tlo][thi][prev][cur][mask] = 0;
    }

    ll ans = dp[level][tlo][thi][prev][cur][mask];
    int bn = bk[level][tlo][thi][prev][cur][mask];
    if(ans != -1)   return ans;
    ans = 0;
    int lo = (tlo) ? l[level]-'0' : 0;
    int hi = (thi) ? r[level]-'0' : 9;
    for(int i=lo; i<=hi; i++)
    {
        int ncur = (cur*10+i) % k;
        bool ntlo = tlo & (i==lo);
        bool nthi = thi & (i==hi);
        int curr_val = (i==0 && prev==0) ? 1 : i;
        int nmask = (i==0) ? mask : (mask|(1<<(i-1)));
        for(int j=2*i; j<=9&&i; j+=i)
            if((nmask>>(j-1))&1)
                nmask ^= (1<<(j-1));
        ll temp = curr_val * rec(level+1, ntlo, nthi, prev|(i>0), ncur, nmask);
        if(temp > ans)
            ans = temp, bn = i;
    }
    dp[level][tlo][thi][prev][cur][mask] = ans;
    bk[level][tlo][thi][prev][cur][mask] = bn;
    return ans;
}

void getAns(int level, bool tlo, bool thi, bool prev, int cur, int mask)
{
    if(level == n)
        return;
    int cn = bk[level][tlo][thi][prev][cur][mask];
    ans.push_back(cn+'0');
    int nmask = (cn) ? (mask|(1<<(cn-1))) : mask;
    int ncur = (cur * 10 + cn) % k;
    if(cn==0) ncur = 0;
    int lo = (tlo) ? l[level]-'0' : 0;
    int hi = (thi) ? r[level]-'0' : 9;
    bool ntlo = tlo & (cn==lo);
    bool nthi = thi & (cn==hi);

    for(int j=2*cn; j<=9&&cn; j+=cn)
        if((nmask>>(j-1))&1)
            nmask ^= (1<<(j-1));

    getAns(level+1, ntlo, nthi, prev|(cn>0), ncur, nmask);
}

void solve()
{
    ans.clear();
    cin >> l >> r >> k;
    n = r.length();
    l = string(r.length()-l.length(), '0') + l;
    memset(dp, -1, sizeof(dp));
    memset(bk,  0, sizeof(bk));
    ll af = rec(0, 1, 1, 0, 0, 0);
    if(af == 0)
    {
        cout << -1 << "\n";
        return;
    }
    cout << af << " ";
    getAns(0, 1, 1, 0, 0, 0);
    ll i = 0;
    while(i<ans.length() && ans[i]=='0')
        i++;
    cout << ans.substr(i) << "\n";
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}




/* Minimum Edge Deletion to make DAG

    Time-Limit: 5 sec Score: 0/100

Difficulty : ****

    Memory: 256 MB Accepted Submissions: 100

Description

Find the minimum number of edges to be deleted to make a Directed Graph a DAG (directed acyclic graph).

Input Format

The first line contains an integer T (1 ≤ T ≤ 50) - the number of testcases.

The first line of each test case contains an integer N. 1 ≤ N ≤ 15.

The next N lines contains N space-separated integers, IsEdge[i][j] which denotes if there is an edge from node i to node j. IsEdge[i][j] = 0 if there is no edge from node i to node j and IsEdge[i][j] = 1 if there is an edge from node i to node j.

Given graph is directed.

Output Format

For each test case print the output in a new line.
Sample Input 1

10
8
1 0 0 1 1 0 0 0
0 0 0 1 1 0 0 0
0 1 1 0 1 0 0 0
0 0 0 1 1 0 0 0
1 0 0 0 0 0 1 1
0 0 0 0 0 1 1 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 1
5
1 1 0 0 0
0 1 0 1 1
0 1 0 1 1
0 1 0 0 0
0 0 1 1 1
2
0 1
0 0
6
0 1 0 0 1 0
0 1 0 0 0 1
0 1 0 0 0 0
0 0 0 1 0 0
0 0 0 0 0 0
1 0 0 0 1 1
11
0 1 0 0 0 0 1 1 0 0 0
1 0 0 0 0 0 0 0 0 0 0
0 0 1 0 1 0 0 1 1 1 1
0 0 0 0 1 0 1 1 0 0 1
1 0 1 1 0 0 0 1 0 0 1
1 0 0 0 0 0 0 0 0 0 0
0 1 0 0 0 0 0 0 0 0 0
0 0 1 0 0 1 0 0 0 0 0
0 1 0 0 0 1 0 0 0 0 1
0 0 0 0 0 0 0 0 1 1 0
1 1 1 0 0 0 0 0 0 0 1
2
1 1
0 0
4
0 0 1 1
0 0 0 0
1 1 0 0
1 0 0 0
5
0 1 0 0 0
1 0 0 0 1
0 0 0 0 1
0 0 0 1 0
1 0 1 0 0
3
0 0 0
0 0 0
0 0 0
8
0 0 0 0 0 1 0 0
0 1 0 0 0 0 0 0
1 0 0 0 0 0 0 1
1 0 0 0 1 1 0 0
0 0 0 0 0 0 1 0
0 0 0 1 1 0 0 1
0 0 1 0 0 0 1 0
0 0 0 0 0 0 1 0 

Sample Output 1

1
2
0
1
6
0
2
2
0
2

*/
// solution
#include<bits/stdc++.h>
using namespace std;

#define int long long 

int n; 
int edge[15][15];
int dp[(1<<15)];
int vis[(1<<15)];

int rec(int pos,int mask){
    if(pos == n) return 0 ; 
    
    if(vis[mask]) return dp[mask] ; 
    
    int ans = 1e18 ;
    
    for(int i=0;i<n;i++){
        if(mask&(1<<i)) continue; 
        
        int temp = 0 ; 
        for(int j=0;j<n;j++){
            if(mask&(1<<j) && edge[i][j]) temp++;
        }

        ans = min(ans,temp + rec(pos+1,mask|(1<<i)));
    }
    
    vis[mask] = 1; 
    return dp[mask] = ans; 
}

void solve(){
    cin>>n;
    memset(vis,0,sizeof(vis));
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>edge[i][j];
        }
    }
    
    int ans = 1e18 ;

    for(int i=0;i<n;i++){
        ans = min(ans,rec(1,1<<i));
    }

    cout<<ans<<endl ;

    return ; 
}

signed main(){
    int t; 
    cin>>t; 
    
    while(t--){
        solve();
    }
    return 0 ;
}


//arsh agarwal's code :
#include <bits/stdc++.h> 
using namespace std;
#define int long long

int n;
int a[15][15];
int dp[1<<15];
int rec(int mask){
    if(mask==((1<<n)-1)) return 0;
    if(~dp[mask]) return dp[mask];
    int ans = 1e18;
    for(int i = 0; i <n ; i++){
        if((mask>>i)&1) continue;
        int cost = 0;
        for(int j = 0; j < n; j++) cost += (((mask>>j)&1) and a[i][j]);
        ans = min(ans, cost + rec(mask|(1<<i)));
    }
    return dp[mask] = ans;
}

void solve(){
    cin>>n; for(int i = 0 ;i < n; i++) for(int j = 0; j < n; j++) cin>>a[i][j];
    memset(dp, -1, sizeof(dp));
    cout << rec(0) << '\n';
}   

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //solve();
    int t; cin >> t; for(int i = 0; i < t; i++) solve();
    return 0;
}

//shreya singh's code:
//श्रमं विना न किमपि साध्यम्
#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
// const int mod = 998244353;

int n; 
int edges[16][16]; 
int dp[16][(1<<16)]; 

long long rec(int node, int mask)
{
    if(mask==((1<<n)-1))
    {
        return 0; 
    }
    if(dp[node][mask] !=-1)
    {
        return dp[node][mask]; 
    }
    long long ans = 1e9; 
    for(int i =0; i<n; i++)
    {
        if(!(mask&(1<<(i))))
        {
            int cnt =0; 
            for(int j =0; j<n; j++)
            {
                if(mask&(1<<(j)) && edges[i][j])
                {
                    cnt++; 
                }
            }
            ans = min(ans,(rec(i, (mask|(1<<(i)))) + cnt)); 
        }
    }
    return dp[node][mask] = ans; 
}

void solve()
{
    cin>>n; 
    memset(edges,0,sizeof(edges)); 
    memset(dp,-1,sizeof(dp)); 
    for(int i =0; i<n; i++)
    {
        for(int j =0; j<n; j++)
        {
            cin>>edges[i][j]; 
        }
    }
    long long ans = 1e9; 
    for(int i =0; i<n; i++)
    {
        ans = min(ans, rec(i,1<<i)); 
    }
    cout<<ans<<'\n'; 
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // solve();
    int t; cin >> t;  while (t--) solve();
    return 0;
}

/*approach and editorial code :

We need to make the directed graph, acyclic. This can be done by removing any cycles in the graph. It would be difficult to think in terms of finding cycles and then removing the edges. Can you use topological sorting to find the cycles?

If we find the topological sorting of a graph, the back edges, i.e. any edge from j to i (i < j), if removed will result in a DAG. But there are multiple number of topological sortings present in a graph, so you need to consider all of them and find the minimum edges to remove.

We would make the DP array as DP[pos][vis] which denotes the minimum edges to delete to make the graph DAG, pos denotes the current vertex we are at and vis denotes the subset of vertices we have visited. When we need to assign a vertex to the current position, we need to ensure that the vertex has not been visited and for finding the back edges from i to the vertices already visited, we would use another loop and check this.

Optimisation similar to the problem Chess and GCD can be made here. The current vertex, pos would be equal to the number of vertices we have already visited, so the DP array can be made as DP[vis].

Time Complexity per test case: O(N^2 * 2^N)

#include <bits/stdc++.h>
using namespace std;

#define int long long

bool isEdge[15][15];
int dp[(1<<15)];
int n;

int dfs(int vis) {
    int pos = __builtin_popcount(vis);
    if(pos == n) {
        return 0;
    }
    if(dp[vis] != -1) {
        return dp[vis];
    }
    int ans = 2e18;
    for (int i = 0; i < n; ++i) {
        if((vis & (1<<i)) == 0) {
            int temp = 0;
            for (int j = 0; j < n; ++j) {
                if(vis & (1<<j)) {
                    temp += isEdge[i][j];
                }
            }
            ans = min(ans, dfs(vis | (1<<i)) + temp);
        }
    }

    dp[vis] = ans;
    return ans;
}

signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        cin >> n;
        for (int j = 0; j < (1<<n); ++j) {
            dp[j] = -1;
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> isEdge[i][j];
            }
        }
        cout << dfs(0) << "\n";
    }
    return 0;
}

*/




/* Tiling

    Time-Limit: 5 sec Score: 0/100

Difficulty : ****

    Memory: 256 MB Accepted Submissions: 100

Description

Find the number of ways to Tile NxM rectangle with dominoes. A domino is 2 * 1 or 1 * 2 rectangle.

Input Format

The first line contains an integer T (1 ≤ T ≤ 100) - the number of testcases.

The first line of each test case contains two space-separated integers N, M. 1 ≤ N, M ≤ 12.
Sample Input 1

7
10 3
10 5
2 3
10 1
2 4
5 4
9 11

Sample Output 1

571
185921
3
1
5
95
0

*/


#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int n, m;
ll dp[12][12][1<<12];
ll rec(int x, int y, int mask){
    mask&=((1<<m)-1);
    if(x==n-1 and y==m-1) return ((mask == ((1<<m)-2)) or (mask == (1<<(m-1))-1)) ? 1 : 0;
    if(dp[x][y][mask]!=-1) return dp[x][y][mask];
    ll ans = 0;
    int nx = x + (y==m-1 ? 1 : 0);
    int ny = (y+1)%m;
    //place horizontal block
    if(((mask>>(m-1))&1) == 0){
        ans = rec(nx, ny, mask<<1|1);
    }else{
        ans = rec(nx, ny, mask<<1);
        if(y and ((mask&1)==0)) ans += rec(nx, ny, (mask<<1)+3);
    }
    return dp[x][y][mask] = ans;
}

void solve(){
    cin>>n>>m; memset(dp, -1, sizeof(dp));
    cout << rec(0, 0, (1<<m)-1) << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //solve();
    int t; cin >> t; for(int i = 0; i < t; i++) solve();
    return 0;
}

/*approach  and editorial code :

If the number of columns and number of rows is odd, the answer would be 0 since each domino occupies an area of 2. You can consider each column as a binary number which gives the information whether the i-th bit in that column is filled with a domino or not.

We make the DP array as DP[pos][vis] (1-based indexing for pos) which denotes the number of ways to fill the grid where pos is the current row and vis denotes the blocks filled in the current row. All the blocks before the pos row must be completely filled. One way to make the transition would be to find DP[pos][vis] from DP[pos-1][n_vis] by using the different possible values of n_vis for which there exists a filling of pos-th row with the same set of filled blocks. But you will get TLE in this since the time complexity will be O(N * 2^(2*M))

Instead of finding all the different possible masks of the previous rows, we can find the different possible masks for the current row to get the answer. This means that we need to find the number of ways to fill the current row with blocks filled as vis. We can make the following cases:

1. If the current block is already filled, we go on to the next block.

2. If the current block is not filled, we can place the block as either 12 or 21 form and go on to the next block after updating the blocks visited for the current row and the next row (for 12 domino)

Whenever we fill the current row completely, a new set of blocks are marked in the next row because of the 12 dominos, so we need to add that to the answer for the next row. For i = 0, filling 0 cells is possible so the base case is DP[0][0] = 1. We need to fill all the n rows such that the columns visited for the next row is 0 and all rows before n are completely filled, so the final answer would be DP[n][0].

Time Complexity per test case: O(N^2 * M * 2^M)

#include <bits/stdc++.h>
using namespace std;

#define int long long

int dp[13][(1<<12)];
int n, m;

void dfs(int x, int y, int vis, int nvis) {
    if(x == n) {
        return ;
    }
    if(y >= m) {
        dp[x+1][nvis] += dp[x][vis];
        return ;
    }
    int mask = 1<<y;
    if(vis & mask) {
        dfs(x, y+1, vis, nvis);
    }
    else {
        dfs(x, y+1, vis, nvis | mask);
        if(y + 1 < m && !(vis & mask) && !(vis & (mask << 1))) {
            dfs(x, y+2, vis, nvis);
        }
    }
}

signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        cin >> n >> m;
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < (1<<m); ++j) {
                dfs(i, 0, j, 0);
            }
        }
        cout << dp[n][0] << "\n";
    }
    return 0;
}

*/



/* Rearrange Marbles

    Time-Limit: 2 sec Score: 0/100

Difficulty : *

    Memory: 256 MB Accepted Submissions: 100

Description

You are given N1 indistinguishable marbles of green colour and N2 indistinguishable marbles of red colour. You have to find the number of arrangements such that no more than K1 consecutive marbles of green colour and no more than K2 consecutive marbles of red colour are adjacent to each other.

Input Format

The first line of the input contains one integer T - the number of test cases. Then T test cases follow.

The first and only line of each test case contains four space-separated integers N1, N2, K1, K2.

Output Format

For each test case, print the required number of arrangements. Since the answer can be large, print it modulo 108.

Constraints

1≤ T ≤ 1000

1≤ N1, N2 ≤ 100

1≤ K1, K2 ≤ 10

Sample Input 1

3
2 2 1 5
2 4 1 2
3 5 2 1

Sample Output 1

3
5
0

Note

For the first test case, the following are the 3 different arrangements possible:

For the second test case, the following are the 5 different arrangements possible:

For the third test case, there are no arrangements possible.

*/

//arsh agarwal's code:
#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll mod = 1e8;
int k1, k2, n1, n2;
ll dp[101][101][2];
ll rec(int x, int y, int flag){
    if(x==0 and y==0) return 1;
    if(dp[x][y][flag]!=-1) return dp[x][y][flag];
    ll ans = 0;
    if(flag){
        for(int i = 1; i <= min(k1, x); i++) (ans += rec(x-i, y, 0))%=mod;
    }else{
        for(int i = 1; i <= min(k2, y); i++) (ans += rec(x, y-i, 1))%=mod;
    }
    return dp[x][y][flag] = ans;
}

void solve(){
    cin>>n1>>n2>>k1>>k2;
    memset(dp, -1, sizeof(dp));
    cout << ((rec(n1, n2, 0) + rec(n1, n2, 1))%mod) << '\n';
}   

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //solve();
    int t; cin >> t; for(int i = 0; i < t; i++) solve();
    return 0;
}

/*approach and editorial :
We make a DP array, where DP[i][j][f] is the i number of green marbles and j number of red marbles are left. f=0 counts the arrangements that begin with green marbles and f=1 counts the arrangements that begin with red marbles.

The number of arrangements in which there are green marbles in the very left is equal to dp[n1][n2 - 1][0] + ... + dp[n1][n2 - min(k2,n2)][0] since there can’t be more than min(k1,n1) number of green marbles on the left. We do the same for red marbles.

Time Complexity per test case: O(N1*N2*20)

#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

const int mod=1e8;

int dp[101][101][2];
int k1,k2;

int calc(int n1, int n2, bool f) {
   if(n1 + n2 == 0)
       return 1;
   if(dp[n1][n2][f] != -1)
       return dp[n1][n2][f];

   dp[n1][n2][f]=0;
   if(f==0){
       for(int i = 1; i <= min(n1,k1); ++i) {
           dp[n1][n2][f] = (dp[n1][n2][f] + calc(n1-i,n2,1-f))%mod;
       }
   }
   else{
       for (int i = 1; i <= min(n2,k2); ++i) {
           dp[n1][n2][f] = (dp[n1][n2][f] + calc(n1,n2-i,1-f))%mod;
       }
   }
   return dp[n1][n2][f];
}

int main() {
   IOS
   int t;
   cin >> t;
   while (t--) {
       int n1, n2;
       cin >> n1 >> n2 >> k1 >> k2;
       for (int i = 0; i <= n1; ++i) {
           for (int j = 0; j <= n2; ++j) {
               dp[i][j][0]=dp[i][j][1]=-1;
           }
       }
       cout<<(calc(n1,n2,0) + calc(n1,n2,1))%mod<<"\n";
   }
   return 0;
}

*/


/* Special Numbers 2

    Time-Limit: 5 sec Score: 0/100

Difficulty :*

    Memory: 256 MB Accepted Submissions: 100

Description

The score of a number consisting of N digits {d1, d2, d3, …, dN} is given as a summation of didi for all 1 ≤ i ≤ N and di ≠0. A number is called special if the score of the number is divisible by all its digits di excluding di=0. For example score of a number 2024 = 22 + 22 + 44 = 264 and 264 is divisible by 2 and 4, so it is a special number.

Given two integers l, r. Find the number of special integers in the range [l, r].

Input Format

The first line of the input contains one integer T - the number of test cases. Then T test cases follow.

The first line of each test case contains two space-separated integers l, r.

Output Format

For each test case print the number of special numbers in the range[l,r].

Constraints

1 ≤ T ≤ 5

1 ≤ l ≤ r ≤ 1012
Sample Input 1

5
150018195126 600174558109
749580912942 895657939678
621006809728 904294359649
35 965470057256
49 230582460206

Sample Output 1

1997439573
467055118
974517934
4172204822
1248761567

*/

//arsh agarwal's code :

#include<bits/stdc++.h>
using namespace std;
#define ll long long int

string l, r;
int n;
ll val[10];
ll dp[12][2][2][512][2520];

ll rec(int level, int left, int right, int mask, int sum){
    if(level==n){
        bool done = true;
        for(int i = 1; i < 10; i++){
            if(((mask>>(i-1))&1) and sum%i !=0) {done=false; break;}
        }
        return done ? 1 : 0;
    }

    if(dp[level][left][right][mask][sum]!=-1) return dp[level][left][right][mask][sum];
    ll ans = 0;
    int lo = 0, hi = 9;
    if(left) lo = l[level]-'0';
    if(right) hi = r[level]-'0';
    for(int i = lo; i <= hi; i++){
        ans += rec(level+1, left and i==lo ? 1 : 0, right and i==hi, mask|(1<<(i-1)), (sum+val[i])%2520);
    }
    return dp[level][left][right][mask][sum] = ans;
}

void solve(){
    cin>>l>>r; while(l.length() < r.length()) l = '0'+l; n = l.length();
    val[0]=0; for(ll i = 1; i < 10; i++) {val[i]=1LL; for(int j = 1; j<=i; j++) val[i]*=i;}
    memset(dp, -1, sizeof(dp));
    cout << rec(0, 1, 1, 0, 0) << '\n';
}   

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //solve();
    int t; cin >> t; for(int i = 0; i < t; i++) solve();
    return 0;
}



/* K-Special Numbers

    Time-Limit: 10 sec Score: 0/100

Difficulty :****

    Memory: 256 MB Accepted Submissions: 100

Relevant For:

Description

A number N is said to be K-Special if there exist K or more distinct digits, such that N is divisible by those digits and those digits are present in the decimal representation of the number. You will be given T queries, each asking the number of K-special numbers between L and R(inclusive).

Input Format

The first line of the input contains one integer T - the number of test cases. Then T test cases follow.

The first line of each test case contains three space-separated integers K, L, and R.

Output Format

For each query, print an integer denoting the number of K-special numbers between L and R(inclusive) on a separate line.

Constraints

1 ≤ T ≤ 5

1 ≤ L ≤ R ≤ 1018

0 ≤ K ≤ 9

Sample Input 1

4
1 1 9
2 20 40
0 5 10
2 40 50

Sample Output 1

9
2
6
1

Note

In the first test case, all numbers from 1 to 9 are divisible by at least K=1 of their digits.

In the second test case, numbers 24 and 36 are divisible by at least K=2 distinct digits.

In the third test case, all numbers from 5 to 10 are divisible by at least K=0 distinct digits.

In the fourth test case, 48 is divisible at least K=2 distinct digits.

*/

// arsh agarwal's code 


#include<bits/stdc++.h>
using namespace std;
#define ll long long int

string s;
int n, k;
ll dp[19][2][512][2520];
ll rec(int level, int right, int mask, int sum){
    if(level==n){
        int cnt = 0;
        for(int i = 1; i < 10; i++){
            if((mask>>(i-1))&1 and sum%i == 0) cnt++;
        }
        //cout << level << ' ' << right << ' ' << mask << ' ' << sum << ' ' << flag << ' ' << cnt  << '\n';
        return cnt < k ? 0 : 1;
    }
    if(dp[level][right][mask][sum]!=-1) return dp[level][right][mask][sum];
    ll ans = 0;
    int hi = 9; if(right) hi = s[level]-'0';
    for(int i = 0; i <= hi; i++){
        ans += rec(level+1, right and i==hi, i==0 ? mask : (mask|(1<<(i-1))), (10*sum+i)%2520);
    }
    return dp[level][right][mask][sum] = ans;
}

void solve(){
    ll a, b; cin>>k>>a>>b; a--; 
    string l = to_string(a), r = to_string(b);
    while(l.length() < r.length()) l = '0'+l; n = l.length();
    memset(dp, -1, sizeof(dp));
    s = r; ll ans = rec(0, 1, 0, 0);
    memset(dp, -1, sizeof(dp));
    s = l; ans -= rec(0, 1, 0, 0);
    cout << ans << '\n';
}   

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //solve();
    int t; cin >> t; for(int i = 0; i < t; i++) solve();
    return 0;
}


/*Make DP array DP[index][num][mask][smaller_already] - the number of ways to choose digits so far such that the number modulo lcm is ‘num’ (lcm can be taken as the lcm of first 10 integers), the digits which we have chosen is ‘mask’ and ‘smaller_already’ says whether we have already chosen some digits smaller than the corresponding digit in K.

Taking lcm of the first 10 integers as 2520 will result in TLE. Optimize it to avoid TLE.

Instead of taking lcm of the first 10 integers as 2520, take it as 504. Do not consider 5 in LCM as divisibility by 5 depends only on the last digit of the number, which you can store for every transition.

For each possible digit in the i-th position of the given number, the DP transition will be:

DP[i][num][mask][smaller] += DP[i+1][(num*10+digit)%504][mask|(1<<(digit-1))][smaller||(digit<t] where t is the corresponding digit in K.

Time Complexity per test case: O(log10(R) * 504 * (1<<9) * 2)

*/




/* Maximum Cost Tree

    Time-Limit: 5 sec Score: 0.00/100

Difficulty :****

    Memory: 256 MB Accepted Submissions: 100

Relevant For:

Description

You are given a tree consisting exactly of 𝑛 vertices. Each vertex 𝑣 of this tree has a value 𝑎𝑣 assigned to it.

Let 𝑑𝑖𝑠𝑡(𝑥,𝑦) be the distance between the vertices 𝑥 and 𝑦. The distance between the vertices is the number of edges on the simple path between them.

Let's define the cost of the tree as the following value: firstly, let's fix some vertex of the tree. Let it be 𝑣. Then the cost of the tree is 

Your task is to calculate the maximum as well as minimum possible cost of the tree if you can choose 𝑣 arbitrarily to calculate the answer for both the case.

Input Format

The first line contains an integer T ( 1 ≤ T ≤ 10^5) - the number of test cases.

The first line of each test case contains an integer N( 1 ≤ N≤ 10^5).

The second line of each test case contains N space-separated integers  1 ≤ ai ≤ 10^5.

The next N-1 lines contain a description of an edge → ui, vi (1 ≤ ui, vi ≤ N, ui≠vi,). Vertices ui and vi are connected by an undirected edge.

It is guaranteed that sum of all N over all test cases does not exceed 10^6.

Output Format

For each test print the maximum and minimum cost in a new line.
Sample Input 1

1
5
1 2 3 4 5
1 2
1 3
2 4
2 5

Sample Output 1

32 16

*/

#include <bits/stdc++.h>
using namespace std;
#define int long long

int indp[100100], outdp[100100];
int sum[100100], sz[100100], a[100100];
vector<vector<int>> g;
int indfs(int node, int par){
    sum[node] = a[node];
    indp[node] = 0;
    for(auto it: g[node]){
        if(it==par) continue;
        indfs(it, node);
        indp[node] += indp[it] + sum[it];
        sum[node] += sum[it];
    } 
}

void outdfs(int node, int par){
    if(node==1) outdp[node] = 0;
    else{
        outdp[node] = outdp[par] + sum[1] - sum[node] + indp[par] -indp[node] - sum[node];
    }

    for(auto it: g[node]){
        if(it==par) continue;
        outdfs(it, node);
    }
}

void solve(){
    int n; cin>>n; g.clear(); g.resize(n+1);
    for(int i = 1; i <= n; i++) cin>>a[i];
    for(int i = 0; i < n-1; i++){
        int x, y; cin>>x>>y; g[x].push_back(y); g[y].push_back(x);
    }
    indfs(1, 0); outdfs(1, 0);
    int maxi = 0, mini = 1e18;
    for(int i = 1; i <= n; i++) maxi = max(maxi, outdp[i]+indp[i]), mini = min(mini, outdp[i]+indp[i]);
    cout << maxi << ' ' << mini << '\n';
} 
 
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t; while(t--) 
    solve();
    return 0;
}



/* Minimum Inversion Of Edges

    Time-Limit: 5 sec Score: 0/100

Difficulty : ***

    Memory: 256 MB Accepted Submissions: 100

Relevant For:

Description

You are given a graph of N nodes having N-1 directed edges. If we don't take the direction of edges into consideration then the graph is a tree.

You have to find all the nodes u, such that it is possible to move from node u to all the other nodes by changing the direction of minimum number of edges.

Print the minimum number of inversions required such that it is possible to reach all the nodes from a node u. After that print all the possible node u in ascending order in the next line.

Input Format

The first line contains an integer T ( 1 ≤ T ≤ 10^5) - the number of test cases.

The first line of each test case contains an integer N( 1 ≤ N≤ 10^5).

The next N-1 lines contain a description of an edge → ui, vi (1 ≤ ui, vi ≤ N, ui≠vi,). Vertices ui and vi are connected by a directed edge from ui to vi.

It is guaranteed that sum of all N over all test cases does not exceed 10^6.

Output Format

Print the minimum number of inversions required such that it is possible to reach all the nodes from a node u. After that print all the possible node u in ascending order in the next line.
Sample Input 1

2
8
1 2
3 2
4 3
4 5
6 5
6 7
8 7
10
2 3
1 8
9 5
5 4
6 10
4 8
5 6
7 6
5 3

Sample Output 1

3
4 6 8 
3
9 

*/


#include<bits/stdc++.h>
using namespace std;
#define int long long
using pii = pair<int, int>;
int n;
vector<vector<pii>> g;
int indp[100100];
int outdp[100100];

void fillindp(int node, int par) {
    indp[node] = 0;
    for(auto it: g[node]) {
        int v = it.first;
        int w = it.second;
        if(v == par) continue;

        fillindp(v, node);
        indp[node] += w + indp[v];
    }
}

void filloutdp(int node, int par) {
    if(par == 0) outdp[node] = 0;

    for(auto it: g[node]) {
        int v = it.first;
        int w = it.second;
        if(v == par) continue;

        outdp[v] = outdp[node]+(1-w)+(indp[node]-indp[v]-w);
        filloutdp(v, node);
    }
}
void solve() {
    cin>>n;
    g.clear();
    g.resize(n+1);
    for(int i = 0; i < n-1; i++) {
        int u, v;
        cin>>u>>v;
        g[u].push_back({v, 0});
        g[v].push_back({u, 1});
    }
    fillindp(1, 0);
    filloutdp(1, 0);

    vector<int> ans;
    int mini = 1e9;
    for(int i = 1; i <= n; i++) {
        mini = min(mini, indp[i]+outdp[i]);
    }
    for(int i = 1; i <= n; i++) {
        if(indp[i]+outdp[i] == mini) ans.push_back(i);
    }
    cout<<mini<<endl;
    for(auto it : ans) {
        cout<<it<<" ";
    }
    cout<<endl;
}
signed main() {
    int t; 
    cin>>t;
    while(t--) {
        solve();
    }
}

//arsh agarwal's code:
#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int n;
vector<vector<pair<int,int>>> g;
int indp[100100];
int sz[100100];
void rec(int node, int par){
    int ans = 0;
    int size = 1;
    for(auto it: g[node]){
        if(it.first==par) continue;
        rec(it.first,node);
        ans += indp[it.first] + it.second;
        size += sz[it.first];
    }
    sz[node] = size;
    indp[node] = ans;
}

int outdp[100100];
void dfs(int node, int par, int out){
    outdp[node] = out;
    for(auto it: g[node]){
        if(it.first==par) continue;
        int nout = out + ((indp[node] - indp[it.first]) - it.second) + 1-it.second;
        dfs(it.first, node, nout);
    }
}

void solve(){
    cin>>n; g.clear(); g.resize(n+1);
    for(int i = 0; i < n-1; i++){
        int a, b; cin>>a>>b; g[a].push_back({b,0}); g[b].push_back({a,1});
    }
    rec(1, 0);
    dfs(1, 0, 0);
    // for(int i = 1; i <= n; i++) cout << indp[i] << ' '; cout << '\n';
    // for(int i = 1; i <= n; i++) cout << outdp[i] << ' '; cout << '\n';
    int mini = 1e9;
    set<int> ans;
    for(int i = 1; i <= n; i++){
        int cur = indp[i] + outdp[i];
        if(mini>cur){
            mini = cur; ans.clear(); ans.insert(i);
        }else if(mini==cur){
            ans.insert(i);
        }
    }
    cout << mini << '\n';
    for(auto it: ans) cout << it << ' '; cout << '\n';
}   

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //solve();
    int t; cin >> t; for(int i = 0; i < t; i++) solve();
    return 0;
}




