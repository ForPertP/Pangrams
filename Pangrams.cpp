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


string pangrams(string s)
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
