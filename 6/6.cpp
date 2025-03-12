#include <iostream>
#include <cmath>
using namespace std;

class Polar {
private:
    double r;  
    double theta;  

public:
    Polar(double radius = 0.0, double angle = 0.0) : r(radius), theta(angle) {}

    Polar operator+(const Polar& other) const {
        double x1 = r * cos(theta);
        double y1 = r * sin(theta);
        double x2 = other.r * cos(other.theta);
        double y2 = other.r * sin(other.theta);
        double x_result = x1 + x2;
        double y_result = y1 + y2;
        double r_result = sqrt(x_result * x_result + y_result * y_result);
        double theta_result = atan2(y_result, x_result);

        return Polar(r_result, theta_result);
    }

    void print() const {
        cout << "Полярные координаты:  " << r << " " << theta << endl;
    }
};

int main() {
    setlocale(LC_ALL, "rus"); 
    Polar p1(5.0, 3.14 / 4);
    Polar p2(3.0, 3.14 / 6);

    cout << "Первый ";
    p1.print();
    cout << "Второй ";
    p2.print();

    Polar result = p1 + p2;

    cout << "Результат сложения: ";
    result.print();

    return 0;
}
