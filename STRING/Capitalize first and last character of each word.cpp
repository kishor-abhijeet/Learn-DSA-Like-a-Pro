#include <bits/stdc++.h>
using namespace std;
void solve(string &res, string s)
{
    istringstream ss(s);
    string word;
    while (ss >> word)
    {
        word[0] = toupper(word[0]);
        word[word.length()-1] = toupper(word[word.length()-1]);

        res += word + " ";
    }
}
int main()
{
    cout << "Enter a string: ";

    string s;
    // cin >> s; ------------> in this way  it will take only one word as input
    //to get the whole line as input we use getline function
    getline(cin, s);

    string res = "";
    solve(res, s);
    cout<<"Result: " << res <<endl;
    return 0;
}
