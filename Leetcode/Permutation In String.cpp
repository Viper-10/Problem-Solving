class Solution
{
public:
  bool checkInclusion(string &s1, string &s2)
  {

    int l1 = s1.size();
    int l2 = s2.size();

    if (l1 > l2)
      return false;

    int freqOfs1[26] = {0};
    int freqOfs2[26] = {0};

    for (int i = 0; i < l1; ++i)
    {
      freqOfs1[s1[i] - 'a']++;
    }

    for (int i = 0; i < l1 - 1; ++i)
    {
      freqOfs2[s2[i] - 'a']++;
    }

    for (int i = l1 - 1; i < l2; ++i)
    {
      freqOfs2[s2[i] - 'a']++;
      bool ans = true;

      for (int j = 0; j < 26; ++j)
      {
        if (freqOfs1[j] != freqOfs2[j])
        {
          ans = false;
        }
      }

      if (ans)
        return true;
      freqOfs2[s2[i - l1 + 1] - 'a']--;
    }

    return false;
  }
};