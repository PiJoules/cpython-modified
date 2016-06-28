# Python program flow

## Programs/pyhon.c

### Program entry point.
Continues to `Py_Main` in  `Modules/main.c`.

The program will not contine after Py_Main if running python shell.

## Modules/main.c

### Py_Main
- If running a file, continue to `run_file` in `Modules/main.c`.

### run_file
- `Py_Initialize` in `Python/pylifecycle.c`
  - [This initializes the table of loaded modules (sys.modules), and creates the fundamental modules __builtin__, __main__ and sys.](https://docs.python.org/2/c-api/init.html#c.Py_Initialize)
Continue to `PyRun_AnyFileExFlags` in `Python/pythonrun.c`.

## Python/pythonrun.c

### PyRun_AnyFileExFlags
- PyRun_SimpleFileExFlags
  - Continue to `PyRun_SimpleFileExFlags` in `Python/pythonrun.c`
- PyRun_InteractiveLoop
  - Running shell

### PyRun_SimpleFileExFlags
- The __main__ module is added here which contains all builtin utilities.
  - `m = PyImport_AddModule("__main__")`
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

### PyEval_EvalFrameEx
This contains the main while loop (actually it's a for(;;) loop) that runs instructions
based on the opcode. The opcodes are declared in `Include/opcode.h`.

It is here where the actual code is interpretted and the final return code is propogated back up the chain.

### call_function
The main function that does most of the work when CALL_FUNCTION opcode is found.

## Python/import.c

### PyImport_AddModule
Add a module from a string name.
- `PyUnicode_FromString` in `Objects/unicodeobject.c`
  - Creates unicode python object (usincode string esentially)
- `PyImport_AddModuleObject` in `Python/import.c`

### PyImport_AddModuleObject
```c
/* Get the module object corresponding to a module name.
   First check the modules dictionary if there's one there,
   if not, create a new one and insert it in the modules dictionary.
   Because the former action is most common, THIS DOES NOT RETURN A
   'NEW' REFERENCE! */
```
- `PyImport_GetModuleDict` in `Python/import.c`
- `PyDict_GetItemWithError`

## Python/pylifecycle.c

### Py_Initialize
This initializes the table of loaded modules (sys.modules), and creates the fundamental modules __builtin__, __main__ and sys.

Continue to `Py_InitializeEx` in `Python/pylifecycle.c`

### Py_InitializeEx
Continue to `_Py_InitializeEx_Private` in `Python/pylifecycle.c`.

### _Py_InitializeEx_Private
- `_PyBuiltin_Init` in `Python/bltinmodule.c`
  - Initialize builtin modules.


## Python/bltinmodule.c

### _PyBuiltin_Init
Initialize builtin functions

### builtin_methods
Array containing all PythonDefs for builtin functions that aren't constructors/initializers for types.



## Include/object.h
- `PyObject` definition

## Include/opcode.h
- Opcode macro declarations

## Python/opcode_targets.h
- Opcode targets organized into a giant lookup table.


