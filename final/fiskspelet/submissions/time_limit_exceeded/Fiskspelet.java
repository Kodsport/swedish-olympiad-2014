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
 
public class Fiskspelet {

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
 
    public static class Fish implements Comparable<Fish> {
        public int index;
        public int size;
        public int height;
        public long x;
        public int y;
        public int speed;
        public long time;
        public long eatenAt = -1; // time
 
        public Fish(int index, String sz, long x, int y) {
            this.index = index;
            switch (sz.charAt(0)) {
                case 'L' : this.height = 3; speed=1; size=0; break;
                case 'M' : this.height = 5; speed=2; size=1; break;
                case 'S' : this.height = 9; speed=3; size=2; break;
            }
            this.x = x;
            this.y = y;
            this.time = this.x / speed;
        }
 
        public int compareTo(Fish fish) {
            if (x<fish.x) return -1;
            if (x>fish.x) return 1;
            return 0;
        }
    }
 
    public static class FishTimeSort implements Comparator<Fish> {
 
        public int compare(Fish fish, Fish fish2) {
            if (fish.time < fish2.time) return -1;
            if (fish.time > fish2.time) return 1;
            return 0;
        }
    }
 
    public static ArrayList<Fish> fishesLeft;
    public static int h;
 
    public static void main(String[] args) throws FileNotFoundException {
        Kattio io = new Kattio(System.in, System.out);
//        Kattio io = new Kattio(new FileInputStream("/Users/yarin/Desktop/F.in"), System.out);
//        String ans = new Scanner(new FileInputStream("/Users/yarin/Desktop/examples/sample0" + sample + ".ans")).next();
 
        int n = io.getInt();
        h = io.getInt();
        ArrayList<Fish> fishes = new ArrayList<Fish>(n);
        for (int i = 0; i < n; i++) {
            String size = io.getWord();
            long x = io.getLong();
            int y = io.getInt();
            fishes.add(new Fish(i, size, x, y));
        }
 
        List<List<Fish>> fh = new ArrayList<List<Fish>>();
        for (int i = 0; i <= h; i++) {
            fh.add(new ArrayList<Fish>());
        }
 
 
        for (Fish fish : fishes) {
            int miny = fish.y - fish.height / 2;
            int maxy = fish.y + fish.height / 2;
            for (int y = miny; y <= maxy; y++) {
                fh.get(y).add(fish);
            }
        }
 
        for (int i = 1; i <= h; i++) {
            Collections.sort(fh.get(i));
            // Only consider when the largest fish eat small/medium
            ArrayList<Fish> smaller = new ArrayList<Fish>();
            for (Fish fish : fh.get(i)) {
                if (fish.size < 2) smaller.add(fish);
                if (fish.size == 2) {
                    for (Fish sf : smaller) {
                        if (fish.time <= sf.time) {
                            long coll = (fish.x - sf.x)/(fish.speed - sf.speed);
                            if (coll >= 0) {
                                if (sf.eatenAt < 0 || coll < sf.eatenAt) {
                                    sf.eatenAt = coll;
                                }
                            }
                        }
                    }
                    smaller = new ArrayList<Fish>();
                }
            }
        }
 
        for (int i = 1; i <= h; i++) {
            // Only consider when the medium fish eat small
            ArrayList<Fish> smaller = new ArrayList<Fish>();
            for (Fish fish : fh.get(i)) {
                if (fish.size < 1) smaller.add(fish);
                if (fish.size == 1) {
                    int t = smaller.size() - 1;
                    while (t >= 0) {
                        Fish sf = smaller.get(t);
                        if (fish.time > sf.time) break;
                        long coll = (fish.x - sf.x)/(fish.speed - sf.speed);
                        if (fish.eatenAt >= 0 && coll >= fish.eatenAt) break;
                        if (coll >= 0) {
                            if (sf.eatenAt < 0 || coll < sf.eatenAt) {
                                sf.eatenAt = coll;
                            }
                        }
                        smaller.remove(t);
                        t--;
                    }
                }
            }
        }
 
        fishesLeft = new ArrayList<Fish>();
        for (Fish fish : fishes) {
            //System.out.println("Fish " + fish.index + " eaten at " + fish.eatenAt);
            if (fish.eatenAt < 0 || fish.x - fish.eatenAt * fish.speed < 0) {
                fishesLeft.add(fish);
            }
        }
        //io.println("Fishes left: " + fishesLeft.size());
 
        Collections.sort(fishesLeft, new FishTimeSort());
 
        memo = new int[h][fishesLeft.size()];
        int best = 0;
        if (fishesLeft.size() > 0) {
            for (int i = 4; i <= h - 3; i++) {
                best = Math.max(best, calcBest(i, 0));
            }
        }
 
        io.println(best);
 
        io.close();
    }
 
    private static int memo[][];
 
    private static int calcBest(int y, int cur) {
        if (memo[y][cur] > 0) return memo[y][cur] - 2;
 
        Fish fish = fishesLeft.get(cur);
        boolean overlap = Math.abs(y - fish.y) <= 3 + fish.height / 2;
        int score = 0;
        if (overlap) {
            if (fish.size == 2) return -1;
            if (fish.size == 0) score = 10;
            if (fish.size == 1) score = 20;
        }
        int next = 0;
        if (cur + 1 < fishesLeft.size()) {
            long delta = fishesLeft.get(cur+1).time - fish.time;
            if (delta > h) delta = h;
            int miny = (int) Math.max(4, y - delta);
            int maxy = (int) Math.min(h-3, y + delta);
            for (int i = miny; i <= maxy; i++) {
                next = Math.max(next, calcBest(i, cur+1));
            }
        }
        if (next < 0) {
            score = -1;
        } else {
            score += next;
        }
 
        memo[y][cur] = score + 2;
 
        return score;
    }
}
