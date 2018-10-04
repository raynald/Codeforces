fun getMap(a: List<Int>): IntArray {
    var aMap = IntArray(a.size) { Int.MAX_VALUE }
    for (i in a.indices) {
        var s = a[i]
        var c = 0
        aMap[c] = minOf(aMap[c], s)
        for (j in i + 1..a.size - 1) {
            s += a[j]
            ++ c
            aMap[c] = minOf(aMap[c], s)
        }
    }
    return aMap
}

fun main(args: Array<String>) {
    readLine()
    val a = readLine()!!.split(" ").map {it -> it.toInt()}
    val b = readLine()!!.split(" ").map {it -> it.toInt()}
    val x = readLine()!!.toInt()
    val aMap: IntArray = getMap(a)
    val bMap: IntArray = getMap(b)
    var ans = 0
    for (i in a.indices) {
        if (aMap[i] > x) break
        for (j in b.indices) {
            if (aMap[i].toLong() * bMap[j].toLong() > x.toLong()) break
            ans = maxOf(ans, (i + 1) * (j + 1))
        }
    }
    println(ans)
}

