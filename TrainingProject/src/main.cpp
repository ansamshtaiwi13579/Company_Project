
//#include "../includes/Ceo.hpp"
#include "../includes/Company.hpp"
#include <iostream>
using namespace std;

int main(){
    cout<<"Hi Ansam!"<<endl;
    Ceo ceo("Tareq"); string com = "Exalt";
    Company *company = Company::getInstance(&ceo, &com);
    cout<<company->companyName()<<endl;
    cout<<company->companyCEO().name<<endl;

    Employee employee1("e1", 1000, HR);
    Employee employee2("e2", 2000, Dev);
    Employee employee3("e3", 3000, DevMng);
    Employee employee4("e4", 1000, HR);
    Employee employee5("e5", 2000, Dev);
    Employee employee6("e6", 3000, DevMng);
    Employee employee7("e7", 4000, Lead);
    Employee floatEmp("float", 1500, Dev);

    Department dep1("d1");
    Department dep2("d2");
    Department dep11("d11");
    Department dep12("d12");
    Department dep21("d21");
    Department dep111("d111");

    set <Employee*> allEmployees;
    set <Department*> alldepartments;
    set <Department*> mainDepartments;
    map <int, set<Employee*>> salaryMap;

    bool depLoop = false;


    company->addEmployee(&employee1, &dep1); //3 normal insertion
    company->addEmployee(&employee1, &dep1); //2 insert Emp that found in the Dep
    company->addEmployee(nullptr, &dep1);//1 null Employee
    company->addEmployee(&floatEmp, nullptr);//4 null department ==> float Employee
    company->addEmployee(&employee2, &dep2);
    company->addEmployee(&employee3, &dep12);
    company->addEmployee(&employee1, &dep12);
    company->addEmployee(&employee4, &dep21);
    company->addEmployee(&employee5, &dep21);
    company->addEmployee(&employee6, &dep111);
    company->addEmployee(&employee7, &dep1);

    company->addDepartment(nullptr); //1 null department
    company->addDepartment(&dep1);//3 normal department insertion
    company->addDepartment(&dep2);
    company->addSubDep(nullptr, nullptr);//1 null subDep or super
    company->addSubDep(&dep111, &dep11);//4 normal insertion
    company->addSubDep(&dep111, &dep11);//2 subDep found in super
    company->addSubDep(&dep111, &dep2);//3 loop department
    company->addSubDep(&dep11, &dep1);
    company->addSubDep(&dep12, &dep1);
    company->addSubDep(&dep21, &dep2);

    company->deleteEmp(nullptr, &dep1);//1 null employee
    company->deleteEmp(&employee1, nullptr);//3 null department and nonfloat Employee
    company->deleteEmp(&employee1, &dep2);//6 emp is not found
    company->deleteEmp(&employee1, &dep1);//4 multi department
    company->deleteEmp(&floatEmp, nullptr);//2 null deparement and float employee
    company->deleteEmp(&employee4, &dep21);//5 normal deletion

    company->deleteDep(&dep21, &dep2);
    company->deleteDep(&dep11, &dep1);
    company->deleteDep(&dep2);



    company->printAllEmps();

    return 0;
}
