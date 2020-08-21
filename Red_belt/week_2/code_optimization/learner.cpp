#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <sstream>
#include <set>
#include <fstream>
#include <profile.h>

using namespace std;

class Learner {
private:
    vector<string> dict_;
    set<string> set_dict_;
public:
    int Learn(const vector<string>& words) {
        int newWords = 0;
        for (const auto& word : words) {
            if (set_dict_.count(word) == 0) {
                ++newWords;
                set_dict_.insert(word);
            }
        }
        return newWords;
    }

    vector<string> KnownWords() {
        dict_ = {set_dict_.begin(), set_dict_.end()};
        return dict_;
    }
};

int main() {
    Learner learner;
    string line;
    // File is somewhere in cmake-build-debug
    ifstream input("io_input.txt");
    {
        LOG_DURATION("#1");
        while (getline(input, line)) {
            vector<string> words;
            stringstream ss(line);
            string word;
            while (ss >> word) {
                words.push_back(word);
            }
            learner.Learn(words);
        }
        cout << "=== known words ===\n";
        auto words = learner.KnownWords();
    }
    input.close();
    return 0;
}