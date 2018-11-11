fun check(): Boolean {
    val (n, s) = readLine()!!.split(" ").map{it.toInt()}
    val a = readLine()!!.split(" ").map{it.toInt()}
    val b = readLine()!!.split(" ").map{it.toInt()}
    if (a[0] == 0) return false
    if (a[s - 1] == 1) return true
    if (b[s - 1] == 0) return false
    for (i in s until n) {
        if (a[i] == 1 && b[i] == 1) return true
    }
    return false
}

fun main(args: Array<String>) {
    if (check()) println("YES") else println("NO")
}
