//
// Created by General on 04.08.2020.
//

#include <iostream>
#include <string>
using namespace std;

struct Fruit {
    int health = 0;
    string type;
};

struct Apple : public Fruit {
    Apple() {
        health = 10;
        type = "apple";
    }
};

struct Orange : public Fruit {
    Orange() {
        health = 5;
        type = "orange";
    }
};

struct Pineapple : public Fruit {
    Pineapple() {
        health = 15;
        type = "pineapple";
    }
};

class Animal {
public:
    explicit Animal(const string& t = "animal") : type_(t){
    }
    void Eat(const Fruit& f) const{
        cout << type_ << " eats " << f.type << ". " << f.health << "hp." << endl;
    }
    void SetType(const string& newType){
        //type_ =  newType;
    }
    string GetType() const{
        return type_;
    }
protected:
    const string type_ = "animal";
};

class Cat : public Animal {
public:
    Cat() : Animal("cat"){
    }
    void Meow() const {
        cout << "meow!" << endl;
    }
};

class Dog : public Animal {
public:
    Dog() : Animal("dog") {
    }
};

void DoMeal(Animal& a, const Fruit& f) {
    a.Eat(f);
}

int main() {
    Apple a;
    Orange o;
    Pineapple p;

    Cat c;
    Dog d;

    c.Meow();
    c.Eat(o);
    d.Eat(a);
    DoMeal(d, p);

    return 0;
}