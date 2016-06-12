# Python version 3.6.0 alpha 1

My fork of the latest version of python at the time. This repo serves as a playground for me
to get more familiar with the python source code.

This code may be edited differently than the original source, and is most likely at least
500 commits behind the moment I cloned it.

This will not run on Windows (and maybe Mac) since I may have removed some code
associated with a specific OS. I do not care about running this on Windows or Mac. This
is just a learning tool for me and I only care if I can play with it on Linux.

Various notes about the source I took along the way are in `notes/`.

## Build Instructions
To create a local copy of the python executable:
```sh
$ mkdir build  # Create and build in dedicated directory
$ cd build
$ ../configure  # Configure Makefile
$ make  # make normally
$ ./python  # RUn the local executable
Python 3.6.0a0 (default, Jun 11 2016, 22:44:48) 
[GCC 4.8.4] on linux
Type "help", "copyright", "credits" or "license" for more information.
>>>
```
I would not recommend installing globally.

To clean:
```sh
$ make clean
```

To create an optimized version of python:
```sh
$ make profile-opt
```
This will rebuild the interpreter executable using Profile
Guided Optimization (PGO).


## Adding custom builtin functions
I have figured out how to add custom functions to the python builtin namespace.
I don't mean that I added something to the global namespace (these are 2 different things).
I mean I can implement my own function in the c source code, and have it available in
python space without having to import anything along side [these builtin functions](https://docs.python.org/3/library/functions.html#built-in-functions).

For this example, I implemented a simple function `prod()` which is like `sum()`, but instead
takes the product of all numbers in an iterable (or at least objects that implement `__mult__`). To see it in action, you will need to rebuild the makefile and the executable again, but
with the `USE_CUSTOM_BUILTINS` flag set.
```sh
$ ../configure CFLAGS="-DUSE_CUSTOM_BUILTINS"
$ make
$ ./python ../CustomTests/test_prod.py  # Test that prod() works properly
```


## Debug prints
To enable all the debug statements I left in this code, use the `DEBUG` flag:
```sh
$ ../configure CFLAGS="-DDEBUG"
$ make
$ ./python ../CustomTests/test_prod.py  # Test that prod() works properly
```


## Tests
Inside the build directory:
```sh
$ make test
```


## Profile Guided Optimization

PGO takes advantage of recent versions of the GCC or Clang compilers.
If ran, the "profile-opt" rule will do several steps.

First, the entire Python directory is cleaned of temporary files that
may resulted in a previous compilation.

Then, an instrumented version of the interpreter is built, using suitable
compiler flags for each flavour. Note that this is just an intermediary
step and the binary resulted after this step is not good for real life
workloads, as it has profiling instructions embedded inside.

After this instrumented version of the interpreter is built, the Makefile
will automatically run a training workload. This is necessary in order to
profile the interpreter execution. Note also that any output, both stdout
and stderr, that may appear at this step is supressed.

Finally, the last step is to rebuild the interpreter, using the information
collected in the previous one. The end result will be a Python binary
that is optimized and suitable for distribution or production installation.

