# [Extra Long Factorials](https://www.hackerrank.com/challenges/extra-long-factorials/problem)

* C++
```c++
void extraLongFactorials(int n) {
    vector<int> d;
    d.push_back(1);

    for (int i = 2; i <= n; ++i) {
        for (auto it = d.begin(); it != d.end(); ++it)
            *it *= i;

        for (size_t j = 0; j < d.size(); ++j) {
            if (d[j] < 10)
                continue;

            if (j == d.size() - 1)
                d.push_back(0);

            d[j + 1] += d[j] / 10;
            d[j] %= 10;
        }
    }

    for (auto it = d.rbegin(); it != d.rend(); ++it)
        cout << *it;
}
```

#### `rbegin(), rend()` 란?
![image](https://user-images.githubusercontent.com/29828988/112166563-16e10b00-8c33-11eb-86af-021cd8f08bb1.png)


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

# BigInteger
