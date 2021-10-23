import java.util.*;
import java.io.*;

public class Solver {
	
	static final char WALL = '#', EMPTY = '.', BEAR = 'B', PLAYER = 'S', EXIT = 'U';
	static final char[] DIR_CHARS = {'V', 'H', 'U', 'N'};
	
	static int[] d;
	static char[] grid;
	static int W, H;
	static StringBuilder res;
	static boolean[][] visited;
	
	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter out = new PrintWriter(System.out);
		
		StringTokenizer st = new StringTokenizer(in.readLine());
		int w = Integer.parseInt(st.nextToken());
		int h = Integer.parseInt(st.nextToken());
		W = w+2;
		H = h+2;
		d = new int[] {-1, 1, -W, W};
		grid = new char[W*H];
		for (int i = 0; i < W; i++) {
			grid[i] = grid[W*(H-1) + i] = WALL;
		}
		int bear = -1, player = -1;
		for (int i = 1; i <= h; i++) {
			grid[W*i] = grid[W*i + W - 1] = WALL;
			String s = in.readLine();
			for (int j = 1; j <= w; j++) {
				char c = s.charAt(j-1);
				if (c == BEAR) {
					bear = W*i + j;
					c = EMPTY;
				} else if (c == PLAYER) {
					player = W*i + j;
					c = EMPTY;
				}
				grid[W*i + j] = c;
			}
		}
		visited = new boolean[W*H][W*H];
		solve(player, bear);
		out.println(res.reverse());
		
		in.close();
		out.close();
	}
	
	static int dist(int p1, int p2) {
		return Math.abs(p1/W - p2/W) + Math.abs(p1%W - p2%W);
	}
	
	static boolean solve(int player, int bear) {
		if (grid[player] == EXIT) {
			res = new StringBuilder();
			return true;
		}
		if (visited[player][bear]) return false;
		visited[player][bear] = true;
		if (player == bear) return false;
		
		for (int playerDir = 0; playerDir < 4; playerDir++) {
			int newPlayer = player + d[playerDir];
			if (newPlayer != bear && grid[newPlayer] != WALL) {
				int newBear = bear;
				// Move bear
				int movesLeft = 2;
				for (int bearDir = 0; bearDir < 4; bearDir++) {
					int newBear2 = newBear + d[bearDir];
					if (movesLeft > 0 && grid[newBear2] != WALL && dist(newBear2, newPlayer) < dist(newBear, newPlayer)) {
						newBear = newBear2;
						movesLeft--;
						bearDir--;
					}
				}
				boolean success = solve(newPlayer, newBear);
				if (success) {
					res.append(DIR_CHARS[playerDir]);
					return true;
				}
			}
		}
		return false;
	}
}
