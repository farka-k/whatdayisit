#include <iostream>
#include <numeric>
#include <vector>
#include <regex>
using namespace std;
int parseDate(string date,int & year, int & month, int & day){
    regex re("[-/. ]");
    sregex_token_iterator first{date.begin(),date.end(),re,-1},last;
    vector<string> tokens{first,last};
    if (tokens.size()!=3) return -1;
    year=stoi(tokens[0]);
    month=stoi(tokens[1]);
    day=stoi(tokens[2]);
    
    return 0;
}
int main(){ 
    string date;
    int year, month, day;
    string dayOfWeek[7]={"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
    int daysInMonth[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    
    cout<<"Date: ";
    cin>>date;
    
    while (parseDate(date,year,month,day)) {
        cout<<"Wrong date format\n";
        cout<<"Date: ";
        cin>>date;
    }
    
    year=(year-1)%400;  
    int count100=year/100;
    year%=100;
    int count4=year/4;
    int monthsDay=0;
    for(int i=0;i<month-1;i++) monthsDay+=daysInMonth[i];
 
    int result=(5*count100 +(year + count4) + monthsDay + day) %7;

    cout<<dayOfWeek[result]<<endl;
    return 0;
}