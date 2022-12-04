# Basics

- [Back to Main](README.md)
- [Compiling](#compiling)
- [namespace and libraries](#namespace-and-libraries)
- [Comments](#comments)
- [Variables](#variables)
  - [Datatypes](#datatypes)
  - [Modifiers](#modifiers)
  - [Min and max values](#min-and-max-values)
  - [local instance or static](#local-instance-or-static)
- [Operators](#operators)
  - [Memory](#memory)
- [Loops](#loops)
- [Control](#control)
- [Input and Output](#input-and-output)
- [Arrays](#arrays)
- [Functions](#functions)
- [Pointers and References](#pointers-and-references)
- [OOP](#oop)
- [Exceptions](#exceptions)
- [Lambdas](#lambdas)

---

# Compiling
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

# namespace and libraries

```cpp
#include <iostream>     // std::cout, cin, cerr
#include <string>       // std::string
#include <cstddef>      // std::size_t

using namespace std;    // now we can do cout instead of std::cout
```

# Comments
```cpp
// one line
/*
multi line
*/
```

# Variables
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

# Operators
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

# Loops

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

iterators
- iterator functions return iterators: `begin()` `end()` and the reverse are `rbegin()` `rend()`
```cpp
string::iterator i;
for (i = s.begin(); i != s.end(); i++)
  cout << i << endl;
```

# Control
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

# Input and Output

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

# Arrays
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
convert c style array to std::array
```cpp
int r[] = {1,2,3};
array<int, 3> a;
copy(begin(arr), end(arr), a.begin());
```

# Functions

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

# Pointers and References

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

# OOP
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

# Exceptions
throw exception with `throw x;`
```cpp
try {
  fun(NULL, 0);   
} catch(...) {
  cout << "Caught";
}
```

use assert statements at run-time (and disable them)
```cpp
// #define NDEBUG 
// uncomment NBEBUG to turn off assert
#include <cassert>
assert(2+2==3+1);
```

use assert statements at compile time
```cpp
#include <cassert>
static_assert(2+2==3+1, "2+2 = 3+1");
```

# Lambdas
- anonymous function
- capture clause allows use of local variables as constants 
- (must use .at(2) instead of [2] for maps because [] might edit map), unless you pass by reference
```cpp
// capture clause first    []
// then inputs             ()
// then function           {}
auto my_func = [loc_var](int input_x) { return (input_x == loc_var); }
auto my_func = [&loc_var](int input_x) { local_var++; return (input_x == loc_var); }
auto my_func = [&](int input_x) { return (input_x == loc_var); } // pass everything in local scope by reference
```
