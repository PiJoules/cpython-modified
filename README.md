# Python version 3.6.0 alpha 1

Python 3.x is a new version of the language, which is incompatible with the
2.x line of releases.  The language is mostly the same, but many details,
especially how built-in objects like dictionaries and strings work,
have changed considerably, and a lot of deprecated features have finally
been removed.


## Build Instructions
On Linux, the source and build will be in to separate dirs, and the executable will not
by installed gloablly, but stay in the build dir:
```sh
$ cd /path/to/python/build/dir  # Goto build dir (not source)
$ /path/to/python/src/dir/configure  # Construct makefile in build dir
$ make all  # Make in build dir
```

To create a debug version, the above steps can be done, but adding `--with-debug` to
the configure command as a flag:
```sh
$ /path/to/python/src/subdir/configure  --with-debug
```

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

