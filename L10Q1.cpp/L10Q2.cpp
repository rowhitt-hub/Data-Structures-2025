//Codeforces
#include <iostream>
#include <vector>
using namespace std;

void calculatePoints(int n, vector<string>& p1, vector<string>& p2, vector<string>& p3) {
    vector<string> allWords; 
    vector<int> wordCount(n*3, 0);
    
    for (int i = 0; i < n; i++) allWords.push_back(p1[i]);
    for (int i = 0; i < n; i++) allWords.push_back(p2[i]);
    for (int i = 0; i < n; i++) allWords.push_back(p3[i]);
    
    for (int i = 0; i < allWords.size(); i++) {
        for (int j = 0; j < allWords.size(); j++) {
            if (allWords[i] == allWords[j]) wordCount[i]++; 
        }
    }
    
    vector<int> scores(3, 0);
    
    for (int i = 0; i < n; i++) {
        if (wordCount[i] == 1) scores[0] += 3; 
        else if (wordCount[i] == 2) scores[0] += 1; 
    }
    
    
    for (int i = n; i < 2 * n; i++) {
        if (wordCount[i] == 1) scores[1] += 3;
        else if (wordCount[i] == 2) scores[1] += 1;
    }
    
    for (int i = 2 * n; i < 3 * n; i++) {
        if (wordCount[i] == 1) scores[2] += 3;
        else if (wordCount[i] == 2) scores[2] += 1;
    }
    
    cout << scores[0] << " " << scores[1] << " " << scores[2] << endl;
}

int main() {
    int t;
    cin >> t; 
    
    while (t--) { 
        int n;
        cin >> n;
        
        vector<string> p1(n), p2(n), p3(n); 
        
        for (int i = 0; i < n; i++) cin >> p1[i];  
        for (int i = 0; i < n; i++) cin >> p2[i]; 
        for (int i = 0; i < n; i++) cin >> p3[i]; 
        
        calculatePoints(n, p1, p2, p3);
    }
    
    return 0; // End program
}
