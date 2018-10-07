fun main(args: Array<String>) {
    val (n, L, a) = readLine()!!.split(" ").map {it.toInt() }
    var time = 0
    var ans = 0
    for (i in 1 .. n) {
        val (t, l) = readLine()!!.split(" ").map {it.toInt()}
        ans += (t - time) / a
        time = t + l
    }
    ans += (L - time) / a
    println(ans)
}

