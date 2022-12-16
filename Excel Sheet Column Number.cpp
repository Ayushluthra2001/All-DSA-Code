class Solution {
public:
    int titleToNumber(string columnTitle) {
        int power=0;
        int ans=0;
        for(int i=columnTitle.length()-1;i>=0;i--){
            ans+=((columnTitle[i]-'A'+1)*pow(26,power));
            power++;
        }
        return ans;
    }
};
