import java.util.*;
import java.io.*;

public class Limousinen {
	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter out = new PrintWriter(System.out);
		
		StringTokenizer st = new StringTokenizer(in.readLine());
		int N = Integer.parseInt(st.nextToken());
		long T = Integer.parseInt(st.nextToken());
		long t = 0;
		long[] times = new long[N];
		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(in.readLine());
			long x = Integer.parseInt(st.nextToken());
			long y = Integer.parseInt(st.nextToken());
			times[i] = 2*(Math.abs(x)+Math.abs(y));
		}
		Arrays.sort(times);
		int res = 0;
		while (res < N && t + times[res] <= T) {
			t += times[res++];
		}
		out.println(res);
		
		in.close();
		out.close();
	}
}
