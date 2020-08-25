#include <iostream>
#include <ctime>
#include <unistd.h>

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

class Company {
    int WORK_DAYS_IN_MONTH = 20;
    
    public:
        int getWorkDays();
};

int Company::getWorkDays() {
    return this->WORK_DAYS_IN_MONTH;
}

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
    
    return (rand() % 3) + 1;
}

int main() {
    
    EmployeeWageComputation employee;
    Company company;
    srand(time(0));
    int monthlyWage = 0;
    int workHrs = 0, totalWorkHrs = 0;

    cout << "Welcome To Employee Wage Computation" << endl << endl;

    for(int day = 1; day <= company.getWorkDays(); day++) {

        int jobType = employee.getJobType();

        switch(jobType) {
            case 1:
                workHrs = employee.getFullDayHour();
                cout << "Day" << day << " WorkHr = " << workHrs << endl;
                break;
            case 2:
                workHrs = employee.getPartTimeHour();
                cout << "Day" << day << " WorkHr = " << workHrs << endl;
                break;
            default:
                workHrs = 0;
                cout << "Day" << day << " WorkHr = " << workHrs << endl;
                break;
        }
       totalWorkHrs += workHrs;
    }

    cout << "Total Hours Worked: " << totalWorkHrs << endl;
    monthlyWage = totalWorkHrs * employee.getWagePerHour();
    cout << "Monthly Wage = " << monthlyWage << endl;
    return 0;
}