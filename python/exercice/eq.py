class A:
    def __init__(self, name, age):
        self.name = name
        self.age = age

    def __eq__(self, other):
        if self.name == other.name and self.age == other.age:
            return True
        else:
            return False

    def __str__(self):
        return "~~~%s" % self.name

a = A('zou', 83)
aa = A('hou', 83)
aa2 = A('zou', 83)

print(a, aa)
print(a == aa)
