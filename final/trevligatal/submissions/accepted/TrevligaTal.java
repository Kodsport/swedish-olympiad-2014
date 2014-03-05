import java.io.*;
 
public class TrevligaTal {
        
        public static void main(String[] args) throws IOException {
                int[] d = {1, 0, 0};
                for (char c : new BufferedReader(new InputStreamReader(System.in)).readLine().toCharArray()) {
                        int s = (3 - (c-'0')%3)%3;
                        int[] d2 = {0, 0, 0};
                        for (int i = 0; i < 3; i++) {
                                d2[i] = (d[i] + d[(i+s)%3]) % 1000000007;
                        }
                        d = d2;
                }
                System.out.println(d[0]);
        }
}
 
