class Solution {
public:
    string reverseWords(string s) {
        s = std::regex_replace(s, std::regex("^ +"), "");//remove leading space
        s = std::regex_replace(s, std::regex(" +$"), "");//remove trailing space
        s = std::regex_replace(s, std::regex(" +"), " ");//remove extra whitespace in between

        string ans = "";
        string temp = "";

        for(int i = s.length()-1; i>=0; i--){
            if(s[i] == ' '){
                reverse(temp.begin(), temp.end());
                ans += temp;
                ans.push_back(' ');
                temp = "";
            }
            else{
                temp.push_back(s[i]);
            }
        }

        reverse(temp.begin(), temp.end());
        ans += temp;

        return ans;
    }
};