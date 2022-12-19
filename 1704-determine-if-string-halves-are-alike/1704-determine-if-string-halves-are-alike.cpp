
class Solution {
public:
    bool halvesAreAlike(string s) {
        int n = s.length();
        int i=0,j=n-1;
        int h1=0,h2=0;
        for(auto& x:s){
            if(x>='A' and x<='Z'){
                x = x-('Z'-'z');
            }
        }
        while(i<j){
            char c=s[i];
            if(c=='a' || c=='e' || c=='o' || c=='i' || c=='u')
                h1++;
            c=s[j];
            if(c=='a' || c=='e' || c=='o' || c=='i' || c=='u')
                h2++;
            
            i++,j--;    
        }
        return h1==h2;
    }
};