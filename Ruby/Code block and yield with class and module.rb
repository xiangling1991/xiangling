代码块是没有名字的函数，它可以作为参数传递给函数或方法，比如
>>2.times {puts 'Hiya there, kiddo'} 
=>Hiya there, kiddo
  Hiya there, kiddo
大括号之间的代码就是代码块，times是Fixnum类的方法，它会执行n次x，其中x是代码块，n是Fixnum对象的值可以采用{/}或do/end方式界定代码块。使用惯例为：
代码只占一行，使用大括号，占多行时使用do/end，代码块可以带1个或多个参数：
eg:
	>>animals = ['lions and', 'tigers and', 'bears', 'oh my']
	=>["lions and ", "tigers and", "bears", "oh my"]
	>>animals.each {|a| puts a}
	lions and
	tigers and
	bears 
	oh my

可将代码块作为参数直接传递给函数，而无需包装在其他结构中传递，在Ruby中，参数名前加一个"&"，表示将代码块作为闭包传递给函数，比如：
def call_block(&block)
  block.call
end

def pass_block(&block)
  call_block(&block)
end

pass_block {puts 'hello'}


在Ruby中，所有的事物，都继承自Object类，但Object基础子BasicObject类，
一个class同时也是一个Module。class的实例将作为对象的模板，比如Fixnum
是Class的一个实例，而数字4是Fixnum的一个实例。每一个类同时也是一个对象。
eg：
	>>4.class.class
	=>Class
	>>4.class.class.superclass
	=>Module
	>>4.class.class.superclass.superclass
	=>Object

	----------
	| Object |
	----------
		/\
		||
	----------
	| Module |
	----------
		/\
		||
	----------		------------
	| Class   | <== |  Numeric |       
	----------		------------
						 /\
						 ||
					------------
					|  Integer |
					------------
						 /\
						 ||
					------------	  -------------
					|  Fixnum  |  <== |     4	  |
					------------	  -------------

class实例：

	class Tree
  attr_accessor :children, :node_name

  def initialize(name, children = [])
    @children = children
    @node_name = name
  end

  def visit_all(&block)
    visit &block
    children.each {|c| c.visit_all &block}
  end

  def visit(&block)
    block.call self
  end
end

ruby_tree = Tree.new('Ruby',
  [Tree.new('Reia'),
  Tree.new('MacRuby')])

puts "visiting a node"
ruby_tree.visit {|node| puts node.node_name}
puts

puts "visiting entire tree"
ruby_tree.visit_all {|node| puts node.node_name}

在这棵树的类中，initialize方法在初始化一个对象的时候调用。
在调用new时，其中的参数和initialize中的参数需要保持一致，以为在
new中的参数最终将送到initialize对应的参数中。
类设计的惯例和规则：
	1、类应以大写字母开头，并且一般采用驼峰命名法。
	2、实例变量（一个对象有一个值）前必须加上@，而类变量（一个类有一个值）
		前必须加上@@。
	3、实例变量和方法名以小写字母开头，并采用下划线命名法。
	4、常量采用全大写形式。
	5、用于逻辑测试的函数和方法一般要加上问好，如if test?
attr关键字可用来定义实例变量，常用的有attr和attr_accessor
attr定义实例变量和访问变量的同名方法，而attr_accessor定义实例变量访问方法
和设置方法。


混入功能(mix in)：
module ToFile
  def filename
    "object_#{self.object_id}.txt"
  end

  def to_f
    File.open(filename, 'w') {|f| f.write(to_s)}
  end
end

class Person
  include ToFile
  attr_accessor :name
  def initialize(name)
    @name = name
  end

  def to_s
    name
  end
end

Person.new('matz').to_f

在模块中定义两个方法：to_f方法把to_s方法的输出写入文件，filename方法
提供了写入文件的文件名。有趣的是：to_s在模块中使用，在类中实现，但定义
模块的时候，实现它的类甚至还没有定义！说明模块与包含它的类之间，是以一种
相当隐秘的方式相互作用的。模块依赖的类方法通常不多。通过鸭子类型来实现的。
此有一致的基本前提：使用单一继承结合mixin的方式，尽可能合理地把各种行为
打包到一起。

模块、可枚举、集合：

	两个重要的mixin：枚举(enumerable)和比较(comparable)。
	1、如果需要使用枚举，需要实现each方法；
	2、如果需要使用比较，需要实现<=>操作符，<=>被称为太空船操作符，
		a > b 返回 1， a < b 返回 -1, a = b ,返回 0
在集合中已经实现了该些方法：
eg:
	>>'begin'<=>'end'
	=>false
	>>'same'<=>'same'
	=>true
	>>a = [5, 3, 4, 1]
	>>a.any?{|i| i > 6}
	=>false
	>>a.any?{|i| i > 4}
	=>true
	>>a.all?{|i| i > 4}
	=>false
	>>a.collect{|i| i * 2}  #这里并未改变a的值，可以赋值给b
	=>[10, 6, 8, 2]
	>>a.select{|i| i % 2 == 0} #even
	=>[4]
	>>a.max
	=>5
	>>a.inject(0) {|sum, i| sum + i} #参数0表示在求玩和之后加上/乘上...该数
	=>13
	>>a.inject {|sum, i| sum + i}
	=>13
	>>a.inject {|product, i| product * i}
	=>60 


array.each_slice(4).map{|i| i.join" "}#4表示4个数据为一个slice
array.each_slice(4){|i| p i} #此处必须为p可生成4个数据为一组的若干数组。
