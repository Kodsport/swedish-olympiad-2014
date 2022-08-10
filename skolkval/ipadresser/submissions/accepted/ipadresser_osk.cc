#include <iostream>
#include <string>
#include <set>

using namespace std;
typedef long long ll;

bool isValidIP(const string& ip) {
    ll sum = 0;
    bool ok = true;
    for (ll i = 0; i < ip.size(); ++i) {
        if (ip[i] == '.') {
            if (sum > 255) ok = false;
            sum = 0;
            continue;
        }
        if (i > 0 && ip[i] != '.' && ip[i-1] == '0') ok = false;
        sum *= 10;
        sum += ip[i]-'0';
    }
    if (sum > 255) ok = false;
    return ok;
}

int main() {
    set<string> result;

    string numbers;
    cin >> numbers;
    for (ll i = 1; i < numbers.size(); ++i) {
        for (ll j = i+1; j < numbers.size(); ++j) {
            for (ll k = j+1; k < numbers.size(); ++k) {
                string ip;
                ip += numbers.substr(0,i);
                ip += ".";
                ip += numbers.substr(i, j-i);
                ip += ".";
                ip += numbers.substr(j, k-j);
                ip += ".";
                ip += numbers.substr(k, numbers.size()-k);
                if (isValidIP(ip)) {
                    result.insert(ip);
                }
            }
        }
    }

    cout << result.size() << endl;
}
