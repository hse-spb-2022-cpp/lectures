class B:
    def __init__(self):
        self.vec = [10, 20, 30]

class A:
    def __init__(self):
        self.bs = [B(), B(), B(), B(), B()]

x = A()
y = x
print(x.bs[0].vec[1])
print(y.bs[0].vec[1])
x.bs[0].vec[1] += 1
print(x.bs[0].vec[1])
print(y.bs[0].vec[1])
