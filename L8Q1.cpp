// Codeforces Q1
#include <iostream>
using namespace std;

void towers();
void sel_sort(int arr[], int n);

int main() {
    int t;
    cout << "No of test cases: ";
    cin >> t;
    while (t--) {
        towers();
    }
}

// Function to sort the array for convenience in checking
void sel_sort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}

// Function to manipulate the block values in towers
void towers() {
    int n;
    cout << "Enter number of towers: ";
    cin >> n;
    cout << "Enter blocks in each tower: ";
    int arr[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int towertop = arr[0];
    sel_sort(arr, n);

    for (int i = 1; i < n; i++) {
        if (arr[i] > towertop) {
            while (arr[i] > towertop) {
                arr[i] = arr[i] - 1;
                towertop = towertop + 1;
            }
        }
    }
    cout << towertop << endl;
}
