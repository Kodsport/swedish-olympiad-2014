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
import java.util.ArrayList;
import java.util.Collections;
 
public class Yarin {
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
    private static class Point implements Comparable<Point> {
        public int x,y;
 
        private Point(int x, int y) {
            this.x = x;
            this.y = y;
        }
 
        public int compareTo(Point point) {
            int d1 = Math.abs(x)+Math.abs(y);
            int d2 = Math.abs(point.x)+Math.abs(point.y);
            return d1-d2;
        }
    }
    public static void main(String[] args) {
        Kattio kattio = new Kattio(System.in, System.out);
 
        int N = kattio.getInt(), t = kattio.getInt();
        ArrayList<Point> points = new ArrayList<Point>();
        for (int i = 0; i < N; i++) {
            int x = kattio.getInt(), y = kattio.getInt();
            points.add(new Point(x,y));
        }
        Collections.sort(points);
        int done = 0;
        while (done < N) {
            Point p = points.get(done);
            t -= 2*(Math.abs(p.x)+Math.abs(p.y));
            if (t >= 0) done++; else break;
        }
        kattio.println(done);
 
        kattio.close();
    }
}
