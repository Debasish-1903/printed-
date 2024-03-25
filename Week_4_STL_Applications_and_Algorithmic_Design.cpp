/*Support Queries II⭐

Time-Limit: 1 sec Score: 50.00/100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

Design a Data Structure which can support the following queries:

Initially, the structure is empty. You have given an integer K. 

The structure is arranged in the order from greater elements to smaller 
elements. So when we say top K elements, we mean the top K largest elements.

1 x: Add x in structure.

2 x: Remove x from the structure if present in the structure. If x doesn't 
present in the structure, do nothing. If there are multiple occurrences of x,
 delete only one occurrence of x.

3 ?: Print the sum of the top K elements. If the structure contains less than K elements,
 then print the sum of all elements present in the structure. 
 If the structure is empty, then print 0.


Input Format

The first line of input contains Q and K - the number of queries.
Next, Q lines contain queries of the format specified in the statement. 


Output Format

For queries of type 3, print the answer in a new line.


Constraints

1 ≤ Q, K ≤ 105
0 ≤ x ≤ 109


Sample Input 1

17 3
1 5
1 2
1 3
1 6
3 ?
2 3
3 ?
2 2
3 ?
2 2
3 ?
2 5
3 ?
2 5
3 ?
2 6
3 ?

Sample Output 1

14
13
11
11
6
6
0*/

void solve() {
    int q, k;
    cin >> q >> k;
    ll sum = 0;
    
    multiset<int> m1;
    multiset<int, greater<int>> m2;

    for (int i = 0; i < q; i++) {
        int x;
        cin >> x;

        if (x == 1) {
            int y;
            cin >> y;
            if (m1.size() < k) {
                m1.insert(y);
                sum += y;
            } else if (m1.size() == k) {
                m1.insert(y);
                sum += y;

                auto it = m1.begin();
                sum -= *it;
                m2.insert(*it);
                m1.erase(it);
            }
        } else if (x == 2) {
            int y;
            cin >> y;
            if (m2.find(y) != m2.end()) {
                m2.erase(m2.find(y));
            } else if (m1.find(y) != m1.end()) {
                m1.erase(m1.find(y));
                sum -= y;
                if (m1.size() == k - 1 && !m2.empty()) {
                    auto itr = m2.begin();
                    m1.insert(*itr);
                    sum += *itr;
                    m2.erase(itr);
                }
            }
        } else if (x == 3) {
            char ch;
            cin >> ch;
            if (ch == '?') cout << sum << nl;
        }
    }
}

/*Alice and Books  ⭐

Time-Limit: 10 sec Score: 1.00/100
Difficulty : ***
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

Alice read N books. The i-th book has Ai pages. After every book Alice reads, 
you have to tell the largest integer B such that Alice has read B books
 that have at least B pages.


Input Format

The first line of the input contains one integer T -
 the number of test cases. Then T test cases follow.
The first line of each test case contains one integer N - 
the length of the array. 
The second line of each test case contains
 N space-separated integers.


Output Format

For each test case, print N integers, A1, A2, ... AN, where Ai is the largest 
integer B such that Alice has read B books that have at least B pages
 after reading the i-th book.


Constraints

1≤ T ≤ 100
1≤ N ≤ 105
1≤ Ai ≤ 105


Sample Input 1

4

4

2 1 4 4

2

5 1

5

1 3 2 3 5

4

3 3 3 3


Sample Output 1

1 1 2 2

1 1

1 1 2 2 3

1 2 3 3


Note

In the first test case of the example, Alice reads N=4 books.
After reading the 1st book, she has read 1 book with at least 1 page i.e.
 book with page 2.
After reading the 2nd book, the answer remains the same as she has read 1 
book with at least 1 page.
After reading the 3rd book, she has read 2 books with at least 2 pages i.e.
 book with pages 2 and 4.
After reading the 4th book, the answer remains the same as she has read 2
 books with at least 2 pages.

In the third test case of the example, Alice reads N=5 books.
After reading the 1st book, she has read 1 book with at least 1 page i.e.
 book with page 1.
After reading the 2nd book, the answer remains the same as she has read 1
 book with at least 1 page.
After reading the 3rd book, she has read 2 books with at least 2 pages i.e.
 book with pages 2 and 3.
After reading the 4th book, the answer remains the same as she has read 2
 books with at least 2 pages.
After reading the 3rd book, she has read 3 books with at least 3 pages i.e. 
book with pages 3,3 and 5.*/

void solve(){
    
int n;
cin>>n;


int freq[100001]={};
ll b=0;ll cnt=0;// b= no of books with pages b
//cnt = no of books present with greater than b pages==present value of cnt
    // x= book with pages x;

for(int i=0;i<n;i++){
    
    int x;
    cin>>x;
    freq[x]++;
    
    if(x>b){
        cnt++;
        
    }
    if(cnt>b){
        
        b++;
        cnt-=freq[b];
    }
    
    cout<<b<<" ";
    
}
cout<<nl;
	
}

/*Largest Rectangle⭐

Time-Limit: 1 sec Score: 1.00/100
Difficulty : **
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

You have to find the largest rectangular area possible in a given histogram 
where the largest rectangle can be made of contiguous bars.
 Assume that all bars have the same width and the width is 1 unit.


Input Format

The first line of the input contains one integer T - 
the number of test cases. Then T test cases follow.
The first line of each test case contains one integer N -
 the length of the array. 
The second line of each test case contains N space-separated integers,
 where Hi denotes the height of the ith bar.


Output Format

For each test case, print the largest area of the rectangle in the histogram.


Constraints

1≤ T ≤ 100
1≤ N ≤ 105
1≤ Hi ≤ 105


Sample Input 1

3
3
2 1 2
4
1 2 3 4
4
5 4 1 2

Sample Output 1

3
6
8

Note

For the first test case, take all the histograms to get area as 3*1 = 3


For the second test case, take the last two histograms to get area as 2*3 = 6


For the third test case, take the first two histograms to get area as 2*4 = 8


*/
int main() {
    IOS
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        stack<int> s;
        int i = 0;
        long long ans = 0;
        while (i < n) {
            if (s.empty() || a[i] >= a[s.top()]) {
                s.push(i);
                i++;
            }
            else {
                int t = s.top();
                s.pop();
                if (s.empty()) {
                    ans = max(ans, 1LL * i * a[t]);
                }
                else {
                    ans = max(ans, 1LL * a[t] * (i - s.top() - 1));
                }
            }
        }
        while (!s.empty()) {
            int t = s.top();
            s.pop();
            if (s.empty()) {
                ans = max(ans, 1LL * i * a[t]);
            }
            else {
                ans = max(ans, 1LL * a[t] * (i - s.top() - 1));
            }
        }
        cout << ans << "\n";
    }
    return 0;
}

/*approach
Height of the largest rectangle will be one of the heights of the histogram. We can 
iterate through all the histograms, and for each histogram H, we try to create 
the maximum rectangle with H as the height.


Consider 2 consecutive histograms H[i] and H[i+1]. When H[i+1] < H[i], for all
 histograms X with index > i + 1 when traversing left for L, there is no point 
 looking at H[i] after looking at H[i+1]. If H[i+1] > X, then H[i] > X as we
  already know H[i] > H[i+1] Then, the next entry we would want to look at the 
  first histogram left of H[i+1] with height less than H[i+1].


We traverse all histograms from left to right, maintaining a stack of histograms. 
Every histogram is pushed to stack once. A histogram is popped from stack when
 a histogram of smaller height is seen. When a histogram is popped, we calculate
  the area with the popped histogram as the smallest histogram. The current index
   tells us the ‘right index’ R and index of the previous item in the stack 
   is the ‘left index’ L.

Time Complexity per test case: O(N)


*/

/*Diversify the Array

Time-Limit: 2 sec Score: 1.00/100
Difficulty : ***
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

You have given an array A. The diversity of the array A is defined
 as the number of pairs i, j, i < j such that Ai ≠ Aj.
You want to maximize the diversity of the array. For that, you are 
allowed to make at most K operations on it, in any of which, you can 
select a particular element and change its value to any integer in 
the range 1 to 109, both inclusive.
Find out the maximum diversity of the array that you can obtain.


Input Format

The first line will contain T, number of test cases.
 Then the test cases follow.
The first line of each test case contains two integers N, K.
 where N denotes the length of array A.
The next line of each test case contains N space-separated integers, 
the i-th of which denotes Ai.


Output Format

For each test case, output in a single line, the answer corresponding to 
the test case, which should be an integer denoting the maximum possible diversity.


Constraints

1 ≤ T ≤ 20
0 ≤ K ≤ 109
2 ≤ N ≤ 105
1 ≤ Ai ≤ 109


Sample Input 1

3
3 10
1 2 3
4 2
1 1 2 2
6 2
2 3 3 2 4 4


Sample Output 1

3
6
14


Note

Explanation 1:
Every element in the array is different. The diversity is 6,
 which is the maximum possible.

Explanation 2:
Change the array to A = [1, 3, 2, 5]. Here we only need to change
 elements at 2nd and 4th positions. Now all elements are different.
The maximum diversity is 6.

Explanation 3:
Change the array to A = [5, 6, 2, 3, 4, 4]. Here we change the elements
 at positions 1 and 2. The maximum diversity is 14.*/

void solve(){
	
	ll n,k;
	cin>>n>>k;
//	cout<<n<<k<<nl;
	
	ll temp=n;
	priority_queue<pair<ll,ll>>pq;
	
	unordered_map<ll,ll>mp;
	
	while(temp--){
	    
	    ll x;
	    cin>>x;
	    
	    mp[x]++; 
	}
	
	
	//cout<<"n is"<<n<<nl;
	
	ll ans=n*(n-1)/2;
	
//	cout<<"ans is"<<ans<<nl;
	
	
	for(auto it:mp){
	    
	    if(it.s>1){
	        
	        pq.push({it.s,it.f});
	        
	        ans-=(((it.s)*(it.s-1))/2);
	        
	    } 
	}
	
	
	while(k--){
	    
	   if(pq.empty())break;
	   
	 //  else{
	       
	      auto it=pq.top();
	      pq.pop();
	      ans+=it.f-1;
	      
	      it.f--;
	      if(it.f>1)pq.push(it);
	    
	 //  } 
	    
	}
	
	
	
	cout<<ans<<nl;
	
	
	
	
	
	
	
	
}

/*
approach
Note that we can change any number to any number in between 1 to 109. 
And the max size of the array is 105.
That means in the best case, it's always possible to make all elements 
distinct (obviously when K is sufficiently large).

Let cnti denotes the number of occurrence of i in the array. In the current
 step, it's always better to change such i which has maximum cnti value.
Because it will add cnti-1 extra value in the current diversity.

Based on these observations we can design our algorithm using a priority queue.

Enumerate cnti structure, where cnti denotes the count of occurrence of i in the array.
In the current step, change the value of number i such that cnti is maximum. Update cnti,
 i.e., cnti--. Note that we have sufficiently large non-occurred numbers available 
 because the max size of the array is 105, and allowed-change varies from 1 to 109.
Do step 2, for K times. To find max cnti value, maintain a priority queue structure 
with pairs {cnti, i}. And arranged the priority queue structure with cnti values.
cnti values can be maintained using Map in STL C++.*/

/*Time complexity: O(NlogN)
Space complexity: O(N) extra space*/


/*Molecular Formula ⭐

Time-Limit: 1 sec Score: 1.00/100
Difficulty : ***
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

You've been given chemical formula of a compound. 
Your task is to print the count of each atom.
The atomic element always starts with an uppercase character,
 then zero or more lowercase letters, representing the name.
One or more digits representing that element's count may follow
 if the count is greater than 1. If the count is 1, no digits will follow. For example,
  H2O and H2O2 are possible, but H1O2 is impossible.
Two formulas concatenated together to produce another formula. For example,
 H2O2He3Mg4 is also a formula.
A formula placed in parentheses, and a count (optionally added) is also a formula. 
For example, (H2O2) and (H2O2)3 are formulas.

It's guaranteed that the total count of each individual atom is within INT_MAX.


Input Format

The only line of input contains a string S representing the chemical formula of a compound.


Output Format

Print the count of all elements as a string in the following form: the first name
 (in sorted order), followed by its count (if that count is more than 1), followed
  by the second name (in sorted order), followed by its count
   (if that count is more than 1), and so on.


Constraints

1 ≤ |S| ≤ 103


Sample Input 1

Mg(OH)2

Sample Output 1

H2MgO2

Sample Input 2

K4(ON(SO3)2)2

Sample Output 2

K4N2O14S4

Sample Input 3

(Ti34)10

Sample Output 3

Ti340*/


const int N = 100010;

int inf = 1e9;
int mod = 1e9 + 7;

string solve(string formula) {
    stack < pair < string, int > > s;

    for(int i = 0; i < (int)formula.length(); i++) {
        if(formula[i] == '(') {
            s.push({"(", -1});
        }
        else if(formula[i] == ')') {
            int multiplier = 0;
            while(i + 1 < (int)formula.length() && formula[i + 1] >= '0' && formula[i + 1] <= '9') {
                multiplier *= 10;
                multiplier += formula[i + 1] - '0';
                i++;
            }
            if(!multiplier) multiplier = 1;

            stack < pair < string, int > > temp;

            while(!s.empty()) {
                auto it = s.top();
                s.pop();
                if(it.first == "(") break;
                temp.push({it.first, it.second * multiplier});
            }

            while(!temp.empty()) {
                s.push(temp.top());
                temp.pop();
            }
        }
        else if(formula[i] >= 'A' && formula[i] <= 'Z') {
            string atom = "";
            atom += formula[i];
            while(i + 1 < (int)formula.length() && formula[i + 1] >= 'a' && formula[i + 1] <= 'z') {
                atom += formula[i + 1];
                i++;
            }

            int cnt = 0;
            while(i + 1 < (int)formula.length() && formula[i + 1] >= '0' && formula[i + 1] <= '9') {
                cnt *= 10;
                cnt += formula[i + 1] - '0';
                i++;
            }

            if(!cnt) cnt = 1;

            s.push({atom, cnt});
        }
    }

    map < string, int > M;

    while(!s.empty()) {
        M[s.top().first] += s.top().second;
        s.pop();
    }

    string ans = "";

    for(auto it : M) {
        ans += it.first;
        if(it.second > 1) ans += to_string(it.second);
    }

    return ans;
}


/*Rain Water⭐

Time-Limit: 1 sec Score: 100.00/100
Difficulty : **
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

You are given an array A, where each ith index represents an elevation on
 that index. The width of each bar is 1. You have to compute how much 
 water it is able to trap after raining.


Input Format

The first line of the input contains one integer T - the number of test cases. 
Then T test cases follow.
The first line of each test case contains one integer N - the length of the array. 
The second line of each test case contains N space-separated integers, where Ai
 denotes the height of the ith bar.


Output Format

For each test case, you have to print how much water it is able to trap after raining.


Constraints

1 ≤ T ≤ 100
1 ≤ N ≤ 105
0 ≤ Ai ≤ 105


Sample Input 1

3
3
3 0 2
5
2 0 0 4 3
5
1 2 3 1 5

Sample Output 1

2
4
2

Note

For the first test case:


For the second test case:


For the third test case:

*/

void solve(){
    
    ll n;
    cin>>n;
    
    ll arr[n];
    for(ll i=0;i<n;i++){
        
        cin>>arr[i];
    }
    
    stack<ll>st;
    
    ll ans=0;
    
    for(ll i=0;i<n;i++){
        
        
        
        while(!st.empty()&&arr[st.top()]<arr[i]){
            

            ll pop_hieght=arr[st.top()];
            st.pop();
            
            
            
            if(st.empty())break;
            
            
            ll dist=i-st.top()-1;
           
           
            ll min_hieght=min(arr[st.top()],arr[i])-pop_hieght; 
            
            
            ans+=dist*min_hieght;  
        }
      
        st.push(i);
    
    }
    
    cout<<ans<<nl;
 	
}

/*Reduce the Array AZ101

Time-Limit: 1 sec Score: 100.00/100
Difficulty : *
 Memory: 256 MB Accepted Submissions: 100
Description

You are given an array of N integers. In one operation, remove any two elements
 in the array and add their sum to the array. The cost of this operation will be 
 the sum of the two elements. Print the minimum cost till the size of the
  array does not become 1.


Input Format

The first line of the input contains one integer T - the number of test cases. 
Then T test cases follow.

The first line of each test case contains one integer N - the length of the array. 

The second line of each test case contains N space-separated integers.


Output Format

For each test case, print the minimum cost till the size of the array does not become 1.


Constraints

1≤ T ≤ 106

1≤ N ≤ 106

1≤ Ai ≤ 109

It is guaranteed that the sum of N over all test cases does not exceed 106.


Sample Input 1

3
4
3 1 4 2
3
1 1 1
4
2 3 1 3

Sample Output 1

19
5
18

Note

For the first test case, take 5 and 6 to get sum (5+6) = 11

For the second test case, take 1 and 1, array becomes [2, 1] and
 then take 2 and 1 to get sum (1+1) + (2+1) = 5

For the third test case, take 1 and 2, array becomes [3, 3, 3] and then take 3 and 3, 
array becomes [6, 3] and then take 6 and 3 to get sum (1+2) + (3+3) + (6+3) = 18*/


void solve(){
	
	ll n;
	cin>>n;
	
	priority_queue<ll,vector<ll>,greater<ll>>pq;
	
	while(n--){
	    
	    ll x;
	    cin>>x;
	    pq.push(x);
	    
	    
	}
	ll ans=0;
	
	while(pq.size()!=1){
	    ll top1=pq.top();
	    pq.pop();
	    ll top2=pq.top();
	    pq.pop();
	    
	    ans+=top1+top2;
	    
	    pq.push(top1+top2);
	    
	    
	}
	
	
	cout<<ans<<nl;
	
	
}
//Time Complexity per test case: O(N log N)


/*Rebuild Original Array⭐

Time-Limit: 4 sec Score: 1.00/100
Difficulty : ***
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

Your class teacher wrote N integers on the board. One of your classmates
 was being mischievous, he replaced the N integers with all possible subset
  sums of the array when the teacher was not in the class. 
Suppose that the integers on the board were [2,1] then the subsets will be:
 {}, {2}, {1}, {2,1} and the subset sums will be: {0,2,1,3}. 
Your task is to rebuild the original array given by your teacher.


Input Format

The first line of the input contains one integer T - 
the number of test cases. Then T test cases follow.
The first line of each test case contains one integer N - 
the number of elements in the initial array.
The second line of each test case contains 2N space-separated
 integers, the new values on the board.


Output Format

For each test case, print N space-separated integers in non-decreasing order.
It is guaranteed that a solution always exists.


Constraints

1 ≤ T ≤ 50
1 ≤ N ≤ 15
0 ≤ Ai ≤ 1015


Sample Input 1

3
2
0 1 2 3
3
0 1 3 4 5 6 8 9
3
0 1 1 1 2 2 2 3

Sample Output 1

1 2 
1 3 5 
1 1 1

Note

In the first test case of the example, the original array is [1,2] which has
 the following subset - {}, {1}, {2}, {1,2}. Their respective sums are 0,1,2,3.

In the third test case of the example, the original array is [1,1,1] which has
 the following subset - {}, {1}, {1}, {1}, {1,1}, {1,1}, {1,1}, {1,1,1}. 
 Their respective sums are 0,1,1,1,2,2,2,3.*/

void solve(){
  multiset<int> allnum;
  int n;
  cin>>n;
  int k=1<<n;
  for(int i=0;i<k;i++){
    int x;
    cin>>x;
    allnum.insert(x);
  }
  vector<int> original;
  multiset <int> generated;
  generated.insert(0);
  allnum.erase(allnum.find(0));
  while(!allnum.empty()){
    int small=*allnum.begin();
    original.push_back(small);
    vector <int> newgen;
    for(auto v:generated){
      newgen.push_back(small+v);
    }
    for(auto v:newgen){
      allnum.erase(allnum.find(v));
      generated.insert(v);
    }
  }
  for(int i=0;i<n;i++){
    cout<<original[i]<<" ";
  }
  cout<<"\n";
}
signed main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);
  int t;
  cin>>t;
  while(t--){
    solve();
  }
}

//Time Complexity: O(N*2^N)


//editorial code 

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define rep(i,s,f) for(i=s;i<f;i++)
#define print(v) for(auto &z:v) cout<<z<<' ';cout<<'\n'
#define db cout<<"db: "
#define pb push_back
#define pii pair<int,int>
#define F first
#define S second
#define B begin()
#define E end()
#define all(v) v.B,v.E
#define sz(v) (int)((v).size())
#define vi vector<int>
#define vii vector<pair<int,int>>
#define boost ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define clk1 clock_t start_time=clock()
#define clk2 cout<<(clock()-start_time)/(double)CLOCKS_PER_SEC
#define clean(arr) memset(arr,0,sizeof(arr))
#define mod 1000000007
#define mod2 998244353
#define space 100005
//<<fixed << setprecision(9)

int main()
{
    ll n,i,j,t;
    boost;

    cin>>t;
    while(t--)
    {
        cin>>n;
        ll m = 1<<n;
        // there are 2^n numbers
        ll arr[m];
        rep(i,0,m)
            cin>>arr[i];
        // take input
        sort(arr,arr+m);
        // sorting the numbers as per logic.

        map<ll,ll> sums;// stores the possible sums as of now and their frequency

        sums[0]=1;// 0 can be generated as of now 

        vi ans;
        vector<ll> subsums; // subset sums that can be created

        rep(i,0,m){
            if(sums[arr[i]]){
                sums[arr[i]]--; // this can be created so skip this once and 
            }
            else{                
                ans.pb(arr[i]); // creates the final array, freq is 0, so needed.
                vector<ll> temp; // new subset sums that can be created.
                for(auto &z:subsums) // with all the previous 
                    temp.pb(z+arr[i]), sums[z+arr[i]]++; // Merging previous subset
                    // sums with this elements and increase their generated frequency.
                for(auto &z:temp)
                    subsums.pb(z); 
                 // add the newly generated ones to the subset sums that are generated.
                subsums.pb(arr[i]); // also add this single element set (merging with 0).
            }
        }
        print(ans); // print the final generated numbers.
    }

    return 0;
}


/*Super Minimum Sum⭐

Time-Limit: 1 sec Score: 50.00/100
Difficulty : **
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

You have given an array A of size N. A1, A2, ..., AN are the elements of the array. 
All elements in the array A are distinct.
Find the sum of the minimum of all subarrays possible of array A.

A subarray of an -element array is an array composed from a 
contiguous block of the original array's elements


Input Format

The first line contains T, the number of test cases.
The first line of each test case contains N, the number of integers in an array A.
The second line of each test case contains N space-separated integers A1, A2, ..., AN.


Output Format

For each test case, print a single number representing the 
sum of the minimum of all subarrays of A.


Constraints

1 ≤ T ≤ 100000
1 ≤ N ≤ 100000
1 ≤ Ai ≤ 106
Sum of N over all test cases ≤ 5 * 105.
It is guaranteed that all elements in an array A are distinct.


Sample Input 1

5
3
1 2 3
2
1 5
4
2 3 4 10
8
1000000 1000001 1000002 1000003 1000004 1000005 1000006 1000007
3
3 1 2

Sample Output 1

10
7
35
36000084
9

Note

Explanation 1:
Min{1} + Min{1, 2} + Min{1, 2, 3} + Min{2} + Min{2, 3} + Min{3} =
 1 + 1 + 1 + 2 + 2 + 3 = 10

Explanation 2:
Min{1} + Min{1, 5} + Min{5} = 1 + 1 + 5 = 7*/

// Function to find the sum of the minimum of all subarrays of A
ll find_sum_of_minimum_subarrays(int arr[], int n) {
    stack<int> st;
    vector<ll> left(n), right(n);

    // Find the index of the next smaller element on the left of each element
    for (int i = 0; i < n; i++) {
        while (!st.empty() && arr[st.top()] >= arr[i])
            st.pop();

        left[i] = (st.empty()) ? -1 : st.top();
        st.push(i);
    }

    while (!st.empty()) st.pop();

    // Find the index of the next smaller element on the right of each element
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && arr[st.top()] >= arr[i])
            st.pop();

        right[i] = (st.empty()) ? n : st.top();
        st.push(i);
    }

    ll sum = 0;

    // Calculate the sum of the minimums of all subarrays
    for (int i = 0; i < n; i++) {
        sum += arr[i] * (i - left[i]) * (right[i] - i);
    }

    return sum;
}

void solve() {
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    ll result = find_sum_of_minimum_subarrays(arr, n);
    cout << result << nl;
}

/*approach
Try to think for the Individual Elements Contribution to the Final answer.
 How may subarrays will some element Ai be a minimum of in total?


Find the next smaller and just previous smaller elements for all elements 
in the array. How to find them? Use stack!


We try to find the individual contribution of all elements in the array. 
Suppose cnti is the number of subarrays with Ai is the minimum.
Then the answer will be the sum of all cnti * Ai. So now the question is 
how to find cnti?
Create a new array B by appending -INF at the beginning and end of the array A.
B = {-INF, A1, A2, ..., AN, -INF}.
Now for newly constructed array B find the next smaller and the previous smaller 
for each element Bi s.t. 2 ≤ i ≤ N+1 (assuming array to be 1-index).
Let ni and pi be the index of next smaller and previous smaller of
 element Bi, s.t. 2 ≤ i ≤ N+1.
Now all the subarrays [start, end] with start ∈ {pi + 1, i} and end ∈ 
{i, ni - 1} has minimum value of Bi.
That means, the contribution of Bi in total sum is (i - pi) * (ni - i).
So the final answer is the sum of the contribution of all Bis.
 (Note that we are only considering 2 ≤ i ≤ N+1.)
We can find the next smaller and previous smaller in O(N) using stack.

Time complexity: O(N)
Space complexity: O(N)


*/

//editorial code
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
        int A[n + 2];
        for(int i = 1; i <= n; i++)
            cin >> A[i];
        A[0] = -inf;
        A[n + 1] = -inf;

        int prev[n + 2], nxt[n + 2];

        stack<int> s;
        s.push(0);
        for(int i = 1; i <= n; i++) {
            while(!s.empty() && A[s.top()] >= A[i])
                s.pop();
            assert(!s.empty());
            prev[i] = s.top();
            s.push(i);
        }

        while(!s.empty()) s.pop();

        s.push(n + 1);
        for(int i = n; i >= 1; i--) {
            while(!s.empty() && A[s.top()] >= A[i])
                s.pop();
            assert(!s.empty());
            nxt[i] = s.top();
            s.push(i);
        }

        ll ans = 0;

        for(int i = 1; i <= n; i++)
            ans += 1LL * A[i] * (i - prev[i]) * (nxt[i] - i);

        cout << ans << "\n";
    }
    return 0;
}


/*Min Stack⭐

Time-Limit: 1 sec Score: 100.00/100
Difficulty : **
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

Implement a stack that supports the following operations.

push x -- Push element x onto stack.
pop -- Remove the element on top of the stack, if the stack 
is non-empty. Otherwise do nothing.
top -- Print the top element, if the stack is non-empty. 
Otherwise, print -1.
getMin -- Print the minimum element in the stack, if the 
stack is non-empty. Otherwise, print -1.
Initially, the stack is empty.


Input Format

The first line of input contains Q - the number of queries.
Each of next line contains input in one of the four formats 
mentioned in the problem statement.


Output Format

Print the answer for the top and getMin operations.


Constraints

1 ≤ Q ≤ 106
0 ≤ x ≤ 109


Sample Input 1

11
push 1
push 3
top
getMin
pop
top
getMin
pop
pop
top
getMin

Sample Output 1

3
1
1
1
-1
-1*/

class MinStack {
private:
stack<int>st;// storing regular values
stack<int>minst;// minst.top==the minimum value present in query stack

public:

    MinStack() {}

    void push(int x) {
        st.push(x);
        if(minst.size()==0||x<=minst.top()){
            minst.push(x);
        }
    
    }

    void pop() {
        
        if(!st.empty()){
            
            if(st.top()==minst.top()){
                
                //st.pop();
                minst.pop();
                
            }
            
            st.pop();
            
        }
    }

    int top() {
        
        if(!st.empty()){
            
            return st.top();
        }
        return -1;
        
        
    }

    int getMin() {
        
        if(!minst.empty()){
            
            return minst.top();
        }
        return -1;
        
    }
};

 


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int q; cin >> q;

    MinStack s;

    while(q--) {
        string op;
        cin >> op;

        if(op == "push") {
            int x;
            cin >> x;
            s.push(x);
        }
        else if(op == "pop") {
            s.pop();
        }
        else if(op == "top") {
            cout << s.top() << "\n";
        }
        else if(op == "getMin") {
            cout << s.getMin() << "\n";
        }
    }

    return 0;
}

/*approach
Try to use two stacks.


One stack is to maintain the minimum of elements present in the stack
 on the top of the stack. Let two stacks be st and minSt.

push x – push x on top of stack st, and push min(x, minSt.top()) 
on top of minSt.
pop – pop from both stacks at the same time.
top – print top of st.
getMin – print top of minSt.
You can do it using one stack implicitly by maintaining pairs.
 But eventually its a same thing. 


Another approach in which we can solve this problem. This is a interesting approach.

We define a variable minEle that stores the current minimum element 
in the stack. Now the interesting part is, how to handle the case 
when minimum element is removed. To handle this, we push 2x – minEle 
into the stack instead of x so that previous minimum element can be 
retrieved using current minEle and its value stored in stack. Below 
are detailed steps and explanation of working.

push x – 
If stack is empty, insert x into the stack and make minEle equal to x.
If stack is not empty, compare x with minEle. Two cases arise:
If x is greater than or equal to minEle, simply insert x.
If x is less than minEle, insert (2x – minEle) into the stack and
 make minEle equal to x.
pop --
Remove element from top. Let the removed element be y. Two cases arise:
If y is greater than or equal to minEle, the minimum element in the stack
 is still minEle.
If y is less than minEle, the minimum element now becomes (2minEle – y),
 so update (minEle = 2*minEle – y). This is where we retrieve previous
  minimum from current minimum and its value in stack. 

*/

//editorial code

//Solution 1:

class MinStack {
public:
    stack<int> st, minSt;

    MinStack() {}

    void push(int x) {
        if(st.empty()) {
            st.push(x);
            minSt.push(x);
            return;
        }
        st.push(x);
        minSt.push(min(minSt.top(), x));
        return;
    }

    void pop() {
        if(st.empty()) return;
        st.pop();
        minSt.pop();
    }

    int top() {
        if(st.empty()) return -1;
        return st.top();
    }

    int getMin() {
        if(minSt.empty()) return -1;
        return minSt.top();
    }
};
//Solution 2:

class MinStack {
private:
    long long int minele=INT_MAX;
    stack<long long int> st;
public:
    void push(int x) {
        if(st.empty()) {
            minele=x;
            st.push(x);
        }
        else if(x<minele) {
            long long int temp=x;
            temp=2*temp-minele;
            st.push(temp);
            minele=x;
        }
        else
            st.push(x);
    }

    void pop() {
        if(st.top()<minele) {
            int temp=st.top();
            minele=2*minele-temp;
        }
        st.pop();
        if(st.empty()) minele=INT_MAX;
    }

    int top() {
        if(st.top()<minele) {
            return minele;
        }
        else return st.top();
    }

    int getMin() {
        return minele;
    }
};


/*Height of Soldiers⭐

Time-Limit: 1 sec Score: 1.00/100
Difficulty : ****
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

There are N soldiers standing in a row, numbered 1 through N. The height of i-th soldier is Hi. For each non-empty contiguous segment of the line, strength is defined as the minimum height of the soldier in that segment.
You have to tell the maximum strength for each x size group, for all groups of size x between 1 to N.


Input Format

The first line of the input contains one integer T - the number of test cases. Then T test cases follow.
The first line of each test case contains one integer N - the length of the array. 
The second line of each test case contains N space-separated integers - H1, H2, ... HN, heights of soldiers.


Output Format

For each test case, print N integers in one line. For each x from 1 to N, print the maximum strength among all groups of size x.


Constraints

1 ≤ T ≤ 100
1 ≤ N ≤ 105
1 ≤ Hi ≤ 109
Sum of N over all test cases doesn't exceed 5 x 105


Sample Input 1

3

3

1 5 3

4

8 6 1 1

7

1 2 3 4 6 3 2


Sample Output 1

5 3 1 

8 6 1 1 

6 4 3 3 2 2 1


Note

In the first test case of the example, for x=1, possible answers are 1, 5 and 3 (maximum of them is 5).
For x=2, possible answers are 1 and 3 (maximum of them is 3)
For x=3, the only possible answer is 1.

In the second test case of the example, for x=1, possible answers are 1, 6 and 8 (maximum of them is 8).
For x=2, possible answers are 1 and 6 (maximum of them is 6)
For x=3 and x=4, the only possible answer is 1.*/


#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int main() {
    IOS
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        stack<int> s;
        int l[n], r[n];
        for (int i = 0; i < n; ++i) {
            while(!s.empty() && a[s.top()] >= a[i]) {
                s.pop();
            }
            if(s.empty()) {
                l[i] = -1;
            }
            else {
                l[i] = s.top();
            }
            s.push(i);
        }
        while (!s.empty()) {
            s.pop();
        }
        for (int i = n-1; i >= 0; --i) {
            while(!s.empty() && a[s.top()] >= a[i])
                s.pop();
            if(s.empty()) {
                r[i] = n;
            }
            else {
                r[i] = s.top();
            }
            s.push(i);
        }

        int ans[n] = {};
        for (int i = 0; i < n; ++i) {
            int x = r[i] - l[i] - 2;
            ans[x] = max(ans[x], a[i]);
        }
        for (int i = n-2; i >= 0; --i) {
            ans[i] = max(ans[i], ans[i+1]);
        }
        for (int i = 0; i < n; ++i) {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

/*For the last part of Code's explaination:

A[i] is max in the range r[i]-1 to l[i]+1.

So there is a range of length x, possible with max. = a[i].

Ans[x] = means what is the max possible Value that is possible for
 x length window.

Now in the next loop, we are doing a suffix max.  Basically saying that 
if there is a X length with max = a[i], then there is also a length X-1 
window with max = a[i].*/

/*approach
Note that the answer is non-increasing.


Try using a data structure to store the answers in groups.


For each i, find the largest j that aj <ai and j < i 
(if there is no such j, then consider it as -1). Let this be Li. Similarly,
 find the smallest j that aj<ai and j > i (if there is no such j, then consider 
 it as N). Let this be Ri. 
You can use the stack for doing this in O(N). For each i, we know 
that it can be the minimum element in groups of size 1,2,...,ri-li-1. Let ansi be
 the answer of i from 0 to N-1, then ans1≥ans2≥...≥ansN.

See Solution code.

Time Complexity: O(N)


*/

/*Running Mean, Median and Mode AZ101⭐

Time-Limit: 1 sec Score: 1.00/100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Description

You have an empty array and can perform the following operations on it:

insert x - add integer x to the array
remove x - remove integer x from the array. It's guaranteed the 
element present in it.
getMean - find the mean of elements currently presents in the array.
getMedian - find the median of elements currently present in the array, 
 if the count of the numbers is even, take the average of the two middle elements.
getMode - find the mode of elements currently present in the array, if 
there is more than one potential element, assume that the mode is the smaller of all.
If the array is empty at the point a query is asked about
 a metric(mean, median, mode), print -1.

If any of the answers for the query is a fraction, let's say, 
P / Q in reduced form, the return the number (P*Q-1) Modulo 1000000007.


Input Format

The first line of the input contains one integer T - the number
 of test cases. Then T test cases follow.
The first line of each test case contains one integer Q - 
the number of queries. 
Each of the next Q lines contains a string S and integer X or 
just a string S - description of the query.


Output Format

For each test case, print the answer for the queries.


Constraints

1 ≤ T ≤ 105
1 ≤ Q ≤ 105
1 ≤ x ≤ 109
It is guaranteed that the sum of Q over all test cases does not exceed 105.


Sample Input 1

1
12
insert 4
insert 3
insert 5
getMean
getMedian
getMode
insert 4
remove 3
insert 5
getMean
getMedian
getMode

Sample Output 1

4
4
3
500000008
500000008
4

Note

Array becomes: [4]
Array becomes [3, 4]
Array becomes [3, 4, 5]
Mean = (3+4+5) / 3 = 4
Median = 4 (middle element)
Mode = 3 (since it is smallest in value)
Array becomes [3, 4, 4, 5]
Array becomes [4, 4, 5]
Array becomes [4, 4, 5, 5]
Mean = (4+4+5+5)/4 = 4.5 (=500000008 in mod domain)
Median = (4+5)/2 = 4.5 (average of the two middle elements)
Mode = 4 (since it is smallest in value)*/

#define ll long long int
#define LD long double

const int N = 100010;

int inf = 1e9;
int mod = 1e9 + 7;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree <pair<int,int>, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
/*
    order_of_key (k)
    find_by_order(k)
*/


inline void add(int &a, int b) {
  a += b;
  if (a >= mod) a -= mod;
}

inline void sub(int &a, int b) {
  a -= b;
  if (a < 0) a += mod;
}

inline int mul(int a, int b) {
  return (int) ((long long) a * b % mod);
}

inline int power(int a, long long b) {
  int res = 1;
  while (b > 0) {
    if (b & 1) {
      res = mul(res, a);
    }
    a = mul(a, a);
    b >>= 1;
  }
  return res;
}

inline int inv(int a) {
  a %= mod;
  if (a < 0) a += mod;
  int b = mod, u = 0, v = 1;
  while (a) {
    int t = b / a;
    b -= t * a; swap(a, b);
    u -= t * v; swap(u, v);
  }
  assert(b == 1);
  if (u < 0) u += mod;
  return u;
}

struct Mean {
    int sum, cnt;

    Mean() : sum(0), cnt(0) {};

    void insert(int x) {
        add(sum, x);
        add(cnt, 1);
    }

    void remove(int x) {
        sub(sum, x);
        sub(cnt, 1);
    }

    int GetMean() const {
        if (!cnt) return -1;
        return mul(sum, inv(cnt));
    }
};

struct Mode {
    set<pair<int,int>> s;
    map<int,int> M;

    void insert(int x) {
        M[x]++;
        if (M[x] > 1) s.erase(s.find({-(M[x] - 1), x}));
        s.insert({-M[x], x});
    }

    void remove(int x) {
        s.erase(s.find({-M[x], x}));
        M[x]--;
        if (M[x]) s.insert({-M[x], x});
    }

    int GetMode() {
        if (s.empty()) return -1;
        return s.begin()->second;
    }
};

struct Median {
    ordered_set s;
    map<int,int> M;

    void insert(int x) {
        M[x]++;
        s.insert({x, M[x]});
    }

    void remove(int x) {
        s.erase(s.find({x, M[x]}));
        M[x]--;
    }

    int GetMedian() {
        if (s.empty()) return -1;
        int n = (int)s.size();
        if (n % 2 == 0) {
            int sum = s.find_by_order(n / 2 - 1)->first;
            add(sum, s.find_by_order(n / 2)->first);
            return mul(sum, inv(2));
        }
        return s.find_by_order(n / 2)->first;
    }
};

signed main()
{
    //freopen("IN", "r", stdin);
    //freopen("OUT", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int q;
        cin >> q;

        Mean mean;
        Mode mode;
        Median median;

        while (q--) {
            string s;
            cin >> s;

            if (s == "insert") {
                int x;
                cin >> x;
                mean.insert(x);
                mode.insert(x);
                median.insert(x);
            } else if (s == "remove") {
                int x;
                cin >> x;
                mean.remove(x);
                mode.remove(x);
                median.remove(x);
            } else if (s == "getMean") {
                cout << mean.GetMean() << "\n";
            } else if (s == "getMode") {
                cout << mode.GetMode() << "\n";
            } else if (s == "getMedian") {
                cout << median.GetMedian() << "\n";
            }
        }
    }
    return 0;
}
/*approach
Mean  = sum of all numbers/count of numbers

Median = Middle element if the array was sorted, if count of the numbers 
is even, take the average of the two middle elements.

Mode = Maximum occurring element, if there is more than one element, 
 assume that the mode is the smaller of the two.


For mean, keep track of the sum of the numbers along with the count of
 numbers in two separate variables.

For median, you can use pair<int, int> in the indexed set to get multiple
 elements with the same value in the set and hence get the middle values easily.

For mode, store the count of each number in a map and use set of pair 
to find the maximum occurring number.

Time Complexity per test case: O(Q log Q)*/


/*LRU Cache⭐⭐

Time-Limit: 2 sec Score: 100.00/100
Difficulty : ****
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.


Input Format

Implement the LRUCache class:

LRUCache(int capacity) : Initialize the LRU cache with positive size capacity.
int get(int key) : Return the value of the key if the key exists, otherwise return -1.
void put(int key, int value) : Update the value of the key if the key exists. Otherwise,
 add the key-value pair to the cache. If the number of keys exceeds the capacity 
 from this operation, evict the least recently used key.

Output Format

For every call to the get function print the value of the key if it exists else print -1.


Constraints

1 ≤ capacity ≤ 105

1 ≤ key, value ≤ 105

At most 105 calls will be made to functions get and put.


Sample Input 1

9 2
put 1 1
put 2 2
get 1
put 3 3
get 2
put 4 4
get 1
get 3
get 4

Sample Output 1

1
-1
-1
3
4

Note

The cache after every operation is:

[{1,1}]
[{1,1},{2,2}]
[{2,2},{1,1}]
[{1,1},{3,3}]
[{1,1},{3,3}]
[{3,3},{4,4}]
[{3,3},{4,4}]
[{4,4},{3,3}]
[{3,3},{4,4}]*/

class LRUCache
{


    // LRUCache(int capacity)
    // {
    //     //Complete function
        
        
        list<int>order;
        unordered_map<int,pair<int,list<int>::iterator>>cach;
        int max_size=0;
        
        void touch(int id){
            auto it=cach.find(id);
            int key=it->f;
            order.erase(it->s.s);
            order.push_front(key);
            it->s.s=order.begin();
            
        }
            
       // }
        
   // }
    
    public:
    LRUCache(int capacity){
        max_size=capacity;
        order.clear();
        cach.clear();
    }
    
    

    int get(int key)
    {
        //Complete function
        
        if(cach.find(key)==cach.end()){
            
            return -1;
            
        }
        else{
            touch(key);
            return cach[key].f;
        }
        
    }

    void put(int key, int value)
    {
        //Complete function
        
        if(cach.find(key)==cach.end()){
            
            if(cach.size()==max_size){
                int del=order.back();
                cach.erase(del);
                order.pop_back();
                
                
            }
            order.push_front(key);
        }else{
            touch(key);
        }
        cach[key]=make_pair(value,order.begin());
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int q, cap;
    cin >> q >> cap;
    LRUCache *obj = new LRUCache(cap);
    for (int i = 0; i < q; i++)
    {
        string op;
        cin >> op;
        if (op == "get")
        {
            int key;
            cin >> key;
            cout << obj->get(key) << '\n';
        }
        else
        {
            int key, val;
            cin >> key >> val;
            obj->put(key, val);
        }
    }

    return 0;
}


/*Can you do the insertion and deletion in the cache in constant time?


Maintain a doubly linked list for the cache and a hash map for storing
 the values of the keys.


We maintain a queue where we store the key values in the order in which we 
encounter them. We create a hash set which stores the values associated with
 each of the keys. When a new key is added, we add it to the end of the queue
  and update its value in the hash set. If a key is updated or we access its 
  value we remove it from the queue and add it again at the end. 

If the implementation of the queue is done using a vector it takes O(N*Q) time 
which is insufficient to pass the constraints. It can be improved to O(Q) if we 
implement it using doubly linked lists, which supports insertion and deletion 
in constant time.


*/

/*SUMPAIR

Time-Limit: 1 sec Score: 75.00/100
Difficulty : **
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

Given two integer arrays A and B, you have to implement a data
 structure that supports queries of two types:

Add a positive integer to an element of a given index in the array B.
Count the number of pairs (i, j) such that A[i] + B[j] equals a given value total

Input Format

Implement the FindPairswithSum class:

FindPairswithSum(vector<int> &A, vector<int> &B) : Initializes the 
FindPairswithSum object with two integer arrays A and B.
void add(int index, int val) : Adds val to B[index] (0-indexing).
int count(int total) : Returns the number of pairs (i, j) such
 that A[i] + B[j] == total.

Output Format

For every call to the count function the number of pairs are printed.


Constraints

1 ≤ A.length ≤ 1000

1 ≤ B.length ≤ 105

1 ≤ A[i],B[i] ≤ 105

0 ≤ index < B.length

1 ≤ val ≤ 105

1 ≤ total ≤ 2
×
109

At most 1000 calls are made to add and count each.


Sample Input 1

3 3 3
4 5 6
1 2 3
count 7
add 0 2
count 9

Sample Output 1

3
2

Note

A = {4, 5, 6}

B = {1, 2, 3}

The first query returns 3 as (0,2), (1,1) and (2,0) are the 
valid pairs with sum equal to 7.

After the second query the arrays are [4,5,6] and [3,2,3].

The third query returns 2 as (2,0) and (2,2) are the valid
 pairs with sum equal to 9.*/

class FindPairswithSum
{
public:

unordered_map<ll,ll>mp;

vector<ll>brr; 
vector<ll>arr;
    FindPairswithSum(vector<ll> &A, vector<ll> &B)
    {
        // brr.resize(m);
        // arr.resize(n);
        
        
        for(auto it:B){
            
            mp[it]++;
            brr.push_back(it);
            
        }
        for(auto it:A){
            arr.push_back(it);
            
        }
        
        
        
        
    }

    void add(int index, int val)
    {
        if(mp.find(brr[index])!=mp.end()&&mp[brr[index]]>0) mp[brr[index]]--;
        
        brr[index]+=val;
        mp[brr[index]]++;
        
        
    }

    int count(int total)
    {
        ll ans=0;
        for(ll i=0;i<arr.size();i++){
            
            if(mp.find(total-arr[i])!=mp.end()&&mp[total-arr[i]]>0){
                
                ans+=mp[total-arr[i]];
                
                
            }
            
        }
        return ans;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    
    cin >> n >> m >> q;

    vector<ll> A(n), B(m);

    for (auto &i : A)
    {
        cin >> i;
    }

    for (auto &i : B)
    {
        cin >> i;
    }

    FindPairswithSum *obj = new FindPairswithSum(A, B);

    for (int i = 0; i < q; i++)
    {
        string op;
        cin >> op;
        if (op == "add")
        {
            int index, val;
            cin >> index >> val;
            obj->add(index, val);
        }
        else
        {
            int total;
            cin >> total;
            cout << obj->count(total) << '\n';
        }
    }

    return 0;
}

/*FMBQUEUE

Time-Limit: 1 sec Score: 1.00/100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

Design a queue that supports push and pop operations 
in the front, middle, and back.


Input Format

Implement the FrontMiddleBack class:

FrontMiddleBack() : Initializes the queue.
void pushFront(int val) : Adds val to the front of the queue.
void pushMiddle(int val) : Adds val to the middle of the queue.
void pushBack(int val) : Adds val to the back of the queue.
int popFront() : Removes the front element of the queue and returns
 it. If the queue is empty, return -1.
int popMiddle() : Removes the middle element of the queue and returns
 it. If the queue is empty, return -1.
int popBack() : Removes the back element of the queue and returns it.
 If the queue is empty, return -1.
Note: When there are two middle position choices, the operation is 
performed on the left middle position choice. For example:

Pushing 6 into the middle of [1, 2, 3, 4, 5] results in [1, 2, 6, 3, 4, 5].
Popping the middle from [1, 2, 3, 4, 5, 6] returns 3 and results in [1, 2, 4, 5, 6].

Output Format

For every pop function, return the popped element.


Constraints

1 ≤ val ≤ 109

At most 105 calls will be made to pushFront, pushMiddle, pushBack,
 popFront, popMiddle, and popBack.


Sample Input 1

9
pushFront 1
pushBack 2
pushMiddle 3
pushMiddle 4
popFront
popMiddle
popMiddle
popBack
popFront

Sample Output 1

1
3
4
2
-1

Note

The state of the queue after the operations:
[1]
[1, 2]
[1, 3, 2]
[1, 4, 3, 2]
[4, 3, 2]
[4, 2]
[2]
[]
-1 -> [] (The queue is empty)*/

class FrontMiddleBackQueue
{
public:

 deque<int>f,s;
 
    FrontMiddleBackQueue()
    {
      // balancing//
      
    
       
        
    }
    
     void balancing(){
         
           if(f.size()>s.size()){
          s.push_front(f.back());    // making fist size= s.size-1;  // for odd no of element
          f.pop_back();
      }
      
      if(s.size()>f.size()+1){   
          
          f.push_back(s.front()); // making f.size==s.size   // for total even no of element
          s.pop_front();
      } 
         
         
         
     }
    
    
    
    void pushFront(int val)
    {
        f.push_front(val);
        
        balancing();
        
        
    }

    void pushMiddle(int val)
    {
        
        if(f.size()==s.size()){
            s.push_front(val);
        }else{
            
            f.push_back(val);
            
        }
        
        
    }

    void pushBack(int val)
    {
        
        s.push_back(val);
        balancing();
        
    }

    int popFront()
    {
        if(f.empty()&&s.empty()) return -1;
        
        int x;
        if(f.empty()){
            
            x=s.front();
            s.pop_front();
            
            
        }else{
            
            x=f.front();
            f.pop_front();
           
        }
         balancing();
            
        return x;
        
    }

    int popMiddle()
    {
        
       if(f.empty()&&s.empty()) return -1;
       
      int x; 
      if(f.size()==s.size()){
          
          x=f.back();
          f.pop_back();
          
          
          
      }else{
          
          x=s.front();
          s.pop_front();
          
          
      }
        
        
        return x;
        
        
    }

    int popBack()
    {
        
        if(f.empty()&&s.empty()) return -1; 
        
        int x;
        x=s.back();
        s.pop_back();
        
        balancing();
        return x;
        
        
        
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int q;
    cin >> q;
    FrontMiddleBackQueue *obj = new FrontMiddleBackQueue();
    for (int i = 0; i < q; i++)
    {
        string op;
        cin >> op;
        if (op == "pushFront")
        {
            int val;
            cin >> val;
            obj->pushFront(val);
        }
        else if (op == "pushMiddle")
        {
            int val;
            cin >> val;
            obj->pushMiddle(val);
        }
        else if (op == "pushBack")
        {
            int val;
            cin >> val;
            obj->pushBack(val);
        }
        else if (op == "popFront")
        {
            cout << obj->popFront() << '\n';
        }
        else if (op == "popMiddle")
        {
            cout << obj->popMiddle() << '\n';
        }
        else if (op == "popBack")
        {
            cout << obj->popBack() << '\n';
        }
    }
    return 0;
}
/*approach
Maintain two deques first and second for the two halves of the queue.


The size of the first deque should be equal to or one less than the second deque
 so that the middle element will always be added to the end of the first deque 
 or beginning of the second deque.


Maintain two deques first and second for the two halves of the queue. Pushing 
to the front of the queue will be pushing to the front of the first deque and 
pushing to the back of the queue is pushing to the back of the second deque. 
Same is for popping the front and back elements. The size of the first deque 
should be equal to or one less than the second deque so that the middle element will
 always be added to the end of the first deque or beginning of the second deque.
  For popping the middle element, pop the last element of the first deque if the 
  size of the deques are the same, else pop the first element of the second deque.
   To maintain the size of the first deque equal to or one less than the size of
    the second deque, shift the last element of the first deque to the front of 
    the second deque, or vice versa, as needed.


*/

/*Maximizing MEX AZ101

Time-Limit: 1 sec Score: 1.00/100
Difficulty : *
 Memory: 256 MB Accepted Submissions: 100
Description

You have an empty array A and a positive integer X. You are given Q queries with an integer Y,
 which you have to append to the array. In one move, you can change Y as: Y = Y + X or Y = Y - X,
  Y cannot become negative. You can perform this move multiple times. After each query, 
  find the maximum MEX of the array. 

The MEX of an array is the minimum excluded non-negative integer.


Input Format

The first line of the input contains one integer T - the number of test cases.
 Then T test cases follow.

The first line of each test case contains two space-separated integers Q X - 
the number of queries and value of X.

Each of the next lines contain one integer Y - the element you have to append in the array.


Output Format

For each test case, print the MEX for each query as space-separated integers.


Constraints

1≤ T ≤ 105

1≤ Q ≤ 105

1≤ X ≤ 105

0≤ Yi ≤ 109

It is guaranteed that the sum of Q over all test cases does not exceed 105.


Sample Input 1

3
4 3
5
3
1
2
5 2
3 
1
2
8
0
3 1
87
32
21

Sample Output 1

0 1 3 3 
0 0 2 4 5 
1 2 3

Note

For the first test case, the given array can be changed to: [2, 0, 1, 5] from [5 3 1 2] ,
 X=3. (all changes are with adding and subtracting X from the numbers).

The mex of [2] is 0
The mex of [2, 0] is 1
The mex of [2, 0, 1] is 3
The mex of [2, 0, 1, 5] is 3

For the second test case, the given array can be changed to: [1, 3, 0, 2, 4]

For the third test case, the given array can be changed to: [0, 1, 2]*/

int main() {
    IOS
    int t;
    cin >> t;
    while (t--) {
         int q, x;
        cin >> q >> x;
        vector<int> v[x];
        set<int> s;
        for (int i = 0; i <= q; ++i) {
            s.insert(i);
        }
        while (q--) {
            int t;
            cin >> t;
            t%=x;
            if (v[t].empty()) {
                v[t].push_back(t);
            }
            else {
                int xx=v[t].back();
                v[t].push_back(xx+x);
                t=xx+x;
            }
            s.erase(t);

            cout << *s.begin() << " ";
        }
        cout << "\n";
    }
    return 0;
}

/*approach
After any number of moves, Ai%X remains the same for any Ai.


Store all the numbers in an array of vector by taking its modulus with
 X and using the smallest unique element possible.

Since the answer cannot exceed Q, you can use set to first store all 
integers from 0 to Q and then remove the values of Ai. To get the MEX, 
simply print the first element of the set.

Time Complexity per test case: O(Q log Q)*/


/*Product of the Last K numbers⭐

Time-Limit: 2 sec Score: 1.00/100
Difficulty : ***
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

Design the algorithm which supports the following operations.

add(int x): Add x to the back of the current list of numbers.
getProduct(int k): Print the product of the last k numbers % 1000000007 in 
the current list. It's guaranteed that the list will contain at least k elements.
Initially, the list is empty.

Complete the code.


Input Format

The first line contains Q - the number of queries.
Each query is one of the types of queries explained in the problem statement.


Constraints

1 ≤ Q ≤ 105
0 ≤ x ≤ 109


Sample Input 1

10
add 3
add 0
add 2
add 5
add 4
getProduct 2
getProduct 3
getProduct 4
add 8
getProduct 2

Sample Output 1

20
40
0
32*/

class ProductOfKNumbers {
public:
    vector<ll> prod;
    int zeroCount;

    ProductOfKNumbers() {
        prod.push_back(1);
        zeroCount = 0;
    }

    void add(int num) {
        if(num == 0) {
            prod.clear();
            prod.push_back(1);
            zeroCount++;
        } else {
            prod.push_back((prod.back()%mod * (num%mod)) % mod);
        }
    }

    ll getProduct(int k) {
        if(prod.size()-1<k) {
            return 0;
        } else {
            ll result = prod.back();
            ll inverse = power(prod[prod.size() - k - 1], mod - 2);
            return (result * inverse) % mod;
        }
    }

    ll power(ll a, ll b) {
        ll result = 1;
        while(b > 0) {
            if(b & 1) {
                result = (result * a) % mod;
            }
            a = (a * a) % mod;
            b >>= 1;
        }
        return result;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int Q;
    cin >> Q;

    ProductOfKNumbers productOfKNumbers;

    while(Q--) {
        string op;
        cin >> op;

        if(op == "add") {
            int num;
            cin >> num;
            productOfKNumbers.add(num);
        } else {
            int k;
            cin >> k;
            cout << productOfKNumbers.getProduct(k) << "\n";
        }
    }

    return 0;
}

/*Stack Increments

Time-Limit: 1 sec Score: 100.00/100
Difficulty : ***
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

You have a box and you want to put numbers into it.
The capacity of the box is n. If the box has n numbers, 
no more numbers can be added to it.
Implement the CustomStack class :

CustomStack(int n): Initialises the object with n which is the maximum 
capacity of the box.
void push(int x) (1 <= x <= 1000) - Add x to the top of the box.
 If the box has already reached its capacity, do nothing.
int pop() - Return the number present on top of the box. Return -1 
if the box is empty.
void inc(int k, int val) -  (1 <= k <= 104, 0 <= val <= 1000) -
 Increment the bottom k numbers of the box by val. If there are 
 less than k numbers in the box, just increment all the numbers.

Input Format

Your CustomStack object will be instantiated and called as such:

CustomStack* obj = new CustomStack(maxSize);
obj->push(x);
int param_2 = obj->pop();
obj->inc(k,val);

Output Format

Implement the CustomStack class.


Constraints

1 <= n <= 100000
1 <= q <= 100000  (total number of function calls)
1 <= x <= 1000
1 <= k <= 105
0 <= val <= 1000

Sample Input 1

4 12
push 5
push 9
push 8
push 7
push 6
pop
inc 2 5
inc 6 5
pop
pop
pop
pop

Sample Output 1

7
13
19
15
-1

Note

1. Box will look like [5].
2. Box will look like [5 ,9]
3. Box will look like [5 ,9 ,8].
4. Box will look like [5 ,9 ,8 ,7].
5. Box will look like [5 ,9 ,8 ,7]. Since the capacity 
of the box is 4, 6 is not added to the box.
6. Box will look like [5 ,9 ,8]. 7 is printed since it 
is at the top.
7. Box will look like [10 ,14 ,8].
8. Box will look like [15 ,19 ,13]. Since 6 numbers are 
not present, all of them are incremented.
9. Box will look like [15 ,19]. 13 is printed since it 
is at the top.
10. Box will look like [15]. 19 is printed since it is at the top.
11. Box will look like []. 15 is printed since it is at the top.
12. Box is empty so -1 is printed.*/


class CustomStack {
public:

	vector<pair<ll,ll>>st; 
	ll top_current;
	
	CustomStack(int maxSize) {
	   st.resize(maxSize);
	   
	    top_current=0;
	
	}

	void push(int x) {
	    
	    if(top_current<st.size()){
	        
	        st[top_current].f=x;
	        st[top_current].s=0;
	        
	        
	        top_current++;
	        
	    }
	    
	    
		
	}

	int pop() {
		
		if(top_current!=0){
		    
		    top_current--;
		    st[top_current].f+=st[top_current].s;
		    if(top_current){
		        
		        st[top_current-1].s+=st[top_current].s;
		    }
		    
		    return st[top_current].f;
		    
		}
		
		return -1;
		
	}

	void increment(ll k, ll val) {
		
	k=min(k,top_current);
	k--;
	if(k>=0)st[k].s+=val;
		
	}
};

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	int maxSize;
	cin >> maxSize;

	int q;
	cin >> q;

	CustomStack* customStack = new CustomStack(maxSize);

	for (int itr = 0; itr < q; itr++) {
		string op;
		cin >> op;

		if (op == "push") {
			int x;
			cin >> x;

			customStack->push(x);
		}
		else if (op == "pop") {
			cout << customStack->pop() << "\n";
		}
		else if (op == "inc") {
			int k, val;
			cin >> k >> val;
			customStack->increment(k, val);
		}
	}

}
/*approach
The increment always occurs on some prefix of the current box.


Instead of incrementing all k numbers in the prefix, can we somehow 
store the information and prevent traversing the box every time?


The constraints do not allow us to simulate the process. We can maintain
 a vector of numbers representing the box. If the size of the vector has 
 reached the capacity of the box we will no longer push any number into it. 
When we need to increment a prefix of length k, instead of adding k to all 
the numbers present in the prefix we can just add it to the kth number. When
 the kth number is popped the value added to the kth number can be passed 
 over to the previous number. This works because we only need to print the
  number present on the top of the box at a time. So when a number is queried,
   all numbers present on top of it must already be printed and thus the
    values added to them would be passed over to the current number.
To do this we maintain another vector inc which stores the value added to 
the last number.
When the ith number is printed the value added to it is passed over to
 the previous number.

        inc[i-1]+=inc[i]

The complexity for each function is O(1).*/

/*Maximum Area AZ101

Time-Limit: 3 sec Score: 1.00/100
Difficulty : ***
 Memory: 256 MB Accepted Submissions: 100
Description

You have a rectangular sheet of paper with dimensions H x W. You make N horizontal 
and verticals cuts in the sheet. Find the area of the maximum fragment after each cut.

It is guaranteed that there won't be any two identical cuts. Also, The cut that you
 make in the previous queries persists on the paper for the next queries. 


Input Format

The first line of the input contains one integer T - the number of test cases.
 Then T test cases follow.

The first line of each test case contains three space-separated integers H W N - 
the dimensions of the sheet and the number of cuts.

Each of the next N lines is of the form H Y or V X. For H Y, you make a horizontal
 cut at distance Y from the lower edge of the sheet and for V X, you make a
  vertical cut at a distance X from the left edges of the sheet.


Output Format

For each test case, print the area of the maximum fragment after each cut.


Constraints

1≤ T ≤ 105

1≤ N ≤ 105

2≤ W, H ≤ 109

1≤ Y ≤ H - 1

1≤ X ≤ W - 1

It is guaranteed that the sum of N over all test cases does not exceed 106.


Sample Input 1

2
5 3 3
H 1
V 1
V 2
3 5 4
H 2
V 2
H 1
V 1

Sample Output 1

12
8
4
10
6
3
3*/

void solve(){
	
ll h,w,n;
cin>>h>>w>>n;

set<ll,greater<ll>>hori_cut;
set<ll,greater<ll>>verti_cut;
multiset<ll,greater<ll>>h_seg,w_seg;

hori_cut.insert(0);
hori_cut.insert(h);
verti_cut.insert(0);
verti_cut.insert(w);
h_seg.insert(h);
w_seg.insert(w);

while(n--){
 char c;
 ll x;
 cin>>c>>x;
 
 if(c=='H'){
     hori_cut.insert(x);
     auto it =hori_cut.lower_bound(x);
    
     auto left=it;
     auto right=it;
     left--;
     right++;
     h_seg.erase(h_seg.find(*left-*right));
     h_seg.insert(*left-x);
     h_seg.insert(x-*right);
     
     
 }else{
     
     verti_cut.insert(x);
     auto it=verti_cut.lower_bound(x);
     auto left=it;
     auto right=it;
     left--;
     right++;
     
     w_seg.erase(w_seg.find(*left-*right));
     w_seg.insert(*left-x);
     w_seg.insert(x-*right);
     
 }
    
    auto ans=(*h_seg.begin())*(*w_seg.begin());
    
    cout<<ans<<nl;
    
    
    
}
	
}/*approach
The largest piece would have the largest height and width.


Store all the height and width in two multisets. Also store all 
the horizontal and vertical cut marks in separate sets.

Time Complexity per test case: O(N * log(W + H))


*/


/*Snapshot Array⭐

Time-Limit: 1 sec Score: 1.00/100
Difficulty : ****
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

Implement a SnapshotArray that supports the following interface:

SnapshotArray(int length) initializes an array-like data structure 
with the given length. Initially, each element equals 0.
void set(index, val) sets the element at the given index to be equal to val.
int snap() takes a snapshot of the array and returns the snap_id: 
the total number of times we called snap() minus 1.
int get(index, snap_id) returns the value at the given index, at 
the time we took the snapshot with the given snap_id.

Input Format

The first line of input contains Q, L - the number of queries and the length of the array.
Next, Q lines contain queries of the types mentioned in the problem statement.


Constraints

1 ≤ Q ≤ 105
1 ≤ L ≤ 109
0 ≤ val ≤ 109
0 ≤ snap_id < (the total number of times we call snap())
0 ≤ index < L


Sample Input 1

4 3
set 0 5
snap
set 0 6
get 0 0

Sample Output 1

0
5*/

class SnapshotArray
{
public:
unordered_map<int,vector <pair<int, int> > > arr;
int timer;
	
	SnapshotArray(int length)
	{
	//	arr.resize(length);
		
		timer=0;
		
	}

	void set(int index, int val)
	{
	    
	    if(!arr[index].empty()&&arr[index].back().f==timer){     // optimization//
	        arr[index].pop_back();
	    }
		
		arr[index].push_back(make_pair(timer,val));
		
		
	}

	int snap()
	{
	timer++;
	return timer-1;
		
	}

	int get(int index, int snap_id)
	{
	    
	    auto it= 
	    lower_bound(arr[index].begin(),arr[index].end(),make_pair(snap_id,INT_MAX));
	    
	    
	    if(it==arr[index].begin()){
	        return 0;
	    }else{
	        
	        it--;
	        return it->s;
	        
	    }
		
	}
};

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	int Q, L;
	cin >> Q >> L;

	SnapshotArray snapshotArray(L);

	while (Q--)
	{
		string op;
		cin >> op;

		if (op == "set")
		{
			int index, val;
			cin >> index >> val;

			snapshotArray.set(index, val);
		}
		else if (op == "get")
		{
			int index, snap_id;
			cin >> index >> snap_id;

			cout << snapshotArray.get(index, snap_id) << "\n";
		}
		else if (op == "snap")
		{
			cout << snapshotArray.snap() << "\n";
		}
	}

	return 0;
}

/*approach
Observe that L ≤ 109, and Q ≤ 105. From these constraints, it's clear that not
 all elements will be set. Most of them will be 0 only.


Maintain unordered map, adding both element and snap_id.


Look into the constraints carefully. L ≤ 109, and Q ≤ 105. Most of the elements
 will be 0. So we'll maintain unordered_map on the index of the array to store data.
  We'll also maintain curSnapId to store what index of snap we currently at,
   or how many snaps we've taken till now.

set(index, val): Look for the last time you take a snap of the value at index. 
We can get that using the last value store at the index. If the snapId of the last
 element is same as curSnapId, just update the element. Otherwise push back 
 new entry {val, curSnapId}.
snap: This is the simplest operation in this design. Just increment the curSnapId.
get(index, val): Look for if we've set index before or not. We can do it by checking 
if index is present in map or not. If not, then return 0. Otherwise, now we've vector 
of pairs with value and snap_id (the value at the time of snap_id). Since it's in 
increasing order of snap_id, we do binary search on snap_id to find the ≤ snap_id snap.
Look into the editorial code for a better understanding.


*/


/*Circular Queue

Time-Limit: 1 sec Score: 1.00/100
Difficulty : ***
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

Design your implementation of the circular queue. The circular queue is a linear data 
structure in which the operations are performed based on FIFO (First In First Out) 
principle and the last position is connected back to the first position to make a circle. 
It is also called "Ring Buffer".

In a normal Queue, we can insert elements until the queue becomes full. But once the 
queue becomes full, we can not insert the next element even if there is a 
space in front of the queue.

Implement the following functions:

MyCircularQueue(k): Initializes the object with the size of the queue to be k.
int Front(): Gets the front item from the queue. If the queue is empty, return -1.
int Rear(): Gets the last item from the queue. If the queue is empty, return -1.
bool enQueue(int value): Inserts an element into the circular queue. Return
 true if the operation is successful.
bool deQueue(): Deletes an element from the circular queue. Return true if
 the operation is successful.
bool isEmpty(): Checks whether the circular queue is empty or not.
bool isFull(): Checks whether the circular queue is full or not.
Initially, the queue is empty.

You must solve the problem without using the built-in queue data structure
 in your programming language. 


Input Format

The first line of input contains Q - the number of queries.
The second line contains k.
Each of the next lines contains queries of one of the types mentioned in the problem statement.


Constraints

1 ≤ k, Q ≤ 105


Sample Input 1

9
3
enQueue 1
enQueue 2
enQueue 3
enQueue 4
Rear
isFull
deQueue
enQueue 4
Rear

Sample Output 1

True
True
True
False
3
True
True
True
4*/

#include <bits/stdc++.h>
using namespace std;

class MyCircularQueue
{
public:
    struct ListNode
    {
        int val;
        ListNode *next, *back;
        ListNode() : val(0), next(nullptr), back(nullptr) {}
        ListNode(int x) : val(x), next(nullptr), back(nullptr) {}
ListNode(int x, ListNode *next, ListNode *back) : val(x), next(next), back(back) {}
    };

    ListNode *head;
    int K;
    int curSize;

    MyCircularQueue(int k)
    {
        head = nullptr;
        K = k;
        curSize = 0;
    }

    bool enQueue(int value)
    {
        if (curSize == K)
            return false;

        ListNode *newNode = new ListNode(value);

        if (!curSize)
        {
            head = newNode;
            head->next = head;
            head->back = head;
        }
        else
        {
            ListNode *tail = head->next;
            tail->back = newNode;
            newNode->next = tail;
            newNode->back = head;
            head->next = newNode;
        }

        curSize++;

        return true;
    }

    bool deQueue()
    {
        if (!curSize)
            return false;

        if (curSize == 1)
        {
            delete (head);
            head = nullptr;
        }
        else
        {
            ListNode *tail = head->next;
            head = head->back;
            delete (head->next);
            head->next = tail;
            tail->back = head;
        }

        curSize--;
        return true;
    }

    int Front()
    {
        if (head)
            return head->val;
        return -1;
    }

    int Rear()
    {
        if (head)
            return head->next->val;
        return -1;
    }

    bool isEmpty()
    {
        return !curSize;
    }

    bool isFull()
    {
        return (curSize == K);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int q;
    cin >> q;

    int k;
    cin >> k;

    MyCircularQueue myCircularQueue(k);

    while (q--)
    {
        string s;
        cin >> s;

        if (s == "enQueue")
        {
            int val;
            cin >> val;

            if (myCircularQueue.enQueue(val))
                cout << "True\n";
            else
                cout << "False\n";
        }
        else if (s == "deQueue")
        {
            if (myCircularQueue.deQueue())
                cout << "True\n";
            else
                cout << "False\n";
        }
        else if (s == "Front")
        {
            cout << myCircularQueue.Front() << "\n";
        }
        else if (s == "Rear")
        {
            cout << myCircularQueue.Rear() << "\n";
        }
        else if (s == "isEmpty")
        {
            if (myCircularQueue.isEmpty())
                cout << "True\n";
            else
                cout << "False\n";
        }
        else if (s == "isFull")
        {
            if (myCircularQueue.isFull())
                cout << "True\n";
            else
                cout << "False\n";
        }
        else
        {
            assert(1 == 0); //This never happen
        }
    }

    return 0;
}

/*approach
If we use a singly linked list, then all operations, except deQueue, are O(1). 
deQueue will take O(n), since we’re not storing any back information of the 
front node. How to make this also O(1)?


Yes, we can use a doubly-linked list. Can we do it using only one pointer?


We create a doubly linked list structure, like below:

    struct ListNode
      {
        int val;
        ListNode *next, *back;
        ListNode() : val(0), next(nullptr), back(nullptr) {}
        ListNode(int x) : val(x), next(nullptr), back(nullptr) {}
        ListNode(int x, ListNode *next, ListNode *back) : val(x), next(next), back(back) {}
    };
We maintain only one pointer head. The front and rear sides of the list are 
connected. The list is arranged in a circular fashion.

enQueue(): Check if the queue is full or not. Create a new node and attach 
it after the head. Update back and next pointers of the new node, head and 
head→next (the rear node, because list is circular). And move the head to the new node.
deQueue(): Check if queue is empty or not. Remove front node and travel to 
the new front using back pointer. And update the next and back pointers of head and head→next.
Front(): Check if queue is empty or not. Otherwise head is the front node.
Rear(): Check if the queue is empty or not. Otherwise, the head→next is the rear node.

*/

/*Circular Deque

Time-Limit: 1 sec Score: 1.00/100
Difficulty : ***
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

Design your implementation of the circular double-ended queue (deque).

Your implementation should support the following operations:

MyCircularDeque(k): Constructor, set the size of the deque to be k.
insertFront(): Adds an item at the front of Deque. Return true if the operation
 is successful.
insertLast(): Adds an item at the rear of Deque. Return true if the
 operation is successful.
deleteFront(): Deletes an item from the front of Deque. Return true 
if the operation is successful.
deleteLast(): Deletes an item from the rear of Deque. Return true if
 the operation is successful.
getFront(): Gets the front item from the Deque. If the deque is 
empty, return -1.
getRear(): Gets the last item from Deque. If the deque is 
empty, return -1.
isEmpty(): Checks whether Deque is empty or not.
isFull(): Checks whether Deque is full or not.
Do it without using STL in C++. All operations should be O(1).


Input Format

The first line of input contains Q - the number of queries.
The second line contains k.
Each of the next lines contains queries of one of the types mentioned in the problem statement.


Constraints

1 ≤ k, Q ≤ 106


Sample Input 1

9
3
insertLast 1
insertLast 2
insertLast 3
insertLast 4
getRear
isFull
deleteLast
insertFront 4
getFront

Sample Output 1

True
True
True
False
3
True
True
True
4*/

#include <bits/stdc++.h>
using namespace std;
class MyCircularDeque
{
public:
    struct ListNode
    {
        int val;
        ListNode *next, *back;
        ListNode() : val(0), next(nullptr), back(nullptr) {}
        ListNode(int x) : val(x), next(nullptr), back(nullptr) {}
        ListNode(int x, ListNode *next, ListNode *back) : val(x), next(next), back(back) {}
    };

    ListNode *head, *tail;
    int K;
    int curSize;

    MyCircularDeque(int k)
    {
        head = nullptr;
        tail = nullptr;
        K = k;
        curSize = 0;
    }

    bool insertFront(int value)
    {
        if (curSize == K)
            return false;

        ListNode *curNode = new ListNode(value);

        if (!curSize)
        {
            head = tail = curNode;
        }
        else
        {
            head->next = curNode;
            curNode->back = head;
            head = curNode;
        }

        curSize++;
        return true;
    }

    bool insertLast(int value)
    {
        if (curSize == K)
            return false;

        ListNode *curNode = new ListNode(value);

        if (!curSize)
        {
            head = tail = curNode;
        }
        else
        {
            tail->back = curNode;
            curNode->next = tail;
            tail = curNode;
        }

        curSize++;
        return true;
    }

    bool deleteFront()
    {
        if (!curSize)
            return false;

        if (curSize == 1)
        {
            delete (head);
            head = nullptr;
        }
        else
        {
            head = head->back;
            delete (head->next);
            head->next = nullptr;
        }

        curSize--;

        return true;
    }

    bool deleteLast()
    {
        if (!curSize)
            return false;

        if (curSize == 1)
        {
            delete (tail);
            tail = nullptr;
        }
        else
        {
            tail = tail->next;
            delete (tail->back);
            tail->back = nullptr;
        }

        curSize--;

        return true;
    }

    int getFront()
    {
        if (!curSize)
            return -1;
        return head->val;
    }

    int getRear()
    {
        if (!curSize)
            return -1;
        return tail->val;
    }

    bool isEmpty()
    {
        return !curSize;
    }

    bool isFull()
    {
        return (curSize == K);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int q;
    cin >> q;

    int k;
    cin >> k;

    MyCircularDeque myCircularDeque(k);

    while (q--)
    {
        string s;
        cin >> s;

        if (s == "insertFront")
        {
            int val;
            cin >> val;
            if (myCircularDeque.insertFront(val))
                cout << "True\n";
            else
                cout << "False\n";
        }
        else if (s == "insertLast")
        {
            int val;
            cin >> val;
            if (myCircularDeque.insertLast(val))
                cout << "True\n";
            else
                cout << "False\n";
        }
        else if (s == "deleteFront")
        {
            if (myCircularDeque.deleteFront())
                cout << "True\n";
            else
                cout << "False\n";
        }
        else if (s == "deleteLast")
        {
            if (myCircularDeque.deleteLast())
                cout << "True\n";
            else
                cout << "False\n";
        }
        else if (s == "getFront")
        {
            cout << myCircularDeque.getFront() << "\n";
        }
        else if (s == "getRear")
        {
            cout << myCircularDeque.getRear() << "\n";
        }
        else if (s == "isEmpty")
        {
            if (myCircularDeque.isEmpty())
                cout << "True\n";
            else
                cout << "False\n";
        }
        else if (s == "isFull")
        {
            if (myCircularDeque.isFull())
                cout << "True\n";
            else
                cout << "False\n";
        }
        else
        {
            assert(1 == 0); //This never happen
        }
    }

    return 0;
}

/*approach
If we use singly linked list, then all operations, except deleteFront, are O(1)
. deleteFront will take O(n), since we’re not storing any back information of 
the front node. How to make this also O(1)?


Yes, we use a doubly linked list. Because of this, all operations will be O(1).


We create a doubly linked list structure, like below:

    struct ListNode
      {
        int val;
        ListNode *next, *back;
        ListNode() : val(0), next(nullptr), back(nullptr) {}
        ListNode(int x) : val(x), next(nullptr), back(nullptr) {}
        ListNode(int x, ListNode *next, ListNode *back) : val(x), next(next), 
        back(back) {}
    };
We maintain two pointers: head and tail. head points to the front of the deque,
 and tail point to the rear side of the deque.

insertFront(): Check if deque is full or not. Create a new node and attach it after
 the head. Update back and next pointers. And move the head to the new node.
insertBack(): Check if deque is full or not. Create a new node and attach it before 
the tail. Update back and next pointers. And move the tail to the new node.
deleteFront(): Check if deque is empty or not. Remove front node and travel to the
 new front using back pointer.
deleteLast(): Check if deque is empty or not. Remove the last node and travel to
 the new front using the next pointer.

*/


/*Common Absolute Difference

Time-Limit: 5 sec Score: 1.00/100
Difficulty : *
 Memory: 256 MB Accepted Submissions: 100
Description

You are given an array A of N integers and an integer K. Find 
the number of pairs (i, j) such that i < j and abs(Ai - Aj) = K


Input Format

The first line of the input contains one integer T - the number of test cases.
 Then T test cases follow.

The first line of each test case contains two space-separated integers N K -
 the length of the array and the required absolute difference.

The second line of each test case contains N space-separated integers.


Output Format

For each test case, print the number of pairs (i, j) such that i < j and
 abs(Ai - Aj) = K


Constraints

1≤ T ≤ 105

1≤ N ≤ 105

1≤ Ai ≤ 109

1≤ K ≤ 10^9.

It is guaranteed that the sum of N over all test cases does not exceed 105.

Notice K≠0, can you handle the case when K=0?


Sample Input 1

3
5 2
1 2 3 4 5
4 1
3 1 2 6
3 10
1 3 2

Sample Output 1

3
2
0

Note

For the first test case, following pairs have absolute difference 
2: [1, 3], [2, 4], [3, 5]

For the second test case, following pairs have absolute difference 
1: [3, 2], [1, 2]

For the third test case, no pair has absolute difference 10.*/

signed main() {
    IOS
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int a[n];
        map<int, int> m;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            m[a[i]]++;
        }
           long long ans = 0;
        for (int i = 0; i < n; ++i) {
            m[a[i]]--;
            ans += m[a[i]-k];
            ans += m[a[i]+k];
        }
        cout << ans << "\n";
    }
    return 0;
}

/*approach
Store all the integers in a map.


As you iterate through the array, check for every possible 
absolute difference as K = abs(Ai - Aj)

There can be two cases: Aj = Ai - K or Aj = Ai + K.

Time Complexity per test case: O(N log N)

Notice: This works when K≠0. 


*/


/*Game on Deque AZ101

Time-Limit: 1 sec Score: 1.00/100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Description

You recently learnt to use the C++ STL deque and decided to play 
a game on it. You are given a deque with N elements. You take the 
first two elements of the deque, pop them and push the larger of the two 
in the front and the smaller at the back of the deque. You are given Q queries,
 asking the first two elements of the deque you will take on the X-th operation. 


Input Format

The first line of the input contains one integer T - the number of test cases. 
Then T test cases follow.

The first line of each test case contains two space-separated integers N Q - 
the number of elements in the deque and the number of queries.

The second line of each test case contains N space-separated integers.

Each of the next Q lines contain a single integer X.


Output Format

For each test case, print the first two elements of the deque you will take on 
the X-th operation for each query. They should be printed in the order in which
 they will be pulled out of the deque.


Constraints

1≤ T ≤ 105

2≤ N ≤ 105

0≤ Q ≤ 105

0≤ Ai ≤ 109

1≤ Xi ≤ 1018

It is guaranteed that the sum of N and the sum of Q over all test cases 
does not exceed 106.


Sample Input 1

2
2 1
1 2
1
4 4
1 3 4 4
1
2
3
4

Sample Output 1

1 2
1 3
3 4
4 4
4 1

Note

For the first test case, in operation 1, you take 1 and 2

For the second test case, in operation 1, you take 1 and 3,
 deque becomes [3, 4, 4, 1]

In operation 2, you take 3 and 4, deque becomes [4, 4, 1, 3]

In operation 3, you take 4 and 4, deque becomes [4, 1, 3, 4]

In operation 4, you take 4 and 1, deque becomes [4, 3, 4, 1] */

signed main() {
    IOS
    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        int m = 0;
        deque<int> d;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            d.push_back(x);
            m = max(m, x);
        }
        int j = 0;
        for (int i = 0; i < n; ++i) {
            if(d[i] == m) {
                j = i;
                break;
            }
        }
        vector<pair<int, int>> v;
        v.push_back({0, 0});
        for (int i = 0; i <= j; ++i) {
            int a = d.front();
            d.pop_front();
            int b = d.front();
            d.pop_front();
            v.push_back({a, b});
            if(a > b) {
                d.push_front(a);
                d.push_back(b);
            }
            else {
                d.push_front(b);
                d.push_back(a);
            }
        }
        d.pop_front();
        n--;
        while (q--) {
            int x;
            cin >> x;
            if(x < v.size()) {
                cout << v[x].first << " " << v[x].second << "\n";
            }
            else {
                cout << m << " " << d[(x - v.size())%n] << "\n";
            }
        }
    }
    return 0;
}

/*approach

If you get the largest element in the deque at the first position, the first 
position will remain the same after the operation. The second element will go
 to the back of the deque.


Find the largest element of the deque, if a query is given before the largest 
element can come to the first position, you can find it manually by storing the 
answer in a vector. Otherwise, the answer will change in cycles of size N-1 
where N is the size of deque.

Time Complexity per test case: O(N + Q)*/
