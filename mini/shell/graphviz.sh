#!/bin/bash
if ! command -v dot &> /dev/null; then
    echo "graphviz未安装,开始安装..."
    sudo apt-get install -y graphviz
    if [ $? -eq 0 ]; then
        echo "graphviz安装成功!"
    else
        echo "graphviz安装失败,请手动安装"
    fi
fi

if ! command -v eog &> /dev/null; then
    echo "eog未安装,开始安装..."
    sudo apt-get install eog
    if [ $? -eq 0 ]; then
        echo "eog安装成功!"
    else
        echo "eog安装失败,请手动安装"
    fi
fi

# 邻接表
declare -A adjacency_list
adjacency_list["a"]="b c d j k l"
adjacency_list["b"]="d"
adjacency_list["d"]="e"
adjacency_list["e"]="a"

echo "[${!adjacency_list[@]}]"
# 生成DOT文件
echo "digraph G {" |tee -a graph.dot

for vertex in "${!adjacency_list[@]}"; do
    neighbors=${adjacency_list[$vertex]}
    for neighbor in $neighbors; do
        echo "  $vertex -> $neighbor;" |tee -a graph.dot
    done
done

echo "}" |tee -a graph.dot

#dot -Tpng graph.dot -o graph.png
#eog graph.png   #可视化


