//
// Created by General on 03.08.2020.
//

#include <iostream>
#include <functional>
#include <algorithm>
#include "../MyPrint/MyPrint.h"
#include "../TestRunner/TestRunner.h"

using namespace std;

template<typename RandomIt>
pair<RandomIt, RandomIt>
FindStartsWith(RandomIt range_begin, RandomIt range_end, const string &prefix)
{
    function<bool(const string&, const string&)> compLB {
            [](const string& lhs, const string& rhs){
                if (lhs.empty()){
                    return true;
                }
                int commonLength = min(lhs.length(), rhs.length());
                string lhs_tmp = lhs.substr(0,commonLength);
                string rhs_tmp = rhs.substr(0, commonLength);
                if (lhs_tmp < rhs_tmp) {
                    return true;
                } else if (lhs_tmp == rhs_tmp) {
                    return lhs.length() < rhs.length();
                } else {
                    return false;
                }
            }
    };
    function<bool(const string&, const string&)> compUB {
            [](const string& lhs, const string& rhs){
                // elements in vector with !(value < element) == true should go before
                // elements with false expression
                if (lhs.empty()){
                    return true;
                }
                int commonLength = min(lhs.length(), rhs.length());
                return rhs.compare(0, commonLength, lhs, 0, commonLength) > 0;
            }
    };
    pair<RandomIt,RandomIt> res;
    res.first = lower_bound(range_begin, range_end, prefix, compLB);
    res.second = upper_bound(range_begin, range_end, prefix, compUB);
    return res;

//    Authors solution:
//
//    // Все строки, начинающиеся с prefix, больше или равны строке "<prefix>"
//    auto left = lower_bound(range_begin, range_end, prefix);
//
//    // Составим строку, которая в рамках буквенных строк является
//    // точной верхней гранью множества строк, начинающихся с prefix
//    string upper_bound = prefix;
//    ++upper_bound[upper_bound.size() - 1];
//
//    // Первое встреченное слово, не меньшее upper_bound,
//    // обязательно является концом полуинтервала
//    auto right = lower_bound(range_begin, range_end, upper_bound);
//
//    return {left, right};
}

void TestEmptyInterval()
{
    {
        vector<string> s = {"aa", "ac", "dd", "gg", "yz"};

        auto p = FindStartsWith(begin(s), end(s), "ab");

        Assert(p.first == p.second, "");
        AssertEqual(*(p.first), "ac", "");

        p = FindStartsWith(begin(s), end(s), "abb");

        Assert(p.first == p.second, "");
        AssertEqual(*(p.first), "ac", "");

        p = FindStartsWith(begin(s), end(s), "abcdtggg");

        Assert(p.first == p.second, "!");
        AssertEqual(*(p.first), "ac", "");

        p = FindStartsWith(begin(s), end(s), "dc");

        Assert(p.first == p.second, "");

        AssertEqual(*(p.first), "dd", "");

        p = FindStartsWith(begin(s), end(s), "dca");

        Assert(p.first == p.second, "");
        AssertEqual(*(p.first), "dd", "");

        p = FindStartsWith(begin(s), end(s), "zzzz");

        Assert(p.first == p.second, "");
        Assert(p.first == end(s), "");

        p = FindStartsWith(begin(s), end(s), "");

        Assert(p.first == p.second, "!");
        Assert(p.first == begin(s), "");

        p = FindStartsWith(end(s), end(s), "z");

        Assert(p.first == p.second, "");
        Assert(p.first == end(s), "");
    }

    {
        set<string> s = {"ba", "bac", "dd", "gg", "yz"};

        auto p = FindStartsWith(begin(s), end(s), "ab");

        Assert(p.first == p.second, "");
        AssertEqual(*(p.first), "ba", "");
    }

    {
        vector<string> s = {"aa", "aa", "aaa", "aaaa", "aaaaaaa", "aab", "z", "za", "zz", "zzzz"};

        auto p = FindStartsWith(begin(s), end(s), "zzzzz");

        Assert(p.first == p.second, "");
        Assert(p.first == end(s), "");
    }
}

void TestNotEmptyInterval()
{
    {
        vector<string> s = {"aa", "aa", "aaa", "aaaa", "aaaaaaa", "aab"};

        auto p = FindStartsWith(begin(s), end(s), "a");
        AssertEqual(vector<string>(p.first, p.second), vector<string>{"aa", "aa", "aaa", "aaaa", "aaaaaaa", "aab"}, "1!");

        p = FindStartsWith(begin(s), end(s), "aaa");
        AssertEqual(vector<string>(p.first, p.second), vector<string>{"aaa", "aaaa", "aaaaaaa"}, "2!");
    }

    {
        vector<string> s = {"aa", "aa", "aaa", "aaaa", "aaaaaaa", "aab", "z", "za", "zz", "zzzz"};

        auto p = FindStartsWith(begin(s), end(s), "z");
        AssertEqual(vector<string>(p.first, p.second), vector<string>{"z", "za", "zz", "zzzz"}, "");

        p = FindStartsWith(begin(s), end(s), "zzzz");
        AssertEqual(vector<string>(p.first, p.second), vector<string>{"zzzz"}, "");

        p = FindStartsWith(begin(s), end(s), "aa");
        AssertEqual(vector<string>(p.first, p.second), vector<string>{"aa", "aa", "aaa", "aaaa", "aaaaaaa", "aab"}, "");
    }

    {
        vector<string> s = {"a", "aa", "ab", "av", "z", "zza", "zzzzz"};

        auto p = FindStartsWith(begin(s), end(s), "a");
        AssertEqual(vector<string>(p.first, p.second), vector<string>{"a", "aa", "ab", "av"}, "");

        p = FindStartsWith(begin(s), end(s), "aa");
        AssertEqual(vector<string>(p.first, p.second), vector<string>{"aa"}, "");

        p = FindStartsWith(begin(s), end(s), "ab");
        AssertEqual(vector<string>(p.first, p.second), vector<string>{"ab"}, "");

        p = FindStartsWith(begin(s), end(s), "av");
        AssertEqual(vector<string>(p.first, p.second), vector<string>{"av"}, "");

        p = FindStartsWith(begin(s), end(s), "z");
        AssertEqual(vector<string>(p.first, p.second), vector<string>{"z", "zza", "zzzzz"}, "");

        p = FindStartsWith(begin(s), end(s), "zza");
        AssertEqual(vector<string>(p.first, p.second), vector<string>{"zza"}, "");

        p = FindStartsWith(begin(s), end(s), "zzzzz");
        AssertEqual(vector<string>(p.first, p.second), vector<string>{"zzzzz"}, "");
    }

    {
        vector<string> s = {"zza", "zzaa", "zzaaa", "zzab", "zzbc", "zzz", "zzzzz"};

        auto p = FindStartsWith(begin(s), end(s), "zzzzz");
        AssertEqual(vector<string>(p.first, p.second), vector<string>{"zzzzz"}, "");

        p = FindStartsWith(begin(s), end(s), "zza");
        AssertEqual(vector<string>(p.first, p.second), vector<string>{"zza", "zzaa", "zzaaa", "zzab"}, "");

        p = FindStartsWith(begin(s), end(s), "zz");
        AssertEqual(vector<string>(p.first, p.second), vector<string>{"zza", "zzaa", "zzaaa", "zzab", "zzbc", "zzz", "zzzzz"}, "");

        p = FindStartsWith(begin(s), end(s), "zzab");
        AssertEqual(vector<string>(p.first, p.second), vector<string>{"zzab"}, "");
    }
}

int main() {

    TestRunner runner;
    runner.RunTest(TestNotEmptyInterval, "TestNotEmptyInterval");
    runner.RunTest(TestEmptyInterval, "TestEmptyInterval");

    return 0;
}