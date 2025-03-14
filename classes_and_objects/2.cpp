#include <iostream>
#include <cstring>

using namespace std;

class Employee {
    private:
        double wage;
        char name[80];
    public:
        void putwage(double w);
        void putname(char *n);
        double getwage();
        void getname(char *n);
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

double Employee::getwage(){
    return wage;
}