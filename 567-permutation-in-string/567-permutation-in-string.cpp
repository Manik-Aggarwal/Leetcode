class Solution {
public:
    bool checkEqual(int a[26], int b[26]){
        for(int i=0; i<26; i++){
            if(a[i] != b[i]) return false;
        }
        return true;
    }
    
    bool checkInclusion(string s1, string s2) {
        int count1[26] = {0};
        
        //counting s1 elements in count1
        for(int i=0; i<s1.length(); i++){
            int index = s1[i] - 'a';
            count1[index]++;
        }
        
        int i=0;
        int windowSize = s1.length();
        int count2[26] = {0};
        
        //running 1st time for window at initial phase
        while(i<windowSize && i<s2.length()){
            int index = s2[i] - 'a';
            count2[index]++;
            i++;
        }
        
        if(checkEqual(count1, count2)) return true;
        
        else{
            while(i<s2.length()){
                char newchar = s2[i];
                int index = newchar - 'a';
                count2[index]++;
                
                char oldchar = s2[i - windowSize];
                index = oldchar - 'a';
                count2[index]--;
                
                i++;
                
                if(checkEqual(count1, count2)) return true;
            }           
        }
        return false;
    }
};