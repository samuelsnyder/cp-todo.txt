#! /usr/bin/env bash

# samuel.l.snyder@gmail.com
# addon to todo.sh
# copies item from one file in todo directory to another 

# CONFIG
# The arg order for the todo.sh action 'mv' is the opposite
# of what one would type into the shell.
# For this reason, one may use the todo.sh arg order for 'cp'
# or use the arg order of the 'cp' shell command.

CP_DEST_FIRST=0 # if 1, usage is 'cp #ITEM DEST [SOURCE]' 
		# otherwise, 'cp #ITEM SOURCE [DEST]'
		# in both cases above the default value for 
		# the optional arg is the todo file. 

if [[ $CP_DEST_FIRST = "1" ]] ; then
	errmsg="cp ITEM# DEST [SOURCE]"
else
	errmsg="cp ITEM# SOURCE [DEST]"
fi

shift

if [[ $1 = "usage" ]]; then
	cat <<-EndActionHelp
		    $errmsg
		     Copies text at line number  ITEM# from source file SOURCE to file
		     DEST. Both files must be in todo dir.  Default file is the todo.txt file.
	EndActionHelp
fi	

# check if first arg is numeric
[[ ! $1 =~ ^[0-9]+$ ]] && die Usage: $errmsg

# check if second arg is a file in todo directory
[[ ! -n $2 ]] && die Usage: $errmsg
[[ ! -r $TODO_DIR/$2 ]] && echo "Unable to read $TODO_DIR/$2" && exit

# if third arg, check that it is a file in todo directory
[[ -n $3 && ! -r $TODO_DIR/$3 ]] && echo "Unable to read $TODO_DIR/$3" && exit

# assign destination and source
if [[ $CP_DEST_FIRST = "1" ]] ; then
	# use destination-first arg order
	cp_dest=$2
	cp_source=${3:-$TODO_FILE}
else
	# use source-first arg order
	cp_source=$TODO_DIR/$2
	cp_dest=${3:-$TODO_FILE}
	cp_dest=${cp_dest##*/}

fi

# get todo 
getTodo $1 $cp_source

# add to destination file
$TODO_FULL_SH command addto $cp_dest "$todo"`
