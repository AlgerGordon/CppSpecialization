//
// Created by General on 11.05.2020.
//

#include <iostream>
#include <set>
#include <map>
#include <string>

using namespace std;


int main() {

    int n;
    cin >> n;
    string operation_code, word1, word2, tmp_word;
    map<string, set<string>> word_to_synonyms;
    for (int ind = 0; ind < n; ++ind) {
        cin >> operation_code;
        if (operation_code == "COUNT") {
            cin >> tmp_word;
            if (word_to_synonyms.count(tmp_word) > 0) {
                cout << word_to_synonyms[tmp_word].size() << endl;
            } else {
                cout << 0 << endl;
            }
        } else {
            cin >> word1 >> word2;
            if (operation_code == "CHECK") {
                if ( (word_to_synonyms.count(word1) == 0) \
                    || (word_to_synonyms.count(word2) == 0)) {
                    cout << "NO" << endl;
                } else {
                    if (word_to_synonyms.count(word1) == 1) {
                        if (word_to_synonyms[word1].count(word2) > 0) {
                            cout << "YES" << endl;
                            continue;
                        }
                    }
                    if (word_to_synonyms.count(word2) == 1) {
                        if (word_to_synonyms[word2].count(word1) > 0) {
                            cout << "YES" << endl;
                            continue;
                        }
                    }
                    cout << "NO" << endl;
                }
            } else if (operation_code == "ADD") {
                word_to_synonyms[word1].insert(word2);
                word_to_synonyms[word2].insert(word1);
            }
        }
    }
    return 0;
}