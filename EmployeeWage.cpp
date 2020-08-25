#include <iostream>
#include <ctime>

using namespace std;

class EmployeeWageComputation {
    int WAGE_PER_HOUR = 20;
    int FULL_DAY_HOUR = 8;
    public:
        int dailyWage = 0;
        int checkPresent();
        int getWagePerHour();
        int getFullDayHour();
};

int EmployeeWageComputation::getWagePerHour() {
    return this->WAGE_PER_HOUR;
}

int EmployeeWageComputation::getFullDayHour() {
    return this->FULL_DAY_HOUR;
}

int EmployeeWageComputation::checkPresent() {
    srand(time(0));
    return (rand() % 2);
}

int main() {
    
    EmployeeWageComputation employee;
    int attendence = employee.checkPresent();

    cout << "Welcome To Employee Wage Computation" << endl << endl;

    if(attendence == 1) {
        cout << "Employee is Present" << endl;
        employee.dailyWage = employee.getWagePerHour() * employee.getFullDayHour();
        cout << "Wage = " << employee.dailyWage;
    }
    else {
        cout << "Employee is Absent" << endl;
    }    
    return 0;
}