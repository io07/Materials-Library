/*
Vocabulary:
reloaded operation
priority queue
pruning
quick_sort
bubble_sort
index
strategy
greedy
dynamic programming
traverse
inorder traverse (left, root, right)
preorder traverse (root, left, right)
postorder traverse(left, right, root)
structure
father / son / previous node / next node
partition operation
the binary tree
maximum
minimum
linked list
pointer
object
tbe best situation
the worst situation
expection
loop
expection
heap
trie tree
sequenece and string
hash algorithm
recurse
recursion formula
recursive
linear time
linear time sorting
backtrace
backtracing method
two pointers method
string
variable
pass by copy
pass by reference
legal
bottom
edge case
address of operator
minus
maintain
make sure
keep
original value
carefulness
section
state equations
 initialized to 0
 preparing data
 subscript
 question mark
 monotonous queue
 parentheses
 parenthesis
 */
#inlcude <algorithm>
/
void map(){
    unordered_map<key, value> mp;
    map<key, value> mp;
    // the default value of mp is 0
    mp[key] = value;
    mp.count(key);
    mp.empty();
    mp.find(key) != mp.end();
    mp.insert(key);
    /*enumerate the value*/
    map<key, value> :: iterator = it;
    for (it = mp.begin(); it != mp.end(); ++it){
        key = it->first;
        value = it->second;     
    }
    for (auto i : mp){
        key = i.first;
        value = i.second;
    }
    mp.size();
}
void set(){
    set<int> ss;
    ss.begin();
    ss.end();
    ss.count();
    ss.erase(iterator);
    ss.find(iterator);
    ss.lower_bound();
    ss.upper_bound();
    ss.size();
	ss.insert();
	unordered_set<string> ss;
}
void queue(){
    queue<int> que;
    que.push();
    que.pop();
    que.front();
    que.size();
    que.empty();
    priority_queue<int> que;
	que.top(); // to get the first number
	
	stack<int> stk;
	stk.push();
	stk.pop();
	stk.top();
	stk.size();
	stk.empty();
}
void string(){
    //string -> float
    float aa = atof("1.2");
    int aa = atoi("1");
    long long atol = atol("1");

    str.append("12345");
    int aa = atoi(str.c_str());

    string:: npos is the largest number of size_t;
    size_t pos = str.find("hehe");
    reverse(str.begin(), str.end());
    str.back();
    str.push_back();
    str.pop_back();
    str.end();
    str.substr(index, length);
    to_string;
    stoi;
    stol;
    stoull;
    stoll;
    '-' is an int;
    "--`" is a string;
    /* split the string by using p*/
    stringstream ss(Original_String);
    vector<string> res;
    while(getline(ss, tmp, '/')){
        res.push_back(tmp); // steady
    }
}
void vector(int n, int m){
    vector<vector<int> > a(n);
    for (int i = 0; i < n; i++){
        a[i].resize(m, 0)
    }
    a.push_back();
    a.back();
    vector.at(i);
    a.clear();
    vector.erase(iterator);
    vector.insert(iterator, val);
    vector.insert(iterator, n, val);
    vector.pop_back();
}
void stl(){
    int index_x = lower_bound(v.begin(), v.end(), key) - v.begin();
    int index_y = upper_bound(v.begin(), v.end(), key) - v.begin();
    std::pair<std::vector<int>::iterator, std::vector<int>::iterator> bounds;
    sort(v.begin(), v.end(), cmp);
    bounds = std::equal_range(v.begin(), v.end(), 20);
    int L = bounds.first - v.begin();
    int R = bounds.second - v.end();
    // Pay attention that the range is [, )
    // Delete the duplicates, unique return the first duplicate
    it = unique(v.begin(), v.end());
    v.resize(distance(v.begin(), it));
    // C++ can use rand() to return an rand value
}
/*
 Somethings to remember to remember:
 ask for the edge case, zero, the maximum int, negtative number
 dfs now is great enough!
 */

/*LeetCode 10. Regular Expression Matching
    P[i][j] = true | false // s[0 .. i] match p[0 .. j]
    * is binded with the previous letter
    // recursion rules:
        1. P[i][j] = P[i-1][j-1] if s[i] == p[j] or (s[i] == '.' or s[j] == '.')
        2. p[j] == '*':
            dp[i][j] = dp[i][j-2] // a* is empty
            dp[i][j] = dp[i][j-1] // a* is once
            dp[i][j] = dp[i-1][j] // a* is multiple, so use this formula to recurse
        the above is the entire situation
        res = P[n-1][m-1]

 */
class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();
        vector<vector<bool> > dp(n+1, vector<bool> (m+1, false));
        dp[0][0] = true;
        /*
            why i start with 0 not 1
            n == 0, m != 0 maybe true
            but n != 0, m == 0 must be false
        */
        for (int i = 0; i <= n; i++)
            for (int j = 1; j <= m; j++){
                bool f = dp[i][j];
                if (i > 0 && (s[i-1] == p[j-1] || p[j-1] == '.'))
                    f = f | dp[i-1][j-1];
                if (p[j-1] == '*'){
                    if (j >= 2)
                        f = f | dp[i][j-2];
                    if (i > 0 && (s[i-1] == p[j-2] || p[j-2] == '.')){ // here is j-2
                        f = f | dp[i][j-1] | dp[i-1][j];
                    }
                }
                dp[i][j] = f;
            }
        return dp[n][m];
    }
};
void two_dimensional_vector(int n, int m){
    vector<vector<int>> dp(n);
    for (int i = 0; i < n; i++)
        dp[i].resize(m);
    vector<vector<bool> > dp(m + 1, vector<bool> (n + 1, false));
}

/*
   serialization
   deserialization
   I can use this two flag
    @param
    @return
    the a[i]'s son left son is i*2 + 1 and i*2 + 2
    traverse method called pre-order traverse
    stoi function convert the string to int
    the wall number and comma, seperator
    return nullptr means the null pointer, NULL 
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    TreeNode* buildtree(string &str){
        size_t pos = str.find(',');
        string val = str.substr(0, pos);
        str = str.substr(pos+1, str.length() - pos - 1);
        if (val == "#"){
            return nullptr;
        }
        else{
            TreeNode* root = new TreeNode(stoi(val));
            root->left = buildtree(str);
            root->right = buildtree(str);
            return root;
        }
    }
    void buildstring(TreeNode* root, string & path){
        if (root){
            path = path + to_string(root->val) + ",";
            buildstring(root->left, path);
            buildstring(root->right, path);
            return;
        }
        else{
            path = path + "#,";
            return;
        }
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res = "";
        buildstring(root, res);
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode* root = buildtree(data);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

/*
   TreeNode* res;
   res != nullptr;
 */

/*
    for dfs, the you must figure out all possible transfers
 */

/*
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/*
	@param
	@return
*/
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        
    }
};
/*
	priority_queue default to launch the maximum value
	priority_queue<int, vector<int>, greater<int> > que; // launch the minimum value
	To use struct:
struct node
{
	friend bool operator < (node n1, node n2)
	{
		return n1 < n2;
	}
	int priority;
	int value;
}
struct cmp1{
	bool operator () (int &a, int &b){
		return a > b; 
	
	}
}
    priority_queue<int, vector<int>, cmp1> sdsd;

*/

// Disjoin Set
int fa[maxn];
int rank[maxn];

void init(int n){
    for (int i = 0; i < n; i++){
        fa[i] = i;
        rank[i] = 1;
    }
}
int get_fa(int x){
    if (x != fa[x])
        return x = get_fa[x]; // path compression
    return x;
}
void union_set(int x, int y){
    x = get_fa[x];
    y = get_fa[y];
    if (x == y)
        return ;
    if (rank[x] < rank[y])
        fa[x] = y;
    else
        fa[y] = x;
}
void is_same(int x, int y){
    return get_fa(x) == get_fa(y);
}


unordered_map<int, queue<int> > mp;

bool isValid(int client, int timestamp){
    if (mp[client].size() < 100){
        mp[client].push(timestamp);
        return true;
    }
    else{
        if (timestamp - mp[client].front() >= 1000){
            mp[client].pop();
            mp[client].push(timestamp);
            return true;
        }
    }
    return false;
}

unordered_map<int, vector<int> > mp;
unordered_map<int, int> > mp_index;

bool isValid(int client, int timestamp){
    if (mp[client].size() < 100){
        mp_index[client] = mp[client].size();
        mp[client].push_back(timestamp);
        return true;
    }
    else{
        int index = mp_index[client];
        if (timestamp - mp[client][index] >= 1000){
            mp[client][index] = timestamp;
            mp_index[client] = (index + 1) % 100;
            return true;
        }
    }
    return false;
}


