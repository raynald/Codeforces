fun main(args: Array<String>) {
    val n = readLine()!!.toInt()
    var x: HashSet<Int> = hashSetOf()
    for (i in 0 until n) {
        val a = readLine()!!.split(" ").map{it.toInt()}
        if (x.isEmpty()) x = a.subList(1, a.size).toHashSet()
        else x = x.intersect(a.subList(1, a.size)).toHashSet()
    }
    println(x.map {it.toString()}.joinToString(" "))
}
