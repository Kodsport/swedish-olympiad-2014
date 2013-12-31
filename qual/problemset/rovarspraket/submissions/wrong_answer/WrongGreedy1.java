package rovarspraket;

import java.util.*;
import java.io.*;

public class WrongGreedy1 {
	
	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter out = new PrintWriter(System.out);
		
		char[] start = in.readLine().toCharArray();
		char[] goal = in.readLine().toCharArray();
		int n = start.length;
		int m = goal.length;
		int i = 0, j = 0;
		while (i < n && j < m) {
			if (start[i] != goal[j]) break;
			if (n - i < m - j && isConsonant(goal[j]) && j + 2 < m && goal[j+1] == 'o' && goal[j+2] == goal[j]) {
				j += 2;
			}
			i++;
			j++;
		}
		out.println(i == n && j == m ? "ja" : "nej");
		
		in.close();
		out.close();
	}
	
	static boolean isConsonant(char c) {
		return !"aeiouy".contains(c+"");
	}
}
