/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
import java.util.Scanner;
import java.util.Arrays;

public class Palindrome_Reorder
{
	public static void main(String[] args) {
	    int n = 1000001;
	    int Alphabet[] = new int[n];
	    Scanner s = new Scanner(System.in);
	    String str = new String();
	    str = s.nextLine();
	    int l = str.length();
	    for (int i = 0; i < l; i++) {
	        Alphabet[str.charAt(i) - 'A']++;
	    }
	    Character midChar = null;     // ky tu nam chinh giua xau neu co
	    int odd_cnt = 0;     // so luong chu cai xuat hien le lan trong xau
	    int even_cnt = 0;    // so luong chu cai xuat hien chan lan trong xau
	    for (int i = 0; i < 26; i++) {
	        if (Alphabet[i] % 2 != 0) {
	            odd_cnt++;
	            midChar = (char)('A' + i);
	        }
	        else
	        even_cnt++;
	    }
	    
	    if (odd_cnt > 1) {
	        System.out.println("NO SOLUTION");
	    }
	    else {
	        // In nua dau cua xau doi xung
	        for (int i = 0; i < 26; i++) {
	            if (Alphabet[i] % 2 == 0) {
	                int half_length = Alphabet[i] / 2;
	                for (int j = 0; j < half_length; j++)
	                System.out.print((char)('A' + i)); 
	            }
	        }
	        // In phan tu chinh giua (neu co)
	        if (midChar != null)
	        System.out.print(midChar.toString());
	        // In nua sau cua xau doi xung
	        for (int i = 25; i >= 0; i--) {
	            if (Alphabet[i] % 2 == 0) {
	                int half_length = Alphabet[i] / 2;
	                for (int j = 0; j < half_length; j++)
	                System.out.print((char)('A' + i));
	            }
	        }
	    }
	    
	}
}
