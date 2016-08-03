#goroutine ==> go

能够被称为表达式语句的调用表达式是我们创建go语句时唯一可以合法使用的表达式。

```
func test() {
    go fmt.Println("Go goroutine") //此时不会打印
}

func test() {
    go fmt.Println("Go goroutine") //此时不一定会打印，关键在于调度器 
    time.Sleep(time.Millisecond)
}

//保险的方式,但是在go1.5版本中，并没有打印
func test() {
    go fmt.Println("Go goroutine")
    runtime.Gosched()
}
```