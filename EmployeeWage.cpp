#include <iostream>
#include <ctime>

using namespace std;

class EmployeeWageComputation {
    public:
        int checkPresent();
};

int EmployeeWageComputation::checkPresent() {
    srand(time(0));
    return (rand() % 2);
}

int main() {
    
    EmployeeWageComputation employee;
    int attendence = employee.checkPresent();

    cout << "Welcome To Employee Wage Computation" << endl;

    if(attendence == 1) {
        cout << "Employee is Present" << endl;
    }
    else {
        cout << "Employee is Absent" << endl;
    }    
    return 0;
}