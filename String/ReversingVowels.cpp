//Write a function that takes a string as input and reverse only the vowels of a string.
//For example-
//Given s = "hello", return "holle".
//Given s = "leetcode", return "leotcede".


    bool isVowel(char ch){
        if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u'|| ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U')
            return true;
        else
            return false;
    }
    string reverseVowels(string s) {
        int i=-1,j=-1;
        int n=s.length();
        int k=0,l=n-1;
        while(k<l){
            while(!isVowel(s[k])) k++;
            while(!isVowel(s[l])) l--;
            if(k<l)
                swap(s[k],s[l]);
            k++;
            l--;
        }
        return s;
    }
