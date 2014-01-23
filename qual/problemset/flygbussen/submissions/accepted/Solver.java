import java.util.*;
import java.io.*;

public class Solver {
	
	static int n, rtt;
	static long[] time, cnt;
	static long[][] cost, dp;
	static int[][] jump;
	
	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter out = new PrintWriter(System.out);
		
		StringTokenizer st = new StringTokenizer(in.readLine());
		int N = Integer.parseInt(st.nextToken());
		int K = Integer.parseInt(st.nextToken());
		rtt = 2*K;
		TreeMap<Long, Integer> timeCount = new TreeMap<Long, Integer>();
		st = new StringTokenizer(in.readLine());
		for (int i = 0; i < N; i++) {
			long t = Long.parseLong(st.nextToken());
			if (timeCount.containsKey(t)) {
				timeCount.put(t, timeCount.get(t) + 1);
			} else {
				timeCount.put(t, 1);
			}
		}
		n = timeCount.size();
		time = new long[n];
		cnt = new long[n];
		int index = 0;
		for (long t : timeCount.keySet()) {
			time[index] = t;
			cnt[index] = timeCount.get(t);
			index++;
		}
		jump = new int[n][2*rtt];
		cost = new long[n][2*rtt];
		for (int i = 0; i < n; i++) {
			long passengerCnt = cnt[i];
			long accCost = 0;
			int jumpCnt = 1;
			int next = i+1;
			cost[i][0] = 0;
			jump[i][0] = 1;
			for (int j = 1; j < 2*rtt; j++) {
				accCost += passengerCnt;
				if (next < n && time[i] + j == time[next]) {
					passengerCnt += cnt[next];
					jumpCnt++;
					next++;
				}
				cost[i][j] = accCost;
				jump[i][j] = jumpCnt;
			}
		}
		dp = new long[n][2*rtt];
		for (int i = 0; i < n; i++) {
			Arrays.fill(dp[i], -1);
		}
		out.println(solve(0, 0));
		
		in.close();
		out.close();
	}
	
	static long solve(int team, int offset) {
		if (team == n) return 0;
		if (dp[team][offset] != -1) return dp[team][offset];
		int next = team + jump[team][offset];
		int nextOffset = next >= n ? 0 : Math.max(0, (int)(time[team] + offset + rtt - time[next]));
		long res = cost[team][offset] + solve(next, nextOffset);
		if (next < n && time[next] - time[team] < 2*rtt) {
			res = Math.min(res, solve(team, (int)(time[next] - time[team])));
		}
		return dp[team][offset] = res;
	}
}
