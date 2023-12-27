#!/bin/bash
#set -x
# 打印进度条函数
print_progress() {
    local progress=$1
    local total=$2
    local length=50  # 进度条长度
    # 计算进度百分比
    local percentage=$((progress * 100 / total))

    # 计算进度条填充长度
    local fill_length=$((progress * length / total))
    # 打印进度条
    printf "["
    for ((i = 0; i <fill_length ; i++)); do
        printf "="
    done
    printf ">"
    for ((i=fill_length; i<length; i++)); do
        printf " "
    done
    printf "] %d%%\r" $percentage
}

# 示例使用
total_steps=100

for ((step=1; step<=total_steps; step++)); do
    # 模拟耗时操作
    sleep 0.1

    # 打印进度条
    print_progress $step $total_steps
done

printf "\n"
