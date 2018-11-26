import java.util.*

fun main(args: Array<String>) {
    val (n, m) = readLine()!!.split(" ").map{it.toInt()}
    val p = readLine()!!.split(" ").map{it.toInt()}
    val map: HashMap<Int, Int> = hashMapOf()
    val v: BooleanArray = BooleanArray(2 * n) { false }
    for (i in 0 until m) {
        val (a, b) = readLine()!!.split(" ").map{it.toInt()}
        map.put(a - 1, b - 1)
        map.put(b - 1, a - 1)
    }
    val t: Int = readLine()!!.toInt()
    for (i in 0 until n) {
        if (t == 1) {
            var min = 0
            var mini = 0
            if (map.isNotEmpty()) {
                for (k in map.keys) {
                    if (p[k] > min) {
                        min = p[k]
                        mini = k
                    }
                }
                val b = map.getOrDefault(mini, 0)
                map.remove(b)
                map.remove(mini)
            } else {
                for (j in 0 until 2 * n) {
                    if (!v[j]) {
                        if (p[j] > min){
                            min = p[j]
                            mini = j
                        }
                    }
                }
            }
            v[mini] = true
            println(mini + 1)
            System.out.flush()
            val temp = readLine()!!.toInt()
            v[temp - 1] = true
        } else {
            val com = readLine()!!.toInt()
            v[com - 1] = true
            var mini = 0
            var min = 0
            if (map.containsKey(com - 1)) {
                mini = map.getOrDefault(com - 1, 0)
                map.remove(com - 1)
                map.remove(mini)
            } else {
                if (map.isNotEmpty()) {
                    for (k in map.keys) {
                        if (p[k] > min) {
                            min = p[k]
                            mini = k
                        }
                    }
                    val b = map.getOrDefault(mini, 0)
                    map.remove(b)
                    map.remove(mini)
                } else {
                    for (j in 0 until 2 * n) {
                        if (!v[j]) {
                            if (p[j] > min) {
                                min = p[j]
                                mini = j
                            }
                        }
                    }
                }
            }
            v[mini] = true
            println(mini + 1)
            System.out.flush()
        }
    }
}