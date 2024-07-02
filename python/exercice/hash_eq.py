class Employee:
    def __init__(self, name, age, sex, partment):
        self.name = name
        self.age = age
        self.sex = sex
        self.partment = partment

    def __hash__(self):
        return hash('%s%s' % (self.name, self.sex))

    def __eq__(self, other):
        if self.name == other.name and self.sex == other.sex:
            return True


employ_lst = []
for i in range(200):
    employ_lst.append(Employee('a', i, 'male', 'python'))
for i in range(200):
    employ_lst.append(Employee('b', i, 'male', 'python'))
for i in range(200):
    employ_lst.append(Employee('c', i, 'male', 'python'))

# print(employ_lst)
employ_set = set(employ_lst)
for person in employ_set:
    print(person.__dict__)
