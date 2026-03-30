/*  
    we have 3 character's : '(', ')' and '*'

    valid string:

    Any left parenthesis '(' must have a corresponding right parenthesis ')'.
    Any right parenthesis ')' must have a corresponding left parenthesis '('.
    Left parenthesis '(' must go before the corresponding right parenthesis ')'.

    '*' could be treated as a single right parenthesis ')' or 
        a single left parenthesis '(' or an empty string ""

    return true if s is valid.

    🧠 Step 1: Start from the basic problem

    Ignore * first.

    For a normal valid parentheses string:

    You keep a count of open brackets
    Never let it go negative
    End with count = 0


    🧠 Step 2: Now introduce *

    Problem:

    '*' can be '(', ')' or empty

    So at any position, you don’t know:

    “How many open brackets do I actually have?”

    👉 This is the key turning point.

    🧠 Step 3: Instead of exact value → think RANGE
        What is the MIN possible open brackets?
        What is the MAX possible open brackets?

        low  = minimum open brackets
        high = maximum open brackets

    1. '('
    Definitely increases open brackets
    low++
    high++

    2. ')'
    Definitely decreases
    low--
    high--

    3. '*'
    Now think carefully:

    It can be:

    '(' → increases open → affects high
    ')' → decreases open → affects low
    '' → no effect

    So:
    low--   (if treated as ')')
    high++  (if treated as '(')

    ❗ Why if(high < 0) return false;
    
        Means:

        Even in the best case, we have too many ) → impossible

    ❗ Why low = max(low, 0)

    Because:

    Minimum open brackets cannot go below 0

    (you can't have negative open brackets)

    This is a classic greedy + range tracking pattern

    Used when:

    choices are flexible
    future decisions matter
    
*/
class Solution {
public:
    bool checkValidString(string s) {
        int low = 0, high = 0;

        for(char c : s) {
            if(c == '(') {
                low++;
                high++;
            }
            else if(c == ')') {
                low--;
                high--;
            }
            else { // '*'
                low--;      // treat as ')'
                high++;     // treat as '('
            }

            if(high < 0) return false; // too many ')'

            if(low < 0) low = 0; // cannot go below 0
        }

        return low == 0;
    }
};