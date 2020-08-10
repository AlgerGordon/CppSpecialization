#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Prof {
public:
    Prof(const string& name, const string& prof = "Person")
            : name_(name), prof_(prof) {}

    virtual void Walk (const string& destination) const {
        cout << prof_ << ": " << name_ << " walks to: " << destination << endl;
    }

    string GetName() const {
        return name_;
    }

    string GetProf() const {
        return prof_;
    }

protected:
    const string name_;
    const string prof_;
};

class Student : public Prof {
public:

    Student(const string& name, const string& favouriteSong)
            : Prof(name, "Student"), FavouriteSong(favouriteSong) {}

    void Learn() const {
        cout << "Student: " << GetName() << " learns" << endl;
    }

    void Walk(const string& destination) const override {
        Prof::Walk(destination);
        SingSong();
    }

    void SingSong() const {
        cout << "Student: " << GetName() << " sings a song: " << FavouriteSong << endl;
    }

private:
    const string FavouriteSong;
};


class Teacher : public Prof {
public:
    Teacher(const string& name, const string& subject)
            : Prof(name, "Teacher"), Subject(subject) {}

    void Teach() {
        cout << "Teacher: " << GetName() << " teaches: " << Subject << endl;
    }

private:
    const string Subject;
};


class Policeman : public Prof {
public:
    Policeman(const string& name)
            : Prof(name, "Policeman") {}

    void Check(Prof& prof) {
        cout << "Policeman: " << GetName() << " checks " << prof.GetProf()
             << ". " << prof.GetProf() << "'s name is: " << prof.GetName() << endl;
    }
};


void VisitPlaces(Prof& prof, const vector<string>& places) {
    for (const auto& place : places)
        prof.Walk(place);
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