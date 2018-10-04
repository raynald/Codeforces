fun main(args: Array<String>) {
    val n = readLine()
    val x = if (n!!.length > 1) "9".repeat(n.length - 1) else "0"
    val y = (n.toBigInteger() - x.toBigInteger()).toString()
    println(x.map {it -> it.toString().toInt()}.reduce {s, sum -> s + sum}
            + y.map {it -> it.toString().toInt()}.reduce {s, sum -> s + sum})
}
