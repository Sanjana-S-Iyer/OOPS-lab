#include <iostream>
using namespace std;
class base {
public:
void normal()   {cout<<"base::normal (early binding)\n";}
virtual void special(){cout<< "base::special\n";}
};
class derived:public base{
    public:
    void normal(){cout<< "derived:: normal\n";}
    void special() override {cout<<"dervied::special (late binding)\n";}
};
int main(){
    derived d;
    base*p=&d;
    p->normal();
    p->special();
    return 0;
}
