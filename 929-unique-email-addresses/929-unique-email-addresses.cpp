class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set <string> s;
        
        for(auto str:emails){
            int i=0;
            
            while(true){
                if(str[i] == '@') break;
                
                if(str[i] == '+'){
                    str.erase(i,str.find('@')-i);
                    break;
                }
                
                if(str[i]=='.') str.erase(i,1);
                
                else i++;
            }
            
            s.insert(str);
        }
        
        return s.size();
    }
};