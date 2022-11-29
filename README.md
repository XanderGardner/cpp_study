# Table of Contents
- [basics](basics.md)
- data structures
  1. [string](#string)
  1. [struct](#struct)
  1. [vector](#vector)
  1. [array](#array)
  1. [forward list](#forward-list)
  1. [stack](#stack)
  1. [pair](#pair)
  1. [list](#list)
  1. [queue](#queue)
  1. [priority queue](#priority-queue)
  1. [set](#set)
  1. [unordered set](#unordered-set)
  1. [multiset](#multiset)
- algorithms
  1. [sorting](#sorting)
  1. [searching](#searching)
  1. [useful](#useful)
- tricks
- [todo](#todo)

---

# string
- objects allocated dynamically and slower than char arrays
- `std::string` object
```cpp
// create string
string s = getline(); // store stream of characters from user
s.push_back('a'); // character at end of string
s.pop_back(); // delete last character from string
```
- length is number elements vs size/capactity is how many it can hold vs more allocation
- `capactiy()`, `resize()`, `length()`, `shrink_to_fit()`
- iterator functions return iterators: `begin()` `end()` and the reverse are `rbegin()` `rend()`
```cpp
string::iterator i;
for (i = s.begin(); i != s.end(); i++)
  cout << endl;
```
```cpp
// copying
string a = "abc";
string c(a, 2, 1); // copy of length 2 starting position 1
char b[80];
a.copy(b, 2, 1); // copy of length 2 starting position 1
```
```cpp
s.clear(); // delete all characters
char ch = s[2]; // access
char cb = s.front(); // s[0]
char ce = s.back(); // s[s.length() - 1]
s.append("more"); // append to end
const char* chstr = s.c_str(); // string to char array
int a = s1.find(s2); // returns -1 or string::npos if not found
a = b.substr(2,3); // substring starting 2, length 3
b.erase(2,3); // deletes chars starting 2, length 3
b.replace(2,3,"hit"); // replaces
```
```cpp
// \nhi
string a = R"(\nhi)"; // raw string literal ignores escape characters
```
splitting string by token using `strtok`
```cpp
string s = "asd,dff,cs";
p = strtok(s, ",");

while (p != NULL) {
  cout << p << endl;
  // strtok will replace s with NULL along way to keep track
  p = strtok(NULL, ","); 
}
```
get last occurance of character in string
```cpp
size_t a = s.find_last_of(","); // s.substr(a+1) is what remains
```
stringstream to read by seperators
```cpp
#include <sstream>
stringstream s(str);
string word;
while (s >> word)
    // now you have word by word
```
a string is a stack
```cpp
string a = "ab";
a.push_back("c");
a.back(); // just look
a.pop_back();
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
vector<int> a;
a = {1,2,3}; // vector<int> a{1,2,3};
// .empty() .size() .emplace()
a[2];
a[1] = 2;
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
forward_list<int> a;
a = {1,2,3};
// .push_front() .pop_front() .insert_after() .remove_if()
*++a.begin(); // second element
```

# stack
- basic stack
```cpp
#include <stack>
stack<int> a;
// .empty() .size()
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
queue<int> q;
q.push(10); // add to back
q.pop(); // remove from front
q.empty(); // if empty
q.size();
q.front(); // see front
q.back(); // see back
```

# priority queue
default is max on top
```cpp
#include <queue>
priority_queue<int> g;
g.push(10);
g.top(); // look only
g.pop(); // pop top
g.empty(); // if empty
g.size();

// create min on top
priority_queue<int, vector<int>, greater<int>> p;
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
unordered_set<int, greater<int>> b;
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
unordered_multiset<int, greater<int>> b;
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
unordered_map<int, int, greater<int>> b;
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
unordered_multimap<int, int, greater<int>> b;
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
- uses quicksort, (heapsort if bad partitionings happen), then insertion sort once smaller
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
    
- important stl algorthms
- useful array algorithms
- partition operations
- valarray class
    
# useful
Vector
```cpp
#include <algorithm>
reverse(a.begin(), a.end()); // reverses
*max_element(a.begin(), a.end()); // (pointer to) max
distance(a.begin(), max_element(a.begin(), a.end())); // index max
*min_element(a.begin(), a.end()); // (pointer to) min
distance(a.begin(), max_element(a.begin(), a.end())); // index min
accumulate(a.begin(), a.end(), 0); // sum all and 0
count(a.begin(), a.end(), 5); // number occurances of 5
find(a.begin(), a.end(), 5); // iterator to first occurance of 5 or a.end() if not found
unique(a.begin(), a.end()); // keeps only unique but doesn't resize, returns pointer to new end
a.erase(unique(a.begin(),a.end()),a.end()); // keeps only unique
```
Array
```cpp
all_of(a, ar+6, [](int x) { return x>0; }); // bool if all positive
any_of(ar, ar+6, [](int x){ return x<0; }); // bool if any are negative
none_of(ar, ar+6, [](int x){ return x<0; }); // bool if none are negative
copy_n(a, 6, b); // deep copies a to b (all 6 elements)
iota(ar, ar+6, 20); // array becomes 20 21 22 23 24 25
```
Partition (vector)
```cpp
is_partitioned(vect.begin(), vect.end(), [](int x) { return x%2==0; }); // bool if partitioned
partition(vect.begin(), vect.end(), [](int x) { return x%2==0; }) // 2 3 4 3 7 9, partitions
// stable_partition(...) preserves order
// partition_point(...) iterator to first element with false property
```

# todo
- https://www.geeksforgeeks.org/bit-tricks-competitive-programming/?ref=lbp
- functors (find video to learn)
