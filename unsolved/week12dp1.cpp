// achiver 
 /*Weighted Job Scheduling

    Time-Limit: 1 sec Score: 0.00/100

Difficulty : ***

    Memory: 256 MB Accepted Submissions: 100

Relevant For:

Description

There are n

Jobs you can do. For each Job, you know its starting and ending days and the amount of money you would get as reward. You can only do one Job during a day.

What is the maximum amount of money you can earn?

Input Format

The first input line contains an integer n

: the number of Jobs.

After this, there are n
lines. Each such line has three integers ai, bi, and pi

: the starting day, the ending day, and the reward.

Output Format

Print one integer: the maximum amount of money you can earn.

Constraints

1
≤ n ≤ 2×105
1 ≤ ai ≤ bi ≤ 109
1 ≤ pi ≤ 109

Sample Input 1

4
2 4 4
3 6 6
6 8 2
5 7 3

Sample Output 1

7

1 */



// approach 
/*Let's create a jobs array that zips startTime,endTime,profit
together.
Let's sort our jobs in increasing order of endTime
.
Let dp[i]
denote the maximum profit-taking jobs in jobs[0...i]
such that there is no overlapping time range.
For the current jobs[i]
, we have 2 choices -:


    Don't pick ith

job: dp(i−1)
.

Pick ith
job: We earn profit[i] and the next job must have the endTime<arr[i].startTime to avoid time overlapping.

So we have to find j from [0,i−1] so that arr[j].endTime<arr[i].startTime
.

Since our jobs is already sorted in increasing order by endTime
. So we can binary search to find the job next j, so that arr[j].endTime<arr[i].startTime
.

Then we have choice dp(j)+profit[i]

    .

Choose the choice which leads to maximum profits between the 2 above choices.
Finally, dp(n−1)

    is our result.

Complexity

Time: O(NlogN)
, where N is the number of jobs.
Space: O(N) */

#include<bits/stdc++.h>
using namespace std;

#define int long long
#define F first
#define S second
#define MP make_pair
#define MAXN 200100

using ii = pair<int, int>;

int mod = 1e9+7;

void inout()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}


int n;
vector<pair<ii,int>> Jobs;
int dp[MAXN];

bool cmp(pair<ii, int> &p1, pair<ii, int> &p2)
{
    if (p1.F.F < p2.F.F)
        return true;
    if(p1.F.F == p2.F.F)
        return (p1.F.S < p2.F.S);
    return false;
}

int rec(int level)
{
    if(level<0)
        return 0;
    if(level == 0)
        return Jobs[level].S;

    if(dp[level] != -1)
        return dp[level];

    // dp[level]
    // Either don't take it

    int ans = rec(level-1);

    // Take it

    int lo = 0;
    int hi = level-1;
    int ans_bs = -1;
    int cmp = Jobs[level].F.S;

    while(lo<=hi)
    {
        int mid = (lo+hi)/2;

        if(Jobs[mid].F.F < cmp)
        {
            ans_bs = mid;
            lo = mid+1;
        }
        else
            hi = mid-1;
    }
    
    ans = max(ans, Jobs[level].S + rec(ans_bs));
    
    return dp[level] = ans;
}

void solve()
{
    cin>>n;


    for(int i=0;i<n;i++)
    {
        int a, b, p;
        cin>>a>>b>>p;
        Jobs.push_back(MP(MP(b,a), p));
    }

    // sort(Jobs.begin(), Jobs.end());

    sort(Jobs.begin(), Jobs.end(), cmp);

    memset(dp, -1, sizeof(dp));
    cout<<rec(n-1)<<"\n";
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    inout();
    //int _t; cin>>_t; while(_t--)
        solve();
    return 0;
}



/* Jenga Tower

    Time-Limit: 1 sec Score: 0.00/100

Difficulty :***

    Memory: 256 MB Accepted Submissions: 100

Relevant For:

Description

Your task is to build a tower whose width is 2 and height is n. You have an unlimited supply of blocks whose width and height are integers.

For example, here are some possible solutions for  n = 6:

Given n, how many different towers can you build? Mirrored and rotated towers are counted separately if they look different.

Input Format

The first input line contains an integer t: the number of tests.

After this, there are t lines, and each line contains an integer n: the height of the tower 

go to this img : https://algozenith.s3.ap-south-1.amazonaws.com/content/07-02-22/99_1644200296111.png

Output Format

For each test, print the number of towers modulo 109+7.

Constraints

    1 ≤ t ≤ 106
     
    1 ≤ n ≤ 106

Sample Input 1

3
2
6
1337

Sample Output 1

8
2864
640403945

1
*/

//approach

#include <bits/stdc++.h>
using namespace std;

#define ll int64_t
#define endl '\n'

const int mx = 1e6 + 10, mod = 1e9 + 7;
ll dp[mx][2];
ll rec(int i, bool f) {
    if (i == 1) return 1;
    auto &ans = dp[i][f];
    if (ans != -1)return ans;
    ans = 0;
    if (f)(ans += 4 * rec(i - 1, 1) + rec(i - 1, 0)) %= mod;
    else (ans += 2 * rec(i - 1, 0) + rec(i - 1, 1)) %= mod;
    return ans;
}
void solve() {
    memset(dp, -1, sizeof(dp));
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << (rec(n, 0) + rec(n, 1)) % mod << endl;
    }

}
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);

#ifdef Mastermind_
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#endif
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


// day 5 achiver :

/* Number of Paths in Grid - 3

    Time-Limit: 3 sec Score: 0/100

Difficulty :***

    Memory: 256 MB Accepted Submissions: 100

Relevant For:201,202,301

Description

Given a grid of size n*m, you need to find the number of paths from (1, 1) to (n, m).
 You are allowed to move from (x, y) to (x+1, y) and (x, y) to (x, y+1).
  You cannot move more than K consecutive right moves. The grid may have
   some blocked cells, represented by 1, and it is not allowed to move to
    a blocked cell. An empty cell is represented by 0.

Input Format

The first line of the input contains one integer t - the number of test cases. 
Then t test cases follow.

The first line of each test case contains three space-separated integers 
n, m, k - the size of the grid and the number of right moves you can make.

Each of the following n lines contains m space-separated integers, aij - 
the number at that cell.

Output Format

For each test case, print the number of paths modulo 10^9 + 7.

Constraints

1 ≤ t ≤ 105

1 ≤ n, m, k ≤ 200

0 ≤ aij ≤ 1

It is guaranteed that the sum of nmk over all test cases does not exceed 108.

Sample Input 1

3
3 3 1
0 0 0
0 0 0
0 0 0
3 3 1
0 1 0
0 1 0
0 0 0
2 3 2
0 0 1
0 0 0

Sample Output 1

3
0
2

Note

For the second test case, there is only one path with 2 consecutive right moves,
 so the answer is 0.

For the third test case, the following 2 paths are possible:
 (1,1) → (1,2) → (2,2) → (2,3) and (1,1) → (2,1) → (2,2) → (2,3).

1
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<vector<ll>> grid;
ll n,m;
ll dp[201][201][401];
ll M=1e9+7;
ll t;

ll rec(ll i,ll j,ll k){
    if(i>=n || i<0 || j>=m || j<0 || k<0 || grid[i][j]==1){
        return 0;
    }

    if(i==n-1 && j==m-1)return 1;

    ll &ans = dp[i][j][k];
    if(ans!=-1)return ans%M;

    ans=0;

    return (ans+=rec(i+1,j,t)%M + rec(i,j+1,k-1)%M)%=M;
}

void solve(){
    ll k;
    cin>>n>>m>>k;
    t=k;
    // memset(dp,-1,sizeof(dp));
    grid.assign(n,vector<ll>(m));

    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }
    
    for(ll i=0;i<=n;i++){
        for(ll j=0;j<=m;j++){
            for(int z=0;z<=k;z++){
                dp[i][j][z]=-1;
            }
        }
    }

    cout<<rec(0,0,k)<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    ll t;
    cin>>t;
    while (t--)
    {
        solve();
    }
    

    return 0;
}




/*editorial code 1 :*/

#include <bits/stdc++.h>
using namespace std;

#define int long long

const int mod = 1e9 + 7;

signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, m, k;
        cin >> n >> m >> k;
        bool grid[n+1][m+1] = {};
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                cin >> grid[i][j];
            }
        }
        if(grid[1][1]) {
            cout << "0\n";
            continue;
        }
        int dp[n+1][m+1][k+1];
        memset(dp, 0, sizeof(dp));
        dp[1][1][0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if(!grid[i][j]) {
                    for (int l = 0; l <= k; ++l) {
                        dp[i][j][0] = (dp[i][j][0] + dp[i-1][j][l])%mod;
                        if(l) {
                            dp[i][j][l] = (dp[i][j][l] + dp[i][j-1][l-1])%mod;
                        }
                    }
                }
            }
        }
        int ans = 0;
        for (int l = 0; l <= k; ++l) {
            ans = (ans + dp[n][m][l])%mod;
        }
        cout << ans << "\n";
    }
    return 0;
}

O(N*M) Code:

#include<bits/stdc++.h>
using namespace std;

using lli = long long;

const lli mod = 1e9+7;

lli n,m,k;
lli grid[202][202];
lli previousBlock[202][202];

lli ways(lli i,lli j);

lli prefix[202][202];
lli getPrefix(int row,int col){
    // rowwise prefix sum of the main dp for optimization. 
    if(row<0||col<0)return 0;
    if(prefix[row][col]!=-1){
        return prefix[row][col];
    }
    return prefix[row][col] = (getPrefix(row,col-1)+ways(row,col))%mod;
}

lli dp[202][202];
lli ways(lli i,lli j){// reach (i,j) with a down move
    if(i<0||j<0||grid[i][j]==1)return 0;
    if(i==0&&j==0)return 1;
    else if(i==0)return 0; //  imp so that i-1 doesn't give error (we need some previous row anyways)

    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int cole = j; //  finding a range in the previous row such that 
    int cols = max(j-k-1,previousBlock[i-1][j]); // in the previous row, from which cells can we come to this with a down move.
    // now use the prefix sum to get the value fast.
    return dp[i][j] = (getPrefix(i-1,cole)-getPrefix(i-1,cols)+mod)%mod;
}

void solve(){
    cin>>n>>m>>k;
    for(lli i=0;i<n;i++){
        lli last = -1;
        for(lli j=0;j<m;j++){
            cin>>grid[i][j];
            if(grid[i][j]==1){
                last = j;
            }
            previousBlock[i][j] = last;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            dp[i][j] = prefix[i][j] = -1;
        }
    }
    int cole = m-1;
    int cols = max(m-1-k-1,previousBlock[n-1][m-1]);
    lli ans = (getPrefix(n-1,cole)-getPrefix(n-1,cols)+mod)%mod;
    cout<<ans<<endl;
}    

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    lli _t;cin>>_t;while(_t--)
    solve();
}

1

​




// approach 

/*The cell (i, j) can only be reached from the cells (i-1, j) and (i, j-1).
 Consider both the cases for right and down moves separately.


When cell (i, j) is reached from (i-1, j), the count of consecutive right 
moves becomes zero and when the cell(i, j) is reached from (i, j-1), 
the count of consecutive right moves becomes one more than the count 
of consecutive right moves for (i, j-1).

Find the number of paths from (1, 1) to (i, j) using the cells (i-1, j)
 and (i, j-1). Define dp[i][j][l] which denotes the number of paths to 
 reach (i, j) with l consecutive right moves. The number of paths for 
 arriving at an unblocked cell (i, j) can be found separately for right
  and down moves. When cell (i, j) is reached from cell (i-1, j),
   dp[i][j][0] += dp[i-1][j][l] where 0 ≤ l ≤ k. When cell (i, j) is
    reached from cell (i, j-1), dp[i][j][l] += dp[i][j-1][l-1] where 1 ≤ l ≤ k.
     The base case would be at cell (1, 1), there is only one way to reach it.
      Since at most k consecutive right moves can be there, the final answer 
      would be, Σdp[n][m][l] from 0 ≤ l ≤ k.

Time Complexity per test case: O(n*m*k)

Another approach is to use optimization of prefix sum of previous rows:

DP(row, col) → number of ways to reach the (row, col) such that the 
last move down moved.

This will be like a sum of K cells of the previous row. Look into 
the code for more details. */



/* The Witcher II

    Time-Limit: 2 sec Score: 0/100

Difficulty : ***

    Memory: 256 MB Accepted Submissions: 100

Relevant For:

Description

Gerald of Rivia also known as The Witcher wants to reach the end of the dungeon.
 The dungeon consists of n×m
rooms laid out in a 2D

grid. Gerald was initially positioned in the top-left room and must fight 
his way through, to the bottom-right room of the dungeon, where the exit is located.

Gerald has an initial health point represented by a positive integer. 
If at any point his health point drops to 0

or below, he dies immediately.

Some of the rooms are guarded by demons (represented by negative integers),
 so Gerald loses health upon entering these rooms; other rooms are either 
 empty (represented as 0

) or contain magic orbs that increase Gerald's health 
(represented by positive integers).

To reach the exit as quickly as possible, Gerald decides to move only 
rightward or downward in each step.

Return Gerald's minimum initial health so that he can exit the dungeon.

Note that any room can contain threats or power-ups, even the
 first room Gerald enters and the bottom-right room where the exit is located.

Input Format

First-line contains T
- the number of test cases.
First-line of each test case contains 2 integers n and m.
Each of the next n lines of each test case contains m integers, 
denoting the values of n×m

dungeon's rooms.

Output Format

For each test case, output Gerald's minimum initial health so 
that he can exit the dungeon.

Constraints

1≤T≤100

1≤n≤200
1≤m≤200
−1000≤dungeon[i][j]≤1000

Sample Input 1

2
3 3
-2 -3 3
-5 -10 1
10 30 -5
1 1
1

Sample Output 1

7
1

Note

For test 1: The initial health of Gerald must be at least 7 if he 
follows the optimal path: Right-> Right -> Down -> Down.

1

​*/

#include<bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<int>> grid;
vector<vector<int>> dp;

bool check(int x, int y){
    if(x>=0 && x<n && y>=0 && y<m){
        return true;
    }
    return false;
}

int rec(int i, int j){
    if(i == n-1 && j==m-1){
        if(grid[i][j] < 0){
            return abs(grid[i][j]);
        }
        return 0;
    }
    
    if(dp[i][j] != 1e9){
        return dp[i][j];
    }
    
    int ans = 1e9;
    if(check(i+1, j)){
        ans = min(ans, rec(i+1, j));
    }
    if(check(i, j+1)){
        ans = min(ans, rec(i, j+1));
    }
    ans -= grid[i][j];
    if(ans < 0){
        ans = 0;
    }
    return dp[i][j] = ans;
}

void solve(){
    cin>>n>>m;
    grid.clear();
    grid.resize(n, vector<int>(m));
    dp.clear();
    dp.assign(n+1, vector<int>(m+1, 1e9));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }
    
    cout<<rec(0, 0)+1<<"\n";
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    int t;cin>>t;while(t--)
        solve();
}


//approach and editorial code :
/*

Let dp[i][j] be the minimum hp we need to reach the exit if we start from point (i,j)

. Let us consider the following example:

-2 -3 +3
-5 -10 +1
+10 +30 -5

Let us add the bottom dummy row and right dummy column to handle border cases more easily. We fill it with infinities, except two ones - neighbors of the exit.

How we can evaluate dp[i][j]
? We need to look at two cells: dp[i+1][j] and dp[i][j+1] and evaluate two possible candidates: dp[i+1][j]−dungeon[i][j] and dp[i][j+1]−dungeon[i][j]

.

If at least one of these two numbers is negative, it means that we can survive just with 1
hp: (look at number +30 in our table for example)
If both these numbers are positive, we need to take the minimum of them, see for example number −10 in our table: to survive we need either 5−−10=15 if we go right and 1−−10=11 if we go down, of course, we choose 11.
This conditions can be written in one a bit ugly line: dp[i][j]=max(min(dp[i+1][j],dp[i][j+1])−dungeon[i][j],1).
Finally, why do we put 1 to two neighbors of the exit? To make this formula valid for exit cell: if we have a negative number like −5 in this cell, we need 6 hp to survive, if we have a non-negative number in this cell, we need 1 hp

to survive.

7 5 2 inf
6 11 5 inf
1 1 6 1
inf inf 1 #

Complexity: both time and space is O(m∗n)

.
Binary Search solution :

Binary search to choose a initHealth
of the Gerald which can survive and reach the bottom left cell.
Minimum value left=1, maximum value right=(m+n)∗1000+1
 (because in the worst case, value of all cells in the grid is −1000

).

mid = (left + right) / 2.
If isGood(mid) then:
ans = mid
right = mid - 1 // Minimize init health as much as possible
Else:
left = mid + 1 // Increasing init health

To check isGood(initHealth)

    Gerald has an initial health point in cell (0,0)

.
Let dp[r][c]
denote the maximum health we can get and we can reach from the cell (0,0) to cell (r,c)
.
Finally, if we found a path which dp[m−1][n−1]>0

    means the knight can survive successfully which this initHealth.

Time: O(M∗N∗logR)
, where M<=200 is the number of rows, N<=200 is the number of columns, 
R=1000∗(m+n) is the binary search range.
Space: O(M∗N) */

#include <bits/stdc++.h>
using namespace std;

#define ll int64_t
#define endl '\n'


void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> dungeon(n, vector<int>(m)), dp(n + 1, vector<int>(m + 1, 1e9));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)cin >> dungeon[i][j];
    }
    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            if (i == n - 1 && j == m - 1)dp[i][j] = max(1, 1 - dungeon[i][j]);
            else dp[i][j] = max(1, min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j]);
        }
    }
    cout << dp[0][0] << endl;
}
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);

#ifdef Mastermind_
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#endif
    int t = 1;
    // int i = 1;
    cin >> t;
    while (t--) {
        // cout << "Case #" << i << ": ";
        solve();
        // i++;
    }
    return 0;
}


/* Balanced Bracket Sequence

    Time-Limit: 1 sec Score: 0.00/100

Difficulty : **

    Memory: 256 MB Accepted Submissions: 100

Relevant For:

Description

Given a bracket sequence with ‘?’ at some places, you need to find the number of ways you can replace ‘?’ with ‘(‘ or ‘)’ to form a regular bracket sequence. A bracket sequence is called regular if it is possible to obtain the correct arithmetic expression by inserting characters + and 1 into this sequence.

Input Format

The first line of the input contains one integer t - the number of test cases. Then t test cases follow.

The first and only line of each test case contains a string with characters, ‘(‘, ‘)’ and ‘?’.

Output Format

For each test case, print the number of ways to replace ‘?’ with ‘(‘ or ‘)’ to form a balanced bracket sequence mod 10^9+7.

Constraints

1 ≤ t ≤ 105

1 ≤ n ≤ 103 where n is the length of the string.

It is guaranteed that the sum of n2 over all test cases does not exceed 106.

Sample Input 1

5
(??)
??
()()()
???
??????

Sample Output 1

2
1
1
0
5

Note

For the first test case, following strings are possible: ()() and (()).

For the second test case, only one string is possible: ().

For the third test case, only one string is possible: ()()().

For the fourth test case, n is odd hence no string is possible.

1

​*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
const int N = 100010;
int mod = 1e9 + 7;
string s;
//int dp[1010][1010];
vector<vector<int>>dp;

int rec(int l1, int cnt) {
    // base case
    if(cnt<0) return 0;

    if (l1 == s.length()) {
        if (cnt == 0)
            return 1;
        else
            return 0;
    }
    if (dp[l1][cnt] != -1) return dp[l1][cnt];

    int ans = 0;
    if (s[l1] == '(') {
        ans = (rec(l1 + 1, cnt + 1)%mod)%mod;
    } else if (s[l1] == '?') {
        ans = (rec(l1 + 1, cnt + 1)%mod + rec(l1 + 1, cnt - 1)%mod)%mod;
    } else if (s[l1] == ')') {
        ans = (rec(l1 + 1, cnt - 1)%mod)%mod;
    }
    return dp[l1][cnt] = ans;
}

void solve() {
    cin >> s;
    int n=s.length();
    //memset(dp,-1,sizeof(dp));
    dp.assign(n, vector<int>(n, -1));
    cout << rec(0,0) << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int _t;cin>>_t;while(_t--)
    solve();
    return 0;
}

// apporach 
/*At any point, the number of ‘(‘ is always greater than equal to the number of ‘)’
 and total count of ‘(‘ and ‘)’ in the string is equal.

Define dp[i][j] which denotes the number of ways to form a balanced
 bracket sequence such that the prefix sum till i is j. Denote ‘(‘ with 1 and ‘)’ with -1.

For ?, consider both the cases for ‘(‘ and ‘)’. At any point, the 
prefix sum should not be negative. The answer would be dp[n][0] since 
the prefix sum should be 0 at the end of the string.

Time Complexity per test case: O(n2)

#include <bits/stdc++.h>
using namespace std;

#define int long long
const int mod=1e9+7;
int dp[1001][1001];
signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        int n = s.size();
        for(int i=0;i<=n;i++)
            for(int j=0;j<=n;j++)
                dp[i][j]=0;
        dp[0][0] = 1;
        for (int i = 1; i <= n; ++i) {
            if(s[i-1] == '(') {
                for (int j = 1; j < n; ++j) {
                    dp[i][j] += dp[i-1][j-1];
                    dp[i][j]%=mod;
                }
            }
            else if(s[i-1] == ')') {
                for (int j = 0; j < n; ++j) {
                    dp[i][j] += dp[i-1][j+1];
                    dp[i][j]%=mod;
                }
            }
            else {
                for (int j = 1; j < n; ++j) {
                    dp[i][j] += dp[i-1][j-1];
                    dp[i][j]%=mod;
                }
                for (int j = 0; j < n; ++j) {
                    dp[i][j] += dp[i-1][j+1];
                    dp[i][j]%=mod;
                }
            }
        }
        cout << dp[n][0] << "\n";
    }
    return 0;
}
*/



//day 6 standered

 /*Destroy Coloured Gemstones

    Time-Limit: 4 sec Score: 1.00/100

Difficulty : *

    Memory: 256 MB Accepted Submissions: 100

Description

You are given an array of colored gemstones. In one second, you can remove exactly one continuous substring of colored gemstones that is a palindrome. You have to find the minimum number of seconds needed to destroy all the gemstones.

Input Format

The first line of the input contains one integer T - the number of test cases. Then T test cases follow.

The first line of each test case contains one integer N - the length of the array. 

The second line of each test case contains N space-separated integers.

Output Format

For each test case, print the minimum number of seconds needed to destroy all the gemstones.

Constraints

1≤ T ≤ 200

1≤ N ≤ 100

1≤ Ai ≤ N

Sample Input 1

3
4
1 3 3 1
3
2 4 3
11
1 3 2 3 2 4 3 3 4 3 1

Sample Output 1

1
3
2

Note

For the first test case, the given array is a palindrome. You can remove it in one go.

For the second test case, you will have to destroy one gemstone at a time.

For the third test case, first destroy 2 3 2 and then 1 3 4 3 3 4 3 1 as follows: 1 3 [2 3 2] 4 3 3 4 3 1

*/

#include<bits/stdc++.h>
using namespace std;
using ll=long long;

#define int long long
#define udit main
#define endl '\n'
#define all(o) (o).begin(),(o).end()
#define allr(o) (o).rbegin(),(o).rend()
#define PB push_back
using state=pair<int,int>;
#define F first
#define S second
#define INF 1000000000LL
#define MP make_pair

int binexp(int a,int b,int mod)
{
    int ans=1;

    while(b)
    {
        if(b&1)
        {
            ans=(ans*a)%mod;
        }
        a=(a*a)%mod;
        b>>=1;
    }

    return ans;
}

int n;
vector<int>v;
vector<vector<int>>dp;

int rec(int l,int r)
{
    if(l>r) return 0;

    if(l==r) return 1;

    if(dp[l][r]!=-1) return dp[l][r];

    int ans=1+rec(l+1,r);

    if(v[l]==v[l+1])
    {
        ans=min(ans,1+rec(l+2,r));
    }

    for(int k=l+2;k<=r;k++)
    {
        if(v[l]==v[k])
        {
            ans=min(ans,rec(l+1,k-1)+rec(k+1,r));
        }
    }

    return dp[l][r]=ans;
}

void solve()
{
    int i,j;

    cin>>n;
    v.resize(n);

    dp.assign(n+1,vector<int>(n+1,-1));

    for(i=0;i<n;i++) cin>>v[i];

    cout<<rec(0,n-1)<<endl;
    
}

signed udit()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t=1;
    cin>>t;

    while(t--)
    {
        solve();
    }
}



//approach and editorial code 

/*
Define a DP array, DP[X][Y] which denotes the minimum number of seconds 
to destroy the array from X to Y.

A gemstone can either be destroyed individually or as a part of a range. 
When A[i] = A[j], when can say that DP[i][j] = DP[i+1][j-1]. This is because 
the last subarray which you destroy from [i+1, j-1] will be a palindrome but 
i and j gemstones are of the same color. If we include A[i] and A[j] at the 
end positions, it would still be a palindrome.

We can make three cases, destroy the left-most gemstone of [i, j] and reduce
 to the subproblem [i+1,j]. In the second case, the 
 left-most gemstone will match with some gemstone to its right. We iterate 
 through every gemstone with the same color as the left-most (let k be the 
 index of this matching gemstone) and reduce to two subproblems [i+1,k-1] and [k+1,j].
  We make a special case when the first two elements in a range are equal and 
  consider the subproblem [i+2,j].

 

Time Complexity per test case: O(N^3)

#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int dp[505][505];

int main() {
   IOS
   int t;
   cin >> t;
   while (t--) {
       int n;
       cin >> n;
       int a[n+2];
       a[0] = 0; a[n+1] = 0;
       for (int i = 1; i <= n; ++i) {
           cin >> a[i];
       }
       for (int i = 0; i <= n + 4; ++i) {
           for (int j = 0; j <= n + 4; ++j) {
               dp[i][j] = 0;
           }
       }
       for (int l = 1; l <= n; ++l) {
           for (int s = 1, e = l; e <= n; ++s, ++e) {
               if(l == 1) dp[s][e] = 1;
               else {
                   dp[s][e] = 1 + dp[s+1][e];
                   if(a[s] == a[s+1])
                       dp[s][e] = min(dp[s][e], 1 + dp[s+2][e]);
                   for (int k = s + 2; k <= e; ++k) {
                       if(a[s] == a[k])
                           dp[s][e] = min(dp[s][e], dp[s+1][k-1] + dp[k+1][e]);
                   }
               }
           }
       }
       cout << dp[1][n] << "\n";
   }
   return 0;
}

1

*/

 /*Scrambled String

    Time-Limit: 1 sec Score: 0.00/100

Difficulty : ***

    Memory: 256 MB Accepted Submissions: 100

Relevant For:

Description

We can scramble a string s
to get a string t

using the following algorithm:

    If the length of the string is 1

, stop.

If the length of the string is >1
, do the following:
2.1 Split the string into two non-empty substrings at a random index, i.e., if the string is s, divide it to x and y where s=x+y.
2.2 Randomly decide to swap the two substrings or to keep them in the same order. i.e., after this step, s may become s=x+y or s=y+x

.

Apply step 1
recursively on each of the two substrings x and y

    .

Input Format

The first-line contains T
- the number of test cases.
Each test case contains two strings s1 and s2

of the same length.

Output Format

For each test case, output "Yes" if s2
is a scrambled string of s1

, otherwise, output "No", in a newline.

Constraints

1≤T≤100

s1.length==s2.length
1<=s1.length<=40
s1 and s2

consist of lower-case English letters.
Sample Input 1

3
abcde caebd
a a
great rgeat

Sample Output 1

No
Yes
Yes

Note

For test case 3

,
One possible scenario applied on s1 is:

    "great" --> "gr/eat" // divide at random index.
    "gr/eat" --> "gr/eat" // random decision is not to swap the two substrings and keep them in order.
    "gr/eat" --> "g/r / e/at" // apply the same algorithm recursively on both substrings. divide at ranom index each of them.
    "g/r / e/at" --> "r/g / e/at" // random decision was to swap the first substring and to keep the second substring in the same order.
    "r/g / e/at" --> "r/g / e/ a/t" // again apply the algorithm recursively, divide "at" to "a/t".
    "r/g / e/ a/t" --> "r/g / e/ a/t" // random decision is to keep both substrings in the same order.

The algorithm stops now and the result string is "rgeat" which is s2
.
As there is one possible scenario that led s1 to be scrambled to s2

, we ouput "Yes".

1

​*/
// approach
Note -:
/*

For this problem, the expected time complexity is O(N4)
per test case, where N=|s1|.
So, try to reduce trivial O(N5) into O(N4)

time.*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

const int mod = 1e9+7;

string s1,s2;

int dp[45][45][45];

int rec(int l, int r, int i)
{
    int j = i + r - l;
    //cout<<i<<" "<<j<<" "<<l<<" "<<r<<endl;
    //pruning
    if (l > r || i > j) return 0;
    
    //base case
    if ((l == r) && (i == j)) 
    {
        if (s1[l] == s2[i]) return 1;
        return 0;
    }
    
    //cache check;
    auto &ans = dp[l][r][i];
    if (ans != -1)return ans;
    
    
    //transition;
    
    //if(s1.substr(l, r - l + 1) == s2.substr(i, j - i + 1)) return ans=1;
    
    ans=0;
    for(int k = l; k < r; k++)
    {
        ans |= (rec(l, k, i) & rec(k + 1, r, i + k - l + 1));
        
        if(ans) return ans;
        
        ans |= (rec(l, k, j - (k - l)) & rec(k + 1, r, i));
    }
    
    //save and return
    return ans;
}


void solve()
{
    cin>>s1>>s2;
    
    memset(dp,-1,sizeof(dp));
    
    if (rec(0, s1.size() - 1, 0)) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int _t=1;

    cin>>_t;
    
    while(_t--) solve();
    
    return 0;
}

/*editorial code :

#include <bits/stdc++.h>
using namespace std;

#define ll int64_t
#define endl '\n'

int dp[41][41][41];
string s1, s2;
bool rec(int l, int r, int i) {
    int j = i + r - l; // relationship... to reduce DP state.

    // we are trying to match if s1[l...r] is scrable of s2[i...j].
    // pruning
    if (l > r || i > j)return false;
    // basecase .. if single element, check if same.
    if (l == r) {
        if (s1[l] == s2[i])return true;
        return false;
    }
    auto &ans = dp[l][r][i];
    if (ans != -1)return ans;

    ans = 0; // by default we asume false.

    // if the two strings are same, trivially true.
    if (s1.substr(l, r - l + 1) == s2.substr(i, j - i + 1))return ans = 1;


    for (int k = l; k < r; k++) {
        // try to take first [l.. k] and [i...k] and rest part.
        ans |= (rec(l, k, i)&rec(k + 1, r, i + k - l + 1));
        // try to take first [l.. k] and [same length of s1] and rest part.
        ans |= (rec(l, k, j - (k - l + 1) + 1)&rec(k + 1, r, i));
    }
    return ans;
}
void solve() {
    cin >> s1 >> s2;
    memset(dp, -1, sizeof(dp));
    if (rec(0, s1.size() - 1, 0)) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);

#ifdef Mastermind_
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#endif
    int t = 1;
    // int i = 1;
    cin >> t;
    while (t--) {
        // cout << "Case #" << i << ": ";
        solve();
        // i++;
    }
    return 0;
}
*/

/*
 Bugs in code

    Time-Limit: 2 sec Score: 0.00/100

Difficulty : ***

    Memory: 256 MB Accepted Submissions: 100

Relevant For:

Description

There are N people working on a project, where they have to write exactly M lines of code. The i-th person makes Ai bugs in every line of code that he writes. The first person writes X1 lines of code, the second person writes X2 lines of code, and so on, such that X1 + X2 + ….+ Xn = M. You have to find the number of distinct plans (X1, X2,….Xn, where Xi≥0 and sum of Xi = M) which have at most B bugs. Since the answer might be large, print it modulo 109+7.

Input Format

The first line contains four space-separated integers N, M, B.

The second line contains N space-separated integers.

Output Format

Print the number of distinct plans which have exactly B bugs. Since the answer might be large, print it modulo 109+7.

Constraints

1≤ N, M ≤ 500

0≤ B ≤ 500

0≤ Ai ≤ 500

Sample Input 1

2 3 3
1 2

Sample Output 1

1

Sample Input 2

2 3 4
1 2

Sample Output 2

2

Sample Input 3

2 2 4
1 2

Sample Output 3

3

Note

For the first test case, there is only one case i.e.
 when the first programmer writes the whole code because then all 3 
 lines of code will have 3 bugs.

For the second test case, there can be two plans: first programmer 
writes 2 lines and second programmer writes 1 lines(Number of bugs
 would be 4), and first programmer writes 3 lines and second programmer
  does not write any line of code(Number of bugs would be 3 ≤ 4).

For the third test case, there can be three plans: first programmer 
writes 2 lines and second programmer writes 0 lines(Number of bugs 
would be 3 ≤ 4), and first programmer writes 1 line and second programmer 
writes 1 line(Number of bugs would be 3 ≤ 4) and first programmer writes
 0 lines and second programmer writes 2 lines(Number of bugs would be 4 ≤ 4)

*/
#include<bits/stdc++.h>   
using namespace std;
#define ll long long
#define ii pair<ll,ll>
const int mod = 1e9+7;
const int N = 200010;
int n,m,b;
int dp[505][505][505];
int a[505];

int rec(int x, int y, int z){
    if(z>b || y>m){
        return 0;
    }
    if(x==n){
    	if(y==m) return 1;
        return 0;
    }
    
    if(dp[x][y][z]!=-1) return dp[x][y][z];
    
    int ans = (rec(x+1,y,z)%mod + rec(x,y+1,z+a[x])%mod)%mod;
    
    return dp[x][y][z] = ans;
}

void solve(){
    cin>>n>>m>>b;
    for(int i=0; i<n; i++) cin>>a[i];
    memset(dp,-1,sizeof(dp));
    cout<<rec(0,0,0)<<"\n";
}

signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
}


//approach and editorial code :

/*Define DP array, DP[X][Y][Z] where X denotes the number of programmers who have written Y lines of code with Z number of bugs.

 

Using an N*N*N array will result in MLE since array of size 500*500*500 is 400MB. We will only need the previous count of X-1 programmers, so we can make array of size 2*N*N.

For the X-th programmer, there can be two cases: when he does not write any line of code and when he writes one or more lines of code.

The DP transition will be: DP[X][Y][Z] = DP[X-1][Y][Z] + DP[X][Y-1][Z-A[i]].

Time Complexity per test case: O(NMB)

#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long

const int mod = 1e9+7;

int dp[2][501][501];

signed main() {
   IOS
   int t = 1;
   while(t--) {
       int n, m, b;
       cin >> n >> m >> b;
       int a[n];
       for (int i = 0; i < n; ++i) {
           cin >> a[i];
       }
       for (int i = 0; i <= 1; ++i) {
           for (int j = 0; j <= m; ++j) {
               for (int k = 0; k <= b; ++k) {
                   dp[i][j][k]=0;
               }
           }
       }
       dp[0][0][0] = 1;
       for (int i = 1; i <= n; ++i) {
           int p = i & 1;
           for (int j = 0; j <= m; ++j) {
               for (int k = 0; k <= b; ++k) {
                   dp[p][j][k] = dp[p^1][j][k];
                   if(j && k >= a[i-1]) {
                       dp[p][j][k] = (dp[p][j][k] + dp[p][j-1][k-a[i-1]])%mod;
                   }
               }
           }
       }
       int ans = 0;
       for (int i = 0; i <= b; ++i) {
           ans = (ans + dp[n&1][m][i]) % mod;
       }
       cout << ans << "\n";
   }
   return 0;
}

*/


/*
 The Witcher

    Time-Limit: 5 sec Score: 0.00/100

Difficulty :****

    Memory: 256 MB Accepted Submissions: 100

Relevant For:201,202,203

Description

Gerald of Rivia also known as The Witcher, on his journey to find Ciri, faced a dangerous labyrinth.

He's in a tunnel that contains N
different rooms. Each room contains Ai monsters inside it. He starts from room 1. Every time he stays near a room X, he may go in and clear it from monsters, or just leave the room locked and move to the room X+1. However, if he clears a room with K monsters and the next room he clears consists of L monsters, then the greatest common divisor of K and L must be greater than 1

, otherwise, he will die ( awful curse! ).

Formally, let us say that the order of rooms he visited is i1,i2,,...,it
. Then gcd(Aij,Aij+1)>1 for all j<t

. Help him cross all the rooms by clearing the maximum number of rooms.

Input Format

The first line of input contains an integer T

denoting the number of test cases.

The first line of each test case contains one integer N

denoting the number of elements in the sequence.

The second line of each test case contains N
integers where ith integer is a number of monsters in a room Ai

.

Output Format

For each test case, output the maximum number of rooms he could clear. (Gerald should survive.)

Constraints

1≤T≤100

1≤N≤105
1≤Ai≤107

Sample Input 1

3
7
13 2 8 6 3 1 9
6
1 2 2 3 3 1
2
2 3

Sample Output 1

5
2
1

Note

Test case 1. Gerald can clear the monsters in the rooms 2,3,4,5,7
in that order. These rooms consist of 2,8,6,3, and 9 monsters, respectively. You can check that gcd(2,8), gcd(8,6), gcd(6,3) and gcd(3,9), all are greater than 1

.

Test case 2. Gerald can clear the monsters in the rooms numbered 2,3
. Each of these two rooms contains two monsters. And we know that gcd(2,2)=2>1

.

There is one more possible solution: Gerald can clear the monsters in the rooms numbered 4,5
. These rooms contains 3 monsters each, and he can clear these rooms as gcd(3,3)=3>1

.

*/

//alternate one 
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'

int n;
vector<int>arr;

const int N = 10001000;

//array containing least prime factors
vector<int>lpf;


void calc()
{
    lpf.resize(N);
    iota(lpf.begin(),lpf.end(),0);

    for(int i=2;i*i<=N;i++)
    {
        if(lpf[i]==i)
        {
            for(int j=i*i;j<=N;j+=i)
            {
                if(lpf[j]==j)
                {
                    lpf[j] = i;
                }
            }
        }
    }

}


void solver()
{
    cin>>n;arr.clear();arr.resize(n);
    for(int i=0;i<n;i++) cin>>arr[i];

    int ans = 1; vector<int>dp(N,0);
    for(auto x:arr)
    {
        //store all the prime factors
        set<int>pf;

        while(x!=1)
        {
            pf.insert(lpf[x]);
            x/=lpf[x];
        }

        //find previous max length of each prime factor
        int mx = 0;

        for(auto factor:pf)
        {
            ++dp[factor];
            mx = max(mx,dp[factor]);
        }

        //now set all the current factors that their largest subsequence length is mx(last element in which they are present)

        for(auto factor:pf)
        {
            dp[factor] = mx;
        }

        ans = max(ans, mx);
    }

    cout<<ans<<endl;
}


signed main()
{
    IOS 
    calc();
    int t;cin>>t;while(t--)
    solver();
}


// another one 
#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<long long, long long>;
using mii = map<long long, long long>;

long long is_prime[1000001], is_primeRange[1000001];

long long sqrt1(long long n) {
    long long lo = 0, hi = 2 * sqrt(n);
    while (lo < hi) {
        long long x = (lo + hi) / 2;
        if (x * x >= n) {
            hi = x;
        } else {
            lo = x + 1;
        }
    }
    return lo;
}

void sieve(){    //O(NloglogN)
    is_prime[0] = is_prime[1] = 0;
    for(long long i = 2; i <= 1000000; i++){
        is_prime[i] = 1;
    }

    for(long long i = 2; i <= 1000000; i++){
        if(is_prime[i]){
            for(long long j = i*i; j <= 1000000; j += i){
                is_prime[j] = 0;
            }
        }
    }
}

// floor(N/2) + floor(N/3) + floor(N/5) + floor(N/7) + ..... = O(NloglogN);
// floor(N/1) + floor(N/2) + floor(N/3) + floor(N/4) + ..... = O(NlogN);

void rangeSieve(long long l, long long r){

    for(long long i = l; i <= r; i++){
        is_primeRange[i-l] = 1;
    }

    for(long long i = 2; i <= sqrt1(r); i++){
        if(is_prime[i]){
            long long cur = ((l+i-1)/i)*i;
            for(long long j = cur; j <= r; j+=i){
                if(j != i){
                    is_primeRange[j-l] = 0;
                }
            }
        }
    }
}


bool prime(ll x){
    if(x == 1) return 0;
    for(ll i = 2; i*i <= x; i++){
        if(x%i == 0) return 0;
    }
    return 1;
}

vector<ll> divisors(ll x){
    vector<ll> ans;

    for(ll i = 1; i*i <= x; i++){
        if(x%i == 0){
            ans.push_back(i);
            if(i*i != x){
                ans.push_back(x/i);
            }
        }
    }

    return ans;
}

vector<pii> Factors(ll x){
    vector<pii> ans;
    for(ll i = 2; i*i <= x; i++){
        if(x%i == 0){
            ll cnt = 0;
            while(x%i == 0){
                cnt++;
                x /= i;
            }
            ans.push_back({i, cnt});
        }
    }
    if(x > 1) ans.push_back({x, 1});
    return ans;
}


long long gcd(long long a, long long b){
    if(a == 0) return b;
    else return gcd(b%a, a);
}

ll lcm(ll a, ll b){
    return (a*b)/gcd(a,b);
}

ll sp[10000003]; //SMALLEST PRIME FACTOR FOR EVERY NUMBER;
void calcSP(){  //O(NloglogN)
    for(ll i = 1; i <= 10000002; i++){
        sp[i] = i;
    }
    for(ll i = 2; i <= 10000002; i++){
        if(sp[i] == i){
            for(ll j = 2*i; j <= 10000002; j += i){
                if(sp[j] == j){
                    sp[j] = i;
                }
            }
        }
    }
}

/*O(logN)*/
vector<ll> primeFact(ll x){
    vector<ll> ans;
    while(x > 1){
        ans.push_back(sp[x]);
        x /= sp[x];
    }
    return ans;
}

ll phi[1000001];
void calc_phi(){
    for(ll i = 1; i <= 1000000; i++){
        phi[i] = i;
    }
    for(ll i = 2; i <= 1000000; i++){
        if(is_prime[i]){
            for(ll j = i; j <= 1000000; j += i){
                phi[j] -= phi[j]/i;
            }
        }
    }
}

ll mod = 1e9+7;

void solve(){
    ll n;
    cin >> n;

    vector<ll> a(n);
    for(ll i = 0; i < n; i++){
        cin >> a[i];
    }

    vector<ll> dp(1e7+3, 0);
    ll ans = 1;

    for(ll i = 0; i < n; i++){
        set<ll> st;
        ll x = a[i];
        while(x > 1){
            st.insert(sp[x]);
            x /= sp[x];
        }

        ll t = 0;
        for(auto y: st){
            dp[y]++;
        }

        for(auto y: st){
            t = max(t, dp[y]);
            ans = max(ans, dp[y]);
        }

        for(auto y: st){
            dp[y] = t;
        }
    
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    calcSP();

    int tc = 1;
    cin >> tc;


    while(tc--){
        solve();
    }

    return 0;
}

/*
approach and editorial code
We will need to prime-factorize each integer in the array.

We first use a sieve to find the smallest prime factor of all integers in the range [1…107]

.

Pseudo-code for pre-computing smallest prime factors using sieve:

  smallest_prime_factor = [1 for all ints uptil 10^7] # initialize
  for i in [2..10^7]:
    if smallest_prime_factor[i] == 1:
      for j in [i..10^7]:
        smallest_prime_factor[j] = i
        j += i

Pseudo-code for prime-factorization of a number:

  prime_factors = set()
  while number != 1:
    prime_factors.add(smallest_prime_factor[number])
    number /= smallest_prime_factor[number]

Now, we can use dynamic programming to store the maximum possible sub-sequence length that ends at index i
, such that ai contains P

as a prime factor.

Let the prime factors of ai
be p1,p2,p3,...,pK.
For each pj, let’s say the maximum possible sub-sequence length such that the previously selected number had a common prime factor was lj.
We choose the maximum length M equal to max(lj) for (1≤j≤K). We update dp(pj) with the value M

.

While performing updates, we maintain a global maximum - the maximum M

calculated uptil now.

Time Complexity

Pre-computation using sieve: O(X∗log(log(X)))
, where X=107.
Computation of max length sub-sequence: O(N∗log2(Y)), where Y

is the number in the array with maximum no. of prime factors.

#include <bits/stdc++.h>
using namespace std;

#define ll int64_t
#define endl '\n'

const int mx = 1e7;


int lpf[mx + 5];
void sieve() {
    for (int i = 2; i <= mx; i++) {
        if (lpf[i])continue;
        for (int j = 1; j * i <= mx; j++)if (lpf[i * j] == 0)lpf[i * j] = i;
    }
}
void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)cin >> v[i];
    vector<int> dp(1e7 + 1, 0);
    int ans = 1;
    for (auto x : v) {
        set<int> s;
        while (x != 1) {
            int p = lpf[x];
            x /= p;
            s.insert(p);
        }
        int t = 0;
        for (auto p : s)dp[p]++, ans = max(ans, dp[p]), t = max(t, dp[p]);
        for (int p : s)dp[p] = t;
    }
    cout << ans << endl;
}
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);

#ifdef Mastermind_
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#endif
    int t = 1;
    // int i = 1;
    sieve();
    cin >> t;
    while (t--) {
        // cout << "Case #" << i << ": ";
        solve();
        // i++;
    }
    return 0;
}



*/

//Maximum Subarray, using DP
https://medium.com/@monisha.mary.mathew/maximum-subarray-using-dp-d712976d19b7

//day 7 standered

 /*Prime Subsequence

    Time-Limit: 5 sec Score: 0.00/100

Difficulty :***

    Memory: 256 MB Accepted Submissions: 100

Relevant For:

Description

You are given a sequence A of prime numbers. You have to tell the number of subsequences with size at most K and which do not contain any two identical numbers. The empty sequence is good. Since the answer can be large, print it modulo 109 + 7.

Input Format

The first line of the input contains one integer T - the number of test cases. Then T test cases follow.

The first line of each test case contains two space-separated integers N and K - the length of the array and maximum numbers to take in a subsequence.

The second line of each test case contains N space-separated integers.

Output Format

For each test case, print a single integer denoting the number of subsequences with size at most K and which do not contain any two identical numbers on a separate line. Since the answer can be large, print it modulo 109 + 7.

Constraints

1 ≤ T ≤ 100

1 ≤ K ≤ N ≤ 10^5

2 ≤ Ai ≤ 10000, only prime numbers

Sample Input 1

4
5 2
5 5 2 2 3
5 3
5 5 2 2 3
4 2
5 5 5 5
4 4
5 2 3 7

Sample Output 1

14
18
5
16

Note

For the first test case, there is 1 subsequence with length 0, 5 subsequence with length 1 and 8 subsequence with length 2.

For the second test case, there is 1 subsequence with length 0, 5 subsequence with length 1, 8 subsequence with length 2 and 4 subsequence with length 3.

For the third test case, there is 1 subsequence with length 0 and 4 subsequence with length 1.

For the fourth test case, there is 1 subsequence with length 0, 4 subsequence with length 1 and 6 subsequence with length 2, 4 subsequence with length 3 and 1 subsequence with length 4.

1

*/
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define left _left
#define right _right

const ll MOD = 1e9+7;

ll n,k;
vector<ll> a;
vector<vector<ll>> dp;

ll rec(ll i,ll left){
    if(left < 0) return 0;
    if(i == n) return 1;
    if(dp[i][left] != -1) return dp[i][left];

    ll ans = (rec(i+1,left) + (a[i]*rec(i+1,left-1))%MOD)%MOD;

    return dp[i][left] = ans;
}

int main(){
    ll t;
    cin >> t;
    while(t--){
        ll m;
        cin >> m >> k;
        map<ll,ll> f;
        while(m--){
            ll x;
            cin >> x;
            f[x]++;
        }
        a.clear();
        for(auto it : f) a.push_back(it.second);
        n = a.size();
        if(k>n) k=n;
        dp.assign(n,vector<ll>(k+1,-1));
        cout << rec(0,k) << endl;
    }
    return 0;

// apporach and editorial code 

/*The number of distinct primes till 10000 is 1229.

The order of the given array does not matter.

Make a DP array, DP[i][j] which denotes the number of valid
 subsets of size j using array values upto i. The DP transition 
 will be: DP[i][j] = DP[i-1][j] + DP[i-1][j-1] * cnt[i]. Here cnt[i] 
 is the count of integer i in the given array. For a given value of
  i,j DP[i-1][j] considers the valid subsets using array values upto 
  i and the second term denotes picking of the number i which has count, cnt[i].

 

Time Complexity per test case: O(X^2) where X is the number of primes 
till 10000, which is 1229.

#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
const int mod=1e9+7;

int dp[1230][1230];

signed main(){
   IOS
   int t;
   cin >> t;
   while (t--) {
       int n, k;
       cin >> n >> k;
       map<int, int> m;
       for(int i = 0; i < n; ++i){
           int x;
           cin >> x;
           m[x]++;
       }
       vector<int> v;
       for(auto i :m)  {
           v.push_back(i.second);
       }
       memset(dp,0,sizeof(dp));
       for(int i = 0; i < v.size(); ++i){
           dp[i][0] = 1;
       }
       dp[0][1] = v[0];
       for(int i = 1; i < v.size(); ++i){
           for(int j = 1; j <= v.size(); ++j){
               dp[i][j] = (dp[i][j] + dp[i - 1][j])%mod;
               dp[i][j] = (dp[i][j] + (dp[i - 1][j - 1] * v[i]) % mod) % mod;
           }
       }
       int ans[v.size() + 1];
       ans[0] = 1;
       for(int i = 1; i <= v.size(); i++){
           ans[i] = (ans[i - 1] + dp[v.size() - 1][i])%mod;
       }

       if(k <= v.size()){
           cout << ans[k] << "\n";
       }
       else{
           cout << ans[v.size()] << "\n";
       }
   }
   return 0;
}

*/
    
    /* Sky

    Time-Limit: 2 sec Score: 0.00/100

Difficulty : ***

    Memory: 256 MB Accepted Submissions: 100

Relevant For:

Description

You can see N stars in the sky. You know the coordinates and the brightness of the stars. The maximum brightness of any star can be C. If at moment M, a star has brightness S, then at moment M+1, the star will have brightness S+1, if S+1 <= C, otherwise 0. You look at the sky Q times, you want to know the total brightness of the stars lying in the viewed rectangle, with the lower-left corner (X1i, Y1i) and upper right corner (X2i, Y2i) at moment Mi.

Input Format

The first line of the input contains one integer T - the number of test cases. Then T test cases follow.

The first line of each test case contains three space-separated integers N, Q, C - the number of the stars, the number of the views, and the maximum brightness of the stars.

Each of the next N lines contains three space-separated integers, Xi, Yi, Si - the description of each star.

Each of the next Q lines contains M, X1, Y1, X2, Y2 - the moment when you look at the sky and the coordinates of the viewed rectangle. X1≤X2, Y1≤Y2

Output Format

For each query, print the total brightness of the stars lying in the viewed rectangle.

Constraints

1≤ T ≤ 100

1≤ N, Q ≤ 105

0≤ Si ≤ C ≤ 10

1≤ Xi, Yi ≤ 100

1≤ Mi ≤ 109

Sample Input 1

2
3 2 3
1 2 1
1 3 0
2 3 3
1 1 3 3 3
2 1 1 1 4
2 3 5
3 3 2
1 1 4
0 1 1 5 5
2 1 1 2 3
3 1 1 3 3

Sample Output 1

1
5
6
0
6

Note

For the first test case, for the first query, at moment 1, the brightness of all-stars becomes S+1, if S+1 <= C, otherwise 0. From 1≤ X ≤ 3 and 3 ≤ Y ≤ 3, there is only one star at X=1, Y=3 with brightness 0+1 = 1. For the second query, at moment 2, from 1≤ X ≤ 1 and 1 ≤ Y ≤ 4, there are two stars at X=1, Y=2 with brightness 1+2 = 3 and at X=1, Y=3, with brightness 0+2 = 2.

For the second test case, for the first query, at moment 0, from 1≤ X ≤ 5 and 1 ≤ Y ≤ 5, there are two stars at X=3, Y=3 with brightness 2+0 = 2 and at X=1, Y=1, with brightness 4+0 =4.

For the second query, at moment 2, from 1≤ X ≤ 2 and 1 ≤ Y ≤ 3, there is one star1 at X=1, Y=1 with brightness 4+2 = 6, which will be 0. For the third query, at moment 3, from 1≤ X ≤ 3 and 1 ≤ Y ≤ 3, there are two stars at X=3, Y=3 with brightness 2+3 = 5 and at X=1, Y=1, with brightness 4+3 =7, which will be 1.

*/
    
    /*sol 1:
    
    #include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

const int mod = 1e9+7;

void solve()
{
    int n,q,c; cin>>n>>q>>c;
    int dp[101][101][11];
    memset(dp,0,sizeof(dp));
    
    for(int i=0;i<n;i++)
    {
        int a,b,p; cin>>a>>b>>p;
        dp[a][b][p]++;
    }
    
    for(int i=1;i<=100;i++)
    {
        for(int j=1;j<=100;j++)
        {
            for(int k=0;k<11;k++)
            {
                dp[i][j][k]+=dp[i-1][j][k];
                dp[i][j][k]+=dp[i][j-1][k];
                dp[i][j][k]-=dp[i-1][j-1][k];
            }
        }
    }
    
    while(q--)
    {
        int m,x1,x2,y1,y2; cin>>m>>x1>>y1>>x2>>y2;
        
        vector<int> temp(11,0);
        
        for(int j=0;j<11;j++)
        {
            temp[j] += dp[x2][y2][j];
            temp[j] -= dp[x1-1][y2][j];
            temp[j] -= dp[x2][y1-1][j];
            temp[j] += dp[x1-1][y1-1][j];
        }
        
        int ans = 0;
        
        for(int j=0;j<11;j++) ans+= ((j+m)%(c+1))*temp[j];
        
        cout<<ans<<endl;
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int _t=1;

    cin>>_t;
    
    while(_t--) solve();
    
    return 0;
}*/
    
    #include<bits/stdc++.h>
using namespace std;

#define int long long 

int n,q,c; 
map<pair<pair<int,int>,int>,int> mp;  
int dp[110][110][11];
int vis[110][110][11];

int rec(int i,int j,int m){
	if(i == 0 || j==0) return 0 ; 
    
    if(i == 1 && j == 1){
        return mp[{{1,1},m}];
    }
    
    if(vis[i][j][m]) return dp[i][j][m];
    
    int ans = mp[{{i,j},m}];
    
    ans = ans + rec(i-1,j,m) + rec(i,j-1,m) - rec(i-1,j-1,m); 
    
    vis[i][j][m] = 1; 
    
    return dp[i][j][m] = ans; 
}

void solve(){
    mp.clear();
    cin>>n>>q>>c; 
    
    memset(vis,0,sizeof(vis));
    
    for(int i=0;i<n;i++){
        int x,y,s; 
        cin>>x>>y>>s ;

        mp[{{x,y},s}]++;
    }

    for(int i=0;i<=10;i++){
        rec(100,100,i);
    }
    
    while(q--){
        int m,x1,y1,x2,y2;
        cin>>m>>x1>>y1>>x2>>y2;
        
        int ans = 0 ; 
        for(int i=0;i<=10;i++){
            int temp = rec(x2,y2,i) - rec(x1-1,y2,i) - rec(x2,y1-1,i) + rec(x1-1,y1-1,i);

            ans += ((i + m)%(c+1))*temp ; 
        }

        cout<<ans<<endl ;
    }
    
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
    
    /*editorial code and approach  :
    The brightness of a star can be between 0 and C. When a star has brightness S, at the next moment it's brightness becomes 0. This means that we need to take modulo (C+1).

We define DP array, DP[X][Y][S] represents the number of stars with brightness S where X1 ≤ X and Y1 ≤ Y.

We can make the DP array using 2-D prefix sums, DP[X][Y][S] += DP[X-1][Y][S] + DP[X][Y-1][S]  - DP[X-1][Y-1][S] for each brightness S ≤ C. For finding the answer to each query, iterate through all the possible values of brightness.

Time Complexity per test case: (N + Q*C + X*Y*C)

#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long

int dp[101][101][11];

signed main() {
   IOS
   int t;
   cin >> t;
   while(t--) {
       int n, q, c;
       cin >> n >> q >> c;
       for (int p = 0; p <= c; ++p) {
           for (int i = 0; i <= 100; ++i) {
               for (int j = 0; j <= 100; ++j) {
                   dp[i][j][p] = 0;
               }
           }
       }
       for (int i = 1; i <= n; ++i) {
           int x, y, s;
           cin >> x >> y >> s;
           dp[x][y][s]++;
       }
       for (int p = 0; p <= c; ++p) {
           for (int i = 0; i <= 100; ++i) {
               for (int j = 0; j <= 100; ++j) {
                   dp[i][j][p] += dp[i-1][j][p] + dp[i][j-1][p] - dp[i-1][j-1][p];
               }
           }
       }
       while (q--) {
           int t, x1, y1, x2, y2;
           cin >> t >> x1 >> y1 >> x2 >> y2;
           int ans = 0;
           for (int i = 0; i <= c; ++i){
               int cur = (i+t)%(c+1);
               ans += (dp[x2][y2][i] - dp[x1-1][y2][i] - dp[x2][y1-1][i] + dp[x1-1][y1-1][i])*cur;
           }
           cout << ans << "\n";
       }
   }
   return 0;
}

*/
// day 7 achiver :

/* Uncommon Subsequences

    Time-Limit: 5 sec Score: 0.00/100

Difficulty :****

    Memory: 256 MB Accepted Submissions: 100

Relevant For:

Description

Given two strings S
and T, find length of the shortest subsequence in S which is not a subsequence in T. If no such subsequence is possible, return −1

. A subsequence is a sequence that appears in the same relative order, but not necessarily contiguous.

Input Format

First-line contains t
- the number of test cases.
The first line of each test case contains the string S.
The Second-line of each test case contains the string T

.

Output Format

For each test case, output the length of the shortest subsequence in S
which is not a subsequence in T. If no such subsequence is possible, output −1

.

Constraints

1≤t≤100

1≤|S|≤1000
1≤|T|≤1000

Sample Input 1

3
banana 
anbnaanbaan
aaa
a
aba
abaa

Sample Output 1

5
2
-1

Note

for first test, one of the shortest uncommon subsequence is "banna".

*/

//approach and editorial code :

/*We establish the relationship between the sub problems and the problem at hand. Let L(i,j) be the length of the shortest subsequence that is in S[1..i] that is not in T[1..j]. Here we have the following relationship:
L(i,j)=

    If letter S[i]

is nowhere to be found in T[1..j], then L(i,j)=1
.
Otherwise, we have two cases:
2.1. S[i]
is in the shortest subsequence. We find k, the most immediate index in T[1..j] where T[k]==S[i]. Then L(i,j)=1+L(i−1,k−1).
2.2 S[i] is not in the shortest subsequence. Then L(i,j)=L(i−1,j)

    .
    We pick whichever is lower.

Time Complexity : O(N2)

per test case.

#include <bits/stdc++.h>
using namespace std;

#define ll int64_t
#define endl '\n'

string s1, s2;
int n, m;
int dp[1001][1001], pre[1001][1001];
int rec(int i, int j) {
    if (i == -1)return 1e9;
    if (j == -1)return 1;
    auto &ans = dp[i][j];
    if (ans != -1)return ans;
    ans = rec(i - 1, j);
    if (pre[i][j] == -1)ans = 1;
    else ans = min(ans, 1 + rec(i - 1, pre[i][j] - 1));
    return ans;
}
void solve() {
    cin >> s1 >> s2;
    n = s1.size(), m = s2.size();
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < n; i++) {
        int p = -1;
        for (int j = 0; j < m; j++) {
            if (s1[i] == s2[j])p = j;
            pre[i][j] = p;
        }
    }
    int ans = rec(n - 1, m - 1);
    if (ans > n)ans = -1;
    cout << ans << endl;
}
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);

#ifdef Mastermind_
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#endif
    int t = 1;
    // int i = 1;
    cin >> t;
    while (t--) {
        // cout << "Case #" << i << ": ";
        solve();
        // i++;
    }
    return 0;
}


*/


/* Distinct Subsequences III

    Time-Limit: 1 sec Score: 0.00/100

Difficulty :*****

    Memory: 256 MB Accepted Submissions: 100

Relevant For:

Description

A subsequence is a string that can be derived from another string by
 deleting some or no symbols without changing the order of the remaining 
 symbols. Characters to be deleted are not required to go successively, 
 there can be any gaps between them. For example, for the string "abaca" 
 the following strings are subsequences: "abaca", "aba", "aaa", "a" and "" 
 (empty string). But the following strings are not subsequences: "aabaca", 
 "cb" and "bcaa".

You are given a string s
consisting of n

lowercase Latin letters.

In one move you can take any subsequence t
of the given string and add it to the set S. The set S can't contain duplicates.
 This move costs n−|t|, where |t|

is the length of the added subsequence (i.e. the price equals to the number 
of the deleted characters).

Your task is to find out the minimum possible total cost to obtain a set S
of size k

or report that it is impossible to do so.

Input Format

First-line contains T
- the number of test cases.
The first line of each test case contains two integers n and k — the length
 of the string and the size of the set, correspondingly.
The second line of each test case contains a string s consisting of n

lowercase Latin letters.

Output Format

For each test case, Print one integer —:
if it is impossible to obtain the set S
of size k, print −1

.
Otherwise, print the minimum possible total cost to do it.

Constraints

1≤T≤100

1≤n≤100
1≤k≤1012

Sample Input 1

4
4 5
asdf
10 100
ajihiushda
5 7
aaaaa
5 6
aaaaa

Sample Output 1

4
233
-1
15

Note

In the first example we can generate S
= { "asdf", "asd", "adf", "asf", "sdf" }. The cost of the first element in 
S is 0 and the cost of the others is 1. So the total cost of S is 4

.*/

//arsh agarwal's code :

#include<bits/stdc++.h>
using namespace std;
#define ll long long int

void solve(){
    ll n, k; cin>>n>>k;
    string s; cin>>s; s = '0'+s;
    ll pre[n+1][n+1]; memset(pre, 0, sizeof(pre)); pre[0][0] = 1;
    int last[26]; memset(last, 0, sizeof(last));
    bool done[n+1]; memset(done, false, sizeof(done));
    for(int i = 1; i <= n; i++){
        for(int j = n; j >= 0; j--){
            if(j==0){pre[i][0]=1; continue;}
            pre[i][j] = pre[i-1][j-1] + pre[i-1][j];
            if(last[s[i]-'a']) pre[i][j] -= pre[last[s[i]-'a']-1][j-1];
            done[j] |= done[j-1];
            if(pre[i][j]>k) done[j] = true;
        }
        last[s[i]-'a']=i;
    }

    //for(int i = 0; i <= n; i++) {for(int j = 0; j <= n; j++) cout << pre[i][j] << ' '; cout << '\n';}

    ll ans = 0;
    for(ll i = n; i >= 0; i--){
        if(done[i]) {ans += (n-i)*k; k=0; break;}
        if(k > pre[n][i]){
            ans += (n-i)*pre[n][i]; k-= pre[n][i];
        }else{
            ans += (n-i)*k; k=0; break;
        }
    }
    if(k!= 0) cout << -1 << '\n';
    else cout << ans << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //solve();
    int t; cin >> t; for(int i = 0; i < t; i++) solve();
    return 0;
}

//solution:

#include <bits/stdc++.h>
using namespace std;using ll=long long;
ll dp[102][102];string s;
ll rec(int i,int n,vector<vector<int>> &as){
    if(n==0)
        return 1;
    if(i>=s.size())
        return 0;
    if(dp[i][n]!=-1)
        return dp[i][n];
    
    ll &an=dp[i][n];
    an=0;
    for(int j=0;j<26;j++){
        int k=upper_bound(as[j].begin(),as[j].end(),i)-as[j].begin();
        if(k<as[j].size())
        an+=rec(as[j][k],n-1,as);
    }
    
    return an;
}
void solve(){
    ll n,k;
    cin>>n>>k;
    memset(dp,-1,sizeof(dp));
    cin>>s;
    vector<vector<int>> as(30);
    for(int j=0;j<s.size();j++){
        as[s[j]-'a'].push_back(j);
    }
    ll a=0;
    ll sum=0;int l=0;
    for(int i=n;i>=0;i--){
        a=0;
        if(i){for(int j=0;j<26;j++){
        int k1=upper_bound(as[j].begin(),as[j].end(),-1)-as[j].begin();
        if(k1<as[j].size())
        {   
            a+=rec(as[j][k1],i-1,as);
            
        }
        
    }}
    else a=1;
        // cout<<a[i]<<" ";
        if(a>=k){
           l=1;
            sum+=(n-i)*(k);
            break;
        }
        else{
            k-=a;
            sum+=(n-i)*a;
        }
    }
    if(l){
        cout<<sum<<"\n";
    }
    else{
        cout<<"-1\n";
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
//editorial code and approach 

/*Firstly, let's calculate the following auxiliary matrix: lsti,j means the maximum position pos that is less than or equal to i, and the character spos=j (in order from 0 to 25, ′a′=0, ′b′=1

, and so on). It can be calculated naively.

After calculating this matrix we can solve the problem by the following dynamic programming: let dpi,j
be the number of subsequences of length j that ends exactly in the position i. Initially all values are zeros except dpi,1=1 for each i from 0 to n−1

.

How do we perform transitionss? Let's iterate over all lengths j
from 2 to n, then let's iterate over all positions i from 1 to n−1 in a nested loop, and for the current state dpi,j we can calculate it as Σ25c=0dplsti−1,c,j−1. If lsti−1,c=−1 then we don't need to add this state of the dynamic programming to the current state. Don't forget to take the minimum with 1012

after each transition!

This transition means that we take all subsequences that end with each possible character of the alphabet and try to add the current character to each of them. You can understand that there are no overlapping subsequences in this dynamic programming.

After that let's iterate over all possible lengths j
from n to 1 and calculate the number of subsequences of the current length j. It equals to cnt=Σ25c=0dplstn−1,c,j. The same, if lstn−1,c=−1 then we don't need to add this state of the dynamic programming to cnt. Don't forget to take the minimum with 1012! If cnt≥k then let's add k∗(n−len) to the answer and break the cycle. Otherwise let's add cnt∗(n−len) to the answer and decrease k by cnt

.

If after all iterations k
is greater than zero then let's try to add the empty string to the answer (we didn't take it into account earlier). Increase the answer by n and decrease k by one. If after this k is still greater than zero then the answer is −1

, otherwise the answer is the calculated sum.

Time complexity: O(26∗n2)

per test case.

Code 1 ~ O(26∗26∗n∗n)

#include <bits/stdc++.h>
using namespace std;

#define ll int64_t
#define endl '\n'

string s;
ll n, k;
ll dp[101][101][26];
ll rec(int i, int l, int c) {
    if (l < 0)return 0;

    if (i == -1) {
        if (l == 0)return 1;
        return 0;
    }
    auto &ans = dp[i][l][c];
    if (ans != -1)return ans;
    ans = 0;
    if (s[i] - 'a' == c) {
        if (l == 1) { // only single character c.
            ans = 1;
        }
        else {
            for (int j = 0; j < 26; j++) {
                ans += rec(i - 1, l - 1, j);
                ans = min(ans, k);
            }
        }
    }
    else ans = rec(i - 1, l , c);
    ans = min(ans, k);
    return ans;
}
void solve() {
    cin >> n >> k;
    cin >> s;
    memset(dp, -1, sizeof(dp));
    ll ans = 0;
    for (int i = n; i >= 1 && k; i--) {
        for (int j = 0; j < 26 && k; j++) {
            if (k >= rec(n - 1, i, j)) {
                k -= rec(n - 1, i, j);
                ans += rec(n - 1, i, j) * (n - i);
            }
            else {
                ans += k * (n - i);
                k = 0;
                break;
            }
        }
    }
    if (k == 1) {
        ans += n;
    }
    else if (k > 1)ans = -1;
    cout << ans << endl;
}
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);

#ifdef Mastermind_
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#endif
    int t = 1;
    // int i = 1;
    cin >> t;
    while (t--) {
        // cout << "Case #" << i << ": ";
        solve();
        // i++;
    }
    return 0;
}

Code 2 ~ O(26∗n∗n)


#include <bits/stdc++.h>

using namespace std;

const long long INF64 = 1e12;

int main() {

#ifdef Mastermind_
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--) {
        int n;
        long long k;
        cin >> n >> k;
        --k; // the whole string costs nothing
        string s;
        cin >> s;

        vector<vector<int>> lst(n, vector<int>(26, -1));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 26; ++j) {
                if (i > 0) lst[i][j] = lst[i - 1][j];
            }
            lst[i][s[i] - 'a'] = i;
        }

        vector<vector<long long>> dp(n + 1, vector<long long>(n + 1));
        for (int i = 0; i < n; ++i) {
            dp[i][1] = 1;
        }

        for (int len = 2; len < n; ++len) {
            for (int i = 1; i < n; ++i) {
                for (int j = 0; j < 26; ++j) {
                    if (lst[i - 1][j] != -1) {
                        dp[i][len] = min(INF64, dp[i][len] + dp[lst[i - 1][j]][len - 1]);
                    }
                }
            }
        }

        long long ans = 0;
        for (int len = n - 1; len >= 1; --len) {
            long long cnt = 0;
            for (int j = 0; j < 26; ++j) {
                if (lst[n - 1][j] != -1) {
                    cnt += dp[lst[n - 1][j]][len];
                }
            }
            if (cnt >= k) {
                ans += k * (n - len);
                k = 0;
                break;
            } else {
                ans += cnt * (n - len);
                k -= cnt;
            }
        }

        if (k == 1) {
            ans += n;
            --k;
        }

        if (k > 0) cout << -1 << endl;
        else cout << ans << endl;
    }
    return 0;
}

*/


// day 1: achiver :

/* Remove Marbles

    Time-Limit: 2 sec Score: 0.00/100

Difficulty :****

    Memory: 256 MB Accepted Submissions: 100

Relevant For:

Description

You are given N marbles in different colours. You have to remove marbles till there are no marbles left. Each time you can choose continuous marbles with the same color, remove them and get k*k points (where ‘k’ is the length of the continuous marbles removed). Find the maximum points you can get.

Input Format

The first line contains one integer N - the length of the array. 

The second line contains N space-separated integers - the colours of the marbles.

Output Format

Print the maximum points you can get in a new line.

Constraints

1 ≤ N ≤ 100

0 ≤ Ai ≤ 100
Sample Input 1

4
2 1 3 2

Sample Output 1

6

Sample Input 2

6
4 3 1 1 4 2

Sample Output 2

10

Note

For the first test case of the example, remove 1, then 3 and then 2, we get 1*1+1*1+2*2 = 6.

For the second test case of the example, remove 1, then 3, then 4 and 2, we get 2*2+1*1+2*2+1*1 = 10.

*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

const int mod = 1e9+7;

int n;
int arr[102];

int dp[102][102][102];

int rec(int l,int r,int cnt)
{
    //pruning
    if(l>r) return 0;
    
    //base case
    if(l==r) return dp[l][r][cnt]=(cnt+1)*(cnt+1);
    
    //cache check
    if(dp[l][r][cnt] != -1) return dp[l][r][cnt];
    
    //transition
    int ans = (cnt+1)*(cnt+1) + rec(l+1,r,0);
    
    for(int p=l+1;p<=r;p++)
    {
        if(arr[p]==arr[l]) ans=max(ans,rec(l+1,p-1,0)+rec(p,r,cnt+1));
    }
    
    return dp[l][r][cnt]=ans;
}

void solve()
{
    cin>>n;
    for(int i=0;i<n;i++) cin>>arr[i];
    
    memset(dp,-1,sizeof(dp));
    
    int ans = rec(0,n-1,0);
    
    cout<<ans<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int _t=1;

    //cin>>_t;
    
    while(_t--) solve();
    
    return 0;
}

/*solution approach and editorial code :
Divide the problem into subproblems. For this problem, a similar approach can be used. f(i,j) = max(f(i,k)+f(k+1,j)) i<=k<j

You have to remove all subarrays with different colors as the end box, then remove all the boxes with the same color as the end boxes.

Use DP[i][j][k] which denotes the largest number we can get using i-th to j-th marbles with k same coloured marbles. The DP transition will be DP[i][j][k] = max(dp[i][p][k+1]+dp[p+1][j-1][0]).

Time Complexity: O(N^4)

Complete solution discussed in the live session.

#include <bits/stdc++.h>
using namespace std;

#define int long long

int dp[100][100][100];
int a[100];

int dfs(int l,int r,int k){
       if (l > r) return 0;
       if (dp[l][r][k]) return dp[l][r][k];

       while (l < r && a[r] == a[r-1]) {
           r--;
           k++;
       }
       dp[l][r][k] = dfs(l,r-1,0) + (k+1) * (k+1);
       for (int i = l; i < r; ++i) {
           if (a[i]==a[r]) {
               dp[l][r][k] = max(dp[l][r][k], dfs(l,i,k+1) + dfs(i+1,r-1,0));
           }
       }
       return dp[l][r][k];
   }

signed main(){
   ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
   int t = 1;
   while (t--) {
       int n;
       cin >> n;
       for (int i = 0; i < n; ++i) {
           cin >> a[i];
       }
       memset(dp, 0, sizeof(dp));
       cout << dfs(0, n-1, 0) << "\n";
   }
   return 0;
}

*/

