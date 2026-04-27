#include <iostream>
#include <Eigen/Dense>
#include "QubitRegister.h"
#include "Gate.h"
#include "PauliX.h"
#include "GateFactory.h"
#include "Circuit.h"

int main () {
    srand(time(0));


    QubitRegister QR(3);
    PauliX gate(1);

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

    std::cout << "After applying the PauliX Gate on Qubit index 1\n";

    probabilityOf1 = QR.probabilityOf(1, true);
    probabilityOfNot1 = QR.probabilityOf(1, false);

    std::cout << "Probability of Qubit 1 being \'1\':\t" << probabilityOf1 << "\n";
    std::cout << "Probability of Qubit 1 being \'0\':\t" << probabilityOfNot1 << "\n";

    std::cout << "Total:\t" << probabilityOf1 + probabilityOfNot1 << "\n\n";

    std::cout << "Resultant State Vector\n" << QR << "\n";

    QR.measure(1);

    std::cout << "After measuring qubit index 1\n";
    std::cout << QR << "\n";

    QR.measure(2);

    std::cout << "After measuring qubit index 2\n";
    std::cout << QR << "\n";

    QR.measure(0);

    std::cout << "After measuring qubit index 0\n";
    std::cout << QR << "\n";
    
    return 0;
}