# Qubit-Simulator

## Plan
We have designed an **MVP** (Minimal Viable Product) for a Quantum Computer Simulation.
This project simulate a multi-qubit system of 5 Qubits on consumer-grade Laptops.
However, this number can extended considering the limitation of memory.


## Progress

### Classes / Structure

* [x] `QubitRegister`: Manages a Qubit-Register, and stores the state vector for that Qubit. 
* [x] `Gate`: An abstract class for gates, it must have a pure virtual function for `apply()`.
  * [x] `HadmardGate`
  * [x] `CNOTGate`
  * [x] `PauliXGate` 
* [X] `GateFactory`: It stores and manages all objects of `Gate`
* [X] `Circuit`: a class to manage a `GateFactory` and (maybe multiple) `QubitRegister` objects. Needed to sequentially execute the `QubitRegister` on the list of `Gate`.

### Algorithms

* [x] **Superposition**: Apply `HadmardGate` to a zero-state. 
* [x] **Entanglement**: Apply `HadmardGate` to a qubit, then `CNOTGate` to observe its effects.
* [x] **Measurement**: Implement a function that collapses the state based on probabilities.

## How to use

* Clone this repostory: ``` git clone https://github.com/Muhaimin-Mairaj/Qubit-Simulator.git ``` 
* Navigate to the Project directory: ``` cd Qubit-Simulator ```
* Create a build directory: ``` mkdir build && cd build ```
* Generate the build system: ``` cmake .. ```
* Compile the code: ``` cmake --build . ```
* Run the executable,
  For Linux or macOS: ``` ./Qubit-Simulator ```
  For Windows: ``` .\Qubit_Simulator.exe ```

## Contribution

This project is currently being developed under a coursework at **School Of Mathematics and Computer Science, IBA Karachi**, so contribution from anyone other than team members is not allowed.

### Team

* Muhaimin Mairaj
* Muhammad Ishaque
* Ayaan Kumar

## License

This project is licensed as **MIT LICENSE**, see [LICENSE](./LICENSE) for more info.