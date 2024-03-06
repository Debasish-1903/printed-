/*Can You Make C

Time-Limit: 1 sec Score: 1.00/100
Difficulty : *
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

Let us see the following equation,

Ax + By = C

Given three positive integers A, B and C.

You have to determine whether there exists at least one solution for some 
integers value of x and y where x,
 y may be negative or non-negative integers.


Input Format

The first line contains T (1 ≤ T ≤ 100000), the number of test cases.
Each of the next T lines contains three positive integers A, B, C (1 ≤ A, B, C ≤ 109).


Output Format

Print "Yes" (without quotes) if at least one solution exits,
 otherwise print "No" (without quotes).


Sample Input 1

2

6 9 33

2 8 1


Sample Output 1

Yes

No

Note

Explanation 1:
For x = 1, y = 3, 6 * 1 + 9 * 3 = 33. The equation is satisfied for (1, 3).

Explanation 2:
No solution exists in this case. Observe that A and B are even 
numbers. So Ax + By is always even number, irrespective of the value of x and y.
But C is an odd number. So no solution exists in this case.*/

ll gcd(ll a, ll b){
	
	
	if(a==0){
		
		return b;
	}else{
		
		
		 return gcd(b%a,a);
	}
	
	
}

void solve(){
	
	ll a,b,c,d;
	
	cin>>a>>b>>c;
	
 d=gcd(a,b);

//cout<<c<<" "<<d<<" "<<c%d<<nl;
	
	if(c%d==0){
		//cout<<c%d<<nl;
		
		cout<<"Yes"<<nl;
	}else{
		
		
		cout<<"No"<<nl;
	}
	
	
	
	
}


/*Number of Divisors AZ101

Time-Limit: 1 sec Score: 100.00/100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Description

You are given an integer N. You have to find the number of divisors of N.


Input Format

The first line of the input contains one integer T - 
the number of test cases. Then T test cases follow.

The first line of each test case contains one integer N.


Output Format

For each test case, print the number of divisors of N.


Constraints

1 ≤ T ≤ 1000

1 ≤ N ≤ 107


Sample Input 1

3
12
5
9

Sample Output 1

6
2
3

Note

For the first test case, the divisors of 12 are: 1, 2, 3, 4, 6, 12.

For the second test case, the divisors of 5 are: 1, 5.

For the third test case, the divisors of 9 are: 1, 3, 9.*/

void solve(){
	
	ll n;
	cin>>n;
	
	ll cnt=0;
	
	for(int i=1;i*i<=n;i++){
		
		if(n%i==0&&i*i!=n){
			
			cnt+=2;
			
		}else if(i*i==n){
	
	       cnt+=1;
	
		}
		
		}
	
	cout<<cnt<<nl;
		
}

/*Prime Check AZ101

Time-Limit: 1 sec Score: 1.00/100
Difficulty : *
 Memory: 256 MB Accepted Submissions: 100
Description

You are given an integer N. You have to tell whether the number is prime or not.


Input Format

The first line of the input contains one integer T - the number of test cases. Then T
 test cases follow.

The first line of each test case contains one integer N.


Output Format

For each test case, print “YES” if the number is prime and 
“NO” if the number is not prime.


Constraints

1 ≤ T ≤ 100

1 ≤ N ≤ 107


Sample Input 1

3
5
12
37

Sample Output 1

YES
NO
YES

Note

For the first test case, divisors of 5 are 1 and 5, so it is a prime number.

For the second test case, divisors of 12 are 1, 2, 3, 4, 6 and 12, 
so it is not a prime number.

For the third test case, divisors of 37 are 1 and 37, so it is a prime number.*/


void solve(){
	
	ll n;
	cin>>n;
	ll cnt=0;
	
	for(ll i=2;i*i<=n;i++){
		
		if(n%i==0){
			
			cnt=1;
            break;
			
		}
		
	}
	
if(n<2){
	    
	    cout<<"NO"<<nl;
	}
	
	else if(cnt==0){
		
		cout<<"YES"<<nl;
	}else{
		
		cout<<"NO"<<nl;
	}
}

//editorial code

int main() {
  IOS int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    bool is_prime = 1;
    for (int i = 2; i * i <= n; ++i) {
      if (n % i == 0) {
        is_prime = 0;
      }
    }
    if (n == 1 || is_prime == 0) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
    }
  }
  return 0;
} 

/*Exponentiation AZ101

Time-Limit: 1 sec Score: 1.00/100
Difficulty : **
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

You are given four integers - A,B,C, and P. P is a prime number.
Find A^B^C%P.
NOTE: 0^0=1.

Input Format
The first line of the input contains one integer T - the number of test cases. Then 
T test cases follow.The first line of each test case contains four space-separated integers 
A,B,C,P.

Output Format

For each test case, print  
A^B^C%P.

Constraints

1≤T≤2×10^5

0≤A,B,C≤10^9

2≤P≤10^4

Sample Input 1

3
2 4 2 7
1 6 20 5
3 1 200 3

Sample Output 1

2
1
0

Note

For the first test case, 
2^4^2%7=2^16%7=65536%7=2
.
For the second test case, 
1^6^20%5=1%5=1
.
For the third test case, 3^1^200%3=3^1%3=3%3=0
.*/

ll expo(ll a, ll x, ll p)  //(a^x)%p
{
  ll n, ans = 1;
  // prod= (a^(2^p1))
  while (x) {
    if (x % 2) {
      ans = ((ans % p) * (a % p)) % p;
    }
    a = ((a % p) * (a % p)) % p;
    x = x / 2;
  }
  return ans;
}
void solve() {
  // write your code here
  ll n, res, ans, a, b, c, p;
  cin >> a >> b >> c >> p;
  if (b == 0 && c != 0) {
    cout << '1' << '\n';
  }

  else if (a % p == 0 || a == 0) {
    cout << "0\n";
  } else {
    res = expo(b, c, p - 1);
    ans = expo(a, res, p);
    cout << ans << endl;
  }
}


/*Divide the Piles

Time-Limit: 1 sec Score: 100.00/100
Difficulty : *
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

There are N piles of stones in front of you. ith pile contains Ai number of stones.
You want to find whether it is possible to split each pile into 1 or
 more piles of X (≥ 2) stones such that each 
splitted-pile has exactly X stones.
Note that X should be the same for each pile.


Input Format

The first line contains T (1 ≤ T ≤ 100000), the number of test cases. 
The description of each test case is as follows:
The first line contains N, the number of piles (1 ≤ N ≤ 100000).
The second line contains N space-separated positive integers A1, A2, ..., AN (2 ≤ Ai ≤ 109).
It is guaranteed that sum of N over all test cases doesn't exceed 106.


Output Format

For each test case, print "Yes" (without quotes) if it is possible to split. 
Otherwise, print "No" (without quotes).


Sample Input 1

2

5

2 2 6 8 12

4

2 6 3 8


Sample Output 1

Yes

No


Note

Explanation 1:
For X = 2, you can divide each pile into smaller piles of size 2.

Explanation 2:
It is not possible to divide piles into smaller piles with size ≥ 2.*/

ll gcd(ll a, ll b){
    if(b == 0)
        return a;
    return gcd(b, a % b);
}

void solve(){
    ll n;
    cin>>n;
    
    vector<ll>a(n);
    for(ll i = 0; i < n; i++){
        cin >> a[i];
    }
    
    // compute GCD of all the elements in vector 'a'
    ll g = a[0];
    for(ll i = 1; i < n; i++){
        g = gcd(g, a[i]);
    }
    
    // check if GCD is greater than or equal to 2
    if(g >= 2){
        cout << "Yes" << nl;
    }
    else{
        cout << "No" << nl;
    }
}


/*Recurring Fractions

Time-Limit: 1 sec Score: 75.00/100
Difficulty : **
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description
Given two integers representing the numerator and denominator of a fraction, 
print the fraction in string format.
If the fractional part is repeating, enclose the repeating part in parentheses.
If multiple answers are possible, print the one which has the smallest length.

Input Format

The first line contains T (1 ≤ T ≤ 100000), the number of test cases.
Each of the next T lines contains two space-separated integers representing 
numerator and denominator respectively 
(0 ≤ |numerator| ≤ 100 and 1 ≤ |denominator| ≤ 100).
It is guaranteed that the denominator is always a non-zero integer.

Output Format

For each test case, print the fraction in string format.

Sample Input 1

4

1 2

2 1

2 3

-3 7


Sample Output 1

0.5

2

0.(6)

-0.(428571)


Note

Explanation 1:
1 / 2 = 0.5

Explanation 2:
2 / 1 = 2

Explanation 3:
2 / 3 = 0.(6). Note that 0.(66) is also the correct representation in 
decimal format, but it has a greater 
length than 0.(6).


1
*/

//approach 

/*Just break the problem into subparts such as

Whether the final answer is negative or positive
Whether the answer would be terminating or recurring*/

void solve(){
    
ll num,den;
cin>>num>>den;


string ans;
if(num==0) {
    
    ans="0";
     cout<<ans<<nl;
    return;
    
}

if(num<0^den<0){
    
    ans+="-";
    
}

ll n=abs(num);
ll d=abs(den);

ans+=to_string(n/d);
n%=d;
if(n==0){
    cout<<ans<<nl;
    return;
    
}

ans+=".";

map<ll,ll>seen;
while(n!=0){
    if(seen.find(n)!=seen.end()){
        ans.insert(seen[n],"(");
        
        ans+=")";
        
        break;
        
    }
    
    
    
   seen[n]=ans.size(); 
    n*=10;
    ans+=to_string(n/d);
    n%=d;
     
    
}
cout<<ans<<nl;
    
	
}


/*Number of Diagonals

Time-Limit: 1 sec Score: 1.00/100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

Find the number of diagonals in the Convex N-gon.


Input Format

The first line contains T (1 ≤ T ≤ 100000), the number of test cases.
Each of the next T lines contains a positive integer N denoting the number of sides of 
convex polygon (3 ≤ N ≤ 109).


Output Format

For each test case, print a single number denoting the number of 
diagonals in the convex N-gon.
 Since answer can be large,
 print it with modulo 1000000007.


Sample Input 1

2

4

5


Sample Output 1

2

5

Note

*/


// approach 

/*((NC2)−N)%1000000007
.
Time Complexity : O(1)*/

ll mul(ll a,ll b){
	
	ll ans=(a*b)%mod;
	if(ans<0) ans+=mod;
	
	return ans;
}

ll binexp(ll a, ll b){
	
	ll ans=1;
	
	while(b>0){
	if(b%2==1){
		
		ans=(ans*a)%mod;
		
		
	}
	
	a=(a*a)%mod;
	
	b/=2;
	
	
	
}
 return (ans+mod)%mod;
}

void solve(){
	

ll n;
cin>>n;


// nc2-n;
ll ans=mul(n,n-1);

ans=mul(ans,binexp(2,mod-2));
ans=ans-n;

cout<<(ans+mod)%mod<<nl;


//cout<<(ans+mod)%mod<<nl;
	
}


/*Number of Ways to Reach B

Time-Limit: 1 sec Score: 1.00/100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

You have given a grid of N x M. You are initially at position A(0, 0) 
and you want to reach B(N, M). 
From the given cell (i, j), we are allowed to move to cells (i + 1, j) and 
(i, j + 1) only.
Find the number of different ways to reach B from A?
 



Input Format

The first line contains T (1 ≤ T ≤ 100000), the number of test cases.
Each of the next T lines contains two positive integers N, M (1 ≤ N, M ≤ 105).


Output Format

For each test case, print the number of ways to reach B from A. 
Since answer can be large, print it with modulo 1000000007.


Sample Input 1

2

2 1

3 2


Sample Output 1

3

10*/

//(m+n)cm or (m+n)cn

vector<ll>fac;
// precomputation of m+n factorials
void pre(){
	
	fac.push_back(0);
	fac.push_back(1);
	for(ll i=2;i<=2*1e5;i++){
		
		ll val=(fac.back()*i)%mod;
		fac.push_back(val);
		
	}
		
	//cout<<fac[4];
}

ll binexp(ll a, ll b){
	
	ll ans=1;
	while(b>0){
		
		if(b%2==1){
			
			ans=(ans%mod)*(a%mod)%mod;
		}
		
		a=(a*a)%mod;
		b/=2;
		
	}
	
	return (ans+mod)%mod;
	
}

void solve(){
	
	int n,m;
	cin>>n>>m;
	
// 	ll v1=fac[n];
// ll v2=fac[m];

// cout<<v1<<" "<<v2<<nl<<nl;
	
ll	v1=binexp(fac[n],mod-2);
	
	ll v2=binexp(fac[m],mod-2);

//cout<<v1<<" "<<v2<<nl<<nl;
	
	ll result=((fac[n+m]%mod)*(v1%mod))%mod;
	result=(result*(v2%mod))%mod;

	cout<<result<<nl;
		
}

/*Number of Parts in Convex Polygon

Time-Limit: 1 sec Score: 50.00/100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

You have given Convex N-gon. Draw all diagonals of the convex N-gon. 
Suppose no three diagonals pass through a point.
Into how many parts is the N-gon divided?


Input Format

The first line contains T (1 ≤ T ≤ 100000), the number of test cases.
Each of the next T lines contains a positive integer N denoting the
 number of sides of convex polygon (3 ≤ N ≤ 109).


Output Format

For each test case, print a single number denoting the number of parts the
convex N-gon divided. Since answer can be large, print it with modulo 1000000007.


Sample Input 1

2

4

5


Sample Output 1

4

11


Note

*/

ll mul(ll a,ll b){
	
	ll ans=(a*b)%mod;
	if(ans<0) ans+=mod;
	
	return ans;
}


ll binexp(ll a, ll b){
	
	ll ans=1;
	
	while(b>0){
	if(b%2==1){
		
		ans=(ans*a)%mod;
		
		
	}
	
	a=(a*a)%mod;
	
	b/=2;
	
}
 return (ans+mod)%mod;
}
void solve(){
	

ll n;
cin>>n;


// nc2-n;
ll ans1=mul(n,n-1);

ans1=mul(ans1,binexp(2,mod-2));
ans1=ans1-n;
if (ans1<0){
	
	ans1+=mod;
}




ll ans2=mul(n,n-1);
ans2=mul(ans2,n-2);
ans2=mul(ans2,n-3);

ans2=mul(ans2,binexp(24,mod-2));
if(ans2<0){
	
	ans2+=mod;
}

ll ans=ans1+ans2+1;

cout<<(ans+mod)%mod<<nl;


//cout<<(ans+mod)%mod<<nl;
	
}

/*Number of Intersecting Diagonals

Time-Limit: 1 sec Score: 75.00/100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

Find the number of unordered pairs of intersecting diagonals in the Convex N-gon.
 The intersecting point should be inside the polygon.


Input Format

The first line contains T (1 ≤ T ≤ 100000), the number of test cases.
Each of the next T lines contains a positive integer N denoting the number
 of sides of convex polygon (3 ≤ N ≤ 109).


Output Format

For each test case, print a single number denoting the number of
 intersecting diagonals in the convex N-gon. 
Since answer can be large, print it with modulo 1000000007.


Sample Input 1

2

4

5


Sample Output 1

1

5


Note

Explanation 1:
(1, 2)

Explanatino 2:
(1, 3), (1, 5), (2, 3), (2, 4), (4, 5)

*/

lli binaryexpo(lli a, lli b, lli m)
{
    lli ans = 1;
    while (b)
    {
        if (b % 2 == 1)
        {
            ans = (ans * a) % m;
        }
        a = (a * a) % m;
        b /= 2;
    }

    return ans;
}

void solve()
{
    //diagonals=nc2-n
    lli n,r,s;
    cin >> n; 
    n %= mod;
    // lli Nr = ( n* (n-1))%mod;//nc2=n(n-1)/2 solve 2 using inverse concept
    // lli dr = 2;
    // lli Dr = binaryexpo(dr, mod - 2, mod);
    // lli ans = (Nr * Dr) % mod;
    lli Nr1=(n*(n-1))%mod;
    lli Nr2=(Nr1*(n-2))%mod;
    lli Nr3=(Nr2*(n-3))%mod;
    lli dr1=24;
    lli Dr3 = binaryexpo(dr1, mod - 2, mod);
    lli ans1=(Nr3*Dr3)%mod;
    // lli ansf=(ans+ans1)%mod;
    // ansf+=1;//final formula
    // ansf-=n;
    cout << ((ans1 % mod) + mod) % mod << endl;
    
    
}

/*Solve the Equation

Time-Limit: 1 sec Score: 1.00/100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

You have given an equation of the form  (a op1 b op2 c) mod p
op1, op2 are operators which can be {+, -, *, /}.
Consider the example: (a * b / c) mod p. Here op1 = * and op2 = /.
It is guaranteed that (a, p) = (b, p) = (c, p) = 1 and p is a prime number.
Compute the value of the equation.

Note: 

(a, b) = 1, means a and b are coprime numbers.
Operators follow the same precedence rules as in mathematics.

Input Format

The first line contains T (1 ≤ T ≤ 100000), the number of test cases.
Each of the next T lines contains an equation in the form (a op1 b op2 c) 
mod p (1 ≤ a, b, c, p ≤ 109).
It is guaranteed that (a, p) = (b, p) = (c, p) = 1 and p is a prime number.


Output Format

For each test case, print a single number denoting the value of the equation.
 Since it is mod p, the value must belong to 0 to p - 1.


Sample Input 1

2

(1 + 2 / 1) mod 3

(2 * 3 - 8) mod 5


Sample Output 1

0

3


Note

Explanation 1:
(1 + 2 / 1) mod 3 = 3 mod 3 = 0.

Explanatino 2:
(2 * 3 - 8) mod 5 = -2 mod 5 = 3.*/

#include <bits/stdc++.h>
using namespace std;
#define IOS                \
  ios::sync_with_stdio(0); \
  cin.tie(0);              \
  cout.tie(0);
#define ll long long

ll mod = 1000000007;

ll add(ll a, ll b) { return ((a % mod) + (b % mod)) % mod; }
ll sub(ll a, ll b) {
  ll ans = ((a % mod) - (b % mod)) % mod;
  ans %= mod;
  ans = (ans + mod) % mod;
  return ans;
}
ll mul(ll a, ll b) { return ((a % mod) * (b % mod)) % mod; }
ll power(ll a, ll b) {
  ll ans = 1;
  while (b) {
    if (b % 2) {
      ans = ((ans % mod) * (a % mod)) % mod;
    }
    a = ((a % mod) * (a % mod)) % mod;
    b /= 2;
  }
  return ans;
}
ll res(char op, ll a, ll b) {
  if (op == '+')
    return add(a, b);
  else if (op == '-')
    return sub(a, b);
  else if (op == '*')
    return mul(a, b);
  else
    return mul(a, power(b, mod - 2));
}

signed main() {
  IOS ll t;
  cin >> t;
  ll a, b, c;
  string s;
  getline(cin, s);
  while (t--) {
    char op1, op2;
    string s1, s2, s3;
    cin >> s1 >> op1 >> b >> op2 >> s2 >> s3 >> mod;
    a = stoi(s1.substr(1));
    s2.pop_back();
    c = stoi(s2);
    ll ans = 0;
    if ((op1 == '+') || (op1 == '-')) {
      if ((op2 == '+') || (op2 == '-')) {
        ans = res(op1, a, b);
        ans = res(op2, ans, c);
      } else {
        ans = res(op2, b, c);
        ans = res(op1, a, ans);
      }
    } else {
      ans = res(op1, a, b);
      ans = res(op2, ans, c);
    }
    cout << ans << "\n";
  }
  return 0;
}


/*LR Sum Query

Time-Limit: 4 sec Score: 100.00/100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

Given an array of N integers and Q queries. In each query two integers L, R is given, 
you have to find (A[L] + A[L+1] + A[L+2] + A[L+3]...A[R]) % 10^9+7.
 


Input Format

The first line contains two space-separated integers N, Q where 1<=N<=10^6, 1<=Q<=10^6.

Next line contains N space-separated integers (-1e9<=Ai<=1e9).

Next Q lines contain two space-separated integers L, R where 1<=L<=R<=N.


Output Format

For each query print the value of (A[L] + A[L+1] + A[L+2] + A[L+3]...A[R]) % 10^9+7 
in a new line.


Sample Input 1

10 10
12 -23 -123 2345 2345 44 345 -93945 -5353 1
1 5
1 8
1 10
2 2
6 6
4 8
2 9
4 10
3 6
5 9


Sample Output 1

4556
999911007
999905655
999999984
44
999911141
999905642
999905789
4611
999903443*/

ll add(ll a,ll b){
	
	ll ans=(a+b)%mod;
	if(ans<0) ans+=mod;
	
	return ans;
}

 ll sub(ll a,ll b){
	
	ll ans=(a-b)%mod;
	if(ans<0) ans+=mod;
	
	return ans;
}


void solve(){
	
	
	ll n,q;
	cin>>n>>q;
	v a ;
	 for(ll i=0;i<n;i++){
	
	ll x;
		
		cin>>x;
		a.pb(x);
	}
	
	
	
	v p(n);
	p[0]=a[0];
	for(ll i=1;i<n;i++){
		
		
		p[i]=add(p[i-1],a[i]);
	}
	
	while(q--){
	ll l,r;
	cin>>l>>r;
	// 1 indexed array
	
	ll ans;
	if(l==1){
	    
	    ans=p[r-1];
	   
	}else{
	
	 ans=sub(p[r-1],p[l-2]);}
	
	cout<<(ans+mod)%mod<<nl;

}
	
}

/*Good Numbers

Time-Limit: 4 sec Score: 1.00/100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

There are N students and ith student likes all numbers in the range [li ,ri ],
 both inclusive. 
A number is good if it is liked by at least K students.

You are even Q queries. Each query consists of two numbers L, R. You have to 
find how many numbers in the range [L,R] is good.


Input Format

The first line of input contains three integers, N, K (1≤K≤N<=1000000), and
 Q (1≤Q≤1000000).

The next N lines contain two integers li and ri (1≤li≤ri≤1000000), 
describing that the i-th student likes all the numbers [li,ri].

The next Q lines contain L and R, (1≤L≤R≤1000000).


Output Format

For each query print how many numbers in the range [L,R] is good in a new line.


Sample Input 1

10 3 10
1 5
2 7
3 9
1 5
3 8
4 10
7 10
8 8
5 5
6 7
1 5
3 8
4 9
3 10
2 6
3 9
7 7
5 5
8 8
3 7

Sample Output 1

4
6
6
7
5
7
1
1
1
5*/

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,k,q;
    cin>>n>>k>>q;
    int p[N],arr[N];
    for(int i=0;i<N;i++)
    {
        p[i]=0;
    	arr[i]=0;
    }
    while(n--){
        int l,r;
        cin>>l>>r;
        p[l]+=1;
        p[r+1]-=1;
    }
    for(int i=1;i<N;i++)
    {
        p[i]=p[i-1]+p[i];
    }
    for(int i=1;i<N;i++)
    {
        p[i]=(p[i]>=k);
    }
    for(int i=1;i<N;i++)
    {
        arr[i]=arr[i-1]+p[i];
    }
    while(q--)
    {
        int L,R,ans;
        cin>>L>>R;
        ans=arr[R]-arr[L-1];
        cout<<ans<<"\n";
    }
    return 0;
}

/*Mobile Notifications AZ101

Time-Limit: 1 sec Score: 1.00/100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Description

You recently bought a new mobile phone. There are N applications 
in the phone and all generate notifications.
 There are 3 types of events

1 X - A new notification is generated by application X
2 X - You read all notifications by application X, you may re-read 
some notifications
3 Y - You read the first Y notifications in the phone. Note that 
you don’t read the first Y unread notifications,
 you just read the first Y notifications and you might re-read a 
 few notifications. It is guaranteed that there have 
 been Y notifications before this. 
After every event, find the number of unread notifications in the 
mobile phone.


Input Format

The first line of the input contains one integer T - the number of
 test cases. Then T test cases follow.

The first line of each test case contains two space-separated 
integers N Q - the number of applications
 and the number of queries.

Each of the next Q lines contains two space-separated integers 
Z X or Z Y - the description of each event.


Output Format

For each test case, find the number of unread notifications
 in the mobile phone after every event.


Constraints

1≤ T ≤ 105

1≤ N, Q ≤ 105

1≤ Z ≤ 3

1≤ X ≤ N

1≤ Y ≤ Q

It is guaranteed that the sum of N and the sum of Q over
 all test cases does not exceed 106.


Sample Input 1

2 
3 4 
1 1 
1 3 
3 2 
2 1 
5 6 
1 4 
1 3 
1 5 
3 3 
1 2 
2 4

Sample Output 1

1
2
0
0
1
2
3
0
1
1

Note

For the first test case,

Application 1 generates a notification
Application 3 generates a notification
Read the first 2 notifications.
Read all notifications by application 1
For the second test case, 

Application 4 generates a notification
Application 3 generates a notification
Application 5 generates a notification
Read the first 3 notifications
Application 2 generates a notification
Read all notifications by application 4*/

void solve(){
	
int i,j,k,m,n,q,y=0,ans=0,type,x,a,mark=0;
cin>>n>>q;
vector<int>unread(n+1);
queue<int>left;

while(q--){
    
   cin>>type;
   if(type==1){
       cin>>x;
       unread[x]++;
       ans++;
       left.push(x);// push the application number in left 
       
   }else if(type==2){
       cin>>x;
       
       ans-=unread[x];
       unread[x]=0;
       
   }else{
      cin>>y;
      
      while(y>mark){
      int cur=left.front();
      if(unread[cur]==0){
          
      }else{
          unread[cur]--;
          ans--;   
      }
          mark++;
          left.pop();
          
      }
       
   }
    cout<<ans<<nl;
}
}


/*Distinct Characters AZ101

Time-Limit: 1 sec Score: 100.00/100
Difficulty : **
 Memory: 256 MB Accepted Submissions: 100
Description

You are given a string S. You are given Q queries of two types,
 asking the number of distinct 
characters in the range [L, R] 
and changing the i-th character to c. (1-based indexing)


Input Format

The first line of the input contains one integer T - the number of
 test cases. Then T test cases follow.

The first line of each test contains a string S.

The second line of each test case contains one integer Q -
 the number of queries. 

Each of the next Q lines contain two types of queries: 
either 1 i c or 2 L R. The query 1 is 
for changing the i-th character to c and the query 2 is for 
finding the number 
of distinct characters in the range [L, R].


Output Format

For each test case, print the required queries.


Constraints

1≤ T ≤ 105

1≤ |S| ≤ 105

1≤ Q ≤ 106

1≤ Ai ≤ 105

It is guaranteed that the sum of |S| and the sum of Q over all test 
cases does not exceed 105.


Sample Input 1

2
abbac
3
2 1 3
1 2 c
2 1 4
flower
4
2 2 5
1 3 l
1 6 w
2 1 6

Sample Output 1

2
3
4
4

Note

For the first test case, distinct characters from 1-3 in abbac are ‘a’ and ‘b’.
 Changing string to acbac, distinct characters from 1-3 in abcac are ‘a’, ‘b’ and ‘c’.

For the second test case, distinct characters from 2-5 in flower are ‘l’, ‘o’, ‘w’, ‘e’.
 Changing string to fllwer and then to fllwee, distinct characters from 1-6 are ‘f’, ‘l’, ‘w’, ‘e’.*/

void solve(){
    
	string str;
	cin>>str;
	int q;
	cin>>q;
	
	unordered_set<char>st;
	while(q--){
	    st.clear();
	  char c;
	  int i, a,l,r;
	  
	  cin>>a;
	  
	  if(a==1){
	      cin>>i>>c;
	      
	      str[i-1]=c;
	      
	  }else if(a==2){
	      
	      cin>>l>>r;
	      for(int j=l-1;j<r;j++){
	          
	          st.insert(str[j]);
	          
	      }
	      
	      cout<<st.size()<<nl;
	      
	  }
	    
	}	
}

/*Kth Val

Time-Limit: 4 sec Score: 1.00/100
Difficulty : ***
 Memory: 256 MB Accepted Submissions: 100
Relevant For:202,301,201
Description 

You have been given an array A of N integers and M ranges. ith range is defined by the two integers 
li and ri, li≤ri.

Initially, array S is empty. For range i, add elements A[li],A[li+1]…..A[ri] in the array S. 
After adding all the elements in each of the range, sort the elements of S in ascending order.

You need to answer Q queries. Each query consists of a number K > 0. You have to find the Kth
 smallest element in S, i.e., the element at Kth position in sorted S.

It may be possible that the same element presents multiple times in S.


Input Format

The first line of the input contains a single integer T - the number of test cases(1 ≤ T ≤ 10). 
Then T test cases follow.

The first line of each test case contains three integers N, M, and Q, (1 ≤ N, M, Q ≤ 10^5).

The second line contains N space-separated integers A1, A2,….,AN, the elements of 
the array A, (1≤Ai≤10^9).

Next M lines contain two space-separated integers li and ri - ith range, (1 ≤ li ≤ ri ≤ N).

The last line of a test case contains Q space-separated integers K1, K2,….,KQ, where Ki
 denotes the ith query. (1 ≤ Ki ≤1 0^18).


Output Format

For each test case, print Q space-separated integers, where ith number denotes the answer 
of ith query.If the Kth value doesn't exist for a particular query, print -1.


Sample Input 1

2
3 3 4
1 3 2
1 3
2 3
1 1
1 2 5 8
4 2 3
1 5 4 3
1 4
1 3
1 5 7

Sample Output 1

1 1 3 -1
1 4 5

Note

Test Case 1: Initially array S is empty.

Add the 1st range -> S = {1,3,2}.

Add the 2nd range -> S = {1,3,2,3,2}

Add the 3rd range -> S = {1,3,2,3,2,1}

After sorting the array, S = {1,1,2,2,3,3}

For K = 8, the 8th element doesn't exist in the atta S. So the answer of the 4th query is -1.

Test Case 2: Initially array S is empty.

Add the 1st range -> S = {1,5,4,3}.

Add the 2nd range -> S = {1,5,4,3,1,5,4}.

After sorting the array, S = {1,1,3,4,4,5,5}.*/

void solve() {
  ll n, k, q, i, a, b, x;
  cin >> n >> k >> q;
  vector<ll> v(n + 1), pre(n + 2, 0), dp(n);
  vector<pair<ll, ll> > suf;

  for (i = 1; i <= n; i++) {
    cin >> v[i];
  }
  for (i = 0; i < k; i++) {
    cin >> a >> b;
    pre[a] += 1;
    pre[b + 1] -= 1;
  }

  for (i = 1; i <= n; i++) {
    if (i != 0) {
      pre[i] = pre[i - 1] + pre[i];
      suf.push_back({v[i], pre[i]});
    }
  }
  sort(suf.begin(), suf.end());
  for (i = 0; i < n; i++) {
    if (i == 0)
      dp[i] = suf[i].second;
    else
      dp[i] = dp[i - 1] + suf[i].second;
  }
  for (i = 0; i < q; i++) {
    cin >> a;
    if (lower_bound(dp.begin(), dp.end(), a) != dp.end()) {
      x = lower_bound(dp.begin(), dp.end(), a) - dp.begin();
      cout << suf[x].first << " ";
    } else {
      cout << "-1 ";
    }
  }
  cout << endl;
}


/*Rectangle Sum Query

Time-Limit: 4 sec Score: 1.00/100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

Given a 2d-array of dimension N*M and Q queries. In each query four integers x1, y1, x2, y2 
is given, you have to find the sum of submatrix with (x1,y1) be the leftmost 
corner and (x2,y2) be the rightmost corner %10^9+7.


Input Format

The first line contains three space-separated integers N, M, Q where 1<=N, M<=10^3, 
1<=Q<=10^6.

Next N lines contains M space-separated integers (-1e9<=Aij<=1e9).

Next Q lines contains four space separated integers x1, y1, x2, y2 where 1<=x1<=x2<=N, 
1<=y1<=y2<=M.

Output Format

For each query print, the sum of submatrix with (x1,y1) be the leftmost corner and (x2,y2) 
be the rightmost corner in a new line %10^9+7.


Sample Input 1

5 5 5
-1 2 3 -4 2
0 0 0 0 4
1 2 4 3 5
-1 -5 -2 3 4
0 -3 -5 3 -6
1 1 2 2
1 2 3 4
2 3 3 3
4 4 4 4
2 3 2 4

Sample Output 1

1
10
4
3
0*/

//approach

/*Use Prefix Sums in 2D matrix. If new to this concept,
Check the video solution - 2D Prefix Sums Concept.


We solve this problem using the concept of prefix sums.

To do this efficiently using prefix sums, we need to first precompute a 2d-array called prefix sums, 
where each cell (i,j) stores the sum of all the values in the submatrix with (1,1) as the top-left 
corner and (i,j) as the bottom-right corner. We can compute this array using the following formula:

partialsums[i][j] = partialsums[i-1][j] + partialsums[i][j-1] - partialsums[i-1][j-1] + values[i][j]

Here, values[i][j] is the value of the cell at (i,j) in the original 2d-array.

Now to find the answer to each of the queries, where we are given the top left corner (x1,y1) 
and bottom right corner (x2,y2). We can find the sum of that rectangle by doing

ans=partialsums[x2][y2]-partialsums[x1][y2]-partialsums[x2][y1]+partialsums[x1][y1]

The time complexity for this algorithm is 
O(Q+N×M)
. For each query it almost takes constant time. initially we iterate over the entire 2D matrix to
 find the prefix sum of the matrix.*/


 
int mod = 1e9 + 7;
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, m, q;
  cin >> n >> m >> q;
  long long arr[n + 1][m + 1];
  memset(arr, 0, sizeof(arr));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> arr[i][j];
      arr[i][j] += arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1];
    }
  }
  while (q--) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    long long ans =
        arr[x2][y2] - arr[x1 - 1][y2] - arr[x2][y1 - 1] + arr[x1 - 1][y1 - 1];
    ans %= mod;
    if (ans < 0) ans += mod;
    cout << ans << '\n';
  }
  return 0;
}

/*Max Value in the Rectangle

Time-Limit: 4 sec Score: 1.00/100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

Given a 2d-array of dimension N*M and Q queries. In each query five integers x1, y1, x2, y2, C 
is given,you have to increase the value of each cell in the submatrix with (x1,y1) be the 
leftmost corner and (x2,y2) be the rightmost corner by C. Initially the value of all the 
cell of the 2d-array is 0.

After all the query is performed, print the maximum value present in the 2d-array and the 
number of the cell with the maximum value.


Input Format

The first line contains three space-separated integers N, M, Q where 1<=N, M<=10^3, 1<=Q<=10^6.

The next Q lines contains five space separated integers x1, y1, x2, y2, C where 1<=x1<=x2<=N,
 1<=y1<=y2<=M, -10^9<=C<=10^9.


Output Format

After all the query is performed, print 2 space-separated integers representing the maximum value
 present in the 2d-array and the number of the cell with the maximum value.


Sample Input 1

5 5 5
1 1 2 2 -8
1 2 3 4 9
2 3 3 3 -2
4 4 4 4 -4
2 3 2 4 0

Sample Output 1

9 5
/*

//approach 

Use Partial Sums in 2D matrix. If new to this concept,
Check the video solution - 2D Partial Sums Concept.


We need to add a value C to a rectangular region with (x1,y1) as the top left 
corner and (x2,y2) as the bottom right corner.
 Lets say we use our idea of partial sums, and just add +C
 to the top left corner at (x1,y1). What will be its effect on the matrix? We can see that 
 due to this addition all the elements in the rectangle (x1,y1) as the left corner and (n,m)
  as the right bottom corner would have the effect of 
+C.But we surely don't want this because our aim is only to add C in the smaller rectangle 
with (x1,y1) and (x2,y2) as corners. How to counter this problem? Well we do a −C
 at the top right and bottom left corners which are (x1,y2) and (x2,y1). 
 Is that all? Does it take care of everything. What about the region which is to the right
  and bottom of (x2,y2). Isn't it getting the effect of all the above additions and 
  subtractions? So it will have one +C and two −C contributions. Well we can easily 
  solve this issue by just adjusting this with a +C at the index (x2,y2).


We solve this problem using the concept of partial sums.

First, create a 2d-array of size N*M to store the initial values of all cells as 0.

Next, for each query (x1, y1, x2, y2, C), we need to add C to each cell in 
the submatrix with (x1,y1)
 be the leftmost corner and (x2,y2) be the rightmost corner.

To do this efficiently using partial sums, we need to first precompute a 
2d-array called partial sums, 
where each cell (i,j) stores the sum of all the values in the submatrix with 
(1,1) as the top-left corner
 and (i,j) as the bottom-right corner. We can compute this array
  using the following formula:partialsums[i][j] = 
  partialsums[i-1][j] + partialsums[i][j-1] - partialsums[i-1][j-1] + values[i][j]

Here, values[i][j] is the value of the cell at (i,j) in the original 2d-array.

Once we have computed the partial sums array, we can update the values in the submatrix 
with (x1,y1) as the top-left corner and (x2,y2) as the bottom-right corner by adding C 
to each cell using the following formula:

partialsums[x2][y2] += C
partialsums[x1-1][y2] -= C
partialsums[x2][y1-1] -= C
partialsums[x1-1][y1-1] += C

After all the queries have been processed, we can compute the final values in the 
original 2d-array by subtracting the partial sums for the overlapping submatrices 
using the following formula:
values[i][j] = 
partialsums[i][j] - partialsums[i-1][j] - partialsums[i][j-1] + partialsums[i-1][j-1]

This will give us the final values in the original 2d-array after all the queries 
have been processed.
After this just iterate over the entire matrix to find the maximum element.
The time complexity for this algorithm is O(Q+N×M)
. For each query it almost takes constant time. Finally we iterate over the entire
 2D matrix to find the prefix sum of the partial sum matrix and keep updating the maximum
  value and its position.


*/


 ll a[N][N];
 ll prefix[N][N];
void solve(){

ll n,m,q;
cin>>n>>m>>q;

while(q--){
    
   ll x1,y1,x2,y2,c;
   cin>>x1>>y1>>x2>>y2>>c;
   
   a[x1][y1]+=c;
   a[x1][y2+1]-=c;
   a[x2+1][y1]-=c;
   a[x2+1][y2+1]+=c;
    
}


ll max=a[1][1];
ll cnt=0;
for(ll i=1;i<=n;i++){
    
    for(ll j=1;j<=m;j++){
        
        prefix[i][j]=a[i][j]+prefix[i-1][j]+prefix[i][j-1]-prefix[i-1][j-1];
        
         if(prefix[i][j]==max){
            
            cnt++;
        }
        
        if(prefix[i][j]>max){
            
            max=prefix[i][j];
            cnt=1;
        }
        
    }
}

cout<<max<<" "<<cnt;
}


/*GP Addition

Time-Limit: 4 sec Score: 1.00/100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Relevant For:201,202,301
Description

Given an array of N integers and Q queries and an integer K. Initially,
 all the elements of the array have value 0.

In each query 3 integers A, L, R is given, which means perform GP addition

Arr[L]+=A

Arr[L+1]+=AK

Arr[L+2]+=AKK

Arr[L+3]+=AKKK

.

.

.

.

Arr[R]+=A*(K^(R-L))

 

After performing all the operations. Print the final array % 10^9+7.


Input Format

The first line contains three space-separated integers N, Q, K 
where 1<=N<=10^6, 1<=Q<=10^6, 1<=K<=10^9.

Next Q lines contain three space-separated integers A, L, 
R where 0<=A<=10^4, 1<=L<=R<=N.


Output Format

Print the N space-separated integer representing the final array %10^9+7.


Sample Input 1

5 5 2
3 1 5
4 2 2
6 3 5
9 5 5
4 2 4

Sample Output 1

3 14 26 52 81 */

long long expo(long long a,long long b){
    long long ans=1;
    while (b){
        if(b%2){ans=(ans*a)%M;}
        a=(a*a)%M;
        b=b/2;
    } return ans;
}

signed main(){
    int n,q; long long K; cin>>n>>q>>K;
    long long a[n]={0}; long long k[n+1];
    long long p[n+1]={0};
    for (int i=0;i<n+1;i++){k[i]=expo(K,i);}
    while(q--){
        long long A,l,r; cin>>A>>l>>r;
        p[l-1]=(p[l-1]+A+M)%M;
        p[r]=((p[r]-(A*k[r-l+1]))+M)%M;   
    }
    for(int i=1;i<n+1;i++){
        p[i]=(p[i]+((p[i-1]*K)+M)%M);
        while(p[i]<0){p[i]=(p[i]+M)%M;}
        p[i]=p[i]%M;
    }
    // for(int i=0;i<n+1;i++){
    //     cout<<p[i]<<" ";
    // }
    cout<<'\n';
    //  for(int i=0;i<n;i++){
    //     cout<<o[i]<<" ";
    // }
    // cout<<'\n';
    for(int i=0;i<n;i++){
        a[i]=p[i];
        while(a[i]<0){a[i]=(a[i]+M)%M;}
        a[i]=a[i]%M;
        cout<<a[i]<<" ";
    }

}

//approach 

/*Use Gp on Partial Sums. If new to this concept,
Check the video solution - GP on Partial Sum.


Arr[i]=A×K^i−L

Arr[i]=A×(K^i/K^L)

Arr[i]=AK^−L×K^i

Arr[i]=constant for a query ×K^i
Arr[i]=C×K^i

The C is constant across a particular query. So we can make use of partial sums for this 
this particular constant. Just add C at Arr[L] and subtract it from Arr[R+1].

For the variable part 
K^i, make sure when we are at a particular index, bring K to that particular power 
of i and multiply with the constant term in array Arr.
So our steps for a particular query A L R, our steps are as follows;
Arr[L]+=AK^-L

Arr[R+1]−=AK^−L
Do this across all queries
After all queries are executed start a loop from the beginning of the array and
Arr[i]+=Arr[i−1]
Arr[i]=Arr[i]∗Ki

In the given code, the add function is used to add a value to an element of the array,
 while the sub function is used to subtract a value from an element of the array.

The time complexity of the given problem is 
O(Q+N),where Q is the number of queries and N is the size of the array.

The while loop in the main function iterates Q times, and each iteration takes 
O(1) time. Inside the while loop, we call the add and sub functions which take 
O(1)time each. Therefore, the time complexity of processing all the queries is O(Q)
.
After processing all the queries, the for loop iterates 
N times and performs constant-time operations inside the loop. Therefore, 
the time complexity of the for loop is also O(N).
So the overall time complexity of the main function is O(Q+N)
.*/


/*AP Addition

Time-Limit: 4 sec Score: 100.00/100
Difficulty : ***
 Memory: 256 MB Accepted Submissions: 100
Relevant For:201,203,301
Description

Given an array of N integers and Q queries. Initially, all the elements of the array 
have value 0.
In each query 4 integers A, D, L, R is given, which means perform AP addition

Arr[L]+=A

Arr[L+1]+=A+D

Arr[L+2]+=A+2D

Arr[L+3]+=A+3D

.

.

.

.

Arr[R]+=A+(R-L)*D.

After performing all the operations. Print the final array % 10^9+7.


Input Format

The first line contains two space-separated integers N, Q where 1<=N<=10^6, 1<=Q<=10^6.

Next Q lines contain four space-separated integers A, D, L, R where 0<=A,D<=10^4, 1<=L<=R<=N.


Output Format

Print the N space-separated integer representing the final array %10^9+7.


Sample Input 1

5 5
1 3 1 5
2 4 2 2
5 6 3 5
6 9 5 5
1 4 2 4

Sample Output 1

1 7 17 30 36 */

ll add(ll a,ll b){
    
    ll ans=(a+b)%mod;
    if(ans<0) ans+=mod;
    
    return ans;
}

 ll sub(ll a,ll b){
    
    ll ans=(a-b)%mod;
    if(ans<0) ans+=mod;
    
    return ans;
}

void solve(){

ll n,q;
cin>>n>>q;
while(q--){
  ll a,d,l,r;
  
  cin>>a>>d>>l>>r;
  
  arr[l]+=(a-(d*l));
  
  arr[r+1]-=(a-(d*l));
  
  brr[l]+=d;
  brr[r+1]-=d;   
    
}

for(ll i=1;i<=n+1;i++){
    
    arr[i]+=arr[i-1]%mod;
  // rect[i]=arr[i]+rect[i-1];
    brr[i]+=brr[i-1]%mod;
    //rect1[i]=brr[i]+rect1[i-1];
    
}

// for(ll i=1;i<=n+1;i++){
    
//   cout<<rect[i]<<" " ;
   
// }
// cout<<nl;

//  for(ll i=1;i<=n+1;i++){
    
//   cout<<rect1[i]<<" " ;
   
// }  
// cout<<nl;


for(ll i=1;i<=n;i++){
    
    ll ans=arr[i]+i*brr[i];
    ans=(ans%mod+mod)%mod;
    cout<<ans<<" ";
}

cout<<nl;
	
}


/*Powers of Two

Time-Limit: 1 sec Score: 1.00/100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Description

You are given an array A of N integers. Find the number of pairs (i, j) such that 
i < j and Ai + Aj is a power of 2.


Input Format

The first line of the input contains one integer T - the number of test cases.
 Then T test cases follow.

The first line of each test case contains one integer N - the length of the array. 

The second line of each test case contains N space-separated integers.


Output Format

For each test case, print the number of pairs (i, j) such that i < j and Ai + Aj is a 
power of 2.


Constraints

1≤ T ≤ 105

1≤ N ≤ 105

1≤ Ai ≤ 230

It is guaranteed that the sum of N over all test cases does not exceed 105.


Sample Input 1

3
5
1 7 2 3 1
3
1 1 1
3
2 6 14

Sample Output 1

5
3
2

Note

For the first test case, possible pairs having powers of two as sum are: 
[1, 7], [1, 3], [1, 1], [7, 1], [3, 1]

For the second test case, possible pairs having powers of two as sum are: 
[1, 1], [1, 1], [1, 1]

For the third test case, possible pairs having powers of two as sum are:
 [2, 6], [2, 14]*/



/*Store all the integers in a map.


Iterate through all powers of 2 possible as sum and store the integers in a map.
 As you iterate through the array,
 check for every possible power of 2, the number of pairs possible.

Time Complexity per test case: O(N log N)*/

void solve(){
	
	ll n,prod,cnt=0;
    cin>>n;
    
    v arr(n);
    
    unordered_map<ll,ll>mp;
    
    for(int i=0;i<n;i++){
        
        cin>>arr[i];
          
    }
    
      for(ll i=0;i<n;i++){
        
        prod=1;
        
        for(ll j=1;j<=31;j++){
            
            prod*=2;
            
            cnt+=mp[prod-arr[i]];
           
        }
        
        mp[arr[i]]++;
          
    }
    
	cout<<cnt<<nl;	
}

/*Triangle Sum Query

Time-Limit: 4 sec Score: 1.00/100
Difficulty : ****
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

Given a 2d-array of dimension N*M and Q queries. In each query 
three integers x1,y1, L are given, 
you have to find the sum of the triangle ( check the image ) %10^9+7.

Assume that the value of cell outside the grid has value 0.

https://lh5.googleusercontent.com/ytCYRQPvCdVeJJOQ07S47tiA1hxnWyXUHLzyb7z8or3xuUJc8X8Jz-NzcImez2nkk4H0dKQaSWtAoBb4Kicj4YLVAm-w6TQWRx8-tSt0zQmxGKzmjcKWTeNIsnRIPAWddoFq4u6J

Input Format

The first line contains three space-separated integers 
N, M, Q where 1<=N, M<=10^3, 1<=Q<=10^6.

Next N lines contains M space-separated integers (-1e9<=Aij<=1e9).

Next Q lines contains three space separated integers 
x1, y1, L where 1<=x1<=N, 1<=y1<=M, 1<=L<=1000.


Output Format

For each query print the sum of the triangle.


Sample Input 1

5 5 5
-1 2 3 -4 2
0 0 0 0 4
1 2 4 3 5
-1 -5 -2 3 4
0 -3 -5 3 -6
1 1 2
1 2 3
2 3 3
4 4 4
2 3 2

Sample Output 1

1000000006
2
5
10
5*/



/*approach*/
/*We need to find the sum of all the values in the triangular region.
 We already know how to do that 
if the shape was of rectangles. 
So lets try to break this problem too into smaller rectangles and triangles.


In this approach, we are calculating the triangular summation using
 prefix sum techniques. Specifically, 
we are first calculating the rectangular prefix sum rect, which is
 the cumulative sum of the elements of 
the 2D array arr up to that point. Then, we are using the rectangular 
prefix sum to calculate the triangular 
prefix sum tri, which is the cumulative sum of the elements of the 2D 
array arr within the lower left triangle.

To calculate the triangular prefix sum tri, we start by initializing
 tri[0][0] = arr[0][0]. Then, for each 
subsequent row i and column j, we calculate tri[i][j] as follows

tri[i][j]=rect[i][j]−rect[i][j−1]+tri[i−1][j−1]Here, rect[i][j]−rect[i][j−1]

 gives us the sum of the elements in the rectangular submatrix from 
 (0, j-1) to (i, j), and tri[i−1][j−1]
 gives us the sum of the elements in the lower left triangle of the submatrix
  from (0, 0) to (i-1, j-1).
  We add these two sums to get the sum of the elements in the lower left 
  triangle of the 
  submatrix from (0, 0) to (i, j).

Once we have calculated the triangular prefix sum tri, we can answer each 
query in constant time. For
 a query with parameters x1, y1, and L, we first find the indices i and j 
 of the top left corner of thesubmatrix with lower left triangle of interest:

i=max(1,x1−L)
j=max(1,y1−L)
Then, we can compute the sum of the elements within the lower left triangle 
of the submatrix from 
(x1, y1) to (x1 - L , y1 - L ) as follows:

ans=tri[x1][y1]−tri[i][j]−(rect[i][y1]−rect[i][y1−L]−rect[x1−L][j]+rect[i][j]).

Here, tri[x1][y1] gives us the sum of the elements in the lower left triangle of the
 submatrix from (0, 0) to (x1, y1), tri[i][j] gives us the sum of the 
 elements in the lower left triangle of the
  submatrix from (0, 0) to (i, j), rect[i][y1] - rect[i][y1 - L] gives us 
 
 the sum of the elements in the rectangular submatrix from (i+1, y1-L+1) 
 to (i, y1), and rect[x1 - L][j]
  gives us the sum of the elements in the rectangular submatrix from
   (x1-L+1, j+1) to (x1, j). We subtract the latter two sums to remove the 
  double-counted elements in the rectangular submatrix. 
  
  Finally, we subtract tri[i][j] from tri[x1][y1] to remove the 
  elements in the lower left triangle 
  of the submatrix from (1, 1) to (i, j), which were subtracted twice.


Check the video solution - 2D Triangular Prefix Sum.


*/

ll arr[N][N];
ll rect[N][N];
ll tri[N][N];


ll add(ll a,ll b){
    
    ll ans=(a+b)%mod;
    if(ans<0) ans+=mod;
    
    return ans;
}

 ll sub(ll a,ll b){
    
    ll ans=(a-b)%mod;
    if(ans<0) ans+=mod;
    
    return ans;
}

void solve(){

ll n,m,q;
cin>>n>>m>>q;


for(ll i=1;i<=n;i++){
    
    for(ll j=1;j<=m;j++){
        
        cin>>arr[i][j];
        
    }
}

for(ll i=1;i<=n;i++){
    
    for(ll j=1;j<=m;j++){
        
        rect[i][j]=(arr[i][j]+rect[i][j-1]+rect[i-1][j]-rect[i-1][j-1])%mod;
        
    tri[i][j]=(rect[i][j]-rect[i][j-1]+tri[i-1][j-1])%mod;    
      
        
    }
}


while(q--){
    
   ll x1,y1,l;
   cin>>x1>>y1>>l;
   
   ll i=max(1ll*0,x1-l);
   ll j=max(1ll*0,y1-l);
   
   ll ans=tri[x1][y1]-tri[i][j]-(rect[i][y1]-rect[i][j]);

   ans=(ans%mod+mod)%mod;
   
   cout<<ans<<nl;
  
}
	
}



/*Multiply Sum Query (unsolved)

Time-Limit: 4 sec Score: 0.00/100
Difficulty : ***
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

Given an array of N integers and Q queries. In each query two integers L, R is given,
 you have to find (A[L] + A[L+1]*2 + A[L+2]*3 + A[L+3]*4...A[R]*(R-L+1)) % 10^9+7.


Input Format

The first line contains two space-separated integers N, Q where 1<=N<=10^6, 
1<=Q<=10^6.

Next line contains N space-separated integers (-1e9<=Ai<=1e9).

Next Q lines contain two space-separated integers L, R where 1<=L<=R<=N.


Output Format
For each query print the value of (A[L] + A[L+1]*2 + A[L+2]*3 + A[L+3]*4..
.A[R]*(R-L+1)) % 10^9+7 in a new line.


Sample Input 1

10 10
12 -23 -123 2345 2345 44 345 -93945 -5353 1
1 5
1 8
1 10
2 2
6 6
4 8
2 9
4 10
3 6
5 9

Sample Output 1

20702
999271828
999223661
999999984
44
999538829
999318004
999506718
11778
999600930*/


/**LR Power Sum Query  (unsolved)

Time-Limit: 4 sec Score: 0.00/100
Difficulty : ***
 Memory: 256 MB Accepted Submissions: 100
Relevant For:201,202,301
Description

Given an array of N integers, Q queries, and an integer K. 
In each query two integers L,
 R is given, you have to find
  (A[L] + A[L+1] * K + A[L+2] * K^2 + …. A[R] * K^(R-L))% 10^9+7.


Input Format

The first line contains three space-separated integers 
N, Q, K where 1<=N<=10^6, 1<=Q<=10^6, 1<=K<=10^9.

Next line contains N space-separated integers (-1e9<=Ai<=1e9).

Next Q lines contain two space-separated integers L, R where 1<=L<=R<=N.


Output Format

For each query print the value of 
(A[L] + A[L+1] * K + A[L+2] * K^2 + …. A[R] * K^(R-L))% 10^9+7 in a new line.


Sample Input 1

10 10 234565
12 -23 -123 2345 2345 44 345 -93945 -5353 1
1 5
1 8
1 10
2 2
6 6
4 8
2 9
4 10
3 6
5 9

Sample Output 1

644011223
645979052
534876628
999999984
44
725883751
503173837
859246404
845338365
605774687  */











