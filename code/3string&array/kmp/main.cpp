#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 10;

int nex[N];
void getnex(char str[], int len)
{
    nex[0] = -1;

    for (int i = 1, j = -1; i < len; i++) {
        while (j != -1 && str[i] != str[j + 1]) j = nex[j];  // 符合回退

        if (str[i] == str[j + 1]) j++;                       // 符合前进
        nex[i] = j;                                          // 记录当前位置的最长前缀的最后一个字符的位置
    }
}

int kmp(char tex[], char patt[])
{
    int len1 = strlen(tex), len2 = strlen(patt), cnt = 0;

    getnex(patt, len2);

    for (int i = 0, j = -1; i < len1; i++) {
        while (j != -1 && tex[i] != patt[j + 1]) {
            printf("unmatch. s[%d]: %c, t[%d]: %c\n",
                   i,
                   tex[i],
                   j + 1,
                   patt[j + 1]);
            j = nex[j];
        }

        if (patt[j + 1] == tex[i]) {
            printf("match. s[%d]: %c, t[%d]: %c\n", i, tex[i], j + 1,
                   patt[j + 1]);
            j++;
        }

        // 匹配成功后次数+1，同时j回推继续匹配
        if (j == len2 - 1) {
            printf("match succeed. match begin at pos %d of s\n", i);
            cnt++, j = nex[j];
        }
    }
    return cnt;
}

signed main()
{
    // ios::sync_with_stdio(false), cin.tie(0);
    char a[] = "aaabbdaabbde", b[] = "aabbd";

    getnex(b, strlen(b));
    cout << "Result: " << kmp(a, b) << endl;

    // system("pause");
    return 0;
}
