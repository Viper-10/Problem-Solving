class Solution
{
private:
  string alphabets[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

public:
  vector<string> letterCombinations(string &digits, int i = 0)
  {
    if (digits.size() == 0)
    {
      return {};
    }

    if (i == digits.size())
    {
      return {""};
    }

    vector<string> smallOutput = letterCombinations(digits, i + 1);

    int letter = digits[i] - '0';

    vector<string> output;

    for (int i = 0; i < alphabets[letter].size(); ++i)
    {
      for (int j = 0; j < smallOutput.size(); ++j)
      {
        output.push_back(alphabets[letter][i] + smallOutput[j]);
      }
    }

    return output;
  }
};