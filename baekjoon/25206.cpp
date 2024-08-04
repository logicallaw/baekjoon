#include <iostream>
#include <string>
using namespace std;
int main(void) {
    double avg = 0;
    double sum = 0;
    for(int i{ 0 }; i < 20; i++) {
        string name;
        double num;
        string grade;
        cin >> name >> num >> grade;
        sum += num;
        if(grade == "A+") {
            avg += num * 4.5;
        }
        else if (grade == "A0") {
            avg += num * 4.0;
        }
        else if (grade == "B+") {
            avg += num * 3.5;
        }
        else if (grade == "B0") {
            avg += num * 3.0;
        }
        else if (grade == "C+") {
            avg += num * 2.5;
        }
        else if (grade == "C0") {
            avg += num * 2.0;
        }
        else if (grade == "D+") {
            avg += num * 1.5;
        }
        else if (grade == "D0") {
            avg += num * 1.0;
        } else if (grade == "P") {
            sum -= num;
        }
    }
    printf("%.6f", avg / sum);
}