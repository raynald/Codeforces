package main

import (
    "fmt"
    "math"
)

func main() {
    var n int
    var a int
    var ans int = -1000001
    var x int
    fmt.Scan(&n)
    for i := 0; i < n;i ++ {
        fmt.Scan(&a);
        if a < 0 {
            if a > ans {
                ans = a
            }
        } else {
            x = int(math.Sqrt(float64(a)))
            if x * x != a {
                if a > ans {
                    ans = a
                }
            }
        }
    }
    fmt.Println(ans)
}
