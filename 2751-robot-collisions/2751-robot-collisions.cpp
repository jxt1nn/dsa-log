/*
    positions = [ ... ]   // where robots are
    healths  = [ ... ]   // their strength
    directions = "LRRLL" // movement

    (position[i], health[i], direction[i])

    'L' → moving left ←
    'R' → moving right →
    All move at same speed

    When do collisions happen?

        one robot is moving RIGHT → 
        another is moving LEFT ←

    SO,
        R ..... L  → collision

    L ..... R  → ❌ never meet
    R ..... R  → ❌ same direction
    L ..... L  → ❌ same direction

    What happens in collision?

    Case1 : health A > health B
        👉 A survives, B dies
        👉 A health becomes healthA - 1

    Case 2: health A < health B
        👉 B survives, A dies
        👉 B health becomes healthB - 1

    Case 3 : healthA == healthB
        both die

    👉 After surviving:
        Robot continues moving
        Can collide again later!

    (positions unsorted)
        positions = [5, 1, 3]
            But actual line is:

    1 ---- 3 ---- 5

        sort robots by position first

    👉 After ALL collisions finish:
        return final healths of surviving robots
    ⚠️ In original input order, not sorted order!


    This is secretly a stack problem 
    Because:
        Right-moving robots (R) are like “waiting”
        When a left-moving robot (L) comes → collision happens with last R

    Example:
        positions = [1, 3, 5]
        directions = "RRL"
    R →   R →   ← L

    👉 The L will collide:

        First with nearest R
        Then maybe next R

    (position, health, direction, original_index)
    
    Sort by position

    Traverse:

    If 'R' → push to stack
    If 'L' → resolve collisions with stack

    Track survivors
    Return in original order

    ⚡ One-line intuition
    “Right-moving robots wait in a stack, and left-moving robots collide with them one by one.”

    for(each robot){
        if(R) push
        else{
            while(stack not empty and collision possible){
                // resolve
            }
            if(L survives) push
        }
    }
*/
class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        
        int n = positions.size();
        
        // Step 1: combine all info
        vector<tuple<int,int,char,int>> robots;
        for(int i = 0; i < n; i++){
            robots.push_back({positions[i], healths[i], directions[i], i});
        }
        
        // Step 2: sort by position
        sort(robots.begin(), robots.end());
        
        // Step 3: stack for indices of robots (in sorted array)
        stack<int> st;
        
        for(int i = 0; i < n; i++){
            
            auto &[pos, health, dir, idx] = robots[i];
            
            if(dir == 'R'){
                st.push(i);
            }
            else{
                // dir == 'L'
                while(!st.empty() && get<2>(robots[st.top()]) == 'R'){
                    
                    int j = st.top(); // last R robot
                    
                    if(get<1>(robots[j]) < health){
                        // R dies
                        st.pop();
                        health--; // L loses 1 health
                    }
                    else if(get<1>(robots[j]) > health){
                        // L dies
                        get<1>(robots[j])--; // R loses 1 health
                        health = 0;
                        break;
                    }
                    else{
                        // both die
                        st.pop();
                        health = 0;
                        break;
                    }
                }
                
                if(health > 0){
                    st.push(i);
                }
            }
        }
        
        // Step 4: collect survivors
        vector<pair<int,int>> survivors; // {original_index, health}
        
        while(!st.empty()){
            int i = st.top();
            st.pop();
            
            auto &[pos, health, dir, idx] = robots[i];
            if(health > 0){
                survivors.push_back({idx, health});
            }
        }
        
        // Step 5: sort by original index
        sort(survivors.begin(), survivors.end());
        
        // Step 6: extract answer
        vector<int> ans;
        for(auto &p : survivors){
            ans.push_back(p.second);
        }
        
        return ans;
    }
};