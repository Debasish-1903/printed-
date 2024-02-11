 // it is used for weighted graph (any weight) without the cylcle sum=-ve 
/*ex: 
      node node weigth
      2 3 3
      3 4 10
      4 5 -6
      5 3 -3     for this case dijkstra is valid as loop (10-6-3=1>0) 
      
      
      
      but for this case dijkstra will be not valid
       
       2 3 3
      3 4 8
      4 5 -6
      5 3 -3     for this case dijkstra is valid as loop (8-6-3=-11<0) 
      

*/
#define ii pair<ll,ll>
#define mp make_pair

ll n,m;




vector<ii>g[100100];

int visited[100100];
ll dist[100100];



void dijkstra(ll src){
	
	for(ll i=1;i<=n;i++){
		
		dist[i]=1e18;
		visited[i]=0;
		//parent[i]=-1;
		
	}
	
	dist[src]=0;
	
	vector<ll>parent(n+1,-1);
	
	 priority_queue<ii,vector<ii>,greater<ii>>pq;
	 pq.push(mp(dist[src],src));
	
	while(!pq.empty()){

          auto it=pq.top();
          ll dis=it.f;
          ll node=it.s;
           
           pq.pop();
           
           
           if(visited[node]){
           	continue;
           }
           
           visited[node]=1;
           
           
           for(auto neigh:g[node]){
           	
           	auto weight=neigh.s;
           	auto v=neigh.f;
           	
           	if(dis+weight<dist[v]){
           		
           		dist[v]=dis+weight;
           		parent[v]=node;
           		
           		pq.push(mp(dist[v],v));
           	}
           	
           	
           	
           }


     		
		
		
		
	}
	
	
	for(ll i=1;i<=n;i++){
		
		
		cout<<"i"<<i<<" "<<"dist:"<<dist[i]<<nl;
		
		
		
		
		if(i!=src){
		    
		    cout<<"path"<<" ";
		    vector<ll>path;
		    for(ll v=i;v!=-1;v=parent[v]){
		        
		        path.push_back(v);
		    }
		    
		   reverse(path.begin(),path.end());
		   
		   
		   for(auto v:path){
		       
		       cout<<v<<" ";
		   }
		   cout<<nl;
		    
		}
		
	}
	
	
	
	
	
	
	
	
}


void solve(){
	
	
	cin>>n>>m;
	
	for(ll i=0;i<m;i++){
		
		ll a,b,w;
		
		cin>>a>>b>>w;
		
		// undirected graph
		
		g[a].push_back({b,w});
		g[b].push_back({a,w});
		
		 
		
		
		
	}
	
	 dijkstra(1);
	
	
	
	
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	// int _t; cin>>_t;while(_t--)
		solve();
	
	
	//cerr<<"Time elapsed: "<< 1.0*clock()/ CLOCKS_PER_SEC << "s.\n\n";
	
	
	
	
}


// bfs implementation code ====> when all edge has same weight =1;


#define ii pair<ll,ll>
#define mp make_pair

ll n,m;
vector<ll>grid[100100];

ll dist[100100];

// level==dist==distance from the src node

ll inf=1e9;
void bfs(ll src){
	
	 queue<ii>q;
	
	  for(ll i=1;i<=n;i++) {
	  	
	  	dist[i]=inf;
	  	
	}
	
	dist[src]=0;
	
	
	q.push({src,dist[src]});
	
	
	
	while(!q.empty()){
		
		 auto it=q.front();
		 
		    ll node=it.f;
		    
		    ll dis=it.s;
		 q.pop();
		 
		 
		 for(auto neigh:grid[node]){
		 	   
		 	   
		 	    if(dist[neigh]>dis+1){
		 	    	
		 	    	dist[neigh]=dis+1;
		 	    	q.push({neigh,dist[neigh]});
		 	    }
		 	 
		 	
		 	
		 }
		
		
		
		
	}
	
	for(int i=1;i<=n;i++){
	cout<<"i:"<<i<<" dist:"<<dist[i]<<nl;}  // print the distance from each node 
	
///	tc=O(ElogE)
}

void solve(){
	
	cin>>n>>m;
	
	for(ll i=0;i<m;i++){
		
		ll a,b;
		
		cin>>a>>b;
		
		grid[a].push_back(b);
		
		
	}
	
	
	bfs(1);
	
	
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	// int _t; cin>>_t;while(_t--)
		solve();
	
	
	//cerr<<"Time elapsed: "<< 1.0*clock()/ CLOCKS_PER_SEC << "s.\n\n";
	
	
	
	
}




// 01 bfs code implementation

#define ii pair<ll,ll>  // path printing 
#define mp make_pair

ll n,m;
vector<ii>grid[100100];

ll dist[100100];

// level==dist==distance from the src node

ll inf=1e9;
void bfs01(ll src){
	
	 deque<ll>dq;
	
	  for(ll i=1;i<=n;i++) {
	  	
	  	dist[i]=inf;
	  	
	}
	
	dist[src]=0;
	
	
	dq.push_back(src);
	
	vector<ll>parent(n+1,-1);
	
	while(!dq.empty()){
		
		 auto node=dq.front();
		 
		   
		 dq.pop_front();
		 
		 
		 for(auto neigh:grid[node]){
		 	
		 	auto  v=neigh.f;
		 	
		 	auto w=neigh.s;
		 	   
		 	   
		 	    if(dist[v]>dist[node]+w){
		 	    	
		 	    	dist[v]=dist[node]+w;
		 	    	parent[v]=node;
		 	    	
		 	    	if(w==0){
		 	    		
		 	    		dq.push_front(v);
		 	    	}else if(w==1){
		 	    		
		 	    		dq.push_back(v);
		 	    	}
		 	    	
		 	    	
		 	    }
		 	 
		 	
		 	
		 }
		
		
		
		
	}
	
	for(int i=1;i<=n;i++){
	cout<<"i:"<<i<<" dist:"<<dist[i]<<nl;
	
	if(i!=src){
		
		
		
		cout<<"path :"<<" ";
		
		vector<ll>path;
		
		for(ll v=i;v!=-1;v=parent[v]){
			
			path.push_back(v);
			
		}
		
		reverse(path.begin(),path.end());
		
		
		for(auto it:path){
			
			cout<<it<<" ";
		}
		cout<<nl;
	}
	
	
	
	
	
	
	}  // print the distance from each node 
	
	
	// tc = O(v+e)
}

void solve(){
	
	cin>>n>>m;
	
	for(ll i=0;i<m;i++){
		
		ll a,b,w;
		
		cin>>a>>b>>w;
		
		grid[a].push_back(mp(b,w));
		
		
	}
	
	
	bfs01(1);
	
	
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	// int _t; cin>>_t;while(_t--)
		solve();
	
	
	//cerr<<"Time elapsed: "<< 1.0*clock()/ CLOCKS_PER_SEC << "s.\n\n";
	
	
	
	
}


/*Edge Reverse

Time-Limit: 1 sec Score: 50.00/100
Difficulty : ** (min)
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

Given a directed graph with 
N vertices and  M edges.

What is the minimum number of edges needed to reverse in order to have at least
 one path from vertex 
1 to vertex 
N
, where the vertices are numbered from 
1 to N
 ?


Input Format

The first line contains 
T
 - the number of test cases.

The first line of each test case contains two space-separated integers N and M
, denoting the number of vertices and the number of edges in the graph respectively.
The ith
 line of the next M lines of each test case contains two space-separated integers Xi and Yi
, denoting that the ith
 edge connects vertices from  Xi
 to Yi.


Output Format

For each test case, In a single line, print the minimum number of edges we need to revert. 
If there is no way of having at least one path from 
1 to N, print -1.


Constraints
1<T<10;
1<N,M<10^5
1<xi,yi<N;


There can be multiple edges connecting the same pair of vertices,
 There can be self-loops too i.e. Xi= Yi

Sample Input 1

1
7 7
1 2 
3 2
3 4
7 4
6 2
5 6
7 5

Sample Output 1

2

Note

We can consider two paths from 1 to 7:

7
In the first one we need to revert edges 

. In the second one - 

. So the answer is 


.*/






#define mp make_pair 
# define ii pair<ll,ll>

vector<vector<ii>>grid;
ll dist[1001001];

ll n,m;


void bfs01(ll src){
	
	
	deque<ll>dq;

	for(ll i=1;i<=n;i++){
		dist[i]=1e18;
	}
	
	
	dist[src]=0;
	
	dq.push_back(src);
	
	
	while(!dq.empty()){
		
		 auto node=dq.front();
		 
		 dq.pop_front();
		 
		 
		 for(auto  neigh:grid[node]){
		 	 auto v=neigh.f;
		 	 
		 	 auto w=neigh.s;
		 	 
		 	 
		 	 if(dist[v]>dist[node]+w){
		 	 	
		 	 	dist[v]=dist[node]+w;
		 	 	
		 	 	
		 	 	if(w==0){
		 	 		
		 	 		dq.push_front(v);
		 	 	}else{
		 	 		
		 	 		dq.push_back(v);
		 	 	}
		 	 }
		 	
		 	
		 }
		
		
	}
	
}


void solve(){
	
	
	cin>>n>>m;
	
	 grid.resize(n+1);
	 grid.clear();
	
	
	
	for(ll i=0;i<m;i++){
		
		
		ll a,b;
		cin>>a>>b;
		
		grid[a].push_back({b,0});
		grid[b].push_back({a,1});
		
	}
	
	
	 bfs01(1);
	 
	 if(dist[n]==1e18){
	 	cout<<-1<<nl;
	 }else{
	 	
	 	cout<<dist[n]<<nl;
	 }
	
	
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	int _t; cin>>_t;while(_t--)
		{    
			solve();
		}
		
	
	
	
	//cerr<<"Time elapsed: "<< 1.0*clock()/ CLOCKS_PER_SEC << "s.\n\n";
	
	
	
	
}


/*Back to KGP

Time-Limit: 1 sec Score: 1.00/100
Difficulty :min(***) 
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

You are going back to KGP and want to travel from Delhi to Kolkata by plane. You would like to find answers to the following questions:

1.
 What is the minimum price of such a route?
2.
 How many minimum-price routes are there? (modulo 
10
9
+
7
)
3.
 What is the minimum number of flights in a minimum-price route?
4.
 What is the maximum number of flights in a minimum-price route?


Input Format

The first input line contains two integers 
n
 and 
m
: the number of cities and the number of flights. The cities are numbered 
1
,
2
,
…
,
n
. City 
1
 is Delhi, and city 
n
 is Kolkata.

After this, there are 
m
 lines describing the flights. Each line has three integers 
a
, 
b
, and 
c
: there is a flight from city 
a
 to city 
b
 with price 
c
. All flights are one-way flights.


Output Format

Print four integers according to the problem statement in a single line. If there is no route from Delhi to Kolkata, then print 
−
1
.


Constraints

1
≤
n
≤
10
5

0
≤
m
≤
2
⋅
10
5

1
≤
a
,
b
≤
n

1
≤
c
≤
10
9

Sample Input 1

4 5
1 4 5
1 2 4
2 4 5
1 3 2
3 4 3

Sample Output 1

5 2 1 2

Sample Input 2

5 5
1 2 4
3 4 6
2 1 3
3 5 10
5 4 6

Sample Output 2

-1*/


#define mp make_pair
#define ii pair<ll,ll>


ll n,m;
vector<vector<ii>>grid;

vector<ll>dist,path,min_fl,max_fl,visited; 
// store min no of flights in the min cost route till each road





void dijkstra(ll src){
	
	
	// for(ll i=1;i<=n;i++){
		
	// 	dist[i]=1e18;
	// 	visited[i]=0;
		
	// 	 max_fl[i]=0;
	// 	 min_fl[i]=0;
	// 	 path[i]=0;
	// 	 	}
	
	
	dist[src]=0;
	
	path[src]=1;
    min_fl[src]=0;
    max_fl[src]=0;
	
	priority_queue<ii,vector<ii>,greater<ii>>pq; // min heap representation
	
	pq.push(mp(dist[src],src));
	
	
	while(!pq.empty()){
		
		auto it=pq.top();
		
		auto node=it.s;
		
		auto weight=it.f;
			pq.pop();
		
		
		if(visited[node]){
			continue;
		}
			visited[node]=1;
		
		
		
	
		
		
		for(auto neigh:grid[node]){
			
			auto v=neigh.f;
			auto w=neigh.s;
			
			// if(v==n){
				
			// 	if(dist[v]==weight+w) dist_cnt.push_back(dist[v]);
			// }
			

			if(dist[v]>weight+w){
				
				
				dist[v]=weight+w;
				
				path[v]=path[node];
				min_fl[v]=min_fl[node]+1;
				max_fl[v]=max_fl[node]+1;
				
				
				
				pq.push(mp(dist[v],v));
				
			}else if(dist[v]==weight+w){
				
				
				path[v]=(path[node]+path[v])%mod;
				min_fl[v]=min(min_fl[node]+1,min_fl[v]);
				max_fl[v]=max(max_fl[node]+1,max_fl[v]);
				
			}
			
		
			
			
		}
		
		
	}
	
	
}



void solve(){
	
	cin>>n>>m;
	
	grid.resize(n+1);
	dist.assign(n+1,1e18);
	visited.assign(n+1,0);
	path.assign(n+1,0);
	max_fl.assign(n+1,0);
	min_fl.assign(n+1,0);
	
	for(ll i=0;i<m;i++){
		
		ll a,b,c;
		cin>>a>>b>>c;
		grid[a].push_back({b,c});
		
	}
	
	
	dijkstra(1);
	
	if(dist[n]==1e18){
		
		cout<<-1<<nl;
	}
	
	else cout<<dist[n]<<" "<<path[n]<<" "<<min_fl[n]<<" "<<max_fl[n];

}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	// int _t; cin>>_t;while(_t--)
		solve();
	
	
	//cerr<<"Time elapsed: "<< 1.0*clock()/ CLOCKS_PER_SEC << "s.\n\n";
	
	
	
	
}

/*Bellman-Ford Revisited

Time-Limit: 2 sec Score: 1.00/100
Difficulty : **
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

You have given a graph G with n nodes and m edges. Each edge has an integer weight associated with. The weight of an edge may negative, positive or zero. If the graph contains a cycle with total weight > 0, print -1. Otherwise, find the weight of the highest weighted path from node 1 to n.


Input Format

The first input line has two integers n and m: the number of nodes and edges. The nodes are numbered 1, 2, …, n.
Then, there are m lines describing the edges. Each line has three integers a, b and x: the edge starts at node a, ends at node b, and weight of the edge is x. All edges are unidirectional edges.
You can assume that it is possible to get from node 1 to node n.


Output Format

Print the answer on a new line.


Constraints

1 ≤ 2500 ≤ n
1 ≤ 5000 ≤ m
1 ≤ a, b ≤ n
−109 ≤ x ≤ 109


Sample Input 1

4 5
1 2 3
2 4 -1
1 3 -2
3 4 7
1 4 4

Sample Output 1

5*/




#include <bits/stdc++.h>
using namespace std;

#define int long long

const int mod = 1e9+7;

void solve()
{
    int m,n; cin>>m>>n;
    vector<vector<int>> edges;
    
    for(int i=0;i<n;i++)
    {
        int a,b,c; cin>>a>>b>>c;
        edges.push_back({a,b,-c});
    }
    
    vector<int> dist(m+1,1e18);
    
    dist[1]=0;
    for(int i=1;i<=m;i++)
    {
        for(auto it:edges)
        {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            
            if(dist[u]+wt < dist[v]) dist[v] = dist[u]+wt;
        }
    }
    
    for(auto it:edges)
    {
        int u = it[0];
        int v = it[1];
        int wt = it[2];
            
        if(dist[u]+wt < dist[v])
        {
            cout<<-1<<endl;
            return;
        }
    }
    
    cout<<-dist[m]<<endl;
    
    
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


// but in this problem somthing is problematic as i submitted the code quite a time
 //ll n,m;
// vector<vector<ll>>grid;
// vector<ll>dist;

// void bellmanFord(ll src){
	
// 	dist[src]=0;
	
// 	bool neg_cyle=0;
	
	
// 	for(ll i=1;i<=m;i++){
		
		
// 		for(auto it:grid){
			
// 			auto u=it[0];
// 			auto v=it[1];
// 			auto weight=it[2];
			
			
// 			if(dist[v]>dist[u]+weight){
				
// 				dist[v]=dist[u]+weight;
// 			}
			
// 		}
		
		
		
// 	}
	
	
// 	for(auto it:grid){
			
// 			auto u=it[0];
// 			auto v=it[1];
// 			auto weight=it[2];
			
			
// 			if(dist[v]>dist[u]+weight){
				
// 				neg_cyle=true;
//                cout<<-1<<nl;
//                 return;
// 			}
			
// 		}
	
    
//     cout<<-dist[n]<<nl;
	
// 	}



// void solve(){
	
// 	cin>>n>>m;
	
// 	grid.resize(m);
// 	dist.assign(n+1,1e18);
// 	for(ll i=0;i<m;i++){
		
// 		ll a,b,w;
// 		cin>>a>>b>>w;
// 		grid[i].push_back(a);
// 		grid[i].push_back(b);
// 		grid[i].push_back(-w);
		
		
// 	}
	
// 	bellmanFord(1);
	
	
// }

// signed main(){
// 	ios_base::sync_with_stdio(0);
// 	cin.tie(0);cout.tie(0);
	
// 	// int _t; cin>>_t;while(_t--)
// 		solve();
	
	
// 	//cerr<<"Time elapsed: "<< 1.0*clock()/ CLOCKS_PER_SEC << "s.\n\n";
	
	
	
	
// }

 
 /*One Piece

Time-Limit: 1 sec Score: 1.00/100
Difficulty : **
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

Monkey D. Luffy, on his journey of becoming the "King of Pirates" and to conquer the "One Piece", wants to travel across the Grand Line.
Grand Line is a mysterious sea, and is in the shape of a 
N
∗
M
 grid 
S
 with each cell denoting the wind direction. The sign of 
s[i][j];
 can be:

1
 which means wind in the cell flows to the right. (i.e from 
s[i][j]-->s[i][j+1]
2 which means wind in the cell flows to the left. (i.e from 
S[i][j]-->s[i][j-1];

3
 which means wind in the cell flows downwards. (i.e from 
s[i][j]-->s[i+1][j]
4
 which means wind in the cell flows upwards. (i.e from 
S[i][j]-->s[i-1][j]

Notice that there could be some signs on the cells of the grid 
S
 that point outside the Grand Line sea grid.

Luffy's ship "Merry" can only sail along the wind direction and can't go outside the Grand Line sea grid 
S
 at any point.
Luffy can also modify the wind's direction on a cell with 
cost=1
. ( can modify the sign on a cell one time only )
Find the minimum cost to make Luffy's Voyage from the top left corner of the Grand line i.e 
S[1][1]
 to its bottom right corner i.e 
S[N][M]
 possible.


Input Format

Input is given from Standard Input in the following format:

s1,1 .....
..........
..........
........sn,m

Output Format

Print the answer.


Constraints

2
≤
N
,
M
≤
1000

N
 and 
M
 are integers.
1 ≤ 
S
i
,
j
 ≤ 4.


Sample Input 1

4 4
1 1 1 1
2 2 2 2
1 1 1 1
2 2 2 2 

Sample Output 1

3

Sample Input 2

3 3
1 1 3
3 2 2
1 1 4

Sample Output 2

0

Note
For Sample 1, You will start at point 
(0,0).The path to 
(3,3)is as follows. (0,0)--> (0,1)-->(0,2)--> (0,3)
 change the arrow to down with 
cost=1--> (1,3)--> (1,2)--> (1,1)--> (1,0)
 change the arrow to down with 
cost=1--> (2,0)
--> (2,1)--> (2,2)--> (2,3)change the arrow to down with 
cost=1--> (3,3)

The total cost = 3.
 
 
 */
 
 #define mp make_pair
#define ii pair<ll,ll>

ll n,m;


vector<vector<ll>>grid;

ll dx[4]={0,0,1,-1};
ll dy[4]={1,-1,0,0};


void bfs01(ll src_x,ll src_y){
	
	
	vector<vector<ll>>dist(n,vector<ll>(m,1e9));
	deque<ii>dq;
	
	dist[src_x][src_y]=0;
	
	dq.push_back(mp(src_x,src_y));
	
	
	while(!dq.empty()){
		
		auto it =dq.front();
		
		auto x=it.f;
		auto y=it.s;
		
		dq.pop_front();
		
		for(ll k=0;k<4;k++){
			
			auto xx=x+dx[k];
			auto yy=y+dy[k];
			
			
			ll w=(k+1==grid[x][y])? 0:1;
			
			if(xx>=0&&yy>=0&&xx<n&&yy<m&&dist[xx][yy]>dist[x][y]+w){
				
				dist[xx][yy]=dist[x][y]+w;
				
				if(w==1){
					
					dq.push_back(mp(xx,yy));
				}else if(w==0){
					
					dq.push_front(mp(xx,yy));
				}
				
				
			}
			
			
			
		}
		
		
		
		
		
	}
	
	cout<<dist[n-1][m-1]<<nl;
	
	
	
}




void solve(){
	
	cin>>n>>m;
	
	grid.assign(n,vector<ll>(m,0));
	
	
	for(ll i=0;i<n;i++){
		for(ll j=0;j<m;j++){
			
			cin>>grid[i][j];
		}
	}
		
	bfs01(0,0);
	
	
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	// int _t; cin>>_t;while(_t--)
		solve();
	
	
	//cerr<<"Time elapsed: "<< 1.0*clock()/ CLOCKS_PER_SEC << "s.\n\n";
	
	
	
	
}

/*Jump Game

Time-Limit: 1 sec Score: 100.00/100
Difficulty : ***(std)
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

Given an array having 
n elements, the cost to move from ith
 element to its adjacent element ( if exist ) at i+1 and 
i−1 is b, and the cost to move to other same valued index is a.
Find min cost to reach every index from a given source index of the array.


Input Format

First-line contains 
n - size of the array and costs a and b
..
Second line contains n elements of the array.
The third line contains a source index src
.


Output Format

In a single line, print the min-cost to reach every index from a given source index src

.


Constraints

1≤n≤2×105

1≤a,b≤109

1≤arr[i]≤100
1≤src≤n

Sample Input 1

10 1 2                                
1 2 1 1 2 3 2 3 2 1                                  
1

Sample Output 1

0 2 1 1 3 5 3 5 3 1 

Sample Input 2

1 1 2                                
7                                  
1

Sample Output 2

0*/




#define mp make_pair
#define ii pair<ll,ll>

ll n,m,a,b;


//int visited[100100];
//ll dist[100100];




void dijkstra(vector<vector<ii>>&grid,ll src){
    vector<int>visited(m+1,0);
        vector<ll>dist(m+1,1e18);
	
// 	for(ll i=1;i<=m+1;i++){
		
// 		dist[i]=1e18;
// 		visited[i]=0;
// 		//parent[i]=-1;
		
// 	}
	
	dist[src]=0;
	
	//vector<ll>parent(n+1,-1);
	
	 priority_queue<ii,vector<ii>,greater<ii>>pq;
	 pq.push(mp(dist[src],src));
	
	while(!pq.empty()){

          auto it=pq.top();
          ll dis=it.f;
          ll node=it.s;
           
           pq.pop();
           
           
           if(visited[node]){
           	continue;
           }
           
           visited[node]=1;
           
           
           for(auto neigh:grid[node]){
           	
           	auto weight=neigh.s;
           	auto v=neigh.f;
           	
           	if(dis+weight<dist[v]){
           		
           		dist[v]=dis+weight;
           	//	parent[v]=node;
           		
           		pq.push(mp(dist[v],v));
           	}
           	
           	
           	
           }

}
     		
		for(ll i=1;i<=n;i++){
			
			cout<<dist[i]<<" ";
		}
		cout<<nl;
		
		
	
}




void solve(){
	cin>>n>>b>>a;
	
	vector<ll>arr(n+1);
	 map<ll,ll>pseudo;
	 
	
	 m=n;
	
	
	
	for(ll i=1;i<=n;i++){
		cin>>arr[i];
		
		if(!pseudo[arr[i]]){
			m+=1;
			
			pseudo[arr[i]]=m;
		}
	}
		
	
vector<vector<ii>>grid(m+1);

	//creating type 1 node (adjacent); total no of nodes =2(N-1) at worst case
	
	
	for(ll i=1;i<=n;i++){
		
		
		if(i-1>=1){
			
			grid[i].push_back({i-1,a});
		}
		
		if(i+1<=n){
			grid[i].push_back({i+1,a});
		}
		
	}
	
	//type 2[same valued index edge] total no of nodes =2N at worst case
	
	for(ll i=1;i<=n;i++){
		
		grid[i].push_back({pseudo[arr[i]],0});
		grid[pseudo[arr[i]]].push_back({i,b});
		
		
	}
	
	ll src;
	cin>>src;
	
// 	for(auto it:grid){
		
// 		for(auto it1:it) {
// 			cout<<"{"<<it1.f<<" "<<it1.s<<"}"<<" ";}
// 			cout<<nl;
// 	}
	
	

	
	
	dijkstra(grid,src);
	
	
	
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
//	int _t; cin>>_t;while(_t--)
		solve();
	
	
	//cerr<<"Time elapsed: "<< 1.0*clock()/ CLOCKS_PER_SEC << "s.\n\n";
	
	
	
	
}


/*approach 
Approach: use the Super Node idea to reduce the number of edges.
For each same values nodes, generate a supernode, such that

i−−0−→SuperNodei and SuperNode i−−a−→i

for all index i having same value arr[i].
Now we have at max 2∗n nodes in the graph and 4∗n−2 edges.
Now apply Dijkstra's algorithm.
So , Time complexity of Dijktra's will be ~ 
O(nlogn)
.*/


/*All Pairs Shortest Path
1 min. readView original
Problem Code     *****()std

Accesscode : 14384

Description

We have given an adjacency representation of a directed weighted graph and 
an array of vertices. At each iteration, a vertex is removed from the graph. 
Vertices are removed in the order given in the array. When the vertex is 
removed, all the edges that go in and out are also removed. 

Print the sum of all pairs shortest path just before each iteration.

Input Format

The first line contains integer n (1≤n≤500) — 
the number of vertices in the graph.
Next n lines contain n integers each — the graph adjacency matrix: 
the j-th number in the i-th line aij (1≤aij≤105,aii=0) represents 
the weight of the edge that goes from vertex i to vertex j.
The next line contains n distinct integers: x1,x2,...,xn (1≤xi≤n) — 
the order of vertices removed from the graph.

Output Format

Print N space-separated numbers, where ith number represents the
 sum of all pairs shortest path just before ith removal.
 
 Constraints

1 ≤ N ≤ 500


Sample Input 1

2
0 5
4 0
1 2

Sample Output 1

9 0

Sample Input 2

4
0 3 1 1
6 0 400 1
2 4 0 1
1 1 1 0
4 1 2 3

Sample Output 2

17 23 404 0 */


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


ll n;

void solve(){
	cin>>n;
	
	ll dist[n][n];
	vector<ll>ans;
	
	for(ll i=0;i<n;i++){
		
		for(ll j=0;j<n;j++){ 
			cin>>dist[i][j];   // take the input array 
		}
	}
	
	ll node[n];
	for(ll i=0;i<n;i++){
		
		cin>>node[i];
		node[i]--;  // o based indexing 
	}
	
	
	for(ll k=n-1;k>=0;k--){   // relaxing the graph dist when a new node comes and start it from last (coming from future to present )
		
		for(ll i=0;i<n;i++){
			
			for(ll j=0;j<n;j++){
				
				dist[i][j]=min(dist[i][j],dist[i][node[k]]+dist[node[k]][j]); 
			}
		}
		
		
		ll temp=0;
		for(ll i=k;i<n;i++){
			for(ll j=k;j<n;j++){
				
				temp+=dist[node[i]][node[j]]; //// get the all pair distnce for all active nodes.
			}
		}
		
		
		
		
		ans.push_back(temp);
	
	}
	
	
	
	for(ll i=n-1;i>=0;i--){
		cout<<ans[i]<<" ";
		
	}
	
	
	
	
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	// int _t; cin>>_t;while(_t--)
		solve();
	
	
	//cerr<<"Time elapsed: "<< 1.0*clock()/ CLOCKS_PER_SEC << "s.\n\n";
	
	
	
	
}


/*The process of removing vertices from the present to the future is equivalent to adding vertices from the future to the present.
Therefore, the problem can be reframed as follows: Start from the future, progressively add vertices, and eventually reconstruct the graph as provided in the input.

Example
Lets take the Test Case 2 into consideration :
So the adjacency matrix is

0 3 1 1
6 0 400 1
2 4 0 1
1 1 1 0
The order in which vertices are removed are

4 1 2 3
We remove the vertex 1 at first and then remove the vertex 2.

Step 1 : Starting from future
So as discussed we would approach this problem from future. Initially we dont have any nodes so the total cost of shortest paths will be 0.

Step 2 : Adding node 3
We add the vertex 3 to an empty graph. The shortest path costs will still be 0 because there is no other node to traverse to. There is just a node 3 and traveling to 3 requires 0 cost.

So the shortest path adjacency matrix now stands to be

0
Step 3 : Adding node 2
After adding node 2, we now have 2 nodes 2 and 3. Using the floyd warshal algorithm continuation to find the shortest path matrix we get :

0 400
4 0
So the shortest path summation comes out to be 404.

Step 4 : Adding node 1
After adding node 1, we now have 3 vertices 1, 2 and 3. Using the floyd warshal algorithm continuation to find the shortest path matrix we get :

0 3 1
6 0 7
2 4 0
So the shortest path summation comes out to be 23.

Step 4 : Adding node 4
After adding node 4, we now have all the 4 vertices 1, 2, 3 and 4. Using the floyd warshal algorithm continuation to find the shortest path matrix we get :

0 1 1 1
1 0 2 1
1 2 0 2
1 2 2 0
So the shortest path summation comes out to be 17.

So we got our answers as 0, 404, 23, 17. Since this is the shortest path values as we keep on adding the vertices from future, we need to reverse them to get the values of removing the vertices each time and getting the shortest path sum cost.


#include<bits/stdc++.h>
#define ll long long int
#define N 510
using namespace std;

ll inf=1e16;
int main()
{
    int n;
    ll A[N][N]; // the adjecency matrix
    scanf("%d",&n); // take n.
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) scanf("%lld",&A[i][j]); // we take the graph in a 0 indexed manner.
    vector<ll> ans; // the final answer array.
    int x[N]; // the order of elements removed.
    for(int i=0;i<n;i++) scanf("%d",&x[i]),x[i]--;// take input, -- for 0 index
    for(int i=n-1;i>=0;i--) // move from backward [x[i],x[i+1]...x[n-1]] are the active edges.
    {
        for(int j=0;j<n;j++) 
            for(int k=0;k<n;k++) 
                A[j][k]=min(A[j][k],A[j][x[i]]+A[x[i]][k]); // relax the current node (Floyd washall)

        // After the ith iteration. The matrix has relaxed nodes x[i],x[i+1]...x[n-1].
        // So we these are the active nodes, and Floyd warshall ensures all those have correct shortest paths.
        ll temp=0;
        for(int j=i;j<n;j++) 
            for(int k=i;k<n;k++)
                temp+=A[x[j]][x[k]]; // get the all pair distnce for all active nodes.
        ans.push_back(temp); // add it to the ans.
    }
    for(int i=(int)ans.size()-1;i>=0;i--) printf("%lld ",ans[i]); // print in reverse order as we added instead of remove.
    return 0;
}*/



// dsu by rank 


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



class DisjointSet{   
	

	
public:
	
		vector<ll>rank,parent;
		
		vector<ll>size;
	DisjointSet(ll n){// constructor
		
	rank.resize(n+1,0); // for 1 based indexing
	parent.resize(n+1);
	
	
	size.resize(n+1,1); // for finding union find by size only size vector is required
	
	
	for(ll i=0;i<=n;i++){
		parent[i]=i;
	}
	
}

 int findUPar(ll node){
 	
 	if(node==parent[node]){
 		return node;
 	}
 	
 	return parent[node]=findUPar(parent[node]);  // caching the  recurstion of findUPar(parent of node) only path compression o(logn)
 	
 	
 	
 }
 
 
void findUnionByRank(ll u,ll v){
 	
 	ll rootu=findUPar(u);
 	ll rootv=findUPar(v);
 	
 	
 	if(rootu==rootv) return ;
 	
 	if(rank[rootu]<rank[rootv]){    // rank compression  with both rank and path compression o(log*n)-->hockerman func
 		
 		
 		parent[rootu]=rootv;
 		
 	}else if(rank[rootu]>rank[rootv]){
 		
 		parent[rootv]=rootu; // This line was missing in your code
 		
 	}else{
 		
 		parent[rootv]=rootu;
 		rank[rootu]++; // for union find by size it will be rank[rootu]+=rootv;
 		
 		
 		
 	}  
 	
 	
 }
 
 void findUnionBySize(ll u,ll v){
 	
 	ll rootu=findUPar(u);
 	ll rootv=findUPar(v);
 	
 	
 	if(rootu==rootv) return ;
 	
 	
 	if(size[rootu]<size[rootv]){
 		
 		
 		parent[rootu]=rootv;
 	} else {   // for >= case 
 		
 		
 		parent[rootv]=rootu;
 		
 		size[rootu]+=size[rootv];
 		
 		
 		
 	}
 	
 
 
 

 
 	
};

void solve(){
	
	DisjointSet ds(7);
	
	ds.findUnionByRank(1,2);
	ds.findUnionByRank(2,3);
	ds.findUnionByRank(4,5);
	ds.findUnionByRank(6,7);
	ds.findUnionByRank(5,6);
	
	
	
	if(ds.findUPar(3)==ds.findUPar(7)){
		
		cout<<"both are in same union set"<<nl;
	}else {
		
		cout<<"not same"<<nl;
	}
	
	//ds.findUnionByRank(3,7);
	
	ds.findUnionByRank(3,7);
	
	
	
	
		for(auto it:ds.parent){
 		cout<<"par[i]"<<it<< " ";
 	}
 	
 	cout<<nl;
 	
 	for(auto it:ds.rank){
 		cout<<"rank[i]"<<it<< " ";
 	}
 	
 	cout<<nl;
 		
 	} 
	
	
	


signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	// int _t; cin>>_t;while(_t--)
		solve();
	
	
	//cerr<<"Time elapsed: "<< 1.0*clock()/ CLOCKS_PER_SEC << "s.\n\n";
	
	
	
	
} //



/*

Disjoint Union

Time-Limit: 0.2 sec Score: 100.00/100
Difficulty : *(min)
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

Write a program that manipulates a disjoint set S = S1, S2, ..., Sk.

First of all, the program should read an integer n, then make a disjoint 
set where each element consists of 0, 1, ..., n-1 respectively.

Next, the program should read an integer q and manipulate the set of q queries.
 There are two kinds of queries for different operations:

unite(x, y): unite sets that contain x and y, say Sx and Sy, into a new set.
same(x, y): determine whether x and y are in the same set.

Input Format

The first line contains two space-separated integers n and q, (1 ≤ n ≤ 104, 1 ≤ q ≤ 105).
Then, q queries are given in the form com x y, where com represents
 the type of queries. '0' denotes unite and '1' denotes same operation (x != y).


Output Format

For each same operation, print 1 if x and y are in the same set, otherwise 0, in a line.


Sample Input 1

5 12
0 1 4
0 2 3
1 1 2
1 3 4
1 1 4
1 3 2
0 1 3
1 2 4
1 3 0
0 0 4
1 0 2
1 3 0
 


Sample Output 1

0
0
1
1
1
0
1
1
 */



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



class DisjointSet{   
	
vector<ll>rank,parent;
	
public:
	
		
	DisjointSet(ll n){// constructor
		
	rank.resize(n+1,0); // for 1 based indexing
	parent.resize(n+1);
	
	
	for(ll i=0;i<=n;i++){
		parent[i]=i;
	}
	
}

 int findUPar(ll node){
 	
 	if(node==parent[node]){
 		return node;
 	}
 	
 	return parent[node]=findUPar(parent[node]);  // caching the  recurstion of findUPar(parent of node)
 	
 	
 	
 }
 
void findUnionByRank(ll u,ll v){
 	
 	ll ultimate_parent_u=findUPar(u);
 	ll ultimate_parent_v=findUPar(v);
 	
 	
 	if(ultimate_parent_u==ultimate_parent_v) return ;
 	
 	if(rank[ultimate_parent_u]<rank[ultimate_parent_v]){
 		
 		parent[ultimate_parent_u]=ultimate_parent_v;
 		
 	}else if(rank[ultimate_parent_u]>rank[ultimate_parent_v]){
 		
 		parent[ultimate_parent_v]=ultimate_parent_u; // This line was missing in your code
 		
 	}else{
 		
 		parent[ultimate_parent_v]=ultimate_parent_u;
 		rank[ultimate_parent_u]++;
 		
 		
 		
 	}  
 	
 	
 }

 
 	
};

void solve(){
	
	
ll n,q;

cin>>n>>q;

DisjointSet ds(n);

while(q--){
    
  ll com,x,y;
  
  
  cin>>com>>x>>y;
  
  
  if(com==0){
      
      ds.findUnionByRank(x,y);
  }
  
  if(com==1){
      
      if(ds.findUPar(x)==ds.findUPar(y))cout<<1<<nl;
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


/* Tree Diameter - I

    Time-Limit: 1 sec Score: 100.00/100

Difficulty :

    Memory: 256 MB Accepted Submissions: 100

Relevant For:

Description

You are given a tree consisting of n nodes. The diameter of a tree is the maximum distance between two nodes. Your task is to determine the diameter of the tree.

Input Format

The first input line contains an integer n: the number of nodes. The nodes are numbered 1, 2, …, n.
Then there are n − 1 lines describing the edges. Each line contains two integers a and b: there is an edge between nodes a and b.

Output Format

Print the diameter of the tree.

Constraints

1 ≤ n ≤ 2 x 105
1 ≤ a, b ≤ n
Sample Input 1

5
1 2
1 3
3 4
3 5

Sample Output 1

3

Note

The diameter corresponds to the path 2→1→3→5.

1
*/

#include<bits/stdc++.h>
using namespace std;


#define ll long long int
# define nl "\n"
#define mp make_pair
#define ii pair<ll,ll>
#define f first
#define s second


ll n,m;

vector<ll>graph[300100]; // vector of array

ll dep[300100];
ll par[300100];
 ll numChild[300100];
ll subtreeSz[300100] ;


void dfs(ll node ,ll parent,ll depth){
    
    dep[node]= depth;
    
    par[node]=parent;
    

    // numChild[node]=0;
    // subtreeSz[node]=1;
    
       // subtree_sz[node]=1+  summation of(all subtree_sz[child]);
    for(auto it:graph[node]){ // go to the neighbours
        
        if(it!=parent){
            
            //numChild[node]++;
            dfs(it,node,depth+1);
            
           // subtreeSz[node]+=subtreeSz[it];
            
          
        }
        
    }
    
}


void solve(){
    
     cin>>n;
    
    for(ll i=1;i<n;i++){
        ll a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    dfs(1,0,0);
    
    ll max_child=1;
    for(ll j=2;j<=n;j++){
        
        if(dep[j]>dep[max_child]){
            max_child=j;
        }
    }
    
    dfs(max_child,0,0);
    
     
     max_child=1;
    for(ll j=2;j<=n;j++){
        
        if(dep[j]>dep[max_child]){
            max_child=j;
        }
    }
    
    
    cout<<dep[max_child]<<nl;
    
    
    
}



signed main(){
   
    
// ll t;
// cin>>t;


// while(t--)
solve();
    
    
    
}

/* Center of Tree

    Time-Limit: 1 sec Score: 75.00/100

Difficulty :

    Memory: 256 MB Accepted Submissions: 100

Relevant For:

Description

You are given a tree consisting of n nodes. Find the center of a tree. If there exist multiple centers, print -1.

Input Format

The first input line contains an integer n: the number of nodes. The nodes are numbered 1, 2, …, n.
Then there are n − 1 lines describing the edges. Each line contains two integers a and b: there is an edge between nodes a and b.

Output Format

Print the center of a tree. If there exist multiple centers, print -1.

Constraints

1 ≤ n ≤ 2 x 105
1 ≤ a, b ≤ n
Sample Input 1

3
1 2
1 3

Sample Output 1

1

1

*/
#include<bits/stdc++.h>
using namespace std;


#define ll long long int
# define nl "\n"
#define mp make_pair
#define ii pair<ll,ll>
#define f first
#define s second


ll n,m;

vector<ll>graph[300100]; // vector of array

ll dep[300100];
ll par[300100];




void dfs(ll node ,ll parent,ll depth){
    
    dep[node]= depth;
    
    par[node]=parent;
    
    
    
    
       // subtree_sz[node]=1+  summation of(all subtree_sz[child]);
    for(auto it:graph[node]){ // go to the neighbours
        
        if(it!=parent){
            
         
            dfs(it,node,depth+1);
          
        }
        
    }
    
}


void solve(){
    
     cin>>n;
    
    for(ll i=1;i<n;i++){
        ll a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    dfs(1,0,0);
    
    ll max_child=1;
    for(ll j=2;j<=n;j++){
        
        if(dep[j]>dep[max_child]){
            max_child=j;
        }
    }
    
    dfs(max_child,0,0);
    
     
     max_child=1;
    for(ll j=2;j<=n;j++){
        
        if(dep[j]>dep[max_child]){
            max_child=j;
        }
    }
    
    
if(dep[max_child]%2){
    
    cout<<-1<<nl;
}else if(dep[max_child]%2==0){
    
    ll half_path=(dep[max_child]/2)+1;
    
    for(ll i=1;i<half_path;i++){
        
        max_child=par[max_child];
    }
    
    cout<<max_child<<nl;
}
    
    
    
    
    
    
}



signed main(){
   
    
// ll t;
// cin>>t;


// while(t--)
solve();
    
    
    
}

/* Tree Diameter - II

    Time-Limit: 1 sec Score: 1.00/100

Difficulty :*****(very very imp)

    Memory: 256 MB Accepted Submissions: 100

Relevant For:

Description

You are given a tree consisting of n nodes. The diameter of a tree
 is the maximum distance between two nodes. Your task is to count 
 the number of different diameters of the tree.

Input Format

The first input line contains an integer n: the number of nodes. 
The nodes are numbered 1, 2, …, n.
Then there are n − 1 lines describing the edges. Each line contains
 two integers a and b: there is an edge between nodes a and b.

Output Format

Print the count of diameters of the tree.

Constraints

1 ≤ n ≤ 2 x 105
1 ≤ a, b ≤ n
Sample Input 1

5
1 2
1 3
3 4
3 5

Sample Output 1

2

Note

Two diameters are:

    2 → 1 → 3 → 4
    2 → 1 → 3 → 5

  */


#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair

#define nl "\n"

const int mod = 1e9 + 7;
const int N = 1e5 + 5;
ll n;
vector<ll>graph[300100];
ll par[300100];
ll dep[300100];

ll height=0;
ll cnt=0;

void dfs(ll node,ll parent,ll depth){
    
    par[node]=parent;
    dep[node]=depth;
    
    if(height==depth){
        cnt++;
    }
    for(auto neigh:graph[node]){
        
        
        if(neigh!=parent){
            
            dfs(neigh,node,depth+1);
        }
    }
   
}

void solve(){
cin>>n;


for(ll i=1;i<n;i++){
    
    ll a,b;
    cin>>a>>b;
    
    graph[a].push_back(b);
    graph[b].push_back(a);
    
    
}


if (n == 1 || n == 2)
    {
        cout << 1 << endl;
        return;
    }
    
    dfs(1,0,0);
    ll max_ch=1;
    
    for(int j=2;j<=n;j++){
        
        if(dep[j]>dep[max_ch]){
            
            max_ch=j;
        }
    }
    
    dfs(max_ch,0,0); // one end of diameter
    
    max_ch=1;
    
    for(int j=2;j<=n;j++){
        
        if(dep[j]>dep[max_ch]){
            
            max_ch=j;
        }
    }
    
    ll diameter_lenght=dep[max_ch];
    
    ll ans=0;

    
    
    if(!(diameter_lenght&1)){ // one center case
        
        ll k=diameter_lenght/2;
        
        ll center1=par[max_ch];
        k--;
        while(k--){
            
            center1=par[center1];
            
        }
        
        height=(diameter_lenght/2)-1;
        vector<ll>temp;
        for(auto it:graph[center1]){
            
                 cnt=0;
                 dfs(it,center1,0);
                 
                 temp.push_back(cnt);
            
            
        }
          ll presum=0;
         for(auto it:temp){
           
            ans+=presum*it;
            presum+=it;
         }
         
        
        
        
        
    }else{ // for 2 center case 
        
        ll k=diameter_lenght/2;
        
        ll c1=par[max_ch];
        k--;
        
        while(k--){
            
            c1=par[c1];
        }
        
        ll c2=par[c1];
        
        
      height=diameter_lenght/2;
        vector<ll>temp;
          
          cnt=0;
          dfs(c1,c2,0);
          temp.push_back(cnt);
          cnt=0;
          dfs(c2,c1,0);
          temp.push_back(cnt);
          
          ans=temp[0]*temp[1];
        
        
    }
    
    
    
    cout<<ans<<nl;
    
    
    
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // your code goes here
    
    ll t;
    // cin>>t;
    // while(t--)
        solve();

    return 0;
}


/*approach
A tree can have at most two centers. The center of a tree is also 
the center of its diameter. To find the center(s) of a tree, follow these steps:

Find the length of the diameter of the tree. The diameter is the 
longest path between any two nodes in the tree.

Once you have the length of the diameter, move from the farthest 
node towards the center by going up a distance of diameter/2 nodes.

If the length of the diameter (diameter) is even, there are two 
centers in the tree. These centers are located at nodes ⌊diameter2⌋
and ⌊diameter2⌋−1

    on the diameter path.

By identifying the length of the diameter and then moving towards
 the center, you can determine the center(s) of the tree. 
If the diameter length is even, there will be two centers at equal 
distances from both ends of the diameter.

Lets approach both the cases :
Case 1 : 1 center

    Consider the center of the tree, let's call it Center.

    Imagine the tree to be rooted at the Center.

    Traverse each adjacent node from the Center and consider them 
    as separate subtrees.

    For each subtree, determine the number of leaf nodes that are 
    located at a depth of ⌊diameter2⌋

    from the root of that subtree. (The diameter is the maximum 
    distance between two nodes in the tree.)

    Calculate the summation of all possible pairwise products of the
     number of leaf nodes in each subtree obtained from step 4. This will
      give you the count of all possible diameters in the tree when 
      there is only one center.

The idea behind this approach is that each adjacent node from the center 
represents a separate subtree. By finding the number of leaf nodes at a 
depth of diameter/2 in each subtree and considering pairwise combinations,
 you account for all possible diameters that can be formed by connecting 
 leaf nodes from different subtrees via the center.

By following these steps, you can determine the count of all possible
 diameters in a tree when there is one center.


Case 2 : 2 centers

    Consider the two centers of the tree. Let's call them Center1 and Center2.

    Start by imagining the tree to be rooted at Center1. From Center1, 
    explore each adjacent node and consider them as separate subtrees.

    For each subtree, determine the number of leaf nodes that are located
     at a depth of ⌊diameter2⌋

from the root of that subtree. (The diameter is the maximum distance
 between two nodes in the tree.)

Repeat the same process, but this time imagine the tree to be rooted
 at Center2. Explore each adjacent node from Center2 and determine 
 the number of leaf nodes at a depth of ⌊diameter2⌋

    from the root of each subtree.

    For each subtree on the side of Center1, and for each subtree on
     the side of Center2, calculate the number of leaf nodes satisfying 
     the condition mentioned in step 3 and step 4.

    Finally, find the summation of all possible pairwise products
     of the number of leaf nodes in each subtree obtained from step 5.
      This will give you the count of all possible diameters in the tree.

By following these steps, you can determine the count of all
 possible diameters in a tree with 2 centers.


        */




/*
 Min Edge Weight

    Time-Limit: 4 sec Score: 1.00/100

Difficulty :***

    Memory: 256 MB Accepted Submissions: 100

Relevant For:

Description

You are given a weighted tree of N nodes. D(u,v) is defined 
as the minimum weight of edge in the simple path from u to v. 
 Find the summation of D(u,v) for all 1≤u≤N, 1≤v≤N, where u<v.

Input Format

The first line of input contains one integer T (1 ≤ T ≤ 105) —
 the number of test cases. Then T test cases follow.
The first line of each test case contains an integer N - 
the number of nodes in the tree (1 ≤ N ≤ 105).
The next N-1 line of each test case contains 3 space-separated
 integers u, v, w  denoting that there is an edge between node
  u and node v of weight w. (1 ≤ u,v ≤ N), (1 ≤ w ≤ 109 ).

It is guaranteed that the sum of N over all test cases does not exceed 106.

Output Format

For each test case print the summation of D(u,v) for all 
1≤u≤N, 1≤v≤N, where u<v in a new line.
Sample Input 1

5
5
1 2 1
2 3 5
3 4 3
4 5 2
5
1 2 5
1 3 4
2 4 1
3 5 2
5
1 2 3
2 3 4
2 4 6
3 5 1
8
1 2 4
2 3 6
2 4 1
2 5 3
3 6 1
3 7 3
3 8 1
10
1 2 10
1 3 5
1 4 9
1 5 7
2 6 10
2 7 11
3 8 9
3 9 11
3 10 15

Sample Output 1

21
23
27
53
316

Note

For the 1st test case:

D(1,2) = D(1,3) = D(1,4) = D(1,5) = 1

D(2,3) = 5, D(2,4) = 3, D(2,5) = 2

D(3,4) = 3, D(3,5) = 2

D(4,5) = 2

Summation = 21

For the second test case:

D(1,2) = 5, D(1,3) = 4, D(1,4) = 1, D(1,5) = 2

D(2,3) = 4, D(2,4) = 1, D(2,5) = 2

D(3,4) = 1, D(3,5) = 2

D(4,5) = 1

Summation = 23

*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vi vector<int>
#define vl vector<ll>
#define vpii vector<pii>
#define vpll vector<pll>
#define all(x) (x).begin(), (x).end()
#define f first  
#define s second
#define lb lower_bound
#define ub upper_bound
#define sz(x) (int)(x).size()
#define nl "\n"

const int mod = 1e9 + 7;
const int N = 1e5 + 5;

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
    return (a / gcd(a, b)) * b;
}

ll binpow(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

ll add(ll a, ll b) {
    return (a + b) % mod;
}

ll sub(ll a, ll b) {
    return (a - b + mod) % mod;
}

ll mul(ll a, ll b) {
    return (a * b) % mod;
}

ll inv(ll a) {
    return binpow(a, mod - 2);
}

struct dsu {
    vector<ll> parent, size;
    dsu(ll n) {
        parent.resize(n+1);
        size.resize(n+1 ,1);
        for (ll i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }
    int find(ll x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }
    void unite(ll x, ll y) {
       ll root_x = find(x);
        ll root_y = find(y);
        if (root_x != root_y) {
            if (size[root_x] < size[root_y]) swap(root_x, root_y);
            parent[root_y] = root_x;
            size[root_x] += size[root_y];
        }
    }
};




void solve(){
	
	ll n;
	cin>>n;
	dsu ds(n);
	
	
	vector<pair<ll,pair<ll,ll>>>edglist;
	
	for(ll i=1;i<n;i++){
		
		ll u,v,w;
		
		cin>>u>>v>>w;
		
		edglist.push_back({w,{u,v}});
	}
	
	
	sort(edglist.begin(),edglist.end());
	ll ans=0;
	
	vector<ll>ans_store;
	
     for(auto it=edglist.rbegin();it!=edglist.rend();it++){  // moving from right side to left side;
     	 
     	ll weight=(*it).f;
     	ll u=(*it).s.f;
     	ll v=(*it).s.s;
     	
     
     	
     	
     	ans+=weight*(ds.size[ds.find(u)]*ds.size[ds.find(v)]);
     	 
     	
     		ds.unite(u,v);
     	
     }
	
	
	ans_store.push_back(ans);
	
	
	for(auto it:ans_store){
		
		cout<<it<<nl;
	}
	
	
	
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // your code goes here
    
    ll t;
    cin>>t;
    while(t--)
    	solve();

    return 0;
}


//approach
/*The main idea behind this solution is to use a modified version of 
the Union-Find data structure to calculate the summation of D(u,v)

efficiently.

Iterate over the sorted edges and process them one by one. 
For each edge (u, v) with weight w, we find the root of the 
tree that contains node u (rootU) and the root of the tree 
that contains node v (rootV) using the find operation of 
the Union-Find data structure.

If rootU and rootV are different (i.e., u and v belong to
 different trees), we calculate the contribution of this 
 edge to the final answer. The contribution is equal to 
 the product of the sizes of the trees rooted at rootU 
 and rootV, multiplied by the weight of the edge. We add 
 this contribution to the final answer.

The size of a tree is determined by the rank value in 
the Union-Find data structure. The rank represents an 
upper bound on the height of the tree. By merging smaller
 trees into larger trees, we can keep the height of 
 the tree small.
By processing the edges in descending order of their 
weights and using the Union-Find data structure, we ensure
 that we are considering the minimum weight edge in 
 the simple path between two nodes. This allows us to 
 calculate the desired summation efficiently.

*/


/* Weighted Union Find Trees

    Time-Limit: 0.3 sec Score: 1.00/100

Difficulty :****(imp ) explaination is in the YT video //2nd dsu 

    Memory: 256 MB Accepted Submissions: 100

Relevant For:

Description

There is a sequence A = a0, a1, ..., an-1. You are given the 
following information and questions.

    relate(x, y, z): ay is greater than ax by z.
    diff(x, y): report the difference between ax and ay i.e. ay - ax.

Input Format

The first line contains two space-separated integers n and q, 
(1 ≤ n ≤ 104, 1 ≤ q ≤ 2 x 105).
Then, q queries are given in the form either 0 x y z or 1 x y 
(0 ≤ x, y < n, x != y, 0 ≤ z ≤ 10000). '0' denotes the relate
 information and '1' denotes diff question.
It is guaranteed that there is no inconsistency in the given information.

Output Format

For each diff question, print the difference between ax and ay i.e.
 ay - ax. If we don't have any information for the current diff query, print '?'.
Sample Input 1

5 6
0 0 2 5
0 1 2 3
1 0 1
1 1 3
0 1 4 8
1 0 4

 
Sample Output 1

2
?
10

 

Note

Query 1: a2 - a0 = 5
Query 2: a2 - a1 = 3
Query 3: We can find the difference between a1 and a0 as a1 - a0 = 2
Query 4: We don't have any information about a3. That's why we print '?'
Query 5: a4 - a1 = 8
Query 6: We can find the difference between a4 and a0 as a4 - a0 = 10

 


*/



#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
#define MP make_pair
using pii= pair<lli,lli>;
#define endl '\n'
# define F first
# define S second
 using ld= long double;
lli n,m,q;
vector<lli> par,ans,ran,flag;
vector<pair<lli,lli>> v,query;
unordered_map<lli,unordered_map<lli,lli>> g;
lli find(lli x){
  if(par[x]==x)return x;
   return find(par[x]);
  
}

lli get_dis(lli x,lli ul){
   //lli dis=0;lli temp=x;
   if(x==ul)return 0;
  if(par[x]==x)return 0;
  // return g[x][par[x]]+get_dis(par[x],ul);
 return g[x][par[x]]+get_dis(par[x],ul);
}


lli diff(lli x,lli y){
   lli nn=find(x);
   lli mm=find(y);
   lli dis1=get_dis(x,nn);
   lli dis2=get_dis(y,mm);
   if(nn!=mm)return LONG_LONG_MAX;
   return dis2-dis1;
}

void unite(lli x,lli y,lli z){
  lli mm=find(x);
  lli nn=find(y);
lli xx=get_dis(x,mm);
lli yy=get_dis(y,nn);
 

   if(mm!=nn){
     if(ran[mm]<=ran[nn]){
       if(ran[mm]==ran[nn])ran[nn]++;
       par[mm]=nn;
      g[mm][nn]=yy-z-xx;
        g[nn][mm]=-g[mm][nn];
       //  g[mm][nn]=-g[nn][mm];
     }
     else{
        par[nn]=mm;
         g[nn][mm]=xx+z-yy;
         g[mm][nn]=-g[nn][mm];
     // g[nn][mm]=-g[mm][nn];
     }
   }

}

void relate(lli x,lli y,lli z){
    // g[y][x]=z;
    // g[x][y]=-z;
  unite(x,y,z);
}

void solve(){
  cin>>n>>q;

  //by level;
  ran.assign(n+1,0);
  par.resize(n+1);
  //g.assign(n+1,vector<lli>(n+1,LONG_LONG_MAX));
  for(lli i=0;i<=n;i++){
    g[i][i]=0;
  }
  for(lli i=0;i<=n;i++){
    par[i]=i;
  }

  for(lli i=0;i<q;i++){
    lli x,y,z,t;
    cin>>t;
    if(t==0){
      cin>>x>>y>>z;
      relate(x,y,z);
    }
    if(t==1){
      cin>>x>>y;
      lli dis=diff(x,y);
      ans.push_back(dis);
    }
  }
  
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
  solve();
 for(auto a:ans){
  if(a==LONG_LONG_MAX){
    cout<<"?"<<endl;
  
  }
  else{
    cout<<a<<endl;
  }

 }
//  for(lli i=0;i<=n;i++){
//   for(int j=0;j<=n;j++){
//     if(g[i][j]!=INT_MAX){
//       cout<<"i:"<<i<<"j:"<<j<<" "<<g[i][j]<<endl;
//     }
//   }
//  }
}

/*approach
For query of type 1 the difference between the pair of nodes is given .
For each query of type 2 , you have to determine the difference between
 the nodes. Since, only difference between nodes is given , 
 we can assume any node as the zero node or root node.

For all the nodes that are being added, the value of the node 
will not be its difference from its adjacent node , rather it 
will be the difference of that node from the zero or root node. 
Hence the value of node i, will be (a[root]- a[i]) . Now how can 
you use Disjoint Set Union small to large merge to determine 
the node values?

The Disjoint Union Set (DSU) has nodes that store their values 
relative to the root node, i.e., 
( \text{{Value of a DSU}} = a[\text{{root}}] - a[i] ). 
Initially, all values in DSU are 0. When a query of type '0' 
comes, we merge two DSUs and update the values in one of the 
DSUs based on their sizes. Smaller size DSU is merged with the
 larger DSU, and values in the smaller DSU are updated with an offset using DFS.

To answer a query of type '1', if two indices don't belong 
to the same DSU, print '?'. If they belong to the same DSU, 
return the difference between them.

Example Run:

780122013312300451141360342114

Output:

1??5

There are 7 nodes and 8 queries given.

    Node 1 and Node 2 are merged. Node 1 is considered as 
    a root node. DFS is run from 2: ({valuenode}[1]=0)

and ({valuenode}[2]=−2)

.

Node 1 and Node 3 are merged. DFS is run from 3: ({valuenode}[1]=0)
and ({valuenode}[3]=−3)

.

Calculate the difference: ({nodevalue}[2]−{nodevalue}[3]=−2−(−3)=1

.

Node 0 and Node 4 are merged. DFS is run from 4: ({valuenode}[0]=0)
and ({valuenode}[4]=−5)

.

Calculate the difference between Node 1 and Node 4. Since they 
have different roots, print '?'.

Calculate the difference between Node 3 and Node 6. Since Node 
6 has not been merged yet, print '?'.

Node 3 and Node 4 are merged. DFS is run from 4: ({valuenode}[3]=−3)
and ({valuenode}[4]=−5)

.

Calculate the difference: ({nodevalue}[4]−{nodevalue}[1]=−5−0=−5

    .

Time complexity: O(nlogn)

Space complexity: O(n)

extra space
*/


/* Road Reparation

    Time-Limit: 1 sec Score: 100.00/100

Difficulty :

    Memory: 256 MB Accepted Submissions: 100

Relevant For:

Description

There are n cities and m roads between them. Unfortunately, the condition of the roads is so poor that they cannot be used. Your task is to repair some of the roads so that there will be a decent route between any two cities.
For each road, you know its reparation cost, and you should find a solution where the total cost is as small as possible.

Input Format

The first input line has two integers n and m: the number of cities and roads. The cities are numbered 1, 2, …, n.
Then, there are m lines describing the roads. Each line has three integers a, b and c: there is a road between cities a and b, and its reparation cost is c. All roads are two-way roads.
Every road is between two different cities, and there is at most one road between two cities.

Output Format

Print one integer: the minimum total reparation cost. However, if there are no solutions, print "IMPOSSIBLE".

Constraints

1 ≤ n ≤ 105
1 ≤ m ≤ 2 x 105
1 ≤ a, b ≤ n
1 ≤ c ≤ 109
Sample Input 1

5 6
1 2 3
2 3 5
2 4 2
3 4 8
5 1 7
5 4 4

Sample Output 1

14

1

*/
#include <bits/stdc++.h>

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



class DisjointSet{   
	
vector<ll>rank,parent;
	
public:
	
		
	DisjointSet(ll n){// constructor
		
	rank.resize(n+1,1); // for 1 based indexing
	parent.resize(n+1);
	
	
	for(ll i=0;i<=n;i++){
		parent[i]=i;
	}
	
}

 int findUPar(ll node){
 	
 	if(node==parent[node]){
 		return node;
 	}
 	
 	return parent[node]=findUPar(parent[node]);  // caching the  recurstion of findUPar(parent of node) // path compression
 	                                                // path compression it takes o(log n)
 	                                               
 	
 }
 
void findUnionBySize(ll u,ll v){
 	
 	ll root_u=findUPar(u);
 	ll root_v=findUPar(v);
 	
 	
 	if(root_u==root_v) return ;
 	
 	if(rank[root_u]<rank[root_v]){  // rank compression  with both rank and path compression o(log*n)-->hockerman func
 		
 		parent[root_u]=root_v;
          rank[root_v]+=rank[root_u];
 		
 	}else{
 		
 		parent[root_v]=root_u;
 		rank[root_u]+=rank[root_v];
 		
 		
 		
 	}  
 	
 	
 }

 
 	
};

void solve(){
	
	ll n,m;
	cin>>n>>m;
	
	vector<pair<ll,ll>>graph[100100];
	
	vector<pair<ll,pair<ll,ll>>>edglist;
	for(ll i=1;i<=m;i++){
		
		ll a,b,c;
		cin>>a>>b>>c;
		
		edglist.push_back({c,{a,b}});
		
	}

	sort(edglist.begin(),edglist.end()); // from smaller edge weight to higher weight 
	
	DisjointSet ds(n);
	
	ll min_mst_cost=0;
	ll edge_cnt=0;
	
	for(auto it:edglist){
		
		
		auto cost=it.f;
		auto x=it.s.f;
		auto y=it.s.s;
		
		if(ds.findUPar(x)!=ds.findUPar(y)){
			edge_cnt++;
			graph[x].push_back({y,cost});
			graph[y].push_back({x,cost}); // final undirected tree
			
			min_mst_cost+=cost;
			ds.findUnionBySize(x,y);
		}
		
	}
	
	

if(edge_cnt!=n-1){
	
	cout<<"IMPOSSIBLE"<<nl;
}else {cout<<min_mst_cost<<nl;}
	
 		
 	} 
	
	
	


signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	// int _t; cin>>_t;while(_t--)
		solve();
	
	
	//cerr<<"Time elapsed: "<< 1.0*clock()/ CLOCKS_PER_SEC << "s.\n\n";
	
	
	
	
}





/* Sum of Distances

    Time-Limit: 1 sec Score: 100.00/100

Difficulty :*

    Memory: 256 MB Accepted Submissions: 100

Relevant For:

Description

You are given a tree consisting of n nodes. d(u, v) is the 
distance between nodes u and v, or number of edges in between 
the path connecting two nodes u and v. Your task is to find 
the sum of distances over all possible pairs of nodes.

Input Format

The first input line contains an integer n: the number of nodes. 
The nodes are numbered 1, 2, …, n.
Then there are n − 1 lines describing the edges. Each line 
contains two integers a and b: there is an edge between nodes a and b.

Output Format

Print the sum as mentioned in the problem statement.

Constraints

1 ≤ n ≤ 2 x 105
1 ≤ a, b ≤ n
Sample Input 1

5
1 2
1 3
3 4
3 5

Sample Output 1

18

Note

    d(1, 1) = 0, d(1, 2) = 1, d(1, 3) = 1, d(1, 4) = 2, d(1, 5) = 2
    d(2, 2) = 0, d(2, 3) = 2, d(2, 4) = 3, d(2, 5) = 3
    d(3, 3) = 0, d(3, 4) = 1, d(3, 5) = 1
    d(4, 4) = 0, d(4, 5) = 2
    d(5, 5) = 0

*/






#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vi vector<int>
#define vl vector<ll>
#define vpii vector<pii>
#define vpll vector<pll>
#define all(x) (x).begin(), (x).end()
#define F first
#define S second
#define lb lower_bound
#define ub upper_bound
#define sz(x) (int)(x).size()
#define nl "\n"

const int mod = 1e9 + 7;
const int N = 1e5 + 5;

/*ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
    return (a / gcd(a, b)) * b;
}

ll binpow(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

ll add(ll a, ll b) {
    return (a + b) % mod;
}

ll sub(ll a, ll b) {
    return (a - b + mod) % mod;
}

ll mul(ll a, ll b) {
    return (a * b) % mod;
}

ll inv(ll a) {
    return binpow(a, mod - 2);
}

struct dsu {
    vector<ll> parent, size;
    dsu(ll n) {
        parent.resize(n);
        size.resize(n, 1);
        for (ll i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    int find(ll x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }
    void unite(ll x, ll y) {
       ll root_x = find(x);
        ll root_y = find(y);
        if (root_x != root_y) {
            if (size[root_x] < size[root_y]) swap(root_x, root_y);
            parent[root_y] = root_x;
            size[root_x] += size[root_y];
        }
    }
};

*/

ll n;
vector<ll>tree[300100];

ll par[300100];
ll dep[300100];
ll subtreeSz[300100];

void dfs(ll node, ll parent, ll depth){ // parameter
	
	par[node]=parent;
	dep[node]=depth;
	subtreeSz[node]=1;// for single node 
	
	for(auto neigh:tree[node]){
		
		if(neigh!=parent){
			
			dfs(neigh,node,depth+1);
			subtreeSz[node]+=subtreeSz[neigh];
		}
	}
	
	
	
	
	
}

void solve(){
	
	cin>>n;
	
	for(ll i=1;i<n;i++){
		
		ll a,b;
		cin>>a>>b;
		tree[a].push_back(b);
		tree[b].push_back(a);
		
	}
	
	dfs(1,0,0); // argument 
	
	// for(ll i=0;i<=n;i++){
		
	// 	cout<<subtreeSz[i]<<" ";
	// }
	
	// cout<<nl;
	ll ans=0;
	
	for(ll i=1;i<=n;i++){
		ans+=subtreeSz[i]*(n-subtreeSz[i]);
		
	}
	
	cout<<ans<<nl;
	
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // your code goes here
    
    ll t;
    // cin>>t;
    // while(t--)
    	solve();

    return 0;
}





/* Centroid

    Time-Limit: 1 sec Score: 1.00/100

Difficulty : *

    Memory: 256 MB Accepted Submissions: 100

Relevant For:

Description

Given a tree of n
nodes, your task is to find a centroid, i.e., a node such that 
when it is appointed the root of the tree, each subtree has at most ⌊n/2⌋

nodes.

Input Format

The first input line contains an integer n: the number of nodes. 
The nodes are numbered 1,2,…,n.

Then there are n−1
lines describing the edges. Each line contains two integers a and b:
 there is an edge between nodes a and b

.

Output Format

Print one integer: a centroid node. If there are several possibilities, 
print the smallest one.

Constraints

1≤n≤2⋅105

1≤a,b≤n

Sample Input 1

5
1 2
2 3
3 4
3 5

Sample Output 1

3

*/





#include <bits/stdc++.h>
using namespace std;

#define int long long

const int mod = 1e9+7;

vector<int> adj[200020];
int parent[200020];
int depth[200020];
int subtreesz[200020];
int isLeaf[200020];
int numChild[200020];
int n;

void dfs(int node,int par,int dep)
{
    parent[node]=par;
    depth[node]=dep;
    subtreesz[node]=1;
    numChild[node]=0;
    isLeaf[node]=0;
    
    for(auto it:adj[node])
    {
        if(it!=par)
        {
            numChild[node]++;
            dfs(it,node,dep+1);
            subtreesz[node]+=subtreesz[it];
        }
    }
    
    if(numChild[node]==0) isLeaf[node]=1;
}

int dfs1(int node,int parent)
{
    for(auto it:adj[node])
    {
        if(it!=parent)
        {
            if(subtreesz[it] > (n/2)) return dfs1(it,node);
        }
    }
    return node;
}


void solve()
{
    cin>>n;
    
    for(int i=0;i<n-1;i++)
    {
        int a,b;cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    dfs(1,0,0);
    
    int ans = dfs1(1,0);
    
    //ans=min(ans,dfs1(ans,parent[ans]));
    
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

/*pproach

We can find a centroid in a tree by starting at the root. Each step,
 loop through all of its children. If all of its children have subtree 
 size less than or equal to N2, then it is a centroid. Otherwise, move
  to the child with a subtree size that is more than N2

and repeat until you find a centroid.

Time Complexity : DFS ~ O(N+M)*/



/* Complete the Game

    Time-Limit: 2 sec Score: 1.00/100

Difficulty :

    Memory: 256 MB Accepted Submissions: 100

Relevant For:

Description

A game has n levels, connected by m teleporters, and your task is to get from level 1 to level n. The game has been designed so that there are no directed cycles in the underlying graph. In how many ways can you complete the game?

Input Format

The first input line has two integers n and m: the number of levels and teleporters. The levels are numbered 1, 2, …, n.
After this, there are m lines describing the teleporters. Each line has two integers a and b: there is a teleporter from level a to level b.

Output Format

Print one integer: the number of ways you can complete the game. Since the result may be large, print it modulo 109+7.

Constraints

1 ≤ n ≤ 105
1 ≤ m ≤ 2 x 105
1 ≤ a, b ≤ n
Sample Input 1

4 5
1 2
2 4
1 3
3 4
1 4

Sample Output 1

3

*/




#include <bits/stdc++.h>
using namespace std;


// use topological ordering


#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n;
vector<int> edge[100001];
vector<int> backedge[100001];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int m; cin >> n >> m;
    int in_degree[n+1], dp[n+1];
    for(int i = 0; i <= n; i++){
        in_degree[i] = 0;
        dp[i] = 0;
    }
    dp[1] = 1;
    for(int i = 0; i < m; i++){
        int a,b; cin >> a >> b;
        edge[a].push_back(b);
        backedge[b].push_back(a);
        in_degree[b]++;
    }
    //uses Kahn's algorithm
    queue<int> q;
    for(int i = 0; i < n; i++) {
        if(in_degree[i] == 0) {
            q.push(i);
        }
    }

    while(!q.empty()) {
        int node = q.front();
        q.pop();
        for(int next : edge[node]) {
            in_degree[next]--;
            if(in_degree[next] == 0) q.push(next);
        }

        for(int prev : backedge[node]) {
            dp[node] = (dp[node] + dp[prev]) % 1000000007;
        }
    }
    cout << dp[n] << endl;
    return 0;
}


/* approach
Topological Sorting.

Now think about each node as a dp state, and try to find the transition.

One useful property of directed acyclic graphs is, as the name suggests,
 that no cycles exist. If we consider each node in the graph as a state,
  we can perform dynamic programming on the graph if we process the states 
  in an order that guarantees for every edge u → v that u is processed before v.
   Fortunately, this is the exact definition of a topological sort!

Let dp[v] denote the number of paths reaching v. We can see, dp[v]= sum of 
all dp[u], s.t. u → v edge exists.
With an exception of dp[1], or the starting node, having a value of 1. 
We process the nodes topologically so dp[u] will already have been 
computed before dp[v].*/


