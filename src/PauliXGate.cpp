#include "QubitRegister.h"
#include "Gate.h"
#include "PauliXGate.h"

PauliXGate::PauliXGate (int index) {
    this->targets.push_back(index);
}

void PauliXGate::apply (StateVector& state) {
    // PauliXGate gate implementation logic
    for (int i = 0; i < state.size(); i++) {
        if (!(i & (1 << this->targets[0]))) {   // Finding if this state (probability) needs to be swapped
            int j = i | (1 << this->targets[0]);    // Finding the swappable position for this state (probability)

            std::complex<double> temp = state[i];   // Swapping the probabilities of these 2 states
            state[i] = state[j];
            state[j] = temp;
        }
    }
}