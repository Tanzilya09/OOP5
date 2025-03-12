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

    Time operator-(const Time& t) const { 
        int totalSec1 = hours * 3600 + minutes * 60 + seconds;
        int totalSec2 = t.hours * 3600 + t.minutes * 60 + t.seconds;
        int diff = totalSec1 - totalSec2;
        if (diff < 0) diff = 0;
        return Time(diff / 3600, (diff % 3600) / 60, diff % 60);
    }

    Time operator*(float factor) const { 
        int totalSec = (hours * 3600 + minutes * 60 + seconds) * factor;
        return Time(totalSec / 3600, (totalSec % 3600) / 60, totalSec % 60);
    }
};

int main() {
    setlocale(LC_ALL, "rus");
    Time t1(10, 59, 58);
    Time t2(2, 30, 30);

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

    Time t3 = t1 - t2;
    cout << "Разница (t1 - t2): ";
    t3.display();

    Time t4 = t1 * 1.5;
    cout << "Умножение времени (t1 * 1.5): ";
    t4.display();

    return 0;
}
