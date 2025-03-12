#include <iostream>
#include <cmath>
using namespace std;

class Sterling {
private:
    long funt;    
    int shill;  
    int pence;      

    double toDecimal() const {
        return funt + shill / 20.0 + pence / 240.0;
    }

public:
    Sterling() : funt(0), shill(0), pence(0) {}

    Sterling(double decimal) {
        funt = static_cast<long>(decimal);
        decimal -= funt;
        shill = static_cast<int>(decimal * 20);
        decimal -= shill / 20.0;
        pence = static_cast<int>(decimal * 240);
    }

    Sterling(long funt, int shill, int pence) {
        this->funt = funt;  
        this->shill = shill;
        this->pence = pence;
        normalize();
    }

    void normalize() {
        if (pence >= 20) {
            shill += pence / 20;
            pence = pence % 20;
        }
        if (shill >= 20) {
            funt += shill / 20;
            shill = shill % 20;
        }
    }

    void getSterling() {
        cout << "Введите фунты: ";
        cin >> funt;
        cout << "Введите шиллинги: ";
        cin >> shill;
        cout << "Введите пенсы: ";
        cin >> pence;
        normalize();
    }

    void putSterling() const {
        cout << "$" << funt << "." << shill << "." << pence << endl;
    }

    Sterling operator+(const Sterling& s2) const {
        return Sterling(toDecimal() + s2.toDecimal());
    }
    Sterling operator-(const Sterling& s2) const {
        return Sterling(toDecimal() - s2.toDecimal());
    }
    Sterling operator*(double factor) const {
        return Sterling(toDecimal() * factor);
    }
    Sterling operator/(double divisor) const {
        return Sterling(toDecimal() / divisor);
    }
    double operator/(const Sterling& s2) const {
        return toDecimal() / s2.toDecimal();
    }

    operator double() const {
        return toDecimal();
    }
};

int main() {
    setlocale(LC_ALL, "rus"); 
    Sterling s1(9, 19, 11);
    Sterling s2(4, 15, 6);   

    cout << "Первый ";
    s1.putSterling();
    cout << "Второй ";
    s2.putSterling();


    Sterling result = s1 + s2;
    cout << "После добавления: ";
    result.putSterling();

    result = s1 - s2;
    cout << "После вычитания: ";
    result.putSterling();

    result = s1 * 2.5;
    cout << "После умножения на 2,5: ";
    result.putSterling();

    result = s1 / 2.0;
    cout << "После деления на 2,0: ";
    result.putSterling();

    double division_result = s1 / s2;
    cout << "Разделение двух объектов Sterling: " << division_result << endl;

    double decimal_value = double(s1);
    cout << "Десятичное представление s1: " << decimal_value << endl;

    return 0;
}

