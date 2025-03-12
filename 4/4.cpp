#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

class bMoney {
private:
    long double money;

public:
    explicit bMoney(long double m = 0.0) : money(m) {}

    void getMoney() {
        string str;
        cout << "Введите сумму (пример: $1234.56): ";
        cin >> str;
        money = atof(str.c_str() + 1);
    }

    void putMoney() const {
        cout << fixed << setprecision(2);
        cout << "$" << money;
    }

    bMoney operator+(const bMoney& other) const {
        return bMoney(money + other.money);
    }

    bMoney operator-(const bMoney& other) const {
        return bMoney(money - other.money);
    }

    bMoney operator*(long double value) const {
        return bMoney(money * value);
    }

    long double operator/(const bMoney& other) const {
        if (other.money == 0.0) {
            cerr << "Ошибка: деление на ноль!" << endl;
            exit(1);
        }
        return money / other.money;
    }

    bMoney operator/(long double value) const {
        if (value == 0.0) {
            cerr << "Ошибка: деление на ноль!" << endl;
            exit(1);
        }
        return bMoney(money / value);
    }
};

int main() {
    setlocale(LC_ALL, "rus"); 
    char choice;
    do {
        bMoney m1, m2, result;
        long double value;

        m1.getMoney();
        m2.getMoney();
        cout << "Введите число: ";
        cin >> value;

        result = m1 + m2;
        cout << "Сумма: "; result.putMoney(); cout << endl;

        result = m1 - m2;
        cout << "Разность: "; result.putMoney(); cout << endl;

        result = m1 * value;
        cout << "Умножение: "; result.putMoney(); cout << endl;

        cout << "Деление денег: " << (m1 / m2) << endl;

        result = m1 / value;
        cout << "Деление на число: "; result.putMoney(); cout << endl;

        cout << "Продолжить (y/n)? ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    return 0;
}


