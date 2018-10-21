fun main(args: Array<String>) {
    var (w, h, k) = readLine()!!.split(" ").map {it -> it.toInt()}
    var ans = 0
    for (i in 1..k) {
        ans += (w + h) * 2 - 4
        w -= 4
        h -= 4
    }
    println(ans)
}
