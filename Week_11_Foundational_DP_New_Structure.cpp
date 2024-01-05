/*Subset Sum Queries

Time-Limit: 1 sec Score: 1.00/100
Difficulty : **
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

Given an array of size 
N,and Q
 queries, for each query, you need to get the indices of the 
 elements of the array whose subset-sum is equal to the queried sum 
sumi, if possible, else return −1.

Input Format

Complete the Function subset_queries( vector &arr, vector &queries ) 
that takes vector a and queries vector as input.


Output Format

Return a vector < vector < int > > having 0
-based indices of the elements of the array whose subset-sum is equal to the queried sum 
sumi for each ith query, if possible, else return vector { −1}.


Constraints
1≤N≤100
 , size of vector < int > arr
1≤Q≤105
 , size of vector < int > queries
 1≤arr[i]≤105
 1≤sumi≤105

Sample Input 1

arr[] = { 1, 2, 3, 4, 5 }
queries[]= { 7, 16, 3 }

Sample Output 1

{ {1, 4}, {-1}, {2} }*/


#define ll int64_t
int dp[105][100100];
vector<int>curr;

int rec(int level,vector<int>&arr,int left){
    int n=arr.size();
    if(left<0)return 0;
    if(level==n){
        if(left==0)return 1;
        else return 0;
    }
    //int ans=0;
    if(dp[level][left]!=-1)return dp[level][left];
    int ans=rec(level+1,arr,left)||rec(level+1,arr,left-arr[level]);
    dp[level][left]=ans;
    return ans;
}



void indicies(int level,vector<int>&arr,int left){
    
    if(level==arr.size())return;
    
    if(rec(level+1,arr,left)){
        //curr.push_back(level);
        indicies(level+1,arr,left);
    }else if(rec(level+1,arr,left-arr[level])==1){
        
        curr.push_back(level);
        
        indicies(level+1,arr,left-arr[level]);
        
    }
    
    
    
    
}

vector<vector<int>> subset_queries(vector<int> &arr, vector<int> &queries) {
    memset(dp,-1,sizeof(dp));
   int x=queries.size();
   int n=arr.size();
   vector<vector<int>>ans;
   
   for(auto it:queries){
       curr.clear();
       
       if(rec(0,arr,it)==1){
           
           indicies(0,arr,it);
           ans.push_back(curr);
       }
       else{
           ans.push_back({-1});
       }
       
   }
   
   return ans;
   }
   

void solve() {
    int N, Q;
    cin >> N >> Q;
    vector<int> arr(N);
    for (int i = 0; i < N; i++)cin >> arr[i];
    vector<int> queries(Q);
    for (int i = 0; i < Q; i++)cin >> queries[i];
    auto ans = subset_queries(arr, queries);

    // checker.
    if (ans.size() != Q) {
        cout << 101 << endl;
        return;
    }
    for (int i = 0; i < Q; i++) {
        auto x = ans[i];
        if (x.size() == 0) {
            cout << 101 << endl;
            continue;
        }
        if (x.size() == 1 && x[0] == -1) {
            cout << -1 << endl;
            continue;
        }
        ll sum = 0, p = -10;
        for (auto y : x) {
            if (y < 0 || y >= N || p >= y ) { // valid 0-indexed.
                sum = -1111;
                break;
            }
            p = y;
            sum += arr[y];
        }
        if (sum == queries[i]) {
            cout << 1 << endl;
        }
        else cout << 101 << endl;
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

/*approach
To solve this problem efficiently, we can use the technique of Dynamic Programming.
 We can pre-compute all the possible subset sums for each index of the array 
 using a 2D boolean array, let's call it dp.

Specifically, 
dp[i][j]will be true if there is a subset of the elements from the array 
arr[0] to arr[i] whose sum is equal to j
We can compute dp[i][j] for all i and j using the following recurrence:dp[i][j]=dp[i−1]
[j]||dp[i−1][j−arr[i]]
dp[i−1][j]
for when we dont take the ith element into our subset.dp[i−1][j−arr[i]] to
 consider the case when we take the 
ith element into our subset and check if it is possible to form a subset in the first
  i−1 elements to form a sum of j−arr[i]The base cases are dp[0][0]=true 
  and dp[0][j]=false for all j>0.

Once we have pre-computed all the possible subset sums using the above recurrence, 
we can answer each query in constant time by checking if 
dp[N−1][sum]
 is true or false. If it is true, we can find the indices of the elements that 
 contribute to the subset sum using a simple backtracking technique.


*/

/*Knapsack

Time-Limit: 2 sec Score: 1.00/100
Difficulty : *
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

There are 
N items numbered from 1 to N .The ith item has a weight of wi and a value of vi .

You have to choose some items out of the N
 items and carry them home in a knapsack. The capacity of the knapsack is 
W
 which donate the maximum weight that can be carried inside the knapsack. In other words, 
W
 means the total summation of all weights of items that can be carried in the knapsack.

Print maximum possible sum of values of items that you can take home.

Note: Solve this problem using recursion.


Input Format

First line contains two numbers N and W number of items and the 
capacity of the knapsack.

Next N lines will conatain two nos. wi and vi.
 
Output Format

Print maximum possible sum of values of items that you can take home.


Constraints

(1≤N≤20,1≤W≤100)

(1≤wi≤50,1≤vi≤1000)


Sample Input 1

3 8
3 30
4 50
5 60

Sample Output 1

90

Sample Input 2

6 15
6 5
5 6
6 4
6 6
3 5
7 2

Sample Output 2

17*/

int N, W;
vector<int> w, v;
int knapsack(int wei, int n)
{
    if (n == 0 || wei == 0)
        return 0;
    // If weight of the nth item is more
    // than Knapsack capacity wei, then
    // this item cannot be included
    // in the optimal solution
    if (w[n - 1] > wei)
    {
        return knapsack(wei, n - 1);
    }
    // Return the maximum of two cases:
    // (1) nth item included
    // (2) not included
    return max(v[n - 1] + knapsack(wei - w[n - 1], n - 1), knapsack(wei, n - 1));
}
int main()
{

    cin >> N >> W;
    w.resize(N);
    v.resize(N);
    for (int i = 0; i < N; i++)
    {
        cin >> w[i] >> v[i];
    }
    int ans = knapsack(W, N);
    cout << ans << endl;
}


/*approach
Try to think what are the two options which one has while iterating through 
the ith item in knapsack.


Let the optimal subset contain all the items which will give the maximum
 value for the given weight.

There can be two cases for every item. 

Case 1: The item is included in the optimal subset.
Case 2: The item is not included in the optimal set.
Therefore, the maximum value that can be obtained from ‘n’ items is 
the max of the following two values. 

Maximum value obtained by n-1 items and W weight (excluding nth item).
Value of nth item plus maximum value obtained by n-1 items and W minus 
the weight of the nth item (including nth item).
If the weight of ‘nth’ item is greater than ‘W’, then the nth item cannot 
be included and Case 1 is the only possibility.*/




/*

Bricks Colouring

Time-Limit: 5 sec Score: 1.00/100
Difficulty : *
 Memory: 256 MB Accepted Submissions: 100
 You are given N bricks in a line and M different coloured buckets of paint.
  You have to find the number of ways you can colour the brick wall such that
   there are exactly K positions out of the N bricks such that it has a different
    colour from the brick wall on its immediate left. (except the first brick, 
    since there is no left brick). Print it modulo 10^9+7.

 

 


Input Format

The first line of the input contains one integer T - the number of test cases. 
Then T test cases follow.

The first and only line of each test case contains three space-separated
 integers N, M, K.

 


Output Format

For each test case, print the number of ways you can colour the brick wall 
satisfying the given condition % 10^9+7.


Constraints

1≤ T ≤ 100

1≤ N, M ≤ 2000

0≤ K ≤ N-1

It is guaranteed that the sum of NK over all test cases does not exceed 4108.


Sample Input 1

3
3 2 2
2 2 1
3 5 0

Sample Output 1

2
2
5

Note

For the first test case, the following are the 2 different arrangements possible:



For the second test case, the following are the 2 different arrangements possible:



For the third test case, the following are the 5 different arrangements possible:

*/

ll n,m,k;
ll dp[2010][2010];
bool done[2010][2010];

ll rec(ll level,ll left){
	
	
	// pruning 
	//if(level>n||m<0)return 0;
	
	// base case
	if(level==n){
	if(left==k)return 1;
	    else return 0;
	}
	
	// cache check 
	if(done[level][left])return dp[level][left];
	
	// compute 
	ll ans=0;
	
	ans=(rec(level+1,left)%mod);
	ans+=((rec(level+1,left+1)*(m-1))%mod);
	
	
	
	
	// save and return 
	done[level][left]=true;
	return dp[level][left]=ans;

	}



void solve(){
	
	
	cin>>n>>m>>k;
	
	memset(done,0,sizeof(done));
	cout<<(m*rec(1,0))%mod<<nl;
	

	
	
}


/*Cleaning Window

Time-Limit: 2 sec Score: 1.00/100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Description

There is a building with N (numbered 1 through N from top to bottom) floors,
 each with M windows. All the windows need to be cleaned. For each valid i and j,
  the window (i,j) must be cleaned on the A(i,j)-th turn. From window(i, j), water
   flows to the window(i+1,j-1), window(i+1,j), and window(i+1,j+1) if exists.
    When a window(i,j) is cleaned, window(i+1,j-1), window(i+1,j) and window(i+1,j+1)
     become dirty because of dirty water after cleaning window(i,j). Water flows 
     further down of these dirty windows making next level windows dirty, and the
      same things go on recursively. 

E.g. When the window(0, 5) is getting cleaned. Then the water flows down to windows 
(1, 4), (1, 5) and (1, 6) making them dirty. Then the water flows from the window (1, 4) 
down to (2, 3), (2, 4), (2, 5), from the window (1,5) to (2, 4), (2, 5), (2, 6). And so on.

You have to determine whether each window will be clean after the cleaning process ends.


Input Format

The first line of the input contains one integer T - the number of test cases. 
Then T test cases follow.

The first line of each test case contains two space-separated integers N, 
M - the size of the building.

Each of the next N lines contains Ai,j - the time at which window (i,j) is cleaned.
 At a time, only one window can be cleaned.


Output Format

For each test case, print N lines, each with M integers denoting whether the (i,j)-th 
window will be clean or not after the cleaning process ends.


Constraints

1 ≤ T ≤ 1000

1 ≤ N, M ≤ 1000

1 ≤ Ai,j ≤ NM

Sum of NM across all test cases <= 10^7.

 


Sample Input 1

3
2 2
4 3
2 1
3 3
1 2 3
6 5 4
7 8 9
3 4
1 4 7 3
5 8 2 6
12 11 9 10

Sample Output 1

11
00
111
111
111
1111
1100
1111

Note

For the first test case, when window(1,1) and window(1,2) are cleaned, they make the 
window(2,1) and window(2,2) dirty. They were cleaned earlier, so they remain dirty.

For the second test case, all the windows remain clean because when a window becomes 
dirty, it gets cleaned afterwards.*/


int rec(int i,int j)
{
    //pruning
    if(i<0||i>n||j<0||j>m)
        return -1e9;
    //base case
    if(i==1)
        return dp[i][j]=grid[i][j];
    //memcheck
    if(dp[i][j]!=-1)
        return dp[i][j];

    //compute
    
    int ans=max(rec(i-1,j),max(rec(i-1,j-1),rec(i-1,j+1)));
    ans=max(ans,grid[i][j]);
    return dp[i][j]=ans;


}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;

        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                cin>>grid[i][j];

        // for(int i=0;i<=n;i++)
        //     for(int j=0;j<=m;j++)
        //         dp[i][j]=-1;
        memset(dp,-1,sizeof(dp));

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(rec(i,j)>grid[i][j])
                    cout<<0;
                else
                    cout<<1;

             }
             cout<<'\n';
        }

    }
}

/*approach
Dirty water reaches (i,j) only from (i-1,j-1), (i-1,j) and (i-1,j+1).


We can make DP array as DP[i][j] = max(DP[i-1][j-1], DP[i-1][j], DP[i-1][j+1])
 which will denote the time when dirty water is reached at (i,j). We are given 
 the time when (i,j) is cleaned, when this is greater than or equal to DP[i][j],
  the window(i,j) is clean, otherwise dirty.

Time Complexity per test case: O(N*M)


Another simple approach -> just start from the window that will be cleaned at last.
 For sure that window will be cleaned. Find out the cells that are reachable from
  that cell. All that cells will be dirty for sure. Now pick the 2nd last 
  cleaned window, if it is not already dirty due to the last window. You can mark 
  it as cleaned and again find all the windows reachable and mark the windows as dirty. 
  If the window is already dirty then no need to do anything. Keep on doing that. 
  You will visit each window only once, so the time complexity is O(n*m).


*/


/*Sum Partition

Time-Limit: 2 sec Score: 1.00/100
Difficulty : ***
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

Find the number of unordered ways, 
N can be partitioned into K
 positive integers (i.e >0), i.e sum of all K numbers must be N
.

Print the answer mod 10^7;

For eg. N=7, K=3
,then the number of unordered ways are 4.
Explanation : { 1, 5, 1 }, { 2, 2, 3 }, { 4, 2, 1 }, and { 3, 1, 3 }.
Note : { 1, 5, 1 }, { 1, 1, 5 } and { 5, 1, 1 } are treated as same combination,
 i.e order doesn't matter.


Input Format

First-line contains 
T
 - the number of test cases.
The first line of each test case contains two integers - N and K;



Output Format

For each test case, Output the number of unordered ways, N can be partitioned
 into K  positive integers .


Constraints

1≤T≤106
1≤N≤5000
1≤K≤5000

Sample Input 1

3
1 1
7 3
4 5

Sample Output 1

1
4
0*/

ll n,k;

ll dp[5100][5100];


ll rec(ll n,ll k){
//cout<<"n :"<<n<<" k :"<<k<<" ans:"<<ans<<nl;
	// pruning 
	if(n<k||n<0||k<0)return 0;
	
	
	// basecase 
	if(k==1){
		if(n>=1)return 1;
	}
	
	
	// cache checking 
	if(dp[n][k]!=-1)return dp[n][k]%mod;
	
	
	// compute 
	
   	ll ans=0;
	
	ans=(rec(n-1,k-1)%mod);
//	cout<<"n :"<<n<<" k :"<<k<<" ans:"<<ans<<nl;
	ans+=((rec(n-k,k)%mod))%mod;  // move to kth position without any partition
	// and ther explore +take 1 with one partiion and explore everything from their
	
	// save and return 
//	cout<<"n :"<<n<<" k :"<<k<<" ans:"<<ans<<nl;
	
	return dp[n][k]=ans;
	
}

void solve(){
	cin>>n>>k;
	
	
	//	cout<<"n :"<<n<<" k :"<<k<<nl;
	cout<<rec(n,k)%mod<<nl;
	
}

/*approach
Let us consider {1,3,5} a way of partitioning 
9
, and permutations {3,1,5} , {5,1,3} ... etc are treated as same, 
so let us work for the sorted partition i.e {1,3,5}.
we can think of each number as a stack of 1's.
So, {1,3,5} can be represented as -:

      1  -> number of 1's = 1 
      1  -> number of 1's = 1 
    1 1  -> number of 1's = 2 
    1 1  -> number of 1's = 2 
+ 1 1 1  -> number of 1's = 3
---------
  1 3 5
---------
So, on each level, the number of 1's is decreasing( not strictly ) as we move up.
By inserting the different decreasing numbers of 1's at each level we can generate
 any sorted permutation partition of the sum.
 
dp[n][k]- Number of ways to partition 
n when inserting 
k number of 1's at the current level.

One can fix the number of ones in final partition:

0 ones -- dp[n−k][k]ways,

1 one -- dp[n−k][k−1] ways,

...

n ones -- dp[n−k][0] ways.

So dp[n][k]=Σkj=0dp[n−k][j].

Time Complexity : 
o(N∗K)
 for pre-computation, O(1) per test case.*/


/*Maximum path sum in grid

Time-Limit: 1 sec Score: 100.00/100
Difficulty : *
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

Given a grid of size n*m with non-negative integers, you need to 
find the maximum path sum from (1, 1) to (n, m). You are allowed 
to move from (x, y) to (x+1, y) and (x, y) to (x, y+1).


Input Format

The first line of the input contains one integer t -
 the number of test cases. Then t test cases follow.

The first line of each test case contains two space-separated 
integers n, m - the size of the grid.

Each of the following n lines contains m space-separated integers,
 aij - the number at that cell.


Output Format

For each test case, print the maximum path sum.


Constraints

1 ≤ t ≤ 105

1 ≤ n, m ≤ 103

0 ≤ aij ≤ 107

It is guaranteed that the sum of n*m over all test cases does not exceed 106.


Sample Input 1

3
2 3
3 2 1
4 1 1
3 3
1 2 1
3 5 1
4 1 1
2 2
1 2
3 4

Sample Output 1

9
11
8

Note

For the first test case, path 3 → 4 → 1 → 1 maximises the sum.

For the second test case, path 1 → 2 → 5 → 1 → 1 and 1 → 3 → 4 → 1 → 1
 maximises the sum.

For the third test case, path 1 → 3 → 4 maximises the sum.*/

ll n,m;

ll arr[1010][1010];

ll dp[1010][1010];

bool done[1010][1010];


ll rec(ll x,ll y){
//best route length(longest)ending at(x,y)position from [{0,0}......{x,y}] 
	
	
	//pruning
	
	if(x<0||y<0)return -1e9;
	
	// base case
	
	if(x ==0&& y ==0){
        return arr[0][0];
    }
	
	//cache check
	
	if(done[x][y])return dp[x][y];
	
	
	//compute 
	
	ll ans=-1e9;
	
	if(x!=0){
		ans=max(ans,rec(x-1,y)+arr[x][y]);
	}
	if(y!=0){
		
			ans=max(ans,rec(x,y-1)+arr[x][y]);
	}
	
	
	//ans=max(rec(x-1,y)+arr[x][y],rec(x,y-1)+arr[x][y]);
	 // it is short cut as if rec(0,1) is called then in pruning 
//section it take -1e9 and ans=max(-INF,rec(0,(1-1=0))+arr[x][y])=
// rec(0,(1-1=0))+arr[x][y],
	//same will be happend for if(1...n,0) is called then 
	// ans=max(.......,-inf)=.......
	
	done[x][y]=true;
	return dp[x][y]=ans;
	
	//save and return
	
	
}


void solve(){
	
	cin>>n>>m;
	
	
	for(int i=0;i<n;i++){
		
		for(int j=0;j<m;j++){
			
			cin>>arr[i][j];
			
			done[i][j]=false;
		}
	}
	
	// ll best=-1e9;
	// for(int i=0;i<n;i++){
		
	// 	for(int j=0;j<m;j++){
			
	// 		best=max(best,rec(i,j));
	// 	}
	// }
	
	// cout<<best<<nl;
	
	
	//*** rec(n-1,m-1)---> means the best path  sum emding at n-1,m-1..
	// eventually this only is asked in the question 
	// so we don't need to write the // ll best=-1e9;
	// for(int i=0;i<n;i++){
		
	// 	for(int j=0;j<m;j++){
			
	// 		best=max(best,rec(i,j));
	// 	}
	// }
	
	// cout<<best<<nl; for checking all the cell   ******
	// --- understand the meaning of rec(x,y)properly
	
	
	
	cout<<rec(n-1,m-1)<<nl;
}

//editorial code 

int dp[1005][1005];
int grid[1005][1005];
signed main(){
   ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
   int t;
   cin >> t;
   while(t--) {
       int n, m;
       cin >> n >> m;
       for (int i = 0; i < n; ++i) {
           for (int j = 0; j < m; ++j) {
               cin >> grid[i][j];
           }
       }
       for (int i = 0; i <= n; ++i) {
           for (int j = 0; j <= m; ++j) {
               dp[i][j] = 0;
           }
       }
       for (int i = 0; i < n; ++i) {
           for (int j = 0; j < m; ++j) {
               dp[i+1][j+1] = grid[i][j] + max(dp[i+1][j], dp[i][j+1]);
           }
       }
       cout << dp[n][m] << "\n";
   }
   return 0;
}

/*approach
The cell (i, j) can only be reached from the cells (i-1, j) and (i, j-1).


Since precomputed values are being used, the problem can be solved using 
dynamic programming.


Find the maximum path sum for the cell (i, j) using the cells (i-1, j) and (i, j-1). 
Define dp[i][j] which denotes the maximum path sum to reach (i, j). The maximum path
 sum for arriving at the cell (i, j) can be given as 
 dp[i][j] = grid[i][j] + max(dp[i-1][j], dp[i][j-1]).
  Use the same recurrence for finding dp[n][m].

Time Complexity per test case: O(n*m)

Solve the same problem for minimum path sum. Do not forget the boundary 
condition for the leftmost column and topmost row.*/


/*Number of Paths in Grid - 1

Time-Limit: 1 sec Score: 100.00/100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

Given a grid of size n*m, you need to find the number of paths from
 (1, 1) to (n, m). You are allowed to move from (x, y) to (x+1, y) and
  (x, y) to (x, y+1). The grid may have some blocked cells, represented by 1,
   and it is not allowed to move to a blocked cell. An empty cell is represented by 0.


Input Format

The first line of the input contains one integer t - the number of test cases. Then t test cases follow.

The first line of each test case contains two space-separated integers n, m - the size of the grid.

Each of the following n lines contains m space-separated integers, aij - the number at that cell.


Output Format

For each test case, print the number of paths modulo 109 + 7.


Constraints

1 ≤ t ≤ 105

1 ≤ n, m ≤ 103

0 ≤ aij ≤ 1

It is guaranteed that the sum of n*m over all test cases does not exceed 106.


Sample Input 1

3
2 3
0 1 0
0 0 0
3 3
0 0 1
0 0 0
0 0 0
2 2
1 0
0 0

Sample Output 1

1
5
0

Note

For the first test case, there is only one path, (1, 1) → (2, 1) → (2, 2) → (2, 3).

For the third test case, no path can reach (2, 2) since the starting point is blocked.*/

ll n,m;

ll arr[1010][1010];

ll dp[1010][1010];

//bool done[1010][1010];


ll rec(ll r,ll c){ //
	
	
	// pruning 
	if(arr[r][c]==1||r<0||c<0)return 0;
	
	// base case
	
	if(r==0&&c==0)return 1;
	
	
	// cache check
	
	if(dp[r][c]!=-1)return dp[r][c];
	
	// compute 
	
	ll ans=(rec(r-1,c))%mod;
	
	ans=(ans+(rec(r,c-1))%mod);
	
	
	
	// save and retunr
	
	//done[r][c]=true;
	
	return dp[r][c]=ans;

}
void solve(){
	
	cin>>n>>m;
	
	
	for(int i=0;i<n;i++){
		
		for(int j=0;j<m;j++){
			
			cin>>arr[i][j];
			
			//done[i][j]=false;
			dp[i][j]=-1;
			
		}
	}
	
	//memset(dp,-1,sizeof(dp));
	
	cout<<rec(n-1,m-1)%mod<<nl;
}



//editorial code
const int mod = 1e9 + 7;
int dp[1005][1005];
bool grid[1005][1005];
signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> grid[i][j];
                dp[i][j] = 0;
            }
        }
        if(grid[0][0] || grid[n-1][m-1]) {
            cout << 0 << "\n";
            continue;
        }
        dp[0][0] = 1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if(grid[i][j]) {
                    continue;
                }
                if(i) {
                    dp[i][j] = (dp[i][j] + dp[i-1][j])%mod;
                }
                if(j) {
                    dp[i][j] = (dp[i][j] + dp[i][j-1])%mod;
                }
            }
        }
        cout << dp[n-1][m-1] << "\n";
    }
    return 0;
}

/*approach
The cell (i, j) can only be reached from the cells (i-1, j) and (i, j-1). 
Since precomputed values are being used, the problem can be solved 
using dynamic programming.


If a cell is blocked, it cannot be reached and will not contribute 
to the final path.


Find the number of paths from (1, 1) to (i, j) using the cells (i-1, j) and (i, j-1). 
Define dp[i][j] which denotes the number of paths to reach (i, j). The number
 of paths for arriving at an unblocked cell (i, j) can be given as 
 dp[i][j] = dp[i-1][j] + dp[i][j-1]. If the cell is blocked, dp[i][j] = 0.
  The base case would be at cell (1, 1), there is only one way to reach it, 
  if it is unblocked. Use the same recurrence for finding dp[n][m].

Time Complexity per test case: O(n*m)


*/


/*Longest Common Substring

Time-Limit: 2 sec Score: 100.00/100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

Given two strings. The task is to find the length of the longest 
common substring.


Input Format

First-line contains 
T
 - the number of test cases.
Each test case contains two strings s1 and s2 in a single line.


Output Format

For each test case, output the length of the longest common
 substring of the two strings, in a new line.


Constraints
1≤T≤100

1≤|s1|≤1000

1≤|s2|≤1000

s1 and s2 contains small letters only.


Sample Input 1

3
abc abc
algozenith algo
algo zenith

Sample Output 1

3
4
0*/

string s1,s2;

ll n,m;



ll dp[1010][1010];
ll rec(ll i,ll j){// lcs from [i....n-1]and [j---m-1]


// pruning
	
	// base case
	if(i>=n||j>=m)return 0;
	
	// cache check
	
	if(dp[i][j]!=-1)return dp[i][j];
	// compute 
	
	ll ans=0;
	
	
	
	// ans=max(ans,rec(i,j+1));
	// ans=max(ans,rec(i+1,j));
//   this moves are not valid in substring ... this moves are only valid in subsequence
	
	
	if(s1[i]==s2[j]){
		
		ans= max(ans,1+rec(i+1,j+1));
	}
	
	// save and return
	
	return dp[i][j]=ans;



}



void solve(){
	
	
	cin>>s1>>s2;
	
	n=s1.size();
	
	m=s2.size();
	

	memset(dp,-1,sizeof(dp));
	 ll ans = 0;
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            ans = max(ans, rec(i,j));
        }
    }
    cout<<ans<<nl;
	
	
	
	
}


/*Subtraction Game

Time-Limit: 1 sec Score: 1.00/100
Difficulty : **
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

Vivek and Abhishek are playing a game of chips, taking turns alternatively. Initially, there are 
x chips on the table. On each turn, a player can pick up  2^m chips such that m≥0
 and x≥2^m .A player loses the game if he has no chips to pick from the table.

Given that Vivek starts the game, Predict the winner of the game.


Input Format

The first line contains 
T - the number of test cases.
The next 
T
 lines contain an integer 
x
, - the number of chips on the table.


Output Format

For each test case, Predict the winner of the chip game. 
Output "Vivek" if Vivek wins; else output "Abhishek", on a new line.


Constraints

1≤T≤106.
0≤x≤2×105.


Sample Input 1

5
0 
2
12783
1001
33

Sample Output 1

Abhishek
Vivek
Abhishek
Vivek
Abhishek*/

ll c;

ll done[200100];
ll dp[200100];


ll rec(ll x){ 
/* state ==moves by the first player ... if any (x-2^m)==0 means 
oponen should lose then the current state will be wining state*/
	
	if(x<0)return 0;
	
	if(x==0)return 0;
	
	
	if(done[x])return dp[x];
	
	int ans=0;
	for(ll m=0;(1<<m)<=x;m++){
		
		
		if(rec(x-(1<<m))==0){
			
			ans=1;
			break;
		}
	}
	
	done[x]=true;
	return dp[x]=ans;
	
}

void solve(){
	
	cin>>c;
	
	// for(ll i=0;i<c;i++){
	// 	done[i]=false;
	// }
	
	if(rec(c)==1)cout<<"Vivek"<<nl;
	else{
		cout<<"Abhishek"<<nl;
	}
	
}


/*approach
Refer to the Game DP video by 
Vivek: https://www.youtube.com/watch?v=0RMrTojwPxs*/

//editorial code 
vector<int> dp;
int rec(int x) {
    if (x == 0)return 0;
    if (__builtin_popcount(x) == 1)return 1;
    auto &ans = dp[x];
    if (ans != -1)return ans;
    ans = 1;
    for (int j = 0; (1 << j) <= x; j++) {
        ans &= rec(x - (1 << j));
    }
    ans ^= 1;
    return ans;
}
void solve() {
    dp.assign((int)2e5 + 10, -1);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        auto ans = rec(n);
        if (ans)cout << "Vivek" << endl;
        else cout << "Abhishek" << endl;
    }
}
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);
    solve();
    return 0;
}


/*Make Palindrome

Time-Limit: 2 sec Score: 50.00/100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

Given a string 
s
, find the minimum number of characters that need to 
be inserted into the string to make it a palindrome.


Input Format

First line contains 
T
 - the number of test cases.
First line of each test case contains the string 
s
.


Output Format

For each test case, output the minimum number of characters
 that need to be inserted into the string to make it a palindrome.


Constraints

1≤T≤100

1≤|s|≤1000

Sample Input 1

4
algozenith
abba
goomgle
fft

Sample Output 1

9
0
3
1*/

string str,str1;
ll n;

ll dp[1010][1010];

ll rec(ll i,ll j){ // give lcs from [i........n-1] of str nd [j......n-1] of str1
	
	//pruning
	
	// basecase
	if(i>=n||j>=n)return 0;
	
	
	// cache check
	
	if(dp[i][j]!=-1)return dp[i][j];
	
	// compute 
	ll ans=0;
	if(str[i]==str1[j]){
		
		ans=max(ans,1+rec(i+1,j+1));
	}else{
		ans=max(ans,rec(i,j+1));
	
	ans=max(ans,rec(i+1,j));}
	
	// save and return 
	
	return dp[i][j]=ans;	
}

void solve(){
	 //s = "GeeksforGeeks";
cin>>str;
n=str.size();
str1 = string(str.rbegin(), str.rend());

memset(dp,-1,sizeof(dp));
ll lcs=rec(0,0);

ll ans=n-lcs;

cout<<ans<<nl;
	
	
	
	
}

/*Approach I
This question requires us to find the minimum number of
 insertions to create a palindrome from a given string.

DP[i][j]= Number if insertions required for the string S[j..i].

Let's say you have the string: “xxa”

You can either insert a character at the beginning, which will be
 the same character as the end, i.e “a”, or you can insert a character 
 at the end, which will be the same character as at the beginning, i.e “x”.
  If you add an “a” at the beginning, then you have to see how many insertions
   are required to make “xx” a palindrome, otherwise, if you add “x”
    at the end, you will need to calculate how many insertions are required 
    to make “xa” a palindrome. Hence, finding the answer for substrings, “xx”, 
    and “xa”, are the smaller subproblems.

Approach II
We can easily get the number of chars not in the palindrome sequence by
 getting the inverse of the original string, finding out the Longest Common
  Substring, which makes a palindrome, and using the total length of the 
  original string subtracting the length of LCS.

Time Complexity : 
O(N2) per test case*/


/*LCS of 3 Strings

Time-Limit: 5 sec Score: 100.00/100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

Given 
3
 strings 
s
1
, 
s
2
 and 
s
3
, the task is to find the length of the longest common sub-sequence in all three given strings.


Input Format

First-line contains 
T
 - the number of test cases.
Each test case contains 
3
 strings in a single line.


Output Format

For each test case, print the length of the longest common subsequence in all the 
3
 given strings, in a new line.


Constraints

1≤T≤100
1≤|s1|≤100

1≤|s2|≤100

1≤|s3|≤100

Sample Input 1

3
abc abc bbc
algozenith algo algorithm
algo zenith zen

Sample Output 1

2
4
0*/

string s1,s2,s3;

 ll n,m,p;
 
 ll dp[110][110][110];
 
 ll rec(ll i,ll j,ll k){  // lcs from [i...n-1],[j.....m-1], [k....p-1]
 	
  // pruning 
 	
 	// base case 
 	
 	if(i>=n||j>=m||k>=p){
 		
 		return 0;
 		
 	}
 	
 	
 	
 	// cache check
 	 
 	if(dp[i][j][k]!=-1){
 		return dp[i][j][k];
 	}
 	
 	// compute
 	
 	ll ans=0;
 	
 	ans=max(ans,rec(i,j,k+1));
 	ans=max(ans,rec(i,j+1,k)) ;
 	
 	ans=max(ans,rec(i+1,j,k));
 	
 	if(s1[i]==s2[j]&&s2[j]==s3[k]){
 		
 		ans=max(ans,1+rec(i+1,j+1,k+1));
 	}
 	
 	
 	// return and save
 	
 	
 	return dp[i][j][k]=ans;
 	
 }


void solve(){
	
	
	cin>>s1>>s2>>s3;
	
	n=s1.size();
	m=s2.size();
	
	p=s3.size();
	
	memset(dp,-1,sizeof(dp));
	
	cout<<rec(0,0,0)<<nl;
	
	
	
}

//editorial code 
#include <bits/stdc++.h>
using namespace std;

#define ll int64_t
#define endl '\n'


int dp[101][101][101], n1, n2, n3;
string s1, s2, s3;
void solve() {
    cin >> s1 >> s2 >> s3;
    memset(dp, 0, sizeof(dp));
    n1 = s1.size(), n2 = s2.size(), n3 = s3.size();
    for (int i = 1; i <= n1; i++) {
        for (int j = 1; j <= n2; j++) {
            for (int k = 1; k <= n3; k++) {
                auto &ans = dp[i][j][k];
if (s1[i - 1] == s2[j - 1] && s2[j - 1] == s3[k - 1])ans = 
	max(ans, 1 + dp[i - 1][j - 1][k - 1]);
ans = max({ans, dp[i - 1][j][k], dp[i][j - 1][k], dp[i][j][k - 1]});
            }
        }
    }
    cout << dp[n1][n2][n3] << endl;
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


/*Maximum Area of Square

Time-Limit: 3 sec Score: 1.00/100
Difficulty : **
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

Given a grid of size n*m with 0s and 1s, you need to find 
the area of the largest square containing only 1.


Input Format

The first line of the input contains one integer t -
 the number of test cases. Then t test cases follow.

The first line of each test case contains two space-separated integers
 n, m - the size of the grid.

Each of the next n lines contains m space-separated integers, aij - 
the number at that cell.


Output Format

For each test case, print the maximum area.


Constraints

1 ≤ t ≤ 105

1 ≤ n, m ≤ 103

0 ≤ aij ≤ 1

It is guaranteed that the sum of n*m over all test cases does not exceed 107.


Sample Input 1

3
2 3
0 1 1
0 0 0
3 3
1 0 1
0 1 1
0 1 1
2 2
0 0
0 0

Sample Output 1

1
4
0*/

int dp[1005][1005];
bool grid[1005][1005];
signed main(){
   ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
   int t;
   cin >> t;
   while(t--) {
       int n, m;
       cin >> n >> m;
       for (int i = 0; i < n; ++i) {
           for (int j = 0; j < m; ++j) {
               cin >> grid[i][j];
           }
       }
       for (int i = 0; i <= n; ++i) {
           for (int j = 0; j <= m; ++j) {
               dp[i][j] = 0;
           }
       }
       int ans = 0;
       for (int i = 1; i <= n; ++i) {
           for (int j = 1; j <= m; ++j) {
               if(grid[i-1][j-1]) {
                   dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
               }
               ans = max(ans, dp[i][j]);
           }
       }
       cout << ans*ans << "\n";
   }
   return 0;
}
/*approach
If the value of the cell at (i,j) is 1, to find the answer for the largest
 square with bottom right corner at (i, j), you will have to extend the 
 square in left, top and diagonal direction.


Instead of the area, store the length of the square in the dp array.


Define dp[i][j] which denotes the length of the largest square with its
 bottom right corner at (i, j). This can be given as:
  dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1. The area is
   equal to length2. You need to find the maximum answer for all (i,j). 
   Use the same recurrence for finding length for all i,j.

Time Complexity per test case: O(n*m)


*/


/*Number of Paths in Grid - 2

Time-Limit: 4 sec Score: 100.00/100
Difficulty : ***
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

Given a grid of size n*m, you need to find the total number of different
 paths from (1, 1) to (n, m). You are allowed to move from (x, y) to (x+1, y) 
 and (x, y) to (x, y+1). The grid may have some blocked cells, represented by 1,
  and it is not allowed to move to a blocked cell. An empty cell is represented by 0
  . You are also given an integer k and you can convert at most k
   blocked cells into unblocked cells.


Input Format

The first line of the input contains one integer t - the number of test cases
. Then t test cases follow.

The first line of each test case contains three space-separated integers n, m, k -
 the size of the grid and the number of cells you can convert.

Each of the following n lines contains m space-separated integers, aij -
 the number at that cell.


Output Format

For each test case, print the number of paths modulo 10^9 + 7.


Constraints

1 ≤ t ≤ 105

1 ≤ n, m ≤ 200

0 ≤ k ≤ 400

0 ≤ aij ≤ 1

It is guaranteed that the sum of nmk over all test cases does
 not exceed 108.


Sample Input 1

3
3 3 2
0 1 1
1 1 0
1 0 0
3 3 1
0 1 1
1 1 0
1 0 0
2 3 0
1 0 0
0 1 0

Sample Output 1

6
0
0

Note

For the first test case, any path from (1,1) to (n,m) has 2 blocked cells,
 which can be unblocked.

For the third test case, no cells can be unblocked and the first cell is blocked, 
so there are no paths from (1,1) to (n,m).


1
*/

ll n, m, k;
ll grid[210][210];
ll dp[210][210][410];

ll rec(ll r, ll c, ll k) {
    // pruning 
    if(r<0 || c<0) return 0;
    if(grid[r][c]==1) {
        if(k<=0) return 0;
        else k--;
    }
    
    // base case 
    if(r==0 && c==0) return 1;
    
    // cache check 
    if(dp[r][c][k] != -1) return dp[r][c][k];
    
    // compute 
    ll ans = 0;
    ans = (rec(r-1, c, k) % mod);
    ans = (ans + (rec(r, c-1, k)) % mod) % mod;
    
    // save and return 
    return dp[r][c][k] = ans;
}

void solve() {
    cin >> n >> m >> k;
    for(ll i=0; i<n; i++) {
        for(ll j=0; j<m; j++) {
            cin >> grid[i][j];
            for(ll l=0; l<=k; l++) {
                dp[i][j][l] = -1;
            }
        }
    }
    cout << rec(n-1, m-1, k) % mod << "\n";
}

/*The transitions would be as follows :

Case1 : If (i,j)
 is a blocked cell
ans = rec(i + 1, j, left - 1) + rec(i, j + 1, left - 1) ;
Converting blocked cell to unblocked takes one of our chances and hence
 in the next recursive step we would have left-1 number of chances left.

Case2 : If 
(i,j)
 is unblocked
ans = rec(i + 1, j, left) + rec(i, j + 1, left ) ;

Time Complexity per test case: 
O(n∗m∗k)

*/


//NOTE: good understandable question of dp. here k is in the rec(function )
//because when it backtrack k must be taken in consideration


/*Count LIS

Time-Limit: 2 sec Score: 1.00/100
Difficulty : ***
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

Given an integer array arr of length n
, output the number of longest increasing subsequences.

Notice that the sequence has to be strictly increasing.


Input Format

First line contains 
T
 - the number of test cases.
First line of each test case contains 
n
 - the length of the array arr;

Second line of each test case contains array arr
.


Output Format

For each test case, output the number of longest 
increasing subsequences in a newline.


Constraints
1≤T≤100

1≤n≤1000

−106≤arr[i]≤106

Sample Input 1

4
5
1 2 2 3 6
5
1 3 5 4 7
6
1 1 1 1 1 1
4
3 1 1 2

Sample Output 1

2
2
6
2*/

ll n;
  ll arr[1010];
ll cnt[1010];
ll dp[1010];
bool done[1010];

ll rec(ll level){
	
	// base case
	if(cnt[level]==1)return 1;
	
	
	// cache check;
	
	if(done[level])return dp[level];
	// compute
	
	ll ans=0;
	for(ll i=level-1;i>=0;i--){
		
		if(arr[i]<arr[level]&&cnt[i]==cnt[level]-1){
			
			ans+=rec(i);
		}
	} 
	
	
	// save and return
	done[level]=true;
	return dp[level]=ans;
	
}


void solve(){
	
	cin>>n;
	for(ll i=0;i<n;i++){
		
		cin>>arr[i];
	}
	
	std::vector<ll>ans;
	
	memset(done,0,sizeof(done));
	
	for(ll i=0;i<n;i++){
		
		if(ans.empty()||ans.back()<arr[i]){
			ans.push_back(arr[i]);
			cnt[i]=ans.size();
			
	}else{
		
		auto it=lower_bound(ans.begin(),ans.end(),arr[i]);
		*it=arr[i];
		cnt[i]=it-ans.begin()+1;
		
	}
	}
	
	ll result=0;
	for(ll i=0;i<n;i++){
		
		if(cnt[i]==ans.size()){
			
			result+=rec(i);
		}
	}
	
	
	cout<<result<<nl;

}

//editorial code 

void solve() {
    ll n, lis = 1;
    cin >> n;
    vector<ll> nums(n), dp(n + 1, 0), cnt(n + 1, 0);
    for (int i = 0; i < n; i++)cin >> nums[i];
    for (int i = 0; i < n; i++) {
        cnt[i] = 1;
        auto &ans = dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (nums[j] < nums[i]) {
                if (ans < dp[j] + 1)ans = dp[j] + 1, cnt[i] = cnt[j];
                else if (ans == dp[j] + 1)cnt[i] += cnt[j];
            }
        }
        lis = max(lis, dp[i]);
    }
    ll ans = 0;
    for (int i = 0; i < n; i++)if (lis == dp[i])ans += cnt[i];
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


/*Hard Problem

Time-Limit: 6 sec Score: 1.00/100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Description

You are given a string S with length N. Each character is assigned a 
cost for removing it. Find the minimum cost for removing characters 
such that it does not contain any subsequence ‘hard’.


Input Format

The first line of the input contains one integer T -
 the number of test cases. Then T test cases follow.

The first line of each test case contains one integer N 
- the length of the array. 

The second line of each test case contains a string S.

The third line of each test case contains N space-separated 
integers - the cost of removing a character.


Output Format

For each test case, print the minimum cost for removing characters 
such that it does not contain any subsequence ‘hard’.


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
/*Define DP array, DP[4] where DP[i] denotes the cost of not being able
 to form a prefix of length i of ‘hard’.


Iterate through the given string, if we encounter any character of ‘hard’, 
we have two choices, remove the current character or remove the previous 
character (in case of ‘h’, there is no previous character).


Iterate through the given string, if we encounter any character j of ‘hard’,
 we have two choices and we take the minimum of the two. You can remove the 
 current character, which will make your cost DP[j] + A[i] or you can remove
  the previous character, which will make your cost DP[j-1].

Time Complexity per test case: O(N)


*/

/*Count of Binary Strings

Time-Limit: 1 sec Score: 1.00/100
Difficulty : *
 Memory: 256 MB Accepted Submissions: 100
Description

Find the number of binary strings of length n where “0100” is not
 present as a substring.


Input Format

The first line of the input contains one integer t - the number of 
test cases. Then t test cases follow.

The first and only line of each test case contains an integer n.


Output Format

For each test case, print the number of binary strings of length n where
 “0100” is not present as a substring mod 10^9+7.


Constraints

1 ≤ t ≤ 106

1 ≤ n ≤ 106 where n is the length of the string.


Sample Input 1

3
3
4
5

Sample Output 1

8
15
28

Note

For the first test case, n = 3, so “0100” cannot be a substring.

For the second test case, there are total 24 = 16 substrings out of which 
“0100” is a substring. So, the answer is 16-1 = 15.*/

string str="0100";

ll n;

ll dp[1001000][8];

ll rec(ll level,ll match){
	
	//pruning
	
	if(match==4)return 0;
	
	// basecase
	
	if(level==0)return 1;
	
	//cache check
	if(dp[level][match]!=-1)return dp[level][match];
	
	
	// compute
	
	ll ans=0;
	
	if(match==0){
		
		ans=rec(level-1,0)%mod+rec(level-1,1)%mod;
		
	}else if(match==1){
		
		ans=rec(level-1,1)%mod+rec(level-1,2)%mod;
		
	}else if(match==2){
		
		ans=rec(level-1,3)%mod+rec(level-1,0)%mod;
		
	}else if(match==3){
		
		ans=rec(level-1,4)%mod+rec(level-1,2)%mod;
		
	}
	
	
	// save and return
	
	return dp[level][match]=(ans%mod);

	
}

void solve(){
	
	cin>>n;
	cout<<rec(n,0)<<nl;
	
}

//editorial code 

const int mod = 1e9 + 7;

int pw(int a,int b,int p){
   if(b==0)return 1;
   int t=pw(a,b/2,p);
   t=(t*t)%p;
   if(b%2)return (a*t)%p;
   return t;
}
int dp[1000001][5];
signed main(){
   ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
       dp[0][0] = 1;
       for (int i = 1; i <= 1000000; ++i) {
           for (int j = 0; j <= 4; ++j) {
               // 0100
               vector<int> v;
               if(j == 0) {
                   v = {0, 2};
               }
               else if(j == 1) {
                   v = {0,1};
               }
               else if(j == 2) {
                   v = {1, 3};
               }
               else if(j == 3) {
                   v = {2};
               }
               else {
                   v = {3, 4, 4};
               }
               for (int k:v) {
                   dp[i][j] = (dp[i][j] + dp[i-1][k])%mod;
               }
           }
       }
   int t;
   cin >> t;
   while(t--) {
       int n;
       cin>>n;
       cout << (pw(2,n,mod) - dp[n][4] + mod)%mod << "\n";
   }
   return 0;
}

/*approach
The total number of binary strings of length n is 2n. Find the number
 of binary strings where “0100” is present as a string and subtract it from 2n.


Define dp[i][j] which is the number of binary strings if the current string
 is of i characters and it matches first j characters of “0100”.


Consider all the cases from j = 0 to j = 4. Use String Matching with Finite 
Automata to find the DP transitions. At index i, the values for dp[i-1][j], 
0 ≤ j ≤ 4 would be known already. The final answer would be dp[n][4].

Time Complexity per test case: O(n)


*/


/*Maximum Product Subarray

Time-Limit: 1 sec Score: 1.00/100
Difficulty : ***
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

Given an integer array nums, find a contiguous non-empty subarray
 within the array that has the largest product and return the product.

The test cases are generated so that the answer will fit in a 64-bit integer.

A subarray is a contiguous subsequence of the array.


Input Format

First-line contains 
T
 - the number of test cases.
The first line of each test case contains 
n
 - the size of the array.
The second line of each test case contains 
n elements of the array nums
.


Output Format

For each test case, print the maximum subarray product on a new line.


Constraints

1≤T≤100

1≤n≤105

−10≤nums[i]≤10

The test cases are generated so that the answer will fit in a 64-bit integer.


Sample Input 1

3
4
2 3 -2 4
3
-2 0 -1
1
-10

Sample Output 1

6
0
-10*/

long long dp1[100100], dp2[100100];
long long rec2(long long);


long long rec1(long long level){
    if(level < 0) return 1;
    
    if(dp1[level] != -1) return dp1[level];
    
    long long ans = -3e9;
    
    ans = max(a[level]*rec1(level-1), a[level]);
    ans = max(a[level]*rec2(level-1) ,ans);
    
    return dp1[level] = ans;
    
}

long long rec2(long long level){
    if(level < 0) return 1;
    
    if(dp2[level] != -1) return dp2[level];
    
    long long ans = -3e9;
    
    ans = min(a[level]*rec2(level-1), a[level]);
    ans = min(ans, a[level]*rec1(level-1));
    
    return dp2[level] = ans;
    
}

void solve(){
    
    cin >> n;
    
    a.resize(n);
    
  
    memset(dp1, -1, sizeof(dp1));
    memset(dp2, -1, sizeof(dp2));
    
    
    for(long long i = 0; i < n; i++){
        cin >> a[i];
    }
    
    long long ans = -3e9;
    
   
    for(long long i = 0; i < n; i++){
        ans = max(ans, rec1(i));
        
    }
    
    cout << ans << '\n';
    a.clear();
}

//editorial code 

ll maxProduct(vector<ll>& nums) {
    ll n = nums.size(), ans = LLONG_MIN, mx = 1, mn = 1;
    for (int i = 0; i < n; i++) {
        ll t = mn;
        mn = min({nums[i], mn*nums[i], mx*nums[i]});
        mx = max({nums[i], mx*nums[i], t*nums[i]});
        ans = max(ans, mx);
    }
    return ans;
}
void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)cin >> a[i];
    cout << maxProduct(a) << endl;
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


/*Word Break

Time-Limit: 2 sec Score: 1.00/100
Difficulty : ***
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

Given a string 
s
 and a dictionary of strings words
, output "Yes" if 
s can be segmented into a space-separated sequence of 
one or more dictionary words
, else output "No".

Note that the same word in the dictionary may be reused multiple times in the segmentation.


Input Format

First-line contains 
T
 - the number of test cases.
The first line of each test case contains 
n
 - the size of the dictionary words
.
The second line of each test case contains string s
.
The next n  lines of each test case contain 
n words of the dictionary words

.


Output Format

For each test case, output "Yes" if 
s
 can be segmented into a space-separated sequence of one or more dictionary 
words
, else output "No".


Constraints

1≤T≤1000

1≤n≤1000

1≤|s|≤300

1≤words[i].length()≤20

Sum of |s|over all test cases is ≤ 3×104
.


Sample Input 1

3
6
ilikealgozenith
algozenith
love
like
i
you
algo
2
applepenapple
apple
pen
3
mississippi
miss
ippi
sis

Sample Output 1

Yes
Yes
No

Note

for test 1, ilikealgozenith -> i + like + algozenith .*/

ll n;
string s;
map<string,ll>dict;

ll dp[310];



bool rec(ll level){
	
	// pruning 
	
	// basecase
	
	if(level==s.size())return 1;
	
	
	// cache check 
	
	if(dp[level]!=-1)return dp[level];
	
	// compute 
	
	bool ans=false;
	
	for(ll end=level;end<s.size();end++){
		
		string sub=s.substr(level,end-level+1);
		
		if(dict.find(sub)!=dict.end()){
			
			ans|=rec(end+1);
		}
		
	}
	
	// save and return 
	
	return dp[level]=ans;
	
	
	}
void solve(){
	
	cin>>n;
	cin>>s;
	
	dict.clear();
	for(ll i=0;i<n;i++){
		
		string word;
		cin>>word;
		dict[word]++;
		
		
	}
	
	memset(dp,-1,sizeof(dp));
	if(rec(0))cout<<"Yes"<<nl;
	else cout<<"No"<<nl;
}


/*Mountain Array II

Time-Limit: 1 sec Score: 1.00/100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

You may recall that an array arr
 is a mountain array if and only if:
arr.length≥3
There exists some index 
i
 (
0
-indexed) with 
0<i<arr.length−1 such that:
arr[0]<arr[1]<...<arr[i−1]<arr[i]
arr[i]>arr[i+1]>...>arr[arr.length−1]Given an integer array, 
output the minimum number of elements to remove to make arr  a mountain array.
If mountain array is not possible, output -1.


Input Format

First-line contains 
T
 - the number of test cases.
First-line of each test case contains 
n
 - the length of the array arr
.
Second-line of each test case contains 
n
 elements of array arr
.


Output Format

For each test case, output the minimum number of elements to remove to make arr 
a mountain array.
If mountain array is not possible, output -1.


Constraints

1≤T≤1000
1≤n≤104
1≤arr[i]≤106

Sample Input 1

3
3
1 5 1
8
2 1 1 5 6 2 3 1
5
1 2 3 4 5

Sample Output 1

0
3
-1*/

ll n;

ll arr[10100];

ll lis_lr[10100], lis_rl[10100];

void solve(){
	cin>>n;
	for(ll i=0;i<n;i++){
		cin>>arr[i];
	}

	vector<ll> temp;
	for(ll i=0;i<n;i++){
		auto it = lower_bound(temp.begin(), temp.end(), arr[i]);
		if(it == temp.end())
			temp.pb(arr[i]);
		else
			*it = arr[i];
		lis_lr[i] = temp.size();
	}

	temp.clear();
	for(ll i=n-1;i>=0;i--){
		auto it = lower_bound(temp.begin(), temp.end(), arr[i]);
		if(it == temp.end())
			temp.pb(arr[i]);
		else
			*it = arr[i];
		lis_rl[i] = temp.size();
	}

	ll ans = 0;
	for(ll i=0;i<n;i++){
		if(lis_lr[i] > 1 && lis_rl[i] > 1)
			ans = max(ans, lis_lr[i] + lis_rl[i] - 1);
	}

	if(ans >= 3)
		cout<<n-ans<<nl;
	else
		cout<<-1<<nl;
}

//editorial code 

void solve() {
    int n, ans = 0;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)cin >> nums[i];
    vector<int> dp1(n), dp2(n), lis, lds;
    for (int i = 0; i < n; i++) {
        auto it = lower_bound(lis.begin(), lis.end(), nums[i]);
        if (it != lis.end())*it = nums[i], dp1[i] = (it - lis.begin()) + 1;
        else lis.push_back(nums[i]), dp1[i] = lis.size();
    }
    for (int i = n - 1; i >= 0; i--) {
        auto it = lower_bound(lds.begin(), lds.end(), nums[i]);
        if (it != lds.end())*it = nums[i], dp2[i] = it - lds.begin() + 1;
        else lds.push_back(nums[i]), dp2[i] = lds.size();
        if (dp1[i] >= 2 && dp2[i] >= 2)ans = max(ans, dp1[i] + dp2[i] - 1);
    }
    if (ans == 0)cout << -1 << endl;
    else cout << n - ans << endl;
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


/*Rock Paper Scissor

Time-Limit: 5 sec Score: 0.00/100
Difficulty : ***
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

Shubham and Vivek have planned to play 
N
 games of Rock-Paper-Scissor. Vivek has already decided upon the sequences of his 
N
 moves. He told his sequence to Shubham and challenged him.

Given a sequence of length 
N
 of Vivek’s moves, Help Shubham to find a sequence of moves that 
 give him the maximum number of wins among 
N
 games, provided that he can only change his current move w.r.t his previous move at most 
K
 times among all 
N
 Moves.

Out of all optimal sequences of moves, print the lexicographically smallest one.


Input Format

First-line contains 
T
 - the number of test cases.
First line of each test case contains 
2
 integers 
N
 and 
K
.
Second-line of each test case contains the string 
S
.


Output Format

For each test case, output the maximum number of wins possible, 
and on the next line, print the lexicographically smallest sequences 
of moves required for the maximum wins.


Constraints

1≤T≤50
1≤N≤1000

0≤K≤1000

String 
S can only have ‘R’, ‘P’and,‘S’characters.


Sample Input 1

4
6 2
RPSSPR
6 3
SRRRRR
6 0
RPSRPS
6 1
PSSPPS

Sample Output 1

4
PPRRPP
6
RPPPPP
2
PPPPPP
4
RRRSSS*/



#include <bits/stdc++.h>
using namespace std;

#define ll int64_t
#define endl '\n'

int n, k;
string s; // PRS
int dp[1001][1001][3], a[1001];
int rec(int i, int cnt, int p) {
    if (i == n)return 0;
    auto &ans = dp[i][cnt][p];
    if (ans != -1)return ans;
    ans = rec(i + 1, cnt, p) + (((p + 1) % 3) == a[i]);
    for (int j = 0; j < 3; j++) {
        if (j != p && cnt < k) {
            ans = max(ans, rec(i + 1, cnt + 1, j) + (((p + 1) % 3) == a[i]));
        }
    }
    return ans;
}
void solve() {
    cin >> n >> k;
    string s;
    cin >> s;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'P')a[i] = 0;
        if (s[i] == 'R')a[i] = 1;
        if (s[i] == 'S')a[i] = 2;
    }
    memset(dp, -1, sizeof(dp));
    int cnt = 0, p = 0, ans2;
    int ans = rec(0, 0, 0);
    if (ans < rec(0, 0, 1))ans = rec(0, 0, 1), p = 1;
    if (ans < rec(0, 0, 2))ans = rec(0, 0, 2), p = 2;
    cout << ans << endl;
    assert(ans > 0);
    ans2 = ans;
    string moves;
    // getting lexicologically smallest.
    for (int i = 0; i < n; i++) {
        if (cnt + (p != 0) <= k && ans == rec(i, cnt + (p != 0), 0)) {
            if (i && p != 0)cnt++;
            p = 0;
            moves.push_back('P');
            if (a[i] == 1)ans--;
        }
        else if (cnt + (p != 1) <= k && ans == rec(i, cnt + (p != 1), 1)) {
            if (i && p != 1)cnt++;
            p = 1;
            moves.push_back('R');
            if (a[i] == 2)ans--;
        }
        else if (cnt + (p != 2) <= k && ans == rec(i, cnt + (p != 2), 2)) {
            if (i && p != 2)cnt++;
            p = 2;
            moves.push_back('S');
            if (a[i] == 0)ans--;
        }
        else {
            assert(false);
        }
    }
    cout << moves << endl;

    // verify.
    assert(moves.size() == n);
    assert(ans == 0);
    char prev = moves[0];
    int cnts = 0;
    for (int i = 0; i < n; i++) {
        if (moves[i] == 'P' && a[i] == 1)ans2--;
        if (moves[i] == 'R' && a[i] == 2)ans2--;
        if (moves[i] == 'S' && a[i] == 0)ans2--;
        if (moves[i] != prev)cnts++;
        prev = moves[i];
    }
    assert(cnts <= k);
    assert(ans2 == 0);
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


/*aproach

Use dynamic programming


The solution uses dynamic programming to determine the maximum score
 that Shubham can achieve and to extract a string representing the
  optimal sequence of moves that Shubham should make. The dp state 
  dp[level][cnt][choice] represents the maximum score possible if 
  Shubham chooses to move choice in the level'th round, he has cnt 
  changes left, and we are considering rounds from level to N-1. If
   Shubham chooses to change his move, he can only do so a limited 
   number of times (cnt). Therefore, we decrement cnt when Shubham 
   decides to change his move.


Transitions can be in the following way:
Lets say the current choice is 2
dp[level][cnt][choice] = (if_Shubham_wins?1:0) + max({rec(level + 1, cnt-1, 1), 
rec(level + 1, cnt, 2), rec(level + 1, cnt - 1, 3)});

Whenever the choice changes in the next chance we reduce the cnt value by 1
 because now we can make one less change.

Time complexity for each test case : O(#states * transitions) = 
O(9NK)*/


//remaining problems : Kadane Twist
/*Max Score: 100
2. Palindromic Paths
Max Score: 100
3. Jenga Tower
Max Score: 100 */


//additon some exta questions....



// calculate size of lis ...using form 2 ...timecomplexity=o(n^2);
int n;
int arr[1001];
int dp[1001];

int rec(int level){  // best lis() ending at level from [1--------level]
    
    // pruning
    if(level<0) return 0;
    //base case 
    //cached check
    
    
    if(dp[level]!=-1)return dp[level];
    
    //transisition
    
    int ans=1;
    for(int prev_taken=0;prev_taken<level;prev_taken++){
        
        if(arr[prev_taken]<arr[level]){
            
            ans=max(ans,1+rec(prev_taken));
        }
        
        
    }
    //save and return 
    
    //return ans;
    return dp[level]=ans;
    
    
    
    
}


void solve(){
    
    
    cin>>n;
    for(int i=0;i<n;i++){
        
        cin>>arr[i];
        
    }
    
    memset(dp,-1,sizeof(dp));
    
    int best=1;
    for(int i=0;i<n;i++){
        
        best=max(best,rec(i));
        
    }
    
    cout<<best<<nl;
    
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    // int _t; cin>>_t;while(_t--)
        solve();
    
    
    //cerr<<"Time elapsed: "<< 1.0*clock()/ CLOCKS_PER_SEC << "s.\n\n";
    
    
    
    
}
