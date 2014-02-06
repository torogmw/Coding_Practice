#include <iostream>

class A{
public:
    void f(){ printf("A:f\n"); }
    virtual void g(){ printf("A:g\n"); }
};

class B :public A{
public:
    void f(){ printf("B:f\n"); }
    void g(){ printf("B:g\n"); }
};

int main(){ 
    A a; 
    B b;
    A* ap= &b;
    B* bp = &b;
    ap->f();	
    ap->g();   // virtual function dynamic binding
    bp->f();
    bp->g();
    return 0;
}


