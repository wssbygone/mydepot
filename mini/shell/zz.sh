# 定义一个函数，打印所有参数
print_args() {
    echo "Using \$@:"
    for arg in "$@"; do
        echo "$arg"
    done

    echo "Using \$*:"
    for arg in $*; do
        echo "$arg"
    done
}

# 调用函数并传递带空格的参数
print_args "apple pie" "orange juice"

