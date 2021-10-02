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
        
        mp[c]++;
        
        if (mp.size() == 27)
        {
            return result;
        }
    }
    
    result.insert(0, "not ");
    return result;
}

