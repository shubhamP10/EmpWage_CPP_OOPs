#include <iostream>
#include <ctime>

using namespace std;

class EmployeeWageComputation {
    int WAGE_PER_HOUR = 20;
    int FULL_DAY_HOUR = 8;
    int PART_TIME_HOUR = 4;
    public:
        int dailyWage = 0;
        int getJobType();
        int getWagePerHour();
        int getFullDayHour();
        int getPartTimeHour();
};

int EmployeeWageComputation::getWagePerHour() {
    return this->WAGE_PER_HOUR;
}

int EmployeeWageComputation::getFullDayHour() {
    return this->FULL_DAY_HOUR;
}

int EmployeeWageComputation::getPartTimeHour() {
    return this->PART_TIME_HOUR;
}

int EmployeeWageComputation::getJobType() {
    srand(time(0));
    return (rand() % 3) + 1;
}

int main() {
    
    EmployeeWageComputation employee;
    int jobType = employee.getJobType();

    cout << "Welcome To Employee Wage Computation" << endl << endl;

    switch(jobType) {
        case 1:
            cout << "Employee is Full Time\n";
            employee.dailyWage = employee.getWagePerHour() * employee.getFullDayHour();
            cout << "Wage = " << employee.dailyWage;
            break;
        case 2:
            cout << "Employee is Part Time\n";
            employee.dailyWage = employee.getWagePerHour() * employee.getPartTimeHour();
            cout << "Wage = " << employee.dailyWage;
            break;
        default:
            cout << "Employee is Absent\n";
    }

    return 0;
}