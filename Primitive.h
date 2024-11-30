#ifndef PRIMITIVE_H
#define PRIMITIVE_H

#include <string>
#include <iostream>
#include <memory>

class Primitive {
public:
    Primitive(const std::string& name, const std::string& type) : name(name), type(type) {}

    std::string getName() const {
        return name;
    }

    std::string getType() const {
        return type;
    }

    virtual ~Primitive() = default; // Важно для полиморфизма

    virtual void draw() = 0; // Виртуальный метод для отрисовки (будет реализован в производных классах)
    virtual std::string get() const = 0; // Чисто виртуальный метод

private:
    std::string name;
    std::string type;
};

class Circle : public Primitive {
public:
    Circle(const std::string& name, double radius) : Primitive(name, "circle"), radius(radius) {}
    
    void draw() override {
        std::cout << "Отрисовка круга " << getName() << " (радиус: " << radius << ")" << std::endl;
    }
    
    std::string get() const override {
        return "круга " + getName() + " (радиус: " + std::to_string(radius) + ")";
    }

private:
    double radius;
};

class Rectangle : public Primitive {
public:
    Rectangle(const std::string& name, double width, double height) :
        Primitive(name, "rectangle"), width(width), height(height) {}

    void draw() override {
        std::cout << "Отрисовка прямоугольника " << getName() << " (ширина: " << width << ", высота: " << height << ")" << std::endl;
    }
    
    std::string get() const override {
        return "прямоугольника " + getName() + " (ширина: " + std::to_string(width) + ", высота: " + std::to_string(height) + ")";
    }

private:
    double width;
    double height;
};

// Другие примитивы (Square, Triangle) можно добавить аналогично...

#endif // PRIMITIVE_H