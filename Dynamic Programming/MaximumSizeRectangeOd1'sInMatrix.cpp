/*
Problem Statement-
Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

For example, given the following matrix:

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0
Return 6.
*/

class Solution {
public:
     int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        stack<int> s;
        int top;
        int maxArea=0;
        int area;
        int i=0;
        while(i<n){
            if(s.empty() || heights[i]>= heights[s.top()])
                s.push(i++);
            else{
                top=s.top();
                s.pop();
                area=heights[top]*(s.empty()?i: i-s.top()-1);
                maxArea=max(maxArea,area);
            }
        }
        while(!s.empty()){
            top=s.top();
            s.pop();
            area=heights[top]*(s.empty()?i: i-s.top()-1);
            maxArea=max(maxArea,area);
        }
        return maxArea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size()==0)
            return 0;
        int m=matrix.size();
        int n=matrix[0].size();
        vector<int> dpHist(n,0);
        int maxRectArea=0,rectArea;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]=='1')
                    dpHist[j]=dpHist[j]+1;
                else
                    dpHist[j]=matrix[i][j]-'0';
            }
            rectArea=largestRectangleArea(dpHist);        
            maxRectArea=max(maxRectArea,rectArea);
        }               
        return maxRectArea;
    }
};
