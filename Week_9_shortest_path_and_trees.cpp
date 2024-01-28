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