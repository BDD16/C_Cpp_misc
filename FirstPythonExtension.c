#include <Python.h>

// Function 2: A C fibonacci implementation
// this is nothing special and looks exactly
// like a normal C version of fibonacci would look
// recursively of course
int Cfib(int n)
{
    if (n < 2)
        return n;
    else
        return Cfib(n-1)+Cfib(n-2);
}

// a non recursive, so in this particular case a faster
// implementation of the fibbonacci sequence
long CFastFib(int n )
{
  unsigned long previous = 0;
  unsigned long current = 1;
  unsigned long extra = 0;
  unsigned long result = 0;

  for(int i = 0; i < n; i += 1){
    if( i == 0){
      result = previous + current;
      current = result;
      previous = current;
    }
    else{
      extra = current + previous;
      previous = current;
      current = extra;
    }

  }

  return extra;
}

char[] Shelly_The_Snail(int length, char flags){
  //Auto Generate a arbitrary code based on given flags
  //
  /****************************************************************************
       +_+_+_+_+_+_+
    | ARCH | OP | OS |
       +_+_+_+_+_+_+

    :ARCH: Architecture 4 bits 1000, 0100, 0010, 0001 will be supported
    :OP: Optimizations 2 bits 00 and 10 will be supported
    :OS: Operating System of Shell Code 2 bits 00 and 10 will be supported

    #TODO: Everything, leaving as a stub for now, in the future will start
    implementings
  *****************************************************************************/
  //
  MIPS = ^flags &(~ 0x8000) // MIPS

  xEigtySix = ^flags &(~ 0x8000) // MIPS

  xSixtyFour = ^flags &(~ 0x8000) // MIPS

  ARM = ^flags &(~ 0x8000) // MIPS

}
// Our Python binding to our C function
// This will take one and only one non-keyword argument
static PyObject* fib(PyObject* self, PyObject* args)
{
    // instantiate our `n` value
    int n;
    // if our `n` value
    if(!PyArg_ParseTuple(args, "i", &n))
        return NULL;
    // return our computed fib number
    return Py_BuildValue("i", Cfib(n));
}

// Our Python binding to our C function
// This will take one and only one non-keyword argument
static PyObject* FastFib(PyObject* self, PyObject* args)
{
    // instantiate our `n` value
    int n;
    // if our `n` value
    if(!PyArg_ParseTuple(args, "i", &n))
        return NULL;
    // return our computed fib number
    return Py_BuildValue("l", CFastFib(n));
}

// Function 1: A simple 'hello world' function
static PyObject* helloworld(PyObject* self, PyObject* args)
{
    printf("Hello World\n");
    return Py_None;
}

// Our Module's Function Definition struct
// We require this `NULL` to signal the end of our method
// definition
static PyMethodDef myMethods[] = {
    { "helloworld", helloworld, METH_NOARGS, "Prints Hello World" },
    {"FastFib", FastFib, METH_VARARGS, "fibonacci Test Function Fast"},
    {"fib", fib, METH_VARARGS, "fibonacci Test function"},
     {NULL, NULL, 0, NULL }
};

// Our Module Definition struct
static struct PyModuleDef myTechTestModule = {
    PyModuleDef_HEAD_INIT,
    "myTechTestModule",
    "Test Module",
    -1,
    myMethods
};

// Initializes our module using our above struct
PyMODINIT_FUNC PyInit_myTechTestModule(void)
{
    return PyModule_Create(&myTechTestModule);
}
