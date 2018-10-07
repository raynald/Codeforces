var matrix: Array<CharArray> = arrayOf()
var bit: Array<BooleanArray> = arrayOf()
var n = 0
var m = 0
val circle = arrayOf(
        Pair(0, 0),
        Pair(0, 1),
        Pair(0, 2),
        Pair(1, 2),
        Pair(2, 2),
        Pair(2, 1),
        Pair(2, 0),
        Pair(1, 0)
)


fun check(i: Int, j: Int, k: Int): Boolean {
    val x = circle[k].first
    val y = circle[k].second
    for (l in 0..7) {
        val new_x = i + circle[l].first - x
        val new_y = j + circle[l].second - y
        if (new_x in 0 until n && new_y in 0 until m && matrix[new_x][new_y] == '#') {
        } else return false
    }
    return true
}

fun find(): Boolean {
    val twoInt = readLine()!!.split(" ").map { it.toInt() }
    n = twoInt[0]
    m = twoInt[1]
    bit = Array(n) { _ -> BooleanArray(m) { false } }
    for (i in 0 until n) {
        matrix += readLine()!!.toCharArray()
    }
    for (i in 0 until n) {
        for (j in 0 until m) {
            if (matrix[i][j] == '#' && !bit[i][j]) {
                var flag = false
                for (k in 0..7) {
                    if (check(i, j, k)) {
                        bit[i][j] = true
                        flag = true
                        break
                    }
                }
                if (!flag) return false
            }
        }
    }
    return true
}

fun main(args: Array<String>) {
    println(if (find()) "YES" else "NO")
}

