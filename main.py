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
