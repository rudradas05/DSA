class Solution {
public:
    long long digitSum (long long n){
        long long sum = 0;
        while(n>0){
            sum = sum+ n%10;
            n = n/10;
        }
        return sum;
    }
    long long makeIntegerBeautiful(long long n, int target) {
        if(digitSum(n)<=target)return 0;
        long long ans = 0, p=1;
        
        while(digitSum(n)> target){
            long long add = (10-(n%10))%10;
            ans += add*p;
            n+=add;
            n = n/10;
            p = p*10;
        }
        return ans;
    }
};