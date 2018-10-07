fun check(a: Int, b: Int, c: Int): Boolean {
    return (a < c && b < c) || (a > c && b > c)
}

fun main(args: Array<String>) {
    readLine()
    val (ax, ay) = readLine()!!.split(" ").map{it.toInt()}
    val (bx, by) = readLine()!!.split(" ").map{it.toInt()}
    val (cx, cy) = readLine()!!.split(" ").map{it.toInt()}
    if (check(bx, cx, ax) && check(by, cy, ay)) println("YES") else println("NO")
}
