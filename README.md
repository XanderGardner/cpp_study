# cpp_study

# Table of Contents
[Basics](#basics)
1. [Compiling](#compiling)
1. [namespace and libraries](#namespace-and-libraries)
1. [Comments](#comments)
1. [Variables](#variables)
    1. [Datatypes](#datatypes)
    1. [Modifiers](#modifiers)
    1. [Min and max values](#min-and-max-values)
    1. [local instance or static](#local-instance-or-static)
1. [Operators](#operators)
    1. [Memory](#memory)
1. [Loops](#loops)
1. [Control](#control)
1. [Input and Output](#input-and-output)
1. [Arrays](#arrays)
1. [Strings](#strings)
1. [Functions](#functions)
1. [Pointers and References](#pointers-and-references)
1. [OOP](#oop)
1. [Exceptions](#exceptions)
1. [STL Algorithms](#stl-algorithms)
1. [STL Containers](#stl-containers)


[TODO](#todo)
1. 

---

# Basics

<blockquote>

## Compiling
- In hello.cpp file
```cpp
#include <iostream>
int main() {
  std::cout << "Hello World!\n";
}
```
- compile with `g++ hello.cpp` in terminal
- specify output file with `g++ hello.cpp -o hello`
- g++ is the GNU C++ Compiler which is a compiler in Linux to compile C++ programs
- gcc is a different compiler, which won't automatically link in the std C++ libraries
- clang in the compiler for mac (g++ will run clang on mac, just get xcode)
- then run with `./hello`
- more on compiling with g++: https://www.geeksforgeeks.org/compiling-with-g-plus-plus/

## namespace and libraries

```cpp
#include <iostream>     // std::cout, cin, cerr
#include <string>       // std::string
#include <cstddef>      // std::size_t

using namespace std;    // now we can do cout instead of std::cout
```

## Comments
```cpp
// one line
/*
multi line
*/
```

## Variables
Example use
```cpp
int score; // declare
int score, score2, score3; // declare multiple
score = 0; // initialize
```
- `sizeof(a)` returns number of bytes

### Datatypes
1. Derived
- Function
- Array
- Pointer
- Reference

2. User Defined
- Class
- Structure
- Union
- Enum
- Typedef

3. Built In
```cpp
int a = 1;        // Interger:  4 bytes -2^31 to 2^31-1
char a = 'a';     // Character: 1 byte (ASCII)
bool a = true;    // Boolean:   1 byte
float a = 4.0;    // Floating Point: 4 bytes
double a = 1.0;   // Double Floating Point: 8 bytes
void;              // means without any value: usually returned
wchar_t a = w'a'; // Wide Character: 2or4 bytes (UNICODE)
```

### Modifiers
Modifiers are signed, unsigned, long, and short
```cpp
long long int a = 1; // 8 bytes
unigned long int a = 1; // 4 bytes
```

### Min and max values
Get max a min values of a type with header file
```cpp
#include <limits.h>
INT_MIN; // int min
INT_MAX; // int max
LLONG_MAX; // long long int max
```

### local instance or static
Variables can be local, instance, or static. Static are like instance variables but only one exist per class no matter how many objects are made.

## Operators
- Unary: ++, --
- Arithmetic: + - * / %
- Relational: <, <=, >, >=, ==, !=
- Logical: &&, ||, !
- Assignment: =, +=, -=, *=, /=, %=
- Bitwise: &, |, <<, >>, ~, ^

Other Operators:
- Casting: (type)
- sizeof(a) returns size_t object w/ num bytes
- comma operator: seperates stuff
- Coniditional: e1 ? e2 : e3
- dot (.) to reference members of classes, strucutres, and unitons
- arrow (->) for pointer to an object
- & for address of variable
- * for pointer to a variable

### Memory:
- malloc(), calloc(), and free() in c become new and delete for heap
- stack: local variables
- heap: static variables, pointers
- instance variables are in where the object is
```cpp
int* p = NULL;
p = new(nothrow) int(25);
if (!p) { // allocation failed
}
delete p; // delete[] p (for array)
```

## Loops

for loop
```cpp
for(int i = 0; i < n; i++) {
  
}
```

while
```cpp
while (i < 6) {
  i++;
}
```

do-while
```cpp
do {
  i++;
} while (i < 6);
```

for-each
```cpp
#include<algorithm>
for_each(arr, arr + 5, function);
```

for-range
```cpp
for (auto i : v)
  std::cout << i << ' ';
for (int i : a)
  std::cout << i << ' ';
```

## Control
```cpp
if(condition)
  statement;
if(condition) {
  statement1;
  statement2;
}

#if else
if(condition) {

} else if (condition) {

} else {

}

switch(exp) {
  case1:
    break;
  case2:
    break;
  default:
}
```
Jump statments are `break;` `continue;` `return 0;` `goto label1;` which will goto the line `label1:`

## Input and Output

```cpp
#include <iostream> // include library iostream
std::cout << "text here"; // print output
std::cin >> variable_name; // read input to variable name (user hits enter)
```
- be more efficient
```cpp
using namespace std;
cout << "My age is " << age << "\n" // chaining output
cout << "done" << endl // endl makes new line and flushes stream
```

Files use `ofstream` `ifstream` or `fstream`. o is for output, i is for input, and the last is for both
```cpp
#include <fstream>

// read
ofstream MyFile("filename.txt");
MyFile << "printing here";
MyFile.close();

// print
string myText;
ifstream MyReadFile("filename.txt");
while (getline (MyReadFile, myText)) {
  cout << myText;
}
MyReadFile.close();
```

Reading input
```cpp
int a;
cin >> a; # reads until the user returns (which is a \n)
cin >> ws; # discards the white space (which is the \n)
string s;
getline(cin, s); # reads line
```

Redirect stdout to file
```cpp
freopen("textfile.txt", "w", stdout); // redirects stdout to testfile
```

Redirecting using buffers
```cpp
#include <fstream>
#include <iostream>
fstream file;
file.open("cout.txt", ios::out);

// Backup streambuffers of  cout
streambuf* stream_buffer_cout = cout.rdbuf();
streambuf* stream_buffer_cin = cin.rdbuf();

// Get the streambuffer of the file
streambuf* stream_buffer_file = file.rdbuf();

// Redirect cout to file
cout.rdbuf(stream_buffer_file);

cout << "This line written to file" << endl;

// Redirect cout back to screen
cout.rdbuf(stream_buffer_cout);
cout << "This line is written to screen" << endl;

file.close();
```    

Throwing an error and writting to stderror
```cpp
cerr << "An error occurred"; // no buffer, meaning no storing the error
clog << "Error occured"; // buffered, meaning flush() needed (or auto flushed at end)
```

## Arrays
- specific length determined and never changed (costly addition/deletion)
- name is pointer to first element of array
- there is NO index out of bounds checking in cpp
```cpp
int a[10]; // whatever is there is there
int a[10] = {}; // initialized to all 0s
int a[10] = {1}; // initialized to all 1s
int a[] = {1, 2, 3};
int b[5][2]; // 5 by 2 matrix
```

## Strings
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

## Functions

The main function may have parameters
```cpp
int main(int argc, char* const argv[])
```

Basic function put above main
```cpp
int max(int x, int y) {
  return x;
}
int max(int x, int y = 0) { // default argument
  return x;
}
```
- Override by changing number of arguments or type
- Use `inline` to remove overhead by replacing code at compile time

## Pointers and References

Pointers
- `datatype *var_name;` or `datatype* var_name;`
- * operator on pointer returns value that it points to
- & operator returns address of variable `&var`
- array notation `nums[1][2]` pointer notation `*(*(nums + 1) + 2)`

References
- an alternative name for an existing varaible `datatype& var_name`
- useful for changing variable outside of function
```cpp
void swap(int& first, int& second) { }
int a = 2, b = 3;
swap(a, b);
```
- useful for changing elements in for each loop (avoids copying too)
```cpp
for (int& x : vect) {
  x = x + 5;
}
```

## OOP
- access specifier can be public, private (client and subclass can't access), or protected (client can't access but subclass can)
```cpp
class Name {
  private: // access specifier
    int a;
  public: 
    Name(int x) { // constructor
      a = x;
    }
    ~Name() { } // default destructor
    void printid() { // function
      cout << "hi";
    }
};
```

Set function outside of class
```cpp
void Person::set_p() {
    cout << "hi";
}
```

Inheritance is private (object cant reach superclass), protected, or public (object can reach superclass)
```cpp
class Student: private person { // private inheritance
```

## Exceptions
throw exception with `throw x;`
```cpp
try {
  fun(NULL, 0);   
} catch(...) {
  cout << "Caught";
}
```

## STL Algorithms
- sorting
- searching
- important stl algorthms
- useful array algorithms
- partition operations
- valarray class

## STL Containers
Not really used are deque, 

### vector
- resizing array
```cpp
#include <vector>
vector<int> a;
a = {1,2,3};
// .empty() .size() .emplace()
a[2];
a[1] = 2;
```

### arrays
- basic array that holds its own size
```cpp
array<int,6> a = {1,2,3}; // 1,2,3,0,0,0
```

### forward list
- singly linked list
```cpp
#include <forward_list>
forward_list<int> a;
a = {1,2,3};
// .push_front() .pop_front() .insert_after() .remove_if()
*++a.begin(); // second element
```

### stack
- basic stack
```cpp
#include <stack>
stack<int> a = {1,2,3};
// .empty() .size()
a.push(3);
a.top(); // just look
a.pop();
```

### pair
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

### list
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

### queue
```cpp
queue<int> q;
q.push(10); // add to back
q.pop(); // remove from front
q.empty(); // if empty
q.size();
q.front(); // see front
q.back(); // see back
```

### priority queue
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

### set
unique elements in sorted order using binary search trees
```cpp
#include <set>
set<int> a;
set<int, greater<int>> b;
a.insert(1); // O(logN)
// iters: begin() end() rbegin() rend() find(5)
a.size();
a.empty();
a.erase(10);
a.clear();
a.count(5); // 1 or 0 if in
```

### unordered set
unique elements in hashtable; same functions as set
```cpp
#include <bits/stdc++.h>
unordered_set<int> a;
vector<int> vec({ 1, 2, 2, 1, 3, 1, 4 }); // input
unordered_set<int> a(vec.begin(), vec.end()); // create from vector
```

### multiset
like set (sorted order) but can have more than one occurance, using binary search trees; same functions as set
```cpp
#include <set>
multiset<int> a;
a.insert(20);
a.erase(1); //removes all instances
a.erase(a.find(1)); //removes one instance
a.count(1); // counts number occurances
```
unordered multiset

### map
key-value pairs using a binary search tree
```cpp
#include <map>
map<int, int> a;
a[1] = 20; // or a.insert(pair<int, int>(1,20));

map<int, int>::iterator itr;
for (itr = a.begin(); itr != a.end(); ++itr) {
    cout << itr->first << '\t' << itr->second;
}
```
multimap; (hash tables) unordered map; unordered multimap

</blockquote>

# TODO
- https://www.geeksforgeeks.org/bit-tricks-competitive-programming/?ref=lbp
- functors (find video to learn)
