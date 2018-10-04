fun main(args: Array<String>) {
    var n = readLine()
    var l = readLine()!!.split(" ").count { it == "0" }
    println(if (l == n!!.toInt()) "EASY" else "HARD")
}
