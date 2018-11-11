fun main(args: Array<String>) {
    val (n, m, l) = readLine()!!.split(" ").map {it.toInt()}
    val hair = readLine()!!.split(" ").map {it.toLong()}.toMutableList()
    val map: HashMap<Int, Int> = hashMapOf()
    val reverseMap: HashMap<Int, Int> = hashMapOf()

    var start = -1
    for (i in 0 until n) {
        if (hair[i] > l) {
            if (start == -1) start = i
        } else {
            if (start != -1) {
                map.put(start, i - 1)
                reverseMap.put(i - 1, start)
                start = -1
            }
        }
    }
    if (start != -1) {
        map.put(start, n - 1)
        reverseMap.put(n - 1, start)
    }
    for (i in 0 until m) {
        val t = readLine()!!
        if (t[0] == '0') {
            println(map.size)
        } else {
            val (_, b, c) = t.split(" ").map {it.toInt()}
            if (hair[b - 1] > l) continue
            hair[b - 1] = hair[b - 1] +  c
            if (hair[b - 1] > l) {
                // b - 1, b - 1
                var x = -1
                if (reverseMap.containsKey(b - 2)) {
                    x = reverseMap[b - 2]!!
                    // [x, b - 1]
                    map.remove(x)
                    reverseMap.remove(b - 1)
                }
                var y = -1
                if (map.containsKey(b)) {
                    y = map[b]!!
                    // b - 1, y
                    map.remove(b)
                    reverseMap.remove(y)
                }
                when {
                    x >= 0 && y >= 0 -> {
                        map.put(x, y)
                        reverseMap.put(y, x)
                    }
                    x < 0 && y >= 0 -> {
                        map.put(b - 1, y)
                        reverseMap.put(y, b - 1)
                    }
                    x >= 0 && y < 0 -> {
                        map.put(x, b - 1)
                        reverseMap.put(b - 1, x)
                    }
                    else -> {
                        map.put(b - 1, b - 1)
                        reverseMap.put(b - 1, b - 1)
                    }
                }
            }
        }
    }
}