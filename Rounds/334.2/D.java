/*
 * k = 0, f(0) = 0, p^(p-1)
 * k = 1, p^p
 * k = 2, p
 *  p = 3, f(2x mod 3) = 2f(x) mod 3, 
 *      f(1) = 1, f(2) = 2
 *      f(2) = 2, f(1) = 1
 *  p = 5, f(2x mod 5) = 2f(x) mod 5,
 *      f(1) = 1, f(2) = 2, f(3) = 3, f(4) = 4
 *      f(1) = 2, f(2) = ...
 * k = 3, p
 *  p = 5, f(3x mod 5) = 3f(x) mod 5,
 *      f(1) = 1, f(3) = 3, f(
 * k = 4, p*p
 *  p = 5, f(4x mod 5) = 4f(x) mod 5,
 *     f(1) = 1, f(4) = 4  f(2) = 1, f(3) =  , 
 *  p = 7, f(4x mod 7) = 4f(x) mod 7,
 *     f(1),f(4),f(2),   f(3)f(5)
 *
 * k = 5, p
 * k = 6, 1,6  2,5 3,4
 * /
 */
import java.util.Scanner;
import java.util.Arrays;
import static java.lang.Math.toIntExact;

public class D {
    private static class mergeSet {
        private int set_size;
        private int[] parent;

        mergeSet(int size) {
            set_size = size;
            parent = new int[size];
            Arrays.fill(parent, -1);
        }

        int find(int x) {
            if(parent[x] < 0) return x; else return find(parent[x]);
        }

        void merge(int x, int y) {
            int p = find(x);
            int q = find(y);
            if (p == q) {
                return;
            }
            parent[q] += parent[p];
            parent[p] = q; 
        }

        int count() {
            int ans=0;
            for(int i=1;i<set_size;i++) {
                if(parent[i]<0) ans ++;
            }
            return ans;
        }
    }

    public static void main(String[] args) {
        Scanner scanIn = new Scanner(System.in);
        int p = scanIn.nextInt();
        int k = scanIn.nextInt();
        int cluster;
        if (k <= 1) {
            cluster = p - 1 + k;
        } else {
            mergeSet m = new mergeSet(p);
            for(int i = 1;i < p;i ++) {
                long temp = i;
                temp *= k;
                temp %= p;
                m.merge(i, toIntExact(temp));
            }
            cluster = m.count();
        }
        long ans = p;
        final int MOD = 1000000007;
        for(int i=1;i<cluster;i++) {
            ans = (ans * p) % MOD;
        }
        System.out.println(ans);
    }
}

