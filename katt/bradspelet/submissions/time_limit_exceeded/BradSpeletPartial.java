import java.io.*;
import java.util.*;

public class BradSpeletPartial {
	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter out = new PrintWriter(System.out);
		StringTokenizer st = new StringTokenizer(in.readLine());
		
		int N = Integer.parseInt(st.nextToken());
		int M = Integer.parseInt(st.nextToken());
		boolean[][] win = new boolean[N][M];
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (i > 0) {
					for (int k = 0; k <= i/2; k++) {
						win[i][j] |= !win[k][j] && !win[i - k - 1][j];
					}
				}
				if (j > 0) {
					for (int k = 0; k <= j/2; k++) {
						win[i][j] |= !win[i][k] && !win[i][j - k - 1];
					}
				}
			}
		}
		out.println(win[N-1][M-1] ? "A" : "B");
		
		
		in.close();
		out.close();
	}
}
