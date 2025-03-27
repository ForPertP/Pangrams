import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.function.*;
import java.util.regex.*;
import java.util.stream.*;
import static java.util.stream.Collectors.joining;
import static java.util.stream.Collectors.toList;

class Result {

    /*
     * Complete the 'pangrams' function below.
     *
     * The function is expected to return a STRING.
     * The function accepts STRING s as parameter.
     */

    public static String pangrams(String s) {
        boolean[] alphabet = new boolean[26];
        int count = 0;

        for (char c : s.toCharArray()) {
            if (Character.isLetter(c)) {
                int index = Character.toLowerCase(c) - 'a';
                if (!alphabet[index]) {
                    alphabet[index] = true;
                    if (++count == 26) return "pangram";
                }
            }
        }

        return "not pangram";
    }
    
    
    public static String pangrams2(String s) {
        Set<Character> set = new HashSet<>();

        for (char c : s.toCharArray()) {
            if (Character.isLetter(c)) {
                set.add(Character.toLowerCase(c));
                if (set.size() == 26) return "pangram";
            }
        }

        return "not pangram";
    }
    
    
    public static String pangrams3(String s) {
        Map<Character, Boolean> map = new HashMap<>();
        int count = 0;

        for (char c : s.toCharArray()) {
            if (Character.isLetter(c)) {
                char lowerC = Character.toLowerCase(c);
                if (!map.containsKey(lowerC)) {
                    map.put(lowerC, true);
                    if (++count == 26) return "pangram";
                }
            }
        }

        return "not pangram";
    }    
}


public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        String s = bufferedReader.readLine();

        String result = Result.pangrams(s);

        bufferedWriter.write(result);
        bufferedWriter.newLine();

        bufferedReader.close();
        bufferedWriter.close();
    }
}
