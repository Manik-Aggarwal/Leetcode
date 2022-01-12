class Solution {
public:
    string removeDuplicates(string s) {
        stack <char> s1;
        
        for(int i=0; i<s.length(); i++){
            if(!s1.empty() && s[i]==s1.top()) s1.pop();
            else s1.push(s[i]);
        }
        
        s = "";
        while(!s1.empty()){
            char x = s1.top();
            s += x;
            s1.pop();
        }
        
        reverse(s.begin(), s.end());
        return s;
    }
};