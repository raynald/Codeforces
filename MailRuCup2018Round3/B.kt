fun main(args: Array<String>) {
    val (n, m) = readLine()!!.split(" ").map { it.toInt() }
    var ans = 0L
    for (i in 0 until m) {
        for (j in 0 until m) {
            if ((i * i + j * j) % m == 0) {
                val x = when {
                    i == 0 -> n / m
                    n >= i -> ((n - i) / m) + 1
                    else -> 0
                }
                val y = when {
                    j == 0 -> n / m
                    n >= j -> ((n - j) / m) + 1
                    else -> 0
                }
                ans += x.toLong() * y
            }
        }
    }
    println(ans)
}