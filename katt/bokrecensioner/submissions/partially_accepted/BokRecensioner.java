import java.util.*;
import java.io.*;

public class BokRecensioner {
	
	/*
6 4 6
2 < 1
3 = 1
6 = 3
6 < 5
5 < 4
1 < 4
	 */
	
	static int N, M, R;
	static int[] deg, res, par, rank;
	static Edge[] g;
	
	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter out = new PrintWriter(System.out);
		StringTokenizer st = new StringTokenizer(in.readLine());
		
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		R = Integer.parseInt(st.nextToken());
		deg = new int[N];
		par = new int[N];
		rank = new int[N];
		for (int i = 0; i < N; i++) {
			par[i] = i;
			rank[i] = 1;
		}
		g = new Edge[N];
		ArrayList<int[]> ltEdges = new ArrayList<int[]>();
		for (int i = 0; i < R; i++) {
			st = new StringTokenizer(in.readLine());
			int a = Integer.parseInt(st.nextToken()) - 1;
			String op = st.nextToken();
			if (op.length() == 2) {
				throw new RuntimeException("Not implemented");
			} else if (op.charAt(0) == '<') {
				int b = Integer.parseInt(st.nextToken()) - 1;
				ltEdges.add(new int[] {a,b});
			} else if (op.charAt(0) == '=') {
				int b = Integer.parseInt(st.nextToken()) - 1;
				merge(a, b);
			}
		}
		boolean good = true;
		for (int[] ltEdge : ltEdges) {
			int pa = find(ltEdge[0]), pb = find(ltEdge[1]);
			if (pa == pb) {
				good = false;
				break;
			}
			g[pa] = new Edge(pb, g[pa]);
			deg[pb]++;
		}
		
		LinkedList<Integer> q = new LinkedList<Integer>();
		res = new int[N];
		for (int i = 0; i < N; i++) {
			int p = find(i);
			if (deg[p] == 0 && res[p] == 0) {
				res[p] = 1;
				q.add(p);
			}
		}
		
		while (!q.isEmpty()) {
			int v = q.removeFirst();
			for (Edge e = g[v]; e != null; e = e.next) {
				deg[e.to]--;
				if (deg[e.to] == 0) {
					res[e.to] = res[v] + 1;
					q.add(e.to);
				}
			}
		}
		for (int i = 0; i < N; i++) {
			int p = find(i);
			if (res[p] < 1 || res[p] > M) {
				good = false;
				break;
			}
		}
		if (!good) {
			out.println(-1);
		} else {
			out.print(res[find(0)]);
			for (int i = 1; i < N; i++) {
				out.write(' ');
				out.print(res[find(i)]);
			}
			out.println();
		}
		
		in.close();
		out.close();
	}
	
	static int find(int v) {
		if (par[v] == v) return v;
		return par[v] = find(par[v]);
	}
	
	static void merge(int a, int b) {
		int pa = find(a), pb = find(b);
		if (pa != pb) {
			if (rank[pa] < rank[pb]) {
				par[pa] = pb;
			} else if (rank[pa] > rank[pb]) {
				par[pb] = pa;
			} else {
				par[pa] = pb;
				rank[pb]++;
			}
		}
	}
	
	static class Edge {
		int to;
		Edge next;
		public Edge(int to, Edge next) {
			this.to = to;
			this.next = next;
		}
	}
}
