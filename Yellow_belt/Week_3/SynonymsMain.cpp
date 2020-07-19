//
// Created by General on 11.05.2020.
//

#include <iostream>

using namespace std;
//comment

#include "synonyms/Synonyms.h"
#include "synonyms/SynonymsUT.h"


int main() {

    TestAll();

    int n;
    cin >> n;
    string operation_code, first_word, second_word, tmp_word;
    Synonyms word_to_synonyms;

    for (int ind = 0; ind < n; ++ind) {
        cin >> operation_code;
        if (operation_code == "COUNT") {
            cin >> tmp_word;
            cout << GetSynonymsCount(word_to_synonyms, tmp_word) << endl;
        } else {
            cin >> first_word >> second_word;
            if (operation_code == "CHECK") {
                if (AreSynonyms(word_to_synonyms, first_word, second_word)) {
                    cout << "YES" << endl;
                } else {
                    cout << "NO" << endl;
                }
            } else if (operation_code == "ADD") {
                AddSynonyms(word_to_synonyms, first_word, second_word);
            }
        }
    }
    return 0;
}
