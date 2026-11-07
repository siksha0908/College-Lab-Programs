//Define a class Shape whose attributes are radius, length and width calculate the perimeter of the rectangle and circle. Use constructors and destructors.

#include <iostream>
#include <cmath>

using namespace std;

class Shape {
private:
    double radius;
    double length;
    double width;

public:
    
    Shape(double r) : radius(r), length(0), width(0) {
        cout << "Circle created with radius: " << radius << endl;
    }

    Shape(double l, double w) : length(l), width(w), radius(0) {
        cout << "Rectangle created with length: " << length << " and width: " << width << endl;
    }

    ~Shape() {
        cout << "Shape object destroyed." << endl;
    }

    double calculateCirclePerimeter() const {
        if (radius > 0) {
            return 2 * 3.14159 * radius;
        } else {
            cout << "Invalid radius for circle." << endl;
            return 0;
        }
    }

    double calculateRectanglePerimeter() const {
        if (length > 0 && width > 0) {
            return 2 * (length + width);
        } else {
            cout << "Invalid length or width for rectangle." << endl;
            return 0;
        }
    }
};

int main() {

    Shape circle(5);
    cout << "Perimeter of the circle: " << circle.calculateCirclePerimeter() << endl;

    Shape rectangle(4, 6);
    cout << "Perimeter of the rectangle: " << rectangle.calculateRectanglePerimeter() << endl;

    return 0;
}