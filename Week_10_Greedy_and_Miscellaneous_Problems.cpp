/*Question 1

Given n job activities with their start time and finish time. Find
 the maximum number of activities that can be performed without 
 performing two activities at the same time.

Example:

Start = {5, 1, 3, 0, 5, 8}, end = {9, 2, 4, 6, 7, 9}  => 4
Solution Idea:

Method1: The greedy idea to solve this problem is to select the 
jobs which end earliest. So we will sort all the jobs with their 
end-time and greedily pick the jobs if it is not clashing
 with previously picked jobs. */

#include<bits/stdc++.h>
typedef long long lli;
using namespace std;
lli mod=1e9+7;

bool comp(pair<lli,lli> &a, pair<lli,lli> &b)
{
    return a.second<b.second;
}

int maxjobs(vector<pair<lli,lli> > &v)
{
    lli n=v.size(),count=0;
    lli prev_end=INT_MIN;
    for(lli i=0;i<n;i++)
    {
        if(v[i].first>=prev_end)
        {
            count++;
            prev_end=v[i].second;
        }
    }
    return count;
}

void solve()
{
    lli n;
    cin>>n;
    vector<pair<lli,lli> > v(n);
    for(lli i=0;i<n;i++)
    {
        lli start,end;
        cin>>start>>end;
        v[i] = {start,end};
    }
    sort(v.begin(),v.end(),comp);
    lli ans = maxjobs(v);
    cout<<ans<<endl;
}

int main()
{
    lli t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0; 
}
Question 2

Given lengths of n ropes, we need to join them and make a single rope. Joining two ropes will make a single rope of length equal to the sum of both the ropes and also the cost of joining is also equal to the sum of ropes that are joined.

Example:

{4,4,3,2,6} => 43
Solution Idea:

Method1: If we look closely at the problem we find that the length of rope which is joined first will contribute to the cost till all the ropes are joined. So we should not join the highest length rope at the first. We will pick the minimum two ropes and join them and recursively perform this operation for rest. For this, we will use min priority_queue (minheap).

#include<bits/stdc++.h>
typedef long long lli;
using namespace std;
lli mod=1e9+7;

int min_cost_to_join(vector<lli> &rope)
{
    lli n=rope.size();
    priority_queue<lli,vector<lli>,greater<lli>> q;
    for(lli i=0;i<n;i++)
    {
        q.push(rope[i]);
    }
    lli cost=0;
    while(!q.empty())
    {
        lli x=q.top();
        q.pop();
        if(q.empty())
        {
            break;
        }
        lli y=q.top();
        q.pop();
        cost+= (x+y);
        q.push(x+y);
    }
    return cost;
}

void solve()
{
    lli n;
    cin>>n;
    vector<lli> rope(n);
    for(lli i=0;i<n;i++)
    {
        cin>>rope[i];
    }
    lli ans = min_cost_to_join(rope);
    cout<<ans<<endl;
}

int main()
{
    lli t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0; 
}
Question 3

Find the maximum value of the sum of arr[i] * i of the given array arr when rearrangement is allowed.

Example:

{2, 7, 4, 1} => 31
Solution Idea:

Method1: We need to scale the maximum number by the maximum value and the minimum number by the minimum value. So we will just sort the array and count the required sum.

#include<bits/stdc++.h>
typedef long long lli;
using namespace std;
lli mod=1e9+7;

lli maximum_value(vector<lli> &arr)
{
    lli n=arr.size(),ans=0;
    sort(arr.begin(),arr.end());
    for(lli i=0;i<n;i++)
    {
        ans+=(arr[i]*i);
    }
    return ans;
}

void solve()
{
    lli n;
    cin>>n;
    vector<lli> arr(n);
    for(lli i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    lli ans = maximum_value(arr);
    cout<<ans<<endl;
}

int main()
{
    lli t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0; 
}
Question 4

Find the minimum product of a subset of numbers of an array.

Example:

{0, -1, 2, 1, -2} => -4
Solution Idea:

Method1: If there are even numbers of negative numbers and no zeros, the result is the product of all except the largest valued negative number. If there are an odd number of negative numbers and no zeros, the result is simply the product of all. If there are zeros and positive, no negative, the result is 0. The exceptional case is when there is no negative number and all other elements positive then our result should be the first minimum positive number.

lli minProductSubset(vector<lli> &a, lli n)
{
    if (n == 1)
        return a[0];
    lli max_neg = INT_MIN;
    lli min_pos = INT_MAX;
    lli count_neg = 0, count_zero = 0;
    lli prod = 1;
    for (lli i = 0; i < n; i++) {
        if (a[i] == 0) {
            count_zero++;
            continue;
        }
        if (a[i] < 0) {
            count_neg++;
            max_neg = max(max_neg, a[i]);
        }
        if (a[i] > 0) {
            min_pos = min(min_pos, a[i]);
        }
        prod = prod * a[i];
    }
    if (count_zero == n || (count_neg == 0 && count_zero > 0))
        return 0;
    if (count_neg == 0)
        return min_pos;
    if (!(count_neg & 1) && count_neg != 0) {
        prod = prod / max_neg;
    }
    return prod;
}
Question 5

Find the maximum sum of the array after performing k negations of elements.

Example:

{5, -2, -4, 1, -1}, k=2 => 11
{2, -3, 0, 4, 1}, k=3 => 10
Solution Idea:

Method1: We need to negate the minimum numbers in the current array and this operation is performed k times or till the minimum number is zero. We will use a priority queue for finding the minimum number in the array.

#include<bits/stdc++.h>
typedef long long lli;
using namespace std;
lli mod=1e9+7;

lli maximum_sum(vector<lli> &arr,lli k)
{
    lli n=arr.size(),ans=0;
    priority_queue<lli, vector<lli>, greater<lli> >q;
    for(lli i=0;i<n;i++)
    {
        q.push(arr[i]);
    }
    for(lli i=0;i<k;i++)
    {
        lli p = q.top();
        q.pop();
        if(p==0)
            break;
        p = -p;
        q.push(p);
    }
    while(!q.empty())
    {
        ans+=q.top();
        q.pop();
    }
    return ans;
}

void solve()
{
    lli n,k;
    cin>>n>>k;
    vector<lli> arr(n);
    for(lli i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    lli ans = maximum_sum(arr,k);
    cout<<ans<<endl;
}

signed main()
{
    lli t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0; 
}  */
