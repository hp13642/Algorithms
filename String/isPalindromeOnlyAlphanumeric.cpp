/*
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.
*/



    bool isAlphanumeric(int a){
        if((a>47 && a<58) || (a>64 && a<91) || (a>96 && a<123))
            return true;
        else
            return false;
    }
    bool isSameIgnoringCase(char ch1,char ch2){
        if((ch1>47 && ch1<58) || (ch2>47 && ch2<58))
            return ch1==ch2;
        else if((ch1==ch2) || (ch1+32==ch2) || (ch1==ch2+32))
            return true;
        else
            return false;
    }
    bool isPalindrome(string s) {
        int n=s.length();
        int i=0,j=n-1;
        while(i<j){
            while(!isAlphanumeric((int)s[i])) i++;
            while(!isAlphanumeric((int)s[j])) j--;
            if(i>j)
                return true;
            if(!isSameIgnoringCase(s[i],s[j]))
                return false;
            i++;
            j--;
        }
        return true;
    }
