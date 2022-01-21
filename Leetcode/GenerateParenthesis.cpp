class Solution
{
private:
  vector<string> recursion(int n)
  {
    if (n == 0)
    {
      return {""};
    }

    if (n == 1)
    {
      return {"()"};
    }

    vector<string> output;

    for (int i = 0; i < n; ++i)
    {
      vector<string> op1 = recursion(i);
      vector<string> op2 = recursion(n - i - 1);

      for (int j = 0; j < op1.size(); ++j)
      {
        for (int k = 0; k < op2.size(); ++k)
        {
          output.push_back("(" + op1[j] + ")" + op2[k]);
        }
      }
    }

    return output;
  }

public:
  vector<string> generateParenthesis(int n)
  {
    vector<vector<string>> output(n + 1);

    output[0].push_back("");
    output[1].push_back("()");

    for (int i = 2; i <= n; ++i)
    {
      for (int j = 0; j < i; ++j)
      {
        vector<string> op1 = output[j];
        vector<string> op2 = output[i - 1 - j];

        for (string &s : op1)
        {
          for (string &p : op2)
          {
            output[i].push_back("(" + s + ")" + p);
          }
        }
      }
    }

    return output[n];
  }
};