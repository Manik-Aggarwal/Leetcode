class Solution {
public:
    char isLower (char ch) {
   if(ch >= 'a' && ch <= 'z') {
       return ch;
   }
   else if (ch>='A'&&ch<='Z'){
        char temp = ch - 'A' + 'a';
       return temp;      
   }
   else return ch;
}

bool isPalindrome(string s)
{
   int start = 0;
   int end = s.size()-1;
   while(start<end) {
       if(!((s[start]>='a'&& s[start]<='z') || (s[start]>='A'&& s[start]<='Z') || (s[start]>='0'&& s[start]<='9'))){
           start++;
           continue;
       }
       if(!((s[end]>='a'&& s[end]<='z') || (s[end]>='A'&& s[end]<='Z') || (s[end]>='0'&& s[end]<='9'))){
           end--;
           continue;
       }
       if(isLower(s[start])==isLower(s[end])){
           start++;
           end--;
       }
       else return false;
   }
   return true;
}
};