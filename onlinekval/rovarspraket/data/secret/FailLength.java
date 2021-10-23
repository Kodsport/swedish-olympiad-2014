import java.util.*;
import java.io.*;

public class FailLength {
    
	static int n, m;
	static char[] start, goal;
	static boolean[][] visited;
	
	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter out = new PrintWriter(System.out);
		
		start = in.readLine().toCharArray();
		goal = in.readLine().toCharArray();
		n = start.length;
		m = goal.length;
		visited = new boolean[n+1][m+1];
		dfs(0, 0);
		out.println(visited[n][m] ? "ja" : "nej");
		
		in.close();
		out.close();
	}
	
	static boolean isConsonant(char c) {
		return !"aeiouy".contains(c+"");
	}
	
	static void dfs(int p1, int p2) {
		if (visited[p1][p2]) return;
		visited[p1][p2] = true;
		if (p1 < n && p2 < m) {
			if (start[p1] == goal[p2]) {
				dfs(p1+1, p2+1);
				System.out.println(p1+" "+p2);
				if (p2 + 2 <= m && isConsonant(goal[p2]) && goal[p2+1] == 'o' && goal[p2+2] == goal[p2]) {
					System.out.println("yeah");
					dfs(p1+1, p2+3);
				}
			}
		}
	}
}

