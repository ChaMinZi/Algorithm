# [Extra Long Factorials](https://www.hackerrank.com/challenges/extra-long-factorials/problem)

* C++
```c++
```

* kotlin
```kotlin
...
fun extraLongFactorials(n: Int): Unit {
    var a = BigInteger("1")
    var b = BigInteger("1")
    
    for (i in 2..n) {
        a = b.multiply(i.toString().toBigInteger())    
        b = a    
    }
    
    println(a)
}

fun main(args: Array<String>) {
    val scan = Scanner(System.`in`)

    val n = scan.nextLine().trim().toInt()

    extraLongFactorials(n)
}

```
