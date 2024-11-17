# Python C API Learning

This repository is a hands-on project to learn the Python C API by creating bindings for a simple C++ class. The focus is on exposing C++ code to Python using the Python C API and building a Python C extension.

## Objective

The primary goal of this project is to gain practical experience in:
- Creating Python C extensions
- Wrapping C++ classes with Python C API
- Memory management and error handling in C extensions
- Understanding how Python interacts with native C/C++ code

### Features

- **C++ Circuit Class**: A simple C++ class that models a circuit with nodes connected by resistors.
- **Python Bindings**: Exposes the C++ class methods to Python using the Python C API.
- **Example Methods**:
  - `connect(u, v, resistance)`: Connect two nodes with a specified resistance.
  - `calculate_total_resistance()`: Calculate and return the total resistance of the circuit.

## Build Guide (Ubuntu)

Follow the steps below to build and install the Python C extension that wraps the C++ `Circuit` class.

First, clone the repository to your local machine:

```bash
git clone https://www.github.com/khobaib529/python-c-api-learning.git
cd python-c-api-learning
```

Create a virual environment:
```bash
python3 -m venv venv
source venv/bin/activate
```

Install dependencies:
```bash
pip3 install -r requirements.txt
```

To build the C extension, run the following command from the root directory of the repository:

```bash
python3 setup.py build_ext --inplace
```

This command compiles the C++ code and generates the Python bindings directly in the current directory.

Run the main.py to see the output:
```bash
python3 main.py
```
### Example Usage

Once the module is built and installed, you can use the `Circuit` class in Python like this:

```python
from CircuitResistanceSolver import Circuit

# Create a Circuit instance with 9 nodes (0 to 8)
my_circuit = Circuit(9)

# Connect nodes with specified resistances (resistance is in Ohms)
my_circuit.connect(0, 1, 2)   # Connect node 0 to node 1 with 2 Ohms
my_circuit.connect(1, 2, 6)   # Connect node 1 to node 2 with 6 Ohms
my_circuit.connect(2, 3, 2)   # Connect node 2 to node 3 with 2 Ohms
my_circuit.connect(3, 4, 10)  # Connect node 3 to node 4 with 10 Ohms
my_circuit.connect(3, 7, 20)  # Connect node 3 to node 7 with 20 Ohms
my_circuit.connect(3, 8, 20)  # Connect node 3 to node 8 with 20 Ohms
my_circuit.connect(4, 5, 10)  # Connect node 4 to node 5 with 10 Ohms
my_circuit.connect(4, 6, 20)  # Connect node 4 to node 6 with 20 Ohms
my_circuit.connect(4, 7, 20)  # Connect node 4 to node 7 with 20 Ohms
my_circuit.connect(5, 6, 10)  # Connect node 5 to node 6 with 10 Ohms
my_circuit.connect(6, 7, 10)  # Connect node 6 to node 7 with 10 Ohms
my_circuit.connect(7, 8, 10)  # Connect node 7 to node 8 with 10 Ohms

total_resistance = my_circuit.calculate_total_resistance()
print(f"Total Resistance: {total_resistance} Ohm")
```
