#include <iostream>
#include "Circuit.h"

int main () {
    srand(time(0));

    Circuit QCircuit(3);

    QCircuit.addGate('H', 0);
    QCircuit.addGate('C', 0, 1);
    QCircuit.addGate('C', 1, 2);

    QCircuit.execute();

    QCircuit.measure();

    std::cout << "State Vector after measurement:\n";
    QCircuit.display();
    
    return 0;
}