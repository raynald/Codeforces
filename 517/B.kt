fun convert(x: IntArray): List<IntArray> {
    return when {
        x[0] == 0 && x[1] == 0 -> listOf(intArrayOf(0, 0))
        x[0] == 1 && x[1] == 0 -> listOf(intArrayOf(1, 0), intArrayOf(0, 1))
        x[0] == 1 && x[1] == 1 -> listOf(intArrayOf(1, 1))
        x[0] == 2 && x[1] == 0 -> listOf(intArrayOf(2, 0), intArrayOf(0, 2))
        x[0] == 2 && x[1] == 2 -> listOf(intArrayOf(2, 2))
        x[0] == 3 && x[1] == 0 -> listOf(intArrayOf(3, 0), intArrayOf(2, 1),
                intArrayOf(0, 3), intArrayOf(1, 2))
        x[0] == 3 && x[1] == 1 -> listOf(intArrayOf(3, 1), intArrayOf(1, 3))
        x[0] == 3 && x[1] == 2 -> listOf(intArrayOf(3, 2), intArrayOf(2, 3))
        x[0] == 3 && x[1] == 3 -> listOf(intArrayOf(3, 3))
        else -> listOf()
    }
}

fun main(args: Array<String>) {
    val n = readLine()!!.toInt()
    val a = readLine()!!.split(" ").map {it.toInt()}
    val b = readLine()!!.split(" ").map {it.toInt()}
    val x = convert(intArrayOf(a[0], b[0]))
    val ans = mutableListOf<Int>()
    for (i in x) {
        ans.clear()
        ans.add(i[0])
        ans.add(i[1])
        var u = i[1]
        for (j in 1..n - 2) {
            val t = convert(intArrayOf(a[j], b[j]))
            var found = false
            for (k in t) {
               if (k[0] == u) {
                   found = true
                   u = k[1]
                   ans.add(u)
                   break
               }
            }
            if (!found) break
        }
        if (ans.size == n) {
            println("YES")
            println(ans.joinToString(" ") { it.toString() })
            break
        }
    }
    if (ans.size != n) println("NO")
}
