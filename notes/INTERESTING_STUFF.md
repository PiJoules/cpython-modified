# Interesting stuff I found while exploring the source

## Builtin functions
All builtin functions are stated in Python/bltinmodule.c.
The the static `builtin_methods` PythonDef array contains the functions shown in https://docs.python.org/3/library/functions.html.
The rest are constructors/initializers for types which are in _PyBuiltin_Init in the bottom of Python/bltinmodule.c.


## The giant switch statement
As expected, the way all the instructions are executed is by checking the opcode in
a switch statement. There are approximately ~130 opcodes that are checked against, some of which
are far apart from each other (there is a gap in opcodes from 31-50 as shown in Python/opcode_targets.h).

### If-Else ladder
If-else ladder comparing a variable to some constant, then executing some instruction(s)
for each branch.
```c
if (x == 0){  // Or some constant. Each condition in this ladder compares against a constant integer.
    z = 0;  // Or some instr...
}
else if (x == 1){
    printf("1\n");
}
else if (x == 2){
    y = 10;
}
...  // More branches
else {
    z = -1;
}
```

As pseudo-assembly code
```
MOVE x, R7
COMPARE 0, R7
BRANCH_IF_EQUAL C1  # Case 1
COMPARE 1, R7
BRANCH_IF_EQUAL C2  # Case 2
...
COMPARE N, R7
BRANCH_IF_EQUAL CN  # Case N
...
# Default case (else branch)
MOVE -1, z
JUMP AFTER_LADDER
C1:
...  # Logic for first case
JUMP AFTER_LADDER
C2:
...  # Logic for second case
JUMP AFTER_LADDER
...
AFTER_LADDER:
# End of ladder
```

### Resources
- [If-else/switch in assembly](http://www.eventhelix.com/RealtimeMantra/Basics/CToAssemblyTranslation3.htm#.V1wzIO1VK1E)

## Other stuff
- Gotos are used every now and then. I have nothing against this.
- Compiled using C90/ANSI C/ISO C/Standard C standards
  - All variables must be delcared first in a function. I did not know about this since
    I have always used C99/C11.
