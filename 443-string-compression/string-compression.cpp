class Solution {
public:
    int compress(vector<char>& chars) {

        string ans = "";     
        int n = chars.size();

        for (int i = 0; i < n; ) {

            char ch = chars[i];
            int count = 0;

            while (i < n && chars[i] == ch) {
                count++;
                i++;
            }

            ans += ch;

            if (count > 1) {
                ans += to_string(count);
            }
        }

        for (int i = 0; i < ans.size(); i++) {
            chars[i] = ans[i];
        }

        return ans.size();
    }
};