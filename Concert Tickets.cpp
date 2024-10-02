#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int binarySearch(vector<int>& vt, int x) {
    if (vt.empty())
    return -1;
    int l = 0;
    int r = vt.size() - 1;
    int mid = 0;
    while (l < r) {
        mid = (l + r) / 2;
        if (x == vt[mid]) {
            vt.erase(vt.begin() + mid);
            return x;
        }
        else if (x > vt[mid]) {
            l = mid + 1;
        }
        else {
            r = mid - 1; 
        }
        
    }
    if (x == vt[l] || x > vt[l]) {
        int tmp = vt[l];
        vt.erase(vt.begin() + l);
        return vt[l];
    }
    // x < vt[l] , l must greater than 0 to do this
    if (l > 0) {
        int tmp = vt[l - 1];
        vt.erase(vt.begin() + l - 1);
        return tmp;
    }
    return -1;
}

int main()
{
    int n, m;
    vector<int> h;
    vector<int> t;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        h.push_back(tmp);
    }
    sort(h.begin(), h.end());
    for (int i = 0; i < m; i++) {
        int tmp;
        cin >> tmp;
        cout << binarySearch(h, tmp) << endl;
    }
    return 0;
}