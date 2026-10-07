#include <iostream>
using namespace std;
class shape {
public:
virtual double area() const=0;
virtual void name() const=0;
virtual ~shape(){}
};
class circle:public shape{
    double r;
    public:
    circle(double r):r(r){}
    double area () const override {return 3.14159*r*r;}
    void name() const override {cout<<"circle:";}
};
class square:public shape{
    double s;
    public:
    square(double s):s(s){}
    double area () const override {return s*s;}
    void name() const override {cout<<"squae:";}
};
int main(){
shape*shapes[]={new circle(2), new square(3)};
for(shape*sh: shapes){
    sh-> name();
    cout<<"area="<<sh->area()<<endl;
}
for (shape*sh: shapes)delete sh;
}