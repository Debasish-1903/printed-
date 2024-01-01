/*Find the Number of Rooms

Time-Limit: 1 sec Score: 1.00/100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

You are given a map of a building, and your task is to count the
 number of its rooms. The size of the map is n × m squares, and each
 square is either floor or wall. You can walk left, right, up, and 
 down through the floor squares.


Input Format

The first input line has two integers n and m: the height and
 width of the map.
Then there are n lines of m characters describing the map. 
Each character is either ‘.’ (floor) or '#' (wall).


Output Format

Print one integer: the number of rooms.


Constraints

1 ≤ n, m ≤ 1000


Sample Input 1

5 8
########
#..#...#
####.#.#
#..#...#
########

Sample Output 1

3*/


int neighborX[4] = {0, 0, 1, -1};
int neighborY[4] = {1, -1, 0, 0};

int n, m, answer = 0;
int vis[1010][1010];
char grid[1010][1010];

bool isValid (int y, int x) {
  if (y < 0) return false;
  if (x < 0) return false;
  if (y >= n) return false;
  if (x >= m) return false;
  if (grid[y][x] == '#') return false;
  return true;
}

void DFS (int y, int x) {
  vis[y][x] = 1;
  for (int i = 0 ; i < 4 ; i++) {
    int newX = x + neighborX[i];
    int newY = y + neighborY[i];
    if (isValid(newY, newX)) {
      if (!vis[newY][newX]) {
        DFS(newY, newX);
      }
    }
  }
}

int main() {
    cin >> n >> m;
    for (int i = 0 ; i < n ; i++) {
      for (int j = 0 ; j < m ; j++) {
        cin >> grid[i][j];
        vis[i][j] = 0;
      }
    }
    for (int i = 0 ; i < n ; i++) {
      for (int j = 0 ; j < m ; j++) {
        if (grid[i][j] == '.' && !vis[i][j]) {
          DFS(i, j);
          answer++;
        }
      }
    }
    cout << answer << endl;
    return 0;
}


/*Round Trip

Time-Limit: 1 sec Score: 1.00/100
Difficulty : *
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

Zenithland has n cities and m roads between them. Your task 
is to check for the existence of a round trip that begins in
 a city, goes through two or more other cities, and finally 
 returns to the starting city. Every intermediate city on the 
 route has to be distinct.


Input Format

The first input line has two integers n and m: the number of 
cities and roads. The cities are numbered 1, 2, …, n.
Then, there are m lines describing the roads. Each line has two 
integers a and b: there is a road between those cities.
Every road is between two different cities, and there is at
 most one road between any two cities.


Output Format

Print ‘YES’ if such round trip exists, otherwise print ‘NO’.


Constraints

1 ≤ n ≤ 105
1 ≤ m ≤ 2 x 105
1 ≤ a, b ≤ n


Sample Input 1

5 6
1 3
1 2
5 3
1 5
2 4
4 5

Sample Output 1

YES

Sample Input 2

4 3
1 2
1 3
3 4

Sample Output 2

NO*/


ll n,m;

vector<vector<int>>g;

vector<int>vis;
vector<int>parent;

bool is_cycle=0;
void dfs(ll node,ll par){
	
	parent[node]=par;
	vis[node]=1;
	
//	cout<<node<<"parnt"<<par<<nl;
	for(auto it:g[node]){
	//	cout<<it<<"node"<< node<<"parent of node"<<parent[node]<<nl;
		
		if(it==parent[node]) continue;
		if(vis[it]==0){
			
			dfs(it,node);
		
		}if(vis[it]==1){
			
			is_cycle=1;
	//	return;
		
		}
		
	

}

	vis[node]=2;		
	

	
}


void solve(){
	
	cin>>n>>m;
	g.resize(n+1);
	vis.assign(n+1,0);
	parent.assign(n+1,0);
	
	for(int i=0;i<m;i++){
		
		int a,b;
		
		cin>>a>>b;
		
		
		
		
		
		g[a].push_back(b);
		g[b].push_back(a);
		
	}
	
	for(ll i=1;i<=n;i++){
		
		if(vis[i]==0){
			
			dfs(i,0);
		}
	}
	
	
		if(is_cycle==0){
		
		cout<<"NO"<<nl;
	
	}else{
		
		cout<<"YES"<<nl;
	
	}
	
	

	
}


/*Easy Graph Queries

Time-Limit: 1 sec Score: 100.00/100
Difficulty : *
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

You have given an undirected graph G with N nodes and M edges. 
You've to answer Q queries. Each query is either of the 
following two types:

1 X: Print the size of the connected components containing node X.
2 X Y: Print ‘YES’ (without quotes) if node X and Y belong to the 
same connected component, else print ‘NO’ (without quotes).

Input Format

The first line of input contains three space-separated integers
 N, M, and Q (1 ≤ N, M, Q ≤ 105).
Next M lines contain two space-separated integers
 u and v (1 ≤ u, v ≤ N).Each of the next Q lines contains queries 
 of one of the types as described in the statement.


Output Format

Print Q lines as the answer to the Q queries, each on a new line.


Sample Input 1

6 5 5
1 2
2 3
1 3
4 4
5 6
1 2
1 4
2 3 4
1 5
2 5 6

Sample Output 1

3
1
NO
2
YES*/

ll n,m,qu;

vector<vector<int>>g;



vector<int>vis;
queue<int>q;
int comp_no=0;

vector<int>comp_size;


void bfs(){
	
	vis.assign(n+1,0);
	
	for(int i=1;i<=n;i++){
		
		if(!vis[i]){
			
			//comp_no=0;
			
			int node_explored=0;
				comp_no++;
			q.push(i);
			vis[i]=comp_no;
			
			node_explored++;
			
		
			while(!q.empty()){
				
				int node=q.front();
				
				q.pop();
				
				for(auto it:g[node]){
					
					if(!vis[it]){
						
						q.push(it);
						vis[it]=comp_no;
						
						node_explored++;
						
					}
				}	
				
			}
			
			comp_size.pb(node_explored);
				
		}
			
	}
			
}

void solve(){
	
	cin>>n>>m>>qu;
	
	g.resize(n+1);
	
	for(ll i=0;i<m;i++){
		
		int a,b;
		
		cin>>a>>b;
		
		g[a].push_back(b);
		g[b].pb(a);
			
	};
	
	bfs();
	
	
	while(qu--){
		
		int d;
		cin>>d;
		if(d==1){
			int x;
			cin>>x;
			
			cout<<comp_size[vis[x]-1]<<nl;
			
		}else if(d==2){
			
			int x,y;
			cin>>x>>y;
			
			
			if(vis[x]==vis[y])cout<<yes<<nl;
			else cout<<no<<nl;
			
		}
		
	}
		
}

/*One Edge

Time-Limit: 2 sec Score: 1.00/100
Difficulty : **
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

You have given an undirected graph with n nodes, and m edges
between them. The goal is to add exactly one edge between two nodes
such that the total number of connected components in the graph decreases.
Your task is to find out the number of ways to add such edge.


Input Format

The first input line has two integers n and m: the number of 
nodes and edges. The nodes are numbered 1, 2, …, n.
After that, there are m lines describing the edges. Each line 
has two integers a and b: there is an edge between those nodes.
An edge always connects two different nodes, and there is at 
most one edge between any two nodes.


Output Format

Print the number of ways to add such edge, described in the statement.


Constraints

1 ≤ n ≤ 105
1 ≤ m ≤ 2 x 105
1 ≤ a, b ≤ n


Sample Input 1

5 4
1 2
2 3
1 3
4 5

Sample Output 1

6

Sample Input 2

4 3
1 2
2 3
3 4

Sample Input 3

0

Note

Explanation 1:
There are 6 ways to add edge so that the number of connected 
components in the graph decreases: (1, 4), (1, 5), (2, 4), (2, 5), (3, 4), (3, 5).

Explanation 2:
The given graph is already connected. Even if add any edge, 
we can't decrease the number of connected components.


1*/


vector<vector<int>> g;
vector<int> vis;
vector<int> co;
queue<int> q;

void bfs(int src) {
    int comp_sz = 0;

    q.push(src);
    vis[src] = 1;
    comp_sz++;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (auto it : g[node]) {
            if (!vis[it]) {
                vis[it] = 1;
                q.push(it);
                comp_sz++;
            }
        }
    }

    co.push_back(comp_sz);
}

void solve() {
    int n, m;
    cin >> n >> m;

    g.resize(n + 1);
    vis.assign(n + 1, 0);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        g[a].push_back(b);
        g[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            bfs(i);
        }
    }

    sort(co.rbegin(), co.rend());  // Sort in non-increasing order

    long long sum = 0, sum_sq = 0;
    for (auto it : co) {
        sum += it;
        sum_sq += 1LL * it * it;
    }

    long long ans = (sum * sum - sum_sq) / 2;
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}


/*Round Trip II

Time-Limit: 1 sec Score: 1.00/100
Difficulty : *
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

Zenithland has 
n cities and m flight connections.
 Your task is to design a round trip that begins in a city, 
 goes through one or more other cities, and finally returns 
 to the starting city. Every intermediate city on the route has
  to be distinct.


Input Format

First line contains 
T- Number of test cases.
First input line of each test case has two integers 

n and m:the number of cities and flights. The cities are numbered 1,2,…,n
.
Then, for each test case, there are 
m lines describing the flights. Each line has two integers a and b
: there is a flight connection from city 
a to city b
. All connections are one-way flights from a city to another city.


Output Format

For each test case, Print "Yes" if such round trip exists,
 otherwise print "No" in a new line.


Constraints

1≤T≤10

1≤n≤10^5

1≤m≤2⋅105

1≤a,b≤n

Sample Input 1

1
4 5
1 3
2 1
2 4
3 2
3 4

Sample Output 1

Yes*/


vector<vector<int>>g;
vector<int>vis;

int is_cycle;
void dfs(ll node){
	
	vis[node]=1;

	for(auto it:g[node]){
	
	if(vis[it]==0){
			dfs(it);
			
		}else if(vis[it]==1){
			
			is_cycle=1;
	         return;
		}
		
		
	
		
	}
	
	vis[node]=2;
	
}



void solve(){
    
    g.clear();
	ll n,m;
	
	cin>>n>>m;
	
	is_cycle=0;
	g.resize(n+1);
	vis.assign(n+1,0);
//	parent.assign(n+1,0);
	
	for(ll i=0;i<m;i++){
		
		int a,b;
		cin>>a>>b;
		
		g[a].pb(b);
	
		
	}
	
	
	for(ll i=1;i<=n;i++){
		
		if(!vis[i]){
			
			dfs(i);
		}
		
	}
	
	if(is_cycle==1){
		
		cout<<"Yes"<<nl;
	}else{
		
		cout<<"No"<<nl;
	}
	
	
}


/*Save Yourself

Time-Limit: 1 sec Score: 1.00/100
Difficulty : **
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

You and some monsters are in a matrix. When taking a step to some
 direction in the matrix, each monster may simultaneously 
 take one as well. Your goal is to reach one of the boundary 
 squares without ever sharing a square with a monster.
Your task is to find out if your goal is possible, and if it is,
 print the shortest length of the path that you can follow. Your
  plan has to work in any situation; even if the monsters know 
  your path beforehand.


Input Format

The first input line has two integers n and m: the height
 and width of the matrix.
After this, there are n lines of m characters describing the matrix.
 Each character is ‘.’ (floor), ‘#’ (wall), ‘A’ (start), or ‘M’ (monster).
  There is exactly one ‘A’ in the input.


Output Format

First, print "YES" if your goal is possible, and "NO" otherwise.
If your goal is possible, also print the length of the shortest 
path that you'll follow.


Constraints

1 ≤ n, m ≤ 1000


Sample Input 1

5 8
########
#M..A..#
#.#.M#.#
#M#..#..
#.######

Sample Output 1

YES
5

Sample Input 2

3 3
###
#A#
#M.

Sample Output 2

NO

Sample Input 3

1 3
##A

Sample Output 3

YES
0*/


#define ii pair<int,int>


const int N=1010;
int n,m;

bool grid[1010][1010] ;
int distM[1010][1010];
int distA[1010][1010];

queue<ii>Mocc,Aocc;
pair<int,int> par[N][N];

vector<ii>moves={
	
	{0,1},{0,-1},{1,0},{-1,0}
	
};
// int dx[4] = {-1, 1, 0, 0};
// int dy[4] = {0, 0, -1, 1};


bool is_valid(int x,int y){
	
	
// 	if(x< 0 || x >= n || y < 0 || y >= m)return false;
// 	else return true;

 return (x >= 0 && x < n && y >= 0 && y < m);

}

void solve(){
	
	cin>>n>>m;
	
memset(grid,false,sizeof(grid));

memset(distA,-1,sizeof(distA));
memset(distM,-1,sizeof(distM));
	
	
	 for(int i = 0; i < n; i++) {
        string str; cin >> str;
        for(int j = 0; j < m; j++) {
            grid[i][j] = true;
            if(str[j] == '#') grid[i][j] = false;
            else if(str[j] == 'M') {
                distM[i][j] = 0;
                Mocc.push({i, j});
            }
            else if(str[j] == 'A') {
                distA[i][j] = 0;
                Aocc.push({i, j});
                par[i][j] = {-1, -1};
            }
        }
    }
	while(!Mocc.empty()){
		
		auto cur=Mocc.front();
		
		int x=cur.f,y=cur.s;
		
		Mocc.pop();
		
		
		//for(int i=0;i<4;i++){
		    	for(auto it:moves){
			
			//int xx=x+dx[i],yy=y+dy[i
				int xx=x+it.f,yy=y+it.s;
			
			 //if(xx < 0 || xx >= n || yy < 0 || yy >= m) continue;
			  if(!is_valid(xx,yy)) continue;
			else if(grid[xx][yy]&&distM[xx][yy]==-1){
			
			distM[xx][yy]=distM[x][y]+1;
		
		     Mocc.push({xx, yy});}
 		}
		
		
	}
	
// 	 while(!Mocc.empty()) {
//         auto it = Mocc.front();
//         Mocc.pop();
//         int x = it.first, y = it.second;

//         for(int i = 0; i < 4; i++) {
//             int xx = x + dx[i], yy = y + dy[i];
//             if(xx < 0 || xx >= n || yy< 0 || yy >= m) continue;
//             if(grid[xx][yy] && distM[xx][yy] == -1) {
//                 distM[xx][yy] = distM[x][y] + 1;
//                 Mocc.push({xx, yy});
//             }
//         }
//     }
	
	
	while(!Aocc.empty()){
		
		auto cur=Aocc.front();
		
		int x=cur.first,y=cur.second;
		
		Aocc.pop();
		
		
	//	for(int i=0;i<4;i++){
			for(auto it:moves){
// 			int xx=x+dx[i]; 
// 			int yy=y+dy[i];
			int xx=x+it.f,yy=y+it.s;
			 //if(xx < 0 || xx >= n || yy < 0 || yy >= m) continue;
			 
			  if(!is_valid(xx,yy)) continue;
			   if(grid[xx][yy]&&distA[xx][yy]==-1){ 
			
			         distA[xx][yy]=distA[x][y]+1;
		              Aocc.push({xx, yy});}
		}
		
		
	}
// 	 while(!Aocc.empty()) {
//         auto it = Aocc.front();
        
//         int x = it.first, y = it.second;
//          Aocc.pop();
//         for(int i = 0; i < 4; i++) {
//             int xx = x + dx[i], yy = y + dy[i];
//             if(xx < 0 || xx >= n || yy < 0 || yy >= m) continue;
//           else  if(grid[xx][yy] && distA[xx][yy] == -1) {
//                 distA[xx][yy] = distA[x][y] + 1;
//                 Aocc.push({xx, yy});
//               // par[xx][yy] = {x, y};
//             }
//         }
//     }
	
	
	
	int finx=-1,finy=-1, findist=1e9;
	
	
	
	for(int i=0;i<n;i++){
		
		
		if(grid[i][0]&&distA[i][0]>=0&&(distA[i][0]<distM[i][0]||distM[i][0]==-1)){
			
			
			finx=i,finy=0;
			
			findist=min(findist,distA[i][0]);
			
			
		}
		if(grid[i][m-1]&&distA[i][m-1]>=0&&(distA[i][m-1]<distM[i][m-1]||distM[i][m-1]==-1)){
			
			
			finx=i,finy=m-1;
			
			findist=min(findist,distA[i][m-1]);
			
			
		}
		
		
		
	}
	
	for(int i=0;i<m;i++){
		
		
		if(grid[0][i]&&distA[0][i]>=0&&(distA[0][i]<distM[0][i]||distM[0][i]==-1)){
			
			
			finx=0,finy=i;
			
			findist=min(findist,distA[0][i]);
			
			
		}
		if(grid[n-1][i]&&distA[n-1][i]>=0&&(distA[n-1][i]<distM[n-1][i]||distM[n-1][i]==-1)){
			
			
			finx=n-1,finy=i;
			
			findist=min(findist,distA[n-1][i]);	
		}
	}
	if(finx==-1){
		
		
		cout<<"NO"<<nl;
	}else{
		cout<<"YES"<<nl<<findist<<nl;
	}

	return;
}


/*Building Roads

Time-Limit: 1 sec Score: 100.00/100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

Zenithland has n cities and m roads between them. The goal is to construct new roads so that there is a route between any two cities. A road is bidirectional.
Your task is to find out the minimum number of roads required.


Input Format

The first input line has two integers n and m: the number of cities and roads. The cities are numbered 1, 2, …, n.
After that, there are m lines describing the roads. Each line has two integers a and b: there is a road between those cities.
A road always connects two different cities, and there is at most one road between any two cities.
 


Output Format

Print the number of minimum roads required.


Constraints

1 ≤ n ≤ 105
1 ≤ m ≤ 2 x 105
1 ≤ a, b ≤ n


Sample Input 1

4 2
1 2
3 4

Sample Output 1

1

Note

Construct a road between cities 1 and 3.*/


int n,m;
vector<vector<int>>g;
vector<int>vis;

int no_comp;
void bfs(int src){
    
    queue<int>q;
    
    q.push(src);
    vis[src]=1;
    no_comp++;
    
    while(!q.empty()){
        
        int node=q.front();
        q.pop();
        
        for(auto it:g[node]){
            if(!vis[it]){
                
                vis[it]=1;
                q.push(it);
                
          }   
            
        }  
    }   
}

void solve(){
 cin>>n>>m;
 
 g.resize(n+1);
 vis.assign(n+1,0);
 
 for(int i=0;i<m;i++){
int a,b;
cin>>a>>b;

g[a].pb(b);
g[b].pb(a);
  
     
 }
 
 for(int i=1;i<=n;i++){
     
     if(vis[i]==0){
         
         bfs(i);
     }
     
     
 }
 
 cout<<no_comp-1<<nl;
 
	
}


/*Creating Teams

Time-Limit: 1 sec Score: 50.00/100
Difficulty : *
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

There are n students in AlgoZenith Course and m friendships 
between them. Your task is to divide the students into two 
teams in such a way that no two students in a team are friends.
 You can freely choose the sizes of the teams. The size of each
  team should be positive.


Input Format

The first input line has two integers n and m: the number of
 students and friendships. The students are numbered 1, 2, …, n.
Then, there are m lines describing friendships. Each line has
 two integers a and b: students a and b are friends.
Every friendship is between two different students. You can 
assume that there is at most one friendship between any two students.


Output Format

Print ‘YES’ if it's possible to divide students in two teams, 
otherwise print ‘NO’.


Constraints

1 ≤ n ≤ 105
1 ≤ m ≤ 2 x 105
1 ≤ a, b ≤ n


Sample Input 1

5 3
1 2
1 3
4 5

Sample Output 1

YES

Sample Input 2

4 3
1 2
2 3
1 3

Sample Output 2

NO*/

int n,m;
vector<vector<int>>g;
//vector<int>vis;

int cyc_ele=0;
vector<int>color;


bool bfs(int src){
    queue<int>q;
    q.push(src);
    //vis[src]=1;
    color[src]=0;
    
    while(!q.empty()){
        
        int node=q.front();
        q.pop();
        for(auto it:g[node]){
            
            
         if(color[it]==-1){
                
                //vis[it]=1;
                color[it]=!color[node];
                q.push(it);
                
            }else if(color[it]==color[node]){
                
                return false;
     
                
            }
           
        }
       
    }
    
    return true;
    
}

bool check(){
    	for(int i=1;i<=n;i++){
	    
	    if(color[i]==-1){
	       if(bfs(i)==false){
	          return false;  
	       }
	        
	    }
	}
    
    return true;
}

void solve(){
	cin>>n>>m;
	g.resize(n+1);
	//vis.assign(n+1,0);
  color.assign(n+1,-1);
	for(int i=0;i<m;i++){
	    int a,b;
	    cin>>a>>b;
	    
	    g[a].pb(b);
	    g[b].pb(a);
	    
	}
	

if(check()){
    
    cout<<"YES"<<nl;
    
}else{
    
    cout<<"NO"<<nl;
}	

}


/*Colour Tree

Time-Limit: 2 sec Score: 1.00/100
Difficulty : ***
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

You have been given a tree with N nodes and N - 1 edges. You want 
to colour each node, such that no two adjacent nodes 
(directly connected by an edge) and no two nearly-adjacent nodes 
(both directly connected to a common node with edges) has the same colour. 
Your task is to find the minimum number of colours required 
to accomplished this. 


Input Format

The first line of input contains N. Each of the remaining N−1 lines
 describes an edge in terms of the two nodes it connects.


Output Format

Print the minimum number of colours require.


Constraints

1 ≤ N ≤ 105


Sample Input 1

4
1 2
4 3
2 3

Sample Output 1

3

Note

We require 4 different colours, colour(1) = 1, colour(2) = 2, 
colour(3) = 3, colour(4) = 1.*/


int n,m;
vector<vector<int>>g;

ll mx=INT_MIN;
void solve(){
	cin>>n;
	m=n-1;
	g.resize(n+1);

	for(int i=0;i<m;i++){
	    int a,b;
	    cin>>a>>b;
	    
	    g[a].pb(b);
	    g[b].pb(a);
	    
	}
	
	for(int i=1;i<=n;i++){
	ll length=g[i].size();
	
	if(length+1>mx){
	    mx=length+1;
	}

	}

cout<<mx;
}


/*Area and Perimeter of Connected Components

Time-Limit: 2 sec Score: 1.00/100
Difficulty : ****
 Memory: 256 MB Accepted Submissions: 100
Relevant For:201,02,301
Description

You have been given a grid of size N x N. Each cell is either empty (.) 
or occupied (#). Size of each cell is 1 x 1. In the connected component,
 you can reach any cell from every other cell in the component by repeatedly
  stepping to adjacent cells in the north, south, east, and west directions. 
Your task is to find the area and perimeter of the connected component having 
the largest area. The area of a connected component is just the number of '#' 
characters that are part of it. If multiple connected components tie for the 
largest area, find the smallest perimeter among them.


Input Format

The first line of input contains N, and the next N lines describe the grid.
 At least one '#' character will be present.


Output Format

Please output one line containing two space-separated integers, the first being 
the area of the largest connected component, and the second being its perimeter.
 If multiple connected components tie for the largest area, print the one which 
 has the smallest perimeter among them.


Constraints

1 ≤ N ≤ 1000


Sample Input 1

6
##....
....#.
.#..#.
.#####
...###
....##

Sample Output 1

13 22*/




#define ii pair<int,int>
int n;



vector<vector<int>>grid;
vector<vector<int>>vis;


int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};


vector<ii>v;
void bfs(ii src){
    
    int area=0;
    int peri=0;
    
    queue<ii>q ;
    vis[src.first][src.second]=1;
    q.push(src);
    area++;
    
    
    for(int i=0;i<4;i++){
        int srcx=src.f+dx[i],srcy=src.s+dy[i];
        
        if(grid[srcx][srcy]==0) peri++;
        
    }
    
    while(!q.empty()){
        auto node=q.front();
        
        
        int x=node.first,y=node.second;
        q.pop();
        
        for(int i=0;i<4;i++){
            
            int xx=x+dx[i],yy=y+dy[i];
            
            if(xx<0||xx>=n+2||y<0||yy>=n+2)continue;
            else if(grid[xx][yy]==1&&vis[xx][yy]==0){
             
                   area++;
                vis[xx][yy]=1;
                   q.push({xx,yy});
                   
                   
                   for(int i=0;i<4;i++){
                   int xxx=xx+dx[i],yyy=yy+dy[i];
                   if(grid[xxx][yyy]==0)peri++;
                   
                   }
                   
            }//else 
            
            
        }
         
    }
    
    
v.pb({-area,peri}) ; 
   
}

void solve(){
cin>>n;
grid.assign(n+2,vector<int>(n+2,0));
vis.assign(n+2,vector<int>(n+2,0));

for(int i=0;i<n;i++){
    
   string str;
   cin>>str;
   
  for(int j=0;j<n;j++){
      if (str[j]=='#'){grid[i+1][j+1]=1;}
       
   }
    

}

for(int i=0;i<n+2;i++){
    
    
    for(int j=0;j<n+2;j++){
        
        if(grid[i][j]==1&&vis[i][j]==0){
            
            bfs({i,j});
           
           
        }
        
        
        
        
    }
}




// for(int i=0;i<n+2;i++){
//   for(int j=0;j<n+2;j++){
       
//       cout<<grid[i][j];
//   }
//   cout<<nl;
    
// }	


// for(auto it:v){
    
//     cout<<-it.f<<" "<<it.s<<nl;
// }
	
sort(v.begin(),v.end());

cout<<-v[0].f<<" "<<v[0].s<<nl;
	
}


/*approach*/
/*Given a grid of cells with # or . (empty) elements. Each cell of the grid 
is equivalent to the node of a graph. All valid transitions to neighboring 
cells (right, left, top and bottom), form the edges that connect the cells.
 In this way, how many connected components do you see in the grid?


The grid can be divided into components of contiguous-filled cells. The area
 is the size of the component, while the perimeter is the count of the number
  of cell borders of the component, which is not shared by another filled cell. 
  We are going to use flood fill to determine the maximum possible area and
   its corresponding minimum possible perimeter.


This problem can be solved with flood fill. We loop over all cells, and
 depth-first search or breadth-first search to label the entire component 
 containing the cell. Ordinarily this would take 
O(N4)time, since each search could take 

O(N2)time and we perform O(N2)
 searches. However, if a cell has already been visited by a previous search 
 (i.e. it is in the same component as a previously seen cell) then we can skip it,
  since the cells in its component have already been labelled. Thus, every cell is 
  only visited once, so the complexity of all the searches together is only O(N2)
, which runs in time.

Now each cell is labelled with a "component ID". Now we need to find the area and 
perimeter of each connected component. The area is simply the number of cells 
labelled with this ID, and the perimeter is the sum over all cells in the region 
of the number of "border edges" of that cell: that is, the number of empty-space 
cells adjacent to that cell.

Hence, we can initialize the area and perimeter of each region to zero, and compute
 them incrementally by making a final pass over the grid.

Once all areas and perimeters are computed, it is a simple matter to find the largest
 area, and among those connected components with largest area, find the smallest perimeter.

We traverse over all the cells of the grid , keeping count of the maximum contiguous 
filled components we can find. We apply DFS or BFS to do so. Since the number of cells is  
N2, there will be N2
searches on all the N2
 cells making the time complexity O(N4)
.

The time complexity can be reduced easily by maintaining a vis[][] array ,
 which marks the cell that has been visited once already. When a cell is getting marked ,
  all the cells that are in the same component as that cell are also traversed and marked. .
   Hence no cell is traversed twice and the time complexity becomes O(N^2).

Alternative Explanation:

In order to calculate the area of the components, count the number of filled cells
 in that component. The value of perimeter is the count of border edges of the 
 connected cells, which they share either with a boundary or an empty cell.

Then finally for all the connected components, find the one with the largest 
area and its corresponding perimeter.

EXAMPLE RUN :
5
#.  ..  #
##  .#  #
..  ..  #
##  ..  .
##  ..  .

This is an 
5×5 grid. Start the dfs from the top left cell. Since it's a filled cell , 
dfs traverses to all the components from that cell.
 Here the area = number of components = 3 .Perimeter is the number of cell 
 borders which are part of the boundary 
(3)+shared by an empty cell (5)=8 .

Also mark the cells visited in this way.

Next move on to the 5th cell of the 1st row and the connected cells in that component. 
Area and perimeter come out to be 
4 and 10 respectively.

Finally, the 3rd component is reached, where area and perimeter is 4 and 8 respectively.
 This is the maximum possible value of the area and its corresponding least perimeter.

So the answer is 4 and 8 .

TIME COMPLEXITY : 
O(N^2)*/



/*Smallest Permutation

Time-Limit: 1 sec Score: 100.00/100
Difficulty : **
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

Among the sequences 
P that are permutations of (1,2,…,N)
 and satisfy the condition below, find the lexicographically smallest sequence.

For each  i=1,…,M,Ai appears earlier than Bi in P
.
If there is no such  P, print -1.


Input Format

Input is given from Standard Input in the following format:

NM
A1 B1
:
:
AM BM

Output Format

Print the answer.


Constraints

2≤N≤2×10^5

1≤M≤2×10^5

1≤ Ai, Bi ≤N
 Ai ≠ Bi

All values in input are integers.


Sample Input 1

4 3
2 1
3 4
2 4

Sample Output 1

2 1 3 4

Sample Input 2

2 3
1 2
1 2
2 1

Sample Output 2

-1*/

int n,m;
 vector<vector<int>>g;
  vector<int>innode;
  vector<int>topo;
  
  
  void kahn(){
      
      priority_queue<int>pq;
      
  	for(int i=1;i<=n;i++){
  	    if(innode[i]==0)pq.push(-i);
  	}
  	
 
  while(!pq.empty()){
      
      int node=-pq.top();
      pq.pop();
      
      topo.pb(node);
      
      for(auto it:g[node]){
          
          innode[it]--;
          
          if(innode[it]==0){pq.push(-it);}
          
      }
       
      
  }
  
  
  }
  
  
void solve(){
	
	
	//it is valid for dag
	
	cin>>n>>m;
	
	
	g.resize(n+1);
	innode.assign(n+1,0);
	for(int i=0;i<m;i++){
     int a,b;
		cin>>a>>b;
		
		g[a].push_back(b);
		innode[b]++;
	}
	
		kahn();
	
	
//reverse(topo.begin(),topo.end());



if(topo.size()!=n){
    
    cout<<-1<<nl;
}else{

for(auto it:topo){
    
    cout<<it<<" ";
}}	
	
}


/*Graph Girth

Time-Limit: 1 sec Score: 1.00/100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

Given an undirected graph, your task is to determine its girth, i.e., the length of its shortest cycle.


Input Format

The first input line has two integers 
n and m: the number of nodes and edges. The nodes are numbered 1,2,…,n.

After this, there are 
m lines describing the edges. Each line has two integers a
 and 
b:there is an edge between nodes a and b .

You may assume that there is at most one edge between every two nodes.
Output Format

Print one integer: the girth of the graph. If there are no cycles, print −1.
Constraints

1
≤
n
≤
2500

1
≤
m
≤
5000

Sample Input 1

5 6
1 2
1 3
2 4
2 5
3 4
4 5

Sample Output 1

3

Sample Input 2

10 9
5 6
4 5
8 9
9 10
1 2
6 7
3 4
2 3
7 8

Sample Output 2

-1*/

vector<int> d;
int g;
void bfs(vector<int> adj[], int s) {
    queue<int> q;
    q.push(s);

    d[s] = 0;

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        for (auto x : adj[v]) {
            if (d[x] == INT_MAX) {
                q.push(x);
                d[x] = d[v] + 1;
            }
            else if (d[v] <= d[x]) {
                g = min(g, d[v] + d[x] + 1);
                if (d[v] == d[x]) {   // optimisation.
                    return;
                }
            }

        }
    }
}

void solve() {
    int n, m, u, v;
    cin >> n >> m;
    vector<int> adj[n + 1];
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    g = INT_MAX;
    for (int i = 1; i <= n; i++) {
        d.assign(n + 1, INT_MAX);
        bfs(adj, i);
    }
    cout << ((g == INT_MAX) ? -1 : g);
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

/*
approach

Supppose you run a bfs from a node 1 to find if there is a cycle involving 
the node 1 what would you look for?? Whenever during bfs we visit some previously
 visited node then we can say that we have found a cycle. 
 Can you guess the length of the cycle?


Let's say when we move from node u to node v during bfs we find that v is 
already discovered and v is not the parent of u. So the obvious conclusion 
is that there is a cycle. What will be the length of the cycle??
$dist[u] + dist[v] + 1(\text{the edge between u and v}).$



cmoplete approcah 

Let's consider a simpler problem: given a graph, find the shortest cycle that
passes through node 1.

What does a cycle through node 1 look like? In any cycle through node 1, there
exists two nodes 
u
 and 
v
 on that cycle such that there is a path from 1 to
u
 and 1 to 
v
, and there is an edge between 
u
 and 
v
. The length of this
cycle is dist(1,u)+dist(1,v)+1.

One might now try to use BFS to find 

dist(1,i)for each i in O(N+M)time and then check for each edge
 (u,v) whether dist(1,u)+dist(1,v)+1 is minimal.

Of course, this means that we might count a "cycle" like
1→x→u→v→x→1
.
However, this doesn't matter for our original problem, since the shortest cycle
will always be shorter than such a "cycle".

There's one problem with this approach though: if the edge 
(u,v) is on the
path from node 1 to node 
v
, then 1→u→v→1

isn't a cycle! And this time, it does matter in our original problem!

Fortunately, there's a relatively simple fix.

Instead of first finding all 
dist(1,i)
 and then checking for the minimum, do
both at the same time during the BFS.

Now to prevent "backtracking", we only consider 
dist(1,u)+dist(1,v)+1
 as
a minimum if we're currently at node u and dist(1,u)≤dist(1,v).

This algorithm runs in 

O(N+M)time. Since  N and M
 are so
small, we can just apply this algorithm for all nodes instead of just node 1.

The final complexity of this solution is thus 
O(N∗(N+M)).


*/

/*Shortest Path I

Time-Limit: 1 sec Score: 1.00/100
Difficulty : *
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

There are n cities and m roads. The capital is located at 1. Your task is
 to determine the length of the shortest route from the capital to every city.


Input Format

The first input line has two integers n and m: the number of cities and road 
connections. The cities are numbered 1, 2, …, n, and city 1 is Capital.
After that, there are m lines describing the roads. Each line has three integers
 a, b and c: a road begins at city a, ends at city b, and its length is c. 
 Each road is a one-way road.
You can assume that it is possible to travel from Capital to all other cities.


Output Format

Print n integers: the shortest route lengths from Capital to cities 1, 2, …, n.


Constraints

1 ≤ n ≤ 105
1 ≤ m ≤ 2 x 105
1 ≤ a, b ≤ n
1 ≤ c ≤ 109


Sample Input 1

3 4
1 2 6
1 3 2
3 2 3
1 3 4

Sample Output 1

0 5 2*/

int mod = 1e9 + 7;

const int N = 100010;

vector<pair<int,int>> graph[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;

    for(int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
    }

    ll dist[n + 1];
    bool marked[n + 1];

    for(int i = 1; i <= n; i++) {
        dist[i] = 1e18;
        marked[i] = false;
    }

    priority_queue <pair<ll,int>> q;

    dist[1] = 0;
    q.push({0, 1});

    while(!q.empty()) {
        int u = q.top().second;
        ll w = -q.top().first;

        q.pop();

        if(marked[u]) continue;
        marked[u] = true;

        for(auto it : graph[u]) {
            int v = it.first;
            ll c = it.second;
            if(dist[v] > dist[u] + c) {
                dist[v] = dist[u] + c;
                q.push({-dist[v], v});
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        cout << dist[i] << " ";
    }
    cout << "\n";
}

/*approach

This problem requires finding the shortest path from the capital (vertex 1)
 to every other vertex in a graph with weighted edges.


This problem can be solved using Dijkstra's algorithm. Dijkstra's algorithm 
is a greedy algorithm that finds the shortest path between nodes in a weighted graph.


Initialize an array of distances called dist, with the distance to the 
starting vertex set to 0 and all other distances set to infinity.

Create a priority queue called pq to store vertices and their distances.
 Insert the starting vertex with distance 0 into the priority queue.

While the priority queue is not empty, remove the vertex with the smallest 
distance from the queue.

For each neighbor of the removed vertex, calculate the tentative distance
 to that neighbor by adding the distance to the removed vertex and the 
 weight of the edge connecting them.

If the tentative distance is less than the current distance stored in the
 dist array for that neighbor, update the dist array with the new distance
  and insert the neighbor into the priority queue with its updated distance.

Repeat steps 3-5 until all vertices have been visited or the destination
 vertex has been removed from the queue.

The shortest path to any vertex from the starting vertex is the distance 
stored in the dist array for that vertex.

Dijkstra's algorithm guarantees finding the shortest path in a graph with 
non-negative edge weights. The algorithm works by maintaining a set of 
visited vertices and a set of unvisited vertices, and at each iteration,
 it selects the unvisited vertex with the smallest tentative distance and 
 adds it to the visited set. The algorithm then relaxes all the edges of the
  selected vertex, updating the tentative distances of its neighbors
   if a shorter path is found.

The priority queue is used to efficiently retrieve the vertex with the
 smallest tentative distance. By using a priority queue, we avoid the need
  to search through the entire set of unvisited vertices for the vertex with
   the smallest tentative distance, which would result in a time complexity of 
   O(V2)
. Instead, the priority queue provides a faster time complexity of O(ElogV)
 for processing all the edges and vertices in the graph, where E is the number
  of edges and V is the number of vertices.


*/


/*Vertical Grid (day 5 archived unsolved)

Time-Limit: 2 sec Score: 0.00/100
Difficulty :*** 
 Memory: 256 MB Accepted Submissions: 100
Relevant For:202,301
Description

You have been given a vertical grid of size N x 10, and a number K.
 Since it's vertical, gravity shows its effect on it. Each cell in
  the grid contains a ball which has some colour. Colour values 
  can vary between 1 to 9.
Each cell in the grid is represented by a number, cij for cell (i, j).
 If cij = 0, then the cell (i, j) is empty. Otherwise, it contains a 
 ball with colour cij. Each cell is either empty (indicated by a 0),
  or a ball in one of nine different colours (indicated by characters 1..9).
   Gravity causes balls to fall downward, so there is never a 0 cell below a ball.
Two cells belong to the same connected region if they are directly adjacent
 either horizontally or vertically, and they have the same non-zero colour.
  Any time a connected region exists with at least K cells, its balls all
   disappear, turning into zeros. If multiple such connected regions exist 
   at the same time, they all disappear simultaneously. Afterwards, gravity 
   might cause balls to fall downward to fill some of the resulting cells 
   that became zeros. In the resulting configuration, there may again be 
   connected regions of size at least K cells. If so, they also disappear 
   (simultaneously, if there are multiple such regions), then gravity pulls
    the remaining balls downward, and the process repeats until no connected 
    regions of size at least K exist.
Given the initial vertical grid, your task is to output a final picture of 
the grid after these operations have occurred.


Input Format

The first line of input contains N and K. The remaining N lines specify
 the initial state of the vertical grid.


Output Format

Please output N lines, describing a picture of the final vertical grid.


Constraints

1 ≤ N ≤ 100
1 ≤ K ≤ 10N


Sample Input 1

6 3
0000000000
0000000300
0054000300
1054502230
2211122220
1111111223

Sample Output 1

0000000000
0000000000
0000000000
0000000000
1054000000
2254500000

Note

In the example above, if K = 3, then there is a connected region of size at 
least K with colour 1 and also one with colour 2. Once these are simultaneously 
removed, the grid temporarily looks like this:

0000000000
0000000300
0054000300
1054500030
2200000000
0000000003
Then, gravity takes effect and the balls drop to this configuration:

0000000000
0000000000
0000000000
0000000000
1054000300
2254500333
Again, there is a region of size at least K (with colour 3). Removing it yields
 the final grid configuration:

0000000000
0000000000
0000000000
0000000000
1054000000
2254500000*/



/*Topological Labelling (day6 archived unsolved)

Time-Limit: 1 sec Score: 0.00/100
Difficulty : ****
 Memory: 256 MB Accepted Submissions: 100
Relevant For:201,202,301
Description

You are given a directed acyclic graph with 
n
 vertices and 
m
 edges. There are no self-loops or multiple edges between any pair of vertices. 
 The graph can be disconnected.

You should assign labels to all vertices in such a way that:

Labels form a valid permutation of length 
n
 — an integer sequence such that each integer from 
1
 to 
n
 appears exactly once in it.
If there exists an edge from vertex v to vertex u
 then label>v should be smaller than label>u   > ---denotes in suffix
.
Permutation should be lexicographically smallest among all suitable.
Find such a sequence of labels to satisfy all the conditions.


Input Format

The first line contains two integer numbers n, m.

Next 
m
 lines contain two integer numbers v and u— edges of the graph. 
 Edges are directed, the graph doesn't contain loops or multiple edges.


Output Format

Print n numbers — lexicographically smallest correct permutation of labels of vertices.


Constraints

2≤n≤105
1≤m≤105
1≤v,u≤n,v≠u

Sample Input 1

3 3
1 2
1 3
3 2

Sample Output 1

1 3 2 

Sample Input 2

4 5
3 1
4 1
2 3
3 4
2 4

Sample Output 2

4 1 2 3 

Sample Input 3

5 4
3 1
2 1
2 3
4 5

Sample Output 3

3 1 2 4 5 

Note

In Sample Test 2, Assigning 
l
abel1=4
,
label2=1, label3=2
 and 
label4=3
 will give the lexicographically smallest correct permutation of labels of 
 vertices which will be 
4 1 2 3
.*/




