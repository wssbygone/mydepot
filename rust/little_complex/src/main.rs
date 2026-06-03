fn main() {
    use std::collections::HashMap;

    let mut scores = HashMap::new();

    scores.insert("Blue", 10);

    // 覆盖已有的值
    let old = scores.insert("Blue", 20);
    assert_eq!(old, Some(10));

    // 查询新插入的值
    let new = scores.get("Blue");
    assert_eq!(new, Some(&20));

    // 查询Yellow对应的值，若不存在则插入新值
    let v = scores.entry("Yellow").or_insert(5);
    assert_eq!(*v, 5); // 不存在，插入5

    // 查询Yellow对应的值，若不存在则插入新值
    let v = scores.entry("Yellow").or_insert(50);
    assert_eq!(*v, 5); // 已经存在，因此50没有插入
}


/*
use tokio::time;
#[tokio::main]
async fn main() {
    // 异步睡眠
    println!("Start");
    time::sleep(time::Duration::from_secs(1)).await;
    println!("1 second later");
    
    // pub fn timeout<T>(duration: Duration, future: T) -> Timeout<T>
    // where
    //    T: Future,
    match time::timeout(time::Duration::from_secs(5),
        async { /* 一些异步操作 */ }
    ).await {                                           //  等价于 time::timeout(time::Duration::from_secs(5), async { /* 一些异步操作 */ }).await
        Ok(_) => println!("Completed in time"),
        Err(_) => println!("Timed out"),
    }
}
 */

 
/*
#[derive(Debug, Ord, Eq, PartialEq, PartialOrd)]
struct Person {
    age: u32,
    name: String,
}

impl Person {
    fn new(age: u32, name: String) -> Person {
        Person { age, name}
    }
}

fn main() {
    let mut people = vec![
        Person::new(25, "Zoe".to_string()),
        Person::new(60,"Al".to_string() ),
        Person::new(30, "Al".to_string()),
        Person::new(15,"John".to_string()),
        Person::new(25, "John".to_string()),
    ];

    people.sort_unstable();

    println!("{:?}", people);
}
*/

/*use std::fmt;
// 为 Vec<i32> 实现自定义显示
struct PrettyVec(Vec<i32>);

impl fmt::Display for PrettyVec {
    fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
        write!(f, "向量包含 {} 个元素: {:?}", self.0.len(), self.0)
    }
}*

fn main() {
    let pv = PrettyVec(vec![1, 2, 3, 4, 5]);
    println!("{}", pv); // 输出: 向量包含 5 个元素: [1, 2, 3, 4, 5]
}
*/


/*
fn main() {
    let mut s = String::from("Hello rust!");
    s.insert(5, ',');
    println!("插入字符 insert() -> {}", s);
    s.insert_str(6, " I like");
    println!("插入字符串 insert_str() -> {}", s);
}
*/
/*
struct Counter {
    count: u32,
}

impl Counter {
    fn new() -> Counter {
        Counter { count: 0 }
    }
}

impl Iterator for Counter {
    type Item = u32;

    fn next(&mut self) -> Option<Self::Item> {
        if self.count < 5 {
            self.count += 1;
            Some(self.count)
        } else {
            None
        }
    }
}

fn main() {
    // let mut counter = Counter::new();
    // assert_eq!(counter.next(), Some(1));
    // assert_eq!(counter.next(), Some(2));
    // assert_eq!(counter.next(), Some(3));
    // assert_eq!(counter.next(), Some(4));
    // assert_eq!(counter.next(), Some(5));
    // assert_eq!(counter.next(), None);

    let sum: u32 = Counter::new()
        .zip(Counter::new().skip(1))
        .map(|(a, b)| a * b)
        .filter(|x| x % 3 == 0)
        .sum();
    println!("{:?}",sum);
    // assert_eq!(18, sum);
}
*/

/*
fn main() {
    let values = vec![1, 2, 3];

    for v in values.into_iter() {
        println!("{}", v)
    }

    // 下面的代码将报错，因为 values 的所有权在上面 `for` 循环中已经被转移走
    // println!("{:?}",values);

    let values = vec![1, 2, 3];
    let _values_iter = values.iter();

    // 不会报错，因为 values_iter 只是借用了 values 中的元素
    println!("{:?}", values);

    let mut values = vec![1, 2, 3];
    // 对 values 中的元素进行可变借用
    let mut values_iter_mut = values.iter_mut();

    // 取出第一个元素，并修改为0
    if let Some(v) = values_iter_mut.next() {
        *v = 0;
    }

    // 输出[0, 2, 3]
    println!("{:?}", values);
}

fn main() {
    let arr = [1, 2, 3];
    let mut arr_iter = arr.into_iter();
    println!("{:?}", arr);

    assert_eq!(arr_iter.next(), Some(1));
    assert_eq!(arr_iter.next(), Some(2));
    assert_eq!(arr_iter.next(), Some(3));
    assert_eq!(arr_iter.next(), None);
    println!("{:?}", arr);   // 为嘛这里还是可以打印？
}
*/

/*
fn main() {
    let s = "sss";

    let update_string =  || println!("{}",s);

    exec(update_string);
    exec1(update_string);
    exec2(update_string);
}

fn exec<F: FnOnce()>(f: F)  {
    f()
}

fn exec1<F: FnMut()>(mut f: F)  {
    f()
}

fn exec2<F: Fn()>(f: F)  {
    f()
}
*/

/*
fn main() {
    let s = "hello, ".to_string();

    let update_string =  |str| println!("{},{}",s,str);

    exec(update_string);

    println!("{:?}",s);
}

fn exec<F: Fn(String) -> ()>(f: F)  {
    f("world".to_string())
}
*/

/*
fn main() {
    let mut s = String::new();

    let mut update_string =  |str| s.push_str(str);
    update_string("hello");

    println!("{:?}",s);
}
*/

/*
fn fn_repeat<F>(func: F)
where
    F: FnOnce(usize) -> bool + Copy,  // 改为 Fn（不可变借用）
{
    println!("{}", func(3));
    println!("{}", func(4));
}

fn main() {
    let x = vec![1, 2, 3];
    fn_repeat(|z| z == x.len());
    fn_repeat(|z| z == x.len());
}
*/