#ifndef CUSTOM_H
#define CUSTOM_H

PyObject* builtin_prod_impl(PyModuleDef *module, PyObject *iterable, PyObject *start);
PyObject* builtin_prod(PyModuleDef *module, PyObject *args);

static const char builtin_prod_doc[] = 
"prod($module, iterable, start=1, /)\n" 
"--\n" 
"\n" 
"Return the product of a \'start\' value (default: 1) plus an iterable of numbers\n" 
"\n" 
"When the iterable is empty, return the start value.\n" 
"This function is intended specifically for use with numeric values and may\n" 
"reject non-numeric types.";

#define BUILTIN_PROD_METHODDEF    \
    {"prod", (PyCFunction)builtin_prod, METH_VARARGS, builtin_prod_doc},

#endif
