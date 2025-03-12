#include <iostream>
using namespace std;


class safearray {
private:
    int arr[100];
    int lower, upper; 
public:
    safearray(int l, int u) {
        if (u - l + 1 > 100) {
            cout << "Ошибка: диапазон выходит за пределы массива!" << endl;
            exit(1);
        }
        lower = l;
        upper = u;
    }

    int& operator[](int index) {
        if (index < lower || index > upper) {
            cout << "Ошибка: выход за границы массива!" << endl;
            exit(1);
        }
        return arr[index - lower];
    }

    void display() {
        for (int i = 0; i <= upper - lower; i++) {
            cout << "arr[" << (i + lower) << "] = " << arr[i] << endl;
        }
    }
};

int main() {
    setlocale(LC_ALL, "rus"); 
    safearray sa(100, 175);

    for (int i = 100; i <= 175; i++) {
        sa[i] = i * 2;
    }

    sa.display();

    return 0;
}