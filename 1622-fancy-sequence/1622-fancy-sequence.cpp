/*  
    so for storing the sequenece
        we can take a vector 

    append -> just push into vector

    addAll -> for(auto &x : arr) x += inc

    mutAll -> for(auto &x : arr) x *= m

    getIndex -> return nums[idx]

    ONE MORE THING.....

        DO mod in every operation...(including push and getIndex)

    BUT here is a thing.......

    we doing unnecessary doing O(n) traversal for add and multiple

    bcoz we need only some elements from array 

    we doesnt need to return the whole array 

    so what we can DO so we dont need to do O(n)

    one thing we can do 

    remeber the how much we need to add in element and multiply by who

    like we have[2,3,4]

    and now we get a opartion of addALL(5)

    so we can store this 5 in a global variable 

    and in future we need to return any index we simply 
    add this number and return it 

    like getIndex(2)
    nums[2] = 4
    4 += addVariable
    now we have 9
    return 9

    SAME logic goes for multiply

    but what if first we get a operation of append
    when our gloabl variable 
    already holding vaules 

    and something like this 

    [2,3,4]
    add = 5
    mult = 3
    append(5)
    getIndex(3)

    but when we go to return this nums[3]
    our global varible apply operayion on them.....

    which is wrong 

    so one thing we can do we can store our new element 
        by subtract and divide by 
        add and mult values 
        so whenever getIndex operation call

    it will work normlly 

    how can we store new element

    stored_value = (real_value - add) / mul

    and for returning 

    real_value = stored_value * mul + add

    we have to multiply global variable also when we get new mult operation..

    bcoz ,
        real_value = stored_value * mul + add
    mul = 2
    add = 3
        real_value = stored * 2 + 3
        multAll(5)

    new_value = (stored * 2 + 3) * 5
        new_value = stored * 10 + 15
        
    mul = 10
    add = 15


    we need modInverse(mul)

    bcoz we do reverse value in append 

    but dicision is not possible in mod

        so we need this 
    division is not allowed with modulo
    So we replace
        division → multiplication with inverse
*/
class Fancy {
public:
    vector<long long> arr;
    long long mul = 1, add = 0;
    const long long mod = 1e9 + 7;

    long long modPow(long long a, long long b) {
        long long res = 1;
        while (b) {
            if (b & 1) res = (res * a) % mod;
            a = (a * a) % mod;
            b >>= 1;
        }
        return res;
    }

    long long modInverse(long long x) {
        return modPow(x, mod - 2);
    }

    Fancy() {}

    void append(int val) {
        long long stored = ((val - add + mod) % mod * modInverse(mul)) % mod;
        arr.push_back(stored);
    }

    void addAll(int inc) {
        add = (add + inc) % mod;
    }

    void multAll(int m) {
        mul = (mul * m) % mod;
        add = (add * m) % mod;
    }

    int getIndex(int idx) {
        if (idx >= arr.size()) return -1;
        return (arr[idx] * mul + add) % mod;
    }
};
// class Fancy {
// public:
//     vector<long long> arr;
//     long long mod = 1e9 + 7;

//     Fancy() {}

//     void append(int val) {
//         arr.push_back(val % mod);
//     }
    
//     void addAll(int inc) {
//         for(auto &x : arr) 
//             x = (x + inc) % mod;
//     }
    
//     void multAll(int m) {
//         for(auto &x : arr) 
//             x = (x * m) % mod;
//     }
    
//     int getIndex(int idx) {
//         if(idx >= arr.size()) return -1;
//         return arr[idx] % mod;
//     }
// };
/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */