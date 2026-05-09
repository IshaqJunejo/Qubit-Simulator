#include <iostream>
#include <stdexcept>
#include "Circuit.h"

Circuit::Circuit (int numQ) : numOfQubits(numQ) {
    this->factory = new GateFactory(numQ);
    this->QRegister = new QubitRegister(numQ);
}

Circuit::~Circuit () {
    delete this->factory;
    delete this->QRegister;
}

void Circuit::addGate (char type, int index) {
    if (index < 0 || index >= this->numOfQubits) {
        throw std::invalid_argument("Invalid Qubit index");
    }

    this->factory->addGate(type, index);
}

void Circuit::addGate (char type, int control, int target) {
    if (control < 0 || control >= this->numOfQubits) {
        throw std::invalid_argument("Invalid control Qubit index");
    } else if (target < 0 || target >= this->numOfQubits) {
        throw std::invalid_argument("Invalid target Qubit index");
    }

    this->factory->addGate(type, control, target);
}

void Circuit::execute () {
    std::cout << "State Vector before execution:\n" << *QRegister << "\n";

    for (int i = 0; i < this->factory->getNumOfGates(); i++) {
        this->factory->execute(QRegister, i);

        std::cout << "State Vector after execution step " << i + 1 << ":\n" << *QRegister << "\n";
    }
}

void Circuit::measure () {
    for (int i = 0; i < this->numOfQubits; i++) {
        this->QRegister->measure(i);
    }
}

void Circuit::display () {
    std::cout << *QRegister << "\n";
}