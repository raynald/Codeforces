class Solution {
    var n = 0

    fun read() {
        n = readLine()!!.toInt()
    }

    fun get(x: Int): IntArray {
        when (x) {
            1 -> return intArrayOf(1)
            2 -> return intArrayOf(1, 2)
            3 -> return intArrayOf(1, 1, 3)
            else -> return IntArray((x + 1) / 2) { 1 } + get(x / 2).map { 2 * it }
        }
    }

    fun output() {
        println(get(n).joinToString(" "))
    }
}

fun main(args: Array<String>) {
    val t = Solution()
    t.read()
    t.output()
}

