package main

import (
        "bufio"
        "fmt"
        "net"
        "time"
)

var quitSemaphore chan bool

func main() {
        var unixAddr *net.UnixAddr
        unixAddr, _ = net.ResolveUnixAddr("unix", "/home/wss/mydepot/go/uds/sidecar.sock")

	conn, err := net.DialUnix("unix", nil, unixAddr)
	if err != nil {
		fmt.Println("Dial error:", err)
		return
	}
	defer conn.Close()

	fmt.Println("Connected to server.")

        go onMessageRecived(conn)
        quitSemaphore = make(chan bool)
        b := []byte("time\n")
        conn.Write(b)

        <-quitSemaphore
}

func onMessageRecived(conn *net.UnixConn) {
        reader := bufio.NewReader(conn)
        for i := 0; i < 5; i++ {
                msg, err := reader.ReadString('\n')
                fmt.Print(msg)
                if err != nil {
                        quitSemaphore <- true
                        break
                }
                time.Sleep(time.Second)
                b := []byte("hahah\n")
                conn.Write(b)
       }
       quitSemaphore <- true
}
