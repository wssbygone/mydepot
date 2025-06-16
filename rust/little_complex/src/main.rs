// use num::complex::Complex;
// use std::convert::TryInto;
#![allow(unused)]

use std::env;
fn main() {
    let args: Vec<String> = env::args().collect();
    dbg!(args);
}

/*
fn main() {
    //-----------------------------------
    // 以下全部输出 "Hello x    !"
    // 为"x"后面填充空格，补齐宽度5
    println!("Hello {:5}!", "x");
    // 使用参数5来指定宽度
    println!("Hello {:1$}!", "x", 5);
    // 使用x作为占位符输出内容，同时使用5作为宽度
    println!("Hello {1:0$}!", 5, 'x');
    // 使用有名称的参数作为宽度
    println!("Hello {:width$}!", "x", width = 5);
    //-----------------------------------

    // 使用参数5为参数x指定宽度，同时在结尾输出参数5 => Hello x    !5
    println!("Hello {:1$}!{}", "x", 5);
}
*/

/*
use std::{slice::from_raw_parts, str::from_utf8_unchecked};

fn get_memory_location() -> (usize, usize) {
  // “Hello World” 是字符串字面量，因此它的生命周期是 `'static`.
  // 但持有它的变量 `string` 的生命周期就不一样了，它完全取决于变量作用域，对于该例子来说，也就是当前的函数范围
  let string = "Hello World!";
  let pointer = string.as_ptr() as usize;
  let length = string.len();
  (pointer, length)
  // `string` 在这里被 drop 释放
  // 虽然变量被释放，无法再被访问，但是数据依然还会继续存活
}

fn get_str_at_location(pointer: usize, length: usize) -> &'static str {
  // 使用裸指针需要 `unsafe{}` 语句块
  unsafe { from_utf8_unchecked(from_raw_parts(pointer as *const u8, length)) }
}

fn main() {
  let (pointer, length) = get_memory_location();
  let message = get_str_at_location(pointer, length);
  println!(
    "The {} bytes at 0x{:X} stored: {}",
    length, pointer, message
  );
  // 如果大家想知道为何处理裸指针需要 `unsafe`，可以试着反注释以下代码
  //let message = get_str_at_location(1000, 10);
}
*/

/*
fn main() {
    use std::collections::HashMap;
    let mut map: HashMap<&str, u32> = HashMap::new();
    map.entry("poneyland").or_insert(3);
    assert_eq!(map["poneyland"], 3);

    let count = map.entry("poneyland").or_insert(10);
    *count *= 2;
    assert_eq!(map["poneyland"], 6);

    // 对比一下下面用法

    let text = "hello world wonderful world";
    let mut map = HashMap::new();
    for word in text.split_whitespace() {         // 根据空格来切分字符串(英文单词都是通过空格切分)
        let &mut count = map.entry(word).or_insert(0);
        //count += 1;  // cannot assign twice to immutable variable
    }
}
*/

/*
fn main() {
    use std::collections::HashMap;

    let name = String::from("Sunface");
    let age = 18;

    let mut handsome_boys = HashMap::new();
    handsome_boys.insert(&name, age);

    // std::mem::drop(name);
    println!("因为过于无耻，{:?}已经被除名", handsome_boys);
    println!("还有，他的真实年龄远远不止{}岁", age);
}
*/
/*
fn main() {
    use std::collections::HashMap;

    let teams_list = vec![
        ("中国队".to_string(), 100),
        ("美国队".to_string(), 10),
        ("日本队".to_string(), 50),
    ];

    let teams_map: HashMap<_,_> = teams_list.into_iter().collect();

    println!("{:?}",teams_map)
}
*/

/*
#[derive(Debug, Ord, Eq, PartialEq, PartialOrd)]
struct Person {
    age: u32,
    name: String,
}

impl Person {
    fn new(name: String, age: u32) -> Person {
        Person { age, name }
    }
}

fn main() {
    let mut people = vec![
        Person::new("Zoe".to_string(), 25),
        Person::new("Al".to_string(), 60),
        Person::new("Al".to_string(), 30),
        Person::new("John".to_string(), 1),
        Person::new("John".to_string(), 25),
    ];

    people.sort_unstable();

    println!("{:?}", people);
}
*/

/*
fn main() {
    let mut vec = vec![1.0, 5.6, 10.3, 2.0, 15f32];
    vec.sort_by(|a, b| a.partial_cmp(b).unwrap());
    assert_eq!(vec, vec![1.0, 2.0, 5.6, 10.3, 15f32]);
}
*/

/*
fn main() {
    let mut vec = vec![1, 2, 3, 4];
    vec.retain(|x| x % 2 == 0);
    assert_eq!(vec, [2, 4]);
}
*/

/*
fn main() {
    let v = vec![1, 2, 3, 4, 5];
    let third: &i32 = &v[2];
    println!("第三个元素是 {}", third);
    match v.get(2) {
        Some(third) => println!("第三个元素是 {third}"),
        None => println!("去你的第三个元素，根本没有！"),
    }

    let v = vec![1, 2, 3];
    for i in v {     // 等同 v.iter()
        println!("{i}");
    }

}
*/

/*
fn main() {
    let arr = vec![Box::new(1), Box::new(2)];
    let (first, second) = (&arr[0], &arr[1]);
    let sum = **first + **second;
}
*/

/*
trait Pilot {
    fn fly(&self);
}

trait Wizard {
    fn fly(&self);
}

struct Human;

impl Pilot for Human {
    fn fly(&self) {
        println!("This is your captain speaking.");
    }
}

impl Wizard for Human {
    fn fly(&self) {
        println!("Up!");
    }
}

impl Human {
    fn fly(&self) {
        println!("*waving arms furiously*");
    }
}

fn main() {
    let person = Human;
    person.fly();
}
*/

/*
pub trait Draw {
    fn draw(&self);
}
pub struct Button {
    pub width: u32,
    pub height: u32,
    pub label: String,
}

impl Draw for Button {
    fn draw(&self) {
        // 绘制按钮的代码
    }
}

pub struct SelectBox {
    pub width: u32,
    pub height: u32,
    pub options: Vec<String>,
}

impl Draw for SelectBox {
    fn draw(&self) {
        // 绘制SelectBox的代码
    }
}

pub struct Screen {
    pub components: Vec<Box<dyn Draw>>,
}

impl Screen {
    pub fn run(&self) {
        for component in self.components.iter() {
            component.draw();
        }
    }
}

fn main() {
    let screen = Screen {
        components: vec![
            Box::new(SelectBox {
                width: 75,
                height: 10,
                options: vec![
                    String::from("Yes"),
                    String::from("Maybe"),
                    String::from("No"),
                ],
            }),
            Box::new(Button {
                width: 50,
                height: 10,
                label: String::from("OK"),
            }),
        ],
    };

    screen.run();
}
*/
/*
trait Draw {
    fn draw(&self) -> String;
}

impl Draw for u8 {
    fn draw(&self) -> String {
        let aa=format!("u8: {}", *self);
        println!("{}",aa);
        aa
    }
}

impl Draw for f64 {
    fn draw(&self) -> String {
        let aa=format!("f64: {}", *self);
        println!("{}",aa);
        aa
    }
}
// 若 T 实现了 Draw 特征， 则调用该函数时传入的 Box<T> 可以被隐式转换成函数参数签名中的 Box<dyn Draw>
fn draw1(x: Box<dyn Draw>) {
    // 由于实现了 Deref 特征，Box 智能指针会自动解引用为它所包裹的值，然后调用该值对应的类型上定义的 `draw` 方法
    x.draw();
}

fn draw2(x: &dyn Draw) {
    x.draw();
}

fn main() {
    let x = 1.1f64;
    // do_something(&x);
    let y = 8u8;
    // x 和 y 的类型 T 都实现了 `Draw` 特征，因为 Box<T> 可以在函数调用时隐式地被转换为特征对象 Box<dyn Draw>
    // 基于 x 的值创建一个 Box<f64> 类型的智能指针，指针指向的数据被放置在了堆上
    draw1(Box::new(x));
    // 基于 y 的值创建一个 Box<u8> 类型的智能指针
    draw1(Box::new(y));
    draw2(&x);
    draw2(&y);
}
*/

/*
fn display_array<T: std::fmt::Debug>(arr: &[T]) {
    println!("{:?}", arr);
}
fn main() {
    let arr: [i32; 3] = [1, 2, 3];
    display_array(&arr);

    let arr: [i32; 2] = [1, 2];
    display_array(&arr);
}
*/

/*
struct Point<T, U> {
    x: T,
    y: U,
}
impl<T, U> Point<T, U> {
    fn mixup<V, W>(self, other: Point<V, W>) -> Point<T, W> {
        Point {
            x: self.x,
            y: other.y,
        }
    }
}
fn main() {
    let p1 = Point { x: 5, y: 10.4 };
    let p2 = Point { x: "Hello", y: 'c'};

    let p3 = p1.mixup(p2);

    println!("p3.x = {}, p3.y = {}", p3.x, p3.y);
}
*/

/*
use std::fmt::Display;
fn create_and_print<T>() where T: From<i32> + Display {
    let a: T = 100.into(); // 创建了类型为 T 的变量 a，它的初始值由 100 转换而来
    println!("a is: {}", a);
}
fn main() {
    create_and_print::<i32>();
}
*/

/*
struct Point {
    x: i32,
    y: i32,
}

fn main() {
    let p = Point { x: 0, y: 7 };

    match p {
        Point { x, y: 0 } => println!("On the x axis at {}", x),
        Point { x, y } => println!("On neither axis: ({}, {})", x, y),
        Point { x: 0, y } => println!("On the y axis at {}", y),
    }
}
*/

/*
fn print_coordinates((x, y): (i32, i32)) {
    println!("Current location: ({}, {})", x, y);
}

fn main() {
    let point = (3, 5);
    print_coordinates(point);
}*/

/*
#[derive(Debug, PartialEq)]  // 添加派生宏
enum MyEnum {
    Foo,
    Bar,
}
fn main() {
    let v = vec![MyEnum::Foo, MyEnum::Bar, MyEnum::Foo];

    // 方法1：使用派生PartialEq后的直接比较
    let filtered: Vec<_> = v.iter()
        .filter(|&x| x == &MyEnum::Foo)  // 注意引用比较
        .collect();
    println!("{:?}", filtered);  // 输出 [Foo, Foo]

    // 方法2：更Rust风格的模式匹配
    let filtered: Vec<_> = v.iter()
        .filter(|x| matches!(x, MyEnum::Foo))
        .collect();
    println!("{:?}", filtered);  // 输出 [Foo, Foo]
}
*/

/*
fn main() {
    let o = None;
    let v = if let Some(x) = o { x } else { 0 };
    println!("{}",v);
}
*/

/*
fn main() {
    // 编译器自动推导出one的类型
    let one = [1, 2, 3];
    // 显式类型标注
    let two: [u8; 3] = [1, 2, 3];
    let blank1 = [0; 3];
    let blank2: [u8; 3] = [0; 3];

    // arrays是一个二维数组，其中每一个元素都是一个数组，元素类型是[u8; 3]
    let arrays: [[u8; 3]; 4] = [one, two, blank1, blank2];
    // 借用arrays的元素用作循环中
    for a in &arrays {
        print!("{:?}: ", a);
        // 将a变成一个迭代器，用于循环
        // 你也可以直接用for n in a {}来进行循环
        for n in a.iter() {
            print!("\t{} + 10 = {}", n, n + 10);
        }

        let mut sum = 0;
        // 0..a.len,是一个 Rust 的语法糖，其实就等于一个数组，元素是从0,1,2一直增加到到a.len-1
        for i in 0..a.len() {
            sum += a[i];
        }
        println!("\t({:?} = {})", a, sum);
    }
}
*/

/*
fn main() {
    let array: [String; 8] = std::array::from_fn(|i| String::from("rust is good!"));
    println!("{:#?}", array);
}
*/

/*
use std::io;
fn main() {
    let a = [1, 2, 3, 4, 5];
    println!("Please enter an array index.");
    let mut index = String::new();
    io::stdin()
        .read_line(&mut index)
        .expect("Failed to read line");
    let index: usize = index
        .trim()
        .parse()
        .expect("Index entered was not a number");

    let element = a[index];
    println!(
        "The value of the element at index {} is: {}",
        index, element
    );
}
*/

/*
#[derive(Debug)]
enum PokerSuit {
  Clubs,
  Spades,
  Diamonds,
  Hearts,
}
fn main() {
    let heart = PokerSuit::Hearts;
    let diamond = PokerSuit::Diamonds;
    print_suit(&heart);

    println!("[{:?}]",heart);

    print_suit(&diamond);
}

fn print_suit(card: &PokerSuit) {
    // 需要在定义 enum PokerSuit 的上面添加上 #[derive(Debug)]，否则会报 card 没有实现 Debug
    println!("{:?}",card);
}
*/

/*
struct Rectangle {
    width: u32,
    height: u32,
}

fn main() {
    let rect1 = Rectangle {
        width: 30,
        height: 50,
    };
    println!("rect1 is {:#?}", rect1);
}
    */

/*
fn main() {
    let s = "中国人";
    let mut iter = s.chars();  // 创建字符迭代器

    while let Some(c) = iter.next() {  // 手动迭代
        println!("{}", c);
    }
}
*/

/*
fn first_word(s: &str) -> &str {
    s.split_whitespace().next().unwrap_or("")
}
fn main() {
    println!("{}", first_word("中国 人 "));
}
*/

/*
fn main() {
   let mut s = String::from("hello");

    let r1 = &s;
    let r2 = &s;
    println!("{} and {}", r1, r2);
    // 新编译器中，r1,r2作用域在这里结束

    let r3 = &mut s;
    println!("{}", r3);
} // 老编译器中，r1、r2、r3作用域在这里结束
  // 新编译器中，r3作用域在这里结束
*/

/*
fn main() {
    let s1: String = String::from("hello");
    let len = calculate_length(&s1);
    println!("The length of '{}' is {}.", s1, len);
}

fn calculate_length(s: &str) -> usize {
    s.len()
}
*/

/*
fn plus_or_minus(x:i32) -> i32 {
    if x > 5 {
        x - 5
    }

    x + 5
}

fn main() {
    let x = plus_or_minus(6);

    println!("The value of x is: {}", x);
}
*/

/*
fn main() {
    // let v1 = 247_u8 + 8;
    // let v2 = i8::checked_add(119, 8).unwrap();
    // println!("{},{}", v1, v2);
    let c = 'z';
    let z = 'ℤ';
    let g = '国';
    let heart_eyed_cat = '😻';
    println!("字符'中'占用了{}字节的内存大小", size_of_val(&heart_eyed_cat));

    // println!("0011 AND 0101 is {:04b}", 0b0011u32 & 0b0101);
    // println!("0011 OR 0101 is {:04b}", 0b0011u32 | 0b0101);
    // println!("0011 XOR 0101 is {:04b}", 0b0011u32 ^ 0b0101);
    // println!("1 << 5 is {}", 1u32 << 5);
    // println!("0x80 >> 2 is 0x{:x}", 0x80u32 >> 2);

}*/

/*
  use std::ops::{Range, RangeInclusive};
fn main() {
    assert_eq!((1..5), Range{ start: 1, end: 5 });
    assert_eq!((1..=5), RangeInclusive::new(1, 5));
}
*/

/*
fn main() {
    let s1 = "hello"; // &'static str（全局有效）
    let s2 = String::from("world");
    let result = longest(s1, &s2); // 返回的引用生命周期 ≤ s2 的生命周期
    println!("{}", result); // 正确，因为 s2 仍然存活
}

fn longest<'a>(x: &'a str, y: &'a str) -> &'a str {
    if x.len() > y.len() { x } else { y }
}
*/

/*
fn main() {
    let x:u32  = 5;
    type_of(&x)
    // assert_eq!("u32".to_string(), type_of(&x));
}

fn type_of<T>(_: &T) -> String {
    format!("{}", std::any::type_name::<T>())
}
*/

/*
    let x: i8 = 127;
    let mut _y: i16 = 5;
    _y += x as i16;
    let _z = 10;
    dbg!("{}", _y);

    assert_eq!(100u8.saturating_add(1), 101);
    assert_eq!(u8::MAX.saturating_add(127), u8::MAX);

    let b: i16 = 255;
    let _b_: u8 = match b.try_into() {
        Ok(b1) => b1,
        Err(e) => {
            println!("{:?}", e.to_string());
            0
        }
    };

    let a = Complex { re: 2.1, im: -1.2 };
    let b = Complex::new(11.1, 22.2);
    let result = a + b;

    println!("{} + {}i", result.re, result.im);

    let a = u8::MAX;
    println!("{}", a);

    let mut values: [i32; 2] = [1, 2];
    let p1: *mut i32 = values.as_mut_ptr();
    let first_address = p1 as usize; // 将p1内存地址转换为一个整数
    let second_address = first_address + 4; // 4 == std::mem::size_of::<i32>()，i32类型占用4个字节，因此将内存地址 + 4
    let p2 = second_address as *mut i32; // 访问该地址指向的下一个整数p2
    unsafe {
        *p2 += 1;
    }
    dbg!("{:?}", values);
    assert_eq!(values[1], 3);

}
 */
