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