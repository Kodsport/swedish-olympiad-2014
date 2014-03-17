import java.util.*;
import java.io.*;

public class BradSpeletNaive {
	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter out = new PrintWriter(System.out);
		StringTokenizer st = new StringTokenizer(in.readLine());
		
		int N = Integer.parseInt(st.nextToken());
		int M = Integer.parseInt(st.nextToken());
		
		out.println(isWin(N, M) ? "A" : "B");
		
		in.close();
		out.close();
	}
	
	static boolean isWin(int n, int m) {
		for (int k = 1; k < n; k++) {
			if (!isWin(k, m) && !isWin(n-k, m)) return true;
		}
		for (int k = 1; k < m; k++) {
			if (!isWin(n, k) && !isWin(n, m - k)) return true;
		}
		return false;
	}
}
