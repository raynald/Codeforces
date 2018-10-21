import kotlin.math.sqrt

fun main(args: Array<String>) {
    val (a, b) = readLine()!!.split(" ").map{it.toLong()}
    var x = (sqrt(2.0 * (a + b)) - 1).toLong()
    while ((x + 2) * (x + 1)/ 2 <= a + b) x ++
    val l = hashSetOf<Long>()
    if ( a <= b ) {
        var n = b
        for (i in x downTo 1) {
            if (n < i) break
            n -= i
            l.add(i)
        }
        if (n != 0L) l.add(n)
        val al = (1..x).filter {!l.contains(it)}
        println(al.size)
        println(al.joinToString(" ") { it.toString() })
        println(l.size)
        println(l.joinToString(" ") { it.toString() })
    } else {
        var n = a
        for (i in x downTo 1) {
            if (n < i) break
            n -= i
            l.add(i)
        }
        if (n != 0L) l.add(n)
        val bl = (1..x).filter {!l.contains(it)}
        println(l.size)
        println(l.joinToString(" ") { it.toString() })
        println(bl.size)
        println(bl.joinToString(" ") { it.toString() })
    }
}

