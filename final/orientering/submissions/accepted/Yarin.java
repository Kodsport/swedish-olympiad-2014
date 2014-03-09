// Arash have tampaered with this for Kattio...

import java.util.LinkedList;
import java.util.Queue;

import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

import java.io.BufferedOutputStream;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
 
public class Yarin {
 
    public static int dx[] = new int[] {1,-1,0,0};
    public static int dy[] = new int[] {0,0,1,-1};
 
    public static class State {
        public int x, y, dir;
 
        public State(int x, int y, int dir) {
            this.x = x;
            this.y = y;
            this.dir = dir;
        }
    }

    public static class Kattio extends PrintWriter{
       public Kattio(InputStream i) {
                super(new BufferedOutputStream(System.out));
                r = new BufferedReader(new InputStreamReader(i));
        }
 
        public Kattio(InputStream i, OutputStream o) {
                super(new BufferedOutputStream(o));
                r = new BufferedReader(new InputStreamReader(i));
        }
 
        public boolean hasMoreTokens() {
                return peekToken() != null;
        }
 
        public int getInt() {
                return Integer.parseInt(nextToken());
        }
 
        public double getDouble() {
                return Double.parseDouble(nextToken());
        }
 
        public long getLong() {
                return Long.parseLong(nextToken());
        }
 
        public String getWord() {
                return nextToken();
        }
 
 
        private BufferedReader r;
        private String line;
        private StringTokenizer st;
        private String token;
 
        private String peekToken() {
                if (token == null)
                        try {
                                while (st == null || !st.hasMoreTokens()) {
                                        line = r.readLine();
                                        if (line == null) return null;
                                        st = new StringTokenizer(line);
                                }
                                token = st.nextToken();
                        } catch (IOException e) {
                        }
                return token;
        }
 
        private String nextToken() {
                String ans = peekToken();
                token = null;
                return ans;
        }
    }
 
    public static int[][][] dist;
    public static int xsize, ysize;
 
    public static void main(String[] args) {
        Kattio io = new Kattio(System.in, System.out);
 
        ysize = io.getInt();
        xsize = io.getInt();
        dist = new int[ysize][xsize][4];
        int ey = io.getInt() - 1, ex = io.getInt() - 1;
        int map[][] = new int[ysize][xsize];
        for (int y = 0; y < ysize; y++) {
            String s = io.getWord();
            for (int x = 0; x < s.length(); x++) {
                switch (s.charAt(x)) {
                    case '.' : map[y][x] = -1; break;
                    case 'v' : map[y][x] = 2; break;
                    case '>' : map[y][x] = 0; break;
                    case '^' : map[y][x] = 3; break;
                    case '<' : map[y][x] = 1; break;
                }
                for (int i = 0; i < 4; i++) {
                    dist[y][x][i] = -1;
                }
 
            }
        }
 
        LinkedList<State> next = new LinkedList<State>();
        Queue<State> cur;
        int curdist = 0;
        add(0,0,0,0,next);
        while (next.size() > 0) {
            cur = next;
            next = new LinkedList<State>();
            while (cur.size() > 0) {
                State curState = cur.poll();
                //io.println("at " + curState.x + "," + curState.y);
                if (curState.y == ey && curState.x == ex) {
                    io.println(curdist);
                    io.close();
                    return;
                }
                int newDir = map[curState.y][curState.x];
                if (newDir < 0) newDir = curState.dir;
                add(curState.x + dx[newDir], curState.y + dy[newDir], newDir, curdist, cur);
                add(curState.x + dx[curState.dir], curState.y + dy[curState.dir], curState.dir, curdist + 1, next);
            }
            curdist++;
        }
        io.println("never");
        io.close();
    }
 
    private static void add(int x, int y, int dir, int dd, Queue<State> q) {
        if (x < 0 || y < 0 || x >= xsize || y >= ysize) return;
        if (dist[y][x][dir] < 0 || dd < dist[y][x][dir]) {
            dist[y][x][dir] = dd;
            q.add(new State(x,y,dir));
        }
    }
 
}
 
