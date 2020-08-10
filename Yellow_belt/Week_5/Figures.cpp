//
// Created by General on 09.08.2020.
//


#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

const double pi = 3.14;

class Figure{
public:
    Figure(const string& type) : type_(type) {}
    virtual string Name() = 0;
    virtual double Perimeter() = 0;
    virtual double Area() = 0;

    string type_;
};

class Triangle : public Figure {
public:
    Triangle(int a, int b, int c) : Figure("TRIANGLE"), a_(a), b_(b), c_(c) {
        perimeter_ =  a_ + b_ + c_;
        double p = perimeter_ / 2;
        area_ = sqrt(p * (p - a_) * (p - b_) * (p - c_));
    }
    string Name() override{
        return type_;
    }
    double Perimeter() override {
        return perimeter_;
    }
    double Area() override {
        return area_;
    }
private:
    int a_;
    int b_;
    int c_;
    double perimeter_;
    double area_;
};

class Rect : public Figure {
public:
    Rect(int width, int height) : Figure("RECT"), width_(width), height_(height){
        perimeter_ = (width_ + height_) * 2;
        area_ = width_ * height_;
    }
    string Name() override{
        return type_;
    }
    double Perimeter() override{
        return perimeter_;
    }
    double Area() override {
        return area_;
    }
private:
    int width_;
    int height_;
    double perimeter_;
    double area_;
};

class Circle : public Figure {
public:
    Circle(int r) : Figure("CIRCLE"), r_(r) {
        perimeter_ = 2 * pi * r_;
        area_ = pi * r_ * r_;
    }
    string Name() override{
        return type_;

    }
    double Perimeter() override{
        return perimeter_;
    }
    double Area() override{
        return area_;
    }
private:
    int r_;
    double perimeter_;
    double area_;
};

shared_ptr<Figure> CreateFigure(istream& is) {
    string figureType;
    is >> figureType;
    if (figureType == "RECT") {
        int width, height;
        is >> width >> height;
        return make_shared<Rect>(width, height);
    } else if (figureType == "TRIANGLE"){
        int a, b, c;
        is >> a >> b >> c;
        return make_shared<Triangle>(a, b, c);
    } else if (figureType == "CIRCLE") {
        int r;
        is >> r;
        return make_shared<Circle>(r);
    }
    throw std::invalid_argument("invalid figure name was specified");
}

int main() {
    vector<shared_ptr<Figure>> figures;
    for (string line; getline(cin, line); ) {
        istringstream is(line);

        string command;
        is >> command;
        if (command == "ADD") {
            // Пропускаем "лишние" ведущие пробелы.
            // Подробнее об std::ws можно узнать здесь:
            // https://en.cppreference.com/w/cpp/io/manip/ws
            is >> ws;
            figures.push_back(CreateFigure(is));
        } else if (command == "PRINT") {
            for (const auto& current_figure : figures) {
                cout << fixed << setprecision(3)
                     << current_figure->Name() << " "
                     << current_figure->Perimeter() << " "
                     << current_figure->Area() << endl;
            }
        }
    }
    return 0;
}