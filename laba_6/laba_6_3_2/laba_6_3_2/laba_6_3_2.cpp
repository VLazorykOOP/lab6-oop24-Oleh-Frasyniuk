#include <iostream>
#include <string>

//базовий клас, що представляє особу
class Person {
protected:
    std::string name;
    int age;

public:
    //конструктор за замовчуванням
    Person() : name("Unknown"), age(0) {}

    //конструктор з параметрами
    Person(const std::string& n, int a) : name(n), age(a) {}

    //віртуальний деструктор
    virtual ~Person() {}

    //перевантаження оператора введення
    friend std::istream& operator>>(std::istream& is, Person& person) {
        std::cout << "Enter name: ";
        std::getline(is, person.name);
        std::cout << "Enter age: ";
        is >> person.age;
        return is;
    }

    //перевантаження оператора виведення
    friend std::ostream& operator<<(std::ostream& os, const Person& person) {
        os << "Name: " << person.name << ", Age: " << person.age;
        return os;
    }
};

//клас батька
class Father : virtual public Person {
public:
    //конструктори
    Father() {}
    Father(const std::string& n, int a) : Person(n, a) {}

    //перевизначення функції виведення
    virtual void printInfo() const {
        std::cout << "Father's ";
        std::cout << *this << std::endl;
    }
};

//клас мама
class Mother : virtual public Person {
public:
    //конструктори
    Mother() {}
    Mother(const std::string& n, int a) : Person(n, a) {}

    //перевизначення функції виведення
    virtual void printInfo() const {
        std::cout << "Mother's ";
        std::cout << *this << std::endl;
    }
};

//клас сина
class Son : public Father, public Mother {
public:
    //конструктори
    Son() {}
    Son(const std::string& n, int a) : Person(n, a), Father(n, a), Mother(n, a) {}

    //перевизначення функції виведення
    virtual void printInfo() const {
        std::cout << "Son's ";
        std::cout << *this << std::endl;
    }
};

int main() {
    Son son;
    std::cin >> son;
    son.printInfo();

    return 0;
}
