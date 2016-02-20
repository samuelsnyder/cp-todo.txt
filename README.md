# cp-todo.txt
Add-on for todo.sh for copying a line from one file in the todo directory to another.

# Usage

The syntax of this command is configurable. On line 12, the variable `CP_DEST_FIRST` is set, by default to `0`, setting the usage to: 

`todo.sh cp ITEM# SOURCE [DEST]`

Setting `CP_DEST_FIRST` equal to `1` sets the usage to:

`todo.sh cp ITEM# DEST [SOURCE]`

In both cases, the default value for the optional file is `todo.txt`.

