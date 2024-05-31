#include <iostream>

class Quadrilateral {
public:
    virtual double area() const = 0; //функція обчислення площі
    virtual double perimeter() const = 0; //функція обчислення периметру
    virtual ~Quadrilateral() {} // деструктор
};

class Square : public Quadrilateral {
private:
    double side;

public:
    Square(double s) : side(s) {} //конструктор
    virtual double area() const override { return side * side; } //перевизначення функції обчислення площі
    virtual double perimeter() const override { return 4 * side; } //перевизначення функції обчислення периметру
};

class Rectangle : public Quadrilateral {
private:
    double length;
    double width;

public:
    Rectangle(double l, double w) : length(l), width(w) {} //конструктор
    virtual double area() const override { return length * width; } //перевизначення функції обчислення площі
    virtual double perimeter() const override { return 2 * (length + width); } //перевизначення функції обчислення периметру
};

class Parallelogram : public Quadrilateral {
private:
    double base;
    double height;

public:
    Parallelogram(double b, double h) : base(b), height(h) {} //конструктор
    virtual double area() const override { return base * height; } //перевизначення функції обчислення площі
    virtual double perimeter() const override { return 2 * (base + height); } //перевизначення функції обчислення периметру
};

class Trapezoid : public Quadrilateral {
private:
    double base1;
    double base2;
    double height;
    double side1;
    double side2;

public:
    Trapezoid(double b1, double b2, double h, double s1, double s2) : base1(b1), base2(b2), height(h), side1(s1), side2(s2) {} //конструктор
    virtual double area() const override { return (base1 + base2) * height / 2; } //перевизначення функції обчислення площі
    virtual double perimeter() const override { return base1 + base2 + side1 + side2; } //перевизначення функції обчислення периметру
};

int main() {
    Square square(5.0);
    Rectangle rectangle(4.0, 6.0);
    Parallelogram parallelogram(4.0, 5.0);
    Trapezoid trapezoid(3.0, 6.0, 4.0, 2.0, 3.0);

    std::cout << "Square Area: " << square.area() << ", Perimeter: " << square.perimeter() << std::endl;
    std::cout << "Rectangle Area: " << rectangle.area() << ", Perimeter: " << rectangle.perimeter() << std::endl;
    std::cout << "Parallelogram Area: " << parallelogram.area() << ", Perimeter: " << parallelogram.perimeter() << std::endl;
    std::cout << "Trapezoid Area: " << trapezoid.area() << ", Perimeter: " << trapezoid.perimeter() << std::endl;

    return 0;
}
