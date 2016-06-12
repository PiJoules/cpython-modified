#include "Python.h"
#include "custom.h"

PyObject* builtin_prod(PyModuleDef *module, PyObject *args){
    PyObject *return_value = NULL;
    PyObject *iterable;
    PyObject *start = NULL;

    if (!PyArg_UnpackTuple(args, "prod", 1, 2, &iterable, &start)){
        return return_value;
    }
    return builtin_prod_impl(module, iterable, start);
}

PyObject* builtin_prod_impl(PyModuleDef *module, PyObject *iterable, PyObject *start){
    PyObject *result = start;
    PyObject *temp, *item, *iter;

    iter = PyObject_GetIter(iterable);
    if (iter == NULL)
        return NULL;

    if (result == NULL) {
        result = PyLong_FromLong(1);  // Initial value of 1
        if (result == NULL) {
            Py_DECREF(iter);
            return NULL;
        }
    } else {
        /* reject string values for 'start' parameter */
        if (PyUnicode_Check(result)) {
            PyErr_SetString(PyExc_TypeError,
                "prod() can't find product of strings");
            Py_DECREF(iter);
            return NULL;
        }
        if (PyBytes_Check(result)) {
            PyErr_SetString(PyExc_TypeError,
                "prod() can't find product of bytes");
            Py_DECREF(iter);
            return NULL;
        }
        if (PyByteArray_Check(result)) {
            PyErr_SetString(PyExc_TypeError,
                "prod() can't find product of bytearray");
            Py_DECREF(iter);
            return NULL;
        }
        Py_INCREF(result);
    }

    /**
     * Fast Multiplication (based off the builtin implementation's Fast Addition)
     * was not included since the builtin one has a fast check for overflow by checking
     * the sign bit, but the only way I can actually think of checking overflow when
     * multiplying is by dividing the result by the dividend, and comparing it
     * against the divisor (assuming the divident is not 0).
     * Since the purpose of fast multiplication is to perform operations in C space,
     * performing division for each multiplication could be costly. This is something
     * that should be tested, but I will not be including it here for now.
     */

    for(;;) {
        item = PyIter_Next(iter);
        if (item == NULL) {
            /* error, or end-of-sequence */
            if (PyErr_Occurred()) {
                Py_DECREF(result);
                result = NULL;
            }
            break;
        }
        temp = PyNumber_Multiply(result, item);  // This function handles overflow
        Py_DECREF(result);
        Py_DECREF(item);
        result = temp;
        if (result == NULL)
            break;
    }
    Py_DECREF(iter);
    return result;
}
