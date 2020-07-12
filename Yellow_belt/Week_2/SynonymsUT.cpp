//
// Created by General on 11.05.2020.
//

#include <iostream>
#include <set>
#include <map>
#include <string>
#include <exception>
#include <sstream>

using namespace std;

using Synonyms = map<string, set<string>>;

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

template<class T>
ostream& operator << (ostream& os, const set<T>& s) {
    os << "{";
    bool first = true;
    for (const auto& item : s) {
        if (!first) {
            os << ", ";
        }
        first = false;
        os << item;
    }
    return os << "}";
}

template<class K, class V>
ostream& operator << (ostream& os, const map<K, V>& m) {
    os << "{";
    bool first = true;
    for (const auto& kv : m) {
        if (!first) {
            os << ", ";
        }
        first = false;
        os << kv.first << ": " << kv.second;
    }
    return os << "}";
}



template <class T, class U>
void AssertEqual(const T& t, const U& u, const string& hint) {
    if (t != u) {
        ostringstream  os;
        os << "Assertion failed: " << t << " != " << u << " "
            << "Hint: " << hint;
        throw runtime_error(os.str());
    }
}

void Assert(bool b, const string& hint) {
    AssertEqual(b,true, hint);
}


void TestAddSynonyms() {
    {
        Synonyms empty;
        AddSynonyms(empty, "a", "b");
        const Synonyms expected = {
                {"a",{"b"}},
                {"b",{"a"}}
        };
        AssertEqual(empty, expected, "Add to empty");
    }

    {
        Synonyms synonyms = {
                {"a", {"b"}},
                {"b", {"a", "c"}},
                {"c", {"b"}}
        };
        AddSynonyms(synonyms, "a", "c");
        const Synonyms expected = {
                {"a", {"b", "c"}},
                {"b", {"a", "c"}},
                {"c", {"b", "a"}}
        };
        AssertEqual(synonyms, expected, "Add to non-empty");
    }
}

void TestCount() {
    {
        Synonyms empty;
        AssertEqual(GetSynonymsCount(empty, "a"), 0u, "count for empty");
    }
    {
        Synonyms synonyms = {
                {"a", {"b", "c"}},
                {"b", {"a"}},
                {"c", {"a"}}
        };
        AssertEqual(GetSynonymsCount(synonyms, "a"), 2u, "count for a");
        AssertEqual(GetSynonymsCount(synonyms, "b"), 1u, "count for b");
        AssertEqual(GetSynonymsCount(synonyms, "z"), 0u, "count for z");
    }

}

void TestAreSynonyms() {
    {
        Synonyms empty;
        Assert(!AreSynonyms(empty, "a", "b"), "empty a b");
        Assert(!AreSynonyms(empty, "b", "a"), "empty b a");
    }
    {
        Synonyms synonyms = {
                {"a", {"b", "c"}},
                {"b", {"a"}},
                {"c", {"a"}}
        };
        Assert(AreSynonyms(synonyms, "a", "b"), "");
        Assert(AreSynonyms(synonyms, "b", "a"), "");
        Assert(AreSynonyms(synonyms, "a", "c"), "");
        Assert(AreSynonyms(synonyms, "c", "a"), "");
        Assert(!AreSynonyms(synonyms, "b", "c"), "");
    }
}

class TestRunner {
public:
     template<class TestFunc>
    void RunTest(TestFunc func, const string &test_name) {
        try {
            func();
            cerr << test_name << " OK" << endl;
        } catch (runtime_error &e) {
            ++fail_count;
            cerr << test_name << " fail: " << e.what() << endl;
        }
    }
    ~TestRunner() {
        if (fail_count > 0) {
            cerr << fail_count << " test failed. Terminate";
            exit(1);
        }
    }
private:
    int fail_count = 0;
};


void TestAll() {
    TestRunner tr;
    tr.RunTest(TestAreSynonyms, "TestAreSynonyms");
    tr.RunTest(TestCount, "TestCount");
    tr.RunTest(TestAddSynonyms, "TestAddSynonyms");
}



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