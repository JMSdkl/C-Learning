#include <iostream>
#include <string>
using namespace std;
//对于自定的类，来做对象的加减运算
class person 
{public:
    int m_A;
    int m_B;
                 //成员函数做运算符重载
    person operator+(person& p) {
        person temp;
        temp.m_A = this->m_A + p.m_A;
        temp.m_B = this->m_B + p.m_B;
        return temp;
    }
}; 
                 //全局函数做运算符重载
person operator+(person& p1, person& p2) {
    person temp;
    temp.m_A = p1.m_A + p2.m_A;
    temp.m_B = p1.m_B + p2.m_B;
    return temp;
}
//运算符重载也可以发生函数重载
person operator+(person& p1, int num) {
    person temp;
    temp.m_A = p1.m_A + num;
    temp.m_B = p1.m_B + num;
    return temp;
}
void test01() {
    person p1;
    person p2, p3;
    p1.m_A = 10;
    p1.m_B = 10;      
    p2.m_A = 10;
    p2.m_B = 10;
   // p3 = p1.operator+(p2);//成员函数做重载的本质调用
   // p3 = operator+(p1, p2);//全局函数做重载的本质调用
   // p3 = p1 + p2;//简化调用
    p3 = p1 + 100;
    cout << "p3成员的属性" << p3.m_A << p3.m_B << endl;          
}

int  main() {

    test01();
    system("pause");
    return 0;

}