#include<iostream>
#include<vector>
using namespace std;

char chessBoard[9][9] = {0};
int cnt = 0;
int col[9] = {0}; 

bool check(int i, int k) {
    if (chessBoard[k][i] == '*')         // Kiem tra vi tri co bi chan khong
    return false;
    for (int j = 1; j < k; j++) {
        if (col[j] == i)                 // Kiem tra cot 
        return false;
        if ((col[j] - j) == (i - k))     // Kiem tra duong cheo
        return false;
        if ((col[j] + j) == (i + k))
        return false;
    }
    return true;

}
// k chay tu 1 -> 8: k ung voi tung hang - Ung voi moi hang ta se tim cot tuong ung de dat quan hau
// col[k] la cot ung voi hang k. Vi du: col[4] = 3 -> Dat quan hau o hang 4 cot 3; 
void solve(int k) {
    for (int i = 1; i <= 8; i++) {
        if (check(i, k)) {
            // Neu vi tri da chon hop ly thi:
            col[k] = i;
            if (k == 8) {
                cnt++;
            }
            else
            solve(k+1);
            col[k] = 0;
        }
    }
}
int main()
{
    for (int i = 1; i < 9; i++) {
        for (int j = 1; j < 9; j++) {
            cin >> chessBoard[i][j];
        }
    }
    solve(1);
    cout << cnt;
    return 0;
}