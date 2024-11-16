#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include <iostream>
#include "circuit.h"  // Include the C++ Circuit class header

// Structure to hold the Circuit object for Python binding
typedef struct {
    PyObject_HEAD
    Circuit* circuit;  // Pointer to the C++ Circuit instance
} PyCircuit;

// Constructor for the Circuit class
static int PyCircuit_init(PyCircuit* self, PyObject* args) {
    int V;
    if (!PyArg_ParseTuple(args, "i", &V)) {
        return -1;  // Error parsing arguments
    }
    self->circuit = new Circuit(V);  // Allocate a new Circuit instance
    return 0;
}

// Destructor for the Circuit class
static void PyCircuit_dealloc(PyCircuit* self) {
    delete self->circuit;  // Free the allocated Circuit instance
    Py_TYPE(self)->tp_free((PyObject*)self);  // Free the Python object itself
}

// Method to connect two nodes
static PyObject* PyCircuit_connect(PyCircuit* self, PyObject* args) {
    int u, v;
    double resistance;
    if (!PyArg_ParseTuple(args, "iid", &u, &v, &resistance)) {
        return NULL;  // Error parsing arguments
    }
    self->circuit->connect(u, v, resistance);  // Call the connect method on the Circuit instance
    Py_RETURN_NONE;  // No return value
}

// Method to calculate total resistance
static PyObject* PyCircuit_calculate_total_resistance(PyCircuit* self) {
    try {
        double result = self->circuit->calculate_total_resistance();  // Calculate total resistance
        return Py_BuildValue("d", result);  // Return result as a Python float
    } catch (const std::runtime_error& e) {
        PyErr_SetString(PyExc_RuntimeError, e.what());  // Handle exceptions and set Python error
        return NULL;  // Return NULL on error
    }
}

// Method definitions for the Circuit class
static PyMethodDef PyCircuit_methods[] = {
    {"connect", (PyCFunction)PyCircuit_connect, METH_VARARGS, "Connect two nodes with given resistance."},
    {"calculate_total_resistance", (PyCFunction)PyCircuit_calculate_total_resistance, METH_NOARGS, "Calculate total resistance."},
    {NULL}  // Sentinel
};

// Type definition for the Circuit class
static PyTypeObject PyCircuitType = {
    PyVarObject_HEAD_INIT(NULL, 0)
    "CircuitResistanceSolver.Circuit",               // tp_name (Module.Class)
    sizeof(PyCircuit),               // tp_basicsize
    0,                               // tp_itemsize
    (destructor)PyCircuit_dealloc,   // tp_dealloc
    NULL,                            // tp_print
    NULL,                            // tp_getattr
    NULL,                            // tp_setattr
    NULL,                            // tp_reserved
    NULL,                            // tp_repr
    NULL,                            // tp_as_number
    NULL,                            // tp_as_sequence
    NULL,                            // tp_as_mapping
    NULL,                            // tp_hash
    NULL,                            // tp_call
    NULL,                            // tp_str
    NULL,                            // tp_getattro
    NULL,                            // tp_setattro
    NULL,                            // tp_as_buffer
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,  // tp_flags
    "Circuit objects",               // tp_doc
    NULL,                            // tp_traverse
    NULL,                            // tp_clear
    NULL,                            // tp_richcompare
    0,                               // tp_weaklistoffset
    NULL,                            // tp_iter
    NULL,                            // tp_iternext
    PyCircuit_methods,               // tp_methods
    NULL,                            // tp_members
    NULL,                            // tp_getset
    NULL,                            // tp_base
    NULL,                            // tp_dict
    NULL,                            // tp_descr_get
    NULL,                            // tp_descr_set
    0,                               // tp_dictoffset
    (initproc)PyCircuit_init,        // tp_init
    0,                               // tp_alloc
    PyType_GenericNew,               // tp_new
};

// Module definition
static struct PyModuleDef CircuitResistanceSolver_module = {
    PyModuleDef_HEAD_INIT,
    "CircuitResistanceSolver",   // Name of the module (used in import statement)
    "A module for calculate total resistance of a circuit given by a directed graph",  // Module documentation
    -1,           // Size of per-interpreter state of the module
    NULL          // Methods (none for now)
};

// Module initialization function
PyMODINIT_FUNC PyInit_CircuitResistanceSolver(void) {
    PyObject *m;

    // Ensure the PyCircuit type object is ready
    if (PyType_Ready(&PyCircuitType) < 0) {
        return NULL;
    }

    // Create the module
    m = PyModule_Create(&CircuitResistanceSolver_module);
    if (m == NULL) {
        return NULL;
    }

    // Add the Circuit type object to the module
    Py_INCREF(&PyCircuitType);
    PyModule_AddObject(m, "Circuit", (PyObject *)&PyCircuitType);

    return m;
}
