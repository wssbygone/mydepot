set -x
a="$1"
b="${a%.*}.styled.json"
echo $b

python -m json.tool $1 > house.sty.json
mv house.sty.json house.json

python xx.py >  $b

sed -i -e 's/\\n\"//g' -e 's/\\\"/\"/g' -e 's/^\"//g'  $b

