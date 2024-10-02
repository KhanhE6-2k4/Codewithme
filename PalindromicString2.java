import java.util.*;
import java.io.*;

public class PalindromicString2 {
    static String Solve(String str) {
      
        int n = str.length();
        char result[] = new char[n];
      
        int alphabet[] = new int[26];
        for (int i = 0; i < n; i++) {
            alphabet[str.charAt(i) - 'A']++;
        }
        int odd_cnt = 0;
        char midChar = 0;
    
        for (int i = 0; i < 26; i++) {
            if (alphabet[i] % 2 == 1) {
                odd_cnt++;
                midChar = (char)(i + 'A');
            }
        }
        if (odd_cnt > 1) {
            return "NO SOLUTION";
          
        }
        int left = 0, right = n - 1;
        for (int i = 0; i < 26; i++) {
            if (alphabet[i] % 2 == 0) {
                while (alphabet[i] > 0) {
                    result[left++] = result[right--] = (char)(i + 'A');
                    alphabet[i] -= 2;
                }
            }
            else {
                while (alphabet[i] > 1) {
                    result[left++] = result[right--] = (char)(i + 'A');
                    alphabet[i] -= 2;
                }
                result[n/2] = midChar;
            }
        }
        
       
        
        //return String.copyValueOf(result);
        return new String(result);
        
        
    }
    public static void main(String[] args) throws IOException {
        BufferedReader bf = new  BufferedReader(new InputStreamReader(System.in));
        String str = bf.readLine();
        str = Solve(str);
        System.out.println(str);
        
    }
}