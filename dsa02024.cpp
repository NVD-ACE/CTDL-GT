#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> a;
vector<int> cur; 
vector <string> v;
void generate(int pos) {
    if (cur.size() >= 2) {
    	string tmp="";
        for (int x : cur) {
            tmp+=to_string(x)+ " ";
        }
        tmp.pop_back();
        v.push_back(tmp);
    }
    for (int i = pos + 1; i < a.size(); i++) {
        if (a[i] > cur.back()) {
            cur.push_back(a[i]);
            generate(i);
            cur.pop_back();
        }
    }
}

int main() {
    int n;
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    //sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
        cur.push_back(a[i]);
        generate(i);
        cur.pop_back();
    }
    sort(v.begin(),v.end());
    for(auto x:v)
    cout << x << endl;
    return 0;
}
