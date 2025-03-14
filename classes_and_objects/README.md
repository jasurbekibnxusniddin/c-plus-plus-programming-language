In C++, the class forms the basis for object-oriented programming. The class is used to define the nature of an object, and it is C++'s basic unit of encapsulation. This chapter examines classes and objects in detail.

# Classes
Classes are created using the keyword class. A class declaration defines a new type that links code and data. This new type is then used to declare objects of that class. Thus, a class is a logical abstraction, but an object has physical existence. In other words, an object is an instance of a class. 

A class declaration is similar syntactically to a structure. In Chapter 11, a simplified general form of a class declaration was shown. Here is the entire general form of a class declaration that does not inherit any other class.

```cpp
class class-name {
    private data and functions
    
    access-specifier:
        data and functions

    access-specifier:
        data and functions
    // ...
    access-specifier:
        data and functions
} object-list;
```

The object-list is optional. If present, it declares objects of the class. Here, access-specifier is one of these three  
C++ keywords:

```cpp
public 
private 
protected
```
**private** <br>
By default, functions and data declared within a class are private to that class and may be accessed only by other members of the class.

**public** <br>
The public access specifier allows functions or data to be accessible to other parts of your program.

**protected** <br>
The protected access specifier is needed only when inheritance is involved (see Chapter 15).

Once an access specifier has been used, it remains in effect until either another access specifier is encountered or the end of the class declaration is reached.

You may change access specifications as often as you like within a class declaration. For example, you may switch to public for some declarations and then switch back to private again. The class declaration in the following example illustrates this feature:
```cpp
#include <iostream>
#include <cstring>

using namespace std;

class employee {
    char name[80]; // private by default
    
    public:
        void putname(char *n); // these are public
        void getname(char *n);

    private:
        double wage; // now, private again

    public:
        void putwage(double w); // back to public
        double getwage();
};

void employee::putname(char *n) {
    strcpy(name, n);
}

void employee::getname(char *n) {
    strcpy(n, name);
}


void employee::putwage(double w) {
    wage = w; 
}

double employee::getwage() {
  return wage;
}

int main() {
    
    employee ted;
    
    char name[80];
    
    ted.putname("Ted Jones");
    ted.putwage(75000);
    ted.getname(name);
    
    cout << name << " makes $";
    cout << ted.getwage() << " per year.";

    return 0; 
}
```

Here, employee is a simple class that is used to store an employee's name and wage.
Notice that the public access specifier is used twice. Although you may use the access specifiers as often as you like within a class declaration, the only advantage of doing so is that by visually grouping various parts of a class, you may make it easier for someone else reading the program to understand it. However, to the compiler, using multiple access specifiers makes no difference.

Actually, most programmers find it easier to have only one private, protected, and
public section within each class. For example, most programmers would code the employee class as shown here, with all private elements grouped together and all public elements grouped together:

```cpp
class employee {
    
    private:
        char name[80];
        double wage;
    
    public:
        void putname(char *n);
        void getname(char *n);
        void putwage(double w);
        double getwage();
};
```

Functions that are declared within a class are called member functions. Member functions may access any element of the class of which they are a part. This includes all private elements. Variables that are elements of a class are called member variable or data members. (The term instance variable is also used.) Collectively, any element of a class can be referred to as a member of that class.

There are a few restrictions that apply to class members. A non-static member variable cannot have an initializer. No member can be an object of the class that is being declared. (Although a member can be a pointer to the class that is being declared.) No member can be declared as auto, extern, or register.

In general, you should make all data members of a class private to that class. This is part of the way that encapsulation is achieved. However, there may be situations in which you will need to make one or more variables public. (For example, a heavily used variable may need to be accessible globally in order to achieve faster run times.) When a variable is public, it may be accessed directly by any other part of your program. The syntax for accessing a public data member is the same as for calling a member function: Specify the object's name, the dot operator, and the variable name. This simple program illustrates the use of a public variable:

```cpp
#include <iostream>

using namespace std;

int main() {

    myclass a, b;
    
    a.i = 100; // access to i, j, and k is OK
    a.j = 4;
    a.k = a.i * a.j;
    b.k = 12; // remember, a.k and b.k are different

    cout << a.k << " " << b.k;
    
    return 0;
}
```

# Structures and Classes Are Related
Structures are part of the C subset and were inherited from the C language. As you
have seen, a class is syntactically similar to a struct. But the relationship between a
class and a struct is closer than you may at first think. In C++, the role of the structure
was expanded, making it an alternative way to specify a class. In fact, the only difference
between a class and a struct is that by default all members are public in a struct and
private in a class. In all other respects, structures and classes are equivalent. That is,
in C++, a structure defines a class type. For example, consider this short program, which
uses a structure to declare a class that controls access to a string:
```cpp
// Using a structure to define a class.
#include <iostream>
#include <cstring>

using namespace std;

struct mystr {

        void buildstr(char *s); // public
        void showstr();
        
    private: // now go private
        char str[255];
};

void mystr::buildstr(char *s) {

    if(!*s) *str = '\0'; // initialize string
    else strcat(str, s);
}

void mystr::showstr() {
    cout << str << "\n";
}

int main() {
    
    mystr s;

    s.buildstr(""); // init
    s.buildstr("Hello ");
    s.buildstr("there!");
    s.showstr();
    
    return 0;
}
```

This program displays the string Hello there!.

The class mystr could be rewritten by using class as shown here:
```cpp
class mystr {
        char str[255];
    
    public:
        void buildstr(char *s); // public
        void showstr();
};
```

You might wonder why C++ contains the two virtually equivalent keywords struct
and class. This seeming redundancy is justified for several reasons. First, there is no
fundamental reason not to increase the capabilities of a structure. In C, structures
already provide a means of grouping data. Therefore, it is a small step to allow them to
include member functions. Second, because structures and classes are related, it may be
easier to port existing C programs to C++. Finally, although struct and class are virtually
equivalent today, providing two different keywords allows the definition of a class to
be free to evolve. In order for C++ to remain compatible with C, the definition of struct
must always be tied to its C definition.

Although you can use a struct where you use a class, most programmers don't.
Usually it is best to use a class when you want a class, and a struct when you want a
C-like structure. This is the style that this book will follow. Sometimes the acronym
POD is used to describe a C-style structure—one that does not contain member
functions, constructors, or destructors. It stands for Plain Old Data.

In C++, a structure declaration defines a class type.

# Unions and Classes Are Related 
Like a structure, a union may also be used to define a class. In C++, unions may
contain both member functions and variables. They may also include constructors
and destructors. A union in C++ retains all of its C-like features, the most important
being that all data elements share the same location in memory. Like the structure,
union members are public by default and are fully compatible with C. In the next
example, a union is used to swap the bytes that make up an unsigned short integer.
(This example assumes that short integers are 2 bytes long.)

```cpp
#include <iostream>

using namespace std;

union swap_byte {
    void swap();
    void set_byte(unsigned short i);
    void show_word();

    unsigned short u;
    unsigned char c[2];
};

void swap_byte::swap() {
    unsigned char t;
    t = c[0];
    c[0] = c[1];
    c[1] = t;
}

void swap_byte::show_word() {
    cout << u;
}

void swap_byte::set_byte(unsigned short i)  {
    u = i;
}

int main() {

    swap_byte b;
    
    b.set_byte(49034);
    b.swap();
    b.show_word();
    
    return 0;
}
```

Like a structure, a union declaration in C++ defines a special type of class. This
means that the principle of encapsulation is preserved.
There are several restrictions that must be observed when you use C++ unions.
First, a union cannot inherit any other classes of any type. Further, a union cannot be
a base class. A union cannot have virtual member functions. (Virtual functions are
discussed in Chapter 17.) No static variables can be members of a union. A reference
member cannot be used. A union cannot have as a member any object that overloads
the = operator. Finally, no object can be a member of a union if the object has an explicit
constructor or destructor function.
As with struct, the term POD is also commonly applied to unions that do not contain
member functions, constructors, or destructors.

## Anonymous Unions
There is a special type of union in C++ called an anonymous union. An anonymous
union does not include a type name, and no objects of the union can be declared.

Instead, an anonymous union tells the compiler that its member variables are to
share the same location. However, the variables themselves are referred to directly,
without the normal dot operator syntax. For example, consider this program:

```cpp
#include <iostream>
#include <cstring>

using namespace std;

int main() {
    // define anonymous union
    union {
        long l;
        double d;
        char s[4];
    } ;

    // now, reference union elements directly
    l = 100000;
    cout << l << " ";
    
    d = 123.2342;
    cout << d << " ";
    
    strcpy(s, "hi");
    cout << s;
    
    return 0;
}
```

As you can see, the elements of the union are referenced as if they had been
declared as normal local variables. In fact, relative to your program, that is exactly how
you will use them. Further, even though they are defined within a union declaration,
they are at the same scope level as any other local variable within the same block. This
implies that the names of the members of an anonymous union must not conflict with
other identifiers known within the same scope.
All restrictions involving unions apply to anonymous ones, with these additions.
First, the only elements contained within an anonymous union must be data. No
member functions are allowed. Anonymous unions cannot contain private or
protected elements. Finally, global anonymous unions must be specified as static.

# Friend Functions
It is possible to grant a nonmember function access to the private members of a class
by using a friend. A friend function has access to all private and protected members of the class for which it is a friend. To declare a friend function, include its prototype
within the class, preceding it with the keyword friend. Consider this program:

```CPP
#include <iostream>

using namespace std;

class myclass {
    int a, b;
    
    public:
        friend int sum(myclass x);
        void set_ab(int i, int j);
};

void myclass::set_ab(int i, int j) {
    a = i;
    b = j;
}

// Note: sum() is not a member function of any class.
int sum(myclass x) {
/* Because sum() is a friend of myclass, it can
directly access a and b. */
    return x.a + x.b;
}

int main() {

    myclass n;
    

    n.set_ab(3, 4);
    cout << sum(n);
    
    return 0;
}
```

In this example, the sum( ) function is not a member of myclass. However, it still
has full access to its private members. Also, notice that sum( ) is called without the use
of the dot operator. Because it is not a member function, it does not need to be (indeed,
it may not be) qualified with an object's name.
