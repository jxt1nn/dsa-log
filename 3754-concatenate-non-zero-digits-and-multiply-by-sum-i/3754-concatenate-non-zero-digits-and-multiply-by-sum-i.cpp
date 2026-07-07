class Solution {
public:
    long long sumAndMultiply(int n) {
        string str = to_string(n);

        long long sum = 0;
        int num = 0;
        for(int i = 0; i < str.size();i++){
            int it = (str[i] - '0');

            if(it == 0){
                continue;
            }

            num *= 10;
            num += it;

            sum += it;
        }
        long long ans = sum * num;
        return ans;
    }
};