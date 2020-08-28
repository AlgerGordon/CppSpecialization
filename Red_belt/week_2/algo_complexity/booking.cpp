//
// Created by General on 23.08.2020.
//


#include <iostream>
#include <map>
#include <queue>
using namespace std;


struct BookingEvent {
    int64_t time;
    uint64_t client_id;
    int room_count;
};

struct HotelManager {
    uint64_t total_rooms = 0;
    uint64_t total_clients = 0;
    void NewBooking(const BookingEvent& be) {
        if (client_to_bookings_[be.client_id] == 0) {
            total_clients += 1;
        }
        total_rooms += be.room_count;
        client_to_bookings_[be.client_id] += 1;
        events_queue_.push(be);
    }
    void DeleteBooking(const BookingEvent& be) {
        auto& client_bookings = client_to_bookings_[be.client_id];
        total_rooms -= be.room_count;
        client_bookings -= 1;
        if (client_bookings == 0) {
            total_clients -= 1;
        }
    }

    void RemoveOldBooking(int64_t current_time) {
        if (events_queue_.empty()) {
            return;
        }
        while ((events_queue_.front()).time <= (current_time - SECONDS_IN_DAY)) {
            DeleteBooking(events_queue_.front());
            events_queue_.pop();
            if (events_queue_.empty()) {
                if (total_rooms != 0  || total_clients != 0) {
                    throw logic_error("Non zero rooms in empty queue");
                }
                break;
            }
        }
    }

private:
    map<int64_t, int> client_to_bookings_;
    queue<BookingEvent> events_queue_;

    const int SECONDS_IN_DAY = 86400;
};

class BookingManager {
public:
    void Book(int64_t time, const string& hotel_name,
              unsigned int client_id, int room_count) {
        current_time_ = time;
        hotel_to_HM[hotel_name].NewBooking({time, client_id, room_count});
    }

    uint64_t Clients(const string& hotel_name) {
        return ClientsAndRoomsImpl(hotel_name, TYPE_OF_METHOD::CLIENTS);
    }

    uint64_t Rooms(const string& hotel_name) {
        return ClientsAndRoomsImpl(hotel_name, TYPE_OF_METHOD::ROOMS);
    }

private:
    int64_t current_time_;
    map<string, HotelManager> hotel_to_HM;


    enum class TYPE_OF_METHOD {
        ROOMS,
        CLIENTS
    };

    uint64_t ClientsAndRoomsImpl(const string& hotel_name,TYPE_OF_METHOD type){
        if (hotel_to_HM.count(hotel_name) == 0) {
            return 0;
        }
        auto& hotel_manager = hotel_to_HM[hotel_name];
        hotel_manager.RemoveOldBooking(current_time_);
        if (type == TYPE_OF_METHOD::CLIENTS) {
            return hotel_manager.total_clients;
        } else if (type == TYPE_OF_METHOD::ROOMS) {
            return hotel_manager.total_rooms;
        }
        return 0;
    }
};

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    BookingManager bm;

    int query_count;
    cin >> query_count;

    for (int i = 0; i < query_count; ++i) {
        string query_type;
        cin >> query_type;

        string hotel_name;
        if (query_type == "BOOK") {
            int64_t time;
            uint64_t client_id;
            int room_count;
            cin >> time >> hotel_name >> client_id >> room_count;
            bm.Book(time, hotel_name, client_id, room_count);
        } else {
            cin >> hotel_name;
            if (query_type == "CLIENTS") {
                cout << bm.Clients(hotel_name) << endl;
            } else if (query_type == "ROOMS") {
                cout << bm.Rooms(hotel_name) << endl;
            }
        }
    }

    return 0;
}