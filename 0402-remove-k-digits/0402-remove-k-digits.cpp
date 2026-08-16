class Solution {
public:
    string removeKdigits(string num, int k) {
        // STL stack to store the digits
    stack<char> st;

    // Traverse every digit
    for(int i = 0; i < num.size(); i++)
    {
        char ch = num[i];

        // Remove bigger digits from the top
        // if the current digit is smaller
        while(k > 0 && !st.empty() && st.top() > ch)
        {
            st.pop();
            k--;
        }

        // Put current digit into stack
        st.push(ch);
    }

    // If some removals are still left,
    // remove digits from the top
    while(k > 0)
    {
        st.pop();
        k--;
    }

    // Stack stores digits in reverse order,
    // so we need to take them out and reverse them
    string ans = "";

    while(!st.empty())
    {
        ans += st.top();
        st.pop();
    }
while(ans.size()!=0 && ans.back()=='0'){
    ans.pop_back();
   }
    reverse(ans.begin(), ans.end());

    // Remove leading zeroes
   if(ans.empty()){
    return "0";
   }
   return ans;
    }
};