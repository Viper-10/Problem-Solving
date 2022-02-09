class Solution
{
public:
  int longestValidParentheses(const string &s)
  {
    stack<int> st;
    int maxLength = 0;

    for (int i = 0; i < s.size(); ++i)
    {
      if (!st.empty() && s[i] == ')')
      {
        if (s[st.top()] == '(')
        {
          st.pop();
          int j = st.empty() ? j = -1 : j = st.top();

          maxLength = max(maxLength, i - j);
        }
        else
        {
          st.push(i);
        }
      }
      else
      {
        st.push(i);
      }
    }

    return maxLength;
  }
};