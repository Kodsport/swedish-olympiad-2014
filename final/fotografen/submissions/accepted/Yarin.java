
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
        int N = io.getInt(), k = io.getInt();
        int state[] = new int[N], rot[] = new int[N+1];
        String s = io.getWord();
        for (int i = 0; i < N; i++) {
            switch (s.charAt(i)) {
                case 'U': state[i] = 0; break;
                case 'H': state[i] = 1; break;
                case 'N': state[i] = 2; break;
                case 'V': state[i] = 3; break;
            }
        }
        int sum = 0, acc = 0;
        for (int i = 0; i < N; i++) {
            acc -= rot[i];
            int cur = (state[i] + acc) % 4;
            int nrot = (4 - cur) % 4;
            sum += nrot;
            acc += nrot;
            if (i+k <= N)
                rot[i+k] = nrot;
            else if (nrot > 0) {
                sum = -1;
                break;
            }
        }
        io.println(sum);
        io.close();
    }
}
 
