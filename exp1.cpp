//  Recurrence relation - 3T(n/2) + (n log n + n)
// master theorem time complexity = O(n ^ log 3(base 2))

#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

void complexRec(int n) {
    int c=0,d=0;
    if (n <= 2) {
        return;
    }

    int p = n;
    while (p > 0) {
        vector<int> temp(n);
        for (int i = 0; i < n; i++) {
            temp[i] = i ^ p;c++;
        }
        p >>= 1;c++;
    }

    vector<int> small(n);
    for (int i = 0; i < n; i++) {
        small[i] = i * i;c++;
    }

    reverse(small.begin(), small.end());c++;

    complexRec(n / 2);d++;
    complexRec(n / 2);
    complexRec(n / 2);
}

int main() {


    auto start = high_resolution_clock::now();
    complexRec(16);
    auto end = high_resolution_clock::now();

    auto duration = duration_cast<milliseconds>(end - start);

    cout <<  duration.count() << " ms\n" << endl;
    cout << c << endl << d;
    return 0;
}