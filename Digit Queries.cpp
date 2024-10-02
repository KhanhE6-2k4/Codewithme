#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

int main() {
    int q = 0;
    cin >> q;
    long k = 0;
    // Do k max = 10^18 nen so phan tu cua 2 mang digit va start lay den 17 la du
    long digit[18] = {0};
    long start[18] = {0};
    digit[0] = 0;
    start[0] = 1;
    for (int i = 1; i < 18; i++) {
        // i vuot qua 15 thi khong can thiet
        long tmp = (long)pow(10, i - 1);
        start[i] = 1 * tmp;
        digit[i] = digit[i - 1] + (9 * tmp * i);
    }
    for (int i = 0; i < q; i++) {
        cin >> k;
        int j;
        int d; // chu so o vi tri k
        long m = 0; // m la bien chua hieu cua k va so luong chu so tinh den trc do
        for (j = 0; j < 17; j++) {
            if (digit[j+1] > k) {
                m = k - digit[j];
                // lay gia tri cua j luc nay
                break;
            }
            
        }
        // Da co gia tri cua m va j
        long tmp = j + 1;
        // tmp ung voi nhom so co tmp chu so ma chua vi tri k (vi du: vi tri k nam o nom so co 3 chu so thi tmp = 3)
        long qt = m / tmp; // thuong
        long re = m % tmp; // so du
        if (re == 0) {
            long tmp1 = start[tmp] + qt - 1;
            d = tmp1 % 10; // Lay chu so cuoi cua tmp1
        }
        else {
            long tmp1 = start[tmp] + qt;
            for (int l = re; l <= tmp; l++) {
                long qt1 = tmp1 / 10;
                d = tmp1 % 10;
                tmp1 = qt1;
            }
        }
        cout << d << endl;
    }
    return 0;
}