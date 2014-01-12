import java.util.*;
import java.io.*;

public class Solver {
	
	static final char WALL = '#', EMPTY = '.', BEAR = 'B', PLAYER = 'S', EXIT = 'U';
	static final char[] DIR_CHARS = {'V', 'H', 'U', 'N'};
	
	static int[] d;
	static char[] grid;
	static int W, H;
	static int player, bear;
	static char[] res;
	
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
		for (int maxDepth = 0; ; maxDepth++) {
			if (solve(0, maxDepth)) {
				out.println(String.valueOf(res));
				break;
			}
		}
		
		in.close();
		out.close();
	}
	
	static int dist(int p1, int p2) {
		return Math.abs(p1/W - p2/W) + Math.abs(p1%W - p2%W);
	}
	
	static boolean solve(int depth, int maxDepth) {
		if (grid[player] == EXIT) {
			res = new char[depth];
			return true;
		}
		if (player == bear || depth == maxDepth) return false;
		int oldPlayer = player, oldBear = bear;
		for (int playerDir = 0; playerDir < 4; playerDir++) {
			int newPlayer = player + d[playerDir];
			if (newPlayer != bear && grid[newPlayer] != WALL) {
				player = newPlayer;
				
				// Move bear
				int movesLeft = 2;
				for (int bearDir = 0; bearDir < 4; bearDir++) {
					int newBear = bear + d[bearDir];
					if (movesLeft > 0 && grid[newBear] != WALL && dist(newBear, player) < dist(bear, player)) {
						bear = newBear;
						movesLeft--;
						bearDir--;
					}
				}
				boolean success = solve(depth + 1, maxDepth);
				player = oldPlayer;
				bear = oldBear;
				if (success) {
					res[depth] = DIR_CHARS[playerDir];
					return true;
				}
			}
		}
		return false;
	}
}
