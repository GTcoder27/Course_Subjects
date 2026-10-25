#include <iostream>
using namespace std;

// Abstract base class
class Shape {
public:
    virtual void draw() = 0;   // Pure virtual function
    virtual double area() = 0; // Another pure virtual function
};

// Derived class 1
class Circle : public Shape {
    double radius;
public:
    Circle(double r) : radius(r) {}
    void draw() override {
        cout << "Drawing Circle\n";
    }
    double area() override {
        return 3.14 * radius * radius;
    }
};

// Derived class 2
class Rectangle : public Shape {
    double width, height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    void draw() override {
        cout << "Drawing Rectangle\n";
    }
    double area() override {
        return width * height;
    }
};

int main() {
    // Shape s; ❌ Error: Cannot instantiate abstract class

    Shape* s1 = new Circle(5);
    Shape* s2 = new Rectangle(4, 6);

    s1->draw();
    cout << "Area: " << s1->area() << endl;

    s2->draw();
    cout << "Area: " << s2->area() << endl;

    delete s1;
    delete s2;
    return 0;
}
