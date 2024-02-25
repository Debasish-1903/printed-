/*Pattern Problem 1 AZ101

Time-Limit: 1 sec Score: 100.00/100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Description

Using characters: . (dot) and * (asterisk) print a grid-like pattern
 as shown in the sample test case.

Input Format

The first line of the input contains one integer T - the number 
of test cases. Then T test cases follow.

The first line of each test case contains two 
space-separated integers N, M.


Output Format

For each test case, print the required pattern.

Constraints

1≤ T ≤ 104

1≤ N, M ≤ 1000

It is guaranteed that the sum of N*M for all test
 cases does not exceed 106.

Sample Input 1

3
3 4
4 2
3 3

Sample Output 1

*************
*..*..*..*..*
*..*..*..*..*
*************
*..*..*..*..*
*..*..*..*..*
*************
*..*..*..*..*
*..*..*..*..*
*************
*******
*..*..*
*..*..*
*******
*..*..*
*..*..*
*******
*..*..*
*..*..*
*******
*..*..*
*..*..*
*******
**********
*..*..*..*
*..*..*..*
**********
*..*..*..*
*..*..*..*
**********
*..*..*..*
*..*..*..*
********** */

int main() {
    IOS
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < 3*n+1; ++i) {
            for (int j = 0; j < 3*m + 1; ++j) {
                if(i%3==0 || j%3 == 0) cout << "*";
                else cout << ".";
            }
            cout << "\n";
        }
    }
    return 0;
}

/*Odd One Out AZ101

Time-Limit: 1 sec Score: 100.00/100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Description

You are given an array of N integers. The frequency of exactly 
one integer is odd. Find that integer.


Input Format

The first line of the input contains one integer T - the 
number of test cases. Then T test cases follow.

The first line of each test case contains one integer N - 
the length of the array. 

The second line of each test case contains N 
space-separated integers.

Output Format

For each test case, print the integer with odd frequency.

Constraints

1≤ T ≤ 106

1≤ N ≤ 106  (N is odd)

-109≤ Ai ≤ 109

It is guaranteed that the sum of N over all test
 cases does not exceed 106

Sample Input 1

3
5
2 5 5 7 2
3
2 1 2
5
0 1 2 1 0

Sample Output 1

7
1
2*/


int main() {
    IOS
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            ans ^= x;
        }
        cout << ans << "\n";
    }
    return 0;
    
    
    
    /*
    
    IO Problem AZ101

Time-Limit: 1 sec Score: 1.00/100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Description

You are given an integer N and a decimal number M. 
M can be represented as Y.Z where .
 is the decimal point and N as X. You have to find (Z+X).(Y+X)


Input Format

The first line of the input contains one integer T - 
the number of test cases. Then T test cases follow.

The first line of each test case contains one integer
 N and a decimal number M.


Output Format

For each test case, print the value of (Z+X).(Y+X)


Constraints

1≤ T ≤ 10^6

1≤ N, M ≤ 10^9


Sample Input 1

3
14 1.2
3 4.5
31 0.143

Sample Output 1

16.15
8.7
174.31

Note

For the first test case, X = 14, Y = 1, Z = 2. So ans = 
(2+14).(1+14) = 16.15

For the second test case, X = 3, Y = 4, Z = 5. So ans =
 (5+3).(4+3) = 8.7

For the third test case, X = 31, Y = 0, Z = 143. So ans =
 (143+31).(0+31) = 174.31*/
    
    void solve()
{
    lli n;
    cin >> n;
    string s;
    cin >> s;
    string s1, s2;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '.')
        {
            swap(s1, s2);
            continue;
        }
        s1 += s[i];
    }
    cout << stoi(s1) + n << "." << stoi(s2) + n << endl;
}



/*Sum of Digits

Time-Limit: 1 sec Score: 1.00/100
Difficulty : *
 Memory: 256 MB Accepted Submissions: 100
Description

You are given an integer N with no more than 10^5 digits.
 You have to find the sum of its digits.


Input Format

The first line of the input contains one integer T - 
the number of test cases. Then T test cases follow.

The first line of each test case contains one integer N.


Output Format

For each test case, print the sum of digits on N on a new line.


Constraints

1≤ T ≤ 106

1≤ Number of digits in N ≤ 106

It is guaranteed that the sum of the number of digits in N over
 all the test cases does not exceed 106.


Sample Input 1

3
12
1561
53453451234567876545676540909890989890987987567654567654567656765678765678765

Sample Output 1

3
13
443

Note

For the first test case, 1+2 = 3

For the second test case, 1+5+6+1 = 13*/



int main() {
    IOS
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int ans = 0;
        for (int i = 0; i < s.size(); ++i) {
            ans += (s[i] - '0');
        }
        cout << ans << "\n";
    }
    return 0;
}



/*The Missing Number AZ101

Time-Limit: 1 sec Score: 100.00/100
Difficulty : *
 Memory: 256 MB Accepted Submissions: 100
Description

You are given an array A. One random element is removed from
 A to form array B and one random element is 
removed from B to form array C. You have to find the missing 
element in B and the missing element in C.


Input Format

The first line of the input contains one integer T - the number of test cases.
 Then T test cases follow.

The first line of each test case contains one integer N - the length of the array. 

The second line of each test case contains N space-separated integers - array A.

The third line of each test case contains (N-1) space-separated integers - array B.

The fourth line of each test case contains (N-2) space-separated integers - array C.


Output Format

For each test case, print the missing element in B and the missing element in C.


Constraints

1 ≤ T ≤ 10^6

2 ≤ N ≤ 10^6

It is guaranteed that the sum of N over all the test cases does not exceed 106.

0 ≤ Ai ≤ 10^9


Sample Input 1

3
4
1 3 5 2
5 1 3
5 1
5
1 3 5 1 0
3 1 1 5
1 1 5
3
1 2 3
3 1
1

Sample Output 1

2 3
0 3
2 3*/


void solve(){

ll n ;
cin>>n;

multiset<ll>a,b,c;

for(ll i=0;i<n;i++){
    
    ll x;
    cin>>x;
    a.insert(x);  
}
for(ll i=0;i<n-1;i++){
    
    ll x;
    cin>>x;
    b.insert(x);
    
}
for(ll i=0;i<n-2;i++){
    
    ll x;
    cin>>x;
    c.insert(x);
    
}
for(auto it:a){
    
    if(!b.empty()){
        
        if(b.find(it)==b.end()){
            
            cout<<it<<" ";
        }  
    } 
}

for(auto it:b){
    
    if(!c.empty()){
        
        if(c.find(it)==c.end()){
            
            cout<<it<<nl;
        }  
    }
}
 }
 
 /*editorial code */
 int main() {
    IOS
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        long long int s1 = 0, s2 = 0, s3 = 0;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            s1 += x;
        }
        for (int i = 0; i < n-1; ++i) {
            int x;
            cin >> x;
            s2 += x;
        }
        for (int i = 0; i < n-2; ++i) {
            int x;
            cin >> x;
            s3 += x;
        }
        cout<< s1 - s2 << " " << s2 - s3 << "\n";
    }
    return 0;
}

/*Grading System AZ101

Time-Limit: 1 sec Score: 100.00/100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Description

You are given the marks of a student in mid-term, final-term and
 the make-up examinations. If the student does not 
attend an exam, marks are assigned as -1. You have to find the 
grade of the student according to the following guidelines:

If the student does not take the mid-term or the final-term exam,
 grade is F
If the total score in mid-term and final-term is greater than or 
equal to 80, grade is A.
If the total score in mid-term and final-term is greater than or
 equal to 65 and less than 80, grade is B.
If the total score in mid-term and final-term is greater than or
 equal to 50 and less than 65, grade is C.
If the total score in mid-term and final-term is greater than or 
equal to 30 and less than 50, grade is D. However, if the
 score of the make-up examination is greater than or equal to 50,
  the grade will be C.
If the total score in mid-term and final-term is less than 30, 
grade is F.

Input Format

The first line of the input contains one integer T - the number 
of test cases. Then T test cases follow.

The first line of each test case contains three space-separated 
integers M, F, R - the marks of the student in the mid-term, 
final-term and the make-up examinations.


Output Format

For each test case, print the grade of the student.


Constraints

1≤ T ≤ 105

1≤ M, F ≤ 50

1≤ R ≤ 100


Sample Input 1

4
41 48 76
-1 48 100
20 25 61
21 5 20

Sample Output 1

A
F
C
F*/

void solve(){

ll m,f,r;

cin>>m>>f>>r;
//cout<<"ans is .. ";
if(m==-1||f==-1){cout<<"F"<<nl;return;}
if(m+f<30)cout<<"F"<<nl;
 if(m+f>=80)cout<<"A"<<nl;
 if(m+f>=65&&m+f<80)cout<<"B"<<nl;
 if(m+f>=50&&m+f<65)cout<<"C"<<nl;
 if(m+f>=30&&m+f<50){
    
    if(r>=50)cout<<"C"<<nl;
    
   else cout<<"D"<<nl;
     
 }

    
    
}

/*
Pattern Problem 2 AZ101

Time-Limit: 1 sec Score: 1.00/100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Description

Using characters: . (dot), * (asterisk), / (slash) and \ 
(backslash) print a grid-like pattern
 as shown in the sample test case.


Input Format

The first line of the input contains one integer T - the number 
of test cases. Then T test cases follow.

The first line of each test case contains three space-separated 
integers N, M, P. - P denotes the 
size of .(dot) and /,\(slash) block.


Output Format

For each test case, print the required pattern.


Constraints

1≤ T ≤ 100

1≤ N, M ≤ 100

1≤ P ≤ 100

It is guaranteed that the sum of NMP*P for all test cases does
 not exceed106.


Sample Input 1

3
3 4 3
4 2 1
3 3 2

Sample Output 1

*****************
*\..*../*\..*../*
*.\.*./.*.\.*./.*
*..\*/..*..\*/..*
*****************
*../*\..*../*\..*
*./.*.\.*./.*.\.*
*/..*..\*/..*..\*
*****************
*\..*../*\..*../*
*.\.*./.*.\.*./.*
*..\*/..*..\*/..*
*****************

*****
*\*/*
*****
*/*\*
*****
*\*/*
*****
*/*\*
*****

**********
*\.*./*\.*
*.\*/.*.\*
**********
*./*\.*./*
*/.*.\*/.*
**********
*\.*./*\.*
*.\*/.*.\*
**********

Sample Input 2

1
3 1 3

Sample Output 2

*****
*\..*
*.\.*
*..\*
*****
*../*
*./.*
*/..*
*****
*\..*
*.\.*
*..\*
*****

Note

The diagonal of the first square of the grid is directed towards 
the down-right corner, use the \ (backslash)
 character to print it, while the next diagonal will be directed 
 towards the upper-right corner, use the / (slash) character to print it.*/

void solve(){
    int n, m, p;
    cin >> n >> m >> p;
    for(int i=0; i<(p+1)*n+1; i++){
        for(int j=0; j<(p+1)*m+1; j++){
            if(i%(p+1) == 0 || j%(p+1) == 0)    cout << '*';
            else if((i+j)%((p+1)*2)==0) cout << '/';
            else if((i-j)%((p+1)*2)==0) cout << '\\';
            else    cout << '.';
        }
        cout << endl;
    }
    cout << endl;
}

/*
Increasing Array AZ101

Time-Limit: 1 sec Score: 1.00/100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Description

You are given an array of N integers. In one operation, you can
 increase the value of any element by one.
 Find the minimum number of operations to make the array non-decreasing.


Input Format

The first line of the input contains one integer T - the number
 of test cases. Then T test cases follow.

The first line of each test case contains one integer N -
 the length of the array. 

The second line of each test case contains N space-separated integers.


Output Format

For each test case, print the minimum number of operations to
 make the array Non-Decreasing.


Constraints

1≤ T ≤ 105

1≤ N ≤ 105

1≤ Ai ≤ 109

It is guaranteed that the sum of N over all test cases does not exceed 105.


Sample Input 1

3
4
4 5 1 9
5
1 3 4 4 3
3
1 1 1

Sample Output 1

4
1
0

Note

For the first test case, increasing array would be: 4, 5, 5, 9

For the second test case, increasing array would be: 1, 3, 4, 4, 4

For the third test case, increasing array would be: 1, 1, 1*/
void solve(){
    
    ll n;
    cin>>n;
    
    ll arr[n];
    ll cnt=0;
    
    for(ll i=0;i<n;i++){
        
        cin>>arr[i];
    
    }
    
    for(ll i=0;i<n-1;i++){
        
        
        if(arr[i+1]<arr[i]){
            
            
            
            cnt+=arr[i]-arr[i+1];
            
            arr[i+1]=arr[i];
            
        } 
    }
    
    cout<<cnt<<'\n';  
}
//editorial code 
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
        long long ans = 0;
        for (int i = 1; i < n; ++i) {
            ans += max(0,a[i-1] - a[i]);
            a[i] = max(a[i], a[i-1]);
        }
        cout << ans << "\n";
    }
    return 0;
}


/*Dice Simulation AZ101

Time-Limit: 1 sec Score: 1.00/100
Difficulty : *
 Memory: 256 MB Accepted Submissions: 100
Description

You are given a dice with different values on each face. 
Find the integer at the top of the face after the sequence 
of commands to roll the dice is performed. 
The dice is initially located as shown.


 



Input Format

The first line of the input contains one integer T - 
the number of test cases. Then T test cases follow.

The first line of each test case contains six
 space-separated integers Ai - values on each face.

The second line of each test case contains a string S - 
the sequence of commands.


Output Format

For each test case, print the integer at the top of the 
face after the sequence of commands to roll the dice is done.


Constraints

1≤ T ≤ 106

1≤ Ai ≤ 107

1≤ |S| ≤ 106

It is guaranteed that the sum of |S| over all test
 cases does not exceed 106.


Sample Input 1

3
1 2 3 4 5 6
NE
2 4 5 3 1 7
SWN
3 4 5 6 7 8
SSEN

Sample Output 1

4
2
7

Note

For the first test case, initially 1 is at top,
 rotating N, 2 is at top, rotating E, 4 is at top.

For the second test case, initially 2 is at top, 
rotating S, 1 is at top, rotating W, 5 is at top,
 rotating N, 2 is at top.

For the third test case, initially 3 is at top, 
rotating S, 7 is at top, rotating S, 8 is at top,
 rotating E, 6 is at top, rotating N, 
7 is at top.*/

void solve(){
    
    int a[7];
for(int i=1;i<=6;i++){
    
    cin>>a[i];
  
}

string s;
cin>>s;

for(int i=0;i<s.size();i++){
    
    /*
a[1]=top;a[6]=bottom;
a[2]=south;a[5]=north;
a[3]=east;a[4]=west;
*/
    if(s[i]=='N'){
        int top=a[1];
        
        a[1]=a[2];
        a[2]=a[6];
        a[6]=a[5];
        a[5]=top;
       
    }else if(s[i]=='S'){
        int top=a[1];
        a[1]=a[5];
        a[5]=a[6];
        a[6]=a[2];
        a[2]=top;
        
    }else if(s[i]=='E'){
        
        int top=a[1];
        a[1]=a[4];
        a[4]=a[6];
        a[6]=a[3];
        a[3]=top;
        
          }else{
        int top=a[1];
        a[1]=a[3];
        a[3]=a[6];
        a[6]=a[4];
        a[4]=top;
         } 
}
cout<<a[1]<<'\n';   
 
}
/*
Perfect Square Cube Check

Time-Limit: 1 sec Score: 100.00/100
Difficulty : *
 Memory: 256 MB Accepted Submissions: 100
Description

You are given an integer N. You have to tell whether the number is
 a perfect square/cube according to the given query. 
Do not use inbuilt sqrt() and cube() function. As sqrt(4) can
 be equal to 1.9999999 and int(1.999999). = 1. Due to precision
 issue do not use sqrt() if you are dealing with integers.


Input Format

The first line of the input contains one integer T - the number of 
test cases. Then T test cases follow.

The first line of each test case contains two space-separated 
integers Q, N - Q=1 denotes that you have to check if N is
 a perfect square and Q=2 denotes that you have to check if
  N is a perfect cube.


Output Format

For each test case, print “YES” if the number is a perfect 
square/cube and “NO” if the number is not a perfect square/cube,
 according to the given query.


Constraints

1 ≤ T ≤ 100

1 ≤ N ≤ 107


Sample Input 1

4
1 64
2 64
2 9
1 5

Sample Output 1

YES
YES
NO
NO

Note

For the first test case, 8*8 = 64, hence it is a perfect square.

For the second test case, 4*4*4 = 64, hence it is a perfect cube.

For the third test case, 9 is not a perfect cube.

For the fourth test case, 5 is not a perfect square.*/

void solve(){

int q;
ll n;
cin>>q>>n;

int cnt=0;
int cnt1=0;
for(ll i=1;i*i<=n;i++){
    
    if(q==1){
        
        if(i*i==n){
            cnt=1;
            
        }  
    }else if(q==2){
        
        if(i*i*i==n){
            
            cnt1=1;
        }
    }  
}
//cout<<cnt<<endl;
//cout<<cnt1;

if(q==1){
    
    if(cnt>0){
        cout<<"YES"<<'\n';
    }else if(cnt==0){
        
        cout<<"NO"<<'\n';
    }
   
}else if(q==2){
    
     if(cnt1>0){
        cout<<"YES"<<'\n';
    }else if(cnt1==0){
        
        cout<<"NO"<<'\n';
    }
    
    
}

   } 
   
   /*
   Matrix Multiplication AZ101

Time-Limit: 1 sec Score: 100.00/100
Difficulty : *
 Memory: 256 MB Accepted Submissions: 100
Description

You are given matrix A of size N*M and matrix B of size M*P. 
You have to find the matrix multiplication of A and B.


Input Format

The first line of the input contains one integer T - 
the number of test cases. Then T test cases follow.

The first line of each test case contains three 
space-separated integers, N, M and P.

Each of the next N lines contain M space-separated integers - matrix A.

Each of the next M lines contain P space-separated integers - matrix B.


Output Format

For each test case, print the matrix multiplication of A and B.


Constraints

1 ≤ T ≤ 10

1 ≤ N, M, P ≤ 100

-103 ≤ Aij, Bij ≤ 103


Sample Input 1

2
2 3 2
1 2 3
2 5 1
3 1
-2 1
0 -1
1 4 1
1 2 1 -5
3
0
2
4

Sample Output 1

-1 0 
-4 6 
-15*/
   
   void solve(){
    
    int n,m,p;
    
    cin>>n>>m>>p;
    
    ll a[n][m];
    ll b[m][p];
    
    ll multi[n][p];
    
    for(int i=0;i<n;i++){
          for(int j=0;j<m;j++){
            
            cin>>a[i][j];     
        }
    }
    
for(int i=0;i<m;i++){
        
        
        for(int j=0;j<p;j++){
            
            cin>>b[i][j];   
        }
    }
        for(int i=0;i<n;i++){
        
        
        for(int j=0;j<p;j++){
            
            multi[i][j]=0;
            
        }
    }
    for(int i=0;i<n;i++){
        
        
        for(int j=0;j<p;j++){
            
        for(int k=0;k<m;k++){
            
            multi[i][j]+=a[i][k]*b[k][j];  
        }      
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<p;j++){
            cout<<multi[i][j]<<" ";
        //  cout<<b[0][1]<<" ";
            
        }
        
        cout<<'\n';
    }
      
}

/*Intersection and Union of Two Rectangles AZ101

Time-Limit: 1 sec Score: 100.00/100
Difficulty : *
 Memory: 256 MB Accepted Submissions: 100
Description

You are given two rectangles with their lower-left and upper-right coordinates.
 You have to find the area of the intersection and union of the rectangles.
  Both rectangles are axis-aligned.


Input Format

The first line of the input contains one integer T - the number
 of test cases. Then T test cases follow.

The first line of each test case contains four space-separated
 integers X1, Y1, X2, Y2 - coordinates of the first rectangle. 

The second line of each test case contains four space-separated 
integers X3, Y3, X4, Y4 - coordinates of the second rectangle. 


Output Format

For each test case, print the area of intersection and 
union of the rectangles.


Constraints

1≤ T ≤ 105
-103≤ Xi, Yi ≤ 103
It is guaranteed that X1 ≤ X2, Y1 ≤ Y2, X3 ≤ X4, and Y3 ≤ Y4.


Sample Input 1

3
0 0 2 2
1 1 3 4
0 0 3 3
1 1 2 3
1 2 3 4
0 0 1 1

Sample Output 1

1 9
2 9
0 5

Note

If the image is not visible please check this docs link - 
https://docs.google.com/document/d/126mU5E-f2FhaByhQ8xE3jeI7JrpCOwyT2Pnp1pAvAu0/

For the first test case,


For the second test case,


For the third test case,

*/
    
    void solve(){
    
    ll x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    
    ll a=(x2-x1)*(y2-y1);
    
    ll c=0;
    
    ll x3,y3,x4,y4;
    cin>>x3>>y3>>x4>>y4;
    
    
    ll b=(x4-x3)*(y4-y3);
    
    
    ll inter,uni,x5,y5,x6,y6;
    
     x5=max(x1,x3);
    
     x6=min(x2,x4);
     y5=max(y1,y3);
     y6=min(y2,y4);
    inter=max(c,(x6-x5))*max(c,(y6-y5));
    uni=a+b+-inter;
    cout<<inter<<" "<<uni<<'\n';
    
}

/*Euclidean and Manhattan Distance AZ101

Time-Limit: 1 sec Score: 100.00/100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Description

You are given two points on a 2-D plane. You have 
to find the euclidean and manhattan 
distance between the two points.


Input Format

The first line of the input contains one integer T -
 the number of test cases. Then T test cases follow.

The first line of each test case contains four 
space-separated integers X1, Y1, X2, Y2.


Output Format

For each test case, print the euclidean and manhattan
 distance between the two points on a new line. 
The answer should contain 7 decimal places after round-off.


Constraints

1 ≤ T ≤ 105

-106 ≤ X1, Y1, X2, Y2 ≤ 106


Sample Input 1

3
0 0 2 2
1 2 5 5
4 1 -8 2

Sample Output 1

2.8284271 4.0000000
5.0000000 7.0000000
12.0415946 13.0000000

Note

This problem is for educational purpose, use double instead 
of long double to store the intermediate values.
 In the case of a problem where you are being asked to round-off and
  match the exact numbers till some places after 
 the decimal, you will have to match the data-type used by the setter.
  generally, these sort of test cases is generated 
 by using some fixed datatype and incase in a test you are unable to
  get an AC, make sure to try double and floats too.*/


void solve(){
    
    
    ll x1,y1,x2,y2,x,y;
    
    cin>>x1>>y1>>x2>>y2;
    
    x=abs(x1-x2);
    y=abs(y1-y2);
    
    double euclid,manhattan;
    euclid=sqrt((x*x)+(y*y));
    manhattan=x+y;
    cout<<fixed<<setprecision(7)<<euclid<<" "<<fixed<<setprecision(7)<<manhattan<<"\n";
}


/*Longest AP AZ101

Time-Limit: 1 sec Score: 1.00/100
Difficulty : *
 Memory: 256 MB Accepted Submissions: 100
Description

You are given an array A of N integers. You have to choose a 
contiguous arithmetic subarray with equal
 difference between consecutive integers, that has the maximum length.
  Find the maximum possible length.


Input Format

The first line of the input contains one integer T - the number of test cases.
 Then T test cases follow.

The first line of each test case contains one integer N -
 the length of the array.

The second line of each test case contains N space-separated integers.


Output Format

For each test case, print the maximum possible length.


Constraints

1 ≤ T ≤ 105

2 ≤ N ≤ 105

-107 ≤ Ai ≤ 107

It is guaranteed that the sum of N over all test cases does not exceed 105.


Sample Input 1

3
4
1 2 3 5
6
1 4 7 4 1 -2
2
1 8

Sample Output 1

3
4
2

Note

For the first test case, 1 2 3 5

For the second test case, 1 4 7 4 1 -2

For the third test case, 1 8*/

void solve(){
    
    
    ll n;
    cin>>n;
    vector<ll>a(n);
    ll cnt=2;
    ll d;
    ll maxi =0;
    for(ll i=0;i<n;i++){
        
        cin>>a[i];   
    }
    
    for(ll i=0;i<n-1;i++){
        
        if(2*a[i+1]==a[i]+a[i+2]){
            
            cnt+=1;
        
        }else{
            
            
            //i++;
            
            cnt=2;
            };  
            maxi=max(maxi,cnt);
        
    }
    
    if(n==1){
        
        cout<<1<<'\n';
    }else if(n==2){
        
        cout<<2<<'\n';
    }else{
    
    
    cout<<maxi<<'\n';}
    
}
//editorial code 
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
        int cur = 2, diff = a[1] - a[0];
        int ans = 2;
        for (int i = 2; i < n; ++i) {
            if(a[i]-a[i-1] == diff) {
                cur++;
            }
            else {
                cur = 2;
                diff = a[i] -a[i-1];
            }
            ans = max(ans, cur);
        }
        cout << ans << "\n";
    }
    return 0;
}

/*
Maximise Zeros AZ101

Time-Limit: 1 sec Score: 1.00/100
Difficulty : **
 Memory: 256 MB Accepted Submissions: 100
Description

You are given two arrays, A and B of N integers. You have to create
 a new array, Ci = Ai * D + Bi

Find the maximum number of zeros you can get in the new array Ci 
taking an optimal value of D. (D is a real number)


Input Format

The first line of the input contains one integer T - the number of test cases.
 Then T test cases follow.

The first line of each test case contains one integer N - the length of the array. 

The second line of each test case contains N space-separated integers - array Ai

The third line of each test case contains N space-separated integers - array Bi


Output Format

For each test case, print the maximum number of zeros you can get in the new 
array Ci taking an optimal value of D.


Constraints

1≤ T ≤ 106

1≤ N ≤ 106

-109 ≤ Ai, Bi ≤ 109

It is guaranteed that the sum of N over all test cases does not exceed 106.


Sample Input 1

3
5
1 3 2 5 4
2 6 1 5 8
3
0 2 0
1 1 1
3
0 0 4
4 0 1

Sample Output 1

3
1
2

Note

For the first test case, take D = -2

For the second test case, take D = -½, C = [1,0,1]

For the third test case, take D = -1/4, C = [4,0,0]*/


int main() {
    IOS
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n], b[n];
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }
        map<pair<int,int>, int> m;
        int s = 0;
        for (int i = 0; i < n; ++i) {
            if(a[i] == 0) {
                if(b[i] == 0) {
                    s++;
                }
            }
            else {
                bool f = 0;
                if((a[i]<0 && b[i]>0) || (a[i]>0 && b[i]<0)) {
                    f = 1;
                }
                a[i] = abs(a[i]);
                b[i] = abs(b[i]);
                int g = __gcd(a[i], b[i]);
                a[i] /= g;
                b[i] /= g;
                if(f) a[i] = -a[i];
                m[{a[i], b[i]}]++;
            }
        }
        int ans = 0;
        for(auto i:m) {
            ans = max(ans, i.second);
        }
        cout << ans + s << "\n";
    }
    return 0;
}

/*
Maximum Candies AZ101

Time-Limit: 1 sec Score: 100.00/100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Description

There are N candies in a shop. Find the maximum number of candies you 
can buy with the B money you have, 
given the price of each candy.


Input Format

The first line of the input contains one integer T - the number of test cases. 
Then T test cases follow.

The first line of each test case contains two space-separated 
integers N and B - the length of the array 
and money you have.

The second line of each test case contains N space-separated integers.


Output Format

For each test case, print the maximum number of candies you can buy.


Constraints

1≤ T ≤ 105

1≤ N, B ≤ 105

1≤ Ai ≤ 1000

It is guaranteed that the sum of N over all test cases does not exceed 105.


Sample Input 1

3
4 6
1 3 3 5
5 3
1 1 1 1 1
2 10
1 3

Sample Output 1

2
3
2

Note

For the first test case, take candies with price 1 and 5.

For the second test case, take 3 candies with price 1.

For the third test case, you can take all candies.*/

void solve(){
    
    ll n,b;
    
    cin>>n>>b; 
    vector<ll>v(n); 
    for(ll i=0;i<n;i++){ 
        cin>>v[i];
    }
    
    sort(v.begin(),v.end());
    ll cnt=0;
    
    for(ll i=0;i<n;i++){   
        if(b-v[i]>=0){
           
            b-=v[i];
            
            cnt++; 
        }
    }
    
    cout<<cnt<<"\n";
}


//editorial code 

int main() {
    IOS
    int t;
    cin >> t;
    while (t--) {
        int n, s;
        cin >> n >> s;
        int a[n];
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        sort(a, a+n);
        int candies = 0, cost = 0;
        for (int i = 0; i < n; ++i) {
            cost += a[i];
            if(cost > s) {
                break;
            }
            candies++;
        }
        cout << candies << "\n";
    }
    return 0;
}




/*Robot Movements AZ101

Time-Limit: 1 sec Score: 0.00/100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Description

You have a robot which can move up, down, left and right. You placed it at (X, Y) 
in a grid with R rows and C columns.The robot is given N instructions of the form 
N(up), S(down), E(right) and W(left). The robot will continue moving the 
 same direction until it reaches a square that it has not been in before. 
 Find the coordinates of the square the robot will reach after the instructions are performed. 
The robot will not go out of the grid, according to the instructions.


Input Format

The first line of the input contains one integer T - the number of test cases.
 Then T test cases follow.

The first line of each test case contains five space-separated integers N, R, C, X, Y - 
the length of the instructions,
 size of grid and the coordinates of initial position.

The second line of each test case contains a string S - the instructions .


Output Format

For each test case, print the coordinates of the square the robot will reach after 
the instructions are performed.


Constraints

1≤ T ≤ 105

1≤ N ≤ 5*104

1≤ R, C ≤ 5*104

1≤ X ≤ R

1≤ Y ≤ C

Sum of N across each test case <= 1000000.


Sample Input 1

2
3 4 5 2 3
SNW
4 5 5 2 2 
SESE

Sample Output 1

1 2
4 4

Note

For the first test case, (2,3) -> (3,3) -> (1,3) -> (1,2)

For the second test case, (2,2) -> (3,2) -> (3,3) -> (4,3) -> (4,4)*/

 
We make a set of intervals for each row and column to represent the cells that have been visited in that particular row or column. When we have to reach another cell (r,c) use lower_bound/upper_bound to find the correct place. Merge the contiguous intervals.

Time Complexity per test case: O(N logN)

 

#include <bits/stdc++.h>
using namespace std;

set<pair<int,int>> hor[50005], vert[50005];

void add(int x, int y)
{
    auto it1=vert[y].lower_bound({x+1, -1});
    auto it2=it1;
    --it2;
    pair<int,int> nxt=*it1, prev=*it2;

    if(prev.second+2==nxt.first){
        vert[y].erase(prev);
        vert[y].erase(nxt);
        vert[y].insert({prev.first, nxt.second});
    }
    else if(x==prev.second+1){
        vert[y].erase(prev);
        ++prev.second;
        vert[y].insert(prev);
    }
    else if(x==nxt.first-1){
        vert[y].erase(nxt);
        --nxt.first;
        vert[y].insert(nxt);
    }
    else{
        vert[y].insert({x, x});
    }

    it1=hor[x].lower_bound({y+1, -1});
    it2=it1;
    --it2;
    nxt=*it1, prev=*it2;

    if(prev.second+2==nxt.first){
        hor[x].erase(prev);
        hor[x].erase(nxt);
        hor[x].insert({prev.first, nxt.second});
    }
    else if(y==prev.second+1){
        hor[x].erase(prev);
        ++prev.second;
        hor[x].insert(prev);
    }
    else if(y==nxt.first-1){
        hor[x].erase(nxt);
        --nxt.first;
        hor[x].insert(nxt);
    }
    else{
        hor[x].insert({y, y});
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, r, c, x, y;
        cin>>n>>r>>c>>x>>y;

        for (int i = 1; i <= r; ++i) {
            hor[i].clear();
            hor[i].insert({0, 0});
            hor[i].insert({c+1, c+1});
        }
        for (int i = 1; i <= c; ++i) {
            vert[i].clear();
            vert[i].insert({0, 0});
            vert[i].insert({r+1, r+1});
        }

        vert[y].insert({x, x});
        hor[x].insert({y, y});

        while(n--){
            char c;
            cin>>c;
            if(c=='N') {
                x--;
                auto it=vert[y].lower_bound({x+1, -1});
                it--;
                if(x>it->second){
                    add(x, y);
                }
                else {
                    x=it->first-1;
                    add(x, y);
                }
            }
            else if(c=='S') {
                x++;
                auto it=vert[y].lower_bound({x+1, -1});
                it--;
                if(x>it->second){
                    add(x, y);
                }
                else {
                    x=it->second+1;
                    add(x, y);
                }
            }
            else if(c=='W') {
                y--;
                auto it=hor[x].lower_bound({y+1, -1});
                it--;
                if(y>it->second){
                    add(x, y);
                }
                else {
                    y=it->first-1;
                    add(x, y);
                }
            }
            else {
                y++;
                auto it=hor[x].lower_bound({y+1, -1});
                it--;
                if(y>it->second){
                    add(x, y);
                }
                else {
                    y=it->second+1;
                    add(x, y);
                }
            }
        }
        cout << x << " " << y << "\n";
    }
    return 0;
}


// approach 

/*Make contiguous intervals for each row and column.

We make a set of intervals for each row and column to represent the cells that have 
been visited in that particular row or column. When we have to reach another cell (r,c)
use lower_bound/upper_bound to find the correct place. Merge the contiguous intervals.

Time Complexity per test case: O(N logN) */
