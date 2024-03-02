

/* Word Ladder

    Time-Limit: 2 sec Score: 0.00/100

Difficulty :*****

    Memory: 256 MB Accepted Submissions: 100

Relevant For: 201,202

Description

Given two words beginWord and endWord and a dictionary of words. Find a minimum number of moves to transform beginWord into endWord. In one move, you can change one letter of the current word. New formed word should always be present in the given dictionary. Note that beginWord does not need to be in the dictionary.

Return minimum moves to transform from beginWord to endWord. If no such transformation exists, return 0.

Input Format

The first line of input contains N - the number of words in the dictionary.
Next N lines contain dictionary words separated by space.
The last line of input contains beginWord and endWord.

Constraints

1 ≤ |beginWord| ≤ 10
|endWord| == |beginWord|
1 ≤ Total words in dictionary ≤ 10000
Each word in a dictionary is the same in length as beginWord.
beginWord, endWord, and dictionary words consist of lowercase English letters.
beginWord != endWord
All the words in the dictionary are unique.
Sample Input 1

6
hot dot dog lot log cog
hit cog

Sample Output 1

5

Note

Explanation: hit → hot →dot → dog → cog*/


/*approach and editorial code :
Let’s consider we can transform word A to word B by changing one of the letters in word A. Suppose we ith letter word A needs to be changed to B[i]. If we create new string A’ and B’ as follows:

A' = A; A’[i] = '*'
B' = B; B[i] = '*'

Observe that both A’ and B’ strings are equal. 

Let’s generalize it: A’i be the word obtained by replacing ith character of string A by ‘*’. Similarly, we define B’i. 

If for any i, A’i == B’i then we can change string A to string B by replacing one character, and that one is ith character.

On the above observation, we design our algorithm to solve the problem.

We change our dictionary words to the new words formed by replacing each character with ‘*’. That is we delete our word A from the dictionary and add A’i words, i.e., total |A| words, in the dictionary with the information of the original A word, maybe index.

Using this above preprocessing, we create a graph. And apply BFS to find the shortest path between beginWord and endWord.
 

class WordLadder
{
public:
    int getMinMoves(string beginWord, string endWord, vector<string> &dictionary)
    {
        //Number of words in the list
        int numWords = (int)dictionary.size();

        //Finding the location of beginWord and endWord in list
        int startIdx = -1, endIdx = -1;

        for (int i = 0; i < numWords; i++)
        {
            if (startIdx == -1 && dictionary[i] == beginWord)
                startIdx = i;
            if (endIdx == -1 && dictionary[i] == endWord)
                endIdx = i;
        }

        //endWord is not in the list
        if (endIdx == -1)
            return 0;

        //beginWord and endWord are same
        if (startIdx == endIdx)
            return 1;

        if (startIdx == -1) {
            dictionary.push_back(beginWord);
            startIdx = (int)dictionary.size() - 1;
        }

        unordered_map<string, vector<int>> graph;

        //Creating graph
        for (int i = 0; i < numWords; i++)
        {
            for (int j = 0; j < (int)dictionary[i].length(); j++)
            {
                char temp = dictionary[i][j];
                dictionary[i][j] = '*';
                graph[dictionary[i]].push_back(i);
                dictionary[i][j] = temp;
            }
        }

        int dist[numWords];
        int whichEnd[numWords];

        memset(dist, -1, sizeof(dist));
        memset(whichEnd, -1, sizeof(whichEnd));

        dist[startIdx] = 1;
        whichEnd[startIdx] = 0;

        dist[endIdx] = 1;
        whichEnd[endIdx] = 1;

        queue<int> q;
        q.push(startIdx);
        q.push(endIdx);

        while (!q.empty())
        {
            int cur = q.front();
            q.pop();

            for (int i = 0; i < (int)dictionary[cur].length(); i++)
            {
                char temp = dictionary[cur][i];
                dictionary[cur][i] = '*';

                for (int u : graph[dictionary[cur]])
                {
                    if (dist[u] == -1)
                    {
                        dist[u] = dist[cur] + 1;
                        whichEnd[u] = whichEnd[cur];
                        q.push(u);
                    }
                    else if (whichEnd[u] != whichEnd[cur])
                    {
                        return dist[u] + dist[cur];
                    }
                }

                dictionary[cur][i] = temp;
            }
        }

        return 0;
    }
};

*/

//arsh agarwal's code:
#include <bits/stdc++.h>
using namespace std;

class WordLadder
{
public:
	int getMinMoves(string s, string t, vector<string> &a)
	{
		int m = s.size();
        map<string, int> mp;
        set<string> st; for(auto it: a) st.insert(it);
        queue<string> q; q.push(s); mp[s] = 0;
        while(!q.empty()){
            string node = q.front(); q.pop();
            string temp = node;
            for(int i = 0; i < m; i++){
                for(int j = 0; j < 26; j++){
                    temp[i] = char('a'+j);
                    if(st.find(temp)!=st.end() and mp.find(temp)==mp.end()){
                        mp[temp] = mp[node] + 1; q.push(temp);
                    }
                }
                temp[i] = node[i];
            }
        }
        if(mp.find(t)==mp.end()) return 0;
        return mp[t]+1;
	}
};

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	vector<string> dictionary;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;

		dictionary.push_back(s);
	}

	string beginWord, endWord;
	cin >> beginWord >> endWord;

	WordLadder wordLadder;

	cout << wordLadder.getMinMoves(beginWord, endWord, dictionary) << "\n";

	return 0;
}

/* ADDMUL

    Time-Limit: 1 sec Score: 0.00/100

Difficulty :***

    Memory: 256 MB Accepted Submissions: 100

Relevant For:

Description

Implement a data structure that supports appending a value to an integer sequence, adding or multiplying a given value to all elements present in the sequence and displaying the value present at any index of the sequence.

Input Format

Implement the AddMul class:

    AddMul() : Initializes the object with an empty sequence.
    void append(val) : Appends an integer val to the end of the sequence.
    void add(inc) : Increments all existing values in the sequence by an integer inc.
    void mult(mul) : Multiplies all existing values in the sequence by an integer mul.
    int get(idx) : Gets the current value at index idx (0-indexed) of the sequence modulo 109 + 7. If the index is greater or equal than the length of the sequence, return -1.

Output Format

For every time the get function is called return the value present at the given index.

Constraints

1 ≤ val, inc, m ≤ 100

0 ≤ idx ≤ 105

At most 105 calls are made in total to append, add, mult and get.

Sample Input 1

11
append 2
add 3
append 7
mult 2
get 0
add 3
append 10
mult 2
get 0
get 1
get 2

Sample Output 1

10
26
34
20

Note

The sequence after the operations:

[2]
[2+3] -> [5]
[5, 7]
[5*2, 7*2] -> [10, 14]
A[0] = 10
[10+3, 14+3] -> [13, 17]
[13, 17, 10]
[13*2, 17*2, 10*2] -> [26, 34, 20]
A[0] = 26
A[1] = 34
A[2] = 20



*/
//arsh agarwal's code:
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll mod = 1e9+7;

ll power(ll a, ll p){
    ll ans = 1LL;
    while(p){
        if(p%2) (ans*=a)%=mod;
        (a*=a)%=mod; p/=2;
    }
    return ans;
}

ll inv(ll a) {return power(a, mod-2);}

class AddMul{
public:
    vector<ll> v;
    ll sum = 0LL, mul = 1LL;
    vector<pair<ll, ll>> p;
    AddMul(){
        
    }

    void append(long long val){
		v.push_back(val);
        p.push_back({sum, mul});
    }

    void add(long long inc){
        (sum += inc) %= mod;
    }

    void mult(long long m){
        (mul*=m)%= mod;
        (sum*=m)%=mod;
    }

    int get(int i){
        if(i>=v.size()) return -1;
        ll ans = (v[i]-p[i].first)%mod;
        (ans*=mul)%=mod;
        (ans*=inv(p[i].second))%=mod;
        (ans+=sum)%=mod;
        return (ans+mod)%mod;
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int q;
    cin >> q;
    
    AddMul *obj = new AddMul();
    
    for (int i = 0; i < q; i++)
    {
        string op;
        cin >> op;
        
        if (op == "append")
        {
            int val;
            cin >> val;
            obj->append(val);
        }
        else if (op == "add")
        {
            int inc;
            cin >> inc;
            obj->add(inc);
        }
        else if (op == "mult")
        {
            int mul;
            cin >> mul;
            obj->mult(mul);
        }
        else
        {
            int idx;
            cin >> idx;
            cout << obj->get(idx) << '\n';
        }
    }
    
    return 0;
}

/*approach and editorial code :
Maintain 2 variables i and m which store the total to be added and multiplied for all the elements in the sequence.

Each element in the array can be represented as a[i] = a[i](initial) *m + i.

When a number is added to all the elements increase i by the corresponding value.
When a number is multiplied to all the elements, m = m*mul and i = i*mul.
When a number val is appended to the sequence, we can update the values of all the other elements for the current values of i and m. But this will exceed the time limit. So we append a value x to sequence such that x*m + i = val. In this way we can avoid updating all the values and not have to reset i and m. Since we are finding the answer modulo 109+7, you can find the inverse using Fermat's Little Theorem when dividing.

class AddMul
{
public:
    long long i, m, MOD;
    vector<long long> v;

    AddMul()
    {
        i = 0, m = 1, MOD = 1e9 + 7;
    }

    long long power(long long a, long long b)
    {
        long long res = 1;
        a = a % MOD;
        while (b > 0)
        {
            if (b & 1)
            {
                res = (res * a) % MOD;
                b--;
            }
            a = (a * a) % MOD;
            b >>= 1;
        }
        return res;
    }

    long long inverse(long long x)
    {
        return power(x, MOD - 2);
    }

    void append(long long val)
    {
        (val += MOD - i) %= MOD;
        (val *= inverse(m)) %= MOD;
        v.push_back(val);
    }

    void add(long long inc)
    {
        (i += inc) %= MOD;
    }

    void mult(long long mul)
    {
        (m *= mul) %= MOD;
        (i *= mul) %= MOD;
    }

    int get(int idx)
    {
        if (idx >= v.size())
            return -1;
        return (v[idx] * m % MOD + i) % MOD;
    }
};


*/


/* Word Dictionary

    Time-Limit: 2 sec Score: 0.00/100

Difficulty :

    Memory: 256 MB Accepted Submissions: 100

Relevant For:

Description

Design a data structure that supports adding new words and finding if a string matches any previously added string.

Implement the WordDictionary class:

    WordDictionary() - Initialises the object.
    void addWord(word) - Adds word to the data structure, it can be matched later.
    bool search(word) - Returns true if there is any string in the data structure that matches word or false otherwise. word may contain dots '.' where dots can be matched with any letter.

Input Format

Your WordDictionary object will be instantiated and called as such:

WordDictionary* obj = new WordDictionary();
obj->addWord(word);
bool param_2 = obj->search(word);

Output Format

For search queries, if there is a string in the data structure that matches word, ‘Yes’ is printed.
Otherwise, ‘No’ is printed.

Constraints

1 <= |word| <= 100
1 <= q <= 1000 (total number of function calls made)
word in addWord consists of lower case English alphabets
word in search consists of lower case English alphabets and ‘.’ character

Sample Input 1

7
add dad
add bad
add mad
search pad
search mad
search .ad
search b..

Sample Output 1

No
Yes
Yes
Yes

Note

pad -> No matching string.
mad -> present in the data structure.
.ad -> Matched by bad, mad, dad.
b.. -> Matched by bad.


*/

/*approach and editorial :
We can solve this problem using the Trie data structure. Do DFS on trie, till the match happens.

class Trie {
public:
    bool word;
    Trie* children[26];
    Trie() {
        word = false;
        memset(children, NULL, sizeof(children));
    }

};

class WordDictionary {
public:
    WordDictionary() {

    }

    void addWord(string word) {
        Trie* node = root;
        for (char c : word) {
            if (!node->children[c - 'a']) {
                node->children[c - 'a'] = new Trie();
            }
            node = node->children[c - 'a'];
        }
        node->word = true;
    }

    bool search(string word) {
        return search(word.c_str(), root);
    }

private:
    Trie* root = new Trie();
    bool search(const char* word, Trie* node) {
        for (int i = 0; word[i] && node; i++) {
            if (word[i] != '.') {
                node = node->children[word[i] - 'a'];
            }
            else {
                Trie* temp = node;
                for (int j = 0; j < 26; j++) {
                    node = temp->children[j];
                    if (search(word + i + 1, node)) {
                        return true;
                    }
                }
            }
        }
        return node && node->word;
    }

};

*/

//lakshya mittal's code:
#include <bits/stdc++.h>
using namespace std;
class WordDictionary {

    bool match(string a, string b){
        if(a.size() != b.size()) return false;
        int n = a.size();
        for(int i=0; i<n; i++){
            if(a[i] == '.') continue;
            else if(a[i] != b[i]) return false;
        }
        return true;
    }
    public:
    vector<string> arr;
	WordDictionary() {

	}

	void addWord(string word) {
		arr.push_back(word);
	}

	bool search(string word) {
		for(auto presentWord: arr){
            if(match(word, presentWord)) return true;
        }
        return false;
	}

};


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	WordDictionary* obj = new WordDictionary();

	int q;
	cin >> q;

	while (q--) {

		string op;
		cin >> op;

		if (op == "add") {
			string word;
			cin >> word;
			obj->addWord(word);
		}

		else {
			string word;
			cin >> word;
			if (obj->search(word))
				cout << "Yes\n";
			else
				cout << "No\n";
		}
	}
}


//arsh agarwal's code:
#include <bits/stdc++.h>
using namespace std;

class WordDictionary {
public:
	struct Trie{
        bool ending;
        Trie* a[26];

        Trie(){
            ending = false;
            for(int i = 0; i < 26; i++) a[i] = nullptr;
        }
    };

    Trie* t = new Trie();
    void insert(string& temp){
        Trie* node = t;
        for(int i = 0; i < temp.length(); i++){
            if(node->a[temp[i]-'a']==nullptr) node->a[temp[i]-'a'] = new Trie();
            node=node->a[temp[i]-'a'];
        }
        node->ending = true;
    }

    bool find(Trie* root, string& temp, int index){
        if(root==nullptr) {return false;}
        if(index==temp.length()) {return root->ending;}
        bool ans = false;
        if(temp[index]=='.'){
            for(int i = 0; i < 26; i++){
                if(ans) break;
                ans |= find(root->a[i], temp, index+1);
            }
        }else{
            ans = find(root->a[temp[index]-'a'], temp, index+1);
        }
        return ans;
    }

	WordDictionary() {
		
	}

	void addWord(string word) {
		insert(word);
	}

	bool search(string word) {
        
		return find(t, word, 0);
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	WordDictionary* obj = new WordDictionary();

	int q;
	cin >> q;

	while (q--) {

		string op;
		cin >> op;

		if (op == "add") {
			string word;
			cin >> word;
			obj->addWord(word);
		}

		else {
			string word;
			cin >> word;
			if (obj->search(word))
				cout << "Yes\n";
			else
				cout << "No\n";
		}
	}
}



/* LFU Cache

    Time-Limit: 1 sec Score: 0.00/100

Difficulty :****

    Memory: 256 MB Accepted Submissions: 100

Relevant For:201

Description

You need to design and implement a data structure that is able to handle different types of queries. The data structure has a capacity n and at any moment it cannot store more than n keys. Implement the LFUCache class:

    LFUCache(int n): Initializes the object with the capacity n of the data structure.
    int get(int key): Gets the value of the key if the key exists in the cache. Otherwise, returns -1.
    void put(int key, int value): Update the value of the key if present, or insert the key if not already present. When the cache reaches its capacity, it should invalidate and remove the least frequently used key before inserting a new item. For this problem, when there is a tie (i.e., two or more keys with the same frequency), the least recently used key would be invalidated.

To determine the least frequently used key, a use counter is maintained for each key in the cache. The key with the smallest use counter is the least frequently used key.
When a key is first inserted into the cache, its use counter is set to 1 (due to the put operation). The use counter for a key in the cache is incremented; either a get or put operation is called on it.
The least recently used key is the key with the smallest frequency which was called on the earliest among all the keys with the smallest frequency.

Input Format

Your LFUCache object will be instantiated and called as such:

LFUCache* obj = new LFUCache(n); 
int param_1 = obj->get(key);
obj->put(key,value);

Output Format

For each get query the value of the key is printed and if the key is not present, ‘-1’ is printed.

Constraints

1 <= n <= 10000
1 <= q <= 10000 (total number of function calls)
1 <= key <= 10000
0 <= value <= 10000

Sample Input 1

2 10
put 5 6
put 7 4
get 5
put 3 3
get 7
get 3
put 4 9
get 5
get 3
get 4

Sample Output 1

6
-1
3
-1
3
9

Note

1) Cache = [5] , cnt[5] = 1
2) Cache = [7 ,5], cnt[5] = 1 cnt[7] = 1
3) 6 is printed. Cache = [5 ,7], cnt[5] = 2 cnt[7] = 1
4) 7 is the least frequently used key so it is removed.
     Cache = [3 ,5] , cnt[5] = 2 cnt[3] =1
5) 7 is not present. So, -1 is printed.
6) 3 is printed. Cache = [3 ,5], cnt[5] = 2 cnt[3] =2
7) 3 and 5 both have the same frequency but 5 is the least recently used so it is removed.
    Cache = [4 ,3] , cnt[4] = 1 cnt[3] =2
8) 5 is not present. So, -1 is printed.
9) 3 is printed. Cache = [3 ,4], cnt[4] = 1 cnt[3] = 3
10) 9 is printed. Cache = [4 ,3], cnt[4] = 2 cnt[3] = 3.

*/


/*approach and editorial

Can we keep the keys sorted first by frequency and then by the timestamp when they were last called on?

We can store the keys in a set with a pair { frequency ,timestamp} such that the least frequent key is on the top and if there are multiple keys then the least recently used key is on the top.

We use a map to store the values of the keys. The frequency of the keys and the last timestamp at which they were used also need to be stored. To answer queries of type 2, the keys need to be sorted by frequency and then by the last timestamp when they were used. To do this we insert the keys into a set with the pair {frequency ,timestamp} so that the keys are sorted by frequency and things having the same frequency are sorted according to the last timestamp when they were called on.
To answer queries of type 1, we just print the value of the key if it is present and update the frequency and timestamp of the key.
For type 2 queries, if the key is present the value, timestamp and  frequency of the key are updated. If the key is not present, the key is inserted into the cache.
If the cache had reached its limit, the key present at the beginning of the set is erased.
This problem can also be solved in O(1) per query using the list container in C++ STL (doubly linked-lists) which allows faster insertion and deletion. We store buckets of frequency where each bucket stores all the keys having that frequency. We also have to store the location (iterator in C++) in the bucket for each key so that we can delete the keys in O(1). When we use a key we delete it from its previous bucket and insert the key into the new bucket.
Since things are added sequentially at the end of each bucket, the Least Recently used key will always be at the front of the bucket. So we can delete the first element of the minimum frequency bucket.

class LFUCache {
public:

    int siz = 0;
    int min_freq;
    int capacity;
    unordered_map <int, pair<int, int>> cache; //key to {value,freq};
    unordered_map <int, list<int>::iterator> freqIter; //key to list iterator;
    unordered_map <int, list<int>>  freq;  //freq to key list;

    LFUCache(int n) {
        capacity = n;
    }

    int get(int key) {
        if (cache.count(key) == 0) {
            return -1;
        }
        else {
            freq[cache[key].second].erase(freqIter[key]);
            cache[key].second++;
            freq[cache[key].second].push_back(key);
            freqIter[key] = --freq[cache[key].second].end();
            if (freq[min_freq].size() == 0)
                min_freq++;
            return cache[key].first;
        }
    }

    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            freq[cache[key].second].erase(freqIter[key]);
            cache[key].second++;
            freq[cache[key].second].push_back(key);
            freqIter[key] = --freq[cache[key].second].end();
            if (freq[min_freq].size() == 0)
                min_freq++;
            cache[key].first = value;

        }
        else {
            if (siz == capacity) {
                cache.erase(freq[min_freq].front());
                freqIter.erase(freq[min_freq].front());
                freq[min_freq].pop_front();
                siz--;
            }
            cache[key] = {value, 1};
            freq[1].push_back(key);
            freqIter[key] = --freq[1].end();
            min_freq = 1;
            siz++;
        }
    }

};

*/

//arsh agarwal's code:
#include <bits/stdc++.h>
using namespace std;

class LFUCache {
public:
	int tot;
	map<int, int> mp, freq, time;
	set<pair<int, pair<int, int>>> cache;
	int cntr = 0;
	LFUCache(int n) {
		tot = n;
	}

	void pr(){
		for(auto it: cache) cout << it.first << ' ' << it.second.first << ' ' << it.second.second << '\n';
	}

	int get(int key) {
		cntr++;
		if(mp.find(key)==mp.end()) return -1;
		cache.erase(make_pair(freq[key], make_pair(time[key], key)));
		freq[key]++; time[key]=cntr;
		cache.insert(make_pair(freq[key], make_pair(time[key], key)));
		//pr();
		return mp[key];
	}

	void put(int key, int val) {
		cntr++;

		if(mp.find(key)==mp.end()){

			if(mp.size()<tot){
				mp[key]=val;
				time[key]=cntr;
				freq[key]=1;
				cache.insert(make_pair(1, make_pair(cntr, key)));
				return;
			}

			int temp = (*cache.begin()).second.second;
			//remove lfu
			cache.erase(cache.begin());
			mp.erase(temp), freq[temp]=0, time[temp]=-1;
			//insert new
			mp[key]=val, freq[key]=1, time[key]=cntr;
			cache.insert(make_pair(1, make_pair(cntr, key)));
		}else{
			mp[key]=val;
			cache.erase(make_pair(freq[key], make_pair(time[key], key)));
			freq[key]++; time[key]=cntr;
			cache.insert(make_pair(freq[key], make_pair(cntr, key)));
		}
	}

};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, q;
	cin >> n >> q;
	LFUCache* obj = new LFUCache(n);
	while (q--) {
		string op;
		cin >> op;
		if (op == "get") {
			int key;
			cin >> key;
			cout << obj->get(key) << "\n";
		}
		else if (op == "put") {
			int key, value;
			cin >> key >> value;
			obj->put(key, value);
		}
	}
}

// aryan goyanka's code:
#include <bits/stdc++.h>
using namespace std;

class LFUCache {
public:
	unordered_map <int, pair<int, int> > cache; // key : value, freq
    unordered_map <int, list<int> > freq_keys;  // freq : list of keys
    unordered_map <int, list<int>::iterator> iter_map;  // key : iterator of list

    int lfu = 0;
    int size;


	LFUCache(int n) {
        size = n;

		cache.clear();
        freq_keys.clear();
        iter_map.clear();
        lfu = 0;
	}
    
    void update(int key){
        int freq_temp = cache[key].second++;
        freq_keys[freq_temp].erase(iter_map[key]);

        if(lfu == freq_temp){
            if(freq_keys[freq_temp].empty()){
                lfu++;
            }
        }

        freq_temp++;
        freq_keys[freq_temp].push_back(key);

        iter_map[key] = --(freq_keys[freq_temp].end());        
    }

	int get(int key) {
        if(!cache.count(key)){
            return -1;
        }

        update(key);
		return (cache[key].first);
	}

	void put(int key, int value) {
        if(cache.count(key)){
            cache[key].first = value;
            update(key);
            return;
        }

		if(cache.size() == size){
            int key_remove = freq_keys[lfu].front();

            cache.erase(key_remove);
            freq_keys[lfu].erase(iter_map[key_remove]);
            iter_map.erase(key);
        }
        cache[key] = {value, 1};
        freq_keys[1].push_back(key);

        iter_map[key] = --(freq_keys[1].end());
        lfu = 1;
	}

};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, q;
	cin >> n >> q;
	LFUCache* obj = new LFUCache(n);
	while (q--) {
		string op;
		cin >> op;
		if (op == "get") {
			int key;
			cin >> key;
			cout << obj->get(key) << "\n";
		}
		else if (op == "put") {
			int key, value;
			cin >> key >> value;
			obj->put(key, value);
		}
	}
}


/* All One

    Time-Limit: 1 sec Score: 0.00/100

Difficulty :*****

    Memory: 256 MB Accepted Submissions: 100

Relevant For:

Description

Design the following data structure.

Implement the AllOne class:

    AllOne() Initializes the object of the data structure.
    inc(String key) Increments the count of the string key by 1. If the key does not exist in the data structure, insert it with count 1.
    dec(String key) Decrements the count of the string key by 1. If the count of the key is 0 after the decrement, remove it from the data structure. It is guaranteed that a key exists in the data structure before the decrement.
    getMaxKey() Returns the key with the maximal count. If there are multiple keys with the maximal count, then return the lexicographically largest key. If no element exists, return an empty string "".
    getMinKey() Returns the key with the minimal count. If there are multiple keys with minimal count, then return the lexicographically largest key. If no element exists, return an empty string "".

Input Format

The first line contains Q - the number of queries.
Each of the next Q lines contains the query of one of the types mentioned in the problem statement.

Constraints

1 ≤ Q ≤ 105
1 ≤ |key| ≤ 20
Sample Input 1

7
inc hello
inc hello
getMaxKey
getMinKey
inc bye
getMaxKey
getMinKey

Sample Output 1

hello
hello
hello
bye


*/
//approach and editorial code:
/*We maintain two maps.

    m_key: Stores key → frequency data.
    m_freq: Stores frequency → keys data.

It may be possible that there are multiple keys with the same frequency. So our m_freq is storing a set of strings for the same frequency.

    inc key : Delete key from mfreq from older frequency value. Update frequency in mkey. And update mfreq as well for this new frequency.
    dec key : Delete key from mfreq from older frequency value. Update frequency in mkey. And update mfreq as well for this new frequency. If new frequency is 0, then we don't need to update mfreq and mkey.
    getMaxKey : Find the maximum frequency from mfreq, and using rbegin operation on the set find the lexicographically largest string. 
    getMinKey : Find the minimum frequency from mfreq, and using rbegin operation on the set find the lexicographically largest string. 

All operations are logarithmic to the size of the map in time.

class AllOne
{
public:

    map&lt;string, int&gt; m_key;
    map&lt;int, set&lt;string&gt;&gt; m_freq;

    AllOne() {

    }

    void inc(string key) {

        if (m_key.find(key) != m_key.end()) {
            int val = m_key[key];
            m_freq[val].erase(key);
            if (m_freq[val].empty()) m_freq.erase(val);
        }

        m_key[key]++;

        int val = m_key[key];

        m_freq[val].insert(key);
    }

    void dec(string key) {

        if (m_key.find(key) != m_key.end()) {
            int val = m_key[key];
            m_freq[val].erase(key);
            if (m_freq[val].empty()) m_freq.erase(val);
        }

        m_key[key]--;

        int val = m_key[key];

        if (!val) m_key.erase(key);
        else m_freq[val].insert(key);
    }

    string getMaxKey() {
        if (m_key.empty()) return "";
        int max_freq = (*m_freq.rbegin()).first;
        return (*m_freq[max_freq].rbegin());
    }

    string getMinKey() {
        if (m_key.empty()) return "";
        int min_freq = (*m_freq.begin()).first;
        return (*m_freq[min_freq].rbegin());
    } 

};

*/
//arsh agarwal's code :

#include <bits/stdc++.h>
using namespace std;

class AllOne
{
public:

	struct cmp {
		bool operator() (const pair<int, string>& a, const pair<int, string>& b) const {
			if(a.first==b.first) return a.second<b.second;
			return a.first>b.first;
		}
	};

	map<string, int> mp;
	multiset<pair<int,string>> maxis;
	multiset<pair<int,string>, cmp> minis;

	AllOne() {

	}

	void inc(string key) {
		mp[key]++;
		if(mp[key]!=1) maxis.erase({mp[key]-1, key}), minis.erase({mp[key]-1, key});
		maxis.insert({mp[key], key}), minis.insert({mp[key], key});
	}

	void dec(string key) {
		mp[key]--;
		maxis.erase({mp[key]+1, key}), minis.erase({mp[key]+1, key});
		if(mp[key]!=0) maxis.insert({mp[key], key}), minis.insert({mp[key], key});
	}

	string getMaxKey() {
		if(maxis.empty()) return "";
		return (*maxis.rbegin()).second;
	}

	string getMinKey() {
		if(minis.empty()) return "";
		return (*minis.rbegin()).second;
	}
};

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	int Q;
	cin >> Q;
	
	AllOne allOne;

	while (Q--)
	{
		string op;
		cin >> op;

		if (op == "inc") {
			string key;
			cin >> key;

			allOne.inc(key);
		}
		else if (op == "dec") {
			string key;
			cin >> key;

			allOne.dec(key);
		}
		else if (op == "getMaxKey") {
			cout << allOne.getMaxKey() << "\n";
		}
		else if (op == "getMinKey") {
			cout << allOne.getMinKey() << "\n";
		}
	}

	return 0;
}

/* Search Suggestions System

    Time-Limit: 2 sec Score: 0.00/100

Difficulty :*****

    Memory: 256 MB Accepted Submissions: 100

Relevant For:201

Description

Given an array of string products and a string searchWord. We want to design a system that suggests at most three product names from products after searchWord is typed. Suggested products should have a common prefix with the searchWord. If there are more than three products with a common prefix return the three lexicographically minimums products.

Return a list of lists of the suggested products after searchWord is typed. 

Input Format

The first line of input contains N - the number of products.
The second line contains product names separated by space.
The third line of input contains Q - the number of queries.
The next Q lines queries contain searchWord.

Constraints

1 ≤ N ≤ 103
1 ≤ Q ≤ 103
1 ≤ |product_name|, |searchWord| ≤ 103
It's guaranteed that all product names are unique.
Sample Input 1

6
mobile mouse moneypot monitor mousepad mango
3
m
mous
mo

Sample Output 1

mango mobile moneypot
mouse mousepad
mobile moneypot monitor


*/
/*approach and editorial*/

/*Brute force is a good choice because the length of the string is ≤ 1000. But how to do an effective search?

Use Trie data structure to store the best three matchings. Traverse the Trie.

Whenever we come across questions with multiple strings, it is best to think if Trie can help us. What we need here is a way to search for all the words with the given prefix, this is a well-known problem that trie can solve. The question also asks for sorted results, if you look closely a trie word is represented by its preorder traversal. It is also worth noting that a preorder traversal of a trie will always result in a sorted traversal of results, thus all we need to do is limit the word traversal to 3.

class SearchSuggestionSystem
{
private:
    struct TrieNode
    {
        bool isEnd;
        struct TrieNode *child[26];

        TrieNode()
        {
            isEnd = false;
            for (int i = 0; i < 26; i++)
                child[i] = nullptr;
        }
    };

    TrieNode *trieRoot;

    void insert(string &word)
    {
        TrieNode *temp = trieRoot;

        for (int i = 0; i < (int)word.length(); i++)
        {
            int x = word[i] - 'a';
            if (temp->child[x] == nullptr)
            {
                TrieNode *newNode = new TrieNode;
                temp->child[x] = newNode;
            }
            temp = temp->child[x];
        }

        temp->isEnd = true;
    }

    void dfs(TrieNode *curNode, string &curString, vector<string> &ans)
    {
        if (curNode == nullptr)
            return;

        if (curNode->isEnd)
            ans.push_back(curString);

        if ((int)ans.size() == 3)
            return;

        for (int i = 0; i < 26; i++)
        {
            if (curNode->child[i])
            {
                curString.push_back('a' + i);
                dfs(curNode->child[i], curString, ans);
                curString.pop_back();

                if ((int)ans.size() == 3)
                    break;
            }
        }
    }

public:
    SearchSuggestionSystem(vector<string> products)
    {
        trieRoot = new TrieNode;

        for (string productName : products)
            insert(productName);
    }

    vector<string> suggestProducts(string searchWord)
    {
        TrieNode *curNode = trieRoot;
        vector<string> ans;

        for (int i = 0; i < (int)searchWord.length(); i++)
        {
            int x = searchWord[i] - 'a';

            if (curNode->child[x] == nullptr)
                return ans;

            curNode = curNode->child[x];
        }

        dfs(curNode, searchWord, ans);

        return ans;
    }
};

*/

#include <bits/stdc++.h>
using namespace std;

class SearchSuggestionSystem
{
public:
    
    struct Node{
      	Node* child[26];
        bool end;
        Node(){for(int i = 0; i < 26; i++) child[i]=nullptr, end = false;}
    };
    
    struct Trie{
      	Node* root;
        Trie(){root = new Node();}
        vector<string> ans;
		string cur;

		void insert(string s){
			Node* temp = root;
			for(auto it: s){
				if(temp->child[it-'a']==nullptr) temp->child[it-'a']=new Node();
				temp = temp->child[it-'a'];
			}
			temp->end = true;
			return;
		}

		void rec(Node* temp){
			if(temp==nullptr) return;
			if(temp->end) ans.push_back(cur);
			for(int i = 0; i < 26; i++){
				if(ans.size()>=3) return;
				cur += char('a'+i);
				rec(temp->child[i]);
				cur.pop_back();
			}
		}
        
        vector<string> search(string s){
            ans.clear();
            Node* temp = root;
            for(auto it: s){
                if(temp->child[it-'a']==nullptr) return vector<string>();
				temp = temp->child[it-'a'];
            }
			cur = s;
			rec(temp);
			return ans;
        }
    };
    
	Trie trie;
    SearchSuggestionSystem(vector<string> products)
    {
		trie = Trie();
        for(auto it: products) trie.insert(it);
    }

    vector<string> suggestProducts(string searchWord)
    {
        return trie.search(searchWord);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<string> products;

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        products.push_back(s);
    }

    SearchSuggestionSystem searchSuggestionSystem(products);

    int q;
    cin >> q;

    while (q--)
    {
        string searchWord;
        cin >> searchWord;

        vector<string> ans = searchSuggestionSystem.suggestProducts(searchWord);

        for (string s : ans)
            cout << s << " ";
        cout << "\n";
    }

    return 0;
}

//priority queue
/*https://www.youtube.com/watch?v=onlhnHpGgC4
https://youtu.be/WCm3TqScBM8
https://youtu.be/MiyLo8adrWw
https://youtu.be/-WEku8ZnynU*/