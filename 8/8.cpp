#include <iostream>
#include <iomanip>
using namespace std;

class sterling;

class bMoney {
private:
    long dol;
    int cents;

public:
    bMoney() : dol(0), cents(0) {}
    explicit bMoney(double amount) {
        dol = static_cast<long>(amount);
        cents = static_cast<int>((amount - dol) * 100);
    }
    explicit bMoney(long dol, int cents) : dol(dol), cents(cents) {}

    void putMoney() const {
        cout << "$" << dol << "." << setfill('0') << setw(2) << cents << endl;
    }

    bMoney operator+(const bMoney& bm2) const {
        long totalCents = (dol * 100 + cents) + (bm2.dol * 100 + bm2.cents);
        return bMoney(totalCents / 100, totalCents % 100);
    }
    bMoney operator-(const bMoney& bm2) const {
        long totalCents = (dol * 100 + cents) - (bm2.dol * 100 + bm2.cents);
        return bMoney(totalCents / 100, totalCents % 100);
    }
    bMoney operator*(long double factor) const {
        double total = (dol + cents / 100.0) * factor;
        return bMoney(total);
    }
    long double operator/(const bMoney& bm2) const {
        return (dol + cents / 100.0) / (bm2.dol + bm2.cents / 100.0);
    }
    bMoney operator/(long double divisor) const {
        return bMoney((dol + cents / 100.0) / divisor);
    }

    explicit operator sterling() const;
};

class sterling {
private:
    long funt;
    int shill;
    int pence;

    double toDecimal() const {
        return funt + shill / 20.0 + pence / 240.0;
    }

public:
    sterling() : funt(0), shill(0), pence(0) {}

    explicit sterling(double decimal) {
        funt = static_cast<long>(decimal);
        decimal -= funt;
        shill = static_cast<int>(decimal * 20);
        decimal -= shill / 20.0;
        pence = static_cast<int>(decimal * 240);
    }
    explicit sterling(long funt, int shill, int pence) : funt(funt), shill(shill), pence(pence) {
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
    void putSterling() const {
        cout << "$" << funt << "." << shill << "." << pence << endl;
    }

    explicit operator bMoney() const {
        return bMoney(toDecimal() * 50); 
    }

    sterling operator+(const sterling& s2) const {
        return sterling(toDecimal() + s2.toDecimal());
    }
    sterling operator-(const sterling& s2) const {
        return sterling(toDecimal() - s2.toDecimal());
    }
    sterling operator*(double factor) const {
        return sterling(toDecimal() * factor);
    }
    sterling operator/(double divisor) const {
        return sterling(toDecimal() / divisor);
    }
};

bMoney::operator sterling() const {
    return sterling((dol + cents / 100.0) / 50); 
}

int main() {
    setlocale(LC_ALL, "rus"); 
    double amount;
    cout << "Введите сумму в долларах: ";
    cin >> amount;

    bMoney bMoneyAmount(amount);
    sterling sterlingAmount = static_cast<sterling>(bMoneyAmount);

    cout << "Сумма в долларах: ";
    bMoneyAmount.putMoney();

    cout << "Эквивалент в фунтах стерлингов: ";
    sterlingAmount.putSterling();

    sterlingAmount = sterling(10, 5, 0);
    bMoneyAmount = static_cast<bMoney>(sterlingAmount);

    cout << "Эквивалент в долларах: ";
    bMoneyAmount.putMoney();

    return 0;
}
