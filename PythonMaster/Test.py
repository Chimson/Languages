# simple example of calling a method two ways
# as a normal method and like a static method, with obj as an arg
class MyInt:
  def __init__(self, i):
    self.i = i
  def func(self):
    print(self.i)
m = MyInt(10)
MyInt.func(m)
m.func()
