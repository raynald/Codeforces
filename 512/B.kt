fun main(args: Array<String>) {
    var (n, d) = readLine()!!.split(" ").map { it.toInt() }
    var m = readLine()!!.toInt()
    for (i in 0 until m) {
        var (p, q) = readLine()!!.split(" ").map { it.toInt() }
        if ((p - q) * (p - q) > d * d || (p - n + q) * (p - n + q) > (n - d) * (n - d)) {
            println("NO")
        } else {
            println("YES")
        }
    }
}

