#include "test_runner.h"

#include <algorithm>
#include <iostream>
#include <string>
#include <queue>
#include <stdexcept>
#include <set>

using namespace std;

template<class T>
class ObjectPool {
public:
    T *Allocate() {
        return AllocateImpl(ALLOC_TYPE::ALLOC);
    }

    T *TryAllocate() {
        return AllocateImpl(ALLOC_TYPE::TRY_ALLOC);
    }

    void Deallocate(T *object) {
        if (allocated.count(object) > 0) {
            freed.push(object);
            allocated.erase(object);
        } else {
            throw invalid_argument("There is no such object");
        }
    }

    ~ObjectPool() {
        for (T* item : allocated) {
            delete item;
        }
        while (!freed.empty()) {
            delete freed.front();
            freed.pop();
        }
    }

private:
    set<T* > allocated;
    queue<T* > freed;

    enum class ALLOC_TYPE {
        ALLOC,
        TRY_ALLOC
    };

    T* AllocateImpl(ALLOC_TYPE type) {
        T* res;
        if (freed.empty()) {
            if (type == ALLOC_TYPE::ALLOC) {
                res = new T;
                allocated.insert(res);
            } else if (type == ALLOC_TYPE::TRY_ALLOC){
                res = nullptr;
            }
        } else {
            res = freed.front();
            allocated.insert(res);
            freed.pop();
        }
        return res;
    };
};

void TestObjectPool() {
    ObjectPool<string> pool;

    auto p1 = pool.Allocate();
    auto p2 = pool.Allocate();
    auto p3 = pool.Allocate();

    *p1 = "first";
    *p2 = "second";
    *p3 = "third";

    pool.Deallocate(p2);
    ASSERT_EQUAL(*pool.Allocate(), "second");

    pool.Deallocate(p3);
    pool.Deallocate(p1);
    ASSERT_EQUAL(*pool.Allocate(), "third");
    ASSERT_EQUAL(*pool.Allocate(), "first");

    try {
        pool.Deallocate(p1);
    } catch (exception& e) {
        cout << e.what() << endl;
    }
}

int main() {
    TestRunner tr;
    RUN_TEST(tr, TestObjectPool);
    return 0;
}
