import java.util.Arrays;
import java.io.*;
public class PalindromicString {

    // function to construct a palindromic string
    static String solve(String S)  {
        int N = S.length();
        char[] ans = new char[N];

        // frequency array to count the occurrence of each character
        int[] freq = new int[26];
        for (int i = 0; i < N; i++) {
            freq[S.charAt(i) - 'A'] += 1;
        }

        // Count the number of characters having odd frequency
        int cnt = 0;
        for (int i = 0; i < 26; i++) {
            if (freq[i] % 2 != 0) {
                cnt += 1;
            }
        }

        // If more than one character has odd frequency, then no solution exists
        if (cnt > 1)
            return "NO SOLUTION";

        int left = 0, right = N - 1;
        for (int i = 0; i < 26; i++) {
            while (freq[i] > 1) {
                ans[left++] = ans[right--] = (char) ('A' + i);
                freq[i] -= 2;
            }
        }

        for (int i = 0; i < 26; i++) {
            if (freq[i] == 1) {
                ans[N / 2] = (char) ('A' + i);
                break;
            }
        }

        return new String(ans);
    }

    public static void main(String[] args) throws IOException {
        // Sample Input
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        String S = new String();
        S = bf.readLine();
        System.out.println(solve(S));
    }
}
