using System.CodeDom.Compiler;
using System.Collections.Generic;
using System.Collections;
using System.ComponentModel;
using System.Diagnostics.CodeAnalysis;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Runtime.Serialization;
using System.Text.RegularExpressions;
using System.Text;
using System;

class Result
{

    /*
     * Complete the 'pangrams' function below.
     *
     * The function is expected to return a STRING.
     * The function accepts STRING s as parameter.
     */

    public static string pangrams(string s)
    {
        bool[] alphabet = new bool[26];
        int count = 0;

        foreach (char c in s)
        {
            if (char.IsLetter(c))
            {
                int index = char.ToLower(c) - 'a';
                if (!alphabet[index])
                {
                    alphabet[index] = true;
                    if (++count == 26) return "pangram";
                }
            }
        }

        return "not pangram";
    }

     public static string pangrams2(string s)
    {
        HashSet<char> set = new HashSet<char>();

        foreach (char c in s)
        {
            if (char.IsLetter(c))
            {
                set.Add(char.ToLower(c));
                if (set.Count == 26) return "pangram";
            }
        }

        return "not pangram";
    }    
    
}


class Solution
{
    public static void Main(string[] args)
    {
        TextWriter textWriter = new StreamWriter(@System.Environment.GetEnvironmentVariable("OUTPUT_PATH"), true);

        string s = Console.ReadLine();

        string result = Result.pangrams(s);

        textWriter.WriteLine(result);

        textWriter.Flush();
        textWriter.Close();
    }
}
