#include <iostream>
#include<utility>
#include<vector>
using namespace std;

string s;
bool visited[7][7] = {false};
int length = 0;
int cnt = 0;
vector<pair<int, int>> vt;

bool in_zone(int i, int j) {
    return (0 <= i) && (i <= 2) && (0 <= j) && (j <= 2);
}

void DFS(int i, int j) {
    // Nếu vị trí hiện tại không hợp lệ hoặc đã được thăm, thoát khỏi hàm
    if (!in_zone(i, j) || visited[i][j]) {
        return;
    }
    // Nếu đã tới vị trí đích và độ dài là 49, tăng cnt
    if (i == 2 && j == 0 && length == 8) {
        for (auto i : vt) {
            cout << i.first << "-" << i.second << " -> ";
    }
        cout << i << "-" << j << endl;
        cnt++;
        return;
    }
    // Đánh dấu vị trí hiện tại đã được thăm và tăng độ dài
    visited[i][j] = true;
    vt.push_back(make_pair(i, j));
    length++;

    // Gọi DFS cho 4 hướng
    DFS(i-1, j); // Xuống dưới

    DFS(i+1, j); // Lên trên
  
    DFS(i, j-1); // Sang trái

    DFS(i, j+1); // Sang phải

    // Quay lui: Đánh dấu lại vị trí hiện tại chưa được thăm và giảm độ dài
    visited[i][j] = false;
    vt.pop_back();
    length--;
}


int main() {
    DFS(0, 0);
    cout << cnt << endl;
    return 0;
}