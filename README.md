# Table of Contents

- [basics](basics.md)
- [practice](practice.md)
- stl data structures
  - [string](#string)
  - [struct](#struct)
  - [vector](#vector)
  - [array](#array)
  - [forward list](#forward-list)
  - [stack](#stack)
  - [pair](#pair)
  - [list](#list)
  - [queue](#queue)
  - [priority queue](#priority-queue)
  - [set](#set)
  - [unordered set](#unordered-set)
  - [multiset](#multiset)
- stl algorithms
  - [sorting](#sorting)
  - [searching](#searching)
- implemented
- [todo](#todo)

---

# string
- dynamic array of characters
```cpp
// create
string s = "abcdefg";

// size
s.length();

// read
char ch = s[2];

// as stack
a.back()
a.front()
s.push_back('a');
s.pop_back();

// update
s.append("more");
s[2] = 'c';
b.replace(2,3,"hit"); // replace charts starting 2, length 3 with "hit"
transform(s.begin(), s.end(), s.begin(), [](auto c) { return toupper(c); }); // to uppercase

// delete
s.clear();
a.erase(2,3); // deletes chars starting 2, length 3

// substrings
string b = a.substr(2,3); // substring starting 2, length 3
string b = a.substr(2);   // substring starting 2, to end
size_t pos = a.find("bcd"); // returns string::npos if not found
size_t a = s.find_last_of(",");
```

- splitting string by token using stringstream
```cpp
#include <sstream>

string input = "abc,def,ghi";
istringstream ss(input);
string token;

while(std::getline(ss, token, ',')) {
    std::cout << token << '\n';
}
```

# struct
- multiple variables in one container
```cpp
struct name { // This structure is named "myDataType"
  int num;
  string str;
};
name var_name;
var_name.num = 5;
```

# vector
- resizing array
```cpp
#include <vector>

// create
vector<int> a = {1,2,3};

// size
a.size()
a.empty()

// access
a[2];
a[1] = 2;

// insert (emplace is inplace efficient inserting)
a.emplace(vec.begin(), 5); // {5,1,2,3}
a.emplace(vec.end()-1, 5); // {1,2,5,3}
```

- vector algorithms
```cpp
#include <algorithm>

// reverse
reverse(a.begin(), a.end());

// min and max
*max_element(a.begin(), a.end()); // (pointer to) max
distance(a.begin(), max_element(a.begin(), a.end())); // index max
*min_element(a.begin(), a.end()); // (pointer to) min
distance(a.begin(), max_element(a.begin(), a.end())); // index min

// sum
accumulate(a.begin(), a.end(), 0); // sum all and 0

// count
count(a.begin(), a.end(), 5); // number occurances of 5

// find
find(a.begin(), a.end(), 5); // iterator to first occurance of 5 or a.end() if not found

// get unique
unique(a.begin(), a.end()); // keeps only unique but doesn't resize, returns pointer to new end
a.erase(unique(a.begin(),a.end()),a.end()); // keeps only unique
```

- functional tools
```cpp
// transform (like map): apply to each element of a vector
vector<int> out;
transform(v.begin(), v.end(), back_inserter(out), f);

// filter: get vector of only valid elements
vector<int> out;
copy_if(v.begin(), v.end(), back_inserter(out), [](int i){return i>=0;} );
```

Partition (vector)
```cpp
is_partitioned(vect.begin(), vect.end(), [](int x) { return x%2==0; }); // bool if partitioned
partition(vect.begin(), vect.end(), [](int x) { return x%2==0; }) // 2 3 4 3 7 9, partitions
// stable_partition(...) preserves order
// partition_point(...) iterator to first element with false property
```

# array
- basic array that holds its own size
```cpp
array<int,6> a = {1,2,3}; // 1,2,3,0,0,0
```

# forward list
- singly linked list
```cpp
#include <forward_list>

forward_list<int> a = {1,2,3};
// .push_front() .pop_front() .insert_after() .remove_if()
*++a.begin(); // second element
```

# stack
- basic stack
```cpp
#include <stack>

// create
stack<int> a;

// size
a.empty() 
a.size()

// operations
a.push(3);
a.top(); // just look
a.pop();
```

# pair
tuple
```cpp
#include <utility>
pair<int, char> p;
p.first = 100;
p.second = 'g';
pair<int, char> p(1, 'a');
pair<int, char> p(p1); // copy of p1
p = {1, 'a'};
```

# list
double linked list
```cpp
#include <iterator>
#include <list>
list<int> l;
// make list
for (int i=0; i<10; ++i) {
  l.push_back(i); // .pop_back() to remove .back() to see
  l.push_front(i); // .pop_front() to remove, .front() to see
}
// traverse list
list<int>::iterator it;
for (it = l.begin(); it != l.end(); ++it) {
    cout << *it;
}
l.sort(); // sort
l.reverse(); // reverse
l.empty(); // if empty
l.size(); // size
l.insert(pos_iter, how_many, ele); // insert
l.erase(pos_iter_first, pos_iter_last)
// remove() removes elements
// remove_if() removes if results in true
```

# queue
```cpp
#include <queue>

// create
queue<int> q;

// size
q.empty();
q.size();

// operations
q.push(10);
q.pop(); // remove from front
q.front();
q.back();
```

# priority queue
default is max on top
```cpp
#include <queue>

// create
priority_queue<int> g;
priority_queue<int, vector<int>, greater<int>> p; // min on top

// size
g.empty();
g.size();

// operations
g.push(10);
g.top(); // look only
g.pop(); // pop top
```

# set
- sorted, unique elements (binary search tree)
- iterating over set is in order
```cpp
#include <set>

// create
set<int> a;
set<int, greater<int>> b;
vector<int> v({ 1, 2, 3});
set<int> d(v.begin(), v.end());
set<int> e = {3, 2, 5};

// size
a.size();
a.empty();

// insert
a.insert(1); 

// read
a.count(5); // 1 or 0 for set

// remove
a.erase(10);
a.clear();
```

# unordered set
- not sorted, unique elements (hashing)
```cpp
#include <unordered_set>

// create
unordered_set<int> a;
vector<int> v({ 1, 2, 3});
unordered_set<int> d(v.begin(), v.end());
unordered_set<int> e = {3, 2, 5};

// size
a.size();
a.empty();

// insert
a.insert(1); 

// read
a.count(5); // 1 or 0 for set

// remove
a.erase(10);
a.clear();
```

# multiset
- sorted, not unique elements (red-black tree)
- iterating over set is in order
```cpp
#include <set>

// create
multiset<int> a;
multiset<int, greater<int>> b;
vector<int> v({ 1, 2, 2, 3});
multiset<int> d(v.begin(), v.end());
multiset<int> e = {3, 2, 2, 5};

// size
a.size();
a.empty();

// insert
a.insert(1); 
a.insert({1,2,3}) // insert multiple
a.insert(v.begin(), v.end())

// read
a.count(5);

// remove
a.erase(10); //removes all instances
a.erase(a.find(1)); //removes one instance
a.clear();
```

# unordered multiset
- not sorted, not unique elements (hashing)
```cpp
#include <unordered_set>

// create
unordered_multiset<int> a;
vector<int> v({ 1, 2, 2, 3});
unordered_multiset<int> d(v.begin(), v.end());
unordered_multiset<int> e = {3, 2, 2, 5};

// size
a.size();
a.empty();

// insert
a.insert(1); 
a.insert({1,2,3}) // insert multiple
a.insert(v.begin(), v.end())

// read
a.count(5);

// remove
a.erase(10); //removes all instances
a.erase(a.find(1)); //removes one instance
a.clear();
```

# map
- sorted, unique keys in key-value pairs (binary search tree)
- iterating over map has keys in order
```cpp
#include <map>

// create
map<int, int> a;
map<int, int, greater<int>> b;
vector<pair<int,int>> v({{1,2}, {2,3}, {3,2}});
map<int, int> d(v.begin(), v.end());
map<int, int> e = {{1,2}, {2,3}};

// size
a.size();
a.empty();

// insert
a[2] = 3;
a.insert({{1,2},{2,3}}); // insert multiple
a.insert(v.begin(), v.end());

// read
a[2];

// remove
a.erase(2); 
a.clear();

// iterating
for (auto i : a) {
    cout << i.first << ' ' << i.second;
}
```

# unordered map
- not sorted, unique keys in key-value pairs (hashing)
```cpp
#include <unordered_map>

// create
unordered_map<int, int> a;
vector<pair<int,int>> v({{1,2}, {2,3}, {3,2}});
unordered_map<int, int> d(v.begin(), v.end());
unordered_map<int, int> e = {{1,2}, {2,3}};

// size
a.size();
a.empty();

// insert
a[2] = 3;
a.insert({{1,2},{2,3}}); // insert multiple
a.insert(v.begin(), v.end());

// read
a[2];

// remove
a.erase(2); 
a.clear();

// iterating
for (auto i : a) {
    cout << i.first << ' ' << i.second;
}
```

# multimap
- sorted, not unique keys in key-value pairs (red-black tree)
- iterating over multimap has keys in order
```cpp
#include <map>

// create
multimap<int, int> a;
multimap<int, int, greater<int>> b;
vector<pair<int,int>> v({{1,2}, {2,3}, {3,2}});
multimap<int, int> d(v.begin(), v.end());
multimap<int, int> e = {{1,2}, {2,3}};

// size
a.size();
a.empty();

// insert
a.insert({1,1});
a.insert({{1,2},{2,3}}); // insert multiple
a.insert(v.begin(), v.end());

// read
auto itr = a.equal_range(1);
for (auto i = itr.first; i != itr.second; i++) {
  cout << i.first << ' ' << i.second;
}

// remove
a.erase(2); // erases all pairs with key
a.clear();

// iterating
for (auto i : a) {
    cout << i.first << ' ' << i.second;
}
```

# unordered_multimap
- not sorted, not unique keys in key-value pairs (hashing)
```cpp
#include <unordered_multimap>

// create
unordered_multimap<int, int> a;
vector<pair<int,int>> v({{1,2}, {2,3}, {3,2}});
unordered_multimap<int, int> d(v.begin(), v.end());
unordered_multimap<int, int> e = {{1,2}, {2,3}};

// size
a.size();
a.empty();

// insert
a.insert({1,1});
a.insert({{1,2},{2,3}}); // insert multiple
a.insert(v.begin(), v.end());

// read
auto itr = a.equal_range(1);
for (auto i = itr.first; i != itr.second; i++) {
  cout << i.first << ' ' << i.second;
}

// remove
a.erase(2); // erases all pairs with key
a.clear();

// iterating
for (auto i : a) {
    cout << i.first << ' ' << i.second;
}
```

# sorting
- uses quicksort, (heapsort if bad partitionings happens), then insertion sort once smaller
- inplace
```cpp
#include <algorithm>

vector<int> a = {3,3,5,3,4};
sort(a.begin(), a.end()); // increasing
sort(a.begin(), a.end(), greater<int>()); // decreasing
sort(a.begin(), a.end(), my_fun()); // using your comparison
```
    
# searching
- binary search
```cpp
#include <algorithm>
binary_search(a.begin(), a.end(), 5); // true or false
lower_bound(a.begin(), a.end(), 5) - a.begin(); // index {1 3 5* 5 6} or {1 6*}
upper_bound(a.begin(), a.end(), 5) - a.begin(); // index {1 3 5 5 6*} or {1 6*}
```
    


# todo
- https://www.geeksforgeeks.org/top-algorithms-and-data-structures-for-competitive-programming/
- functors
- defaultdict
- linked list
- graphs
  - dfs
  - bfs
- dynamic programming
- unions
- trie
- trees
  - dfs
  - bfs
- binary search tree
- AVL tree
- kd trees
- fenwick tree
- segment tree
