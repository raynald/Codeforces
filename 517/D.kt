import java.util.*

fun main(args: Array<String>) {
    val sc = Scanner(System.`in`)
    val (n, k) = sc.nextLine().split(" ").map {it.toInt()}
    val mat = Array(n) {_ -> CharArray(n) }
    val left = Array(n) {_ -> IntArray(n) { -1 }}
    for (i in 0 until n) {
        mat[i] = sc.nextLine().toCharArray()
    }
    left[0][0] = k
    var max = -1
    var stack = MutableList<IntArray>(n * 2) { intArrayOf(0, 0)}
    var count = 0
    for(step in 0..2 * n - 2) {
        var flag = false
        for (i in maxOf(0, step - n + 1)..minOf(step, n - 1)) {
            val j = step - i
            if (i > 0) left[i][j] = maxOf(left[i][j], left[i - 1][j])
            if (j > 0) left[i][j] = maxOf(left[i][j], left[i][j - 1])
            if (mat[i][j] != 'a') left[i][j] --
            if (left[i][j] >= 0) {
                max = maxOf(max, i + j)
                flag = true
            }
        }
        if (!flag) break
    }
    if (max == -1) {
        stack[count ++] = intArrayOf(0, 0)
        print(mat[0][0])
    } else {
        for(i in maxOf(0, max - n + 1).. minOf(max, n - 1)) {
            val j = max - i
            if (left[i][j] >= 0) {
                stack[count ++] = intArrayOf(i, j)
            }
        }
        print("a".repeat(max + 1))
    }
    while (count > 0) {
        var countNew = 0
        val q = MutableList(n * 2) { intArrayOf(0, 0) }
        var comp = '#'
        for(st in 0 until count) {
            val (x, y) = stack[st]
            if (x < n - 1) {
                if (comp == '#' || mat[x + 1][y] < comp) {
                    countNew = 0
                    q[countNew ++] = intArrayOf(x + 1, y)
                    comp = mat[x + 1][y]
                    left[x + 1][y] = 0
                } else if (mat[x + 1][y] == comp) {
                    if (left[x + 1][y] != 0) q[countNew++] = intArrayOf(x + 1, y)
                }
            }
            if (y < n - 1) {
                if (comp == '#' || mat[x][y + 1] < comp) {
                    countNew = 0
                    q[countNew ++] = intArrayOf(x, y + 1)
                    comp = mat[x][y + 1]
                    left[x][y + 1] = 0
                } else if (mat[x][y + 1] == comp) {
                    if (left[x][y + 1] != 0) q[countNew ++] = intArrayOf(x, y + 1)
                }
            }
        }
        if (comp != '#') print(comp)
        count = countNew
        stack = q
    }
    println()
}