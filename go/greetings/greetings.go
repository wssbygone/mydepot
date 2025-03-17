package greetings

import "fmt"

// 首字母大写的函数会暴露给外部模块调用, 否则只能包内使用.
// 括号内为函数参数, name是参数名, string是参数类型
// 括号外的string 是返回类型
func Hello(name string) string {
    // := 在go中表示同时在一行内声明和初始化一个变量
    message := fmt.Sprintf("Hi, %v. Welcome to China!", name)
    return message

}
