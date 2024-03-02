/* How Many Solutions

    Time-Limit: 3 sec Score: 0.00/100

Difficulty :

    Memory: 256 MB Accepted Submissions: 100

Relevant For:

Description

Given the value of integer N how many solutions does the following equation have?

If x and y are integers there is only a finite number of solutions but if x and y are real numbers then there can be an infinite number of solutions. What if x and y are floating-point numbers with limited size, e.g. x and y are floating point numbers with d digits after the decimal points, how many different solutions will be there?

Input Format

Input file contains at most 2000 lines of input. Each line contains two integers N (0 < N ≤ 10000000000) and d (0 ≤ d ≤ 1000), here d means that there can be maximum d digits after the decimal point. Input is terminated by a line containing two zeros. This line should not be processed.

Output Format

For each line of input, produce one line of output which contains an integer T. This line contains the number of different solutions the equation has for the given value of N and d. As the value of T can be very large so output T modulo 1000007.
Sample Input 1

23 10
10 2
0 0

Sample Output 1

2645
97

*/


//solution approach& editorial code:
/*Can you frame the given equation to this format? The task will be much easier then.
(x−n)(y−n)=n2

1/x+1/y=1/N

xy−nx−ny=0
xy−nx−ny+n2=n2
x(y−n)−n(y−n)=n2
(x−n)(y−n)=n2
Replace x−n=a, and
y−n=b
a×b=n2

Note :
We subtract 1
at the end to take care of the case when x=y=0. Since that is not a valid option so we need to subtract 1

from the final solution.

1/x+1/y=1/N

xy−nx−ny=0
xy−nx−ny+n2=n2
x(y−n)−n(y−n)=n2
(x−n)(y−n)=n2
Replace x−n=a, and
y−n=b
a×b=n^2

Note :
We subtract 1
at the end to take care of the case when x=y=0. Since that is not a valid option so we need to subtract 1

from the final solution.

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll mod = 1e9 + 7;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while (true)
    {
        ll n, d;
        cin >> n >> d;

        if (!n && !d)
            break;

        map<ll, ll> M;

        for (ll i = 2; i * i <= n; i++)
        {
            ll cnt = 0;
            while (n % i == 0)
            {
                n /= i;
                cnt++;
            }
            if (cnt)
                M[i] += 2 * cnt;
        }

        if (n > 1)
            M[n] += 2;

        M[2] += 2 * d;
        M[5] += 2 * d;

        ll ans = 1;
        bool sqr = true;

        ll mod = 1000007;

        for (auto it : M)
        {
            ans *= (it.second + 1);
            ans %= mod;
            if (ans < 0)
                ans += mod;
            if (it.second % 2)
                sqr = false;
        }

        ans *= 2;
        ans %= mod;
        if (ans < 0)
            ans += mod;

        if (sqr)
            ans = (ans - 1 + mod) % mod;

        cout << ans << "\n";
    }
}

*/

// arsh agarawal:
#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll mod = 1000007LL;

void solve(){
	while(1){
		ll n, d; cin >> n >> d; if(n==0) break;
		ll lim = min((ll) sqrtl(n)+2LL, n);

		map<ll, ll> mp;
		for(ll i = 2LL; i*i <= n; i++){
			if(n%i) continue;
			ll cnt = 0; while(n%i==0) n/=i, cnt++;
			mp[i]=2LL*cnt;
		}
		if(n!=1) mp[n]+=2LL;
		mp[2LL]+=2LL*d, mp[5LL]+=2LL*d;
		ll ans = 1LL;
		for(auto it: mp){
			//cout << it.first << ' ' << it.second << '\n';
			(ans*=(it.second+1LL))%=mod;
		}
		(ans*=2LL)%=mod;
		ans--; if(ans<0) ans+=mod;
		cout << ans << '\n';
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	solve();
	//int t; cin >> t; while(t--) solve();
	return 0;
}

/* Sieve of Eratosthenes Revisited

    Time-Limit: 1 sec Score: 0.00/100

Difficulty :***

    Memory: 256 MB Accepted Submissions: 100

Relevant For:

Description

Find all prime numbers between the range from L to R (endpoints inclusive). Print them in non-decreasing order.

Input Format

The only line of input contains L and R, representing the range.

Output Format

The first line of output contains n - the number of prime numbers in between [L, R].
The second line contains n space-separated integers denoting the prime numbers between [L, R] in non-decreasing order.

Constraints

1 ≤ L ≤ R ≤ 1012
R - L + 1 ≤ 106 
Sample Input 1

1 20

Sample Output 1

8
2 3 5 7 11 13 17 19

Sample Input 2

100000000000 100000000020

Sample Output 2

2
100000000003 100000000019

*/

/*approach and editorial code:
To find all primes in a range, we can use the segmented sieve algorithm, which generates primes up to the square root of the upper limit, and then uses those primes to sieve the range in segments.

The solution approach uses the segmented sieve algorithm to generate primes in the range [L, R]. First, we generate all primes up to √R

using the regular sieve of Eratosthenes. Then, we use these primes to sieve the range [L, R] in segments, marking all composite numbers that are multiples of any prime in the prime list. Finally, we output all the unmarked numbers as prime numbers.

The complete approach begins by generating all primes up to √R
using the sieve of Eratosthenes. We first initialize a boolean vector mark of size lim+1, where lim=√R . We set all elements of mark to false, indicating that all numbers in the range [2, lim] are prime. We then iterate over all numbers from 2 to √R

, marking all multiples of each prime as composite. At the end of this process, all unmarked numbers are primes, and we store them in a vector called primes.

Next, we use the segmented sieve algorithm to sieve the range [L, R]. We initialize another boolean vector isPrime of size R−L+1
, where each element initially corresponds to a number in the range [L, R] and is set to true. For each prime p in the primes vector, we start sieving the range by setting isPrime[j - L] to false for all multiples of p in the range [L, R], starting from the first multiple greater than or equal to p2

, to avoid marking composite numbers that are already marked by smaller primes. Finally, we output all unmarked numbers in the isPrime vector as prime numbers.

The time complexity of the segmented sieve algorithm is O((R−L+1)loglogR)

Note: We used a set to store the primes in the solution code to eliminate duplicates and print primes in non-decreasing order. The time complexity of the set operations is O(log n) per insertion or deletion, where n is the number of elements in the set. Since the maximum size of the set is R−L+1
in our case, the total time complexity of set operations is O((R−L+1)log(R−L+1))

. However, this is a sub-dominant term in the overall time complexity, and we can ignore it.

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<bool> segmentedSieve(long long L, long long R)
{
    // generate all primes up to sqrt(R)
    long long lim = sqrt(R);
    vector<bool> mark(lim + 1, false);
    vector<long long> primes;
    for (long long i = 2; i <= lim; ++i)
    {
        if (!mark[i])
        {
            primes.emplace_back(i);
            for (long long j = i * i; j <= lim; j += i)
                mark[j] = true;
        }
    }

    vector<bool> isPrime(R - L + 1, true);
    for (long long i : primes)
        for (long long j = max(i * i, (L + i - 1) / i * i); j <= R; j += i)
            isPrime[j - L] = false;
    if (L == 1)
        isPrime[0] = false;
    return isPrime;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll L, R;
    cin >> L >> R;
    vector<bool> isPrime = segmentedSieve(L, R);

    set<ll> primes;

    for (int i = 0; i < (int)isPrime.size(); i++)
    {
        if (isPrime[i])
        {
            primes.insert(i + L);
        }
    }

    cout << (int)primes.size() << "\n";
    for (ll u : primes)
    {
        cout << u << " ";
    }
    cout << "\n";
}

*/

//arsh agarwal:
#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll mod = 1000007LL;

void solve(){
	ll l, r; cin>>l>>r;
	vector<bool> prime(r-l+1LL, true);
	for(ll i = 2; i*i <= r; i++){
		ll start = max(2LL*i, ((l+i-1LL)/i)*i);
		//cout << i << '\n';
		for(ll j = start; j <= r; j+=i) prime[j-l]=false;
	}
	vector<ll> ans; for(ll i = 0; i < r-l+1; i++) {
		if(l+i==1) continue;
		if(prime[i]) ans.push_back(l+i);
	}
	cout << ans.size() << '\n'; for(auto it: ans) cout << it << ' '; cout << '\n';
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	solve();
	//int t; cin >> t; while(t--) solve();
	return 0;
}


//karan wadha:
#include<bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b){ return (b ? gcd(b, a % b) : a); }
#define ll long long int
#define ld long double
#define pb push_back
#define endl '\n'
#define f(a,b,c) for(ll i=a;i<b;i+=c)
ll mod=1000000007;
ld PI=acos(-1.0);
ll binary__exp(ll a,ll b,ll p){
    ll ans=1;
   while(b){
      if(b%2==1) ans=(ans*a)%p;
      a=(a*a)%p;
      b/=2;
   }
   return ans;
}

void solve(){
   ll a,b;
   cin>>a>>b;
   ll n=sqrt(b);
   ll m=b-a+1;
   vector<ll> sp(n+1);
   ll sp1[m+1];
   vector<ll> v;
   for(ll i=2;i<=n;i++) sp[i]=1;
      for(ll i=0;i<=m;i++) sp1[i]=1;
      for(ll i=2;i<=n;i++){
         if(sp[i]){
            v.pb(i);
            for(ll j=2*i;j<=n;j+=i) sp[j]=0;
         }
      }

      for(auto i=0;i<v.size();i++){
         ll curr=((a+v[i]-1)/v[i])*v[i];
         while(curr<=b){
            if(curr!=v[i]) sp1[curr-a]=0;
            //else curr+=1;
            curr+=v[i]; 
         }
      }
      ll cnt=0;
      if(a==1) sp1[a-1]=0;
      //if(a<=n) {if(sp[a]) { sp1[]=1;}}
      for(ll i=0;i<m;i++){
         if(sp1[i]) cnt++;
         //cout<<sp1[i]<<" ";
      }

      cout<<cnt<<endl;
      for(ll i=0;i<m;i++){
         if(sp1[i]) cout<<i+a<<" ";
      }
      //for(ll i=0;i<m;i++) cout<<sp1[i]<<" ";*/
      cout<<endl;
   }
signed main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);cout.tie(0);
   #ifndef ONLINE_JUDGE
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
   #endif
  //int t; cin>>t; while(t--)
     solve();
    }
    
    
    /* Hard Floor

    Time-Limit: 3 sec Score: 0.00/100

Difficulty :***

    Memory: 256 MB Accepted Submissions: 100

Relevant For:

Description

Your task is to find the answer to the following sum.

https://lh3.googleusercontent.com/Pg9_ZmO-6k3fD_6Rn2JA5MU8eB4CjF-TwQTPfd2AllMyGWCynn1I-qyqOxvi_CEUtPf8gpBzWrfxAMvpA6_vzuLBRO9gEPUcFzFAgrUIRqbAk2JFsPbqTzwU9TPQHqf1abpAMd2I

Input Format



The only line of input contains two space-separated integers n and m.

Output Format

Print the answer on a new line.

Constraints

1 ≤ n ≤ 1012
1 ≤ m ≤ 109
Sample Input 1

4 2

Sample Output 1

22

Sample Input 2

100000000000 100000000

Sample Output 2

728180943

*/
    
    /*approach and editorial:
    Find the largest x such that ⌊n/i⌋=⌊n/x⌋

The value of ⌊n/i⌋
remains same from i to la where
Value of la=⌊n/⌊n/i⌋⌋

So from i
to la there are (la−i+1) values. All these will have the same fractional value of ⌊ni⌋.
The overall contribution of ⌊ni⌋, will be (la−i+1)×⌊ni⌋.
In the same manner we can find the total summation from i=1 to i=N

The time complexity of the solution is O(√n∗log(mod))

.

The loop in the program iterates over all positive integers i
that divide n, with a step size of la−i+1, where la is the largest integer such that nla=ni. Since there are O(√n) divisors of n, the loop iterates O(√n)

times.

Inside the loop, the program uses binary exponentiation to compute the value of (ni)m
, which takes O(log(m))

time.

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int mod = 1e9 + 7;

inline void add(int &a, int b)
{
    a += b;
    if (a >= mod)
        a -= mod;
}

inline void sub(int &a, int b)
{
    a -= b;
    if (a < 0)
        a += mod;
}

inline int mul(int a, int b)
{
    return (int)((long long)a * b % mod);
}

inline int power(int a, long long b)
{
    int res = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            res = mul(res, a);
        }
        a = mul(a, a);
        b >>= 1;
    }
    return res;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n;
    int m;
    cin >> n >> m;

    int ans = 0;

    for (ll i = 1, la; i <= n; i = la + 1)
    {
        la = n / (n / i);
        // n / x yields the same value for i <= x <= la.
        ll x = n / i;
        x %= mod;
        if (x < 0)
            x += mod;
        int cur = power(x, m);
        int y = 1LL * (la - i + 1) % mod;
        if (y < 0)
            y += mod;
        cur = mul(cur, y);
        add(ans, cur);
    }

    cout << ans << "\n";
}

*/
    #include<bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b){ return (b ? gcd(b, a % b) : a); }
#define ll long long int
#define ld long double
#define pb push_back
#define endl '\n'
#define f(a,b,c) for(ll i=a;i<b;i+=c)
ll mod=1000000007;
ld PI=acos(-1.0);
ll binary__exp(ll a,ll b,ll p){
    ll ans=1;
   while(b){
      if(b%2==1) ans=(ans*a)%p;
      a=(a*a)%p;
      b/=2;
   }
   return ans;
}
void solve(){
  ll n,m;
  cin>>n>>m;
  ll ans=0;
  for(ll i=1,last;i<=n;i=last+1){
   ll p=(n/i);
   last=(n/p);
   ans=(ans%mod+(binary__exp((n/i)%mod,m,mod)*((last-i+1)%mod))%mod);

  }
  cout<<ans%mod<<endl;
 }
signed main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);cout.tie(0);
   #ifndef ONLINE_JUDGE
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
   #endif
   
  //int t; cin>>t; while(t--)
     solve();
    }
    
    
    /* Multiply All GCDs

    Time-Limit: 2 sec Score: 0.00/100

Difficulty :

    Memory: 256 MB Accepted Submissions: 100

Relevant For:

Description

You are given N integers (not necessarily distinct) => A1, A2, A3, ..., AN. There are 2N possible subsets (including the empty subset). 
The GCD of a subset is defined as the greatest common divisor of all the integers in that subset. 
You need to find the product of the GCDs of all the 2N possible subsets you can construct from A. Since the answer can be large, you need to output the answer modulo 1000000007. Do you think you can solve this question?

Note: The greatest common divisor of an empty subset is 1.

Input Format

The first line of input consists of a single integer T denoting the number of test cases. The description of T test cases follow. 
The first line of each test case consists of a single integer N. The second line of each test case consists of N space-separated integers A1, A2, ..., AN.

Output Format

For each test case, output a single integer on a separate line denoting the answer for that test case. Note that you need to output all the values modulo 1000000007 (109 + 7).

Constraints

1 ≤ T ≤ 30
1 ≤ N ≤ 105
1 ≤ Ai ≤ 105
Sample Input 1

3
1
1
2
1 2
3
1 2 2

Sample Output 1

1
2
8

Note

For the first test case, N = 1, and A = [1]. There are 2 possible subsets => {}, {1} and both have a gcd of 1. Hence, the answer is 1 * 1 = 1.

For the second test case, N = 2, and A = [1, 2]. There are 4 possible subsets => {}, {1}, {2}, {1, 2}, having a gcd of 1, 1, 2 and 1 respectively. Hence, the answer is 1 * 1 * 2 * 1 = 2.

For the third test case, N = 3, and A = [1, 2, 2]. There are 8 possible subsets => {}, {1}, {2}, {2}, {1, 2}, {2, 2}, {1, 2}, {1, 2, 2}, having a gcd of 1, 1, 2, 2, 1, 2, 1, 1. Hence, the answer is 1 * 1 * 2 * 2 * 1 * 2 * 1 * 1 = 8.

*/
    #include <bits/stdc++.h>
#include <chrono>
#include <iomanip>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
#define print(v) for (auto i : v)  cerr << i << " "; cerr << endl
const int mod = 1e9 + 7;
using namespace std;
using namespace chrono;

int binpow(int a, int b, int modd) {
    int ans = 1;
    while (b) {
        if (b & 1) {
            ans = (ans % modd * a % modd) % modd;
        }
        a = (a % modd * a % modd) % modd;
        b >>= 1;
    }
    return ans;
}

int N = 100010;

void solution() {
    int F[N], S[N], freq[N];
    memset(F, 0, sizeof(F));
    memset(S, 0, sizeof(S));
    memset(freq, 0, sizeof(freq));

    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        freq[x]++;
    }
    for (int i = 1; i < N; i++) {
        for (int j = i; j < N; j += i) {
            F[i] += freq[j];
        }
    }
    for (int i = N - 1; i >= 1; i--) {
        S[i] = binpow(2, F[i], mod - 1) - 1;
        if (S[i] < 0) S[i] += mod - 1;
        // check from next element that is multiple of this number
        for (int j = i + i; j < N; j += i) {
            S[i] = (S[i] - S[j] + (mod - 1)) % (mod - 1);
        }
    }
    int ans = 1;
    for (int i = 1; i < N; i++) {
        if (S[i] >= 0 && S[i] < mod - 1) {
            ans = (ans * binpow(i, S[i], mod)) % mod;
        }
    }
    if (ans >= 0 && ans < mod) {
        cout << ans << endl;
    }
}

signed main() {
    fast;
    auto start = high_resolution_clock::now();

    int t = 1;
    cin >> t;
    while (t--) {
        solution();
    }

    auto end = high_resolution_clock::now();
    duration<double> duration = end - start;
    cerr << fixed << setprecision(6);
    cerr << "Execution time: " << duration.count() * 1e3 << " ms" << endl;
    return 0;
}
    
    /*editorial:
    No Hints are available. See Complete Approach section for detailed editorial.

No Hints are available. See Complete Approach section for detailed editorial.

Given an array A consisting of N integers where, each value Ai ≤ 105. For each number i where i ∈ (1, 105), calculate the number of non-empty subsets with gcd = i modulo 109 + 7. 

Lets create an array S[ ] where Si will contain the number of non-empty subsets with gcd = i and an array F[ ] where Fi will contain the number of elements among given N elements that are multiple of i.

It is given that each value in the array A i.e Ai ≤ 105. Therefore, we can simply precompute the divisors for a given i where i ∈ [1, 105] and use it to fill array F.
Fx stores the count of numbers which are multiple of x. Therefore, choosing any non-empty subset of these numbers will produce gcd of any of these kinds x, 2x, 3x … and so on ( multiples of x ) and if we know how many subsets are there which produces gcd = 2x, 3x, 4*x … and so on in advance, we can evaluate the number of subsets with gcd = x easily.

At this point, we know for each value x ∈ [1, 105], the number of subsets with gcd = x in Sx and our original problem asked for the following expression.

Note that if a given x can’t be gcd of any subset, then S_x = 0 and therefore it is correct to write above expression.

We cannot compute this expression easily as value of Sx can be very large. So, we will be using Fermat Little Theorem here. Fermat’s Little theorem states that a{p-1} = 1 mod p. Where p is prime. This is valid for all integers a. So if we want to calculate ab mod ( p ) and b = k * (p-1) + m. Then we know ab = (a{p-1})k * am = 1k * am = am and therefore, we will be maintaining array S[ ] modulo (109 + 6) instead.

Please have a look at editorialist’s solution for implementation details.


#include<bits/stdc++.h>
using namespace std;

#define ll long long int

const int N = 100010;

int mod = 1e9 + 7;

int power(int a, int b, int M) {
    if(!b) return 1;
    int temp = power(a, b / 2, M);
    temp = 1LL * temp * temp % M;
    if(b % 2) temp = 1LL * temp * a % M;
    return temp;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while(t--) {
        int n; cin >> n;

        int F[N], S[N], cnt[N];
        memset(F, 0, sizeof(F));
        memset(S, 0, sizeof(S));
        memset(cnt, 0, sizeof(cnt));

        for(int i = 0; i < n; i++) {
            int x; cin >> x;
            cnt[x]++;
        }

        for(int i = 1; i < N; i++) {
            for(int j = i; j < N; j += i) {
                F[i] += cnt[j];
            }
        }

        for(int i = N - 1; i >= 1; i--) {
            S[i] = power(2, F[i], mod - 1) - 1;
            if(S[i] < 0) S[i] += mod - 1;
            for(int j = i + i; j < N; j += i) {
                S[i] = (S[i] - S[j] + (mod - 1)) % (mod - 1);
            }
        }

        int ans = 1;
        for(int i = 1; i < N; i++) {
            assert(S[i] >= 0 && S[i] < mod - 1);
            ans = 1LL * ans * power(i, S[i], mod) % mod;
        }

        assert(ans >= 0 && ans < mod);
        cout << ans << "\n";
    }
    return 0;
}

*/
    
    /* GCD of Products

    Time-Limit: 4 sec Score: 0/100

Difficulty :

    Memory: 256 MB Accepted Submissions: 100

Relevant For:

Description

You have to calculate the GCD of N numbers. Since the numbers are too large to be written as numbers, they are written as products of smaller numbers. Find their GCD.

Input Format

The first line of the input contains one integer N - the number of numbers.
Each of the next N lines contains an integer M followed by M space-separated integers, A1, A2,..., AM -  the numbers whose product is the i-th number.
It is guaranteed that the sum of M over all N numbers doesn't exceed 106.

Output Format

Print the GCD on a single line. Since this number might be pretty big, output it modulo 109+7.

Constraints

2≤ N ≤ 106
1≤ M ≤ 106
1≤ Ai ≤ 107
Sample Input 1

3

4 2 3 1 2

3 3 6 2

3 2 4 7

Sample Output 1

4

Note

The first number will be A1 = 2*3*1*2 = 12
The second number will be A2 = 3*6*2 = 36
The third number will be A3 = 2*4*7 = 56

The GCD of these three numbers will be GCD(12, 36, 56) = 4

*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

const int N = 1e7+1;
vector<int> sp;

map<int, int> getpf(vector<int>& a){
    map<int,int> mp;
    for(auto it: a){
        while(it!=1) mp[sp[it]]++, it/=sp[it];
    }
    return mp;
}

ll power(ll a, ll p,ll mod){
    ll ans = 1LL;
    while(p){
        if(p%2LL) (ans*=a)%=mod; (a*=a)%=mod; p/=2LL;
    }
    return ans;
}

void solve(){
    sp.resize(N);
    for(int i = 2; i < N; i++) sp[i]=i;
    for(ll i = 2; i < N; i++){
        if(sp[i]!=i) continue;
        for(ll j = i*i; j < N; j+=i) sp[j]=i;
    }
    int n; cin >> n;
    map<int,int> ans;
    for(int i = 0; i < n; i++){
        int m; cin >> m; vector<int> a(m); for(int j = 0; j < m; j++) cin >> a[j];
        map<int,int> mp = getpf(a);
        if(i==0) ans=mp;
        else{
            for(auto it: ans){
                ans[it.first]=min(mp[it.first], it.second);
            }
        }
    }

    ll mod = 1e9+7;
    ll val = 1LL;
    for(auto it: ans){
        (val*=power(it.first, it.second, mod))%=mod;
    }
    cout << val << '\n' ;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    solve();
    //int t; cin >> t; while(t--) solve();
    return 0;
}

/* editorial:
You can factorise A1, A2, …, AM for each number and then calculate GCD.

You can use Sieve of Eratosthenes to find the lowest prime factor of every number and using that lowest prime number you can find all the factors in a much-optimized way.

#include <bits/stdc++.h>
using namespace std;

#define int long long

const int mod=1e9+7;

int prime[10000001];
void sieve() {
    for(int i = 1; i < 10000001; ++i) {
        prime[i] = i;
    }
    for(int i = 2; i < 10000001; ++i) {
        if(prime[i] == i) {
            for(int j = i; j < 10000001; j += i) {
                prime[j] = i;
            }
        }
    }
}

int pw (int a, int b, int p) {
    if(b == 0) return 1;
    int t = pw(a, b/2, p);
    t = (t * t) % p;
    if(b % 2) return (a * t) % p;
    return t;
}

signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    sieve();
    int n;
    cin >> n;
    map<int, int> m1;
    for (int i = 0; i < n; ++i) {
        int m;
        cin >> m;
        map<int, int> m2;
        for (int j = 0; j < m; ++j) {
            int x;
            cin >> x;
            while (x > 1) {
                m2[prime[x]]++;
                x /= prime[x];
            }
        }
        if(i == 0) {
            m1 = m2;
        }
        else {
            for(auto it:m1) {
                m1[it.first] = min(m1[it.first], m2[it.first]);
            }
        }
    }
    int ans = 1;
    for(auto it : m1) {
        ans = (ans * pw(it.first, it.second,mod)) % mod;
    }
    cout << ans;
    return 0;
}

*/


/* Coloured Marbles

    Time-Limit: 2 sec Score: 0.00/100

Difficulty :*

    Memory: 256 MB Accepted Submissions: 100

Relevant For:

Description

You have N marbles, out of which C1 are red, C2 are blue and C3 are green. (C1+C2+C3 = N) You have to tell the number of different arrangements possible. Since the answer can be quite large, print it modulo 109+7.

Assume that marbles of the same colour are indistinguishable.

Input Format

The first line of the input contains one integer T - the number of test cases. Then T test cases follow.
The first line of each test case contains four integers N, C1, C2, C3 - the number of marbles, the numbers of red coloured marbles, the number of blue coloured marbles and the number of green coloured marbles respectively.

Constraints

1 ≤ T ≤ 105
0 ≤ C1, C2, C3 ≤ N ≤ 105 
It is guaranteed that C1 + C2 + C3 = N.
Sample Input 1

3
3 1 1 1
2 0 2 0
5 4 0 1

Sample Output 1

6
1
5

Note

In the first test case of the example, the following are the 6 different arrangements possible:
In the second test case of the example, only one different arrangement is possible:

*/

/*Try using combinatorics to calculate the answer.

Use the formula for arrangements of N objects of which there might be groups of indistinguishable objects.

The following formula can be used for calculating the answer: 

NCC1 * (N-C1)CC2 * (N-C1-C2)CC3  = N! / (C1! * C2! * C3!)

The factorials should be pre-calculated and Modular Multiplicative Inverse should be used to calculate the denominator efficiently.

Time Complexity: O(N + T*log(N))

#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long

const int mod = 1e9+7;
int fact[100001];

int pw(int a, int b, int p) {
    if(b == 0) return 1;
    int t = pw(a, b/2, p);
    t = (t * t)%p;
    if(b % 2) return (a * t)%p;
    return t;
}

signed main() {
    IOS
    fact[0] = 1;
    for (int i = 1; i <= 100000; ++i) {
        fact[i] = (fact[i-1] * i)%mod;
    }
    int t;
    cin >> t;
    while (t--) {
        int n, c1, c2, c3;
        cin >> n >> c1 >> c2 >> c3;
        int ans = fact[n];
        ans = (ans * pw(fact[c1], mod-2, mod))%mod;
        ans = (ans * pw(fact[c2], mod-2, mod))%mod;
        ans = (ans * pw(fact[c3], mod-2, mod))%mod;
        cout << ans <<"\n";
    }
    return 0;
}
*/

#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;
const int MAX_N = 100005; // Maximum value of N according to constraints

vector<int> factorial(MAX_N, 1); // Pre-calculate factorials

// Function to pre-calculate factorials up to MAX_N
void precalculateFactorials() {
    for (int i = 1; i < MAX_N; ++i) {
        factorial[i] = (1LL * factorial[i - 1] * i) % MOD;
    }
}

// Function to calculate modular multiplicative inverse
int modInverse(int a, int m) {
    int m0 = m;
    int y = 0, x = 1;

    if (m == 1) return 0;

    while (a > 1) {
        int q = a / m;
        int t = m;
        m = a % m, a = t;
        t = y;
        y = x - q * y;
        x = t;
    }

    if (x < 0) x += m0;
    return x;
}

// Function to calculate the number of arrangements for a test case
int countArrangements(int N, int C1, int C2, int C3) {
    // Calculate the multinomial coefficient
    int denominator = (1LL * factorial[C1] * factorial[C2]) % MOD;
    denominator = (1LL * denominator * factorial[C3]) % MOD;
    int inverse_denominator = modInverse(denominator, MOD);

    // Calculate the numerator (N!)
    int numerator = factorial[N];

    // Calculate the modular multiplicative inverse of the denominator
    int arrangements = (1LL * numerator * inverse_denominator) % MOD;

    return arrangements;
}

int main() {
    int T;
    cin >> T;

    precalculateFactorials(); // Pre-calculate factorials

    while (T--) {
        int N, C1, C2, C3;
        cin >> N >> C1 >> C2 >> C3;

        int arrangements = countArrangements(N, C1, C2, C3);
        cout << arrangements << endl;
    }

    return 0;
}


/* Character Encoding

    Time-Limit: 2 sec Score: 0.00/100

Difficulty :****

    Memory: 256 MB Accepted Submissions: 100

Relevant For:

Description

Find the number of solutions of following equation.

x1 + x2 + x3 + … + xn = k, satisfying that 0 ≤ xi < m, modulo 1000000007.

Input Format

The only line of input contains three space-separated integers n, m, k.

Output Format

Print the number of solutions.

Constraints

1 ≤ n, m, k ≤ 105
Sample Input 1

2 4 5

Sample Output 1

2

Sample Input 2

20 10 50

Sample Output 2

366736536

Note

For the first test cases, only two solutions exist (2, 3) and (3, 2).

*/

/*The number of non-negative integer solutions to x1 + x2 + …+ xn = k is given by (n + k - 1) C (k).

Try to think of how to remove the constraint on xis, by doing inclusion-exclusion.

The only thing we need to handle is to get rid of that annoying constraint xi < m. To do that, we apply the inclusion-exclusion principle. Let ei = xi ≥ m, then No is our desired answer. Clearly, this set of properties is homogeneous. Take T = {1, 2, …, j} (j ≤ n), then NT is the number of solutions with x1 ≥ m, x2 ≥ m, …, xj ≥ m. Setting yi = xi - m(i ≤ j), yi = xi(i > j), and it's the same as the number of solutions of the system

y1 + y2 + … + yn = k - jm,

thus the answer is therefore

No = Summation over j = [0, n] (-1)j * nCj * (n + k - jm - 1) C (n - 1)

Time complexity: O(n) with some preprocessing.

#include<bits/stdc++.h>
using namespace std;

#define ll long long int

const int N = 500010;

int mod = 1e9 + 7;

int power(int a, int b, int M) {
    if(!b) return 1;
    int temp = power(a, b / 2, M);
    temp = 1LL * temp * temp % M;
    if(b % 2) temp = 1LL * temp * a % M;
    return temp;
}

int fact[N];

void pre() {
    fact[0] = 1;
    for(int i = 1; i < N; i++) {
        fact[i] = 1LL * fact[i - 1] * i % mod;
    }
}

int ncr(int n, int r) {
    if(n < r) return 0;
    assert(n >= 0 && n < N && r >= 0 && r < N);
    int ans = fact[n];
    ans = 1LL * ans * power(fact[n - r], mod - 2, mod) % mod;
    ans = 1LL * ans * power(fact[r], mod - 2, mod) % mod;
    if(ans < 0) ans += mod;
    assert(ans >= 0 && ans < mod);
    return ans;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    pre();
    int n, m, k;
    cin >> n >> m >> k;

    int ans = 0;

    for(int i = 0; i <= n; i++) {
        int temp = ncr(n, i);
        if(n + k - i * m - 1 < n - 1) break;
        temp = 1LL * temp * ncr(n + k - i * m - 1, n - 1) % mod;
        if(temp < 0) temp += mod;
        if(i % 2) ans = (ans - temp + mod) % mod;
        else ans = (ans + temp) % mod;
    }

    assert(ans >= 0 && ans < mod);

    cout << ans << "\n";

    return 0;
}

*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define nl "\n";
#define mod 1000000007
#define inf 1e18

int n, m, k;
ll fact[200010];

ll binpow(ll a, ll b, ll m)
{
    a %= m;
    ll res = 1LL;
    while (b)
    {
        if (b & 1)
        {
            res = (res % m * a % m) % m;
        }
        a = (a % m * a % m)% m;
        b >>= 1;
    }
    return res;
}

void getFact()
{
    fact[0] = 1;
    for (ll i = 1; i < 200010; i++)
    {
        fact[i] = (i % mod * fact[i - 1] % mod) % mod;
    }
}

ll getInverse(ll a)
{
    return binpow(a,mod-2,mod); 
}

ll nCr(ll n, ll r)
{
    if(n<0 || r<0 || r>n) return 0; 
    return (((fact[n]*getInverse(fact[r]))%mod)*getInverse(fact[n-r])%mod)%mod; 
}

void solve()
{
    cin >> n >> m >> k;
    ll ans = 0;
    for (ll i = 0; i <= n; i++)
    {
       ll tmp = (nCr(n,i)%mod*nCr(n+k-i*m-1LL,n-1LL)%mod)%mod;
       if(i%2) ans-= tmp; 
       else
       ans+=tmp; 
       ans%=mod; 
       if(ans<0) ans+=mod;  
    }
    cout << ans << '\n';
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
    // cin >> t;
    getFact();
    while (t--)
        solve();
    return 0;
}

/*
2
366736536
*/

/* Count Good Subsequences

    Time-Limit: 4 sec Score: 0.00/100

Difficulty :****

    Memory: 256 MB Accepted Submissions: 100

Relevant For:

Description

You are given a sequence A1, A2, …, AN. Let's call a subsequence Ai1, Ai2, …, Aik (for any k > 0, 1 ≤ i1 < i2 < … < ik ≤ N) good if the median of this subsequence is an element of this subsequence. 
Find the number of good subsequences. Since this number may be large, compute it modulo 1000000007 (109+7).

Note:

    The median of a set of data is the middlemost number in the set. The median is also the number that is halfway into the set. To find the median, the data should first be arranged in order from least to greatest.
    For odd length sequence, the median is the middle element in the sorted sequence. While for even length sequence, it is the average of the middle two elements.

Input Format

The first line of input contains T - the number of test cases.
The first line of each test case contains a number N - the size of the array.
The second line of each test case contains N space-separated integers A1, A2, ..., AN. 

Output Format

For each test case, print the number of good subsequences on a new line.

Constraints

1 ≤ T ≤ 30
1 ≤ N ≤ 1000
1 ≤ Ai ≤ 2N
Sample Input 1

1
3
2 3 2

Sample Output 1

5

Note

The good subsequences are [2], [3], [2], [2,2], [2,3,2].

*/

/*approach:
    Every subset of odd size has its median present in the subset, so, we can directly add 2N − 1 to answer.
    For even size subset, The subset is good, if and only if the middle two elements are equal.

We can fix the left middle element, and for every possible even size of the subset, say 2X, try to find count.

First of all, let us formulate the definition of median. If the size of the selected subset is odd, the median is just the middle element of subset after sorting. Since the middle element is present in the subset, all subsets of odd size are valid. It can be easily proven that there are 2N−1 such subsets. So, we can directly count these and move toward even size subsets.
If the size of the selected subset is even, the median is defined as the average of two middlemost elements after sorting. Now, say we have two middle elements x and y, with condition x ≤ y. Let z = (x + y) / 2 be the median of sequence. If we write y = x + d, d ≥ 0, we can see, z = x + d / 2 and also, z = y − d / 2. This way, we can see, that the median of a sequence can never be smaller than x and greater than y. So, For z to be present in subset, we need either z = x or z = y. But, this would imply d = 0, Hence leading to the conclusion that for an even size subset to be valid, the two middlemost elements should be equal. This forms the crux of our solution, and now, we need to count the number of even sized subsets with equal middle elements.
After all this, there are a number of approaches to solving this problem, all of which required us to sort the array AA first.

Let us consider a O(N3) solution first. Iterate over every pair of equal elements (i, j) such that Ai ​= Aj​ and iterate over the size 2X of subset from X = 1 to N. The number of ways to make the subset of size X with two fixed middle elements is just the product of the number of ways we can select X − 1 elements from [1, i − 1] and X − 1 elements from [j + 1, N].

This solution requires to iterate over every pair (i, j) which takes O(N2) time and O(N) time per pair, leading to Overall time complexity O(N3).

We were fixing two equal elements and tried to count the number of ways we can make subsets of all sizes. Now, We shall fix only the Left Middle Element (Or Right one, whichever implementation you prefer).

Suppose we fixed the ith element as the left middle element. Now, We will iterate over all sizes 2X and try to include X − 1 elements from [1, i − 1] and X elements from [i + 1, N]. We need the right middle element to be same as the left middle element. So, When choosing X elements from [i+1,N], we need at least one occurrence of A[i]. This is same as subtracting all the ways to select X elements in the range [i + 1, N] which do not have A[i] at all. Suppose Number of occurrence of A[i] in range [i + 1, N] is f, then we can count the number of ways to select X elements from range [i + 1, N] such that it contains at least one occurrence of A[i] as T = Number of ways to select X elements out of N−i elements less Number of ways to select X elements out of N−i−f elements.

We can select X−1 elements from [1, i − 1] in suppose U ways. Then, Number of ways we can have good subsets with A[i] as the left middle element is UT. Summation of this product for all sizes for all elements gives us the number of good subsets of even size. We can add to it, the number of good odd sized subsets and print the answer.

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
vector<ll> fact;
vector<ll> factInv;
int mod = 1e9 + 7;

ll binpow(ll a, ll b) {
  ll ans = 1;
  while (b) {
    if (b % 2) ans = (ans * a) % mod;
    a = (a * a) % mod;
    b /= 2;
  }
  return ans;
}

ll ncr(ll n, ll r) {
  return (((fact[n] * factInv[n - r]) % mod) * factInv[r]) % mod;
}

void solve() {
  int n;
  cin >> n;
  vector<int> v(n);
  vector<int> pos(n, 1);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  sort(v.begin(), v.end());

  for (int i = n - 2; i >= 0; i--) {
    if (v[i] == v[i + 1]) {
      pos[i] += pos[i + 1];
    }
  }

  ll ans = binpow(2, n - 1);

  for (int i = 0; i < n; i++) {
    if (pos[i] == 1) continue;
    int temp = min(i, n - i - 1 - 1);
    for (int j = 0; j <= temp; j++) {
      if (j == 0) {
        ans = (ans + ncr(pos[i + 1], j + 1)) % mod;
        continue;
      }
      ans += (ncr(i, j) * ncr(n - 1 - i, j + 1)) % mod;
      ans %= mod;
      if (n - 1 - i - pos[i + 1] >= (j + 1)) {
        ans -= (ncr(i, j) * ncr(n - 1 - i - pos[i + 1], j + 1)) % mod;
        ans = (ans + mod) % mod;
      }
    }
  }
  cout << ans << "\n";
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  fact = vector<ll>(2001);
  factInv = vector<ll>(2001);
  fact[0] = 1;
  for (int i = 1; i <= 2000; i++) {
    fact[i] = (i * fact[i - 1]) % mod;
  }
  factInv[2000] = binpow(fact[2000], mod - 2);
  for (int i = 2000; i > 0; i--) {
    factInv[i - 1] = (i * factInv[i]) % mod;
  }

  int _t;
  cin >> _t;
  while (_t--) solve();
}

*/


#include<bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define mod 1000000007
ll fact[100010],invfact[100010];

ll power(ll x,ll y)//binary exponentiation
{
    ll res=1,z=x;
    while(y>0)
    {
        while(y%2==0)
        {
            y/=2;
            z=(z*z)%mod;
        }
        y--;
        res=(res*z)%mod;
    }
    return res%mod;
}
ll ncr(ll n,ll r)
{
    if(r==0)
    return 1;
    if(n<r)
    return 0;
    ll ans=fact[n]%mod;
    ans=(ans*invfact[r])%mod;
    ans=(ans*invfact[n-r])%mod;
    return ans;
}
void factorial()
{
    fact[0]=1;
    for(ll i=1;i<100010;i++)
    fact[i]=(fact[i-1]*i)%mod;
}
void invfactorial()
{
    invfact[0]=1;
    invfact[1]=1;
    for(ll i=2;i<100010;i++)
    invfact[i]=power(fact[i],mod-2)%mod;

}

void solve()
{
    ll n;
    cin>>n;
    vector<ll> arr(n);
    for(ll i=0;i<n;i++)
    cin>>arr[i];
    ll ans=power(2,n-1);
    sort(arr.begin(),arr.end());
    ll l,r,k;
    for(ll i=0;i<n;i++){
        l=i;
        r=n-i-1;
        auto it=upper_bound(arr.begin(),arr.end(),arr[i]);
        k=it-arr.begin()-1-i;
        if(k>0){
            for(ll j=0;j<=min(l,r-1);j++){
                ans=(ans+(ncr(l,j)*(ncr(r,j+1)-ncr(r-k,j+1)))%mod)%mod;
            }
        }
    }
    ans=(ans+mod)%mod;
    cout<<ans<<"\n";

}
signed main()
{
    IOS
    factorial();
    invfactorial();
    ll T;
    cin>>T;
    while(T--)
    solve();
}


/* Learn This Thing

    Time-Limit: 2 sec Score: 0.00/100

Difficulty :

    Memory: 256 MB Accepted Submissions: 100

Relevant For:

Description

For a given n, find the number of even and odd numbers among the set, { nC0, nC1,... nCn }.

Input Format

First-line contains T (1 ≤ T ≤ 105), the number of test cases. Next T lines contain one integer per line, denoting n (0 ≤ n ≤ 1012). 

Output Format

For each test case, output two space-separated integers specifying the number of even numbers and odd numbers respectively.
Sample Input 1

2
3
4

Sample Output 1

0 4
3 2

Note

For 3, values are: 1 3 3 1. All are odd. Hence 0 4.
For 4, values are: 1 4 6 4 1. Hence 3 2.

*/

/*approach :
Have you heard of Lucas Theorem (https://en.wikipedia.org/wiki/Lucas%27s_theorem)?

Can you find the generalize results for p = 2 in Lucas Theorem?

Using Lucas Theorem (https://en.wikipedia.org/wiki/Lucas%27s_theorem) we can find that iff x & y = y, then xCy will be odd. Otherwise even. That's it! Find the number of integers in the submask in n.
See the solution code for more implementation.

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int T; cin >> T;
    while(T--) {
        ll n; cin >> n;
        ll ans = 1;
        for(ll i = 0; i < 64; i++) {
            if((n >> i) & 1) {
                ans *= 2;
            }
        }
        cout << n + 1 - ans << " " << ans << "\n";
    }
}

*/

//arsh agarwal:
#include<bits/stdc++.h>
using namespace std;
#define ll long long int

void solve(){
    ll n; cin >> n;
    ll cnt = __builtin_popcountll(n);
    ll odd = (1LL<<cnt);
    cout << n+1LL-odd << ' ' << odd << '\n';
}
 
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //solve();
    int t; cin >> t; while(t--) solve();
    return 0;
}

/* Tough Mex

    Time-Limit: 3 sec Score: 0.00/100

Difficulty :****

    Memory: 256 MB Accepted Submissions: 100

Relevant For:

Description

For a (possibly empty) sequence of positive integers S, mex is defined as f(S) as the smallest positive integer that does not appear in S. For example, f([]) = 1, f([3,4,3,5]) = 1, f([2,5,1,1,2,3]) = 4.

You have given a sequence of N integers A1, A2, …, AN. Your task is to find the sum of f(S) over all 2N possible subsequences S of this sequence.

Since the resulting sum can be very big, compute it modulo 998244353.

Input Format

The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains a single integer N.
The second line contains N space-separated integers A1, A2, …, AN.

Output Format

For each test case, print a single line containing one integer ― the sum of f(S) over all subsequences modulo 998244353.

Constraints

1 ≤ T ≤ 10
1 ≤ N ≤ 105
1 ≤ Ai ≤ 109 for each valid i
Sample Input 1

2
2
1 1
3
1 2 1

Sample Output 1

7
17

Note

Example case 1: The values for all possible subsequences are f([]) = 1, f([1]) = 2, f([1]) = 2, f([1,1]) = 2.

Example case 2: The values for all possible subsequences are f([]) = 1, f([1]) = 2, f([2]) = 1, f([1]) = 2, f([1,2]) = 3, f([2,1]) = 3, f([1,1]) = 2, f([1,2,1]) = 3.

*/
/*approach and editorial:
The mex of a subsequence of length N cannot exceed N. So we can replace all elements greater than N with N.

Fixing the value of mex, let’s try to count the number of subsequences with specific mex.

The mex of a subsequence of length N cannot exceed N. So we can replace all elements greater than N with N.
Fixing the value of mex, let’s try to count the number of subsequences with specific mex.
For a given mex, we need each positive value smaller than mex to be present at least once, value mex shouldn’t be present, and values greater than mex do not affect us.
If fx​ denote the frequency of value x, the number of non-empty subsets of these fx​ elements is 2fx​−1. We need to select one of the subsets for each x less than current mex, giving us (2f1 - 1) * (2f2 - 1)  …. * (2f(x-1) - 1).
To consider elements greater than mex, we can take any subset of those. If there are y elements greater than mex, it contributes 2y subsets for each choice of subsets of smaller values.

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 200010;
const int MOD = 998244353;

int t, n; 
ll two[N], a[N], freq[N], sf[N];

int main() {
  two[0] = 1;
  for (int i = 1; i < N; ++i) two[i] = 2 * two[i - 1] % MOD;
  cin >> t;
  while (t--) {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
      scanf("%lld", a + i);
      ++freq[min(a[i], n + 1LL)];
    }
    sf[n + 69] = 0;
    for (int i = n + 68; i; --i) sf[i] = sf[i + 1] + freq[i];
    ll ans = 0, pf = 1;
    for (ll i = 1; i <= n + 1; ++i) {
      ans = (ans + i * (pf * two[sf[i + 1]] % MOD)) % MOD;
      pf = pf * (two[freq[i]] - 1) % MOD;
    }
    ans += MOD, ans %= MOD;
    printf("%lld\n", ans);
    for (int i = 0; i <= n + 69; ++i) freq[i] = 0;
  }
  return 0;
}

*/

//arsh agarwal :
#include <bits/stdc++.h>
using namespace std;
#define int long long

int mod = 998244353;
int p2[100100];
void pre(){
    p2[0] = 1; for(int i = 1; i < 100100; i++) p2[i] = p2[i-1]*2%mod;
}
int power(int a, int p){int ans = 1; while(p){if(p&1) (ans*=a)%=mod; (a*=a)%=mod; p/=2;} return ans;}
int inv(int a){return power(a, mod-2);}

void solve(){
    int n; cin>>n; map<int,int> mp; 
    for(int i = 0; i < n; i++){int temp; cin>>temp; mp[temp]++;}
    int left = 1, right = p2[n];
    int ans = 0;
    for(int i = 1; i <= n+1; i++){
        (right *= inv(p2[mp[i]]))%=mod;
        (ans += i*left%mod*right%mod)%=mod;
        (left *= (p2[mp[i]]-1))%=mod;
    }
    if(ans<0) ans += mod;
    cout << ans << '\n';
} 
 
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    pre();
    int t; cin >> t; while(t--) 
    solve();
    return 0;
}

/* Fraction Rank (dAY 6 standered)

    Time-Limit: 1 sec Score: 0.00/100

Difficulty :

    Memory: 256 MB Accepted Submissions: 100

Relevant For:

Description

Let us consider a set of fractions x / y, such that 0 ≤ x / y ≤ 1, y ≤ n and gcd (x, y) = 1.

For example, say n = 5. Then we have the following set in increasing order : 0/1, 1/5, 1/4, 1/3, 2/5, 1/2, 3/5, 2/3, 3/4, 4/5, 1/1

You are given n, a and b. The task is to find the rank of a / b in a set of fractions as stated above which is in increasing order.

Note: Fractions should be finite.

Input Format

The first line of contains a number T (1 ≤ T ≤ 20) - the number of testcases. Then T lines follow.
In each of T lines you are given n, a, b (1 ≤ n ≤ 100000, a ≤ b ≤ n) such that gcd(a, b) = 1.

Output Format

Print T lines. The ith line contains the rank of a fraction a / b for a given n, a and b in the (i + 1)th line of input.
Sample Input 1

5
5 3 4
8 5 7
123 23 32
500 99 123
1000 501 611

Sample Output 1

9
17
3332
61269
249428

Note

Explanation 1:
For n = 5, we have the following set in increasing order: 0/1, 1/5, 1/4, 1/3, 2/5, 1/2, 3/5, 2/3, 3/4, 4/5, 1/1
So the rank of 3 / 4 is 9.

1

​*/

/*approach :
One way to approach this problem is to count the number of fractions which are less than or equal to the given fraction ab
in the given set. Once we know the count of such fractions, we can easily find the rank of ab

in the set by adding 1 to this count.

To count the number of fractions less than or equal to ab

, we can make use of the following observation:

For any given denominator y
, the fractions xy which satisfy the condition gcd(x,y)=1 and 0≤xy≤1 form a Farey sequence of order y, denoted as Fy. The set of all fractions satisfying the given conditions can be obtained by taking the union of all Farey sequences of order y, where 1≤y≤n

.

Now, we can count the number of fractions less than or equal to ab
in each Farey sequence of order y, and add them up to get the total count of fractions less than or equal to ab in the given set. To count the number of fractions less than or equal to ab in a Farey sequence of order y

, we can make use of the following property:

If ab
is a fraction in a Farey sequence of order y, then the fractions 2a2b, 3a3b, ..., (y−1)a(y−1)b

are not in the sequence.

Using this property, we can count the number of fractions less than or equal to ab
in a Farey sequence of order y, by first calculating the number of fractions xy in the sequence for each y≤n

, and then subtracting the number of fractions which are not in the sequence using the property mentioned above.

The above approach can be implemented using a simple algorithm as follows:

Initialize ans=0
and an array arr of size n+1 to store the count of fractions xy less than or equal to ab

for each denominator y.

For each denominator y ≤ n, calculate the number of fractions xy
less than or equal to ab, by setting arr[y]=⌊(ay)/b⌋, where ⌊.⌋ denotes the floor function. This is because the fraction xy is less than or equal to ab

if and only if x ≤ ⌊(ay)/b⌋.

For each denominator y≤n

, subtract the count of fractions which are not in the Farey sequence of order y, by iterating over all multiples of y less than or equal to n, and subtracting arr[i] for each such i.

Add up the counts of fractions less than or equal to ab
for each denominatory≤n to get the total count, and add 1 to get the rank of ab

in the given set.

The time complexity of the above algorithm is O(nlogn)
, since we need to iterate over all denominators y≤n, and for each denominator y, we need to subtract the counts of non-Farey fractions, which takes O(logy)

time using the above property.

Thus, the above algorithm efficiently solves the given problem.

#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define LD long double

const int N = 100010;

int inf = 1e9;
int mod = 1e9 + 7;

ll get_fractions_less_than_eq(ll n, ll a, ll b){
    ll ans = 0,arr[n + 1];

    for(ll i = 1; i <= n; i++)
        arr[i] = (a * i) / b;

    for(ll i = 1; i <= n; i++){
        for(ll j = i * 2; j <= n;j += i)
            arr[j] -= arr[i];
        ans += arr[i];
    }
    return ans;
}

signed main()
{
    //freopen("IN", "r", stdin);
    //freopen("OUT", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int T; cin >> T;
    while(T--) {
        int n, a, b;
        cin >> n >> a >> b;
        cout << get_fractions_less_than_eq(n, a, b) + 1 << "\n";
    }
    return 0;
}

1

​*/

#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007

void solve(){
    int n,a,b;
    cin>>n>>a>>b;
    int arr[n+1];
    int ans=0;
    for(int i=1;i<=n;i++){
        arr[i]=(a*i)/b;
    }
    for(int i=1;i<=n;i++){
        for(int j=i*2;j<=n;j+=i){
            arr[j]=(arr[j]-arr[i]);
        }
        ans+=arr[i];
    }
    cout<<ans+1<<"\n";
}



signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    while(n--){
        solve();
    }
    // solve();
    return 0;
}