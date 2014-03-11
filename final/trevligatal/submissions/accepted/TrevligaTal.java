import java.io.*;
import java.util.*;

public class TrevligaTal {
	
	static final int MOD = 1000000007;
	
	static int n;
	static int[] d;
	static int[][][] dp;
	
	public static void main(String[] args) throws IOException {
		String s = new BufferedReader(new InputStreamReader(System.in)).readLine();
		n = s.length();
		d = new int[n];
		for (int i = 0; i < n; i++) {
			d[i] = s.charAt(i) - '0';
		}
		dp = new int[n][3][2];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 3; j++) {
				Arrays.fill(dp[i][j], -1);
			}
		}
		int res = solve(0, 0, 1) - 1;
		if (res < 0) res += MOD;
		System.out.println(res);
	}
	
	static int solve(int pos, int sum, int first) {
		if (pos == n) {
			return sum == 0 ? 1 : 0;
		}
		if (dp[pos][sum][first] != -1) return dp[pos][sum][first];
		int res = solve(pos + 1, sum, first);
		if (d[pos] == 0 && first == 1) {
			res = (res + 1) % MOD;
		} else {
			res = (res + solve(pos + 1, (sum + d[pos]) % 3, 0)) % MOD;
		}
		return dp[pos][sum][first] = res;
	}
}
