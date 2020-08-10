//
// Created by General on 10.08.2020.
//


#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Human {
public:
    Human(const string &name, const string &sr) : Name_(name), SocialRole_(sr) {}

    virtual void Walk(const string &destination) const {
        cout << SocialRole_ << ": " << Name_ << " walks to: " << destination << endl;
    };

    const string& getName() const {
        return Name_;
    }

    const string& getSocialRole() const {
        return SocialRole_;
    }

protected:
    const string Name_;
    const string SocialRole_;
};

class Student : public Human {
public:

    Student(const string &name, const string &favouriteSong)
            : Human(name, "Student"), FavouriteSong(favouriteSong){}

    void Learn() const {
        cout << "Student: " << Name_ << " learns" << endl;
    }

    void SingSong() const {
        cout << "Student: " << Name_ << " sings a song: " << FavouriteSong
             << endl;
    }

    void Walk(const string &destination) const override {
        cout << "Student: " << Name_ << " walks to: " << destination << endl;
        SingSong();
    }

private:
    const string FavouriteSong;
};


class Teacher : public Human {
public:

    Teacher(const string &name, const string &subject) :
        Human(name,"Teacher"), Subject(subject) {}

    void Teach() const {
        cout << "Teacher: " << Name_ << " teaches: " << Subject << endl;
    }

private:
    const string Subject;
};


class Policeman : public Human {
public:
    Policeman(const string &name) : Human(name, "Policeman") {}

    void Check(const Human &person) const {
        cout << "Policeman: " << Name_ << " checks " << person.getSocialRole() << ". "
             << person.getSocialRole()<< "'s name is: " << person.getName() << endl;
    }

};

void VisitPlaces(const Human &human, const vector<string>& places) {
    for (auto &p : places) {
        human.Walk(p);
    }
}


int main() {
    Teacher t("Jim", "Math");
    Student s("Ann", "We will rock you");
    Policeman p("Bob");

    VisitPlaces(t, {"Moscow", "London"});
    p.Check(s);
    VisitPlaces(s, {"Moscow", "London"});
    return 0;
}