# import MySum.py module that contains mySum() function
import MySum
mySum = MySum.mySum  # save locally in Test.py

msg = "Hi"
print(msg)
print(max(1,2))
print(MySum.mySum(1,2))
print(mySum(4,5))
print(MySum.GLOBAL)   