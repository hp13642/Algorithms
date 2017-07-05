//Test if given number is power of four

 bool isPowerOfFour(int num) {
        if(num<=0)
            return false;
        int i=log2(num)/log2(4);
        if(abs(pow(4,i)-num)<0.00001)
            return true;
        else
            return false;
    }
    
    //In a generalised way if we want to check either a given is either power of 'a' then we can do it as follows
     bool isPowerOfFour(int num,int a) {
        if(num<=0)
            return false;
        int i=log2(num)/log2(a);
        if(abs(pow(a,i)-num)<0.00001)
            return true;
        else
            return false;
    }
