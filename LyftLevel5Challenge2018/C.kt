fun main(args: Array<String>) {
    val n = readLine()!!.toInt()
    val list = readLine()!!.split(" ").map {it.toInt()}
    val wei: Array<Int> = Array<Int>(n + 1) { 0 }
    for ((index, item) in list.withIndex()) {
        wei[item] = index
    }
    val m: Array<Boolean> = Array(n + 1) { false }
    val s: MutableSet<Int> = mutableSetOf(wei[n])
    for (i in n - 1 downTo 1) {
        for(j in 1..(n - wei[i])/ i) {
            if (s.contains(wei[i] + j * i)) {
                m[i] = true
                break
            }
        }
        if (!m[i]) {
            for(j in 1..wei[i]/ i) {
                if (s.contains(wei[i] - j * i)) {
                    m[i] = true
                    break
                }
            }
        }
        if (!m[i]) {
            s.add(wei[i])
        }
    }
    println(list.map{if (m[it]) "A" else "B"}.joinToString(""))
}
