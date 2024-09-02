#include<bits/stdc++.h>
using namespace std;
class Employee{
    string name;
    double fixedSalary;
public:
    virtual void pay() = 0;
    Employee(string name, double fixedSalary): name(name), fixedSalary(fixedSalary){}
    string getName(){return name;}
    double getSalary(){return fixedSalary;}
};
class Technician: virtual public Employee{
public:
    virtual void pay(){
        cout << getName() << ": " << getSalary() << "per hour" << endl;
    }
    Technician(string name, double fixedSalary=100): Employee(name, fixedSalary){}
};
class Manager: virtual public Employee{
public:
    virtual void pay(){
        cout << getName() << ": " << getSalary() << "per month" << endl;
    }
    Manager(string name, double fixedSalary=7000): Employee(name, fixedSalary){}
};
class Salesman: virtual public Employee{
    double valueOfSales;
    double commission;
public:
    virtual void pay(){
        cout << getName() << ": " << "commission " << getCommission() << endl;  
    }
    double getCommission(){return commission;}
    Salesman(string name, double value=0, double ratio=0.05): Employee(name, 0), valueOfSales(value){
        valueOfSales = value;
        commission = value * ratio;
        }
};
class SalesManager: virtual public Manager, virtual public Salesman{
public:
    virtual void pay(){
        cout << getName() << ": " << getSalary() << "per month + " << "commission: " << getCommission() << endl;
    }
    // 虚基类必须初始化
    SalesManager(string name, double value, double salary = 4000): Manager("", salary), Salesman("", value, 0.005), Employee(name, salary){}
};

int main(void){
    Employee* ptr;
    Technician e1("Role");
    Manager e2("Gauss");
    Salesman e3("Mark", 10000);
    SalesManager e4("Lee", 50000);

    ptr = &e1;
    ptr->pay();
    ptr = &e2;
    ptr->pay();
    ptr = &e3;
    ptr->pay();
    ptr = &e4;
    ptr->pay();
    return 0;
}