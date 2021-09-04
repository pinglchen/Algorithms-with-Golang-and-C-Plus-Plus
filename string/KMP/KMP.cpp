class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size()==0) return 0;
        int m=haystack.size(),n=needle.size();
        vector<int> next(needle.size(),0);//
        int i=0,j=-1;
        next[0]=-1;
        while(i<needle.size()-1){
            // 注意：不能是i<needle.size()，因为最后一个next[needle.size()-1]
            //值是由i=needle.size()-2计算的
            if(j==-1||needle[i]==needle[j]){
                i++;j++; 
                next[i]=j;               
            }
            else j=next[j];
        }
        i=0;j=0;//!!! not: i=0,j=0;
        while(i<m&&j<n){//while(i<haystack.size()&&j<needle.size()) 有意外错误(int)?

            if(j==-1||haystack[i]==needle[j]){
                ++i;++j;
            }
            else j=next[j];
        }
        if(j==n) return (i-needle.size());
        return -1;
    }
};