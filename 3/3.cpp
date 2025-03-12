#include <iostream>
using namespace std;

class Fraction {
private:
    int chis;
    int znam;
    bool valid;

    int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    void lowterms() {
        int divisor = gcd(chis, znam);
        chis /= divisor;
        znam /= divisor;
    }

public:
    Fraction(int num = 0, int denom = 1) : chis(num), znam(denom), valid(true) {
        if (znam == 0) {
            cout << "Ошибка: знаменатель не может быть равен нулю." << endl;
            valid = false;
        }
        else {
            lowterms();
        }
    }

    bool isValid() const {
        return valid;
    }

    Fraction operator+(const Fraction& f) const {
        return Fraction(chis * f.znam + f.chis * znam, znam * f.znam);
    }

    Fraction operator-(const Fraction& f) const {
        return Fraction(chis * f.znam - f.chis * znam, znam * f.znam);
    }

    Fraction operator*(const Fraction& f) const {
        return Fraction(chis * f.chis, znam * f.znam);
    }

    Fraction operator/(const Fraction& f) const {
        if (f.chis == 0) {
            cout << "Ошибка: деление на ноль." << endl;
            return Fraction();
        }
        return Fraction(chis * f.znam, znam * f.chis);
    }

    bool operator==(const Fraction& f) const {
        return chis == f.chis && znam == f.znam;
    }

    bool operator!=(const Fraction& f) const {
        return !(*this == f);
    }

    void print() const {
        if (valid) {
            cout << chis << "/" << znam << endl;
        }
        else {
            cout << "Некорректная дробь" << endl;
        }
    }
};

int main() {
    setlocale(LC_ALL, "rus");
    Fraction f1(2, 3);
    Fraction f2(3, 4);

    Fraction result = f1 + f2;
    result.print();
    result = f1 - f2;
    result.print();
    result = f1 * f2;
    result.print();
    result = f1 / f2;
    result.print();

    if (f1 == f2) {
        cout << "Дроби равны!" << endl;
    }
    else {
        cout << "Дроби не равны!" << endl;
    }

    Fraction userInput;
    do {
        int num, denom;
        cout << "Введите дробь (числитель знаменатель): ";
        cin >> num >> denom;
        if (denom == 0) {
            cout << "Ошибка: знаменатель не может быть равен нулю!" << endl;
            break; 
        }
        userInput = Fraction(num, denom);
        if (!userInput.isValid()) {
            cout << "Некорректная дробь. Попробуйте снова." << endl;
            break;
        }

        cout << "Результат сложения: ";
        (userInput + f2).print();
        cout << "Результат вычитания: ";
        (userInput - f2).print();
        cout << "Результат умножения: ";
        (userInput * f2).print();
        cout << "Результат деления: ";
        (userInput / f2).print();

        if (num == 0 && denom == 1) { 
            break;
        }

    } while (true);

    return 0;
}



