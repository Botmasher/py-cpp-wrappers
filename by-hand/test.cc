#include "test.h"

// 0. write C/C++ function
char* test(char* what) {
	return what;
}

// 1. write Python-callable function returning string as obj
static PyObject* test_wrapper(PyObject* self, PyObject* args) {
  char* input;
  char* result;
  PyObject* pythonized_result;

  /* parse args to tell Python that:
  		- the C++ func takes one arg
  		- the argument is type "s" for string (versus "ss" strings, "si" string and integer, ...)
  		- NULL return when expecting PyObject* will throw error within ParseTuple just to pass error up stack
  		- 
   */
  if (!PyArg_ParseTuple(args, "s", &input)) {
    return NULL;
  }

  // turn return val into py object
  pythonized_result = PyString_FromString(test_func(input));
  /*
  	A "new reference" so the PyString_FromString returns reference count 1 for the one created object
  		- if it were a "borrowed reference" like to list or dict we would need to Py_INCREF (if added) ot Py_DECREF (if deleted)
  	
  	Tips from http://intermediate-and-advanced-software-carpentry.readthedocs.io/en/latest/c++-wrapping.html:
  		1. if you receive a Python object from the Python API, you can use it within your own C code without INCREFing it.
			2. if you want to guarantee that the Python object survives past the end of your own C code, you must INCREF it.
			3. if you received an object from Python code and it was a new reference, but you don’t want it to survive past the end of your own C code, you should DECREF it.
			4. if you wanted to return None, by the way, you can use Py_None. Remember to INCREF it!
	 */
  free(result);

  return pythonized_result;
}

// 2. register Python-callable function within module's symbol table
static PyMethodDef HelloMethods[] = {
	{ "test", test_func, METH_VARARGS, "Test return string" },
	{ NULL, NULL, 0, NULL }
};

// 3. write init function for this module (required for all extension modules)
DL_EXPORT(void) inithello(void) {
	Py_InitModule("hello", HelloMethods);
}

// 4. write setup.py (see that file)
