import java.util.Scanner;

public class Solution {
    static final int MAXN = 100010;

    public static void main(String[] args) {
        Scanner scanIn = new Scanner(System.in);
        int n;
        int[] a = new int[MAXN];
        int[][] map = new int[2][2];

        n = scanIn.nextInt();
        for (int i = 0;i < n;i ++) {
            a[i] = scanIn.nextInt();
        }
        int i = 0, j = 1;
        int ans = 0;
        map[1][0] = -1; map[1][1] = -1;
        map[0][0] = a[i]; map[0][1] = 0;
        while (i < n && j < n) {
            while (j < n) {
                if (map[0][0] > -1 && Math.abs(a[j] - map[0][0]) > 1) break;
                if (map[1][0] > -1 && Math.abs(a[j] - map[1][0]) > 1) break;
                if(map[0][0] == a[j]) {
                    map[0][1] = j;
                } else if (map[1][0] == a[j]) {
                    map[1][1] = j;
                } else {
                    if(map[0][0] == -1) {
                        map[0][0] = a[j];
                        map[0][1] = j;
                    } else {
                        map[1][0] = a[j];
                        map[1][1] = j;
                    }
                }
                j ++;
            }
            if (j - i > ans) ans = j - i;
            if(map[0][0] > -1 && Math.abs(map[0][0] - a[j]) > 1) {
                i = Math.max(map[0][1] + 1, i);
                map[0][0] = -1;
            }
            if(map[1][0] > -1 && Math.abs(map[1][0] - a[j]) > 1) {
                i = Math.max(map[1][1] + 1, i);
                map[1][0] = -1;
            }
        }
        System.out.println(ans);
    }
}
