//DFS

class Solution {
public:
    void solve(vector<string> &ans, string in, string out) {
        if (in == "") {
            ans.push_back(out);
            return;
        }

        if (isalpha(in[0])) {
            string out1 = out, out2 = out;
            out1.push_back((char)tolower(in[0]));
            out2.push_back((char)toupper(in[0]));

            solve(ans, in.substr(1), out1);
            solve(ans, in.substr(1), out2);
        }
        else {
            solve(ans, in.substr(1), out);
        }
    }

    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        solve(ans, s, "");
    }
};

//BFS

class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        deque<string> q;
        q.push_back(s);
        int n = s.size();
        for (int i = n - 1; i >= 0; i--) {
            char c = s[i];
            if (isalpha(c)) {
                int size = q.size();
                while(size--) {
                    string temp = q.front();
                    q.pop_front();
                    string left = temp.substr(0, i);
                    string right = temp.substr(i + 1);
                    q.push_back(left + (char)tolower(c) + right);
                    q.push_back(left + (char)toupper(c) + right);
                }
            }
        }
        return {q.begin(), q.end()};
    }
};
