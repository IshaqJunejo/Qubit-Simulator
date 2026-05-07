#include <iostream>
#include <Eigen/Dense>
#include "QubitRegister.h"
#include "Gate.h"
#include "PauliXGate.h"
#include "HadamardGate.h"
#include "CNOTGate.h"
#include "GateFactory.h"
#include "Circuit.h"

int main () {
    srand(time(0));

    int size = 3;

    QubitRegister QR(size);

    HadamardGate h(0, size);
    CNOTGate c1(0, 1, size);
    CNOTGate c2(1, 2, size);

    std::cout << "Initial State\n" << QR << "\n";

    double prob, prob2;

    for (int i = 0; i < size; i++) {
        prob = QR.probabilityOf(i, true);
        prob2 = QR.probabilityOf(i, false);

        std::cout << "Qubit index: " << i << "\tTrue: " << prob << "\tFalse: " << prob2 << "\n";
    }

    h.apply(QR);

    std::cout << "\nApplying Hadamard Gate (index 0):\n" << QR << "\n";

    for (int i = 0; i < size; i++) {
        prob = QR.probabilityOf(i, true);
        prob2 = QR.probabilityOf(i, false);

        std::cout << "Qubit index: " << i << "\tTrue: " << prob << "\tFalse: " << prob2 << "\n";
    }

    c1.apply(QR);
    c2.apply(QR);

    std::cout << "\nEntanglement:\n" << QR << "\n";

    for (int i = 0; i < size; i++) {
        prob = QR.probabilityOf(i, true);
        prob2 = QR.probabilityOf(i, false);

        std::cout << "Qubit index: " << i << "\tTrue: " << prob << "\tFalse: " << prob2 << "\n";
    }

    QR.measure(0);

    std::cout << "\nAfter measuring the state of Qubit 0:\n" << QR << "\n";
    
    return 0;
}