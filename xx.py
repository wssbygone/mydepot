#python -m json.tool 1F.json > 1FStyled.json
import json
import sys

reload(sys)
sys.setdefaultencoding( "utf-8" )

file = open("house.json")

for line in file:
        print(json.dumps(line.decode('unicode_escape'),ensure_ascii=False))
file.close()


#sed -i  's/\\n\"//g' 1Fout.json
#sed -i 's/\\\"/\"/g'  1Fout.json
#sed -i 's/^\"//g' 1Fout.good.jso
