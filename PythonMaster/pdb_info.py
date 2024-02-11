
# python pdb
in your file:
	import pdb   # at top
	pdb.set_trace()  # where to begin debugging
	
(pdb)
h   # commands
l .	# list nearby lines of code
b file.py:68  # insert breakpoint
c   # continue
n, s, r  # next, step into, return from
display var

# run the pdb module script on your file
> python -m pdb myfile.py

# Here are some commands you can use in pdb to help debug your program
# (pdb) indicates that you are in the pdb debugger
# -> points to current line of code, just before executing it
# assume q1 and x are objs defined in source code
'''
(pdb) h     # lists the commands 
(pdb) l     # shows source code around the current line, can move down in further calls
(pdb) l .   # shows source code only around the current line
(pdb) h l   # shows info on the l command
(pdb) b 45  # adds a breakpoint at line 45 in source code
(pdb) b     # show the list of set breakpoints
(pdb) b QueueWithIter.enqueue    # adds a breakpoint at the beginning of method in class
(pdb) c   # continue executing code until hit breakpoint
(pdb) n   # execute current line of code, then point to the next line (does not step into function)
(pdb) p q1  # print q1 reference
(pdb) print(q1)   # execute the normal print expression, printing obj's __str__
(pdb) s   # step into the current function/method
(pdb) r   # execute until function returns
(pdb) display x   # set display on the obj, once its defined, shows it each time it changes
(pdb) display     # shows all objs that have been previously set
(pdb) display print(q1)   # will display the print expression() in the same way
(pdb) undisplay x  # unsets the display obj
(pdb) undisplay   # unsets all display objs
(pdb) clear 1   # clears the first breakpoint
(pdb) clear     # clears all breakpoints
(pdb) restart   # restart the debugger, keeping the breakpoints
(pdb) quit      # quit the debugger
'''