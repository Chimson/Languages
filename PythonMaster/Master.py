# FROM CSC_401, PYTHON IDLE HELP, PYTHON TEXT
# IN PYTHON IDLE HELP, STOPPED AT THE PYTHON TUTORIAL > 10.1 (done?)
  # I did skip: Input and Output, Errors and Exceptions

Language lives in C:\Users\Benso\AppData\Local\Programs\Python\Python310

RUN INTERPRETER, IDLE
BUILT-IN
MODULES
PACKAGES
TYPE
OPERATORS
LIST
TUPLE
SET
RANGE
STRING
DICTIONARY
IMMUTABLE VS MUTABLE
IO
CONTROL
MATCH
SCOPE
LOOP
FUNCTION
CLASS
INHERITANCE
OPERATOR OVERLOADING 
EXCEPTION
ITERATOR, GENERATORS, AND GENERATOR EXPRESSIONS

RUN INTERPRETER, FILE
# start interpreter in command prompt
> py        # or > python
$ quit()    
# ------
# run file in interpreter
> py Test.py        # runs and exits interpreter
> py -i Test.py     # runs and stays in interpreter
# ------
# use pdb
# starts debugging at the first executable line of the file
> python -m pdb test.py


BUILT-IN
# best to see these in IDE
# in __builtins__ namespace
vars()		# shows variables im current namespace
vars(__builtins__)		# displays variables in __builtins__ namespace
vars(x)   # displays atrs of object
dir()     # returns namespaces in current scope, as a list of strings
dir(obj)  # returns a directory of methods and functions for variable
help(x)   # displays help info for type of x 
id(x)   # displays the mem location aka reference value of x
isinstance(obj, class)  # returns boolean
issubclass(class1, class2)  # returns boolean
# -----
# more notable built_in functions 
zip() reversed(), sorted()

MODULES
# python scripts that are saved in seperate files with .py
# see MySum.py module, includes mySum() functions
# ImportEx.py importing MySum.py
# each module is only imported once per interpreter session
import MySum    # imports Module to this program/shell
MySum.mySum(2,3)    # calls mySum
mySum = MySum.mySum   # assigns it as a local name in Test.py without need to use Module namespace
mySum(4,5)
print(MySum.GLOBAL)   # GLOBAL defined in MySum.py
# -----
# grabs from MySum.py, saves the function locally  
# ideal way to import a module
from MySum import mySum
print(mySum(3,4))
# -----
# imports all functions, variables locally, except those like _name
from MySum import * 
print(GLOBAL)
# -----
# binds name S to MySum.py module
import MySum as S
print(S.mySum(3,4))
# -----
# imports MySum.mySum() and renames it as sm
from MySum import mySum as sm
print(sm(3,4))
# -----
# pass command line args to Test.py
# > py Test.py 1    // 1
# Test.py:
import sys
print(int(sys.argv[1]))
# -----
# imported modules are compiled in __pycache__ as .pyc files
# -m runs module as a script
> python -m compileall    # compiles .pyc files for all modules in a directory
# -----
# dir() used find which names a module defines
dir()  
import MySum
dir(MySum)    #  __builtins__, __name__ 
dir(__builtins__)   #  lists the names of builtin functions and variables

PACKAGES
# namespace package (no __init__.py file, see regular package)
# if there are the same names in two different samespaces they should not collide
# reach module .\package\PackageFile.py   # PackageFile.py is a module
# > py Test.py
from package.PackageFile import packageFunc as f   # grabs only the one function from the file 
f()   
# -----
# subpackage, SubpackageFile.py is a module
from package.subpackage.SubpackageFile import *   # imports everything in the file (module) locally  
subpackageFunc()
# ------
# import multiple modules in one package, this is a regular package bc it has __init__.py
# requires __init__.py file in package with __all__ list defined inside, see ./package/importmodules
# Test.py:
from package.importmodules import *   
module1.module1F()
module2.module2F()
# ------
# intra-package import
# see package\subpackage\SubackageFile.py, contains subpackageFunc()
# SubpackageFile.py imports package\importmodules\module1.py function module1F() 
# Test.py:
from package.subpackage.SubpackageFile import subpackageFunc  
subpackageFunc()  
# -----
# relative branch import, using . and ..
# in module1.py: 
from . import module2  # import a model in same package
from .. import PackageFile  # imports a module in parent package
# -----
# install 3rd party modules using pip
> python -m pip install numpy
> python -m pip install matplotlib

TYPE
# all are governed by their respective class, everything is an object
str, int, float, complex, bool, bytes, bytearray
str(x), int(x), float(x), ...   # constructors to convert to this type
eval(x)   # python chooses what to convert it to
None  # is the value of NoneType 
# -----
# type() helps to validate input
type("string") == str    # returns bool of true

OPERATORS
# basic variables, operators, functions
# numerical operators, in order of precedence
()  
**  # exponent
*, /, //, %    #   % is remainder, modulus or "mod",  // is floor division, also called "div"
+, -
x = 3   # assignment
x, y = 0,1   # multiple assignment
a = 3 + 4  # expression evaluated then assigned to variable 
+=, -=, ... # op=
# see individual classes like int for more __op__() operations  
# ------
# multiple statements in one line using ;  # normally you seperate by next lines 
x = 1
if(x): print(x); x += 1; print(x);  # 1, 2
else: print("nothing")
# -----
# is checks if the same obj (same memory location), == checks if they have the same value
# see example in  CLASS
is 
==    # calls's a classes __eq__
# ----
# in, see LIST
in  # checks if in a container, calls obj.__contains__
# -----
# boolean operators and vars
==, !=, <, <=, >, >=, and, or, not
True		# 1, but also any non-0 evals to True
False		# 0
# -----
# walrus operator := allows assignment in an expression
i = -1
while((i := i + 1) < 10):  # adds 1 first, then compares with <
  print(i)


LIST
# lists are mutable, a sequence data type: has slicing, concat, indexing, ... other operations
# also has packing and unpacking
# compare reference with is, value comparison using ==
lst1 = [1,2]    # is vs == and location     # true for any type
lst2 = [1,2]
lst1 == lst2    # true, values are the same
lst1 is lst2    # false, different locations
lst3 = list(lst2)   # list constructor, copies value of lst2 into a new location lst3
# indexing
lst = [0, 1, 2, 3]
lst[1];
lst[3 : : -1]   # [3, 2, 1, 0], [start: stop: step] 
2 in lst    # True
# -----
# lists are mutable, so the references are the same
lst = [0, 1, 2, 3]
print(id(lst))
lst += [4, 5, 6]
print(id(lst))
# -----
# del does not save the values, like pop
l = [0,1,2,3]
del l[1:3]
print(l)  # [0,3]
# -----
# list constructor with range
lst = list(range(0,20,2))    # [0, 2, ... ,18]
# -----
# packing and unpacking
l = [0, 1, 2]
x, y, z = l
print(x, y, z)
# -----
# list comprehensions create lists
# they are of form [expr(i) for(i) ...]  # can be followed by 0 or more for or if statements
# nest going right: for(i) if(i) for(j) if(j) exp(i,j)
[i for i in range(0,10,1)]  # [0, 1, ..., 9]
[i for i in range(0,10,1) if i % 2 == 0]    # [0, 2, 4, 6, 8]
vec = [-10, -9, -8, -7]; l = [abs(x) for x in vec];  #[10, 9, 8, 7]
# -----
# flatten a list using list comprehension
vect = [[1,2,3], [4,5,6], [7,8,9]]; 
l = [num for vec in vect for num in vec];  # [1,2,3,4,5,6,7,8,9]
# -----
# nested list comprehension
l = [ [-x for x in [0, 1, 2, 3]] for i in range(3) ]  
print(l)  #[[0,-1,-2,-3],[0,-1,-2,-3],[0,-1,-2,-3] 
# -----
# enumerate() allows to print each value and its index in a sequence
l = ['a', 'b', 'c', 'd']
for i, v in enumerate(l):
  print(i, v)

TUPLE
# a sequence data type, immuable, but can contain mutable elements
# tuples can accept any value
t1 = (1,2)
print(t1)
t2 = ('a', 'b', 'c')
print(t2)
# ----
# immutable, so no assignment
t1 = (1,2)
#  t1[0] = 3, cannot assign
print(t1[0])
# -----
# supports in, by calling __contains__
t0 = 'a'
t1 = 1
t = (t0, t1)    # can support mixed values
print(1 in t)   #True
# -----
# use in list comprehension and tuple creator
list0 = [(p0,p1) for p0 in '123' for p1 in '456']  # all cross-product tuples
print(list0)
# -----
# empty and singleton
e = ()
s = 1,
print(e)  # empty
print(s)  # (1,)
# -----
# packing and unpacking a tuple, works for any sequence including list and range
t = (0, 1, 2)
x, y, z = t
print(x, y, z)

SET
# sets have no indexing
# they are unordered
# can also create set comprehensions, see LIST
e = set()  # empty set
s1 = {0,1,2,3,4,5}
print(0 in s1)   # calls __contains__
s2 = {3,4,5,6,7,8}
u = s1 | s2   # union
print(u)
i = s1 & s2  # intersection
print(i) 
# -----
# create a set from a list, removes duplicates in a list
l = [1,1,2,2,3,3]
s = set(l)    
print(s)
# -----
# can't add elements that are lists, but can add tuples
s = {1,2,3}
# s.add([3,4,5,5])   # does not run
s.add((1,2,3,4))
print(s)   # {(1,2,3,4), 1, 2, 3}

RANGE
# an iterable object and a sequence data type
# also has packing and unpacking, see TUPLE
range(10)  # 0, 1, 2, ..., 9
range(0,100,1)   # range(start, stop, step))
range(3,100,2)[7]    # 3+7*2 = 17
5 in range(0,100,1)  # True
sum(range(10))  # returns 0 + 1 + 2 + ... + 9

STRING
# can use '' or "", or multiple of either
# namespace str, string values are immutable
# [] index
name = "Ben Harki"
name2 = ("Ben" " Harki")   # automatic concat
print(name[2])   # n
print(name[-1])  # i, from right back
empty = ""
# -----
# [start, stop, step], can leave any blank
name = "Ben Harki"
print(name[2 : 5])  # n H, displays chars at indices 2, 3, 4
print(name[len(name)-2 : 1 : -1])  # "n kraH"
# -----
# len(string), needs escape char \
name = 'Ben\'s'   
print(len(name))  # 5
# -----
# string concat +
# multiline using ''' or \n
print("Ben" + " Harki")  # __add__
print('''Hi
next line''')
print("Hi \nnext line") 
print("B" in "Ben")  # True, calls __contains__
# ------
x = 3
s = str(3)    # converts to string
# ------
# f-string, a formatted string
# also can use f, x, o, e for formatting 
x = 3.12345678
num1 = 64
print(f"{x:.5} people")   # rounds to 5 dig digits: 3.1235
print(f"{num1:b}")    # binary

DICTIONARY
# is a mapping type
# any immutable type can be a key, anything can be a value
# can also do dict comprehensions, see LIST
e = {}   # empty dictionary
key0 = 'zero'
key1 = 'one'
val0 = 0
val1 = 1
dict1 = {key0:val0, key1:val1}
print(dict1)
dict2 = {0:'a', 1:3}    # can also be mixed
print(dict2)
# -----
# index and assign using key
# also supports del
d1 = {'a':1, 'b':2}
print(d1['a'])
d1['b'] = 3
print(d1)
del d1['b']  # removes the key:val pair
# -----
# in, which calls __contains__, only works on keys
d1 = {'a':1, 'b':2}
print('b' in d1)    # True
# ------
# order of key/vaue pairs does not matter
print({'a':1, 'b':2} == {'b':2, 'a':1})
# -----
# can create a dictionary using a sequence of sequence pairs
# also can use keyword args, that translate into keys of the dict
d = dict([('a', 1), ('b', 0)])
d1 = dict(ben = 0, mags = 1)   # keyword args of ben, mags
# -----
# get both the key and value using items()
d = dict([['ben', 0], ['mags', 1]])
for k, v in d.items():
  print(k,v)

IMMUTABLE VS MUTABLE
# immutable string
# different locations
s1 = "Ben"
s2 = " Harki"
print(hex(id(s1)))
s1 += s2
print(hex(id(s1)))
# -----
# mutable list
# same locations
list1 = [0, 1, 2, 3]
list2 = [4, 5, 6]
print(hex(id(list1)))
list1 += list2
print(hex(id(list1)))

IO
# io functions 
print(), input(), open(), eval()
with open() as file:    # auto closes  

CONTROL
# commands inside functions or loops
return  # terminates function 
break   # terminates innermost loop
continue    # termininates current iteration, skips to next iteration
pass    # does nothing
# -----
# if(non-zero) is true annd if(0) is false like C
# if will accept 1 for True, 0 for false
# can add an else like below
state = 12
if(state):    # don't need parens for if
  print("yep its not 0")
elif(~state):
  print("yep its 0")    
# -----
# if else
if(0):
  print("true")
else:
  print("false")    # executes
# -----
# pass defers the need to implement now, for writing abstract code
# allows compilation and can be replaced by actual code later
class Minimal:  
  pass
def abstractF():
  pass
# -----
# pass in a condition
x = 2
if(x % 2 == 0):
  pass

MATCH
# has pattern matching, this is a recursive function
# if no case matches, nothing executes
# _ is a wildcard and will match anything, but is not allowed in the body of a case 
def length(listVar):
  match listVar:
    case []:  # empty list
      return 0
    case [_, *rest]:   # rest is the "tail" or rest of the list (can also use case [x, *rest])
      return 1 + length(rest)
# MAIN
print(length([]))    # 0
print(length([0,1,2,3]))  # 4
# -----
# case doesn't match, exits match block
# also with an if guard
def isXAxis(point):
  match point:
    case (x, 0) if x > 10:   # it binds x to the paramter point's x value 
      print("at x = ", x)
      return True
  return False
# MAIN
print(isXAxis((3,0)))  # False
print(isXAxis((0,3)))  # False
print(isXAxis((11, 0)))  # True
# -----
# pattern matching on custom class
class MyInt:
  x: int   # notation to catch field in pattern matching
  def __init__(self, _x):  
    self.x = _x 
  def __str__(self):
   return f"{self.x}" 
def isEven(myint):
  match myint:
    case MyInt(x = y):  # x returns to MyInt's field
      return y % 2 
# MAIN
print(isEven(MyInt(2)))  # 0
print(isEven(MyInt(3)))  # 1
# -----
# capture using as
def MyPoint(p):
  match p:
    case (x,1) as px:
      print("point of ", px)
# MAIN
MyPoint((2,1))
# -----
# use pattern matching on an enum class, like a switch
from enum import Enum
class Color(Enum):
  RED = 0
  GREEN = 1
  BLUE = 2
# main
color = Color.RED
match color:
  case Color.RED:
    print("RED")
  case Color.GREEN:
    print("GREEN")
  case Color.BLUE:
    print("BLUE")

LOOP
# for loop with range
# range includes 1st number not the last
for i in range(0,5):    
  print(i)      # 0,1,2,3,4
# -----
# for each iteration cannot change the value of each member bc its copy by value
list1 = [0, 1, 2, 3, 4]
for l in list1:
  l = 0
print(list1)   #  [0,1,2,3,4]
# -----
# lists are mutable, so you can use indices and change the element
list2 = [0, 1, 2, 3, 4]
for i in range(len(list2)):
  list2[i] = 0
print(list2)      # [0,0,0,0,0]
# -----
# while loop with break
i = 0
while(1):
  if(i == 10): break
  print("Hi")
  i += 1
# -----
# while and for can have an else: executes when iteration breaks, unless there is a break 
i = 0
while(i < 10):
  if(i == 5):
    print(i)  # 5
  i += 1
else:   # not connected to the if, but to the while
  print(i)  # 10
# -----
# with a break, the else does not execute
i = 0
while(i < 10):
  if(i == 5):
    print(i)    # 5
    break;
  i += 1
else:
  print(i)    # does not execute bc of break  

SCOPE
# global keyword is used to write to a global variable from within a subscope
# it also pushes any other subscopes variable out to main, see g1
# global is meaningless used outside a function 
# generally enclosing scope variables are read only in their subscopes
def local():
  l = 10  # l is local to local() 
  print("l inside local: ", l)
  def subfunction():
    g1 = 2   # this variable is pushed all the way to main, by declaring it global in rw_globe
def ro_globe():   # a default global variable is read only in an enclosing scope
  print("g inside ro_globe: ", g)    # will throw exception if write to g
def rw_globe():  # with global keyword, I can write to it in an enclosing scope
  global g
  global g1     # now accessible in MAIN, even though it wasn't initialized in main
  g = 1
  g1 = 3
# MAIN
local()    # l = 10
# print(l)  # does not run, l is not visible
g = 0  # default global variable
ro_globe()   # g = 0, readble in subscope
rw_globe()   
print("g global variable changed: ", g, ", ", g1)  # g = 1, g1 = 3
# -----
# hiding enclosing function variables of same name in nested functions
def outer():
  x = 0
  def inner():
    x = 1  # hides outer x in this scope
    print(x)  
  inner()
  print(x)
# MAIN
outer()
# -----
# nonlocal is similar to global, except that it does not push it all the way back to MAIN
# nonlocal keyword takes an inner functions local variable and pushes it out of the local scope into the closest outer scope
def outer():
  x = 0
  def inner():
    nonlocal x  # this variable needs to be found in nearest enclosing scope excluding globals 
    x = 1
  inner()
  print(x)  # x = 1
# MAIN
outer()

FUNCTION
# def defines a function
# generally function parameters are call by value, but everything (including java-like primitives of int, etc.) is an object
# objects as parameters: pass by value on their references, simulates pass by reference 
# see SCOPE for global and nonlocal keyword, used inside a function
# -----
# pass by value
# everything in python is an object, so swap only swaps reference values or "primitive-like class" value
# ints are also objects, but unlike normal objects their value is not a memory location but an int, so they are primitive-like, see CLASS
# swap actually swaps, because the reference to the whole object is accepted and it swaps the object's "primitve" field vals
class MyInt:
  def __init__(self, _i):
    self.i = _i
  def __str__(self):
    return f"{self.i}"
def noSwap(x, y):  # swaps ref's or "primitive-like objs" vals
  tmp = x   
  x = y
  y = tmp
def swap(x, y):  
  tmp = MyInt(0)
  tmp.i = x.i    
  x.i = y.i
  y.i = tmp.i   
# MAIN
a = 0
b = 1
noSwap(a, b)
print(a, b)  # 0 1
c = MyInt(0)   
d = MyInt(1)
noSwap(c, d)  
print(c, d)   # 0 1
swap(c, d)
print(c, d)   # 1 0
swap(a, b)
print(a, b)
# -----
# annotations help show the typing of return val and params of a function
# annotations are totally optional, saved in __annotations__ as a dictionary
# annotations do not enforce strict typing, so functions will accept diffent types
def MySum(x:int, y:int = 0) -> int:
  return x + y
print(MySum(3,4)) # 7
print(MySum("3", "4"))     # 34  # string concat
print(MySum.__annotations__)  # a dict of each parameter an its class annotation
# -----
# """ """ defines a docstring for the function
# first line of docstring is a summary, remaining lines are more in depth
# functions that return nothing, actually return None
def p_list(lst):
  """ Prints all elements of a list.
  
      It prints taking one element at a time and printing it, line by line.
  """   
  for i in range(len(lst)):
    print(i)
# MAIN
l = [0, 1, 2, 3]
p_list(l)   # calls function
print(p_list(l))    # None, also true if the function ends on "return", but returns nothing
print(p_list)       # reference's value, which is a location, normally suppressed by idle
print(help(p_list))  # shows full docstring
docstring = p_list.__doc__  # saves the docstring as a string
print(docstring)   
# -----
# default value is shared among function calls, so it can accumulate with more calls
# can set it to None to avoid accumulation
def f(a, L=[]):
  L.append(a)
  return L
print(f(1))   # [1]
print(f(2))   # [1, 2] 
print(f(3))   # [1, 2, 3]
# -----
# with a return
def mySum(l):
  sum = 0
  for i in l:
    sum += i
  return sum
# MAIN
print(mySum([0,1,2,3,4,5,6,7,8,9]))
# -----
# call with keyword arguments, order doesn't matter
# must have all keyword args or none at all
# also one path returns nothing the other a list
def mySum(l, sum):
  if sum == -1: return
  for i in l:
    sum += i
  return sum
# MAIN
print(mySum(l = [0,1,2,3,4,5,6,7,8,9], sum = 0))   #  45
print(mySum(sum = -1, l = [0,1,2]))                # None, since returning nothing returns None
# -----
# before / indicates positional only arguments, after * indicates keyword only arguments
# without / or *, or in between indicates the arguments could be either
def printName(msg, /, *, name1, name2):
  print(msg); print(name1); print(name2)
# MAIN
printName("This cannot be called with keyword", name2 = "Harki", name1 = "Ben")
# -----
# bring in any custom arguments on call and print information on args and their value
# *arguments scoops up any remaining number of arguments to bring into the function
# *arguments is normally set as last in arg list (unlike this one), however any arg after is automatically a keyword-only argument
def printName(name, *arguments, **keywords):
  print(name)
  for arg in arguments:
    print(arg)
  for kw in keywords:
    print(kw, ":", keywords)
# MAIN
printName("Ben Harki", "And Mags", "And Finn")  # call does not work with name = "Ben Harki", keyword argument
# -----
# unpacking args from lists, tuples, or dictionaries
# dictioary needs keys that are the same names as the args
def printName(name1, name2, name3, name4):
  print(name1, name2, name3, name4)
# MAIN
args1 = [0, 11, 1]
print(list(range(*args1)))
args2 = [0, 11, 2]
print(list(range(*args2)))
args3 = {"name1":"Ben", "name2":"Mags", "name3":"Finn", "name4":"Adam"}
printName(**args3)
# -----
# function three accepts a function as a parameter
def print_num(num):
  print("hello", num)
def three(pfunc):
  num = 3
  pfunc(num)
# MAIN
p = print_num  # p and print_num are function references to the same function  
three(p)  
# -----
# function inside another function
def number():
  num = 3
  def print_num(num):
    print(num)
  print_num(num)
# MAIN
number()
# -----
# function returns another function
def number():
  num = 3
  def print_num(num):
    print(num)
  return print_num
# MAIN
pn = number()
pn(20)     # 20
# -----
# lambda's are small anonymous functions, made up of a single expression
# lambdas are like functions as objects, can be returned or passed as an argument
def binaryOp(x, y, operate):
  return operate(x, y)
def returnOp(x, y):
  one = 1   # returned lambda knows its enclosed function data, even when called outside returnOp (closure)
  return lambda x, y: x - y - one
# MAIN
print(binaryOp(1, 2, lambda x,y: x + y))  # 3
minus = returnOp(10, 5)    # lambdas can be named
print(minus(10, 5))  # 4   
print(minus(100, 50))  # 49


CLASS
# is compares memory locations of objects, but be careful with primitive like classes, like int
# in calls __eq__ in class, compares values
# can also use del to delete objects or delete its fields
class MyInt:
  def __init__(this, _i):
    this.i = _i
  def __str__(self):
    return f"{this.i}"
  def __eq__(this, other):
    return this.i == other.i
# MAIN
obj1 = MyInt(1)
obj2 = MyInt(1)
obj3 = MyInt(3)
obj3 = obj1   # points to obj1
obj4 = MyInt(4)
print(obj1 is obj2)  # false, since they are different objects
print(obj1 is obj3)  # true, both point to the same object
print(obj1 == obj2)  # true, have the same value
print(obj1 == obj4)  # false, have different values
# -----
# simple class, default constructor only initializes z, x and y are initialized by set methods
# has a doc string
class Point:
  """ This is a 2D point """
  def setX(self, _x):
    self.x = _x   # initializes the x attribute
  def setY(self, _y):
    self.y = _y   # initializes the y attribute
# MAIN
p = Point()   # default constructor does nothing, no default values for x and y
print(p)    # prints the refernce for the object, since no __repr__
# print(p.x)    # does not run, p.x is not declared
p.setX(1)
p.setY(2)
print(p.x) # 1
print(p.y) # 2
print(Point.__doc__)  # prints the class's doc string
print(p.__class__)    # prints info on p's class
# -----
# with field annotation, that does not do any allocation of x or strict typing, basically does nothing
# can name "self" anything, like "this" from C++
# methods from a class have attribute of __self__ and __func__
class MyInt:
  x: int    # no allocation, no initialization
  def __init__(this, _x):  
    this.x = _x  # x is initialized by constructor
  def __str__(this):
    return f"{this.x}" 
# MAIN
print(MyInt(1))
# -----
# use isinstance to enforce the type on a field
# using None is nice because it does nothing in a lot of built-in
class MyInt:
  x = None    # allocation, but initialized with value None  (its not static)
  def __init__(this, _x):  
    if(isinstance(_x, int)):  # enforces that only an int is added as a field
      this.x = _x  # x is initialized by constructor
  def __str__(this):
    return f"{this.x}"   # if this.x = None, it will print None, without any extra if statement 
# MAIN
print(MyInt(1))     # 1
print(MyInt(1.2))   # None
# -----
# the difference between "primitive-like" objects and normal objects
# without an overridden __str__ method, the location of the object is displayed on print 
class MyInt():
  i: int
  def __init__(this, _i):
    this.i = _i
# MAIN
x = 3
print("x = ", x)  # 3
m = MyInt(4)
print("m = ", m)   # memory location stored in m (m is a reference that has a mem location value)
print(hex(id(m)))  # same location as above using id
# -----
# another simple class with a method calling it own Class's method
# also a class method __str__ is written outside the class
# shows both ways to call a method: though an object, or through the class
def myString(this):   
  return f"({this.x}, {this.y})"
class Point:
  def __init__(this, _x, _y):
    Point.setX(this, _x)   # equiv to below
    this.setY(_y)          # equiv to above
  def setX(this, _x):
    this.x = _x
  def setY(this, _y):
    this.y = _y
  __str__ = myString  # binds it to this class, from outside the class
# MAIN
p = Point(3,4)
print(p)
# -----
# this __init__ is the constructor and overrides the default constructor Point()
# x and y can can be declared and initialized in the constructor, do not need None declarations
# you can use default values for params in __init__
# overrided Object methods: __init__, __repr__, __str__, __eq__
class Point:
  def setX(this, _x): this.x = _x
  def setY(this, _y): this.y = _y
  def getX(this): return this.x
  def getY(this): return this.y
  def __init__(this, _x, _y):   # overrides default constructor Point()
    this.x = _x
    this.y = _y
  def __repr__(this):  # used to be able to type "p" to see what it is in repr, also used in print()
      return f"({this.x}, {this.y})"  
  def __str__(this):  # used in print() for console output representation, print() will choose this over repr
      return f"({this.x}, {this.y})"
  def __eq__(this, rhs):   # overrides ==  # by default __eq__ that only checks the object locations
    return this.x == rhs.x and this.y == rhs.y
# MAIN
p = Point(1, 2)
print(p)
print(p.x)    # can access raw data, but shouldn't, should use p.getX()
p.setX(3)
print(p)  # (3, 2)
print(p.getX() + p.getY())  # 5
p1 = Point(3,2)
print(p == p1)    # true
print(id(p) == id(p1))  # false
print(vars(p))  # vars(p) is a dictionary of each of the obj's atr and their value
# -----
# class with a variable shared by the all objects of a class
# can change it with a class method or an external function
# fileds defined in __init__ are automatically per obj
# None also allocates space, but the value is None
class Name:
  n = "Ben Harki"  # like a static class field
  perObj = None      # this is not static, since its in __init__, even though it is initialized outside __init__
  def __init__(this):
    this.perObj = "XXX"   # makes perObj field per object instance
  def getN(this):
    return this.n 
  def changeN(this, name):   # changes static field via any object 
    Name.n = name
  def staticChangeN(name):   # changes static field via a static method
    Name.n = name  
  def __str__(this):
    return f"{this.n}, {this.perObj}"
def extChangeN(name):  # function, external to Name, that changes Name's static field
  Name.n = name
# MAIN
nm1 = Name()  
print(nm1)    # Ben Harki, XXX
nm2 = Name()  
print(nm2)    # Ben Harki, XXX
nm2.changeN("Mags")  # nm2 changes name for every obj
print(nm1)  # Mags, XXX
print(nm2)  # Mags. XXX
extChangeN("Finn")
print(nm1)  # Finn, XXX
print(nm2)  # Finn, XXX
Name.staticChangeN("Adam")  # calls class's static method
print(nm1)  # Adam, XXX
print(nm2)  # Adam, XXX
nm1.perObj = "Harki"    # only changes perObj field for nm1
print(nm1)  # Adam, Harki   
print(nm2)  # Adam, XXX
# -----
# anonymous object
class Name:
  def __init__(this, _name):
    this.name = str(_name)
  def __str__(this):
    return this.name
# MAIN
print((Name("Ben Harki")))
# -----
# classes can be defined in any scope
def add(i1:int, i2:int):
  class MyInt:
    def __init__(this, _i):
      this.i = _i
    def __str__(this):
      return f"{this.i}"
  return MyInt(i1 + i2)  # returns an anonymous object
# MAIN
print(add(3, 4))
# -----
# private field and private method via name mangling
# __i attribute is renamed _A__i in the class attribute list, similar for private method
class A:
  def __init__(this, i):
    this.__i = i
    this.__constrPrint()
  def __constrPrint(this):
    print("I'm only called in the constructor") 
a = A(1)
# print(a.__i)           # throws because __i is private
# a.__constrPrint()      # throws bc its private
# -----
# bundle attributes and methods on the fly
class OnTheFly: pass    # every object of this class must be manually created like this, since it has pass
a = OnTheFly()
a.name = "Ben Harki"
a.age = 10
a.i = 0
def counter(this):
  this.i += 1
def __str__(this):
  return f"{this.name}, {this.age}, {this.i}"
OnTheFly.counter = counter   # use class name
OnTheFly.__str__ = __str__
a.counter()
a.counter()
print(a)    # Ben Harki, 10, 2

INHERITANCE
# inheritance, sub class overrides superclass methods
# also calls superclass's method, with or without super()
# subclass can call superclass's distinct method, but superclass cannot call a subclass's distinct method
# force all attributes to be floats, otherwise they could be other classes, like OneDim
class OneDim:
  x : float
  def __init__(this, _x):
    this.x = float(_x)
  def __str__(this):
    return f"{this.x}"
  def add(this, rhs):   # distinct method
    this.x += float(rhs)  
class TwoDim(OneDim):   # if OneDim is in a different module, say Mod, then use "class TwoDim(Mod.OneDim):"
  y :float
  def __init__(this, _x, _y):   # overrides OneDim's constructor, but also calls it and extends it
    OneDim.__init__(this, _x)
    # super().__init__(_x)              # same as above line using super()
    # super(TwoDim, this).__init__(_x)  # this also works
    this.y = float(_y)
  def __str__(this):  # overrides OneDim's __str__
    return f"({this.x}, {this.y})"  # this.x is a OneDim field
# MAIN
p = TwoDim(3, 4)
print(p)  # (3, 4)
p.add(3)  # TwoDim obj calls OneDim distinct method
print(p)  # (6, 4)
# -----
# kind of like an abstract class in java
# "casts" rhs in add to be an IPoint, so subclass's can be used as a parameter in superclass's method
# also shows isinstance(), issubclass()
class IPoint:
  x : float
  y : float
  def __init__(this, _x, _y):
    this.x = float(_x)
    this.y = float(_y)
  def add(this, rhs):    
    rhs = IPoint(rhs.x, rhs.y)   # forces rhs to be an IPoint, or a subclass
    return IPoint(this.x + rhs.x, this.y + rhs.y)  # returns a new IPoint
  def __str__(this):
    return f"({this.x}, {this.y})"
  def override(this):
    return "in IPoint.override()"
class RotateYAxis(IPoint):    
  def __init__(this, _x, _y):
    _x = -_x
    IPoint.__init__(this, _x, _y)  
  def override(this):
    return f"in RotateYAxis.override(), x = {this.x}, y = {this.y}"
# MAIN
x = RotateYAxis(1, 2)
y = IPoint(3, 4)
print(x)
print(y)
z = x.add(y)    # subclass calls superclass method
z1 = y.add(x)   # superclass calls its method on a subclass obj
print(z)
print(z1)
print(x.override())
print(y.override())  
print(RotateYAxis.override(y))   # y is a superclass, calling a method that its subclass overrides 
print(isinstance(x, RotateYAxis))     # True
print(isinstance(x, IPoint))          # True, since x is in a a sublcass of IPoint
print(isinstance(y, RotateYAxis))     # False, since y is only the SuperClass IPoint
print(isinstance(y, IPoint))          # True
print(issubclass(RotateYAxis, IPoint))  # True
# -----
# printInt is like a virtual function
#  subclass's calls a superclass unique method that in turn a subclass's overrided method
# duck typing: does not look at the obj's type to determine if it has the right interface, just look at methods
#   the class is less important than the methods the object defines (quacks like a duck, then its a duck)
#   another example: all containers like list, dict, string, have __len__() method, so you can call len(container) 
class SuperInt:
  def __init__(this, _i):
    this.i = _i
  def printInt(this):
    print("in SuperInt:", this.i)
  def unique(this):
    this.printInt()     # depends on this object, could call  SubInt.printInt()
class SubInt(SuperInt):
  def printInt(this):        # virtual
    print("in SubInt:", this.i)
# MAIN
supi = SuperInt(0)   
subi = SubInt(1)     
supi.unique()    # in SuperInt: 0   # calls superclass version
subi.unique()    # in SubInt: 1     # calls subclass version
listInt = [supi, subi]
for l in listInt:   # since there is no strict typing, it automatically calls its class's method (duck typing)
  l.printInt()
# -----
# can make a method private to bypass the virtual nature of an overrided method
class SuperInt:
  def __init__(this, _i):
    this.i = _i
  def printInt(this):
    print("in SuperInt:", this.i)
    __printInt = printInt  # private version of a public method
  def unique(this):
    this.__printInt()     # depends on this object, could call  SubInt.printInt()
class SubInt(SuperInt):
  def printInt(this):        # virtual
    print("in SubInt:", this.i)
# MAIN
supi = SuperInt(0)   
subi = SubInt(1)     
supi.unique()    # in SuperInt: 0   # calls superclass version
subi.unique()    # in SuperInt: 1   # calls superclass version instead of subclass, compare to above, now not virtual
# -----
# multiple inheritance
# also name mangling, where the fields have __ prefixes
# this allows the field to be "private", so that they are hidden from other classes
# in this case it allows derived classes  to avoid name confusion from base class
class A:
  def __init__(this, i):
    this.__i = i
  def __str__(this):
    return f"{this.__i}"
class B:
  def __init__(this, i):
    this.__i = i    
  def __str__(this):
    return f"{this.__i}"
class AB(A, B):   
  def __init__(this, i):
    A.__init__(this, i + 1)
    B.__init__(this, i + 2)
    this.__i = i
  def __str__(this):
    return A.__str__(this) + B.__str__(this) + f"{this.__i}"
# MAIN
ab = AB(0) 
print(ab)    #120  
# -----
# multiple inheritance diamond problem, middle classes B and C have the same named method pong, so which is called from D?
# MRO: method resolution Order, can be seen calling __mro__ field form a class
# the order of method search is through MRO by default
class A:
  def __init__(this, i):
    this.__i = i
  def __str__(this):
    return f"{this.__i}"
  def ping(this):
    print("in A")
class B(A):
  def __init__(this, i):
    this.__i = i    
  def __str__(this):
    return f"{this.__i}"
  def pong(this):
    print("in B")
class C(A):   
  def __init__(this, i):
    this.__i = i
  def __str__(this):
    return f"{this.__i}"
  def pong(this):
    print("in C")
class D(B, C):   
  def __init__(this, i):
    this.__i = i
  def __str__(this):
    return f"{this.__i}"    
  def ping(this):
    super().ping()    # looks recursively in MRO until it finds A.ping(), since there is not one overrided in B or C    
  def pong(this):
    # super().pong()   # automatically picks B.pong() by MRO
    C.pong(this)       # forces the pick of C.pong()
# MAIN
d = D(0)
d.ping()  
d.pong()  # in B, # B.pong() if there is no impl in D  # if there is an impl in D, then either C.pong() or B.pong 
C.pong(d) # in C  # bypass MRO to C's manually using the class name
print(D.__mro__)  # shows, D, then B, then C, then A in terms of looking for a method
  
OPERATOR OVERLOADING
# TODO
# see The Python Language Reference > Data Model > 3.3 Special Method names

EXCEPTION
# catches the error, prints message, and continues program
x = 0
try:
    print( 1/x )
except:
    print('x is zero')    # replaced with pass, will print nothing 
# -----
# displays a built-in exception message
# can have multipe excepts for different exceptions
x = 0
try:
  print( 1/x )
except ValueError:    # displays ZeroDivisionError
  pass
except:   # any other exception
  pass
# -----
# force a custom error message
raise ValueError("incorrect value")
# -----
# inherit the Python exception class, and use a custom error message
class CustomError(Exception): # inherit from Exception
  pass
raise CustomError('my message here')    # shows my message as a Python exception
# -----
# handle by printing the Exception message
try:
  aneg = 1/0
except Exception as e:
  print(e)

ITERATOR, GENERATORS, AND GENERATOR EXPRESSIONS
# built-in types with an iterator
list1 = [0, 1]
listIt = iter(list1)
print(next(listIt))
print(next(listIt))
#  print(next(listIt))  # throws StopIteration exception, no more elements in list
# -----
# define a custom iterator by overriding __iter__() and __next__()
# these are called in a for in loop
class MyList:
  def __init__(this, _l):
    this.l =_l
    this.length = len(_l) 
    this.index = -1
  def __iter__(this):
    return this
  def __next__(this):
    if(this.index == this.length - 1):
      raise StopIteration
    this.index += 1
    return this.l[this.index]
# MAIN
_raw = [0, 1, 2, 3, 4]
mylist = MyList(_raw)
for l in mylist:
  print(l)
# -----
# generator function and a generator expression in a method
# generators create iterators, like range()
# __iter__  and __next__ are automatically created for the for-in loop
# also saves the state of the next and which statement was last executed
# also automatically raises the StopIteration exception
class MyList:
  def __init__(this, _l):
    this.l =_l
    this.length = len(_l)
  def getLength(this):
    return this.length
  def get(this, i):
    return this.l[i]
  def gen(this):       # a generator expression returned from a method
    return (this.get(i) for i in range(this.getLength()))  # a generator expression 
def generator(mylist):  # simple function, unlike an iterator
  for i in range(mylist.getLength()):
    yield mylist.get(i)   # yield returns data for a generator
# MAIN
mylist = MyList([0,1,2])
for m in generator(mylist):  # using the generator function
  print(m)
for elem in mylist.gen():
  print(elem)
# -----
# generator expression
# like a list comprehension but with ()
# designed for situations where the generator is used right way
s = sum(i for i in range(10))
print(s)
l = list(i*i for i in range(10))
print(l)
a = (i for i in range(10))   # this is a saved generator
print(a)  # generator reference
for ai in a:
  print(ai)