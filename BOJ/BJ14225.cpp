#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{   
    vector<int> s;
    int n, tmp, max = 0;
    bool exist = false;
    cin >> n;
    for(int i=0; i<n; ++i) {
        cin >> tmp;
        s.push_back(tmp);
        max += tmp;
    }
    sort(s.begin(), s.end());
    vector<bool>check(max+1, 0);
    for (int i=1; i<=n;++i) { // 1개 ~ n개의 조합 생성
        vector<bool>num(n-i, false); // n-i만큼 false
        num.insert(num.end(),i, true); // i만큼 true
        sort(num.begin(), num.end());
        do {
            tmp = 0;
            for (int j=0; j<n; ++j) {
                if(num[j]) tmp += s[j]; // true인것만 더해줌
            }
            check[tmp] = true;
        } while(next_permutation(num.begin(), num.end()));
    }
    
    for (int i=1; i<check.size(); ++i) {
        if (!check[i]) {
            cout << i << "\n";
            return 0;
        }
    }
    cout << check.size() << "\n";
    
    return 0;
}