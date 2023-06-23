# this file, if run as a a standalone module, when __name__=='main', will call the script
# if its imported it only loads the f() function and does not call the script
# > python module_and_script.py  #  runs the script

def f():
  print("Hi")

# could also call it a main function
if __name__=='__main__':
  # test f()
  print("Only runs when this module is run on its own")
  print("this is not called if the module is imported into another")
  f() 

