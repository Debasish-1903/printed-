//week 3:

/* Vector AZ101

    Time-Limit: 1 sec Score: 100.00/100

Difficulty : *

    Memory: 256 MB Accepted Submissions: 100

Description

You are given Q queries and have to perform the following operations:

    add x - add element x at the end of vector
    remove - delete last element of the vector, if vector is not empty
    print x - print the x-th character of the vector, if it exists, otherwise print 0. (0-indexing)
    clear - empty the vector

Input Format

The first line of the input contains one integer T - the number of test cases. Then T test cases follow.

The first line of each test case contains one integer Q - the number of queries.

Each of the next Q ines contains queries.

Output Format

For each test case, print the required queries.

Constraints

1≤ T ≤ 106

1≤ Q ≤ 106

1≤ X ≤ 106

It is guaranteed that the sum of Q over all test cases does not exceed 106.

Sample Input 1

1
9
add 3
add 4
print 1
remove
add 7
add 2
print 0
clear
print 0

Sample Output 1

4
3
0

Note

    Vector becomes: [3]
    Vector becomes: [3, 4]
    V[1] = 4
    Vector becomes: [3]
    Vector becomes: [3, 7]
    Vector becomes: [3, 7, 2]
    V[0] = 3
    Vector becomes: []
    Vector is empty, hence no element at 0 index

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define ull unsigned long long int
#define mod 1000000007
#define inf 1e9
#define mt make_tuple
#define pb push_back
#define eb emplace_back
#define pob pop_back
#define f first
#define s second
#define nl "\n"
#define pi pair<int,int>
#define v vector<long long int>
#define vp vector<pair<int,int>>
#define vvl vector<vector<long long int>>
#define rep(n) for(int i=0 ; i<n ; i++)
#define rei(i) for(int i=n ; i>0 ; i--)
#define prio priority_queue
#define np next_permutation
#define N 200100

#define yes "YES"
#define no "NO"




 /*ll add(ll a,ll b){
	
	ll ans=(a+b)%mod;
	if(ans<0) ans+=mod;
	
	return ans;
}

 ll sub(ll a,ll b){
	
	ll ans=(a-b)%mod;
	if(ans<0) ans+=mod;
	
	return ans;
}

ll mul(ll a,ll b){
	
	ll ans=(a*b)%mod;
	if(ans<0) ans+=mod;
	
	return ans;
}*/


void solve(){
	
	int q;
	cin>>q;
	string str;
	string temp;
	
	//getline(cin,temp);
	
	v a;
	
	while(q--){
		
	//	getline(cin,str);
		cin>>str;
		
		if(str=="add"){
		    
		    int x;
		    cin>>x;
		    
		    
		    a.pb(x);
		    
		}else if(str=="remove"){
		    
		    if(!a.empty()) a.pob();
		}else if(str=="print"){
		    
		    int x;
		    cin>>x;
		    
		    
		    if(x>=0&&x<a.size()){
		    cout<<a[x]<<nl;}else{
		        
		        cout<<'0'<<nl;
		    }
		    
		}else if(str=="clear"){
		    
		    
		    a.clear();
		}
		
		
		
	}
	
	
	
	
	
	
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	 int _t; cin>>_t;while(_t--)
		solve();
	
	
	//cerr<<"Time elapsed: "<< 1.0*clock()/ CLOCKS_PER_SEC << "s.\n\n";
	
	
	
	
}



/* Product of Digits AZ101

    Time-Limit: 1 sec Score: 100.00/100

Difficulty :*

    Memory: 256 MB Accepted Submissions: 100

Description

You are given the digits of a positive number N. Find the product of its digits. Since the product can be large, print it modulo 109 + 7. It is guaranteed that the number begins with a non-zero digit.

Input Format

The first line of the input contains one integer T - the number of test cases. Then T test cases follow.

The first line of each test case contains one integer N - the number of digits in the number. 

The second line of each test case contains N space-separated integers - the digits of the number.

Output Format

For each test case, print the product of digits of the number modulo 109 + 7.

Constraints

1≤ T ≤ 106

1≤ N ≤ 106

0≤ D ≤ 9

It is guaranteed that the sum of N over all test cases does not exceed 106.

Sample Input 1

3
5
1 5 2 3 4
4
9 0 5 3
3
2 2 2

Sample Output 1

120
0
8

Note

For the first test case, 1*5*2*3*4 = 120

For the second test case, 9*0*5*3 = 0

For the third test case, 222 = 8

*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define ull unsigned long long int
#define mod 1000000007
#define inf 1e9
#define mt make_tuple
#define pb push_back
#define eb emplace_back
#define pob pop_back
#define f first
#define s second
#define nl "\n"
#define pi pair<int,int>
#define v vector<long long int>
#define vp vector<pair<int,int>>
#define vvl vector<vector<long long int>>
#define rep(n) for(int i=0 ; i<n ; i++)
#define rei(i) for(int i=n ; i>0 ; i--)
#define prio priority_queue
#define np next_permutation
#define N 200100

#define yes "YES"
#define no "NO"




 /*ll add(ll a,ll b){
	
	ll ans=(a+b)%mod;
	if(ans<0) ans+=mod;
	
	return ans;
}

 ll sub(ll a,ll b){
	
	ll ans=(a-b)%mod;
	if(ans<0) ans+=mod;
	
	return ans;
}

*/ll mul(ll a,ll b){
	
	ll ans=(a*b)%mod;
	if(ans<0) ans+=mod;
	
	return ans;
}


void solve(){
	
	int n;
	cin>>n;
	
	v a(n);
	
	for(int i=0;i<n;i++){
		
		
		cin>>a[i];
	}
	
	ll ans=1;
	
	for(int i=0;i<n;i++){
		
		ans=mul(ans,a[i]);
		
	}
	
	
	cout<<(ans+mod)%mod<<nl;
	
	
	
	
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	 int _t; cin>>_t;while(_t--)
		solve();
	
	
	//cerr<<"Time elapsed: "<< 1.0*clock()/ CLOCKS_PER_SEC << "s.\n\n";
	
	
	
	
}

/* Queue AZ101

    Time-Limit: 1 sec Score: 100.00/100

Difficulty :*

    Memory: 256 MB Accepted Submissions: 100

Description

You are given Q queries and have to perform the following operations:

    add x - add element x at the end of queue
    remove- delete front element of the queue, if queue is not empty
    print - print the element at the first position, if queue is not empty, otherwise print 0

Input Format

The first line of the input contains one integer T - the number of test cases. Then T test cases follow.

The first line of each test case contains one integer Q - the number of queries.

Each of the next Q ines contains queries.

Output Format

For each test case, print the required queries.

Constraints

1≤ T ≤ 106

1≤ Q ≤ 106

1≤ X ≤ 106

It is guaranteed that the sum of Q over all test cases does not exceed 106

Sample Input 1

1
5
add 3
add 4
print
remove
print

Sample Output 1

3
4

Note

    Queue becomes [3]
    Queue becomes [3, 4]
    Element at front = 3
    Queue becomes [4]
    Element at front = 4

*/


#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define ull unsigned long long int
#define mod 1000000007
#define inf 1e9
#define mt make_tuple
#define pb push_back
#define eb emplace_back
#define pob pop_back
#define f first
#define s second
#define nl "\n"
#define pi pair<int,int>
#define v vector<long long int>
#define vp vector<pair<int,int>>
#define vvl vector<vector<long long int>>
#define rep(n) for(int i=0 ; i<n ; i++)
#define rei(i) for(int i=n ; i>0 ; i--)
#define prio priority_queue
#define np next_permutation
#define N 200100

#define yes "YES"
#define no "NO"




 /*ll add(ll a,ll b){
	
	ll ans=(a+b)%mod;
	if(ans<0) ans+=mod;
	
	return ans;
}

 ll sub(ll a,ll b){
	
	ll ans=(a-b)%mod;
	if(ans<0) ans+=mod;
	
	return ans;
}

ll mul(ll a,ll b){
	
	ll ans=(a*b)%mod;
	if(ans<0) ans+=mod;
	
	return ans;
}*/


void solve(){
	
	int q;
	cin>>q;
	string str;
	string temp;
	
	//getline(cin,temp);
	
	queue<int>a;
	
	while(q--){
		
	//	getline(cin,str);
		cin>>str;
		
		if(str=="add"){
		    
		    int x;
		    cin>>x;
		    
		    
		    a.push(x);
		    
		}else if(str=="remove"){
		    
		    if(!a.empty()) a.pop();
		}else if(str=="print"){
		    
		    //int x;
		    // cin>>x;
		    
		    
		    if(!a.empty()){
		    cout<<a.front()<<nl;}else{
		        
		        cout<<'0'<<nl;
		    }
		    
		// }//else if(str=="clear"){
		    
		    
		//     a.clear();
		// }
		
		
		
	}
	
	
	}
	
	
	
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	 int _t; cin>>_t;while(_t--)
		solve();
	
	
	//cerr<<"Time elapsed: "<< 1.0*clock()/ CLOCKS_PER_SEC << "s.\n\n";
	
	
	
	
}

/* Stack AZ101

    Time-Limit: 1 sec Score: 100.00/100

Difficulty :*

    Memory: 256 MB Accepted Submissions: 100

Description

You are given Q queries and have to perform the following operations:

    add x - add element x at the top of stack
    remove - delete top element of the stack, if stack is not empty
    print - print the element at top, if stack is not empty, otherwise print 0

Input Format

The first line of the input contains one integer T - the number of test cases. Then T test cases follow.

The first line of each test case contains one integer Q - the number of queries.

Each of the next Q ines contains queries.

Output Format

For each test case, print the required queries.

Constraints

1≤ T ≤ 106

1≤ Q ≤ 106

1≤ X ≤ 106

It is guaranteed that the sum of Q over all test cases does not exceed 106

Sample Input 1

1
5
add 3
add 4
print
remove
print

Sample Output 1

4
3

Note

    Stack becomes [3]
    Stack becomes [3, 4]
    Element at top = 4
    Stack becomes [3]
    Element at top = 3

*/


#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define ull unsigned long long int
#define mod 1000000007
#define inf 1e9
#define mt make_tuple
#define pb push_back
#define eb emplace_back
#define pob pop_back
#define f first
#define s second
#define nl "\n"
#define pi pair<int,int>
#define v vector<long long int>
#define vp vector<pair<int,int>>
#define vvl vector<vector<long long int>>
#define rep(n) for(int i=0 ; i<n ; i++)
#define rei(i) for(int i=n ; i>0 ; i--)
#define prio priority_queue
#define np next_permutation
#define N 200100

#define yes "YES"
#define no "NO"




 /*ll add(ll a,ll b){
	
	ll ans=(a+b)%mod;
	if(ans<0) ans+=mod;
	
	return ans;
}

 ll sub(ll a,ll b){
	
	ll ans=(a-b)%mod;
	if(ans<0) ans+=mod;
	
	return ans;
}

ll mul(ll a,ll b){
	
	ll ans=(a*b)%mod;
	if(ans<0) ans+=mod;
	
	return ans;
}*/


void solve(){
	
	int q;
	cin>>q;
	string str;
	string temp;
	
	//getline(cin,temp);
	
	stack<int>a;
	
	while(q--){
		
	//	getline(cin,str);
		cin>>str;
		
		if(str=="add"){
		    
		    int x;
		    cin>>x;
		    
		    
		    a.push(x);
		    
		}else if(str=="remove"){
		    
		    if(!a.empty()) a.pop();
		}else if(str=="print"){
		    
		    //int x;
		    // cin>>x;
		    
		    
		    if(!a.empty()){
		    cout<<a.top()<<nl;}else{
		        
		        cout<<'0'<<nl;
		    }
		    
		// }//else if(str=="clear"){
		    
		    
		//     a.clear();
		// }
		
		
		
	}
	
	
	}
	
	
	
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	 int _t; cin>>_t;while(_t--)
		solve();
	
	
	//cerr<<"Time elapsed: "<< 1.0*clock()/ CLOCKS_PER_SEC << "s.\n\n";
	
	
	
	
}

/* Second Smallest Integer AZ101

    Time-Limit: 1 sec Score: 100.00/100

Difficulty :

    Memory: 256 MB Accepted Submissions: 100

Description

You are given an array of N integers. You have to find the second smallest integer in the given array.

Input Format

The first line of the input contains one integer T - the number of test cases. Then T test cases follow.

The first line of each test case contains one integer N - the length of the array. 

The second line of each test case contains N space-separated integers.

Output Format

For each test case, print the second smallest integer in the given array. If it doesn’t exist, print -1.

Constraints

1 ≤ T ≤ 105

1 ≤ N ≤ 105

0 ≤ Ai ≤ 105

It is guaranteed that the sum of N over all test cases does not exceed 105

Sample Input 1

3
5
3 4 1 7 7
5
1 5 1 2 1
3
1 1 1

Sample Output 1

3
2
-1

Note

For the first test case, the smallest element is 1 and the next smallest element is 3.

For the second test case, the smallest element is 1 and the next smallest element is 2.

For the third test case, the smallest element is 1 and there is no next smallest element.

*/


#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define ull unsigned long long int
#define mod 1000000007
#define inf 1e9
#define mt make_tuple
#define pb push_back
#define eb emplace_back
#define pob pop_back
#define f first
#define s second
#define nl "\n"
#define pi pair<int,int>
#define v vector<long long int>
#define vp vector<pair<int,int>>
#define vvl vector<vector<long long int>>
#define rep(n) for(int i=0 ; i<n ; i++)
#define rei(i) for(int i=n ; i>0 ; i--)
#define prio priority_queue
#define np next_permutation
#define N 200100

#define yes "YES"
#define no "NO"




 /*ll add(ll a,ll b){
	
	ll ans=(a+b)%mod;
	if(ans<0) ans+=mod;
	
	return ans;
}

 ll sub(ll a,ll b){
	
	ll ans=(a-b)%mod;
	if(ans<0) ans+=mod;
	
	return ans;
}

ll mul(ll a,ll b){
	
	ll ans=(a*b)%mod;
	if(ans<0) ans+=mod;
	
	return ans;
}*/


void solve(){
	
	ll n;
	cin>>n;
	
	v a(n);
	
	for(ll i=0;i<n;i++){
		
		cin>>a[i];
		
	}
	
	sort(a.begin(),a.end());
	queue<ll>pq;//(a.begin(),a.end());
	
	for(ll i=0;i<n;i++){
		
		if(a[i]!=a[i+1]){
			
			pq.push(a[i]);
		}
		
	}
	
	
	
	pq.pop();
	
	if(!pq.empty()){
	
	cout<<pq.front()<<nl;}else{
	    
	    cout<<"-1"<<nl;
	}
	
	
	
	
	
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
 int _t; cin>>_t;while(_t--)
		solve();
	
	
	//cerr<<"Time elapsed: "<< 1.0*clock()/ CLOCKS_PER_SEC << "s.\n\n";
	
	
	
	
}


/* Queue using 2 Stacks AZ101

    Time-Limit: 1 sec Score: 100.00/100

Difficulty :

    Memory: 256 MB Accepted Submissions: 100

Description

Implement a queue using 2 stacks. You will be given the following type of Q queries:

    push x - add x to the queue
    pop - pop the front element of the queue, you also have to print the element you have popped.
    front - find the element at the front of the queue

Input Format

The first line of the input contains one integer T - the number of test cases. Then T test cases follow.

The first line of each test case contains one integer Q - the number of queries

Each of the next Q lines contain the queries.

Output Format

For each test case, print the required queries.

Constraints

1≤ T ≤ 106

1≤ Q ≤ 106

1≤ X ≤ 106

It is guaranteed that the sum of Q over all test cases does not exceed 106.

Sample Input 1

1
7
push 3
push 5
pop
front
push 7
pop
pop

Sample Output 1

3
5
5
7

Note

    Queue becomes: [3]
    Queue becomes: [3, 5]
    Queue becomes [5] and element at front was 3
    Queue becomes [5]  and element at front is 5
    Queue becomes [5, 7]
    Queue becomes [7] and element at front was 5
    Queue becomes empty and element at front was 7

*/



#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define ull unsigned long long int
#define mod 1000000007
#define inf 1e9
#define mt make_tuple
#define pb push_back
#define eb emplace_back
#define pob pop_back
#define f first
#define s second
#define nl "\n"
#define pi pair<int,int>
#define v vector<long long int>
#define vp vector<pair<int,int>>
#define vvl vector<vector<long long int>>
#define rep(n) for(int i=0 ; i<n ; i++)
#define rei(i) for(int i=n ; i>0 ; i--)
#define prio priority_queue
#define np next_permutation
#define N 200100

#define yes "YES"
#define no "NO"




 /*ll add(ll a,ll b){
	
	ll ans=(a+b)%mod;
	if(ans<0) ans+=mod;
	
	return ans;
}

 ll sub(ll a,ll b){
	
	ll ans=(a-b)%mod;
	if(ans<0) ans+=mod;
	
	return ans;
}

ll mul(ll a,ll b){
	
	ll ans=(a*b)%mod;
	if(ans<0) ans+=mod;
	
	return ans;
}*/


void solve(){
	
	int m;
	cin>>m;
	
	queue<int>q;
	
	while(m--){
		
		string st;
		cin>>st;
		
		
		if(st=="push"){
			
			int x;
			cin>>x;
			
			q.push(x);
			
			
		}else if(st=="pop"){
			
			
			cout<<q.front()<<nl;
			
			q.pop();
			
			
			
		}else if(st=="front"){
			
			
			if(!q.empty()){
				
				cout<<q.front()<<nl;
			}
			
			
		}
		
	}
	
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	 int _t; cin>>_t;while(_t--)
		solve();
	
	
	//cerr<<"Time elapsed: "<< 1.0*clock()/ CLOCKS_PER_SEC << "s.\n\n";
	
	
	
	
}



/* Registration AZ101

    Time-Limit: 1 sec Score: 100.00/100

Difficulty : *

    Memory: 256 MB Accepted Submissions: 100

Description

Being the site administrator, you need to register the people on the website. A person registers with his name, S. If the name does not occur in the records, the person gets registered on the website and “OK” is shown. Otherwise, if the record already exists, print the name along with the number of times the person has registered on the website before, without any spaces.

Input Format

The first line of the input contains one integer T - the number of test cases. Then T test cases follow.

The first line of each test case contains one integer N - the number of people who register. 

Each of the next N lines contains a string S - the name in lower case alphabets.

Output Format

For each test case, print “OK” if the person registers for the first time. Otherwise, print the name along with the number of times the person has registered on the website before, without any spaces.

Constraints

1≤ T ≤ 105

1≤ N ≤ 105

1≤ |S| ≤ 30

It is guaranteed that the sum of N over all test cases does not exceed 106.

Sample Input 1

2
4
harry
ron
harry
hermione
3
abc
abc
abc

Sample Output 1

OK
OK
harry1
OK
OK
abc1
abc2

Note

For the first test case, harry registers again, so his name along with the name of times is printed.

For the second test case, abc registers thrice, so his name along with the name of times is printed.

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define ull unsigned long long int
#define mod 1000000007
#define inf 1e9
#define mt make_tuple
#define pb push_back
#define eb emplace_back
#define pob pop_back
#define f first
#define s second
#define nl "\n"
#define pi pair<int,int>
#define v vector<long long int>
#define vp vector<pair<int,int>>
#define vvl vector<vector<long long int>>
#define rep(n) for(int i=0 ; i<n ; i++)
#define rei(i) for(int i=n ; i>0 ; i--)
#define prio priority_queue
#define np next_permutation
#define N 200100

#define yes "YES"
#define no "NO"




 /*ll add(ll a,ll b){
	
	ll ans=(a+b)%mod;
	if(ans<0) ans+=mod;
	
	return ans;
}

 ll sub(ll a,ll b){
	
	ll ans=(a-b)%mod;
	if(ans<0) ans+=mod;
	
	return ans;
}

ll mul(ll a,ll b){
	
	ll ans=(a*b)%mod;
	if(ans<0) ans+=mod;
	
	return ans;
}*/


void solve(){
	
	ll n;
	cin>>n;


string str; 
unordered_map<string,ll>mp;

	while(n--){
	   	
	   	cin>>str;
	   	
	   	
	   	if(mp.find(str)==mp.end()){
	   	    
	   	    cout<<"OK"<<nl;
	   	    mp[str]++;
	   	}else{
	   	    
	   	    cout<<str<<mp[str]<<nl;
	   	    mp[str]++;
	   	}
	   	
	    
	    
	}
	
	
	
	
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	 int _t; cin>>_t;while(_t--)
		solve();
	
	
	//cerr<<"Time elapsed: "<< 1.0*clock()/ CLOCKS_PER_SEC << "s.\n\n";
	
	
	
	
}


/* Deque AZ101

    Time-Limit: 1 sec Score: 100.00/100

Difficulty :

    Memory: 256 MB Accepted Submissions: 100

Description

You are given Q queries and have to perform the following operations:

    insertback x - add element x at the end of deque
    eraseback - delete end element of the queue, if queue is not empty
    insertfront x - add element x at the front of deque
    erasefront - delete front element of the queue, if queue is not empty
    printfront - print element at front of the queue, if queue is not empty, otherwise print 0
    printback - print element at back of the queue , if queue is not empty, otherwise print 0
    print x - print the x-th character of the vector, if it exists, otherwise print 0. (0-indexing)

Input Format

The first line of the input contains one integer T - the number of test cases. Then T test cases follow.

The first line of each test case contains one integer Q - the number of queries.

Each of the next Q ines contains queries.

Output Format

For each test case, print the required queries.

Constraints

1≤ T ≤ 105

1≤ Q ≤ 105

1≤ X ≤ 106

It is guaranteed that the sum of Q over all test cases does not exceed 105

Sample Input 1

1
8
insertback 3
insertback 5
insertfront 2
printback
print 1
eraseback
insertfront 1
printfront

Sample Output 1

5
3
1

Note

    Deque becomes [3]
    Deque becomes [3, 5]
    Deque becomes [2, 3, 5]
    Last element of deque is 5
    Element at index 1 is 3
    Deque becomes [2, 3]
    Deque becomes [1, 2, 3]
    First element of deque is 1

*/


#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define ull unsigned long long int
#define mod 1000000007
#define inf 1e9
#define mt make_tuple
#define pb push_back
#define eb emplace_back
#define pob pop_back
#define f first
#define s second
#define nl "\n"
#define pi pair<int,int>
#define v vector<long long int>
#define vp vector<pair<int,int>>
#define vvl vector<vector<long long int>>
#define rep(n) for(int i=0 ; i<n ; i++)
#define rei(i) for(int i=n ; i>0 ; i--)
#define prio priority_queue
#define np next_permutation
#define N 200100

#define yes "YES"
#define no "NO"




 /*ll add(ll a,ll b){
	
	ll ans=(a+b)%mod;
	if(ans<0) ans+=mod;
	
	return ans;
}

 ll sub(ll a,ll b){
	
	ll ans=(a-b)%mod;
	if(ans<0) ans+=mod;
	
	return ans;
}

ll mul(ll a,ll b){
	
	ll ans=(a*b)%mod;
	if(ans<0) ans+=mod;
	
	return ans;
}*/


void solve(){
	
	deque<int>dq;
	
	int q;
	
	cin>>q;
	//string st;
	while(q--){
		
		
	string st;
	cin>>st;
	
	
		if(st=="insertback"){
			
			int x;
			cin>>x;
			
			dq.pb(x);
			
		}else if(st=="eraseback"){
			
			
			if(!dq.empty()){
				
				dq.pob();
				
			}
		
		}else if(st=="insertfront"){
			
			int x;
			cin>>x;
			
			
			dq.push_front(x);
			
		}else if(st=="erasefront"){
			
			// int x;
			// cin>>x;
			
			if(!dq.empty()){ dq.pop_front();}
			
		}else if(st=="printfront"){
			
			// int x;
			// cin>>x;
			
			if(!dq.empty()){
				
				cout<<dq.front()<<nl;
			}else{
				
				cout<<'0'<<nl;
			}
			
		}else if(st=="printback"){
			
			// int x;
			// cin>>x;
			
			if(!dq.empty()){
				
				cout<<dq.back()<<nl;
			}else{
				
				cout<<'0'<<nl;
			}
			
		}else if(st=="print"){
			
			 int x;
			 cin>>x;
			
			if(x>=0&&x<dq.size()){
				
				cout<<dq.at(x)<<nl;
			}else{
				
				cout<<'0'<<nl;
			}
			
		}
		
		
		
		
	}
	
	
	
	
	
	
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	 int _t; cin>>_t;while(_t--)
		solve();
	
	
	//cerr<<"Time elapsed: "<< 1.0*clock()/ CLOCKS_PER_SEC << "s.\n\n";
	
	
	
	
}
/* Set AZ101

    Time-Limit: 1 sec Score: 100.00/100

Difficulty :*

    Memory: 256 MB Accepted Submissions: 100

Description

You are given Q queries and have to perform the following operations:

    add x - add element x in the set
    erase x - delete element with value x, if it exists
    find x - if x is present print “YES”, else print “NO”
    print - print the values in set
    empty - empty the set

Input Format

The first line of the input contains one integer T - the number of test cases. Then T test cases follow.

The first line of each test case contains one integer Q - the number of queries.

Each of the next Q ines contains queries.

Output Format

For each test case, print the required queries.

Constraints

1≤ T ≤ 105

1≤ Q ≤ 105

1≤ X ≤ 106

It is guaranteed that the sum of Q over all test cases does not exceed 105.

Sample Input 1

1
7
add 3
add 2
add 7
print
find 2
erase 2
find 2

Sample Output 1

2 3 7 
YES
NO

Note

    Set becomes: [3]
    Set becomes: [2, 3]
    Set becomes: [2, 3, 7]
    Set is: 2, 3, 7.
    2 exists in the set
    Set becomes: [3, 7]
    2 does not exist in the set

*/


#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define ull unsigned long long int
#define mod 1000000007
#define inf 1e9
#define mt make_tuple
#define pb push_back
#define eb emplace_back
#define pob pop_back
#define f first
#define s second
#define nl "\n"
#define pi pair<int,int>
#define v vector<long long int>
#define vp vector<pair<int,int>>
#define vvl vector<vector<long long int>>
#define rep(n) for(int i=0 ; i<n ; i++)
#define rei(i) for(int i=n ; i>0 ; i--)
#define prio priority_queue
#define np next_permutation
#define N 200100

#define yes "YES"
#define no "NO"




 /*ll add(ll a,ll b){
	
	ll ans=(a+b)%mod;
	if(ans<0) ans+=mod;
	
	return ans;
}

 ll sub(ll a,ll b){
	
	ll ans=(a-b)%mod;
	if(ans<0) ans+=mod;
	
	return ans;
}

ll mul(ll a,ll b){
	
	ll ans=(a*b)%mod;
	if(ans<0) ans+=mod;
	
	return ans;
}*/


void solve(){
	
	set<int>dq;
	
	int q;
	
	cin>>q;
	//string st;
	while(q--){
		
		
	string st;
	cin>>st;
	
	
		if(st=="add"){
			
			int x;
			cin>>x;
			
			dq.insert(x);
			
		}else if(st=="erase"){
			
			int x;
			cin>>x;
			
			if(!dq.empty()&&dq.count(x)){
				
				dq.erase(x);
				
			}
		
		}else if(st=="find"){
			
			int x;
			cin>>x;
			
			if(dq.find(x)!=dq.end()){
				
				cout<<yes<<nl;
			}else{
				
				cout<<no<<nl;
				
			}
			
			
		}else if(st=="print"){
			
			// int x;
			// cin>>x;
			
			//if(!dq.empty()) {
				
				for(auto it:dq){
					
					cout<<it<<" ";
				}
				
				cout<<nl;
				
		//	}
			
		}else if(st=="empty"){
			
			dq.clear();
			
		}
		
		
		
		
	}
	
	
	
	
	
	
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	 int _t; cin>>_t;while(_t--)
		solve();
	
	
	//cerr<<"Time elapsed: "<< 1.0*clock()/ CLOCKS_PER_SEC << "s.\n\n";
	
	
	
	
}


/* Map AZ101

    Time-Limit: 1 sec Score: 100.00/100

Difficulty :*

    Memory: 256 MB Accepted Submissions: 100

Description

You are given Q queries and have to perform the following operations:

    add x y - add student name X (string in lowercase alphabets) with marks y (integer). If it already exists, update.
    erase x - erase marks of student with name x, if the entry exists
    print x - print marks of student with name x, if entry is not there for x, print 0.

Input Format

The first line of the input contains one integer T - the number of test cases. Then T test cases follow.

The first line of each test case contains one integer Q - the number of queries.

Each of the next Q ines contains queries.

Output Format

For each test case, print the required queries.

Constraints

1≤ T ≤ 105

1≤ Q ≤ 105

1≤ |S| ≤ 50

1≤ Y ≤ 106

It is guaranteed that the sum of Q over all test cases does not exceed 105.

Sample Input 1

1
5
add alice 24
add bob 21
print alice
erase alice
print alice

Sample Output 1

24
0

Note

    Map becomes: [alice: 24]
    Map becomes: [alice: 24, bob: 21]
    Value of key alice is 24
    Map becomes: [bob: 21]
    Key alice does not exist

*/


#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define ull unsigned long long int
#define mod 1000000007
#define inf 1e9
#define mt make_tuple
#define pb push_back
#define eb emplace_back
#define pob pop_back
#define f first
#define s second
#define nl "\n"
#define pi pair<int,int>
#define v vector<long long int>
#define vp vector<pair<int,int>>
#define vvl vector<vector<long long int>>
#define rep(n) for(int i=0 ; i<n ; i++)
#define rei(i) for(int i=n ; i>0 ; i--)
#define prio priority_queue
#define np next_permutation
#define N 200100

#define yes "YES"
#define no "NO"




 /*ll add(ll a,ll b){
	
	ll ans=(a+b)%mod;
	if(ans<0) ans+=mod;
	
	return ans;
}

 ll sub(ll a,ll b){
	
	ll ans=(a-b)%mod;
	if(ans<0) ans+=mod;
	
	return ans;
}

ll mul(ll a,ll b){
	
	ll ans=(a*b)%mod;
	if(ans<0) ans+=mod;
	
	return ans;
}*/

//right answer
void solve(){
	
	map<string,int>dq;
	
	int q;
	
	cin>>q;
	//string st;
	while(q--){
		
		
	string st;
	cin>>st;
	
	
		if(st=="add"){
			
			string x;
			cin>>x;
			int y;
			cin>>y;
			
			
			if(dq.find(x)==dq.end()){
			dq.insert({x,y});
			    
			}else{
			    
			    dq[x]=y;
			}
			
		}else if(st=="erase"){
			
			string x;
			cin>>x;
			
			if(!dq.empty()&&dq.count(x)){
				
				dq.erase(x);
				
			}
		
		}else if(st=="print"){
			
			string x;
			 cin>>x;
			
			if(dq.find(x)!=dq.end()) {
				
				cout<<dq.at(x)<<nl;
				
			}else{
				
				cout<<'0'<<nl;
			}
			
		}
		
		
		
		
	}
	
	
	
	
	
	
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	 int _t; cin>>_t;while(_t--)
		solve();
	
	
	//cerr<<"Time elapsed: "<< 1.0*clock()/ CLOCKS_PER_SEC << "s.\n\n";
	
	
	
	
}


//wrong answer

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define ull unsigned long long int
#define mod 1000000007
#define inf 1e9
#define mt make_tuple
#define pb push_back
#define eb emplace_back
#define pob pop_back
#define f first
#define s second
#define nl "\n"
#define pi pair<int,int>
#define v vector<long long int>
#define vp vector<pair<int,int>>
#define vvl vector<vector<long long int>>
#define rep(n) for(int i=0 ; i<n ; i++)
#define rei(i) for(int i=n ; i>0 ; i--)
#define prio priority_queue
#define np next_permutation
#define N 200100

#define yes "YES"
#define no "NO"




 /*ll add(ll a,ll b){
	
	ll ans=(a+b)%mod;
	if(ans<0) ans+=mod;
	
	return ans;
}

 ll sub(ll a,ll b){
	
	ll ans=(a-b)%mod;
	if(ans<0) ans+=mod;
	
	return ans;
}

ll mul(ll a,ll b){
	
	ll ans=(a*b)%mod;
	if(ans<0) ans+=mod;
	
	return ans;
}*/


void solve(){
	
	map<string,int>dq;
	
	int q;
	
	cin>>q;
	//string st;
	while(q--){
		
		
	string st;
	cin>>st;
	
	
		if(st=="add"){
			
			string x;
			cin>>x;
			int y;
			cin>>y;
			
			dq.insert({x,y});
			
		}else if(st=="erase"){
			
			string x;
			cin>>x;
			
			if(!dq.empty()&&dq.count(x)){
				
				dq.erase(x);
				
			}
		
		}else if(st=="print"){
			
			string x;
			 cin>>x;
			
			if(dq.find(x)!=dq.end()) {
				
				cout<<dq.at(x)<<nl;
				
			}else{
				
				cout<<'0'<<nl;
			}
			
		}
		
		
		
		
	}
	
	
	
	
	
	
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	 int _t; cin>>_t;while(_t--)
		solve();
	
	
	//cerr<<"Time elapsed: "<< 1.0*clock()/ CLOCKS_PER_SEC << "s.\n\n";
	
	
	
	
}


/* Multiset AZ101

    Time-Limit: 1 sec Score: 100.00/100

Difficulty :*

    Memory: 256 MB Accepted Submissions: 100

Description

You are given Q queries and have to perform the following operations:

    add x - add element x in the set
    erase x - delete one element with value x, if it exists
    eraseall x - delete all elements with value x, if it exists
    find x - if x is present print “YES”, else print “NO”
    count x - print the number of times x occurs in the set
    print - print the values in set
    empty - empty the set

Input Format

The first line of the input contains one integer T - the number of test cases. Then T test cases follow.

The first line of each test case contains one integer Q - the number of queries.

Each of the next Q lines contains queries.

The combination of print and n does not exceed 10^8.

Output Format

For each test case, print the required queries.

Constraints

1≤ T ≤ 105

1≤ Q ≤ 105

1≤ X ≤ 106

It is guaranteed that the sum of Q over all test cases does not exceed 105.

Sample Input 1

1
13
add 3
add 1
add 5
add 3
add 3
count 3
erase 3
print
eraseall 3
print
find 5
empty
find 5

Sample Output 1

3
1 3 3 5 
1 5 
YES
NO

Note

    Multiset becomes: [3]
    Multiset becomes: [1, 3]
    Multiset becomes: [1, 3, 5]
    Multiset becomes: [1, 3, 3, 5]
    Multiset becomes: [1, 3, 3, 3, 5]
    3 occurs 3 times in the multiset
    Multiset becomes: [1, 3, 3, 5]
    Multiset is: 1, 3, 3, 5
    Multiset becomes: [1, 5]
    Multiset is: 1, 5
    5 exists in the multiset
    Multiset becomes empty
    5 does not exist in the multiset

*/


#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define ull unsigned long long int
#define mod 1000000007
#define inf 1e9
#define mt make_tuple
#define pb push_back
#define eb emplace_back
#define pob pop_back
#define f first
#define s second
#define nl "\n"
#define pi pair<int,int>
#define v vector<long long int>
#define vp vector<pair<int,int>>
#define vvl vector<vector<long long int>>
#define rep(n) for(int i=0 ; i<n ; i++)
#define rei(i) for(int i=n ; i>0 ; i--)
#define prio priority_queue
#define np next_permutation
#define N 200100

#define yes "YES"
#define no "NO"




 /*ll add(ll a,ll b){
	
	ll ans=(a+b)%mod;
	if(ans<0) ans+=mod;
	
	return ans;
}

 ll sub(ll a,ll b){
	
	ll ans=(a-b)%mod;
	if(ans<0) ans+=mod;
	
	return ans;
}

ll mul(ll a,ll b){
	
	ll ans=(a*b)%mod;
	if(ans<0) ans+=mod;
	
	return ans;
}*/


void solve(){
	
	multiset<int>dq;
	
	int q;
	
	cin>>q;
	//string st;
	while(q--){
		
		
	string st;
	cin>>st;
	
	
		if(st=="add"){
			
			int x;
			cin>>x;
			
			dq.insert(x);
			
		}else if(st=="erase"){
			
			int x;
			cin>>x;
			auto it=dq.find(x);
			if(it!=dq.end()){
				
				dq.erase(it);
				
			}
		
		}else if(st=="eraseall"){
			
			int x;
			cin>>x;
			
			if(dq.find(x)!=dq.end()){
				
				dq.erase(x);
				
			}
			
			
		}else if(st=="find"){
			
			int x;
			cin>>x;
			
			if(dq.find(x)!=dq.end()){
				
				cout<<yes<<nl;
			}else{
				cout<<no<<nl;
			}
			
		}else if(st=="count"){
			
			int x;
			cin>>x;
			
			cout<<dq.count(x)<<nl;
			
		}else if(st=="print"){
			
			for(auto it:dq){
				
				cout<<it<<" ";
			}
			cout<<nl;
			
		}else if(st=="empty"){
			
			dq.clear();
			
		}
		
		
		
		
	}
	
	
	
	
	
	
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	 int _t; cin>>_t;while(_t--)
		solve();
	
	
	//cerr<<"Time elapsed: "<< 1.0*clock()/ CLOCKS_PER_SEC << "s.\n\n";
	
	
	
	
}


/* Priority Queue AZ101

    Time-Limit: 1 sec Score: 100.00/100

Difficulty :

    Memory: 256 MB Accepted Submissions: 100

Description

You are given Q queries and have to perform the following operations:

    add x - add element x at the top of Priority Queue
    remove - delete top element of the Priority Queue, if Priority Queue is not empty
    print - print the element at top of the Priority Queue, if Priority Queue is not empty, otherwise print 0

Input Format

The first line of the input contains one integer T - the number of test cases. Then T test cases follow.

The first line of each test case contains one integer Q - the number of queries.

Each of the next Q ines contains queries.

Output Format

For each test case, print the required queries.

Constraints

1≤ T ≤ 105

1≤ Q ≤ 105

1≤ X ≤ 106

It is guaranteed that the sum of Q over all test cases does not exceed 106.

Sample Input 1

1
6
add 4
add 5
add 3
print
remove
print

Sample Output 1

5
4

Note

    Priority Queue becomes [4]
    Priority Queue becomes [4, 5]
    Priority Queue becomes [3, 4, 5]
    Element at top = 5
    Priority Queue becomes [3, 4]
    Element at top = 4

*/

//wrong answer

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define ull unsigned long long int
#define mod 1000000007
#define inf 1e9
#define mt make_tuple
#define pb push_back
#define eb emplace_back
#define pob pop_back
#define f first
#define s second
#define nl "\n"
#define pi pair<int,int>
#define v vector<long long int>
#define vp vector<pair<int,int>>
#define vvl vector<vector<long long int>>
#define rep(n) for(int i=0 ; i<n ; i++)
#define rei(i) for(int i=n ; i>0 ; i--)
#define prio priority_queue
#define np next_permutation
#define N 200100

#define yes "YES"
#define no "NO"




 /*ll add(ll a,ll b){
	
	ll ans=(a+b)%mod;
	if(ans<0) ans+=mod;
	
	return ans;
}

 ll sub(ll a,ll b){
	
	ll ans=(a-b)%mod;
	if(ans<0) ans+=mod;
	
	return ans;
}

ll mul(ll a,ll b){
	
	ll ans=(a*b)%mod;
	if(ans<0) ans+=mod;
	
	return ans;
}*/


void solve(){
	
	prio<int>pq;
	
	int q;
	
	cin>>q;
	//string st;
	while(q--){
		
		
	string st;
	cin>>st;
	
	
		if(st=="add"){
			
			int x;
			cin>>x;
			
			pq.push(x);
			
		}else if(st=="remove"){
			
			// int x;
			// cin>>x;
			
			if(!pq.empty()){
				
				pq.pop();
				
			}
		
		}else if(st=="print"){
			
			if(!pq.empty()){
				
				cout<<pq.top()<<nl;
			}
			
		}
		
		
		
		
	}
	
	
	
	
	
	
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	 int _t; cin>>_t;while(_t--)
		solve();
	
	
	//cerr<<"Time elapsed: "<< 1.0*clock()/ CLOCKS_PER_SEC << "s.\n\n";
	
	
	
	
}

//right answer



#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define ull unsigned long long int
#define mod 1000000007
#define inf 1e9
#define mt make_tuple
#define pb push_back
#define eb emplace_back
#define pob pop_back
#define f first
#define s second
#define nl "\n"
#define pi pair<int,int>
#define v vector<long long int>
#define vp vector<pair<int,int>>
#define vvl vector<vector<long long int>>
#define rep(n) for(int i=0 ; i<n ; i++)
#define rei(i) for(int i=n ; i>0 ; i--)
#define prio priority_queue
#define np next_permutation
#define N 200100

#define yes "YES"
#define no "NO"




 /*ll add(ll a,ll b){
	
	ll ans=(a+b)%mod;
	if(ans<0) ans+=mod;
	
	return ans;
}

 ll sub(ll a,ll b){
	
	ll ans=(a-b)%mod;
	if(ans<0) ans+=mod;
	
	return ans;
}

ll mul(ll a,ll b){
	
	ll ans=(a*b)%mod;
	if(ans<0) ans+=mod;
	
	return ans;
}*/


void solve(){
	
	prio<int>pq;
	
	int q;
	
	cin>>q;
	//string st;
	while(q--){
		
		
	string st;
	cin>>st;
	
	
		if(st=="add"){
			
			int x;
			cin>>x;
			
			pq.push(x);
			
		}else if(st=="remove"){
			
			// int x;
			// cin>>x;
			
			if(!pq.empty()){
				
				pq.pop();
				
			}
		
		}else if(st=="print"){
			
			if(!pq.empty()){
				
				cout<<pq.top()<<nl;
			}else{
                
                cout<<'0'<<nl;
            }
			
		}
		
		
		
		
	}
	
	
	
	
	
	
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	 int _t; cin>>_t;while(_t--)
		solve();
	
	
	//cerr<<"Time elapsed: "<< 1.0*clock()/ CLOCKS_PER_SEC << "s.\n\n";
	
	
	
	
}



/* Set Queries AZ101

    Time-Limit: 1 sec Score: 1.00/100

Difficulty :*

    Memory: 256 MB Accepted Submissions: 100

Description

You have an empty set and can perform the following operations on it:

    1 x - Add integer x to the set
    2 x - Find the smallest integer that is not present in the set, which is greater than or equal to x.

Input Format

The first line of the input contains one integer T - the number of test cases. Then T test cases follow.

The first line of each test case contains one integer Q - the number of queries. 

Each of the next Q lines contain two space-separated integers ti and xi - type and value of the query.

Output Format

For each test case, print the answer for the queries.

Constraints

1≤ T ≤ 105

1≤ Q ≤ 105

1≤ ti ≤ 2

1≤ xi ≤ 1012

It is guaranteed that the sum of Q over all test cases does not exceed 106.

Sample Input 1

2
4
1 1
1 3
2 1
2 4
3
2 4
1 4
2 4

Sample Output 1

2
4
4
5

Note

For the first test case, the set is [1, 3]. Value which is not present and is ≥ 1 is 2 and ≥ 4 is 4.

For the second test case, the value which is not present and is ≥ 4 is 4. Then set becomes [4]. Value which is not present and is ≥ 4 is 5 now.

1

​*/


#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define ull unsigned long long int
#define mod 1000000007
#define inf 1e9
#define mt make_tuple
#define pb push_back
#define eb emplace_back
#define pob pop_back
#define f first
#define s second
#define nl "\n"
#define pi pair<int,int>
#define v vector<long long int>
#define vp vector<pair<int,int>>
#define vvl vector<vector<long long int>>
#define rep(n) for(int i=0 ; i<n ; i++)
#define rei(i) for(int i=n ; i>0 ; i--)
#define prio priority_queue
#define np next_permutation
#define N 200100

#define yes "YES"
#define no "NO"


void solve(){
	
	
	int q;
	cin>>q;
	
	set<ll>st;
	set<ll>st1;
	
	while(q--){
		
		int x;
		cin>>x;
		
		if(x==1){
			
			ll y;
			cin>>y;
			
			st.insert(y);
			st1.erase(y);
			
			if(st.find(y+1)==st.end()){
			    
			    st1.insert(y+1);
			}
			
			
			
		}else if(x==2){
			
			
			ll y;
			cin>>y;
			
			if(st.find(y)==st.end()){
			    
			    cout<<y<<nl;
			    
			    
			}else{
			   auto it=st1.upper_bound(y);
			   cout <<*it<<nl;
			    
			    
			    
			}
		
			
		}
		
		
		
	}
	
	
	
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	 int _t; cin>>_t;while(_t--)
		solve();
	
	
	//cerr<<"Time elapsed: "<< 1.0*clock()/ CLOCKS_PER_SEC << "s.\n\n";
	
	
	
	
}

/* Nearest Smaller Values AZ101

    Time-Limit: 1 sec Score: 1.00/100

Difficulty : *

    Memory: 256 MB Accepted Submissions: 100

Description

You are given an array of N integers. For each position, find the nearest position to its left having a smaller value. (1-based indexing)

Input Format

The first line of the input contains one integer T - the number of test cases. Then T test cases follow.

The first line of each test case contains one integer N - the length of the array. 

The second line of each test case contains N space-separated integers.

Output Format

For each test case, print N space-separated integers, for each position, the nearest position to its left having a smaller value.  If no position to its left has a smaller value, print 0.

Constraints

1≤ T ≤ 105

1≤ N ≤ 105

1≤ Ai ≤ 109

It is guaranteed that the sum of N over all test cases does not exceed 106.

Sample Input 1

3
5
3 5 1 6 2
4
1 1 2 1
5
1 3 2 6 6

Sample Output 1

0 1 0 3 3 
0 0 2 0 
0 1 1 3 3

Note

For the first test case, for 3 there is no smaller value, for 5, A[1] = 3, for 1, there is no smaller value, for 6 A[3] = 1, for 2, A[3] = 1.

For the second test case, for all 1 there is no smaller value, for 2, A[2] = 1.

For the third test case, for 1 there is no smaller value, for 3 and 2, A[1] = 1, for 6 and 6, A[3] = 2

*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define ull unsigned long long int
#define mod 1000000007
#define inf 1e9
#define mt make_tuple
#define pb push_back
#define eb emplace_back
#define pob pop_back
#define f first
#define s second
#define nl "\n"
#define pi pair<int,int>
#define v vector<long long int>
#define vp vector<pair<int,int>>
#define vvl vector<vector<long long int>>
#define rep(n) for(int i=0 ; i<n ; i++)
#define rei(i) for(int i=n ; i>0 ; i--)
#define prio priority_queue
#define np next_permutation
#define N 200100

#define yes "YES"
#define no "NO"


 
void solve(){
	
	ll n;
	cin>>n;
	ll arr[n];
	stack<ll>st;
	
	for(ll i=0;i<n;i++){
	    
	    cin>>arr[i];
	    
	    while(!st.empty()&&arr[st.top()]>=arr[i]){
	        
	        st.pop();
	        
	    }
	    
	    if(st.empty()){
	        
	    
	       
	       cout<<"0"<<" ";
	    }else{
	     
	       cout<<st.top()+1<<" ";
	    }
	    st.push(i); 
	}
	
	
	
	cout<<nl;
	
	
	
	
	
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	 int _t; cin>>_t;while(_t--)
		solve();
	
	
	//cerr<<"Time elapsed: "<< 1.0*clock()/ CLOCKS_PER_SEC << "s.\n\n";
	
	
	
	
}

/* The Magical Candy Bag AZ101

    Time-Limit: 1 sec Score: 100.00/100

Difficulty : *

    Memory: 256 MB Accepted Submissions: 100

Description

You have N magical candy bag. The i-th bag contains Ai candies. In each minute you can eat all the candies, Ai of one bag, after that, the candies become [Ai / 2] where [x] is the greatest integer less than x. You have K minutes, find the maximum number of candies you can eat.

Input Format

The first line of the input contains one integer T - the number of test cases. Then T test cases follow.

The first line of each test case contains two space-separated integers N, K - the number of bags and the number of minutes.

The second line of each test case contains N space-separated integers.

Output Format

For each test case, print the maximum number of candies you can eat.

Constraints

1≤ T ≤ 105

1≤ N ≤ 105

0≤ K ≤ 105

1≤ Ai ≤ 109

It is guaranteed that the sum of K over all test cases does not exceed 106.

Sample Input 1

3
4 2
4 3 5 1
1 2
4
6 3
3 2 2 5 1 2

Sample Output 1

9
6
10

Note

For the first test case, first take 5 candies then the bag becomes: [4, 3, 2, 1], and then take 4 candies to get a total 5+4 = 9 candies.

For the second test case, first take 4 candies, then bag becomes: [2] and then take 2 candies to get a total 4+2 = 6 candies.

For the third test case, first take 5 candies, then bag becomes: [3, 2, 2, 2, 1, 2] and then take 3 candies, then bag becomes: [1, 2, 2, 2, 1, 2], then take 2 candies to get a total 5+3+2 = 10 candies.

*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define ull unsigned long long int
#define mod 1000000007
#define inf 1e9
#define mt make_tuple
#define pb push_back
#define eb emplace_back
#define pob pop_back
#define f first
#define s second
#define nl "\n"
#define pi pair<int,int>
#define v vector<long long int>
#define vp vector<pair<int,int>>
#define vvl vector<vector<long long int>>
#define rep(n) for(int i=0 ; i<n ; i++)
#define rei(i) for(int i=n ; i>0 ; i--)
#define prio priority_queue
#define np next_permutation
#define N 200100

#define yes "YES"
#define no "NO"


void solve(){
	
ll n,k;
cin>>n>>k;

priority_queue<int>pq;

for(ll i=0;i<n;i++){
    
    ll x;
    cin>>x;
    pq.push(x);
}

ll ans=0;
while(k--){
    
    ll temp=pq.top();
   ans+=pq.top();
   pq.pop();
   pq.push(temp/2);
    
}



cout<<ans<<nl;



}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	 int _t; cin>>_t;while(_t--)
		solve();
	
	
	//cerr<<"Time elapsed: "<< 1.0*clock()/ CLOCKS_PER_SEC << "s.\n\n";
	
	
	
	
}


/* Towers AZ101

    Time-Limit: 1 sec Score: 1.00/100

Difficulty :*

    Memory: 256 MB Accepted Submissions: 100

Description

You are given N blocks. You have to build towers by placing blocks on top of each other with the condition that the upper block must be smaller than the lower block. You have to process the blocks in the given order. Find the minimum possible number of towers you can create.

Input Format

The first line of the input contains one integer T - the number of test cases. Then T test cases follow.

The first line of each test case contains one integer N - the length of the array. 

The second line of each test case contains N space-separated integers.

Output Format

For each test case, print the minimum possible number of towers you can create.

Constraints

1≤ T ≤ 105

1≤ N ≤ 105

1≤ Ai ≤ 109

It is guaranteed that the sum of N over all test cases does not exceed 106.

Sample Input 1

3
5
3 2 5 1 4
4
1 1 1 1
5
5 4 5 3 2 

Sample Output 1

2
4
2

Note

For the first test case, the towers would be: [3, 2, 1] and [5,4]

For the second test case, the towers would be: [1], [1], [1], [1]

For the third test case, the towers would be: [5, 4, 3] and [5, 2]

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define ull unsigned long long int
#define mod 1000000007
#define inf 1e9
#define mt make_tuple
#define pb push_back
#define eb emplace_back
#define pob pop_back
#define f first
#define s second
#define nl "\n"
#define pi pair<int,int>
#define v vector<long long int>
#define vp vector<pair<int,int>>
#define vvl vector<vector<long long int>>
#define rep(n) for(int i=0 ; i<n ; i++)
#define rei(i) for(int i=n ; i>0 ; i--)
#define prio priority_queue
#define np next_permutation
#define N 200100

#define yes "YES"
#define no "NO"


 
void solve(){
	
	int n;
	cin>>n;
	
	multiset<int>st;
	
	for(int i=0;i<n;i++){
		
		int x;
		
		cin>>x;
		
		
		auto it=st.upper_bound(x);
		
		if(it==st.end()){
			
			st.insert(x);
			
		}else{
			
			st.erase(it);
			st.insert(x);
			
			
		}
		
		
		
	}
	
	cout<<st.size()<<nl;
	
	
	
	
	
	
	
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	 int _t; cin>>_t;while(_t--)
		solve();
	
	
	//cerr<<"Time elapsed: "<< 1.0*clock()/ CLOCKS_PER_SEC << "s.\n\n";
	
	
	
	
}


/* Minimal String AZ101

    Time-Limit: 1 sec Score: 1.00/100

Difficulty :*

    Memory: 256 MB Accepted Submissions: 100

Description

You are given a string S along with 2 empty strings T and U. You can make the following two moves: pop first character of S and append it to T or pop last character of T and append it to U.

You need to make the string U lexicographically minimum such that string S and T are empty.

Input Format

The first line of the input contains one integer T - the number of test cases. Then T test cases follow.

The first line of each test contains a string S.

Output Format

For each test case, print the lexicographically minimum possible string U.

Constraints

1≤ T ≤ 106

1≤ |S| ≤ 106

It is guaranteed that the sum of |S| over all test cases does not exceed 106.

Sample Input 1

3
bdab
sss
gtddb

Sample Output 1

abdb
sss
bddtg

Note

For the first test case, S = bdab

    S = dab, T = b, U = 
    S = ab, T = bd, U = 
    S = b, T = bda, U = 
    S = b, T = bd, U = a
    S = , T = bd, U = ab
    S = , T = b, U = abd
    S = , T = , U = abdb

For the second test case, S = sss

    S = ss, T = s, U = 
    S = s, T = ss, U = 
    S = s, T = s, U = s
    S = , T = ss, U = s
    S = , T = s, U = ss
    S = , T = , U = sss

For the third test case, S = gtddb

    S = tddb, T = g, U = 
    S = ddb, T = gt, U = 
    S = db, T = gtd, U = 
    S = b, T = gtdd, U = 
    S = , T = gtddb, U = 
    S = , T = gtdd, U = b
    S = , T = gtd, U = bd
    S = , T = gt, U = bdd
    S = , T = g, U = bddt
    S = , T =, U = bddtg

*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define ull unsigned long long int
#define mod 1000000007
#define inf 1e9
#define mt make_tuple
#define pb push_back
#define eb emplace_back
#define pob pop_back
#define f first
#define s second
#define nl "\n"
#define pi pair<int,int>
#define v vector<long long int>
#define vp vector<pair<int,int>>
#define vvl vector<vector<long long int>>
#define rep(n) for(int i=0 ; i<n ; i++)
#define rei(i) for(int i=n ; i>0 ; i--)
#define prio priority_queue
#define np next_permutation
#define N 200100

#define yes "YES"
#define no "NO"




 /*ll add(ll a,ll b){
	
	ll ans=(a+b)%mod;
	if(ans<0) ans+=mod;
	
	return ans;
}

 ll sub(ll a,ll b){
	
	ll ans=(a-b)%mod;
	if(ans<0) ans+=mod;
	
	return ans;
}

ll mul(ll a,ll b){
	
	ll ans=(a*b)%mod;
	if(ans<0) ans+=mod;
	
	return ans;
}*/


void solve(){


string str;
stack<char>t;
string u="";

cin>>str;

ll n=str.size();

vector<char>arr(n);

arr[n-1]=str[n-1];

for(ll i=n-2;i>=0;i--){
   if(str[i]<arr[i+1]) arr[i]=str[i];
   else{
       arr[i]=arr[i+1];
   }
    
}


for(ll i=0;i<n;i++){
    
    if(i==0)t.push(str[i]);
    
    else {
        
        while(!t.empty()&&t.top()<=arr[i]){
            
            u+=t.top();
            t.pop();
        
        
          }
        t.push(str[i]);
    }
}

while(!t.empty()){
    
    u+=t.top();
    t.pop();
}

cout<<u<<nl;	
	
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	 int _t; cin>>_t;while(_t--)
		solve();
	
	
	//cerr<<"Time elapsed: "<< 1.0*clock()/ CLOCKS_PER_SEC << "s.\n\n";
	
	
	
	
}


/* Valid Parentheses AZ101

    Time-Limit: 1 sec Score: 75.00/100

Difficulty :**

    Memory: 256 MB Accepted Submissions: 100

Relevant For:

Description

You are given a string S. Find the minimum number of parentheses you should add to make the parentheses valid.

A parentheses is valid if:

    It is an empty string
    It can be written as AB where A and B are valid parentheses
    It can be written as (A) where is a valid parentheses

Input Format

The first line of the input contains one integer T - the number of test cases. Then T test cases follow.

The first line of each test case contains one string S.

Output Format

For each test case, print the minimum number of parentheses you should add to make the parentheses valid.

Constraints

1 ≤ T ≤ 2 x 105
1 ≤ |S| ≤ 105
It is guaranteed that the sum of |S| over all test cases does not exceed 106. 
Sample Input 1

3
(())))
()()(()
))((

Sample Output 1

2
1
4

Note

For the first test case, we need to add 2 opening brackets: (((())))

For the second test case, we need to add 1 closing bracket: ()()(())

For the third test case, we need two add 2 opening and 2 closing brackets: (())(())

*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve(){
    string s; cin >> s; int n  = s.length();
    int temp = 0;
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '(') temp++;
        else {
            if(temp) temp--;
            else ans++;
        }
    }
    cout << ans + temp << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //solve();
    int t; cin >> t; while(t--) solve();
    return 0;
}


//my code :
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define ull unsigned long long int
#define mod 1000000007
#define inf 1e9
#define mt make_tuple
#define pb push_back
#define eb emplace_back
#define pob pop_back
#define f first
#define s second
#define nl "\n"
#define pi pair<int,int>
#define v vector<long long int>
#define vp vector<pair<int,int>>
#define vvl vector<vector<long long int>>
#define rep(n) for(int i=0 ; i<n ; i++)
#define rei(i) for(int i=n ; i>0 ; i--)
#define prio priority_queue
#define np next_permutation
#define N 200100

#define yes "YES"
#define no "NO"




 /*ll add(ll a,ll b){
	
	ll ans=(a+b)%mod;
	if(ans<0) ans+=mod;
	
	return ans;
}

 ll sub(ll a,ll b){
	
	ll ans=(a-b)%mod;
	if(ans<0) ans+=mod;
	
	return ans;
}

ll mul(ll a,ll b){
	
	ll ans=(a*b)%mod;
	if(ans<0) ans+=mod;
	
	return ans;
}*/


void solve(){
	
	
	string s;
	cin>>s;
	
	int n=s.length();
	
	map<char,int>mp;
	
	 mp['(']=1;
	mp[')']=-1;
	
	stack<int>st;
	int cnt=0;
	
	for(auto it:s){
		
		int x=mp[it];
		
	if(it=='('){	st.push(mp[it]);
	
		
	}else{
		if(!st.empty()&&st.top()+x==0){
			
			st.pop();
			
			cnt-=2;
		
		}else{
			
			st.push(mp[it]);
		}
		
	}
		
		cnt++;
		
	}
		
		
	cout<<cnt<<nl;	
	
	
	
	
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	 int _t; cin>>_t;while(_t--)
		solve();
	
	
	//cerr<<"Time elapsed: "<< 1.0*clock()/ CLOCKS_PER_SEC << "s.\n\n";
	
	
	
	
}


/* Maximum in Window

    Time-Limit: 1 sec Score: 100.00/100

Difficulty :

    Memory: 256 MB Accepted Submissions: 100

Relevant For:

Description

You have given an array A of size N and a positive integer K (≤ N). A1, A2, ..., AN are the elements of the array.
Let Bi = max (Ai, Ai+1, ..., Ai+K-1), for 1 ≤ i ≤ N - K + 1. 
Find Bi values for all is such that 1 ≤ i ≤ N - K + 1.

Input Format

The first line contains T, the number of test cases. 
The first line of each test case contains N, the number of integers in an array A and K.
The second line of each test case contains N space-separated integers A1, A2, ..., AN.

Output Format

For each test case, print array B as B1 B2 ... BN-K+1 in a new line.

Constraints

1 ≤ T ≤ 100000
1 ≤ K ≤ N ≤ 100000
-109 ≤ Ai ≤ 109
Sum of N over all test cases ≤ 5 * 105.
Sample Input 1

4

9 3

1 2 3 1 4 5 2 3 6

5 5

1 -4 3 -3 -9

4 1

-3 1 -8 3

5 2

-1 -1 -1 -1 -1

Sample Output 1

3 3 4 5 5 5 6

3

-3 1 -8 3

-1 -1 -1 -1

Note

Explanation 1:
B1 = max(1, 2, 3) = 3
B2 = max(2, 3, 1) = 3
B3 = max(3, 1, 4) = 4
B4 = max(1, 4, 5) = 5
B5 = max(4, 5, 2) = 5
B6 = max(5, 2, 3) = 5
B7 = max(2, 3, 6) = 6

Explanation 2:
B1 = max(1, -4, 3, -3, -9) = 3

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define ull unsigned long long int
#define mod 1000000007
#define inf 1e9
#define mt make_tuple
#define pb push_back
#define eb emplace_back
#define pob pop_back
#define f first
#define s second
#define nl "\n"
#define pi pair<int,int>
#define v vector<long long int>
#define vp vector<pair<int,int>>
#define vvl vector<vector<long long int>>
#define rep(n) for(int i=0 ; i<n ; i++)
#define rei(i) for(int i=n ; i>0 ; i--)
#define prio priority_queue
#define np next_permutation
#define N 200100

#define yes "YES"
#define no "NO"




 /*ll add(ll a,ll b){
	
	ll ans=(a+b)%mod;
	if(ans<0) ans+=mod;
	
	return ans;
}

 ll sub(ll a,ll b){
	
	ll ans=(a-b)%mod;
	if(ans<0) ans+=mod;
	
	return ans;
}

ll mul(ll a,ll b){
	
	ll ans=(a*b)%mod;
	if(ans<0) ans+=mod;
	
	return ans;
}*/


void solve(){
	
	int n,k;
	cin>>n>>k;
	v a(n);
	
	
	for(int i=0;i<n;i++){
		
		cin>>a[i];
	}
	
	
	multiset<int>mt;
	
	
	for(int i=0;i<n;i++){
		
		
		mt.insert(a[i]);
		
		if(i>=k){
			
			mt.erase(mt.find(a[i-k]));
		}
		
		if(i>=k-1) cout<<*mt.rbegin()<<" ";
		
		
		
		
	}
	
	cout<<nl;
	
	
	
	
	
	
	
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	int _t; cin>>_t;while(_t--)
		solve();
	
	
	//cerr<<"Time elapsed: "<< 1.0*clock()/ CLOCKS_PER_SEC << "s.\n\n";
	
	
	
	
}

/* Buy Maximum Objects I

    Time-Limit: 1 sec Score: 100.00/100

Difficulty :*

    Memory: 256 MB Accepted Submissions: 100

Relevant For:

Description

There are N objects, and each object has some price. The price of ith object is Ai.
You have total money M, and you want to buy as many objects as possible.
Find the maximum objects that you can buy?

Input Format

The first line contains T, the number of test cases.
The first line of each test case contains N, the number of objects, and M, the money you have.
The second line of each test case contains N space-separated integers A1, A2, ..., AN.

Output Format

For each test case, print a single number representing the maximum objects that you can buy.

Constraints

1 ≤ T ≤ 105
1 ≤ N ≤ 105
1 ≤ Ai ≤ 108
1 ≤ M ≤ 108
Sum of N over all test cases ≤ 5 * 105.
Sample Input 1

3

5 5

1 3 2 4 5

5 10

1 3 2 4 5

5 20

1 3 2 4 5

Sample Output 1

2

4

5

Note

Explanation 1:
Buy Objects with prices 1, 2.

Explanation 2:
Buy Objects with prices 1, 2, 3, 4.

Explanation 3:
Buy all objects.

*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define ull unsigned long long int
#define mod 1000000007
#define inf 1e9
#define mt make_tuple
#define pb push_back
#define eb emplace_back
#define pob pop_back
#define f first
#define s second
#define nl "\n"
#define pi pair<int,int>
#define v vector<long long int>
#define vp vector<pair<int,int>>
#define vvl vector<vector<long long int>>
#define rep(n) for(int i=0 ; i<n ; i++)
#define rei(i) for(int i=n ; i>0 ; i--)
#define prio priority_queue
#define np next_permutation
#define N 200100

#define yes "YES"
#define no "NO"




 /*ll add(ll a,ll b){
	
	ll ans=(a+b)%mod;
	if(ans<0) ans+=mod;
	
	return ans;
}

 ll sub(ll a,ll b){
	
	ll ans=(a-b)%mod;
	if(ans<0) ans+=mod;
	
	return ans;
}

ll mul(ll a,ll b){
	
	ll ans=(a*b)%mod;
	if(ans<0) ans+=mod;
	
	return ans;
}*/


void solve(){
	
	ll n,m;
	
	cin>>n>>m;
	
   vector<ll>a(n);
	
	for(ll i=0;i<n;i++){
		
		cin>>a[i];
		
	}
	
	ll cnt=0;
	ll ans=0;
	
	sort(a.begin(),a.end());
	
	for(ll i=0;i<n;i++){
		
		  if(ans+a[i]<=m){
			
				cnt++;
			ans+=a[i];
			
		
		}else if(ans==m){
			
			break;
			
		}
		
		
	}
	
	cout<<cnt<<nl;
	
	
	
	
	
	
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
 int _t; cin>>_t;while(_t--)
		solve();
	
	
	//cerr<<"Time elapsed: "<< 1.0*clock()/ CLOCKS_PER_SEC << "s.\n\n";
	
	
	
	
}

/* Students and Grades

    Time-Limit: 2 sec Score: 100.00/100

Difficulty :*

    Memory: 256 MB Accepted Submissions: 100

Relevant For:

Description

There are N students in section A. The i-th student got Ai marks. The class teacher of section B was absent so sections A and B were merged. The students of section B did not want to humiliate themselves, so they decided to sit with students having the same marks as them. You are given the marks of students of section B in order of their entry in the class. You have to tell whether the i-th student of section B can sit with a student with the same marks as him. If there is at least 1 person in the room with the same marks, print ‘YES’ else print ‘NO’. (without the quotes)

See Sample Test Cases.

Input Format

The first line of the input contains one integer T - the number of test cases. Then T test cases follow.
The first line of each test case contains two space-separated integers N and M - the number of students in sections A and B respectively.
The second line of each test case contains N space-separated integers A1, A2, …, AN - the grades of students of section A.
The third line of each test case contains M space-separated integers B1, B2, …, BM - the grades of students of section B.

Output Format

For each test case, print M strings on a new line. Print ‘YES’ if there is at least 1 person in the room with the same IQ. Otherwise, print ‘NO’. (without the quotes)

Constraints

1≤ T ≤ 10
1≤ N, M ≤ 105
1≤ Ai , Bi ≤ 1012
Sample Input 1

2

3 5

2 5 4

7 4 1 4 5

4 4

1 1 8 2

8 3 3 5

Sample Output 1

NO

YES

NO

YES

YES

YES

NO

YES

NO

Note

In the first test case of the example, when the first student enters, there is no student with 7 marks.
When the second student enters, there is 1 student with 4 marks.
When the third student enters, there is no student with 1 mark.
When the fourth student enters, there are 2 students with 4 marks.
When the fifth student enters, there is 1 student with 5 marks.

*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define ull unsigned long long int
#define mod 1000000007
#define inf 1e9
//#define mt make_tuple
#define pb push_back
#define eb emplace_back
#define pob pop_back
#define f first
#define s second
#define nl "\n"
#define pi pair<int,int>
//#define v vector<long long int>
#define vp vector<pair<int,int>>
#define vvl vector<vector<long long int>>
#define rep(n) for(int i=0 ; i<n ; i++)
#define rei(i) for(int i=n ; i>0 ; i--)
#define prio priority_queue
#define np next_permutation
#define N 200100

#define yes "YES"
#define no "NO"




 /*ll add(ll a,ll b){
	
	ll ans=(a+b)%mod;
	if(ans<0) ans+=mod;
	
	return ans;
}

 ll sub(ll a,ll b){
	
	ll ans=(a-b)%mod;
	if(ans<0) ans+=mod;
	
	return ans;
}

ll mul(ll a,ll b){
	
	ll ans=(a*b)%mod;
	if(ans<0) ans+=mod;
	
	return ans;
}*/


void solve(){
	
	int n,m;
	
	cin>>n>>m;
	
	vector<int>a(n);
	vector<int>b(m);
	
	unordered_map<int ,int>mp;
	
	for(int i=0;i<n;i++){
		
		cin>>a[i];
		
		
	}
	
	for(int i=0;i<m;i++){
		
		
		cin>>b[i];
	}
	
	
	
	
	
	for(int i=0;i<n;i++){
		
		mp.insert({a[i],1});
		
		
		
		//mp(a[i])=1;
		
		
	}
	
		
		
	// for(auto it:mp){
		
	// 	cout<<it.first<<" "<<it.second<<endl;
		
		
	//  }
	
	
	for(auto it:b){
		
		mp[it]++;
		
	if(mp[it]>1)	{
	    
	    cout<<yes<<nl;
	}else{
	    
	    cout<<no<<nl;
	}
		
	}
	
	
	
	
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	int _t; cin>>_t;while(_t--)
		solve();
	
	
	//cerr<<"Time elapsed: "<< 1.0*clock()/ CLOCKS_PER_SEC << "s.\n\n";
	
	
	
	
}


/* Multimap AZ101

    Time-Limit: 1 sec Score: 100.00/100

Difficulty :

    Memory: 256 MB Accepted Submissions: 100

Description

You are given Q queries and have to perform the following operations:

    add x y - add student name X (string) for marks y (integer). If it already exists, add a new entry.
    erase x - erase the first current entry of student with name x
    eraseall x - erase all entries of student with name x
    print x - print the first entry of marks of student with name x, if entry is not there for x, print 0.

Input Format

The first line of the input contains one integer T - the number of test cases. Then T test cases follow.

The first line of each test case contains one integer Q - the number of queries.

Each of the next Q ines contains queries.

Output Format

For each test case, print the required queries.

Constraints

1≤ T ≤ 105

1≤ Q ≤ 105

1≤ X ≤ 106

It is guaranteed that the sum of Q over all test cases does not exceed 105.

Sample Input 1

1
9
add alice 24
add bob 21
add alice 23
add alice 22
print alice
erase alice
print alice
eraseall alice
print alice

Sample Output 1

24
23
0

Note

    Map becomes: [alice: 24]
    Map becomes: [alice: 24, bob: 21]
    Map becomes: [alice: 24, bob: 21, alice: 23]
    Map becomes: [alice: 24, bob: 21, alice: 23, alice: 22]
    alice: 24
    Map becomes: [bob: 21, alice: 23, alice: 22] (since first entry of alice is removed)
    alice: 23
    Map becomes: [bob: 21]
    key alice doesn't exist, hence alice: 0

*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define ull unsigned long long int
#define mod 1000000007
#define inf 1e9
#define mt make_tuple
#define pb push_back
#define eb emplace_back
#define pob pop_back
#define f first
#define s second
#define nl "\n"
#define pi pair<int,int>
#define v vector<long long int>
#define vp vector<pair<int,int>>
#define vvl vector<vector<long long int>>
#define rep(n) for(int i=0 ; i<n ; i++)
#define rei(i) for(int i=n ; i>0 ; i--)
#define prio priority_queue
#define np next_permutation
#define N 200100

#define yes "YES"
#define no "NO"




 /*ll add(ll a,ll b){
	
	ll ans=(a+b)%mod;
	if(ans<0) ans+=mod;
	
	return ans;
}

 ll sub(ll a,ll b){
	
	ll ans=(a-b)%mod;
	if(ans<0) ans+=mod;
	
	return ans;
}

ll mul(ll a,ll b){
	
	ll ans=(a*b)%mod;
	if(ans<0) ans+=mod;
	
	return ans;
}*/


void solve(){


multimap<string,int>mp;

ll q;
cin>>q;

while(q--){
    
    string x,z;
    ll y;
    
    cin>>z;
    if(z=="add"){
        
        cin>>x>>y;
        
      mp.insert(make_pair(x,y));
    }
    
    else if(z=="print"){
        
        cin>>x;
        
        auto it = mp.find(x);
        if (it != mp.end()) cout << (*it).s<< nl;
        else cout<<0<<nl;
        
    }else if(z=="erase"){
        
        cin>>x;
            auto it = mp.find(x);
            if (it != mp.end()) mp.erase(it);
        
    }else if(z=="eraseall"){
        
        cin>>x;
        mp.erase(x);
        
    }
    
    
    
}


}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	 int _t; cin>>_t;while(_t--)
		solve();
	
	
	//cerr<<"Time elapsed: "<< 1.0*clock()/ CLOCKS_PER_SEC << "s.\n\n";
	
	
	
	
}

//runtime error:
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define ull unsigned long long int
#define mod 1000000007
#define inf 1e9
#define mt make_tuple
#define pb push_back
#define eb emplace_back
#define pob pop_back
#define f first
#define s second
#define nl "\n"
#define pi pair<int,int>
#define v vector<long long int>
#define vp vector<pair<int,int>>
#define vvl vector<vector<long long int>>
#define rep(n) for(int i=0 ; i<n ; i++)
#define rei(i) for(int i=n ; i>0 ; i--)
#define prio priority_queue
#define np next_permutation
#define N 200100

#define yes "YES"
#define no "NO"




 /*ll add(ll a,ll b){
	
	ll ans=(a+b)%mod;
	if(ans<0) ans+=mod;
	
	return ans;
}

 ll sub(ll a,ll b){
	
	ll ans=(a-b)%mod;
	if(ans<0) ans+=mod;
	
	return ans;
}

ll mul(ll a,ll b){
	
	ll ans=(a*b)%mod;
	if(ans<0) ans+=mod;
	
	return ans;
}*/


void solve(){


multimap<string,int>mp;

ll q;
cin>>q;

while(q--){
    
    string x,z;
    ll y;
    
    cin>>z;
    if(z=="add"){
        
        cin>>x>>y;
        
      mp.insert(make_pair(x,y));
    }
    
    else if(z=="print"){
        
        cin>>x;
        
        auto it = mp.find(x);
        if (it != mp.end()) cout << it->s<< nl;
        else cout<<0<<nl;
        
    }else if(z=="erase"){
        
        cin>>x;
        mp.erase(mp.find(x));
        
    }else if(z=="eraseall"){
        
        cin>>x;
        mp.erase(x);
        
    }
    
    
    
}


}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	 int _t; cin>>_t;while(_t--)
		solve();
	
	
	//cerr<<"Time elapsed: "<< 1.0*clock()/ CLOCKS_PER_SEC << "s.\n\n";
	
	
	
	
}

/* Good Sequence AZ101

    Time-Limit: 1 sec Score: 100.00/100

Difficulty :*

    Memory: 256 MB Accepted Submissions: 100

Description

You are given an array A of N integers. A sequence is called good if the value x occurs x times in the array. Find the minimum number of integers you need to delete from A to make it good.

Input Format

The first line of the input contains one integer T - the number of test cases. Then T test cases follow.

The first line of each test case contains one integer N - the length of the array. 

The second line of each test case contains N space-separated integers.

Output Format

For each test case, print the minimum number of integers you need to delete from A to make it good.

Constraints

1≤ T ≤ 105

1≤ N ≤ 105

1≤ Ai ≤ 109

It is guaranteed that the sum of N over all test cases does not exceed 106.

Sample Input 1

3
5
3 2 3 3 1
4
3 2 2 4
5
6 6 1 1 2

Sample Output 1

1
2
4

Note

For the first test case, remove 2

For the second test case, remove 3 and 4

For the third test case, remove 6, 6, 1 and 2

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define ull unsigned long long int
#define mod 1000000007
#define inf 1e9
#define mt make_tuple
#define pb push_back
#define eb emplace_back
#define pob pop_back
#define f first
#define s second
#define nl "\n"
#define pi pair<int,int>
#define v vector<long long int>
#define vp vector<pair<int,int>>
#define vvl vector<vector<long long int>>
#define rep(n) for(int i=0 ; i<n ; i++)
#define rei(i) for(int i=n ; i>0 ; i--)
#define prio priority_queue
#define np next_permutation
#define N 200100

#define yes "YES"
#define no "NO"




 /*ll add(ll a,ll b){
	
	ll ans=(a+b)%mod;
	if(ans<0) ans+=mod;
	
	return ans;
}

 ll sub(ll a,ll b){
	
	ll ans=(a-b)%mod;
	if(ans<0) ans+=mod;
	
	return ans;
}

ll mul(ll a,ll b){
	
	ll ans=(a*b)%mod;
	if(ans<0) ans+=mod;
	
	return ans;
}*/


void solve(){

ll n;

cin>>n;

unordered_map<ll,ll>mp;

for(ll i=0;i<n;i++){
    
    ll x;
    cin>>x;
    
    mp[x]++;
    
    
}

ll cnt=0;

for(auto it:mp){
    
    if(it.s<it.f)cnt+=it.s;
    else if(it.s>it.f)cnt+=(it.s-it.f);
}

cout<<cnt<<nl;


    
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	 int _t; cin>>_t;while(_t--)
		solve();
	
	
	//cerr<<"Time elapsed: "<< 1.0*clock()/ CLOCKS_PER_SEC << "s.\n\n";
	
	
	
	
}


/* Buy Maximum Objects II

    Time-Limit: 1 sec Score: 75.00/100

Difficulty :**

    Memory: 256 MB Accepted Submissions: 100

Relevant For:

Description

There are N objects, and each object has some price. The price of ith object is Ai.
You have been asked Q queries. In each query, you have been given total money M, and find the maximum number of objects that you can buy.

Input Format

The first line of each test case contains N, the number of objects, and Q, total queries.
The second line of each test case contains N space-separated integers A1, A2, ..., AN.
Next, Q lines contain a number M, the total money.

Output Format

For each query, print a single number in a new line representing the maximum objects that you can buy.

Constraints

1 ≤ N, Q ≤ 105
1 ≤ Ai ≤ 108
1 ≤ M ≤ 108
Sample Input 1

5 4
1 4 2 9 6
1
5
10
25

Sample Output 1

1
2
3
5

Note

M = 1, buy Object with price 1.
M = 5, buy Objects with prices 1, 4.
M = 10, buy Objects with prices 1, 2, 4.
M = 25, buy Objects with prices 1, 2, 4, 9, 6.

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define ull unsigned long long int
#define mod 1000000007
#define inf 1e9
#define mt make_tuple
#define pb push_back
#define eb emplace_back
#define pob pop_back
#define f first
#define s second
#define nl "\n"
#define pi pair<int,int>
#define v vector<long long int>
#define vp vector<pair<int,int>>
#define vvl vector<vector<long long int>>
#define rep(n) for(int i=0 ; i<n ; i++)
#define rei(i) for(int i=n ; i>0 ; i--)
#define prio priority_queue
#define np next_permutation
#define N 200100

#define yes "YES"
#define no "NO"




 /*ll add(ll a,ll b){
	
	ll ans=(a+b)%mod;
	if(ans<0) ans+=mod;
	
	return ans;
}

 ll sub(ll a,ll b){
	
	ll ans=(a-b)%mod;
	if(ans<0) ans+=mod;
	
	return ans;
}

ll mul(ll a,ll b){
	
	ll ans=(a*b)%mod;
	if(ans<0) ans+=mod;
	
	return ans;
}*/


void solve(){
	
	ll n,q;
	
	cin>>n>>q;
	
	
	v a(n);
	for(ll i=0;i<n;i++){
		
		
		cin>>a[i];
	}
	
	
	
	
	sort(a.begin(),a.end());
	
	
	
	for(ll i=1;i<n;i++){
		
		
		a[i]+=a[i-1];
		
		
	}
	
	
	
	ll cnt=0;
	
	int ans=0;
	
	
	for(ll i=0;i<q;i++){
		
		 ll m;
		 cin>>m;
		 
		 auto it=upper_bound(a.begin(),a.end(),m)-a.begin();
		// it-=1;
		 cout<<it<<nl;
		
		
	}
	
	
	
	
	
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	
	
	// int _t; cin>>_t;while(_t--)
		solve();
	
	
	//cerr<<"Time elapsed: "<< 1.0*clock()/ CLOCKS_PER_SEC << "s.\n\n";
	
	
	
	
}

/* STL Searching

    Time-Limit: 1 sec Score: 100.00/100

Difficulty :

    Memory: 256 MB Accepted Submissions: 100

Description

You are given an array A of size N. You have to answer the following queries

    1 x - Find the smallest Element ≥ x 
    2 x - Find the smallest Element > x 
    3 x - Find the number of elements ≤ x
    4 x - Find the number of elements < x

If the answer does not exist print -1.

Input Format

The first line of the input contains one integer T - the number of test cases. Then T test cases follow.

The first line of each test case contains two space-separated integers N Q - the size of the given array and the number of queries

The second line of each test case contains N space-separated integers.

Each of the next Q lines contains the queries in the form of t x.

Output Format

For each test case, print the answer of the required queries.

Constraints

1≤ T ≤ 105

1≤ N, Q ≤ 105

1≤ Ai ≤ 106

1≤ t ≤ 4

1≤ x ≤ 106

It is guaranteed that the sum of Q over all test cases does not exceed 105.

Sample Input 1

2
5 4
1 2 2 3 4
1 2
2 2
3 4
3 2
3 2
5 5 5
3 5
4 5

Sample Output 1

2 3 5 3 
3 0 

Sample Input 2

1
5 4
1 2 3 4 5
1 5
1 6
3 2
3 0

Sample Output 2

5 -1 2 0

Note

For the first test case, 

    The smallest element ≥ 2 is 2
    The smallest element > 2 is 3
    The number of elements ≤ 4 is 5 (1, 2, 2, 3, 4)
    The number of elements ≤ 2 is 3 (1, 2, 2)

*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define ull unsigned long long int
#define mod 1000000007
#define inf 1e9
#define mt make_tuple
#define pb push_back
#define eb emplace_back
#define pob pop_back
#define f first
#define s second
#define nl "\n"
#define pi pair<int,int>
#define v vector<long long int>
#define vp vector<pair<int,int>>
#define vvl vector<vector<long long int>>
#define rep(n) for(int i=0 ; i<n ; i++)
#define rei(i) for(int i=n ; i>0 ; i--)
#define prio priority_queue
#define np next_permutation
#define N 200100

#define yes "YES"
#define no "NO"




 /*ll add(ll a,ll b){
	
	ll ans=(a+b)%mod;
	if(ans<0) ans+=mod;
	
	return ans;
}

 ll sub(ll a,ll b){
	
	ll ans=(a-b)%mod;
	if(ans<0) ans+=mod;
	
	return ans;
}

ll mul(ll a,ll b){
	
	ll ans=(a*b)%mod;
	if(ans<0) ans+=mod;
	
	return ans;
}*/


void solve(){
	
	ll n,q;
	cin>>n>>q;
	
	v a(n);
	
	for(ll i=0;i<n;i++){
		
		
		cin>>a[i];
		
	}
	
	
	sort(a.begin(),a.end());
	
	while(q--){
		
		
		int t;
		cin>>t;
		
		
		if(t==1){
			
			ll x;
			cin>>x;
			
			auto it=lower_bound(a.begin(),a.end(),x)-a.begin();
			
			
			if(it!=n){
			cout<<a[it];}else{
			    
			    cout<<-1;
			}
			
			
			
			
		}else if(t==2){
		    
		    ll x;
		    cin>>x;
		    
		    
		    auto it=upper_bound(a.begin(),a.end(),x)-a.begin();
		    if(it!=n){
		        
		        cout<<a[it];
		        
		    }else{
		        
		        
		        cout<<-1;
		    }
		    
		    
		}else if(t==3){
		    
		    ll x;
		    cin>>x;
		    
		    
		    auto it=upper_bound(a.begin(),a.end(),x)-a.begin();
		    
		    cout<<it;
		}else if(t==4){
		    
		    
		    ll x;
		    cin>>x;
		    
		    	auto it=lower_bound(a.begin(),a.end(),x)-a.begin();
		    	
		    	cout<<it;
		    
		}
		
		
		cout<<" ";
		
		
	}
	
	cout<<nl;
	
	
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
 int _t; cin>>_t;while(_t--)
		solve();
	
	
	//cerr<<"Time elapsed: "<< 1.0*clock()/ CLOCKS_PER_SEC << "s.\n\n";
	
	
	
	
}
//editorial code :
#include <bits/stdc++.h>
using namespace std;

#define IOS                \
  ios::sync_with_stdio(0); \
  cin.tie(0);              \
  cout.tie(0);

int main() {
  IOS int t;
  cin >> t;
  while (t--) {
    int n, q;
    cin >> n >> q;
    int a[n];
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    sort(a, a + n);
    while (q--) {
      int t, x;
      cin >> t >> x;
      if (t == 1) {
        int i = lower_bound(a, a + n, x) - a;
        if (i == n)
          cout << "-1 ";
        else
          cout << a[i] << " ";
      } else if (t == 2) {
        int i = upper_bound(a, a + n, x) - a;
        if (i == n)
          cout << "-1 ";
        else
          cout << a[i] << " ";
      } else if (t == 3) {
        auto it = upper_bound(a, a + n, x) - a;
        cout << it << " ";
      } else {
        auto it = lower_bound(a, a + n, x) - a;
        cout << it << " ";
      }
    }
    cout << "\n";
  }
  return 0;
}


/* Collisions

    Time-Limit: 1 sec Score: 50.00/100

Difficulty :

    Memory: 256 MB Accepted Submissions: 100

Relevant For:

Description

There are N balls on the X-axis and M balls on the Y-axis. At the time, t=0, each ball on X-axis is thrown parallel to the Y-axis in the positive Y direction. Similarly, each ball on Y-axis is thrown parallel to the X-axis in the positive X direction. At any time, if two balls collide, they disappear. A collision can only happen between the ball thrown from X-axis and the ball thrown from Y-axis. No two balls from X-axis or Y-axis can collide. A ball can take part in at max one collision. You have to find the total number of collisions. 

Input Format

The first line of the input contains one integer T - the number of test cases. Then T test cases follow.
The first line of each test case contains two space-separated integers N and M - the number of balls on the X-axis and Y-axis respectively.
For each test case, N lines follow. The i-th of the line contains two space-separated integers Xi and Ui, the position and speed of the i-th ball respectively.
For each test case, M lines follow. The i-th of the line contains two space-separated integers Yi and Vi, the position and speed of the i-th ball respectively.

Output Format

For each test case, print the number of collisions on a separate line.

Constraints

1≤ T ≤ 100
1≤ N, M ≤ 105
1≤ Xi, Ui, Yi, Vi ≤ 109
Sample Input 1

3
1 1 
1 3 
3 1 
2 1 
1 4 
1 3 
4 1 
2 3 
1 2 
2 3 
1 6 
2 1 
6 1

Sample Output 1

1
1
2

Note

In the first test case of the example, at t=1 the balls collide. The number of collisions is 1.

In the second test case of the example, at t=1, the first ball on X-axis and the first ball on Y-axis collide and disappear. The number of collisions is 1.

In the third test case of the example, at t=⅓, the second ball on X-axis and the first ball on Y-axis collide and disappear. At t=1, the first ball on X-axis and the second ball on Y-axis collide and disappear. The number of collisions is 2.

*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define ull unsigned long long int
#define mod 1000000007
#define inf 1e9
#define mt make_tuple
#define pb push_back
#define eb emplace_back
#define pob pop_back
#define f first
#define s second
#define nl "\n"
#define pi pair<int,int>
//#define v vector<long long int>
#define vp vector<pair<int,int>>
#define vvl vector<vector<long long int>>
#define rep(n) for(int i=0 ; i<n ; i++)
#define rei(i) for(int i=n ; i>0 ; i--)
#define prio priority_queue
#define np next_permutation
#define N 200100

#define yes "YES"
#define no "NO"




 /*ll add(ll a,ll b){
	
	ll ans=(a+b)%mod;
	if(ans<0) ans+=mod;
	
	return ans;
}

 ll sub(ll a,ll b){
	
	ll ans=(a-b)%mod;
	if(ans<0) ans+=mod;
	
	return ans;
}

ll mul(ll a,ll b){
	
	ll ans=(a*b)%mod;
	if(ans<0) ans+=mod;
	
	return ans;
}*/


void solve(){

ll n,m;

cin>>n>>m;
 unordered_map<ll,ll>mp;
 
 while(n--){
     ll x,u;
     cin>>x>>u;
     
     ll mul=x*u;
     
     mp[mul]++;
     
 }
 

 
 ll cnt=0;
while(m--){
    
    ll y,v;
    cin>>y>>v;
    
    ll mul=y*v;
    
    if(!mp.empty()&&mp.find(mul)!=mp.end()){
       
       mp[mul]--;
        cnt++;
        
        if(mp[mul]==0)mp.erase(mul);
    }
    
    
    
}


cout<<cnt<<nl;

}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	 int _t; cin>>_t;while(_t--)
		solve();
	
	
	//cerr<<"Time elapsed: "<< 1.0*clock()/ CLOCKS_PER_SEC << "s.\n\n";
	
	
	
	
}

/* Concatenate Array AZ101

    Time-Limit: 1 sec Score: 50.00/100

Difficulty :

    Memory: 256 MB Accepted Submissions: 100

Description

You are given an array A of N integers. Find the length of the largest increasing subsequence if the array A is concatenated to itself N times. A sequence A is a subsequence of an array B if A can be obtained from B by deletion of several (possibly, zero or all) elements. The longest increasing subsequence should be strictly increasing.

Input Format

The first line of the input contains one integer T - the number of test cases. Then T test cases follow.

The first line of each test case contains one integer N - the length of the array. 

The second line of each test case contains N space-separated integers.

Output Format

For each test case, print the length of the largest increasing subsequence if the array A is concatenated to itself N times. 

Constraints

1≤ T ≤ 2*105

1≤ N ≤ 106

1≤ Ai ≤ 109

It is guaranteed that the sum of N over all test cases does not exceed 106.

Sample Input 1

3
3
2 1 3
5
3 1 1 1 4
4
3 2 1 4

Sample Output 1

3
3
4

Note

For the first test case, 2 1 3 2 1 3 2 1 3

For the second test case, 3 1 1 1 4 3 1 1 1 4 3 1 1 1 4 3 1 1 1 4 3 1 1 1 4

For the third test case, 3 2 1 4 3 2 1 4 3 2 1 4 3 2 1 4

*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define ull unsigned long long int
#define mod 1000000007
#define inf 1e9
#define mt make_tuple
#define pb push_back
#define eb emplace_back
#define pob pop_back
#define f first
#define s second
#define nl "\n"
#define pi pair<int,int>
//#define v vector<long long int>
#define vp vector<pair<int,int>>
#define vvl vector<vector<long long int>>
#define rep(n) for(int i=0 ; i<n ; i++)
#define rei(i) for(int i=n ; i>0 ; i--)
#define prio priority_queue
#define np next_permutation
#define N 200100

#define yes "YES"
#define no "NO"




 /*ll add(ll a,ll b){
	
	ll ans=(a+b)%mod;
	if(ans<0) ans+=mod;
	
	return ans;
}

 ll sub(ll a,ll b){
	
	ll ans=(a-b)%mod;
	if(ans<0) ans+=mod;
	
	return ans;
}

ll mul(ll a,ll b){
	
	ll ans=(a*b)%mod;
	if(ans<0) ans+=mod;
	
	return ans;
}*/


void solve(){

ll n;
cin>>n;

set<ll>st;
while(n--){
    
    ll x;
    cin>>x;
    st.insert(x);
    
}

cout<<st.size()<<nl;


}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	 int _t; cin>>_t;while(_t--)
		solve();
	
	
	//cerr<<"Time elapsed: "<< 1.0*clock()/ CLOCKS_PER_SEC << "s.\n\n";
	
	
	
	
}

/* Indexed Set

    Time-Limit: 1 sec Score: 1.00/100

Difficulty :*

    Memory: 256 MB Accepted Submissions: 100

Description

You are given Q queries and have to perform the following operations:

    add x - if x doesn't present in the set, add element x in the set. Otherwise do nothing.
    remove x - remove element x from the set, if it exists. Otherwise do nothing.
    find x - find the value at position x (0-indexing) if it exists. Otherwise print -1.
    findpos x - find the position (0-indexing) of the element with value x if it exists. Otherwise, find the position that the element would have in the set

The set is ordered in the non-decreasing order of the elements.

Input Format

The first line of the input contains one integer T - the number of test cases. Then T test cases follow.
The first line of each test case contains one integer Q - the number of queries.
Each of the next Q lines contains queries.

Output Format

For each test case, print the required queries.

Constraints

1≤ T ≤ 105
1≤ Q ≤ 105
1≤ x ≤ 105

It is guaranteed that the sum of Q over all test cases does not exceed 106.
Sample Input 1

1
6
add 4
add 1
add 6
find 1
findpos 7
findpos 6

Sample Output 1

4
3
2

Note

    Set becomes: [4]
    Set becomes: [1, 4]
    Set becomes: [1, 4, 6]
    S[1] = 4
    7 doesn’t exist in set, but if it did set would be: [1, 4, 6, 7] and S[3] = 7
    S[3] = 6;

*/


#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define LD long double

const int N = 100010;

int inf = 1e9;
int mod = 1e9 + 7;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_set;
/*
    order_of_key (k)
    find_by_order(k)
*/

signed main() {
  // freopen("IN", "r", stdin);
  // freopen("OUT", "w", stdout);

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int T;
  cin >> T;

  while (T--) {
    int Q;
    cin >> Q;

    ordered_set s;

    while (Q--) {
      string op;
      int x;
      cin >> op >> x;

      if (op == "add") {
        s.insert(x);
      } else if (op == "remove") {
        if (s.find(x) != s.end()) {
          s.erase(s.find(x));
        }
      } else if (op == "find") {
        if (x >= (int)s.size()) {
          cout << "-1\n";
        } else {
          cout << *(s.find_by_order(x)) << "\n";
        }
      } else {
        cout << s.order_of_key(x) << "\n";
      }
    }
  }
  return 0;
}


//tle:
#include<bits/stdc++.h>
using namespace std;

void solve() {
    int Q;
    cin >> Q;
    set<int> s;
    for(int i = 0; i < Q; i++) {
        string op;
        int x;
        cin >> op >> x;
        if(op == "add") {
            s.insert(x);
        } else if(op == "remove") {
           if(s.find(x)!=s.end()) s.erase(x);
        } else if(op == "find") {
            auto it = s.begin();
            advance(it, x);
            if(it != s.end()) {
                cout << *it << "\n";
            } else {
                cout << -1 << "\n";
            }
        } else if(op == "findpos") {
            auto it = s.lower_bound(x);
            if(it != s.end() && *it == x) {
                cout << distance(s.begin(), it) << "\n";
            } else {
                cout << distance(s.begin(), it) << "\n";
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}


/* Set Operations AZ101

    Time-Limit: 1 sec Score: 100.00/100

Difficulty :*

    Memory: 256 MB Accepted Submissions: 100

Description

You are given two sets, A and B of N and M integers respectively. There are no duplicate integers in each respective array. Find the set union, set intersection and set difference (A-B) of the two sets in sorted order.

Input Format

The first line of the input contains one integer T - the number of test cases. Then T test cases follow.

The first line of each test case contains two space-separated integers N, M - the length of the sets.

The second line of each test case contains N space-separated integers.

The third line of each test case contains M space-separated integers.

Output Format

For each test case, print the set union, set intersection and set difference (A-B) of the two sets  in sorted order, each on a separate line.

Constraints

1≤ T ≤ 105

1≤ N, M ≤ 10^4

1≤ Ai, Bi ≤ 109

It is guaranteed that the sum of N and the sum of M over all test cases does not exceed 2*10^5.

Sample Input 1

3
4 5
2 4 1 5
4 5 6 9 3
2 3
4 5
6 7 1
3 3
1 2 3
1 2 3

Sample Output 1

1 2 3 4 5 6 9 
4 5 
1 2 
1 4 5 6 7 

4 5 
1 2 3 
1 2 3

*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define ull unsigned long long int
#define mod 1000000007
#define inf 1e9
#define mt make_tuple
#define pb push_back
#define eb emplace_back
#define pob pop_back
#define f first
#define s second
#define nl "\n"
#define pi pair<int,int>
#define v vector<long long int>
#define vp vector<pair<int,int>>
#define vvl vector<vector<long long int>>
#define rep(n) for(int i=0 ; i<n ; i++)
#define rei(i) for(int i=n ; i>0 ; i--)
#define prio priority_queue
#define np next_permutation
#define N 200100

#define yes "YES"
#define no "NO"


 
void solve(){
	
	
	int n,m;
	cin>>n>>m;
	
	map<int,int>mp;
	int arr[n];
	int brr[m];
	
	for(int i=0;i<n;i++){
	   
	    cin>>arr[i];
	    mp[arr[i]]++;
	    
	}
	
		for(int i=0;i<m;i++){
	   
	    cin>>brr[i];
	    mp[brr[i]]++;
	    
	}
	
	for(auto it:mp){
	    
	    cout<<it.f<<" ";
	  
	}
	
	cout<<nl;
	for(auto it:mp){
	    
	   if(it.s==2) cout<<it.f<<" ";
	  
	}
	
	cout<<nl;
	
	sort(arr,arr+n);

for(int i=0;i<n;i++){
    
    if(mp[arr[i]]==1) cout<<arr[i]<<" ";
    
}
cout<<nl;

	
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	 int _t; cin>>_t;while(_t--)
		solve();
	
	
	//cerr<<"Time elapsed: "<< 1.0*clock()/ CLOCKS_PER_SEC << "s.\n\n";
	
	
	
	
}


/* Sort by Roll Number

    Time-Limit: 1 sec Score: 100.00/100

Difficulty :*

    Memory: 256 MB Accepted Submissions: 100

Description

You are given a list of N students with their names and roll number. Sort the list according to their roll numbers.

Input Format

The first line of the input contains one integer T - the number of test cases. Then T test cases follow.

The first line of each test case contains one integer N - the length of the array. 

The second line of each test case contains a string S and an integer R - the name and roll number.

Output Format

For each test case, print the sorted list according to their roll numbers.

Constraints

1≤ T ≤ 105

1≤ N ≤ 105

1≤ |S| ≤ 100

1 ≤ R ≤ 105

It is guaranteed that the sum of N over all test cases does not exceed 105.

Sample Input 1

2
5
amelia 21
sophia 12
emma 11
ava 8
isabel 1
3
alice 34
bob 20
hannah 5

Sample Output 1

isabel 1
ava 8
emma 11
sophia 12
amelia 21
hannah 5
bob 20
alice 34

*/


#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define ull unsigned long long int
#define mod 1000000007
#define inf 1e9
#define mt make_tuple
#define pb push_back
#define eb emplace_back
#define pob pop_back
#define f first
#define s second
#define nl "\n"
#define pi pair<int,int>
#define v vector<long long int>
#define vp vector<pair<int,int>>
#define vvl vector<vector<long long int>>
#define rep(n) for(int i=0 ; i<n ; i++)
#define rei(i) for(int i=n ; i>0 ; i--)
#define prio priority_queue
#define np next_permutation
#define N 200100

#define yes "YES"
#define no "NO"




 /*ll add(ll a,ll b){
	
	ll ans=(a+b)%mod;
	if(ans<0) ans+=mod;
	
	return ans;
}

 ll sub(ll a,ll b){
	
	ll ans=(a-b)%mod;
	if(ans<0) ans+=mod;
	
	return ans;
}

ll mul(ll a,ll b){
	
	ll ans=(a*b)%mod;
	if(ans<0) ans+=mod;
	
	return ans;
}*/


void solve(){
	
	ll n;
	cin>>n;
	
	map<ll,string>mp;
	
	for(ll i=0;i<n;i++){
	    
	   string str;
	   ll x;
	   
	   
	   cin>>str>>x;
	   
	   
	    mp.insert({x,str});
	    
	   
	}
	
	for(auto it:mp){
	    
	    
	    cout<<it.s<<" "<<it.f<<nl;
	}
	
	
	
	
	
	
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	 int _t; cin>>_t;while(_t--)
		solve();
	
	
	//cerr<<"Time elapsed: "<< 1.0*clock()/ CLOCKS_PER_SEC << "s.\n\n";
	
	
	
	
}

/* Generating Permutations AZ101

    Time-Limit: 1 sec Score: 100.00/100

Difficulty :

    Memory: 256 MB Accepted Submissions: 100

Description

You are given an integer N. You have to find all the permutations of N in lexicographic order.

Input Format

The first and only line of the input contains one integer N.

Output Format

Print all the permutations of N in lexicographic order.

Constraints

1≤ N ≤ 10
Sample Input 1

3

Sample Output 1

1 2 3 
1 3 2 
2 1 3 
2 3 1 
3 1 2 
3 2 1

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define ull unsigned long long int
#define mod 1000000007
#define inf 1e9
#define mt make_tuple
#define pb push_back
#define eb emplace_back
#define pob pop_back
#define f first
#define s second
#define nl "\n"
#define pi pair<int,int>
#define v vector<long long int>
#define vp vector<pair<int,int>>
#define vvl vector<vector<long long int>>
#define rep(n) for(int i=0 ; i<n ; i++)
#define rei(i) for(int i=n ; i>0 ; i--)
#define prio priority_queue
#define np next_permutation
#define N 200100

#define yes "YES"
#define no "NO"




 /*ll add(ll a,ll b){
	
	ll ans=(a+b)%mod;
	if(ans<0) ans+=mod;
	
	return ans;
}

 ll sub(ll a,ll b){
	
	ll ans=(a-b)%mod;
	if(ans<0) ans+=mod;
	
	return ans;
}

ll mul(ll a,ll b){
	
	ll ans=(a*b)%mod;
	if(ans<0) ans+=mod;
	
	return ans;
}*/


void solve(){
	
	int n;
	cin>>n;
	
	
	v a(n);
	
	
	for(int i=0;i<n;i++){
		
		
		a[i]=i+1;
		
	}
	
int i=0;	
do{
   for(int i=0;i<n;i++){ 
    cout<<a[i]<<" ";}
    cout<<nl;
    
}while(next_permutation(a.begin(),a.end()));
	
	
	
	
	
	
	
	
	
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	// int _t; cin>>_t;while(_t--)
		solve();
	
	
	//cerr<<"Time elapsed: "<< 1.0*clock()/ CLOCKS_PER_SEC << "s.\n\n";
	
	
	
	
}

/* Count the Pairs

    Time-Limit: 1 sec Score: 1.00/100

Difficulty :

    Memory: 256 MB Accepted Submissions: 100

Description

You are given an array A of size N. You need to find the number of pairs (i, j) , i != j, such that A[i]+A[j] ≤ X.

Input Format

The first line of the input contains one integer T - the number of test cases. Then T test cases follow.

The first line of each test case contains two space-separated integers N  X.

The second line of each test case contains N space-separated integers.

Output Format

For each test case, print the number of pairs (i, j) , i != j, such that A[i]+A[j] ≤ X.

Constraints

1≤ T ≤ 105

1≤ N ≤ 105

1≤ Ai ≤ 106

1≤ X ≤ 106

It is guaranteed that the sum of N over all test cases does not exceed 105.

Sample Input 1

2

5 4

1 2 2 3 4

3 10

5 5 5

Sample Output 1

8

6

Note

For the first test case, the following pairs have sum ≤ 4: (1,2), (1,2), (1,3), (2,1), (2,2), (2,1), (2,2), (3,1)

For the second test case, the following pairs have sum ≤ 10: (5,5), (5,5), (5,5), (5,5), (5,5), (5,5)

*/
//Solution 1
#include <bits/stdc++.h>
using namespace std;

#define IOS                \
  ios::sync_with_stdio(0); \
  cin.tie(0);              \
  cout.tie(0);
#define int long long int

signed main() {
  IOS int t;
  cin >> t;
  while (t--) {
    int n, x;
    cin >> n >> x;
    int a[n];
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    sort(a, a + n);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      int j = upper_bound(a, a + n, x - a[i]) - a;
      if (a[i] <= x - a[i]) j--;
      ans += j;
    }
    cout << ans << "\n";
  }
  return 0;
}

//my code :
//Solution 1
#include <bits/stdc++.h>
using namespace std;

#define IOS                \
  ios::sync_with_stdio(0); \
  cin.tie(0);              \
  cout.tie(0);
#define int long long int

signed main() {
  IOS int t;
  cin >> t;
  while (t--) {
    int n, x;
    cin >> n >> x;
    int a[n];
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    sort(a, a + n);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      int j = upper_bound(a, a + n, x - a[i]) - a;
      if (a[i] <= x - a[i]) j--;
      ans += j;
    }
    cout << ans << "\n";
  }
  return 0;
}

//wrong ans:
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define ull unsigned long long int
#define mod 1000000007
#define inf 1e9
#define mt make_tuple
#define pb push_back
#define eb emplace_back
#define pob pop_back
#define f first
#define s second
#define nl "\n"
#define pi pair<int,int>
#define v vector<long long int>
#define vp vector<pair<int,int>>
#define vvl vector<vector<long long int>>
#define rep(n) for(int i=0 ; i<n ; i++)
#define rei(i) for(int i=n ; i>0 ; i--)
#define prio priority_queue
#define np next_permutation
#define N 200100

#define yes "YES"
#define no "NO"




 /*ll add(ll a,ll b){
	
	ll ans=(a+b)%mod;
	if(ans<0) ans+=mod;
	
	return ans;
}

 ll sub(ll a,ll b){
	
	ll ans=(a-b)%mod;
	if(ans<0) ans+=mod;
	
	return ans;
}

ll mul(ll a,ll b){
	
	ll ans=(a*b)%mod;
	if(ans<0) ans+=mod;
	
	return ans;
}*/


void solve(){
	
	ll n,x;
	
	cin>>n>>x;
	
	v a(n);
	
	for(ll i=0;i<n;i++){
		
		cin>>a[i];
		
		
	}
	
	sort(a.begin(),a.end());
	
	ll m;
	
	m=x-a[0];
	
	ll cnt=0;
	
	for(auto it:a){
		
		if(it<=m){
			
			cnt++;
		}
		
		
	}
	
	cout<<2*cnt<<nl;
	
	
	
	
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	 int _t; cin>>_t;while(_t--)
		solve();
	
	
	//cerr<<"Time elapsed: "<< 1.0*clock()/ CLOCKS_PER_SEC << "s.\n\n";
	
	
	
	
}


/* Support Queries I

    Time-Limit: 1 sec Score: 100.00/100

Difficulty :

    Memory: 256 MB Accepted Submissions: 100

Relevant For:

Description

Design a Data Structure which can support the following queries:

1 x: Add x in structure
2 x: Remove x from the structure if present in the structure. If x doesn't present in the structure, do nothing. If there are multiple occurrences of x, delete only one occurrence of x.
3 ?: Print the minimum number present in the structure. If the structure is empty, print -1.
4 ?: Print the maximum number present in the structure. If the structure is empty, print -1.
5 ?: Print the sum of all numbers present in the structure. If the structure is empty, print 0.

Initially, the structure is empty.

Input Format

The first line of input contains Q - the number of queries.
Next, Q lines contain queries of the format specified in the statement.

Output Format

For queries of type 3, 4 and 5, print the answer in a new line.

Constraints

1 ≤ Q ≤ 105
0 ≤ x ≤ 109
Sample Input 1

18

1 5

1 4

1 4

3 ?

4 ?

5 ?

2 4

3 ?

4 ?

5 ?

2 4

3 ?

4 ?

5 ?

2 5

3 ?

4 ?

5 ?

Sample Output 1

4

5

13

4

5

9

5

5

5

-1

-1

0

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define ull unsigned long long int
#define mod 1000000007
#define inf 1e9
#define mt make_tuple
#define pb push_back
#define eb emplace_back
#define pob pop_back
#define f first
#define s second
#define nl "\n"
#define pi pair<int,int>
//#define v vector<long long int>
#define vp vector<pair<int,int>>
#define vvl vector<vector<long long int>>
#define rep(n) for(int i=0 ; i<n ; i++)
#define rei(i) for(int i=n ; i>0 ; i--)
#define prio priority_queue
#define np next_permutation
#define N 200100

#define yes "YES"
#define no "NO"




 /*ll add(ll a,ll b){
	
	ll ans=(a+b)%mod;
	if(ans<0) ans+=mod;
	
	return ans;
}

 ll sub(ll a,ll b){
	
	ll ans=(a-b)%mod;
	if(ans<0) ans+=mod;
	
	return ans;
}

ll mul(ll a,ll b){
	
	ll ans=(a*b)%mod;
	if(ans<0) ans+=mod;
	
	return ans;
}*/


void solve(){

map<ll,ll>mp;

ll q;
cin>>q;
ll ans=0;
while(q--){
    ll a;
    cin>>a;
    
     ll x;
    if(a==1){
        
       
        cin>>x;
        
        mp[x]++;
        ans+=x;
       // cout<<"ans is :"<<ans<<nl;
        
    }else if(a==2){
        
        cin>>x;
        
        if(mp.find(x)!=mp.end()){
            
            mp[x]--;
            ans-=x;
            
            
            if(mp[x]==0)mp.erase(x);
            // cout<<"ans is :"<<ans<<nl;
        }
        
    }else if(a==3){
        char y;
        cin>>y;
        auto it =mp.begin();
        if(!mp.empty())cout<<it->f<<nl;
        else cout<<-1<<nl;
    }else if(a==4){
        char y;
        cin>>y;
        
        auto it =mp.rbegin();
        if(!mp.empty())cout<<it->f<<nl;
        else cout<<-1<<nl;
    }else if(a==5){
        char y;
        cin>>y;
        
        if(!mp.empty())cout<<ans<<nl;
        else cout<<0<<nl;
    }
    
    
}

}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	// int _t; cin>>_t;while(_t--)
		solve();
	
	
	//cerr<<"Time elapsed: "<< 1.0*clock()/ CLOCKS_PER_SEC << "s.\n\n";
	
	
	
	
}

/* Round and Round

    Time-Limit: 2 sec Score: 1.00/100

Difficulty :***

    Memory: 256 MB Accepted Submissions: 100

Relevant For:

Description

Bob is standing in a park at (0,0) facing north. He is given a series of instructions to move around the park. The instructions can be:

    ‘W’: go straight 1 unit
    ‘L’: turn 90 degrees left
    ‘R’: turn 90 degrees right

Bob has to perform the given instructions forever. If he is going in a circle forever, print ‘YES’. Otherwise, print ‘NO’ (without the quotes).

Input Format

The first line of the input contains one integer T - the number of test cases. Then T test cases follow.
The first line of each test case contains N - the length of the input string of instructions.
The second line of each test case contains one string S - the series of instructions to move around the park.

Output Format

For each test case, print ‘YES’ if Bob is going in a circle forever. Otherwise, print ‘NO’. (without the quotes)

Constraints

1≤ T ≤ 100
1≤ |S| ≤ 105 where |S| denotes the length of the given series of instructions.
Sample Input 1

3

3

WWW

2

LW

4

WLLW

Sample Output 1

NO

YES

YES

Note

In the first sample test case, Bob moves north indefinitely.

In the second sample test case, Bob moves as follows: (0,0) => (-1,0) => (-1,-1) => (0,-1) => (0,0). So, Bob goes in a circle forever

In the third sample test case, Bob moves from (0,0) to (0,1) turns 180 degress and returns to (0,0). So, Bob goes in a circle forever

*/

#include <bits/stdc++.h>
using namespace std;

#define IOS                \
  ios::sync_with_stdio(0); \
  cin.tie(0);              \
  cout.tie(0);

int main() {
  IOS int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int x = 0, y = 0;
    int direction = 0;  // 0-north, 1-west, 2-south, 3-east
    bool flag = false;
    for (int i = 0; i < n; i++) {
      if (s[i] == 'L')
        direction = (direction + 3) % 4;
      else if (s[i] == 'R')
        direction = (direction + 1) % 4;
      else {
        if (direction == 0)
          y++;
        else if (direction == 1)
          x--;
        else if (direction == 2)
          y--;
        else
          x++;
      }
    }
    if ((x == 0 && y == 0) || direction != 0)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}


//wrong ans:
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define ull unsigned long long int
#define mod 1000000007
#define inf 1e9
#define mt make_tuple
#define pb push_back
#define eb emplace_back
#define pob pop_back
#define f first
#define s second
#define nl "\n"
#define pi pair<int,int>
//#define v vector<long long int>
#define vp vector<pair<int,int>>
#define vvl vector<vector<long long int>>
#define rep(n) for(int i=0 ; i<n ; i++)
#define rei(i) for(int i=n ; i>0 ; i--)
#define prio priority_queue
#define np next_permutation
#define N 200100

#define yes "YES"
#define no "NO"




 /*ll add(ll a,ll b){
	
	ll ans=(a+b)%mod;
	if(ans<0) ans+=mod;
	
	return ans;
}

 ll sub(ll a,ll b){
	
	ll ans=(a-b)%mod;
	if(ans<0) ans+=mod;
	
	return ans;
}

ll mul(ll a,ll b){
	
	ll ans=(a*b)%mod;
	if(ans<0) ans+=mod;
	
	return ans;
}*/


void solve(){
ll n;
cin>>n;

set<char>st;
while(n--){
    
    char x;
    cin>>x;
    st.insert(x);
    
    
}


if(st.size()==1){
    
    if(*st.begin()=='W')cout<<no<<nl;
    else cout<<yes<<nl;
    
}else if(st.size()==2){
    cout<<yes<<nl;
    
}else{
    cout<<no<<nl;
}


}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	int _t; cin>>_t;while(_t--)
		solve();
	
	
	//cerr<<"Time elapsed: "<< 1.0*clock()/ CLOCKS_PER_SEC << "s.\n\n";
	
	
	
	
}


/* Interesting Game

    Time-Limit: 1 sec Score: 1.00/100

Difficulty :***

    Memory: 256 MB Accepted Submissions: 100

Relevant For:

Description

Alice and Bob are playing a new game, which is very interesting and fun. The game is as follows:

    The game starts with two n-sized integer arrays, A and B, and is played by two players, P1 and P2.
    The players move in alternating turns, with P1 always moving first. During each move, the current player must choose an integer, i, such that 0 ≤ i ≤ n - 1. If the current player is P1, then  P1 receives Ai points; if the current player is P2, then P2 receives Bi points.
    Each value of i can be chosen only once. That is, if a value of i is already chosen by some player, none of the players can re-use it. So, the game always ends after n moves.
    The player with the maximum number of points wins.
    The arrays A and B are accessible to both the players P1 and P2. So the players make an optimal move at every turn.

Given the values of n, A, and B, can you determine the outcome of the game? P1 is Alice and P2 is Bob.
Print ‘Alice’ if Alice will win, 'Bob' if Bob will win, or 'Tie' if they will tie. Assume both players always move optimally.

Input Format

The first line of input contains one integer T (1 ≤ T ≤ 10) — the number of test cases. Then T test cases follow.
The first line of each test case contains N (2 ≤ N ≤ 1000), the number of elements in arrays A and B.
The second line contains N space-separated integers A1, A2, ..., AN - the elements of array A.
The third line contains N space-separated integers B1, B2, ..., BN - the elements of array B.

Output Format

For each test case, print one of the following predicted outcomes of the game on a new line:

    Print 'Alice' if Alice will win.
    Print 'Bob' if Bob will win.
    Print 'Tie' if the two players will tie.

Constraints

1 ≤ T ≤ 10
2 ≤ N ≤ 1000
1 ≤ Ai, Bi ≤ 105
Sample Input 1

3

3

1 3 4

5 3 1

2

1 1

1 1

2

2 2

3 3

Sample Output 1

Alice

Tie

Bob

Note

Explanation 1:
The players make the following 3 moves:

    Alice chooses i = 2 and receives 4 coins.
    Bob chooses i = 0 and receives 5 coins. Notice that Bob won't choose i = 1, because this would cause Alice to win.
    Alice chooses i = 1 (the only remaining move) and receives 3 coins.

The total score of Alice is 7, while the total score of Bob is 5. Hence, Alice wins.

Explanation 2:
Both players will only make 1 move and all possible point values are 1, the players will end the game with equal scores.

Explanation 3:
Both players will only make 1 move and all the possible point values for Bob are greater than all the possible point values for Alice, Bob will win the game.

*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define F first
#define S second

using ii = pair<int, int>;

bool comp(ii a, ii b) { return a.F + a.S > b.F + b.S; }

void solve() {
  int n;
  cin >> n;
  int a[n], b[n];
  vector<ii> arr;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) cin >> b[i];
  for (int i = 0; i < n; i++) arr.push_back({a[i], b[i]});

  sort(arr.begin(), arr.end(), comp);
  int asc = 0, bsc = 0, turn = 0;
  for (int i = 0; i < n; i++) {
    if (turn == 0) {
      asc += arr[i].F;
      turn++;
    } else {
      bsc += arr[i].S;
      turn--;
    }
  }

  if (asc > bsc)
    cout << "Alice" << endl;
  else if (asc == bsc)
    cout << "Tie" << endl;
  else
    cout << "Bob" << endl;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int _t = 1;
  cin >> _t;
  // string s; getline(cin, s);//

  while (_t--) {
    solve();
  }
}


//theory behind sorting merge sort and quick sort:


/* https://youtu.be/k3oezbZgfDs
https://youtu.be/v-1EGgaTFuw
https://youtu.be/NvGitWFoSas
https://youtu.be/0ufNJSWOTqo
https://youtu.be/pJ1IQD5rv4o */
