# Python program flow

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


