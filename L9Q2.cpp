//Advantage
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;
void sort_solution(vector<int> arr, int n);
void normal_solution(vector<int> arr, int n);

int main() {
    int t;
    cin>>t;
    while (t--) {
        int n;
        cin>>n;
        vector <int> arr (n);
        for (int i=0; i<n; i++) {
            cin>>arr[i];
        }
        //sort_solution(arr,n);
        //normal_solution(arr,n);

    }
}

void sort_solution(vector <int> arr, int n) {
    vector <int> sort_arr= arr;
    sort(sort_arr.begin(), sort_arr.end());
    int new_max;
    for (int i=0; i<n; i++) {
        if (arr[i]==sort_arr[n-1]) {
            new_max=sort_arr[n-2];
        }
        else if (arr[i]<sort_arr[n-1]) {
            new_max=sort_arr[n-1];
        }
        cout<<arr[i]-new_max<<" ";
    }
    cout<<endl;
}

void normal_solution(vector <int> arr, int n) {
    int max1=0;
    int max2=0;
    for (int i=0; i<n; i++) {
        if (arr[i]>max1) {
            max2=max1;
            max1=arr[i];
        }
        else if (arr[i]>max2 && arr[i]!=max1) {
            max2=arr[i];
        }
    }
    if (max2==0) {
        max2=max1;
    }
    for (int i=0; i<n; i++) {
        if (arr[i]==max1) {
            cout << max1-max2<<" ";
        }
        else if (arr[i]<max1) {
            cout<<arr[i]-max1<<" ";
        }
    }
    cout<<endl;
}
