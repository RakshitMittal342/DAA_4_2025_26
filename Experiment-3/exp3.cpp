//Experiment–3: Stable Attendance Window
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<char> attendance(n);
    for (int i = 0; i < n; i++) {
        cin >> attendance[i];
    }

    unordered_map<int, int> m;  
    m[0] = -1;                   

    int balance = 0;
    int longestWindow = 0;

    for (int i = 0; i < n; i++) {
        if (attendance[i] == 'P' || attendance[i] == 'p')
            balance++;
        else
            balance--;

        if (m.count(balance)) {
            longestWindow = max(longestWindow, i - m[balance]);
        } else {
            m[balance] = i;
        }
    }

    cout << longestWindow;
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(n)

