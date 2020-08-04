//
// Created by General on 01.08.2020.
//

#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <stack>

using namespace std;

int main() {
    int N;
    cin >> N;
    // Use vector for access to certain element
    // push_back() and pop_back() in priority
    vector<int> v(N);
    while (!v.empty()) {
        v.erase(v.begin());
    }
    cout << "Empty! (Slow)" << endl;

    // Use deque for push_front() and pop_front()
    deque<int> d(N);
    while (!d.empty()) {
        d.pop_front();
    }
    cout << "Empty! (Fast)" << endl;

    // Use queue for partial functionality
    // deleting from begin and pushing to the end
    // q.push(x), q.pop()
    // q.front(), q.back()
    // q.size(), q.empty()

    // Use stack if access to certain element is not necessary
    // st.push(x) st.pop()
    // st.top()
    // st.size(), st.empty()

    return 0;
}