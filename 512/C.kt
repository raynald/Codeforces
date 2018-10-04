fun main(args: Array<String>) {
    var n = readLine()!!.toInt()
    var str = readLine()
    var sum = 0
    for (ch in str!!) {
        sum += ch.toString().toInt()
    }
    var t = 0
    var flag = true
    for (i in 1 .. sum / 2) {
        t = 0
        flag = true
        for (ch in str) {
            t += ch.toString().toInt()
            when {
                t > i -> flag = false
                t == i -> t = 0
            }
            if (!flag) {
                break
            }
        }
        if (flag && t == 0) break
    }
    if (flag && t == 0 && sum != 1) println("YES") else println("NO")
}

