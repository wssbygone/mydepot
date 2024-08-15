#!/bin/bash
# :lc: 这里最开始的冒号:用于禁止getopts默认的错误处理行为，而允许脚本自行处理错误情况
while getopts ":lc:" opt; do    
    case $opt in
        l)
            echo "列出指定目录下的所有文件:"
            ls -l
            ;;
        c)
            echo "统计指定文件的行数:"
            file="$OPTARG"
            if [ -f "$file" ]; then
                lines=$(wc -l < "$file")
                echo "文件 $file 有 $lines 行."
            else
                echo "文件 $file 不存在."
            fi
            ;;
        :)
            echo "选项 -$OPTARG 需要参数."
            ;;
        \?)
            echo "未知选项: -$OPTARG"
            ;;
    esac
done

