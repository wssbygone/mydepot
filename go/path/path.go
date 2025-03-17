package main

import (
    "fmt"
    "os"
    "path/filepath"
)

func main() {
    root := "/home/wss/mydepot/go" // 当前目录
    err := filepath.Walk(root, func(path string, info os.FileInfo, err error) error {
        if err != nil {
            fmt.Printf("Error accessing path %q: %v\n", path, err)
            return err
        }
        fmt.Println(path)
        return nil
    })
    if err != nil {
        fmt.Printf("Error walking the path: %v\n", err)
    }
}

func mainx() {
    rootDir := "/home/user/documents"
    path := "/home/user/documents/projects/go-project/main.go"

    // 计算相对路径
    relPath, err := filepath.Rel(rootDir, path)
    if err != nil {
        fmt.Printf("Error calculating relative path: %v\n", err)
        return
    }

    fmt.Printf("Relative path of %s to %s is: %s\n", path, rootDir, relPath)
}
