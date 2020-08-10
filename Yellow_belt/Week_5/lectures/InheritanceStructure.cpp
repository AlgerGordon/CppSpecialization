//
// Created by General on 04.08.2020.
//

#include <iostream>
#include <string>
using namespace std;

struct Log {
    explicit Log(const string& name) : n(name) {
        cout << "+ " << n << endl;
    }
    ~Log() {
        cout << "- " << n << endl;
    }
    string n;
};

struct Fruit {
    explicit Fruit(const string& t) : l(t + " (Fruit)"){
    }
    const Log l;
};

struct Apple : public Fruit {
    explicit Apple(const string& t) : Fruit(t), l(t){
    }
    const Log l;
};

class AppleTree{
public:
    // Список инициализиции не решает порядок инициализации
//    ERROR: AppleTree::type' will be initialized after field 'l'
//    AppleTree(const string& t) : type(t), l("AppleTree"), a1(type + "a1"), a2(type + "a2"){
//    }
    explicit AppleTree(const string& t) : l("AppleTree"), a1("a1"), a2("a2"), type(t){
    }

    // ВАЖЕН порядок, в котором задекларированы переменные
    const Log l = Log("AppleTree");
    Apple a1;
    Apple a2;
    string type;
};



int main() {
    AppleTree at("AppleTree");


    return 0;
}