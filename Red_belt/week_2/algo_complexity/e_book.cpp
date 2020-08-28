#include <iomanip>
#include <iostream>
#include <vector>
#include <utility>
#include <set>
using namespace std;

class ReadingManager {
public:
    ReadingManager() : user_page_counts_(MAX_USER_COUNT_ + 1),
                       n_users_read_MoE_pages_(MAX_PAGES + 1), n_users_(0) {}

    void Read(int user_id, int page_count) {
        if (user_page_counts_[user_id] == 0) {
            n_users_ += 1;
        }
        int prev_page = user_page_counts_[user_id];
        for (int ind = (prev_page + 1); ind <= page_count; ++ind) {
            n_users_read_MoE_pages_[ind] += 1;
        }
        user_page_counts_[user_id] = page_count;
    }

    double Cheer(int user_id) const {
        int page = user_page_counts_[user_id];
        if (page == 0) {
            return 0.0;
        }
        if (n_users_ == 1) {
            return 1.0;
        }
        int users_read_less = n_users_ - n_users_read_MoE_pages_[page];
        return  users_read_less * 1.0 / (n_users_ - 1);
    }

private:
    static const int MAX_PAGES = 1000;
    static const int MAX_USER_COUNT_ = 100'000;

    vector<int> user_page_counts_;
    // n_users read more or equal pages
    vector<int> n_users_read_MoE_pages_;
    int n_users_;
};


int main() {
    // Для ускорения чтения данных отключается синхронизация
    // cin и cout с stdio,
    // а также выполняется отвязка cin от cout
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ReadingManager manager;

    int query_count;
    cin >> query_count;

    for (int query_id = 0; query_id < query_count; ++query_id) {
        string query_type;
        cin >> query_type;
        int user_id;
        cin >> user_id;

        if (query_type == "READ") {
            int page_count;
            cin >> page_count;
            manager.Read(user_id, page_count);
        } else if (query_type == "CHEER") {
            cout << setprecision(6) << manager.Cheer(user_id) << "\n";
        }
    }

    return 0;
}