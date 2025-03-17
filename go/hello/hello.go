package main

import (
      "fmt"
      "example.com/greetings"
)
import "rsc.io/quote"
import "github.com/mazeyqian/asiatz"

func main() {
    fmt.Println("Hello, World!")
    fmt.Println(quote.Go()) //
    utcTime, err := asiatz.ShanghaiToUTC("10:00")
    if err != nil {
         fmt.Println("Error")
         return
    }
    fmt.Println("UTC Time:", utcTime) // Output: 02:00
    message := greetings.Hello("Hanmeimei") 
    fmt.Println(message)
}
