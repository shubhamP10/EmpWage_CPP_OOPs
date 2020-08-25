#include <iostream>
#include <ctime>
#include <unistd.h>

using namespace std;

class EmployeeWageComputation { 
    public:
        int dailyWage = 0;
        int getJobType();
};

class Company {
    int WORK_DAYS_IN_MONTH = 20;
    int WAGE_PER_HOUR = 20;
    int FULL_DAY_HOUR = 8;
    int PART_TIME_HOUR = 4;
    int MAX_WORK_HOURS_IN_MONTH = 100;
    
    public:
    int getWagePerHour();
    int getFullDayHour();
    int getPartTimeHour();
    int getWorkDays();
    int getMaxWorkHours();
};

int Company::getWorkDays() {
    return this->WORK_DAYS_IN_MONTH;
}

int Company::getMaxWorkHours() {
    return this->MAX_WORK_HOURS_IN_MONTH;
}

int Company::getWagePerHour() {
    return this->WAGE_PER_HOUR;
}

int Company::getFullDayHour() {
    return this->FULL_DAY_HOUR;
}

int Company::getPartTimeHour() {
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
    int workHrs = 0, totalWorkHrs = 0, totalWorkDays = 1;

    cout << "Welcome To Employee Wage Computation" << endl << endl;

    while(totalWorkHrs < company.getMaxWorkHours() && totalWorkDays < company.getWorkDays()) {
        totalWorkDays++;
        int jobType = employee.getJobType();

        switch(jobType) {
            case 1:
                workHrs = company.getFullDayHour();
                cout << "Day" << totalWorkDays << " WorkHr = " << workHrs << endl;
                break;
            case 2:
                workHrs = company.getPartTimeHour();
                cout << "Day" << totalWorkDays << " WorkHr = " << workHrs << endl;
                break;
            default:
                workHrs = 0;
                cout << "Day" << totalWorkDays << " WorkHr = " << workHrs << endl;
                break;
        }
       totalWorkHrs += workHrs;
    }

    cout << "Total Hours Worked: " << totalWorkHrs << endl;
    monthlyWage = totalWorkHrs * company.getWagePerHour();
    cout << "Monthly Wage = " << monthlyWage << endl;
    return 0;
}