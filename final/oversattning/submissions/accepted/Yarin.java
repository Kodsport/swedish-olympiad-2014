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
import java.io.FileNotFoundException;
import java.util.HashMap;
import java.util.Map;
 
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
    public static void main(String[] args) throws FileNotFoundException {
        Kattio io = new Kattio(System.in, System.out);
        int N = io.getInt();
        HashMap<String, String> sweEng = new HashMap<String, String>();
        HashMap<String, String> engSwe = new HashMap<String, String>();
        for (int i = 0; i < N; i++) {
            String swe = io.getWord();
            String eng = io.getWord();
            if (!sweEng.containsKey(swe)) sweEng.put(swe, eng);
            if (!engSwe.containsKey(eng)) engSwe.put(eng, swe);
        }
        Map<String,String> cache = new HashMap<String,String>();
        boolean first = true;
        while (io.hasMoreTokens()) {
            String a = io.getWord();
            if (!cache.containsKey(a)) {
                String org = a;
                String aa = null;
                while (!a.equals(aa)) {
                    aa = a;
                    String b = sweEng.get(a);
                    a = engSwe.get(b);
                }
                cache.put(org, a);
            } else {
                a = cache.get(a);
            }
            if (!first) io.print(" ");
            first = false;
            io.print(a);
        }
        io.println();
        
        io.close();
    }
}
 
