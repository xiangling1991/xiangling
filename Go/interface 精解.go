//interface:
//简单讲，就是一组method的组合，通过interface来定义对象的一组行为

//a、interface可以被任意对象实现，一个类型/对象也可以实现多个interface
//b、方法不能重载，如eat() eat(s string )不能同时存在

//interface 值
//  声明为 interface 类型的变量，可以存储任何实现了 interface 中所有方法的类型的变量(对象)
//  注：类的值类型传递方法会自动生成对应的引用类型传递方法，反之不成立

//interface 组合
//  将一个 interface1 嵌入到另一个 interface2 的声明中
//  其作用相当于把 interface1 的函数包含到 interface2 中，但是组合中不同有重复的方法
//  注：
//  a.只要两个接口中的方法列表相同，(与顺序无关)，即为相同的接口，可以相互赋值
//  b. interface1 的方法列表属于另一个 interface2 的方法列表的子集，interface2 可以赋值给 interface1，反之不成立(因为方法缺失)，interface2 中的方法会覆盖 interface1 中同名的方法
//  c. 可以嵌入包中的 interface

//  空接口
//  空接口，无方法，即interface{},可以代表任何类型，有点类似与
// Java中的Object类。
// 可以作为任何形参和返回类型

//Interface就像鸭子类型，无论你是什么类，只要实现了interface中的方法，该interface就可以被看做是这个类的对象

 package main

import "fmt"

type Person1 struct {
	name string
	age int
}

func (p Person1) printMsg() {
	fmt.Printf("I'm %s, and my age is %d\n", p.name, p.age)
}

func (p Person1) eat(s string) {
	fmt.Printf("%s is eating %s...\n",p.name, s)
}

func (p Person1) drink(s string) {
	fmt.Printf("%s is driking %s...\n",p.name, s)
}

type Person2 interface {
	printMsg()
	eat()
	drink()
}

type PeopleDrink interface {
	drink(s string)
}

type PeopleEat interface {
	eat(s string)
}

type PeopleEatDrink interface {
	eat(s string)
	drink(s string)
}

type Foodie struct {
	name string
}

func (f Foodie) eat(s string) {
	fmt.Printf("I'm Foodie %s, I'd like eat %s\n", f.name, s)
}

func main() {
	var p1 PeopleDrink
	p1 = Person1{"f", 4}
	if p2, ok := p1.(Person1); ok {
		p2.drink("o")
		fmt.Println(ok)
	}
}
