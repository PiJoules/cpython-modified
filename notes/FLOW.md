# Python program flow

Left off in Python/ceval.c, _PyEval_EvalCodeWithName. Checking out PyObject definition in Include/object.h.

## Programs/pyhon.c

### Program entry point.
Continues to `Py_Main` in  `Modules/main.c`.

The program will not contine after Py_Main if running python shell.

## Modules/main.c

### Py_Main
- If running a file, continue to `run_file` in `Modules/main.c`.

### run_file
Continue to `PyRun_AnyFileExFlags` in `Python/pythonrun.c`.

## Python/pythonrun.c

### PyRun_AnyFileExFlags
- PyRun_SimpleFileExFlags
  - Continue to `PyRun_SimpleFileExFlags` in `Python/pythonrun.c`
- PyRun_InteractiveLoop
  - Running shell

### PyRun_SimpleFileExFlags
- not maybe_pyc_file
  - Continue to `PyRun_FileExFlags` in `Python/pythonrun.c`

### PyRun_FileExFlags
Continue to `run_mod` in `Python/pythonrun.c`

### run_mod
- PyAST_CompileObject
- PyEval_EvalCode
  - Continue to `PyEval_EvalCode` in `Python/ceval.c`

## Python/ceval.c

### PyEval_EvalCode
Continue to `PyEval_EvalCodeEx` in `Python/ceval.c`

### PyEval_EvalCodeEx
Continue to `_PyEval_EvalCodeWithName` in `Python/ceval.c`

### _PyEval_EvalCodeWithName
Continue to `PyEval_EvalCodeEx` in `Python/ceval.c`

### PyEval_EvalCodeEx
This contains the main while loop (actually it's a for(;;) loop) that runs instructions
based on the opcode.

The opcodes are declared in `Include/opcode.h`.

## Include/object.h
- `PyObject` definition

## Include/opcode.h
- Opcode macro declarations


