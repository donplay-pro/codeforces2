#include <iostream>
using namespace std;
class employee
{
public:
    int salary, bs, exp1, exp2, exp3, inc, grossinc;
    void calcsalary()
    {
        cout << "Enter basic salary of employee:" << endl;
        cin >> bs;
        cout << "Enter experience of adminofficer:" << endl;
        cin >> exp1;
        cout << "Enter experience of faculty:" << endl;
        cin >> exp2;
        cout << "Enter experience of dean:" << endl;
        cin >> exp3;
    }
};

class adminofficer : virtual public employee

{
public:
    void calcsalary_a()
    {
        cout << "Calculating adminofficer's salary" << endl;
        inc = 0.01 * bs;
        grossinc = inc * (exp1 / 2);
        salary = bs + grossinc;
        cout << "Adminofficer's salary is: " << salary << endl;
    }
};
class faculty : virtual public employee, public adminofficer
{
public:
    void calcsalary_f()
    {
        cout << "Calculating faculty salary" << endl;
        inc = 0.005 * bs;
        grossinc = inc * (exp2 / 4);
        salary = bs + grossinc;
        cout << "Faculty salary is: " << salary << endl;
    }
};
class dean : virtual public employee, public faculty
{
public:
    void calcsalary_d()
    {
        cout << "Calculating dean salary" << endl;
        inc = 0.02 * bs;
        grossinc = inc * (exp3 / 2);
        salary = bs + grossinc;
        cout << "Dean salary: " << salary << endl;
    }
};
int main()
{
    dean d;
    d.calcsalary();
    d.calcsalary_d();
    d.calcsalary_f();
    d.calcsalary_a();
}
