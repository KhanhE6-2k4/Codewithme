#include <iostream>
#include<vector>
#include<math.h>
using namespace std;

vector<string> solve(int n) {
    if (n == 1) {
        vector<string> vt;
        vt.push_back("0");
        vt.push_back("1");
        return vt;
    }
    vector<string> vt_cur;
    vector<string> vt_pre = solve(n - 1);
    int k = 1 << (n - 1);
    for (int i = 0; i < k; i++) {
        string s = "0" + vt_pre[i];
        vt_cur.push_back(s);
    }
    for (int i = k - 1; i >= 0; i--) {
        string s = "1" + vt_pre[i];
        vt_cur.push_back(s);
    }
    return vt_cur;
    
}

int main()
{
    int n = 0;
    cin >> n;
    vector<string> vt;
    vt = solve(n);
    for (auto i : vt) {
        cout << i << endl;
    }

    return 0;
}