
 all bs quest are ⭐
/*Rotated Sorted Array⭐

Time-Limit: 2 sec Score: 100.00/100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

Given a rotated sorted array. Find the index of the minimum element in the array.

All the elements are distinct.

 


Input Format

The first line contains T, the number of test cases (1<=T<=10000).

The first line contains an integer N where 1<=N<=10^5.

The second line contains N space-separated integers A1,A2....AN where -1e9<=Ai<=1e9.

Sum of N over all test cases ≤10^6.


Output Format

For each test case print the index of the minimum element in the array.

0-indexed.


Sample Input 1

5
5
3 4 5 1 2
5
4 5 1 2 3
5
5 1 2 3 4
5
1 2 3 4 5
5
2 3 4 5 1

Sample Output 1

3
2
1
0
4*/
int n, arr[100100];

int check(int x){
	
	if(arr[x]<arr[0]){return 1;}
	else{return 0;}	
}


void solve(){
	
	//int n;
	cin>>n;
	
	for(int i=0;i<n;i++){
		
		cin>>arr[i];
		
	}
	
	int l,r,mid,ans;
	
	l=0;r=n-1; ans=0;
	
	while(l<=r){
		
		mid=l+((r-l)>>1);
		
		if(check(mid)){
			
			ans=mid;
			r=mid-1;
			
		}else{
			
			
			l=mid+1;
		}
			
	}
	
	cout<<ans<<nl;
	
}


/*approach --The array was sorted in ascending order originally. When it is rotated,
 there would be a point in the array where the element is smaller than the element 
 before it, i.e. A[i-1] > A[i]. You need to find this point.


You can use the fact that all numbers to the left of the inflection point 
(where the element is smaller than the element before it) are greater than 
the first number and all numbers to the right of the inflection point are smaller 
than the first number.*/


/*Bitonic Array ⭐

Time-Limit: 2 sec Score: 1.00/100
Difficulty :** 
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

Given a bitonic array A consisting of N integers and an integer Q. 
In each query, you will be given an integer K, find the positions of K in A.
 Integer K exists in A.

Bitonic array - 
A bitonic sequence is a sequence with A[1]<A[2]<A[3]....A[k]>A[k+1]>A[k+2]....>A[N] 
for some 1<=K≤N. 


Input Format

The first line contains T, the number of test cases (1<=T<=10000).

The first line contains two space separated-integer N, Q where 1<=N<=10^5, 1<=Q<=10^6.

The second line contains N space-separated integers A1,A2....AN where -1e9<=Ai<=1e9.

Next Q lines contains an integer K, -1e9<=K<=1e9.

Sum of N, Q across all test case ≤10^6


Output Format

For each test case print the positions of K in A in sorted order in a new line.

Positions are 1-indexed.


Sample Input 1

1
6 4
1 2 5 3 2 1
1
2
5
3

Sample Output 1

1 6
2 5
3
4*/

int n,q;
vector<int> arr;

bool check(int i){
   if(arr[i]>arr[i-1])return 1;
   else return 0;
}

void solve(){
   cin>>n>>q;
   arr.resize(n);
   for(int i=0;i<n;i++){
       cin>>arr[i];
   }

   int lo = 1;
   int hi = n-1;
   int peak = 0;
   while(lo<=hi){
       int mid = (lo+hi)/2;
       if(check(mid)){
           peak = mid;
           lo = mid + 1;
       }else{
           hi = mid - 1;
       }
   }

   while(q--){
       int k;
       cin>>k;

       vector<int> final;
       lo = 0;
       hi = peak-1;
       while(lo<=hi){
           int mid = (lo+hi)/2;
           if(arr[mid]==k){
               final.push_back(mid+1);
               break;
           }else if(arr[mid]>k){
               hi=mid-1;
           }else{
               lo=mid+1;
           }
       }

       lo = peak;
       hi = n-1;
       while(lo<=hi){
           int mid = (lo+hi)/2;
           if(arr[mid]==k){
               final.push_back(mid+1);
               break;
           }else if(arr[mid]>k){
               lo=mid+1;
           }else{
               hi=mid-1;
           }
       }

       for(auto v:final){
           cout<<v<<" ";
       }  
       cout<<endl;
   }
}

/*approach
The given array can be seen as two different arrays which are merged together,
 one is in increasing order and the other in decreasing order.


First, find the peak of the given array using binary search and since both the 
parts of the array are sorted, we can use binary search on both of them to find 
the given query number.


*/

/*ClassRoom

Time-Limit: 4 sec Score: 1.00/100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Description

Vivek has built a new classroom with N seats. The seats are located along a 
straight line at positions x1,x2…..xN.
Vivek has to assign seats to K students such that a seat can be assigned to 
at most 1 student and the minimum distance between any two students is as 
large as possible. Find the largest minimum distance possible.


Input Format

The first line contains a single integer T (1 ≤ T ≤ 100000) - the number 
of test cases.

The first line of each test case contains 2 space-separated integers N, 
K (2 ≤ N ≤ 100000, 2 ≤ K ≤ N) - the number of seats and the number of students.

The second line of each test case contains N space-separated integers 
(0 ≤ xi ≤ 10^9) - the position of the seats. All the given positions are distinct.

Sum of N across all test cases ≤ 10^6.


Output Format

For each test case print the largest minimum distance possible in a new line.


Sample Input 1

14
13 3
6048 2794 6123 1643 6907 6993 2382 6961 1094 488 7424 6469 6009 
10 6
469 706 278 545 711 386 298 242 385 316 
18 17
1042 271 839 45 1253 1060 428 676 418 1298 1230 668 665 158 916 659 458 202
11 10
16073873 456996657 980038523 123316193 427829862 54109396 319462445 181390046
 543060523 490620628 938036110
6 2
274592090 858952753 241301573 721888021 806214246 383142174
12 5
5940 28062 23820 1965 3005 18306 23749 18322 17322 15504 14570 4481
17 13
1905 1798 5250 986 1239 3311 3519 5262 2444 151 5580 5008 1914 2366 5285 1528 331 
4 3
792050646 886157889 58701906 576742651
9 6
3584 5153 5516 6249 2453 3992 6179 1646 4810
7 6
149042184 953621985 987837168 343845676 726735692 6723177 435784762 
4 3
149479138 621021707 506424026 519149062 
2 2
1557 4228 
5 2
4150 9442 5146 9633 3537
6 4
160913372 862781533 10044128 722271773 201193061 944524755 

Sample Output 1

2306
70
8
38035523
617651180
3975
116
309415238
706
91939086
114597681
2671
6096
191148933*/

ll n,k,arr[100100];



int check(ll x){
    
    ll minpost=arr[0];
    
    ll stu=1;
    
    
    for(ll i=1;i<n;i++){
        
        
        
        if(arr[i]-minpost>=x){
            
            stu++;
            minpost=arr[i];    
        }
          
    }
    
    if(stu>=k){
        
        return 1;
    }else{
        
        return 0;
    }
    
    
   // return 1;
    
    
}
void solve(){
	cin>>n>>k;

	for(ll i=0;i<n;i++){
		
		
		cin>>arr[i];
		
	}
	sort(arr,arr+n);
	ll mid,l,r,ans;
	l=1;
	r=arr[n-1]-arr[0];
//	ans=1;
	
	while(l<=r){
		
		mid=l+((r-l)/2);
		
		if(check(mid)){
		
			ans=mid;
			
			l=mid+1;
			
			
		}else{
			
			r=mid-1;
		}
		
	}
	
	cout<<ans<<nl;
	
}


/*approach -->
If minimum distance, X is possible by assigning seats to K students,
 then it is possible to have a minimum distance lesser than X as well. 
 That means this is a monotonic function. You can use this to apply 
 binary search.


We would be doing binary search on the largest minimum adjacent distance
 possible. First, we will sort the seat positions given to us. We take 
 the left pointer as L = 1(since it is given that a seat can be assigned
  to at most 1 student) and R = X[N-1] - X[0]. We take mid = (L+R)/2. \
  Find the number of students that can be seated if the minimum separation 
  should be mid. This can be done by assigning the first seat to student 1 
  and then assigning seats such that they have separation of at least mid.

If this number is ≥ K, that means this can be a possible answer and so we 
continue binary search on L = mid+1 to R. Otherwise, we need to decrease 
the value of minimum distance to allow more number of students to be seated
 so we continue binary search on L to R = mid-1.

Time Complexity per test case: O(N * log2(X[N-1] - X[0]))*/


/*Minimise Max Diff

Time-Limit: 2 sec Score: 1.00/100
Difficulty : **
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

You are given N distinct points on the number line in a sorted array A. 
You can place at most K more points on the Line (Integer coordinates only). 
You have to make the maximum separation between any two consecutive points 
in the final configuration as minimum as possible. Output this minimal value.  

Note - You can place the points anywhere you like, but you cannot place more 
than one point at the same position on the line. 


Input Format

The first line contains an integer T, the number of test cases (1<=T<=10000).

The first line of each test case contains two space-separated integers N, K, 
2<=N<=10^5, 0<=K<=10^9.

Next line contains N space-separated distinct integers (0<=Ai<=1e9).

Sum of N across all test cases <= 10^6.


Output Format

For each test case output the minimum maximum separation between any two 
consecutive points possible in a new line.


Sample Input 1

5
5 5
1 2 3 4 5
5 0
2 5 7 8 10
3 2
100 200 230
6 5
1 3 5 7 9 11
6 4
1 4 8 13 19 26

Sample Output 1

1
3
34
1
4
 


Note

For the first test case - do not place any additional points or place 
points at 6,7.

For the third test case - place the points at 133, 166. So final 
configuration = [100, 133, 166, 200, 230] and maximum difference 
between two consecutive numbers = 34.

For fourth test case - place the points at 2, 4, 6, 8, 10. So final 
configuration = [1,2,3,4,5,6,7,8,9,10,11] and maximum difference between 
two consecutive numbers = 1.*/

ll n,k,arr[100100];

int check(ll x){
	ll cnt=0;
	
	for(int i=1;i<n;i++){
	    
	    ll dist=arr[i]-arr[i-1];
	    
	    if(dist%x==0){
	        
	        cnt+=(dist/x)-1;
	        
	        
	    }else{
	        
	        
	        cnt+=dist/x;
	    }
	 	
	}
	
	if(cnt<=k)return 1;
	else return 0;
}

void solve(){
	
	cin>>n>>k;
	
	for(ll i=0;i<n;i++){
		
		
		cin>>arr[i];	
	}
	
	ll l,r,mid,ans;
	
	l=1;
	r=arr[n-1]-arr[0];
	
	
	ans=1;
	
	while(l<=r){
	    
	    mid=l+((r-l)>>1);
		
		if(check(mid)){
			
			
			ans=mid;
			r=mid-1;
		}else{

			l=mid+1;
		}	
	}
	
	
	cout<<ans<<nl;

}

/*approach-->
If maximum separation, X is possible by placing at most K more points, 
then it is possible to have maximum separation lesser than X as well. 
That means this is a monotonic function and we can apply binary search.


We would be doing binary search on the minimum answer possible. We take 
the left pointer as L = 1(since it is given that all the numbers have to
 be distinct) and R = A[N-1] - A[0]. We take mid = (L+R)/2. We find the 
 number of points we need to place to have the answer as mid. This can 
 be done by placing the K points in between any two given points (array A) 
 greedily since we want the distance between any two points to be at most mid.
  If there are two points, x and y present in the original array, we will 
  place points x + mid, x + 2*mid, … x + X*mid in between them such that
   x + X*mid < y.

If the number of points we need to place to have the answer as mid is ≤ K, 
that means it could be a possible answer and so we continue binary search 
from L to R = mid-1(since we want to minimize the answer). Otherwise, we need
 to increase the value of the answer and hence we continue binary 
 search from L = mid+1 to R.

Time Complexity per test case: O(N * log2(A[N-1] - A[0]))*/


/*Number & Sum of Digit

Time-Limit: 1 sec Score: 100.00/100
Difficulty : **
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

You are given two integers N and S. Find the number of positive integers X 
less than equal to N, such that the difference between X and the sum of its 
digits (in decimal representation) is not less than S.


Input Format

The first line of input contains one integer T (1 ≤ T ≤ 104) — the number of 
test cases. Then T test cases follow.

The first line of each test case contains two space-separated integer N, S
 where 1<=N<=10^18, 0<=S<=10^18.


Output Format

For each test case print the number of positive integers X in a new line.


Sample Input 1

10
5 4
100 5
20 3
40 19
32 15
69 12
1000000000000000 0
1000000000000000000 10000000
9999999999999 9999999999882
13465751690089037 981448507916936

Sample Output 1

0
91
11
11
13
50
1000000000000000
999999999989999991
10
12484303182172038*/

/*approach*/

ll n,s;
int check(ll x){
	
	ll digit=0;
	ll rem=0;
	
	ll temp=x;
	
	while(x>0){
		rem=x%10;
		
		digit+=rem;
		
		x/=10;
	}
	
if(temp>=s+digit){
	    return 1;
	    
	}
	else{return 0;}
		
}

void solve(){
	
	cin>>n>>s;
	ll l,h,mid,ans;
	
	l=0;
	h=n;
	
	ans=0;
	while(l<=h){
		
		mid=l+((h-l)>>1);
		if(check(mid)){
			
			ans=mid;
			
			h=mid-1;
			
		}else{
			
			l=mid+1;
			
		}
		
	}
	
	if(s==0){cout<<n<<nl;}
else if(ans==0){cout<<ans<<nl;}

   else{cout<<n-ans+1<<nl;}
	
	
	
}

/*approach:
If for a number X, the difference between X and the sum of its digits is not less than S, then for X+1 also difference
will not be less than S. Can you prove it?
If this claim is true then use this monotone property.
Hint 2

Prove: Let F(X) represents the sum of digits of X.

Since F(X+1) is not greater than F(X)+1, 
F(X+1) ≤ F(X)+1
X + F(X+1) ≤ F(X) + 1 + X , adding X both side
X - F(X) ≤ X + 1 - F(X+1)

then X + 1 - F(X+1) ≥ X - F(X). 

and if X - F(X) ≥ S, 

then X + 1 - F(X+1) ≥ S.
Solution Approach

This observation allows us to use binary search to find the minimum number X, such that the difference
between X and the sum of its digits is not less than S. It follows the monotone property that initially 
all numbers less than X have difference less than equal to S. So “NO”  instance holds for numbers less than X. 
Then for all numbers ≥X “YES” instance hold. Using binary search we can find the smallest value X such that the
“YES” instance holds. And if X ≤ N, then all numbers in the segment [X, N] have difference not less than S.*/

/*Good Pairs AZ101

Time-Limit: 2 sec Score: 1.00/100
Difficulty : **
 Memory: 256 MB Accepted Submissions: 100
Description

You are given two arrays A and B, both of size N. A pair is called good 
if i < j and Ai + Aj > Bi + Bj. Find the number of good pairs.


Input Format

The first line of the input contains one integer T - the number of test 
cases. Then T test cases follow.

The first line of each test case contains one integer N - the length o
f the array. 

The second line of each test case contains N space-separated integers.

The third line of each test case contains N space-separated integers.


Output Format

For each test case, print the number of good pairs.


Constraints

1≤ T ≤ 106

1≤ N ≤ 106

1≤ Ai ≤ 109

It is guaranteed that the sum of N over all test cases does not exceed 10^6.


Sample Input 1

3
4
2 3 5 4
2 1 5 6
3
1 4 6
2 3 3
5
5 6 1 1 2
1 9 2 4 1

Sample Output 1

2
2
4

Note

For the first test case, following pairs satisfy the given inequality: 
(2+3) > (2+1) and (3+5) > (1+5)

For the second test case, following pairs satisfy the given inequality: 
(1+6) > (2+3) and (4+6) > (3+3)

For the third test case, following pairs satisfy the given inequality: 
(5+6) > (1+9), (5+1) > (1+2), (5+1) > (1+4) and (5+2) > (1+1)*/



/*approach  
The given inequality is the same as: 
(Ai−Bi)+(Aj−Bj)>0. Let Ci=Ai−Bi. You just need to find pairs such that
 Ci+Cj>0.

Store all the values of Ai - Bi in a vector and sort it. A question that might
 arise is how we can allow ourselves to sort the vector since the constraint 
i
<
j
 is clearly mentioned in the problem. Sorting a vector results in the loss of 
 information about the original indices of the elements, making it difficult 
 to determine the original order of the elements.

When we want to find pairs in a vector such that their sum is greater than 
0
, we can use the fact that addition is a commutative operation, which means that 
the order in which we add the elements doesn't matter. For example, 
2+3is the same as 3+2
.

Now, let's say we have a vector C
 and we want to find pairs 
(i,j)
 such that Ci+Cj>0
. We can sort the vector in non-decreasing order, which means that the smallest 
element will be first and the largest element will be last. Once the vector is
 sorted, we can start with the smallest element and add it to the largest element.
  If the sum is greater than 0
, then we know that all pairs involving the largest element will satisfy the 
condition as well, because any pair with a smaller element than the largest 
element will have a sum that is even smaller than the sum we just computed.

At no point during this process do we need to worry about losing track of the 
original indices of the elements, because we can always interchange the indices 
of any two elements in a pair. For example, if we find a pair 

(i,j) where i>j, we can simply swap 
i and j to get the pair (j,i). This means that even if we sort the vector, 
we can still consider all 
possible pairs and find the ones that satisfy the condition 
Ci+Cj>0.

Store all the values of Ai−Bi
in a vector and sort it. Since Cj>−Ci,
you can use upper_bound for finding the value of such pairs.

Time Complexity per test case: O(NlogN)

*/

 
void solve(){
	ll n;
	cin>>n;
	
	ll arr[n];
	ll brr[n];
	
	ll crr[n];

	for(int i=0;i<n;i++){
	    
	    cin>>arr[i];
	     
	}
	for(ll i=0;i<n;i++){
	    
	    cin>>brr[i];
	    
	    crr[i]=arr[i]-brr[i];
	}
	sort(crr,crr+n);
	
	ll cnt=0;
	for(ll i=0;i<n;i++){
	
	ll x=-crr[i]+1;
	 if(crr[i]<=0){
	   auto it=lower_bound(crr,crr+n,x)-crr;
	     
	     if(it!=n){
	         
	         cnt+=n-it;
	     }    
	     
	 } else{
	     
	     cnt+=n-1-i;
	      
	 }
	 
	}
	
cout<<cnt<<nl;	
}



/*Famous Painter Partition Problem ⭐

Time-Limit: 4 sec Score: 100.00/100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Description

We have to paint n boards of length {A1, A2…An}. There are k painters
 available and each takes 1 unit time to paint 1 unit of the board. 
 The problem is to find the minimum time to get
this job done under the constraints that any painter will only 
paint continuous sections of boards.

Note:

2 painters cannot share a board to paint. A board cannot be painted 
partially by one painter, and partially by another.
A painter will only paint contiguous boards. If a painter paints
 board 1 and 3 but not 2 is invalid.

Input Format

The first line contains a single integer T (1 ≤ T ≤ 100000) - 
the number of test cases.

The first line of each test case contains 2 space-separated integers 
N, K (1 ≤ N ≤ 100000, 1 ≤ K ≤ 100000) - the number of boards and 
the number of painters.

The second line of each test case contains N space-separated integers 
(0 ≤ xi ≤ 10^9) - the length of the boards.

Sum of N across all test cases ≤ 10^6.


Output Format

For each test case print the minimum time required to complete the
 painting in a new line.


Sample Output 1

5
5 2
1 2 3 4 5
5 3
2 5 7 2 5
5 1
1 2 3 4 5
5 5
1 2 3 4 5
5 4
1 7 2 3 5

Sample Input 2

9
7
15
5
7*/

ll  n,k,t[100100];


int check(ll x){
	
	
	ll painter_needed=1;
	ll time_req =0;
	for(ll i=0;i<n;i++){	
		if(t[i]>x) {return 0;
	
	}else if(time_req+t[i]<=x){
		
		time_req+=t[i];	
	}else{
		
		painter_needed++;
		
		time_req=t[i];	
		
	}	
	}
	if(painter_needed>k) {return 0;}
	else{
		return 1;
	}	
}

void solve(){

	cin>>n>>k;
	
	ll sum=0;
	
	for(ll i=0;i<n;i++){
		
		cin>>t[i];
		
		sum+=t[i];
	}
	ll low ,high,ans,mid;
	
	 low=*max_element(t,t+n);
// low=0;
	 high =sum;
	 ans=sum;
	 
	 while(low<=high){
	 	
	 	mid=low+(high-low)/2;
	 	
	 	if(check(mid)){
	 		
	 		ans=mid;
	 		high=mid-1;
	 		
	 	}else{
	 		
	 		low=mid+1;
	 	}	
	 }
	
	cout<<ans<<nl;	
}

/*approach

If K painters are able to paint the boards in time X, then they can
 paint the boards in time less than X as well. That means this is a 
 monotonic function. You can use this to apply binary search.


We would be doing binary search on the minimum time to paint all the
 boards by the K painters. We take the left pointer as L = max(Xi)
  (because 2 painters cannot share a board to paint) and R = Σ(Xi). 
  We take mid = (L+R)/2. Find the number of painters it takes to paint
   all the boards in time ‘mid’. This can be done by assigning the boards
    to the painters in contiguous order and at the same time ensuring 
    that the painters are painting the boards in continuous order.

If the number of painters is ≤ K, that means this is a possible answer 
and we can minimize the time taken to paint the boards, we continue 
binary search on L to R = mid-1. Otherwise, we need to increase the 
time to ensure that only K painters are doing the job, so we continue
 the binary search on L = mid+1 to R.

Time Complexity: O(N * log2(ΣXi))*/


/*Kth Sum Value ⭐

Time-Limit: 3 sec Score: 75.00/100
Difficulty : ****
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

Given two arrays A of size N and B of size M and an integer K. 
Create a new array C of size N*M consisting of A[i]+B[j] for 
1≤i≤N, 1≤j≤M. Find the Kth smallest element in the array C.


Input Format

The first line contains T, the number of test cases (1<=T<=10000).

The first line contains 3 space-separated integer N, M, K where 
1<=N<=10^6, 1<=M<=10^6, 1<=K<=N*M.

Next line contains N space-separated integers (0<=Ai<=1e4).

Next line contains M space-separated integers (0<=Bi<=1e4).

Sum of min(N, M) across all test cases<=10^5.


Output Format

For each test case print the Kth smallest element in the array C.


Sample Input 1

1
3 3 6
1 2 3
4 5 6

Sample Output 1

7

Note

Array C -> [1+4,1+5,1+6,2+4,2+5,2+6,3+4,3+5,3+6] -> 
[5,6,7,6,7,8,7,8,9]
Array C after sorting - [5,6,6,7,7,7,8,8,9]
6th element is 7.*/

ll n,m,k;
vector<int>arr,brr;

ll check(ll x){
    
    ll cnt=0;
   for(int i=0;i<n;i++){
       cnt+=upper_bound(brr.begin(),brr.end(),x-arr[i])-brr.begin();
     
   }
   
   return cnt>=k;
    
}





void solve(){
	

	
	cin>>n>>m>>k;
	
	arr.resize(n);
	brr.resize(m);
	
	for(int i=0;i<n;i++){
	    cin>>arr[i];
	}
	
		for(int i=0;i<m;i++){
	    cin>>brr[i];
	}
	if(n>m){
	    swap(n,m);
	    swap(arr,brr);
	}
	sort(arr.begin(),arr.end());
	sort(brr.begin(),brr.end());
	
	ll low=arr[0]+brr[0];
	ll high=arr.back()+brr.back();
	ll ans=-1;
	while(low<=high){
	    
	    ll mid=low+(high-low)/2;
	    
	    if(check(mid)){
	        // 0's followed by 1's
	        
	        ans=mid;
	        high=mid-1;
	        
	    }else{
	        low=mid+1;
	    }  
	}
	cout<<ans<<nl;
	
}


/*Consecutive one⭐

Time-Limit: 2 sec Score: 100.00/100
Difficulty : **
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

Given a binary array of length N. The score of an array is the length 
of the longest continuous subsegment consisting of only one.

Find the maximum score possible if you can change at most K elements
 of the array.


Input Format

The first line contains an integer T, the number of test cases.
The first line of each test case contains two space-separated 
integer N, K where 
The next line contains N space-separated integers which are 
either 0 or 1.


Output Format

For each test case print the maximum score possible if you can change 
at most K elements of the array in a new line.


Constraints

1 ≤ T ≤ 104
1 ≤ N ≤ 105
0 ≤ K ≤ N
Sum of N across all test cases ≤ 106.


Sample Input 1

5
10 2
1 0 1 1 0 1 1 0 0 1
10 1
1 1 0 1 0 0 0 1 0 0
10 3
1 0 0 1 1 0 1 1 0 1
10 3
1 1 1 0 0 0 1 1 1 1
10 3
1 1 0 0 1 1 0 0 1 1

Sample Output 1

7
4
8
10
7
 */

ll n,k, arr[100100];


void solve(){
	
	cin>>n>>k;
	
	
	for(ll i=0;i<n;i++) cin>>arr[i];
		
		
		// define head , tail, and answer variable
		
		
		ll tail,head, ans;
	
	head=-1; tail=0;ans=0;
	
	//keep window data structure//
	
	ll cnt0=0;
	
	while(tail<n){
		
		// push head as far as possible//
		
		while(head+1<n && //can_we_talke(tail,head+1)
			               cnt0+(arr[head+1]==0?1:0)<=k){
			
			head++;
			
			
			if(arr[head]==0) cnt0++;
			
		}
		
		ans=max(ans,head-tail+1);
		
		
		
		//push tail one step//
		if(head<tail){
			
			tail++;
			
			head=tail-1;
		}else{
			
			if(arr[tail]==0) cnt0--;
			tail++;	
		}
		
	}
	cout<<ans<<nl;
	
	
}

/*Maximise the fraction⭐

Time-Limit: 4 sec Score: 1.00/100
Difficulty : ***
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

Given two arrays A and B of size N and an integer K. You have to 
select K indexes i1,i2,i3....iK such that 

(A[i1]+A[i2]+A[i3]+……+A[iK]) / (B[i1]+B[i2]+B[i3]+……+B[iK]) is maximum.


Input Format

The first line contains T, the number of test cases (1<=T<=10000).

The first line contains an integer N, K where 1<=N<=10^4, 1<=K<=N.

Next line contains N space-separated integers (1<=Ai<=1e4).

Next line contains N space-separated integers (1<=Bi<=1e4).

Sum of N across all test cases<=10^5.


Output Format

For each test case print the maximum possible value of 
(A[i1]+A[i2]+A[i3]+……+A[iK]) / (B[i1]+B[i2]+B[i3]+……+B[iK]).
 You have to print the result round off to 6 decimal places.


Sample Input 1

3
3 2
10 9 7
3 5 4
8 3
4 4 2 1 5 3 2 5
2 2 2 5 3 5 2 3
1 1
1 
1

Sample Output 1

2.428571
1.857143
1.000000

Note

1st test case:
Select index → [1,3], result = 17/7.*/

void solve(){
	
	ll n,k;
	cin>>n>>k;
	
	ld arr[n],brr[n];
	ld sum=0;
	for(ll i=0;i<n;i++){
	    
	    cin>>arr[i];
	    sum+=arr[i];
	}
	for(ll i=0;i<n;i++){
	    
	    cin>>brr[i];
	}
	
	ld low=0;
	ld high=sum;
	ld ans;
	ld mid;
	
	while(abs(low-high)>1e-10){
	    
	    mid=(low+high)/2.0;
	    priority_queue<ld,vector<ld>,greater<ld>>pq;
	    
	    for(int i=0;i<n;i++){
	        
	        pq.push(arr[i]-mid*brr[i]);
	        
	        if(pq.size()>k)pq.pop();
	    }
	    
	    
	    ld s=0.0;
	    while(pq.size()){
	        
	        s+=pq.top();
	        pq.pop();
	    }
	    
	    if(s>=0.0){
	        
	        ans=mid;
	        low=mid;
	    }else{
	        
	        high=mid;
	    }
	     
	}
	
	cout<<fixed<<setprecision(6)<<ans<<nl;
}

/*approach

Equate (A[i1]+A[i2]+A[i3]+……+A[iK]) / (B[i1]+B[i2]+B[i3]+……+B[iK]) to X.
 If the value of X is possible, then the maximum value would be ≥ X. 
 Otherwise it would be < X. This is a monotonic function and hence we 
 can use binary search in this problem.

(A[i1]+A[i2]+A[i3]+……+A[iK]) / (B[i1]+B[i2]+B[i3]+……+B[iK]) = X

(A[i1]+A[i2]+A[i3]+……+A[iK]) - X*(B[i1]+B[i2]+B[i3]+……+B[iK]) = 0

(A[i1] - XB[i1]) + (A[i2] - XB[i2]) + …… + (A[iK] - X*B[iK]) = 0

So, we need to select K indices such that the above condition must be satisfied.


We would be doing binary search on the maximum possible value of
 (A[i1]+A[i2]+A[i3]+……+A[iK]) / (B[i1]+B[i2]+B[i3]+……+B[iK]). Let’s

We take the left pointer as L = 0 and the right pointer as R = 108. 
We take mid = (L+R)/2. We then check if it is possible to have mid as
 a possible value of the given function. To do this, we take the maximum
  K values of (A[i] - mid*B[i]) by using a priority queue. If the sum of 
  these values is ≥ 0, then it might be possible to equate the sum to 0. 
  If mid is a possible value, the maximum possible value can be ≥ mid and
   we continue binary search on L = mid to R. Otherwise, the maximum possible 
   value would be < mid, so we continue binary search on L to R = mid.

Time Complexity per test case: O(N * log2(ΣAi) * log2K)
   */


 
/*Color Balls ⭐

Time-Limit: 2 sec Score: 1.00/100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

You are given N balls and an integer K. The color of each ball is given in 
an array A. A basket is filled if it contains at least K balls of different 
colors. Find the maximum number of filled baskets you can get if you 
optimally put the balls in the baskets.


Input Format

The first line contains T, the number of test cases (1<=T<=100000).

The first line contains three space-separated integers N, K where 
1<=N<=10^5, 1<=K<=N.

Next line contains N space-separated integers (0<=Ai<=1e9).

Sum of N across all test cases <=10^6.


Output Format

For each test case output the maximum number of filled baskets 
in a new line. 


Sample Input 1

3
5 5
1 2 3 4 5
5 2
1 2 3 4 5
6 3
1 2 2 1 3 3

Sample Output 1

1
2
2

Note

1st test case:
1st basket -> {1,2,3,4,5}

2nd test case:
1st basket -> {1,2,3}
2nd basket -> {4,5}

3rd test case:
1st basket -> {1,2,3}
2nd basket -> {1,2,3} */

typedef long long ll;
const int N = 100001;
ll n, k;
ll arr[N];
map<ll, ll> freq;
bool check(ll minVal)
{
    ll totalUsefulBalls = 0;
    for (auto v : freq)
    {
        totalUsefulBalls += min(v.second, minVal);
    }
    return totalUsefulBalls >= k * minVal;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll testcases;
    cin >> testcases;
    while (testcases--)
    {
        cin >> n >> k;
        ll sum = 0;
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
            freq[arr[i]]++;
        }
        ll low = 0, high = n;
        ll ans = low;
        while (low <= high)
        {
            ll mid = (low + high) / 2;
            if (check(mid))
                ans = mid, low = mid + 1;
            else
                high = mid - 1;
        }
        cout << ans << "\n";
        freq.clear();
    }
}

//approach//

/*If we can fill X number of baskets with at least K
balls of different colors, then the maximum possible baskets would be ≥X.
Otherwise, possible baskets would be <X .This is a monotonic function 
and hence we can use binary search in this problem.


The first step in this solution is to use binary search to find the 
maximum number of filled baskets. We start with L=0
and R=N/K since each basket must have at least K balls. We then 
calculate the midpoint, mid=L+R2
, and check if it is possible to fill mid baskets with at least K
 distinct colors. To do this, we use a frequency hashmap to count 
 the number of balls of each color. For each color, we cannot use more 
 than mid balls, since we want distinct balls in the baskets. If it is
  possible to fill mid baskets, then we update our left pointer to mid+1 
  and continue the binary search on the right half of the array. 
  Otherwise, the maximum number of filled baskets must be less than mid,
   so we update our right pointer to mid-1 and continue the
 binary search on the left half of the array. We repeat this process until
 L>R, at which point we return the maximum number of filled baskets.


Calculate the sum of min(freq[color],mid).

If the 
sum≥mid×K then there exists a way to fill “mid” baskets.

The goal of the construction step is to find a way to fill the baskets 
with at least K distinct colors while making sure that no basket has the 
same color ball. To do this, we can use a 2-D grid of size midK where 
each row represents a basket, and each column represents a color.

Starting from the first column, we fill each basket with the same color
 ball until we have used up all of the balls of that color or until we 
 have reached the maximum number of balls allowed in each basket, which 
 is mid. Once we have filled all the baskets with the same color ball for
  the first column, we move on to the next column and repeat the process.

We continue this process for all the columns until we have filled each 
basket with at least K distinct colors. At this point, we have constructed
 a solution that satisfies the problem constraints, since no basket has the
  same color ball, and each basket has at least K distinct colors.

The time complexity of this algorithm is 
O(Nlog2N)
 per test case due to the binary search step.

*/


/*Number of Subarray with at most K distinct ⭐

Time-Limit: 1 sec Score: 100.00/100
Difficulty : **
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

Given an array of N integers, find the number of 
subarrays with at most K distinct elements.


Input Format

The first line contains T, the number of test cases (1<=T<=10).

The first line contains two space-separated integers N, K where
 1<=N<=10^5, 0<=K<=10^5.

Next line contains N space-separated integers (0<=Ai<=1e6).


Output Format

For each test case print the number of subarrays with at most K
 distinct elements in a newline.


Sample Input 1

5
3 2
1 2 3
3 2
3 2 2
5 0
2 1 0 4 0
7 3
1 2 1 0 1 0 2
10 5
1 0 7 1 10 2 4 10 1 3

Sample Output 1

5
6
0
28
46 */


ll n,k,arr[100100];


map<int,int>freq;

ll distinct=0;

int check(ll x){
	
	if((distinct+(freq[x]==0?1:0))<=k){
		 
		 return 1;
	}else{
		return 0;
	}
	
	
}

void insert_head(ll x){
	
	if(freq[x]==0){distinct++;}
		freq[x]++;

	
	
}

void remove_tail(ll x){
	
	freq[x]--;
	
	if(freq[x]==0) distinct--;
	
	
}



void solve(){
	
	cin>>n>>k;
	for(ll i=0;i<n;i++){
		
		cin>>arr[i];
	}
	ll head,tail,ans;
	
	head=-1;
	tail=0;ans=0;
	distinct=0;
	freq.clear();
	
	
	while(tail<n){
		
		//push head as far as possible
		while(head+1<n&& check(arr[head+1])){
			
			head++;
			
			insert_head(arr[head]);
		}
		
		
		ans+=(head-tail+1);
		
		
		
		if(head<tail){
			
			tail++;
			head=tail-1;
		}else{
			
		
			
			remove_tail(arr[tail]);
			
			tail++;
		}
	
		
	}
	
	
	cout<<ans<<nl;
}

 
 /*approach
 If one of our subarray is between [L,R] we can for surely say that 
 for the subarray starting from L+1 our desired subarray will be R' 
 such that R' >= R. This allows us to apply the 2 pointer approach 
 for this problem.


We use two pointers, start and current, to keep track of the window.
 We maintain an array freq to keep track of the frequency of each
  element in the current window.

For each subarray check using a frequency array how many distinct
 elements are there at a particular instant. Whenever we exceed K 
 we make that as our right pointer boundary.*/


/*Number of Subarray with sum at most K ⭐

Time-Limit: 1 sec Score: 100.00/100
Difficulty : **
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

Given an array of N integers, find the number of subarrays with a 
sum less than equal to K.


Input Format

The first line contains T, the number of test cases (1<=T<=10).

The first line of each test case contains two space-separated 
integers N, K where 1<=N<=10^5, 0<=K<=10^9.

Next line contains N space-separated integers (0<=Ai<=1e4).


Output Format

For each test case print the number of subarrays with a sum 
less than K in a newline.


Sample Input 1

5
3 5
1 2 3
3 6
3 2 1
5 0
2 1 0 4 5
7 6
1 2 3 0 1 5 2
10 10
1 0 1 1 10 2 3 7 5 9

Sample Output 1

5
6
1
18
18
 


Note

For the first test case, number of subarray with sum
 <=5 -> (1),(1,2),(2),(2,3),(3)

For the second test case, all the subarrays have sum <=6.*/

ll n,k,arr[100100];
 ll sum=0;

int check(ll x){
	
	if((sum+x)<=k){
		
		return 1;
	}else{
		return 0;
	}	
}

void insert_head(ll x){
	
	sum+=x;
	
}

void remove_tail(ll x){
	
	sum-=x;
}

void solve(){
	
	cin>>n>>k;
	
	for(ll i=0;i<n;i++)cin>>arr[i];
		
		
		ll head,tail,ans;
	
	head=-1;tail=0;ans=0;
	
	while(tail<n){
		
		while(head+1<n && check(arr[head+1])){
			
			head++;
			
			insert_head(arr[head]);
			
		}
		
		ans+=(head-tail+1);
	if(head<tail){
		
		tail++;
		head=tail-1;
	}else{
		
		remove_tail(arr[tail]);
		tail++;	
	}
}	cout<<ans<<nl;
	
}	

/*Longest Distinct Subarray AZ101

Time-Limit: 1 sec Score: 100.00/100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Description

You are given an array of N integers. Find the longest subarray
 with distinct characters.


Input Format

The first line of the input contains one integer T - the number 
of test cases. Then T test cases follow.

The first line of each test case contains one integer N - 
the length of the array. 

The second line of each test case contains N 
space-separated integers.


Output Format

For each test case, print the longest subarray 
with distinct characters.


Constraints

1≤ T ≤ 105

1≤ N ≤ 105

1≤ Ai ≤ 109

It is guaranteed that the sum of N over all test
 cases does not exceed 105.


Sample Input 1

3
5
1 2 2 1 2
4
3 3 3 3
5
1 3 2 4 1

Sample Output 1

2
1
4

Sample Input 2

1
7                   
1 2 3 1 4 5 6

Sample Output 2

6

Note

For the first test case: 1 2 2 1 2

For the second test case: 3 3 3 3

For the third test case: 1 3 2 4 1*/

ll n,k,arr[100100];


map<int,int>freq;

ll distinct=0;

int check(ll x){
	
	if(freq[x]==0){
		 
		 return 1;
	}else{
		return 0;
	}
	
	
}

void insert_head(ll x){
	
//	if(freq[x]==0){distinct++;}
		freq[x]++;	
	
}

void remove_tail(ll x){
	
	freq[x]--;
	
//	if(freq[x]==0) distinct--;	
}



void solve(){
	
	cin>>n;
	
	
	for(ll i=0;i<n;i++){
		
		cin>>arr[i];
	}
	
	
	ll head,tail,ans;
	
	head=-1;
	tail=0;ans=0;
	
	
// 	distinct=0;
// 	freq.clear();
	
	
	while(tail<n){
		
		//push head as far as possible
		while(head+1<n&& check(arr[head+1])){
			
			head++;
			
			insert_head(arr[head]);
		}
		
		
		ans=max(ans,head-tail+1);
		
		
		
		if(head<tail){
			
			tail++;
			head=tail-1;
		}else{	
			remove_tail(arr[tail]);
			
			tail++;
		}
		
	}
	cout<<ans<<nl;
	
}


/*3 Sum ⭐

Time-Limit: 2 sec Score: 1.00/100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Relevant For:**
Description

Given an array A of N integers and an integer target, 
find three integers in A such that the sum is closest to the 
target (absolute value of (sum-target) is minimum). Print the
 minimum absolute value of (sum-target). You cannot select an 
 index more than one. All three indexes should be distinct.


Input Format

The first line contains T, the number of test cases (1<=T<=100).

The first line contains two space-separated integers N, target 
where 3<=N<=10^3, -1e18<=target<=1e18.

Next line contains N space-separated integers (-1e9<=Ai<=1e9).

The Sum of N across all test cases ≤ 10^4.


Output Format

For each test case print the minimum absolute value of (sum-target).


Sample Input 1

1
5 3
1 2 3 4 5

Sample Output 1

3*/

typedef long long ll;
signed main()
{
   ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
   int testcases;
   cin>>testcases;
   while(testcases--){
       ll n,target;
       cin>>n>>target;
       vector< ll > arr(n);
       for(int i=0;i<n;i++)
           cin>>arr[i];
       sort(arr.begin(),arr.end());
       ll best = arr[0]+arr[1]+arr[2];
       for(ll i=1;i<(ll)arr.size()-1;i++){
           ll lo = 0;
           ll hi = (ll)arr.size()-1;
           while(1){
               if(abs(arr[lo]+arr[i]+arr[hi]-target)<abs(best-target)){
                   best=arr[lo]+arr[i]+arr[hi];
               }
               if(arr[lo]+arr[i]+arr[hi]>target)hi--;
               else lo++;
               if(lo==i||hi==i)break;
           }
       }
       cout<<abs(best-target)<<"\n";
   }
}

/*approach

Sorting the given array would help us use the two-pointer technique.


We iterate through the array and fix the first number of the array
 (index, K), and then use the two-pointer technique on the array to 
 its right side. We take the left pointer as L = K + 1 and the right
  pointer as R = size(A) - 1. This would help us ensure that all the 
  indexes taken are distinct. Find the sum of the three integers and 
  take the minimum absolute difference between all such sums and target. 
  If the sum < target, decreasing the value of R would only decrease the 
  sum and hence increase the absolute difference, so we increase the value 
  of L. Similarly if sum > target, we decrease the value of R. Continue 
  doing the two-pointer until L < R and find the minimum possible absolute
   difference of sum and target.*/



/*Shortest Subarray ⭐

Time-Limit: 1 sec Score: 1.00/100
Difficulty : **
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

Given an array of N integers, find the length of the smallest
 sub-array that contains all the distinct elements of the array.


Input Format

The first line contains T, the number of test cases (1<=T<=10).

The first line contains an integer N, 1<=N<=10^5.

Next line contains N space-separated integers (0<=Ai<=1e5).

 


Output Format

For each test case print length of the smallest sub-array that 
contains all the distinct elements of array in a newline.


Sample Input 1

6
5
1 1 3 2 3
5
1 2 3 4 5
6
1 2 2 3 3 4
6
1 2 1 3 2 4
5
1 1 1 1 1
1
1

Sample Output 1

3
5
6
4
1
1
 


Note

For first test case → smallest subarray -> (1,3,2).

For second test case → smallest subarray -> (1,2,3,4,5).

For third test case → smallest subarray -> (1 2 2 3 3 4).*/

typedef long long ll;
signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    ll testcases;
    cin>>testcases;
    while(testcases--){
        ll n;
        cin>>n;
        ll arr[n];
        ll freq[100001] = {0};
        for(ll i=0;i<n;i++)cin>>arr[i],freq[arr[i]]++;
        ll distinctElement = 0;
        for(ll i=0;i<=100000;i++){
            distinctElement+=(freq[i]>0);
            freq[i] = 0;
        }
        ll ans = n;
        ll start = 0;
        ll current = 0;
        ll currSum = 0;
        while(current<n){
            freq[arr[current]]++;
            if(freq[arr[current]]==1)
                currSum++;
            while(start<=current and currSum==distinctElement){
                ans = min(ans,current-start+1);
                if(freq[arr[start]]==1)
                    currSum--;
                freq[arr[start]]--;
                start++;
            }
            current++;
        }
        cout<<ans<<"\n";
    }
}

/*First, find the number of distinct elements in the entire subarray 
and then find the shortest subarray with that number of distinct elements.


If a subarray from L to R has K number of distinct elements, it is possible
 that a shorter subarray from X to R (L < X) also has K number of distinct elements.


We would be using two pointers to solve this problem. We start both the pointers 
from the beginning i.e. L = 0 and R = 0. We would be maintaining a frequency count
array for the elements in the current subarray. To find the number of distinct 
elements in the current subarray, when increasing the frequency, if we get
 it as 1, that means a new element has been added to the current subarray, 
  the number of distinct elements in the subarray increases, and when 
  decreasing the frequency, if we get it as 0, that means the element is
   no more present in the subarray and the number of distinct elements 
   in the subarray decreases.

We start from the beginning of the array and keep increasing the right
 pointer, R till the number of distinct elements is less than or equal
  to K. If the subarray from L to R has a number of distinct elements = K,
   it is possible that a shorter subarray from X to R (L < X) also has K
    number of distinct elements. Find the length of this subarray, i.e.
     the penalty, and take the minimum of all such penalties. When the 
     number of distinct elements becomes equal to K, we start moving the
      left pointer, until the number of distinct elements is less than K.
       We continue doing this till R < N.

Time Complexity per test case: O(N)


*/

/*Remove K integers (unsolved)(day5 std)

Time-Limit: 1 sec Score: 0.00/100
Difficulty : ****
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

Given an array N integers in nondecreasing order. Remove K integers such 
that the maximum difference between two consecutive elements is minimized.


Input Format

The first line contains T, the number of test cases (1<=T<=10).

The first line of each test case contains two integers N and K, 
3<=N<=3*10^5, 1<=K<=N-2.

The second line of each test case contains N space-separated integers,
 -1e9<=A[I]<=1e9.


Output Format

For each test case print a single integer, representing the minimum-maximum
 difference between two consecutive elements after removing K integers in a new line.


Sample Input 1

2
5 1
1 5 6 8 9
5 2
1 5 6 7 1000

Sample Output 1

2
1

Note

For the first test case → remove 1.

For the second test case → remove 1 and 1000.*/

/*Distinct Integers(day5 std)

Time-Limit: 2 sec Score: 0.00/100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

Given an array A of N integers and an integer K, a subarray of A 
is good if the number of distinct integers present in the subarray 
is exactly K. Find the number of good subarrays.


Input Format

The first line of the input contains a single integer T denoting 
the number of test cases, (1<=T<=100000).

The first line of each test case contains two space-separated 
integers N, K (1<=N<=100000), (1<=K<=10^6).

The second line contains N space-separated integers A1,A2,…,AN, (0<=Ai<=10^6).

Sum of N overall test case <=10^6.


Output Format

For each test case output in a new line the number of good subarrays.


Sample Input 1

5
5 2
1 2 3 4 5
6 3
1 2 3 2 4 2
10 4
1 2 2 3 2 4 1 3 1 2
10 5
1 2 3 4 1 2 3 4 1 2
10 5
1 2 3 4 1 5 2 5 2 6 

Sample Output 1

4
6
21
0
12
 


Note

For the 1st test case, good subarrays are - {1,2},{2,3},{3,4},{4,5}

For the 2nd test case, good subarrays are - {1,2,3}, {1,2,3,2}, 
{2,3,2,4}, {2,3,2,4,2}, {3,2,4}, {3,2,4,2}.*/



/*K Odd Number (day 5 achiver)

Time-Limit: 2 sec Score: 0.00/100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

Given an array of N integers, find a subarray with at most K odd numbers 
and the total sum is maximum but not more than D. If no such subarray 
exists print "IMPOSSIBLE" without double-quotes.


Input Format

The first line contains T, the number of test cases (1<=T<=10).

The first line contains two space separated integers N, K, D
 where 1<=N<=10^5,  0<=K<=10^5, -1e9<=D<=1e9.

Next line contains N space-separated integers (-1e4<=Ai<=1e4).


Output Format

For each test case print the sum of subarray with at most K odd 
numbers and the total sum is maximum, but not more than D in a 
newline. If no subarray is possible then print "IMPOSSIBLE" without double-quotes.


Sample Input 1

6
3 2 5
1 2 3
3 1 2
-3 -1 -3
5 2 8
-1 2 3 4 -5
7 0 -2
1 -4 1 0 1 0 2
10 3 14
1 0 -7 1 -10 4 -2 10 -1 3
3 0 1000
-101 201 -301

Sample Output 1

5
-1
8
-4
14
IMPOSSIBLE

Note

For the first test case, the optimal subarray - (2,3) → 
number of odd number is 1<=2 and sum is 5<=5.

For the second test case, the optimal subarray - (-1) → 
number of odd number is 1<=2 and sum is -1<=2.

For the third test case, the optimal subarray - (-1,2,3,4) → 
number of odd number is 2<=2 and sum is 8<=8.

For the fourth test case, the optimal subarray - (-4) → number 
of odd number is 0<=0 and sum is -4<=-2.*/


/*Median of Subarray Sum

Time-Limit: 2 sec Score: 0.00/100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

Given an array of N integers A. The score of a subarray is the sum 
of all integers in the subarray. Mr.X calculated the score of all N*(N+1))/2 
subarray. Mr.X wants you to find the median of the array containing the 
score of all the subarray.

 

Note: The median of a sequence is the value that is in the middle when the
 sequence is sorted. If the length of the sequence is even, there are two 
 values in the middle and the median is the smaller of these 
 values (or either when they are equal).


Input Format

The first line contains an integer T, the number of test cases (1<=T<=10000).

The first line of each test case contains an integer N where (1<=N<=10^5).

Next line contains N space-separated integers (0<=Ai<=1e9).

Sum of N across all test cases ≤ 10^6.


Output Format

For each test case output the median of the array containing the 
score of all the subarray in a new line.


Sample Input 1

5
3
1 2 3
1
5
2
1 5
10
1 2 2 3 3 4 5 4 6 7
15
100 222 333 511 555 232 444 555 777 888 999 1000 1112 12345 123456

Sample Output 1

3
5
5
13
3629
 


Note

1st test case:
Subarray and score:
1 -> 1
1,2 -> 3
1,2,3 -> 6
2 -> 2
2,3 -> 5
3 -> 3
New array = {1,2,3,3,5,6}, median = 3

2nd test case:
Subarray and Score:
5 -> 5
New array = {5}, median = 5

3rd test case:
Subarray and score
1 -> 1
1,5 -> 5
5 -> 5
New array = {1,5,5}, median = 5.*/





/*Count Unique Char in Substrings ⭐

Time-Limit: 2 sec Score: 0.00/100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

Given a string S consisting of the lowercase character of length N.
 Score of a string is the number of unique characters present in the 
 string( characters which are only present once in the string). 
 Like score of "character" is 3 {h,t,e}.

Find the sum of the score of all substring of S.


Input Format

The first line contains T, the number of test cases (1<=T<=10).

The first line of each test case contains an integers N, size
 of the string, 1<=N<=10^5.

The second line of each test case contains a string S of length N.


Output Format

For each test case print the sum of the score of all 
substring of S in a newline.


Sample Input 1

5
2
ac
3
aac
5
abode
5
aaaaa
10
jdnbfjdhzw

Sample Output 1

4
6
35
5
194

Note

For the 1st test case:
Substring and score = ("a",1), ("c",1) ("ac",2).
Total score = 4

For the 2nd test case:
Substring and score = ("a",1), ("aa",0), ("aac",1),
 ("a",1), ("ac",2), ("c",1).
Total score = 6*/



/*Count Distinct Char in Substrings ⭐

Time-Limit: 2 sec Score: 0.00/100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

Given a string S consisting of the lowercase character of length N.
 Score of a string is the number of distinct characters present in 
 the string. Like the score of "character" is 6.

Find the sum of the score of all substring of S.


Input Format

The first line contains T, the number of test cases (1<=T<=10).

The first line of each test case contains an integers N, size
 of the string, 1<=N<=10^5.

The second line of each test case contains a string S of length N.


Output Format

For each test case print the sum of the score of all substring 
of S in a newline.


Sample Input 1

5
2
ac
3
aac
5
abode
5
aaaaa
10
jdnbfjdhzw

Sample Output 1

4
8
35
15
207

Note

For the 1st test case:
Substring and score = ("a",1), ("c",1) ("ac",2).
Total score = 4

For the 2nd test case:
Substring and score = ("a",1), ("aa",1), ("aac",2), 
("a",1), ("ac",2), ("c",1).
Total score = 8*/
