//
// Created by General on 06.08.2020.
//

//
// Created by General on 04.08.2020.
//

#include <iostream>
#include <string>
#include <vector>
#include <memory>

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
    //  PURE virtual function, or abstract method.
    //  It MUST be implemented in derived class
    //  If there is ANY abstract method, than CLASS IS ABSTRACT
    virtual void Voice() const = 0;
protected:
    const string type_ = "animal";
};

class Cat : public Animal {
public:
    Cat() : Animal("cat"){
    }
    void Voice() const override {
        cout << "Meow!" << endl;
    }
};

class Dog : public Animal {
public:
    Dog() : Animal("dog") {
    }
    void Voice() const override {
        cout << "Bark!" << endl;
    }
};

class Parrot : public Animal{
public:
    Parrot(const string& name) : Animal("parrot"), name_(name){
    }
    void Voice() const override{
        cout << name_ << " is good!" << endl;
    }
private:
    const string name_;
};

class Horse : public Animal {
public:
    Horse() : Animal("horse"){

    }
    void Voice() const override {
        cout << "Yeee ha!" << endl;
    }
};

// Parameters should be passed BY REFERENCE (!)
// Otherwise, basic's class implementation of virtual function will be used
void MakeSound(const Animal& animal) {
    animal.Voice();
}

int main() {
    Cat cat;
    Dog dog;
    Parrot parrot("Kesha");
    Horse horse;

    MakeSound(cat);
    MakeSound(dog);
    MakeSound(parrot);
    MakeSound(horse);

    // Work with shared_ptr

    // COMPILE ERROR: couldn't create vector of references
    // vector<Animal&> animals;

    // It's the useful type for references to use in vector.
    // It has alike logic for iterators
    // As parameter basic class passes
    shared_ptr<Animal> animals;

    animals = make_shared<Cat>();
    cout << endl << "Shared_ptr:" << endl;
    // cout: "Meow!"
    animals->Voice();

    // Lets create vector with all kind of animals
    // Parameters of make_shared are passed to constructors
    vector<shared_ptr<Animal>> animalsVec = {
            make_shared<Cat>(),
            make_shared<Dog>(),
            make_shared<Horse>(),
            make_shared<Parrot>("Kesha"),
    };


    cout << endl << "Vector of shared_ptr:" << endl;
    // shared_ptr should be passed BY VALUE (!)
    for (auto animal : animalsVec ){
        // Due to animal is ptr, than it MUST be dereferenced
        MakeSound(*animal);
    }


    return 0;
}