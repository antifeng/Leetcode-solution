/*Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can be segmented into a space-separated sequence of one or more dictionary words. You may assume the dictionary does not contain duplicate words.

For example, given
s = "leetcode",
dict = ["leet", "code"].

"abcd"
["a","abc","b","cd"]

"bb"
"a","b","bbb","bbbb"

Return true because "leetcode" can be segmented as "leet code"
*/
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
private:
    bool bFound;
    int* visited;
public:

    // Depth first traverse the solution graph
    // Find any item in dict could match the string s start at pos
    bool backTrack( string s, int pos, vector<string>& dict, vector<string>& path )
    {
        bool bMatched = false;

        // for_each( path.begin(), path.end(), [](string& f)
        //                                {
        //                                   cout<< f << endl;
        //                                });
        // Prevent reentry
        for ( int i = visited[pos]+1; i < dict.size(); ++i )
        {
            visited[pos] = i;

            if ( ( pos + dict[i].length() )  > s.length() )
                continue;

            bMatched = ( pos == s.find( dict[i], pos ) );

            // if matched then test the rest of the string with all elements in the dict
            // Otherwise try to match with other elements in the dict
            if (bMatched)
            {
                path.push_back( dict[i] );
                if ( ( pos + dict[i].length() ) == s.length() )
                {
                    bFound = true;
                    return true;
                }

                return backTrack(s, pos+dict[i].length(), dict, path );
            }
        } // end for

        // Still not found, backtrack when possible
        // Or return false if not matched
        if ( path.size() > 0 )
        {
            string last = path[path.size()-1];
            path.erase(path.begin() + path.size() - 1 );
            return backTrack( s, pos-last.length(), dict, path );
        }

        return false;
    }

    bool wordBreak(string s, vector<string>& wordDict )
    {
      sort( wordDict.begin(), wordDict.end() );

      bFound = false;
      visited = new int[s.length()]();

      // -1 is also necessary for the initial iteration
      std::fill_n( visited, s.length(), -1 );

      vector<string> path;
      backTrack( s, 0, wordDict, path );
      delete [] visited;

      for_each( path.begin(), path.end(), [](string& f)
                                     {
                                        cout<< f << endl;
                                     });

      return bFound;
    }
};

int main()
{
    vector<string> vec = { "a","b","bbb","bbbb" };

    Solution s;
    if ( s.wordBreak( "bb", vec ) )
        cout << "true" << endl;
    else
        cout << "false" << endl;

    ////////////////////

    vector<string> vec2 = { "a","abc","b","cd" };
    if ( s.wordBreak( "abcd", vec2 ) )
      cout << "true" << endl;
    else
      cout << "false" << endl;

    return 0;
}

/*
Initial version didn't pass

bool wordBreak(string s, vector<string>& wordDict) {

        sort( wordDict.begin(), wordDict.end(), [](const string& a, const string& b) -> bool
      {
          return a.length() > b.length();
      });

      for_each(wordDict.begin(), wordDict.end(), [&s](const string& f)
                            {
                                std::size_t pos = s.find(f);
                                while ( pos != string::npos )
                                {
                                   s.erase( pos, f.length() );
                                   pos = s.find(f);
                                }
                            });

      return s.empty();
    }
*/
