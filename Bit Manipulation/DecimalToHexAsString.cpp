/*
Given an integer, write an algorithm to convert it to hexadecimal. For negative integer, two’s complement method is used.

Note:

All letters in hexadecimal (a-f) must be in lowercase.
The hexadecimal string must not contain extra leading 0s. If the number is zero, it is represented by a single zero character '0'; otherwise, the first character in the hexadecimal string will not be the zero character.
The given number is guaranteed to fit within the range of a 32-bit signed integer.
You must not use any method provided by the library which converts/formats the number to hex directly.
*/

void toHexUtil(long num,int base,string &s){
        if(num==0)
            return;
        else{
            char rem=num%16 + '0';
            toHexUtil(num/16,16,s);
            if(rem>'9'){
                rem=rem-'9'+'a'-1;
            }
            s=s+rem;
            return;
        }
    }
    string toHex(long num) {
        if(num==0)
            return "0";
        string s="";
        if(num<0)
            num=(pow(2,32)-1 + num)+1;
        toHexUtil(num,16,s);
        return s;
    }
