fun main(args: Array<String>) {
    val n = readLine()!!.toInt()
    if (n == 1) {
        println(1)
    } else {
        val p = readLine()!!.split(" ").map { it.toInt() }
        val count: IntArray = IntArray(n) { 0 }
        for (i in p.size - 1 downTo 0) {
            if (count[i + 1] == 0) {
                count[i + 1]++
            }
            count[p[i] - 1] += count[i + 1]
        }
        println(count.sorted().map { it.toString() }.joinToString(" "))
    }
}

