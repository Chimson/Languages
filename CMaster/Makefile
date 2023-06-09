# need a text editor with size 4 tabs

######## USED FOR SEPERATE COMPILATION DEMONSTRATION ######## 
# does not create .o's, seperately compiles, generates exec
no_obj:
	gcc module1.c modules_main.c -o modules

# generates seperate .o's, no exec	
obj:
	gcc -c module1.c modules_main.c
	
# generates exec from o's 
from_obj:	
	gcc module1.o modules_main.o -o modules
	
#only update module1.c
mod1:	
	gcc -c module1.c	# only compiles one of the modules
	gcc module1.o modules_main.c -o modules

# force compile one at a time
seperate:
	gcc -c module1.c
	gcc -c modules_main.c
	gcc module1.o modules_main.o -o modules # link o's to finish compilation

run:
	./modules
	
###############################################################
# SIMPLE MAKEFILE	
SRC = module1.c modules_main.c
OBJ = module1.o modules_main.o   # for dependency
PROG = modules

# $ make obj first, then $ make modules, will to check for dependencies to avoid
# unnecessary recompilation of unchanged files

# if objs change link executable again by command
$(PROG): $(OBJ)			
	gcc $(OBJ) -o $(PROG)

# if src file changes, recompile obj files
$(OBJ): $(SRC)

################################################################
	
clean:
	rm -f module1.o modules_main.o modules
