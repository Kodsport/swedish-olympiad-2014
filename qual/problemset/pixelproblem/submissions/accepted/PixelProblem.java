import java.util.*;
import java.io.*;

public class PixelProblem {
	
	static int[] r, g, b;
	
	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter out = new PrintWriter(System.out);
		
		int N = Integer.parseInt(in.readLine());
		
		StringTokenizer st = new StringTokenizer(in.readLine());
		r = new int[N];
		g = new int[N];
		b = new int[N];
		for (int i = 0; i < N; i++) {
			r[i] = Integer.parseInt(st.nextToken());
			g[i] = Integer.parseInt(st.nextToken());
			b[i] = Integer.parseInt(st.nextToken());
		}
		double best = -1;
		int bestW = -1;
		for (int w = 2; w < N; w++) {
			if (N % w == 0) {
				double d = 0;
				int cnt = 0;
				for (int i = 0; i < N; i++) {
					if (i + w < N) {
						d += diff(i, i + w);
						cnt++;
					}
					if (i % w < w-1) {
						d += diff(i, i+1);
						cnt++;
					}
				}d /= cnt;
				if (best < 0 || d < best) {
					best = d;
					bestW = w;
				}
			}
		}
		out.println(bestW + " " + N/bestW);
		
		in.close();
		out.close();
	}
	
	static int diff(int p1, int p2) {
		int res = Math.abs(r[p1] - r[p2]);
		res = Math.max(res, Math.abs(g[p1] - g[p2]));
		res = Math.max(res, Math.abs(b[p1] - b[p2]));
		return res;
	}
}
