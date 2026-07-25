class Solution {
public:
    int maxProduct(int n) {
        int count = 0;
        int lar = 0,sec = 0;

        while(n > 0){
            int last = n % 10;

            if(last > lar){
                sec = lar;
                lar = last;
                count = 1;
            }
            else if(last > sec){
                sec = last;
            }
            else if(last == lar){
                count++;
            }
            n /= 10;
        }
        if(count > 1) return lar * lar;

        return lar * sec;
    }
};