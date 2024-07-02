#!/bin/bash

cleanup() {
    echo "Caught Ctrl+C. Cleaning up..."
    # 在这里执行清理操作
}

trap cleanup SIGINT

echo "Running... Press Ctrl+C to interrupt."

# 模拟一个长时间运行的操作
sleep 10
