#!/bin/bash

# 定义JSON数据
json_data='{
    "paras/xx": {
        "src_path": "src/neta_ep32",
        "target": ["parameters_post.json", "zzz"]
    },
    "aaa/xx":"bbb",
    "aa":["cc","zz"]
}'

# 通过管道将JSON数据传递给jq，并解析所有的键和值
keys_values=$(echo "$json_data" | jq -r 'to_entries | .[] | "\(.key) \(.value)"')

# 逐个输出每个键值对的键和值，仅在键为"aaa/xx"时打印
while IFS= read -r line; do
    key=$(echo "$line" | awk '{print $1}')
    value=$(echo "$line" | awk '{print $2}')
    if [ "$key" == "aa" ];then
        echo $json_data | jq -r ".aa | map(@json)[]"
    fi

done <<< "$keys_values"
