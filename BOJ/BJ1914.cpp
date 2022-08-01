#include <iostream>
#include <cmath>
#include <string>
using namespace std;
int n;
void hanoi(int n, int start, int by, int end) {
    if (n == 1) {
        cout << start << " " << end << "\n";
    } else {
        hanoi(n-1, start, end, by);
        cout << start << " " << end << "\n";
        hanoi(n-1, by, start, end);
    }
}
int main(void)
{   
    cin >> n;
	string ans = to_string(pow(2, n));
	int idx = ans.find('.');
	ans = ans.substr(0, idx);
	ans[ans.length() - 1] -= 1;
	cout << ans.c_str() << "\n";
	if (n<=20) {
		hanoi(n, 1, 2, 3);	
	}
    return 0;
}