#include <iostream>
using namespace std;

string s;
bool visited[7][7] = {false};
int cnt = 0;
int path = 0; // max_path = 48;
bool in_zone(int i, int j) {
    return (0 <= i) && (i <= 6) && (0 <= j) && (j <= 6);
}

bool canGoUp(int i, int j) {
    return in_zone(i - 1, j) && !visited[i - 1][j];
}
bool canGoDown(int i, int j) {
    return in_zone(i + 1, j) && !visited[i + 1][j];
}
bool canTurnRight(int i, int j) {
    return in_zone(i, j + 1) && !visited[i][j + 1];
}
bool canTurnLeft(int i, int j) {
    return in_zone(i, j - 1) && !visited[i][j - 1];
}
bool isDone(int i, int j) {
    if (i == 6 && j == 0) {
       if (path == 48)
       return true;
    }
    return false;
}

void DFS(int i, int j) {
    // Nếu vị trí hiện tại không hợp lệ hoặc đã được thăm, thoát khỏi hàm
    if (!in_zone(i, j) || visited[i][j]) {
        return;
    }
    if (canTurnLeft(i, j) && canTurnRight(i, j) && !canGoDown(i, j) && !canGoUp(i, j))
    return;
    
    if (canGoUp(i, j) && canGoDown(i, j) && !canTurnRight(i, j) && !canTurnLeft(i, j))
    return;
    
    if (in_zone(i - 1, j + 1) && visited[i - 1][j + 1] && canGoUp(i, j) && canTurnRight(i, j))
    return;
    
    if (in_zone(i + 1, j + 1) && visited[i + 1][j + 1] && canGoDown(i, j) && canTurnRight(i, j))
    return;
    
    if (in_zone(i - 1, j - 1) && visited[i - 1][j - 1] && canGoUp(i, j) && canTurnLeft(i, j))
    return;
    
    if (in_zone(i + 1, j - 1) && visited[i + 1][j - 1] && canGoDown(i, j) && canTurnLeft(i, j))
    return;
    
    // Nếu đã tới vị trí đích tăng cnt
    if (isDone(i, j)) {
        cnt++;
        return;
    }
      
    // Đánh dấu vị trí hiện tại đã được thăm 
    visited[i][j] = true;
    path += 1;
    
    if (s[path - 1] == '?') {
         // Gọi DFS cho 4 hướng
        DFS(i - 1, j); // Lên trên
        DFS(i + 1, j); // Xuống dưới
        DFS(i, j - 1); // Sang trái
        DFS(i, j + 1); // Sang phải
    }
    else {
        if (s[path - 1] == 'D' && i < 6)
        DFS(i + 1, j);
        else if (s[path - 1] == 'U' && i > 0)
        DFS(i - 1, j);
        else if (s[path - 1] == 'L' && j > 0)
        DFS(i, j - 1);
        else if (s[path - 1] == 'R' && j < 6)
        DFS(i, j + 1);
    } 
    // Quay lui: Đánh dấu lại vị trí hiện tại chưa được thăm và giảm độ dài
    visited[i][j] = false;
    path -= 1;
}
int main() {
    cin >> s;
    DFS(0, 0);
    cout << cnt << endl;
    return 0;
}