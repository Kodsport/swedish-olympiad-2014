import java.util.*;
import java.io.*;

public class Solver {
	
	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter out = new PrintWriter(System.out);
		StringTokenizer st;
		
		char[] c = new char[1<<4];
		Arrays.fill(c, '?');
		int T = Integer.parseInt(in.readLine());
		for (int i = 0; i < T; i++) {
			st = new StringTokenizer(in.readLine());
			char ch = st.nextToken().charAt(0);
			c[Integer.parseInt(st.nextToken(), 2)] = ch;
		}
		
		String s = in.readLine();
		int index = 0;
		while (index < s.length()) {
			out.print(c[Integer.parseInt(s.substring(index, index + 4), 2)]);
			index += 4;
		}
		out.println();
		
		in.close();
		out.close();
	}
}
