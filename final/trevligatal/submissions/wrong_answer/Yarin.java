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
    public static void main(String[] args) {
        Kattio io = new Kattio(System.in, System.out);
        String s = io.getWord();
        int dp[][] = new int[s.length() + 1][3];
        dp[s.length()][0] = 1;
        int MOD = 1000000000;
        for (int i = s.length() - 1; i >= 0; i--) {
            for (int j = 0; j < 3; j++) {
                // at digit i, sum is j
                // keep it
                int newSum1 = (j+s.charAt(i)-'0')%3;
                int newSum2 = j;
                int cnt = (dp[i+1][newSum1] + dp[i+1][newSum2]) % MOD;
                dp[i][j] = cnt;
            }
        }
        io.println(dp[0][0]);
 
        io.close();
    }
}
