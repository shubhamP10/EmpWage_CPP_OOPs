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
    int WORK_DAYS_IN_MONTH;
    int WAGE_PER_HOUR;
    int FULL_DAY_HOUR = 8;
    int PART_TIME_HOUR = 4;
    int MAX_WORK_HOURS_IN_MONTH;
    string companyName;
    
    public:
    int getWagePerHour();
    void setWagePerHour(int wagePerHr);
    int getFullDayHour();
    int getPartTimeHour();
    int getWorkDays();
    void setWorkDays(int workDays);
    int getMaxWorkHours();
    void setMaxWorkHours(int maxHrs);
    void setCompanyName(string companyName);
    string getCompanyName();
};

void Company::setCompanyName(string companyName) {
    this->companyName = companyName;
}

string Company::getCompanyName() {
    return this->companyName;
}

void Company::setWorkDays(int workDays) {
    this->WORK_DAYS_IN_MONTH = workDays;
}

int Company::getWorkDays() {
    return this->WORK_DAYS_IN_MONTH;
}

void Company::setMaxWorkHours(int maxHrs) {
    this->MAX_WORK_HOURS_IN_MONTH = maxHrs;
}

int Company::getMaxWorkHours() {
    return this->MAX_WORK_HOURS_IN_MONTH;
}

void Company::setWagePerHour(int wagePerHr) {
    this->WAGE_PER_HOUR = wagePerHr;
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

int readInt(std::istream& stream) {
    int i;
    stream >> i;
    return i;
}

string readString(std::istream& stream) {
    string i;
    stream >> i;
    return i;
}

void displayWelcomeMessage() {
    cout << "Welcome To Employee Wage Computation" << endl << endl;
}



int getToalWorkHours(Company company) {
    EmployeeWageComputation employee;
    srand(time(0));
    int workHrs = 0, totalWorkHrs = 0, totalWorkDays = 1;

    while(totalWorkHrs <= company.getMaxWorkHours() && totalWorkDays <= company.getWorkDays()) {
        totalWorkDays++;
        int jobType = employee.getJobType();

        switch(jobType) {
            case 1:
                workHrs = company.getFullDayHour();
                cout << totalWorkDays - 1 << "\t\t" << workHrs << endl;
                break;
            case 2:
                workHrs = company.getPartTimeHour();
                cout << totalWorkDays - 1 << "\t\t" << workHrs << endl;
                break;
            default:
                workHrs = 0;
                cout << totalWorkDays - 1 << "\t\t" << workHrs << endl;
                break;
        }
       totalWorkHrs += workHrs;
    }
    return totalWorkHrs;
}

Company readDataOfCompany(Company company, int companyCount) {
    cout << "\nFor Company: " << companyCount + 1 << endl;
    cout << "Enter Company Name: ";
    company.setCompanyName(readString(cin));
    cout << "Enter Wage Per Hour: ";
    company.setWagePerHour(readInt(cin));
    cout << "Enter Number Of Working Days: ";
    company.setWorkDays(readInt(cin));
    cout << "Enter Max Workig Hour Per Month: ";
    company.setMaxWorkHours(readInt(cin));
    return company;
}

void displayCompanyData(Company company, int companyCount) {
    int monthlyWage = 0;
    int totalWorkHrs = 0;
    
    cout << "\n====================================================\n";
    cout << "Employee Wage Calculation For: " << company.getCompanyName() << endl;
    cout << "----------------------------\n";
    cout << "DAY\t\tHOURS_WORKED\n";
    cout << "----------------------------\n";

    totalWorkHrs = getToalWorkHours(company);
    cout << "\nTotal Hours Worked: " << totalWorkHrs << endl;
    monthlyWage = totalWorkHrs * company.getWagePerHour();
    cout << "Monthly Wage = " << monthlyWage << endl;
}

void start() {
    Company company;
    int totalCompanies = 0;
    srand(time(0));

    cout << "Enter Number of Companies: ";
    cin >> totalCompanies;

    Company companies[totalCompanies];

    for(int companyCount = 0; companyCount < totalCompanies; companyCount++) {
        companies[companyCount] = readDataOfCompany(companies[companyCount], companyCount);
    }

    for(int companyCount = 0; companyCount < totalCompanies; companyCount++) {
        displayCompanyData(companies[companyCount], companyCount);
    }
}

int main() {

    displayWelcomeMessage();

    start();

    return 0;
}