#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<string, int> P;

int count(string &str, string &patt)
{
    int cnt = 0;

    for (int i = 0; i < str.size() - patt.size() + 1; ++i) {
        bool flag = 1;

        for (int j = 0; j < patt.size(); ++j) {
            if (patt[j] != str[j + i]) {
                flag = 0;
                break;
            }
        }

        if (flag) ++cnt;
    }
    return cnt;
}

signed main()
{
    string s = "aababcabcdabcde";
    int len = s.size();
    vector<P> ans;

    for (int l = 1; l <= len; ++l) {
        for (int i = 0; i + l < len; ++i) {
            string temp = s.substr(i, l);
            int cnt = count(s, temp);

            if (cnt >= 2) ans.push_back(P(temp, cnt));
        }
    }
    sort(ans.begin(), ans.end(), [=](P a, P b) {
        if (a.first.size() == b.first.size()) return a.second > b.second;

        return a.first.size() > b.first.size();
    });
    ans.erase(unique(ans.begin(), ans.end()), ans.end()); // 假去重+移除

    for (auto e:ans) cout << e.first << ' ' << e.second << endl;
    cout << "Result: " << ans[0].first << ' ' << ans[0].second << endl;
    return 0;
}
