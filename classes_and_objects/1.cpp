#include <iostream>
#include <cstring>

using namespace std;

class Employee { 

    char name[80]; // private by default

    public:
        void putname(char *n);
        void getname(char *n);
    
    private:
        double wage;

    public:
        void putwage(double w);
        double getwage();
};

void Employee::putname(char *n){
    strcpy(name, n);
}

void Employee::getname(char *n){
    strcpy(n, name);
}

void Employee::putwage(double w){
    wage = w;
}

int main() {

    Employee ted;

    ted.putname("Ted jones");
    ted.putwage(75000);

    char name[80];
    ted.getname(name);

    cout << name << " makes $";
    cout << ted.getwage() << " per year.";

    return 0; 
}