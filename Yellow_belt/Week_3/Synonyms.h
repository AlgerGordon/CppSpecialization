//
// Created by General on 13.07.2020.
//
#pragma once

#ifndef WEEK_3_SYNONIMS_H
#define WEEK_3_SYNONIMS_H

#endif //WEEK_3_SYNONIMS_H

#include <set>
#include <map>
#include <string>
#include <sstream>

using namespace std;
//comment


using Synonyms = map<string, set<string>>;

// Interface

void AddSynonyms(Synonyms& word_to_synonyms,
                 const string& first_word, const string& second_word);
size_t GetSynonymsCount(Synonyms& word_to_synonyms, const string& tmp_word);
bool AreSynonyms(Synonyms& word_to_synonyms,
                 const string& first_word, const string& second_word);

