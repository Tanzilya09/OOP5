#include <iostream>
using namespace std;

class Time {
private:
    int hours, minutes, seconds;

public:
    Time(int h = 0, int m = 0, int s = 0) : hours(h), minutes(m), seconds(s) {}

    void display() const {
        cout << (hours < 10 ? "0" : "") << hours << ":"
            << (minutes < 10 ? "0" : "") << minutes << ":"
            << (seconds < 10 ? "0" : "") << seconds << endl;
    }

    Time& operator++() {  
        seconds++;
        if (seconds >= 60) {
            seconds = 0;
            minutes++;
        }
        if (minutes >= 60) {
            minutes = 0;
            hours++;
        }
        return *this;
    }

    Time operator++(int) {  
        Time temp = *this;
        ++(*this);
        return temp;
    }

    Time& operator--() {  
        if (seconds == 0) {
            seconds = 59;
            if (minutes == 0) {
                minutes = 59;
                if (hours > 0) hours--;
            }
            else {
                minutes--;
            }
        }
        else {
            seconds--;
        }
        return *this;
    }

    Time operator--(int) {  
        Time temp = *this;
        --(*this);
        return temp;
    }
};

int main() {
    setlocale(LC_ALL, "rus");
    Time t1(10, 59, 58);

    cout << "Исходное время: ";
    t1.display();

    ++t1;
    cout << "После префиксного ++: ";
    t1.display();

    t1++;
    cout << "После постфиксного ++: ";
    t1.display();

    --t1;
    cout << "После префиксного --: ";
    t1.display();

    t1--;
    cout << "После постфиксного --: ";
    t1.display();

    return 0;
}

