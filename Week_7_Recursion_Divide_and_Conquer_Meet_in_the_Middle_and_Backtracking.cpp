
all 11 questions of backtracking is important

/*All Permutations

Time-Limit: 1 sec Score: 100.00/100
Difficulty : *
 Memory: 256 MB Accepted Submissions: 100
Description

Given an array of numbers, that might contain duplicates, print all
 possible unique permutations in lexicographically increasing order.


Input Format

The first line of input contains n - the size of the array.
The second line contains n space-separated integers denoting the 
elements of the array - a1, a2, …, an.


Output Format

Print all permutations in lexicographically increasing order. 
See the sample output for more clarity.


Constraints

1 ≤ n ≤ 8
0 ≤ ai ≤ 109


Sample Input 1

3
1 1 1

Sample Output 1

1 1 1

Sample Input 2

3
1 2 1

Sample Output 2

1 1 2
1 2 1
2 1 1

Sample Input 3

3
2 1 3

Sample Output 3

1 2 3
1 3 2
2 1 3
2 3 1
3 1 2
3 2 1*/


ll n;
// vector<ll>vec(10000);

vector<ll>current_perm;
multiset<ll>available;

bool is_valid(ll x){
    
 for(auto it :current_perm){
     
     if(x==it)return 0;
 }
    
   return 1; 
    
}

void rec(ll level){
    // base case
    
    
    if(level==n){
        
        for(auto it:current_perm){
            
            cout<<it<<" ";
        }
        cout<<nl;
        return;
    }
    
    
    //choice
    
    set<ll>st(available.begin(),available.end());
    
    for(auto num:st){
        
        current_perm.push_back(num);
        available.erase(available.find(num));
        rec(level+1);
        available.insert(num);
        current_perm.pop_back();
        
    }   
}

void solve(){

cin>>n;

ll x;
for(ll i=0;i<n;i++){
    
    cin>>x;
    available.insert(x);
}

rec(0);	
}

/*Kth Permutation - easy version

Time-Limit: 1 sec Score: 100.00/100
Difficulty : *
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

For the given n, consider the array A = {1, 2, …, n}. There 
exist n! unique permutations of the array. When we list all
 these n! permutations in lexicographically order, your task
 is to find kth permutation in that list.


Input Format

The first line contains two space-separated integers n and k.


Output Format

Print n space-separated integers, denoting the kth permutation.


Constraints

1 ≤ n ≤ 9
1 ≤ k ≤ n!


Sample Input 1

3 4

Sample Output 1

2 3 1

Sample Input 2

4 9

Sample Output 2

2 3 1 4

Note

Explanation 1: All 9 permutations in lexicographic order are

1 2 3
1 3 2
2 1 3
2 3 1
3 1 2
3 2 1
The 4th one is {2, 3, 1}.*/


ll n,k;
vector<ll>arr(100100);
void solve(){

cin>>n>>k;

arr.resize(n);


for(ll i=0;i<n;i++){
    
    arr[i]=i+1;
    
}

while(k>1){
    
    next_permutation(arr.begin(),arr.end());
    k--;
}

for(auto it:arr){
    
    cout<<it<<" ";
}

cout<<nl;
	
	
}

//editorial code 1
void func(int k, vector<int> &arr)
{
    int n = (int)arr.size();
    k--;
    vector<int> ans;
    int fact = 1;
    for (int i = 1; i < n; i++)
    {
        fact = i * fact;
    }
    while (1)
    {
        ans.push_back(arr[k / fact]);
        arr.erase(arr.begin() + k / fact);
        if ((int)arr.size() == 0)
            break;
        k %= fact;
        fact /= (int)arr.size();
    }
    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout << "\n";
}

void solve()
{
    int n, k;
    cin >> n >> k;
    if (n <= 13)
    {
        vector<int> arr;
        for (int i = 1; i <= n; i++)
        {
            arr.push_back(i);
        }
        func(k, arr);
    }
    else
    {
        vector<int> arr;
        for (int i = 1; i < n - 12; i++)
        {
            cout << i << " ";
        }
        for (int i = n - 12; i <= n; i++)
        {
            arr.push_back(i);
        }
        func(k, arr);
    }
}

signed main()
{
    IOS;
    solve();
    return 0;
}
//Solution 2 //// editorial code 2

const int N = 100010;

int inf = 1e9;
int mod = 1e9 + 7;

signed main()
{
    // freopen("IN", "r", stdin);
    // freopen("OUT", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        nums[i] = i + 1;
    }

    for (int i = 0; i < k - 1; i++)
    {
        next_permutation(nums.begin(), nums.end());
    }

    for (int u : nums)
    {
        cout << u << " ";
    }
    cout << "\n";

    return 0;
}

/*Queens On Chessboard

Time-Limit: 1 sec Score: 100.00/100
Difficulty : **
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

Your task is to place eight queens on a chessboard so that no two 
queens are attacking each other. As an additional challenge, each 
square is either free or reserved, and you can only place queens on
 the free squares. However, the reserved squares do not prevent 
 queens from attacking each other.

How many possible ways are there to place the queens?


Input Format

The input has eight lines, and each of them has eight characters.
 Each square is either free (.) or reserved (*).


Output Format

Print one integer: the number of ways you can place the queens.


Sample Input 1

........
........
..*.....
........
........
.....**.
...*....
........

Sample Output 1

65*/


ll n;
// vector<ll>vec(10000);
vector<ll>queen;
vector<pair<ll,ll>>block;

bool is_valid(ll row,ll col){
    
    ll pc;
    for(auto it:block){
        
      if(it.f==row&&it.s==col)return 0;  
        
    }
    for(ll pr=0;pr<queen.size();pr++){
        
        pc=queen[pr];
        
        if(col==pc)return 0;
        
      if(abs(col-pc)==abs(row-pr))return 0;
      
        
    }
    
    return 1;  
    
}

void display(){
    
    ll pos_queen=-1;
    for(ll i=0;i<n;i++){
        
        if(i<queen.size()){
            
            pos_queen=queen[i];
        }
         
       for(ll j=0;j<n;j++){
           
           if(j==pos_queen){
               
               cout<<"Q ";
               
           }else{
               cout<<".";
           } 
       } 
       cout<<nl;
    }
    
    cout<<nl<<nl;
}

ll rec(ll level){
    // base case
    
    
    if(level==n){
        
        //display();
        return 1;
    }
   
   
   //choice
   
   ll ans=0;
   for(ll col=0;col<n;col++){
       
       if(is_valid(level,col)){
           
           queen.push_back(col);
           ans+=rec(level+1);
           queen.pop_back(); 
       }  
   }
   return ans;
    
}
void solve(){
n=8;


string str;
for(int i=0;i<n;i++){
    cin>>str;
    
    for(int j=0;j<n;j++){
      if(str[j]=='*'){ block.push_back({i,j});}
        
    }
}
cout<<rec(0)<<nl;	
}

/*Kth Permutation - hard version

Time-Limit: 1 sec Score: 75.00/100
Difficulty : ***
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

For the given n, consider the array A = {1, 2, …, n}. There exist
 n! unique permutations of the array. When we list all these n!
  permutations in lexicographically order, your task is to find 
  kth permutation in that list.


Input Format

The first line contains two space-separated integers n and k.


Output Format

Print n space-separated integers, denoting the kth permutation.


Constraints

1 ≤ n ≤ 105
1 ≤ k ≤ min(n!, 109)


Sample Input 1

3 4

Sample Output 1

2 3 1

Sample Input 2

10 3

Sample Output 2

1 2 3 4 5 6 7 9 8 10*/
void func(int k, vector<int> &arr)
{
    int n = (int)arr.size();
    k--;
    vector<int> ans;
    int fact = 1;
    for (int i = 1; i < n; i++)
    {
        fact = i * fact;
    }
    while (1)
    {
        ans.push_back(arr[k / fact]);
        arr.erase(arr.begin() + k / fact);
        if ((int)arr.size() == 0)
            break;
        k %= fact;
        fact /= (int)arr.size();
    }
    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout << "\n";
}

void solve()
{
    int n, k;
    cin >> n >> k;
    if (n <= 13)
    {
        vector<int> arr;
        for (int i = 1; i <= n; i++)
        {
            arr.push_back(i);
        }
        func(k, arr);
    }
    else
    {
        vector<int> arr;
        for (int i = 1; i < n - 12; i++)
        {
            cout << i << " ";
        }
        for (int i = n - 12; i <= n; i++)
        {
            arr.push_back(i);
        }
        func(k, arr);
    }
}

/*N-Queens Revisited

Time-Limit: 3 sec Score: 1.00/100
Difficulty : **
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

An S-Queen is a chess piece that combines the power of a knight and a queen. 
Find the number of ways to place N S-Queens on N x N chessboard.



Input Format

The input contains only single integer N denoting the side of the chessboard. 


Output Format

Print the number of ways to place N S-Queens on the N x N chessboard.


Constraints

2 ≤ N ≤ 14


Sample Input 1

3

Sample Output 1

0

Sample Input 2

10

Sample Output 2

4*/

int checker(int x, int y) {
  for (int i = 0; i < x; i++) {
    if (v[i] == y || (v[i] + i) == (x + y) || (v[i] - i) == (y - x)) return 0;
  }
  if ((x - 1) >= 0) {
    if (v[x - 1] == y - 2 || v[x - 1] == y + 2) return 0;
  }
  if ((x - 2) >= 0) {
    if (v[x - 2] == y - 1 || v[x - 2] == y + 1) return 0;
  }
  return 1;
}

void back_tracking(int level) {
  if (level == n) {
    ans++;
    return;
  }
  for (int i = 0; i < n; i++) {
    if (checker(level, i)) {
      v.push_back(i);
      back_tracking(level + 1);
      v.pop_back();
    }
  }
}

void solve() {
  cin >> n;
  back_tracking(0);
  cout << ans << "\n";
}

/*Generate Balanced Parenthesis - easy version

Time-Limit: 1 sec Score: 75.00/100
Difficulty : **
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

You have given a positive even integer n. Your task is to print all
 balanced parenthesis of length n in lexicographic order 
 (https://en.wikipedia.org/wiki/Lexicographic_order). 

Balanced parentheses mean that each opening symbol has a
 corresponding closing symbol and the pairs of parentheses 
 are properly nested.


Input Format

The only line of input contains a number n.


Output Format

Print all balanced parenthesis of length n in lexicographic order.


Constraints

2 ≤ n ≤ 24
It is guaranteed that n is even.


Sample Input 1

2

Sample Output 1

()

Sample Input 2

4

Sample Output 2

(())
()()*/

void valid_paranthesis(ll open,ll close,string str, ll max){
	
	if(str.length()==max*2){
		
		cout<<str<<nl;
		return;
	}
	
	
	if(open<max){
		
		valid_paranthesis(open+1,close,str+"(",max);
	}
	
	if(close<open){
		
		valid_paranthesis(open,close+1,str+")",max);
	}
	
	
}



void solve(){
	
	ll n;
	cin>>n;
	
	valid_paranthesis(0,0,"",n/2);
	
	
}

/*Generate Balanced Parenthesis - medium version

Time-Limit: 1 sec Score: 1.00/100
Difficulty : *
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

You have given two positive integers n and k. Your task
 is to print all balanced parenthesis of length n in 
 lexicographic order 
 (https://en.wikipedia.org/wiki/Lexicographic_order)
  with depth exactly k. 

Balanced parentheses mean that each opening symbol has 
a corresponding closing symbol and the pairs of parentheses 
are properly nested.

Note:

depth("") = 0.
depth('(' + A + ')) = depth(A) + 1, where A is a balanced
 paranthesis sequence.
depth(A + B) = max(depth(A), depth(B)), where A and B are
 both balanced paranthesis sequence.
depth("(") = depth(")") = 0

Input Format

The only line of input contains two numbers number n and k.


Output Format

Print all balanced parenthesis of length n with depth k in lexicographic order.


Constraints

2 ≤ n ≤ 24
1 ≤ k ≤ n / 2
It is guaranteed that n is an even number.


Sample Input 1

6 2

Sample Output 1

(()())
(())()
()(())

Sample Input 2

4 2

Sample Output 2

(())*/

#define ll long long int
#define LD long double

const int N = 100010;

int inf = 1e9;
int mod = 1e9 + 7;

string ans = "";

void dfs(int curLen, int totalLen, int openCnt, int depth, int k) {
    if(curLen == totalLen) {
        assert(openCnt == 1);
        ans += ")";
        if(depth == k) cout << ans << "\n";
        ans.pop_back();
        return;
    }

    if(!openCnt) {
        ans += "(";
        dfs(curLen + 1, totalLen, openCnt + 1, max(depth, openCnt + 1), k);
        ans.pop_back();
    }
    else {
        int remLen = totalLen - curLen + 1;
        if(remLen > openCnt && openCnt < k) {
            ans += "(";
            dfs(curLen + 1, totalLen, openCnt + 1, max(depth, openCnt + 1), k);
            ans.pop_back();
        }
        ans += ")";
        dfs(curLen + 1, totalLen, openCnt - 1, max(depth, openCnt - 1), k);
        ans.pop_back();
    }
}

signed main()
{
    //freopen("IN", "r", stdin);
    //freopen("OUT", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, k;
    cin >> n >> k;

    dfs(1, n, 0, 0, k);

    return 0;
}

/*Prime Palindromes (unsolved)

Time-Limit: 5 sec Score: 0/100
Difficulty : **
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description 

A number which is both a prime number as well as palindrome 
is called a Prime Palindrome. 151 is a prime as well as a 
palindrome, hence 151 is a prime palindrome.Your task is to find 
the count of Prime Palindromes belonging to the given range [a, b].


Input Format

The only line of input contains two space-separated numbers: a and b.


Output Format

Print the count to Prime Palindromes in-between the range [a, b].


Constraints

2 ≤ a ≤ b ≤ 109


Sample Input 1

5 500

Sample Output 1

12*/

/*Target Subsets

Time-Limit: 3 sec Score: 1.00/100
Difficulty : ***
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

You have given an array of length N, and a number X. 
Find the number of subsets with the sum of elements less than
 equal to X.

Note:

The sum of elements in an empty subset is 0.
The set may contain duplicates elements.

Input Format

The first line of input contains T - the number of test cases.
The first line of each test case contains two space-separated 
numbers N and X.
The second line of each test case contains N space-separated 
integers A1, A2, ..., AN.  


Output Format

Print the number of subsets with a sum less than equal to X 
in a new line for each test case.


Constraints

1 ≤ T ≤ 5
1 ≤ N ≤ 35
0 ≤ Ai ≤ 104
0 ≤ X ≤ 106


Sample Input 1

2
2 1
1 2
3 8
2 2 6

Sample Output 1

2
7

Note

Explanation 1:
The subsets are {}, {1}, {2}, {1, 2}. The number of subsets with sum ≤ 1 is 2.

Explanation 2:
The subsets are {}, {2}, {2}, {6}, {2, 2}, {2, 6}, {2, 6}, 
{2, 2, 6} The number of subsets with sum ≤ 8 is 7.*/

ll n,x;
vector<ll> arr;

vector<ll> generate(vector<ll>&vec){
    ll size = vec.size();
    vector<ll> res;

    for(int mask=0;mask < (1<<size);mask++){
        ll sum = 0;
        for(int i=0;i<size;i++){
            if((mask >> i) & 1){
                sum += vec[i];
            }
        }
        res.push_back(sum);
    }

    sort(res.begin(),res.end());
    return res;
}

void solve(){
    cin>>n>>x;

    arr.resize(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    vector<ll> subsets[2];

    for(int i=0;i<n;i++){
        subsets[i%2].push_back(arr[i]);
    }

    auto subset_1 = generate(subsets[0]);
    auto subset_2 = generate(subsets[1]);

    ll cnt = 0;

    for(auto it : subset_1){
        cnt += upper_bound(subset_2.begin(),subset_2.end(),x-it) - subset_2.begin();
    }

    cout<<cnt<<"\n";
    subsets[0].clear();
    subsets[1].clear();
}


/*Four Values

Time-Limit: 1 sec Score: 1.00/100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

You are given an array of n integers, and your task is to 
find four values (at distinct positions) whose sum is x.


Input Format

The first input line has two integers n and x: the array size 
and the target sum.
The second line has n integers a1, a2, …,an: the array values.


Output Format

Print 'YES' if such four values exist, otherwise 'NO'.


Constraints

1 ≤ n ≤ 1000
1 ≤ x, ai ≤ 109


Sample Input 1

8 15
3 2 5 8 1 3 2 3

Sample Output 1

YES

Note

Four values are {2, 8, 3, 2}.*/

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, x; 
    cin >> n >> x;

    if(n < 4) {
        cout << "NO\n";
        return 0;
    }

    int a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    map<int,pair<int,int>> M;
    M[a[0] + a[1]] = {0, 1};

    for(int i = 2; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            int cur = a[i] + a[j];
            if(M.find(x - cur) != M.end()) {
                cout << "YES\n";
               
                return 0;
            }
        }
        for(int j = 0; j < i; j++) {
            int cur = a[j] + a[i];
            M[cur] = {j, i};
        }
    }

    cout << "NO\n";

    return 0;
}

/*Modulo Subsequences

Time-Limit: 2 sec Score: 1.00/100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

You are given an array a consisting of n integers, and 
additionally an integer m. You have to choose some sequence 
of indices b1,b2,...,bk (≤b1<b2...<bk≤n) in such a way that the value 
of (a[b1] + a[b2] + ... + a[bk]) mod m is maximized. The chosen 
sequence can be empty.

Print the maximum possible value of (a[b1] + a[b2] + ... + a[bk]) mod m.


Input Format

The first line contains two integers n and m (1≤n≤35, 1≤m≤109).
The second line contains n integers a1, a2, ..., an (1≤ai≤109).


Output Format

Print the maximum possible value of (a[b1] + a[b2] + ... + a[bk]) mod m.


Sample Input 1

4 4
5 2 4 1

Sample Output 1

3

Note

You can choose a sequence b={1,2}, so the sum (5 + 2) is equal to 7 
(and that's 3 after taking it modulo 4).*/


int main() 
{ 
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> a(n);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    if (n == 1) {
        cout << a[0] % m << '\n';
        return 0;
    }
    int mid = ((n + 1) / 2);
    vector<int> sums;
    for (int conf = 0; conf < (1 << mid); ++conf) {
        int sum = 0;
        for (int i = 0; i < mid; ++i) {
            if ((conf & (1 << i)) != 0) {
                sum = (sum + a[i]) % m;
            }
        }
        sums.push_back(sum);
    }
    sort(sums.begin(), sums.end());
    int ans = 0;
    for (int64_t conf = 0; conf < (1LL << n); conf += 1LL << mid) {
        int sum = 0;
        for (int i = mid; i < n; ++i) {
            if ((conf & (1LL << i)) != 0) {
                sum = (sum + a[i]) % m;
            }
        }
        int need = (m - 1 - sum + m) % m;
        int pos = upper_bound(sums.begin(), sums.end(), need) - sums.begin() - 1;
        if (pos < 0) {
            pos = SZ(sums) - 1;
        }
        ans = max(ans, (sum + sums[pos]) % m);
    }
    cout << ans << '\n';
}


/*Count Inversions

Time-Limit: 2 sec Score: 1.00/100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

You have given an array A of N elements. An Inversion Count 
of the array is defined as the number of pairs (i, j) such 
that Ai > Aj and i < j.
Find the Inversion Count in A.


Input Format

The first line of input contains one integer T (1 ≤ T ≤ 105) —
 the number of test cases. Then T test cases follow.
The first line of each test case contains N (2 ≤ N ≤ 105), the number of elements in an array A.
The second line contains N space-separated integers A1, A2, …, AN, (0 ≤ Ai ≤ 109)
It is guaranteed that the sum of N over all test cases does not exceed 5 x 105.


Output Format

For each test case, print the answer on a new line denoting the Inversion Count.


Sample Input 1

3

4

8 4 2 1

3

3 1 2

6

1 2 3 4 5 5


Sample Output 1

6

2

0


Note

Explanation 1:
Inversion Pairs are (8, 4), (8, 2), (8, 1), (4, 2), (4, 1), (2, 1).

Explanation 2:
Inversion Pairs are (3, 1), (3, 2).

Explanation 3:
There are no Inversion Pairs. And hence, 0 Inversion Count.*/

const int N = 100010;



int inf = 1e9;

int mod = 1e9 + 7;



long long solve(vector<int> &A, int l, int r) {

    if(l > r) return 0;

    if(l == r) return 0;

    if(r - l == 1) {

        if(A[r] < A[l]) {

            swap(A[r], A[l]);

            return 1;

        }

        return 0;

    }



    int mid = (l + r) / 2;



    long long ans = solve(A, l, mid) + solve(A, mid + 1, r);



    int ptr = mid + 1;

    for(int i = l; i <= mid; i++) {

        while(ptr <= r && A[ptr] < A[i])

            ptr++;

        ans += 1LL * (ptr - mid - 1);

    }

    vector<int> temp;

    for(int i = l; i <= r; i++)

        temp.push_back(A[i]);

    sort(temp.begin(), temp.end());

    for(int i = l; i <= r; i++)

        A[i] = temp[i - l];

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

        int n; cin >> n;

        vector<int> A(n);

        for(int i = 0; i < n; i++) cin >> A[i];

        cout << solve(A, 0, n - 1) << "\n";

    }

    return 0;

}

/*Bubble Sort Swap Parity⭐

Time-Limit: 2 sec Score: 1.00/100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

You all know the Bubble Sort! The classical sorting algorithm.

In this problem, you have to find the parity of the number of swaps 
that will perform in the standard bubble sort algorithm on the 
given input array.

For more details about Bubble Sort refer
 this: https://en.wikipedia.org/wiki/Bubble_sort


Input Format

The first line of input contains one integer T (1 ≤ T ≤ 105) —
 the number of test cases. Then T test cases follow.
The first line of each test case contains N (2 ≤ N ≤ 105), 
the number of elements in an array A.
The second line contains N space-separated integers A1, A2, ...,
 AN, (0 ≤ Ai ≤ 109).
It is guaranteed that the sum of N does not exceed 5 x 105.


Output Format

For each test case, print the answer on a new line denoting the 
parity of number swaps in the Bubble Sort.


Sample Input 1

3

4

8 4 2 1

3

2 1 3

6

1 2 3 4 5 5


Sample Output 1

0

1

0


Note

Explanation 1:

First Iteration	4 2 1 8	3 swaps
Second Iteration	 2 1 4 8 	2 swaps
Third Iteration 	1 2 4 8 	1 swap
Total Swaps: 6, so the parity is 0.

 

Explanation 2:

First Iteration	1 2 3	1 swap
Total Swaps: 1, so the parity is 1.

 

Explanation 3:

The given array is already sorted, so 0 swaps and hence, 0 parity.*/

const int N = 100010;

int inf = 1e9;
int mod = 1e9 + 7;

long long solve(vector<int> &A, int l, int r) {
    if(l > r) return 0;
    if(l == r) return 0;
    if(r - l == 1) {
        if(A[r] < A[l]) {
            swap(A[r], A[l]);
            return 1;
        }
        return 0;
    }

    int mid = (l + r) / 2;

    long long ans = solve(A, l, mid) + solve(A, mid + 1, r);

    int ptr = mid + 1;
    for(int i = l; i <= mid; i++) {
        while(ptr <= r && A[ptr] < A[i])
            ptr++;
        ans += 1LL * (ptr - mid - 1);
    }
    vector<int> temp;
    for(int i = l; i <= r; i++)
        temp.push_back(A[i]);
    sort(temp.begin(), temp.end());
    for(int i = l; i <= r; i++)
        A[i] = temp[i - l];
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
        int n; cin >> n;
        vector<int> A(n);
        for(int i = 0; i < n; i++) cin >> A[i];
        cout << solve(A, 0, n - 1) % 2 << "\n";
    }
    return 0;
}

/*Prime Cycles

Time-Limit: 2 sec Score: 0/100
Difficulty : ***
 Memory: 256 MB Accepted Submissions: 100
Relevant For:201,202
Description

Find the number of Prime Cycles with the permutation of first N
 positive integers. The cycle is called a Prime Cycle if all 
 neighbouring pairs sum up to be a prime. 

The two distinct prime cycles for N = 6 are:

1, 4, 3, 2, 5, 6
1, 6, 5, 2, 3, 4
The permutation of 3, 2, 5, 6, 1, 4 is considered the same 
as the first sequence.


Input Format

The input contains only a single integer N - denoting the
 number of positive integers.


Output Format

Print the number of Prime Cycles that are possible to form 
from first N positive numbers.


Constraints

2 ≤ N ≤ 19


Sample Input 1

2

Sample Output 1

1

Sample Input 2

4

Sample Output 2

2

Sample Input 3

6

Sample Output 3

2

Note

Explanation 1:
One one Prime cycle exists: {1, 2}.

Explanation 2:
Two Prime Cycles are there: {1, 2, 3, 4}, {1, 4, 3, 2}.

Explanation 3:
Two Prime Cycles are there: {1, 4, 3, 2, 5, 6}, 
{1, 6, 5, 2, 3, 4}.*/




/*Count Valid Grid Paths

Time-Limit: 3 sec Score: 0.00/100
Difficulty : ****
 Memory: 256 MB Accepted Submissions: 100
Relevant For:202,301
Description

There are 88418 paths in a 7×7 grid from the upper-left square to 
the lower-left square. Each path corresponds to a 48-character 
description consisting of characters D (down), U (up), L (left) and R (right).

For example, the path corresponds
to the description DRURRRRRDDDLUULDDDLDRRURDDLLLLLURULURRUULDLLDDDD.

You are given a description of a path which may also contain characters ? 
(any direction). Your task is to calculate the number of paths that
 match the description.


Input Format

The only input line has a 48-character string of characters ?, D, U, L and R.


Output Format

Print one integer: the total number of paths.


Sample Input 1

??????R??????U??????????????????????????LD????D?

Sample Output 1

201*/


/*4 Reversals

Time-Limit: 5 sec Score: 0.00/100
Difficulty :**** 
 Memory: 256 MB Accepted Submissions: 100
Relevant For:201,202,203
Description

We are given two equal-length strings S and T. Figure out if we 
can get string T starting from string S and applying 4 substring
 reversal operations.


Input Format

The first line contains an integer TC (number of test cases),

The next line contains a string S. 

The next line contains a string T. 


Output Format

For each test case print “YES” if it is possible to form a square fence,
 else print “NO” without double quotes in a new line.



Constraints

1 ≤ TC ≤ 10^2
1 ≤ |S| ≤ 40
|T|=|S|

Sample Input 1

2
abacde
beacda
abcdef
abdefc

Sample Output 1

YES
YES

Note

TEST CASE 1:

S = prqs

T = psrq

4 transitions are : 

prqs → pqrs
pqrs → srqp
srqp → srpq
srpq → psrq
 

TEST CASE 2:

S = abdec

T = bdaec

4 transitions are : 

abdec → abced
abced → aecbd
aecbd → bcead
bcead → bdaec*/



/*Karatsuba Multiplication

Time-Limit: 15 sec Score: 0.00/100
Difficulty : **
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

You have given two polynomials of degree n as:
A(x) = a0 + a1x + ... + anx^n
B(x) = b0 + b1x + ... + bnx^n

C(x) = A(x) * B(x) = c0 + c1x + ... + cnx^2n

Find c0, c1, c2, ..., c2n.


Input Format

The first line of input contains one integer T (1 ≤ T ≤ 10) —
 the number of test cases. Then T test cases follow.
The first line of each test case contains a single integer n.
The second line of each test case contains n+1 space-separated 
integers a0, a1, ..., an - ai is the coefficient 
of xi in A(x) (0 ≤ ai ≤ 103).
The third line of each test case contains n+1 space-separated 
integers b0, b1, ..., bn - bi is the coefficient 
of xi in B(x) (0 ≤ bi ≤ 103).
It is guaranteed that n + 1 = 2k, 2 ≤ k ≤ 16.


Output Format

For each
test case, print 2n+1 space-separated integers c0, c1, ..., c2n,
 where ci denotes coefficient of xi in C(x)=A(x)*B(x).


Sample Input 1

2

3

5 2 6 8

0 6 1 8

31

1 7 1 5 0 1 0 5 5 3 4 6 9 2 5 4 4 4 7 3 1 6 8 2 4 1 8 6 0 1 2 6

4 1 2 7 8 0 0 7 1 3 3 7 2 6 6 0 8 7 2 7 8 8 6 4 4 4 5 7 9 7 3 5


Sample Output 1

0 30 17 78 70 56 64

4 29 13 42 64 77 44 69 82 52 124 145 187 124 237 237 208 235 278 296
 289 377 393 365 395 465 438 428 534 578 561 582 522 530 569 564 483
  524 604 517 530 474 483 494 401 389 374 383 330 293 292 256 239 217
   179 170 112 111 97 71 53 28 30


Note

Explanation 1:

A(x) = 5 + 2x + 6x^2 + 8x^3
B(x) = 6x + x2 + 8x3

C(x) = A(x) * B(x) = 30x + 17x^2 + 78x^3 + 70x^4 + 56x^5 + 64x^6*/


/*Android Unlock Pattern

Time-Limit: 1 sec Score: 0.00/100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

Android mobile unlock pattern is a grid of 3 x 3 cells,
 where drawing a specific pattern connecting a specific 
 sequence of cells in order will unlock the android mobile.

Given a number n, your task is to find the number of android
 unlock patterns connecting exactly n cells.

Rules of a valid pattern:

Each pattern must connect exactly n cells.
All the cells must be distinct.
If the line connecting two consecutive cells in the pattern passes
 through any other cells, the other cells must have previously
  selected in the pattern. No jumps through the non-selected 
  cell is allowed. The order of cells used matters.

Input Format

The only line of input contains a single integer n.


Output Format

Print answer on a new line.


Constraints

1 ≤ n ≤ 9


Sample Input 1

1

Sample Output 1

9

Sample Input 2

2

Sample Output 2

56*/



/*approach 
Numbered the cells as

1	2	3
4	5	6
7	8	9

Lets try out some examples.

6 - 5 - 4 - 1 - 9 - 2: It's a valid move.
4 - 1 - 9 - 2 : It's a invalid move, because line 1 - 9 
passes through key 5 which had not been selected in the 
pattern. 
4 - 1 - 3 - 6 : It's a invalid move, because line 1 - 3 
passes through key 2 which had not been selected in the pattern.
Can you observe some pattern?


We use DFS to count the number of valid paths from the current 
number (1–9)to the remaining numbers. To optimize, calling DFS 
less than 9 times, we can use the symmetry of the 3 by 3 matrix.
 If we start from 1 or 3 or 7 or 9, the valid paths number should
  be the same. If we start from 2 or 4 or 6 or 8, the valid paths
   number are also the same. Start from 5 is the third case.

One of the invalid cases can be if you want to move your finger from 
1 to 3, without selecting 2, that's not possible. Can you try it on 
your own Android phone?

We need to create a matrix to keep a record of unselected numbers on
 the path between two keys.

Now in DFS, we keep trying to find the next valid cell. What is a valid 
candidate? We need to make sure if the next cell hasn’t been visited, 
and either it’s adjacent to the current cell, or it’s the cell in between
 (recorded as the unselected number on the path)but has been visited.

*/
#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define LD long double

const int N = 100010;

int inf = 1e9;
int mod = 1e9 + 7;

bool visited[10];
int skip[10][10];

int brute_force(int cur, int remLen) {
 // base case : if remaining length done, then return 1 as 1 sequence found.
    if(!remLen) return 1;
    // Mark this cell visited.
    visited[cur] = true;
    int ans = 0;
    // Try to take next cell as i
    for(int i = 1; i <= 9; i++) {
    /* If i is not already taken && either their is no cell to skip 
    	or the cell to skip is already selected.*/
        if(!visited[i] && (!skip[cur][i] || visited[skip[cur][i]])) {
            // try that option.
            ans += brute_force(i, remLen - 1);
        }
    }
    // revert the changes done.
    visited[cur] = false;
    return ans;
}

signed main()
{
    //freopen("IN", "r", stdin);
    //freopen("OUT", "w", stdout);

    memset(visited, false, sizeof(visited));
    memset(skip, 0, sizeof(skip));

    // We are numbering
    // 1 2 3
    // 4 5 6
    // 7 8 9

    // These save the connection that skips a point.
    skip[1][3] = skip[3][1] = 2;
    // to join 1 and 3, 2 needs to be pre-selected, or its invalid move.
    skip[1][7] = skip[7][1] = 4;
    skip[3][9] = skip[9][3] = 6;
    skip[7][9] = skip[9][7] = 8;
   skip[1][9] = skip[9][1] = skip[2][8] = skip[8][2] = skip[3][7] = 
    skip[7][3] =skip[4][6] = skip[6][4] = 5;
    // This you will have to create manually.

    int n;
    cin >> n;

    int ans = 0;
    ans += brute_force(1, n - 1) * 4;   
    //Symmetry as starting from 1 3 7 9 all will be similar
    ans += brute_force(2, n - 1) * 4;   
    //Symmetry as starting from 2 4 6 8 all will be similar
    ans += brute_force(5, n - 1);

    cout << ans << "\n";
    return 0;
}

