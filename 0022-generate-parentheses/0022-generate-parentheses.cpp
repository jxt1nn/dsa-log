/*
    we have a "n"
    and we have to genrate all combination of parenthess
    using 
    n "(" and n ")"

    like we have n = 3

    ((())) this is a valid combination 

    we have to "generate all combination" 

    keywords :
        generate all combinations

    BACKTRACKING
    
    at every position we have 2 choics :
        (
        )

    so recursion tree looks like :

                ""
             /      \
           "("      ")"

    But starting with ")" is INVALID.

    So we need RULES.

---------------------------------------------------------

    Example valid:

    ((()))
    ()()()
    (()())

    Invalid:

    ))((
    (()(

---------------------------------------------------------

    When does a bracket string become invalid?

    At ANY point:

        close brackets > open brackets

    is illegal.

    Example:

        ")("

    At first character:

        close = 1
        open  = 0

    INVALID immediately.

---------------------------------------------------------

    Instead of tracking remaining brackets,
    easier to track USED brackets.

    We track:

        openUsed
        closeUsed

---------------------------------------------------------

    Rules:

    We can add '(' if:

        openUsed < n

    because total open brackets allowed = n

---------------------------------------------------------

    We can add ')' if:

        closeUsed < openUsed

    MOST IMPORTANT condition.

    Meaning:

        we cannot close more than opened

---------------------------------------------------------

    Base case :

    When string length becomes:

        2 * n

    we used all brackets.

    Store answer.

---------------------------------------------------------

    DRY RUN : n = 2

    solve("" , open=0 , close=0)

                ""
          open=0 close=0

    choices:
        can add '('
        cannot add ')'

---------------------------------------------------------

    add '('

                "("
          open=1 close=0

    choices:
        can add '('
        can add ')'

---------------------------------------------------------

    branch 1 : add '('

                "(("
          open=2 close=0

    choices:
        cannot add '('
        can add ')'

---------------------------------------------------------

    add ')'

                "(()"
          open=2 close=1

    choices:
        cannot add '('
        can add ')'

---------------------------------------------------------

    add ')'

                "(())"
          open=2 close=2

    size == 2*n

    VALID ANSWER

---------------------------------------------------------

    backtrack

    remove last ')'

                "(()"

    return

---------------------------------------------------------

    remove last ')'

                "(("

    return

---------------------------------------------------------

    remove last '('

                "("

---------------------------------------------------------

    branch 2 : add ')'

                "()"
          open=1 close=1

    choices:
        can add '('
        cannot add ')'

---------------------------------------------------------

    add '('

                "()("
          open=2 close=1

---------------------------------------------------------

    add ')'

                "()()"
          open=2 close=2

    size == 2*n

    VALID ANSWER

---------------------------------------------------------

    final answers:

        (())
        ()()

---------------------------------------------------------

    MAIN BACKTRACKING PATTERN :

        choose
        explore
        undo

    Example:

        s.push_back('(');   // choose

        solve(...);         // explore

        s.pop_back();       // undo

*/
class Solution {
public:

    vector<string> ans;

    void solve(string &s, int open, int close, int n) {

        // valid complete string
        if (s.size() == 2 * n) {
            ans.push_back(s);
            return;
        }

        // choose '('
        if (open < n) {

            s.push_back('(');

            solve(s, open + 1, close, n);

            s.pop_back();
        }

        // choose ')'
        if (close < open) {

            s.push_back(')');

            solve(s, open, close + 1, n);

            s.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {

        string s;

        solve(s, 0, 0, n);

        return ans;
    }
};