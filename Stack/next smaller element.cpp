# include <bits/stdc++.h>
using namespace std;

vector<int> nextSmallerElement(vector<int> &arr) {
    int n = arr.size();
    vector<int> result(n, -1);
    stack<int> s;

    for (int i = 0; i < n; i++) {
        while (!s.empty() && arr[s.top()] > arr[i]) {
            result[s.top()] = arr[i];
            s.pop();
        }
        s.push(i);
    }

    return result;
}

int main() {
    vector<int> arr = {4, 5, 2, 10, 8};
    vector<int> result = nextSmallerElement(arr);
    for (int i : result) {
        cout << i << " ";
    }
    return 0;
}