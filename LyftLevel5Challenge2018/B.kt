fun check(a: Long, b: Long): Boolean {
    if (a - b > 1) return false
    val res = a + b
    for (i in 2..Math.sqrt(res.toDouble()).toInt()) {
        if (res % i == 0L) {
            return false
        }
    }
    return true
}

fun main(args: Array<String>) {
    val t = readLine()!!.toInt()
    for (test in 0 until t) {
        val (a, b) = readLine()!!.split(" ").map{it.toLong()}
        if (check(a, b)) println("YES") else println("NO")
    }
}
