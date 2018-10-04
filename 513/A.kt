fun main(args: Array<String>) {
    var n = readLine()!!.toInt()
    var digits = readLine()!!.count {it == '8'}
    println(minOf(n / 11, digits))
}
