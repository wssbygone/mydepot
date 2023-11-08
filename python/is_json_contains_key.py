import json

json_str1 = '{"name": "小明", "age": 18, "gender": "男", "address": {"province": ["广东","广州"], "city": "深圳"}}'
json_str2 = '{"name": "小红", "age": 20, "gender": "女", "address": {"province": "北京", "city": "北京"}}'
json_str3 = '{"name": "小刚", "age": 22, "gender": "男"}'

json_list = [json.loads(json_str1), json.loads(json_str2), json.loads(json_str3)]

for index, json_dict in enumerate(json_list):
	if "address" in json_dict:
		print(f"第{index + 1}个JSON数据中address字段存在")
		print(json_dict["address"]["province"])
		#address_value=json_dict.get("address",None)
		#pro_value=address_value.get("province",None)
		#for p in pro_value:
		#	print(f"pro字段的值为：{p}")
	else:
		print(f"第{index + 1}个JSON数据中address字段不存在")
