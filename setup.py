from setuptools import setup, Extension

module = Extension('CircuitResistanceSolver', sources=['CircuitResistanceSolverModule.cpp'])

setup(
    name='CircuitResistanceSolver',
    version='1.0',
    ext_modules=[module],
)
