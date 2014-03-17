import java.util.*;
import java.io.*;

public class BradSpelet {
	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter out = new PrintWriter(System.out);
		StringTokenizer st = new StringTokenizer(in.readLine());
		
		int N = Integer.parseInt(st.nextToken());
		int M = Integer.parseInt(st.nextToken());
		while (N % 2 == 0 && M % 2 == 0) {
			N /= 2;
			M /= 2;
		}
		out.println(N % 2 == M % 2 ? "B" : "A");
		
		in.close();
		out.close();
	}
}
