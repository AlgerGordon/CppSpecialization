//
// Created by General on 11.05.2020.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void printVec(const vector<string>& v) {
    for (const auto& item : v) {
        cout << item << " ";
    }
}

bool strComp(const string& l, const string& r){
    for (int ind = 0; ind < min(l.size(), r.size()); ++ind) {
        if (tolower(l[ind]) < tolower(r[ind])) {
            return true;
        } else if (tolower(l[ind]) > tolower(r[ind])){
            return false;
        }
    }
    return l.size() < r.size();

//    sort(begin(v), end(v),
//            // компаратор для сортировки — лямбда-функция, сравнивающая строки без учёта регистра
//         [](const string& l, const string& r) {
//             // сравниваем лексикографически...
//             return lexicographical_compare(
//                     // ... все символы строки l ...
//                     begin(l), end(l),
//                     // ... со всеми символами строки r ...
//                     begin(r), end(r),
//                     // ..., используя в качестве компаратора сравнение отдельных символов без учёта регистра
//                     [](char cl, char cr) { return tolower(cl) < tolower(cr); }
//             );
//         }
//    );
}

int main() {
    int n;
    cin >> n;
    vector<string> v(n);
    for (int ind = 0; ind < n; ++ind) {
        cin >> v[ind];
    }
    sort(begin(v), end(v), strComp);
    printVec(v);
    return 0;

}