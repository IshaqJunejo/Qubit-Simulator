#include <iostream>
#include <Eigen/Dense>
#include "QubitRegister.h"
#include "Gate.h"
#include "PauliXGate.h"
#include "GateFactory.h"
#include "Circuit.h"

int main () {
    srand(time(0));

    int size = 3;

    QubitRegister QR(size);
    PauliXGate gate(1);

    std::cout << "Initial State\n";
    std::cout << QR << "\n";

    QR.randomize();

    std::cout << "Randomized State\n";
    std::cout << QR << "\n";

    double probabilityOf1 = QR.probabilityOf(1, true);
    double probabilityOfNot1 = QR.probabilityOf(1, false);

    std::cout << "Probability of Qubit 1 being \'1\':\t" << probabilityOf1 << "\n";
    std::cout << "Probability of Qubit 1 being \'0\':\t" << probabilityOfNot1 << "\n";

    std::cout << "Total:\t" << probabilityOf1 + probabilityOfNot1 << "\n\n";

    gate.apply(QR.getState());

    std::cout << "After applying the PauliXGate Gate on Qubit index 1\n";

    probabilityOf1 = QR.probabilityOf(1, true);
    probabilityOfNot1 = QR.probabilityOf(1, false);

    std::cout << "Probability of Qubit 1 being \'1\':\t" << probabilityOf1 << "\n";
    std::cout << "Probability of Qubit 1 being \'0\':\t" << probabilityOfNot1 << "\n";

    std::cout << "Total:\t" << probabilityOf1 + probabilityOfNot1 << "\n\n";

    std::cout << "Resultant State Vector\n" << QR << "\n";

    for (int i = 0; i < size; i++) {
        QR.measure(i);

        std::cout << "After measuring qubit index " << i << "\n" << QR << "\n";
    }
    
    return 0;
}