#include<iostream>
#include<vector>
using namespace std;

vector<string> vt;
char str[8] = {0};
char* out_string = new char[9]{0};
int alphabet[26] = {0};
int mem_alpha[26] = {0};
int cnt = 0;
int k = 0;
int n = 0;

bool check(int i) {
    return (mem_alpha[str[i] - 'a'] < alphabet[str[i] - 'a']);
    
}
void Solve(int h) {
    for (int i = 0; i < k; i++) {
        if (check(i)) {
            mem_alpha[str[i] - 'a']++;
            out_string[h] = str[i];
            if (h == n - 1) {
                cnt++;
                vt.push_back((string)out_string);
            }
            else
            Solve(h + 1);
            out_string[h] = 0;
            mem_alpha[str[i] - 'a']--;
        }
    }
}

int main() {
    string s1;
    cin >> s1;
    n = s1.length();
    for (int i = 0; i < n; i++) {
        alphabet[s1[i] - 'a']++;
    }
    for (int i = 0; i < 26; i++) {
        if (alphabet[i] != 0) {
            str[k] = i + 'a';
            k++;
        }
    }
    Solve(0);
    cout  << cnt << endl;
    for (auto i : vt) {
        cout << i << endl;
    } 
    delete[] out_string;
}