#include "test_runner.h"

using namespace std;

// Реализуйте здесь шаблонный класс Table
template <typename T>
class Table {
public:

    Table(size_t nRows, size_t nColumns) {
        Resize(nRows, nColumns);
    }

    const vector<T>& operator [] (size_t index) const {
        return data_[index];
    }

    vector<T>& operator [] (size_t index) {
        return data_[index];
    }

    void Resize(size_t nRows, size_t nColumns) {
        data_.resize(nRows);
        for (auto& item : data_) {
            item.resize(nColumns);
        }
    }

    pair<size_t, size_t> Size() const {
        if (!data_.empty() && !data_[0].empty()) {
            return {data_.size(), data_[0].size()};
        }
        return  {0, 0};
    }

private:
    vector<vector<T>> data_;
};

void TestTable() {
  Table<int> t(1, 1);
  ASSERT_EQUAL(t.Size().first, 1u);
  ASSERT_EQUAL(t.Size().second, 1u);
  t[0][0] = 42;
  ASSERT_EQUAL(t[0][0], 42);
  t.Resize(3, 4);
  ASSERT_EQUAL(t.Size().first, 3u);
  ASSERT_EQUAL(t.Size().second, 4u);
}

int main() {
  TestRunner tr;
  RUN_TEST(tr, TestTable);
  return 0;
}
