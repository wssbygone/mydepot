class Foo:
    def __getitem__(self, item):
        print("__getitem__.start: ", item.start)
        print("__getitem__.stop: ", item.stop)
        print("__getitem__.step: ", item.step)

    def __setitem__(self, key, value):
        print("__setitem__.index: ", key)
        print("__setitem__.value: ", value)
        return value

    def __delitem__(self, key):
        print("__delitem__: ", key)

f = Foo()
f[1:5:2]    #自动触发__getitem__
f[0] = 1   #自动触发__setitem__
del f[0]    #自动触发__delitem__
