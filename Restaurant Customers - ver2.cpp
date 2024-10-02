#include <iostream>
#include <vector>
#include <algorithm>

struct Event {
    int time; // Thời gian
    bool isArrival; // true nếu là sự kiện đến, false nếu là sự kiện rời
};

// Hàm so sánh để sắp xếp sự kiện
bool compare(Event a, Event b) {
    if (a.time == b.time) {
        return a.isArrival < b.isArrival; // Rời trước nếu cùng thời gian
    }
    return a.time < b.time; // Sắp xếp theo thời gian
}

int maxCustomers(std::vector<std::pair<int, int>>& customers) {
    std::vector<Event> events;

    // Tạo danh sách sự kiện
    for (const auto& customer : customers) {
        events.push_back({customer.first, true});  // Sự kiện đến
        events.push_back({customer.second, false}); // Sự kiện rời
    }

    // Sắp xếp các sự kiện
    std::sort(events.begin(), events.end(), compare);

    int currentCustomers = 0; // Số lượng khách hiện tại
    int maxCustomers = 0;      // Số lượng khách tối đa

    // Duyệt qua các sự kiện
    for (const auto& event : events) {
        if (event.isArrival) {
            currentCustomers++; // Tăng số lượng khách
        } else {
            currentCustomers--; // Giảm số lượng khách
        }
        maxCustomers = std::max(maxCustomers, currentCustomers); // Cập nhật số lượng tối đa
    }

    return maxCustomers;
}

int main() {
    std::vector<std::pair<int, int>> customers;
    int n = 0;
    std::cin >> n;
    int a, b;
    for (int i = 0; i < n; i++) {
        std::cin >> a >> b;
        customers.push_back(std::make_pair(a, b));
    }
    std::cout << maxCustomers(customers) << std::endl;
    return 0;
}
