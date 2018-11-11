fun gcd(x: Int, y: Int): Int {
    if (x < y) return gcd(y, x)
    if (x % y == 0) return y
    return gcd(y, x % y)
}

fun main(args: Array<String>) {
    var (l, r, t) = readLine()!!.split(" ").map { it.toInt() }
    var (l2, r2, t2) = readLine()!!.split(" ").map { it.toInt() }
    val g = gcd(t, t2)
    if (g == 1) {
        println(minOf(r - l + 1, r2 - l2 + 1))
    } else {
        var ans = 0
        if (l < l2) {
            var temp = (l2 - l) / g * g
            l += temp
            r += temp
            ans = maxOf(ans, minOf(r, r2) - maxOf(l, l2) + 1)
            l += g
            r += g
            ans = maxOf(ans, minOf(r, r2) - maxOf(l, l2) + 1)
        } else {
            var temp = (l - l2) / g * g
            l2 += temp
            r2 += temp
            ans = maxOf(ans, minOf(r, r2) - maxOf(l, l2) + 1)
            l2 += g
            r2 += g
            ans = maxOf(ans, minOf(r, r2) - maxOf(l, l2) + 1)
        }
        println(ans)
    }
}