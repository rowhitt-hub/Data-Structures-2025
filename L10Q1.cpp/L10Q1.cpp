//Codeforces

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

/*
int check_unique(vector<int> arr) {
    unordered_set<int> seen;
    for (int num : arr) {
        if (seen.find(num) != seen.end()) {
            return -1;
        }
        seen.insert(num);
    }
    return 1;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int count = 0;
        int r = check_unique(arr);
        if (r == -1) {
            while (r == -1 && !arr.empty()) {  
                arr.pop_back();
                count++;
                r = check_unique(arr);
            }
        }
        cout << count << endl;
    }
}
*/

#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

int minRemovalsToUnique(vector<int>& seq) {
    unordered_set<int> seen;
    int count = 0;

    // Traverse from the last element to the first
    for (int i = seq.size() - 1; i >= 0; --i) {
        if (seen.count(seq[i])) break;  // Stop when duplicate is found
        seen.insert(seq[i]);
        count++;
    }

    return seq.size() - count;  // Elements removed
}

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<int> seq(n);
        for(int i=0; i<n; i++) {
            cin>>seq[i];
        }
        int r=minRemovalsToUnique(seq);
        cout<<r<<" "<<endl;
    }
}
