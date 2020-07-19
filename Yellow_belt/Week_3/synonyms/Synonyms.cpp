//
// Created by General on 14.07.2020.
//

#include "Synonyms.h"

void AddSynonyms(Synonyms& word_to_synonyms,
                 const string& first_word, const string& second_word) {
    word_to_synonyms[first_word].insert(second_word);
    word_to_synonyms[second_word].insert(first_word);
}

size_t GetSynonymsCount(Synonyms& word_to_synonyms, const string& tmp_word) {
    if (word_to_synonyms.count(tmp_word) > 0) {
        return word_to_synonyms[tmp_word].size();
    } else {
        return 0;
    }
}

bool AreSynonyms(Synonyms& word_to_synonyms,
                 const string& first_word, const string& second_word) {
    if (word_to_synonyms.count(second_word) == 1) {
        if (word_to_synonyms[second_word].count(first_word) > 0) {
            return true;
        }
    }
    return false;
}
