#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'pangrams' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

std::string pangrams(std::string s)
{
    std::unordered_set<char> st;
    
    for (char c : s)
    {
        if (std::isalpha(c))
        {
            st.insert(std::tolower(c));
            if (st.size() == 26) return "pangram";
        }
    }

    return "not pangram";
}

std::string pangrams2(std::string s)
{
    std::vector<bool> alphabet(26, false);
    int count = 0;

    for (char c : s)
    {
        if (std::isalpha(c))
        {
            int index = std::tolower(c) - 'a';
            if (!alphabet[index])
            {
                alphabet[index] = true;
                if (++count == 26) return "pangram";
            }
        }
    }

    return "not pangram";
}


std::string pangrams_map(std::string s)
{
    std::unordered_map<char, bool> mp;
    int count = 0;

    for (char c : s)
    {
        if (std::isalpha(c))
        {
            c = std::tolower(c);
            if (!mp[c])
            {
                mp[c] = true;
                if (++count == 26) return "pangram";
            }
        }
    }

    return "not pangram";
}



string pangrams(string s)
{
    std::string result {"pangram"};
    std::set<char> st;

    for (char c : s)
    {
        if (std::isupper(c) != 0)
        {
            c = tolower(c);
        }
        
        auto ret = st.insert(c);
        
        if (ret.second == true && st.size() >= 27)
        {
            return result;
        }
    }
    
    result.insert(0, "not ");
    return result;
}


string pangrams2(string s)
{
    std::string result {"pangram"};
    std::map<char, char> mp;

    for (char c : s)
    {
        if (std::isupper(c) != 0)
        {
            c = tolower(c);
        }
        
        mp[c];
        
        if (mp.size() == 27)
        {
            return result;
        }
    }
    
    result.insert(0, "not ");
    return result;
}



int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = pangrams(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
