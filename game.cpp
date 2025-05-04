#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        vector<int> arr1(a);
        vector<int> arr2(b);

        
        for (int i = 0; i < a; i++) {
            cin >> arr1[i];
        }

        
        for (int i = 0; i < b; i++) {
            cin >> arr2[i];
        }

        int first = arr1[0]; 

        
        for (int i = 0; i < b; i++) {
            int n = arr2[i];  
            int winners = 0;

           
            for (int num = 1; num <= n; num++) {
                if (num < first) {
                    winners++;
                }
            }
            cout << winners << " ";
        }
        cout << endl;
    }
    return 0;
}
