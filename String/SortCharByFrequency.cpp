/*
Given a string, sort it in decreasing order based on the frequency of characters
*/

bool static compare(const pair<int,char> &p1,const pair<int,char> &p2){
        if(p1.first > p2.first)
            return true;
        else if(p1.first==p2.first){
            if(p1.second < p2.second)
                return true;
            else
                return false;
        }
        else
            return false;
    }
    string frequencySort(string s) {
        pair<int,char> p[256];
        for(int i=0;i<256;i++){
            p[i].first=0;
            p[i].second=(char)(i);
        }
        for(int i=0;i<s.length();i++){
            p[s[i]].first++;
        }
        sort(p,p+256,compare);
        string result;
        for(int i=0;i<256;i++){
            while(p[i].first>0){
                result+=p[i].second;
                p[i].first--;
            }
        }
        return result;
    }
