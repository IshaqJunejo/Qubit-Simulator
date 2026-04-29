#include <unsupported/Eigen/KroneckerProduct>
#include "QubitRegister.h"
#include "Gate.h"
#include "HadamardGate.h"

HadamardGate::HadamardGate (int index, int numQ) {
    this->targets.push_back(index);
    this->initKroneckerProduct(numQ);
}

void HadamardGate::initKroneckerProduct (int numQ) {
    int numOfQubits = numQ;
    Eigen::Matrix2cd H;

    std::complex<double> s = 1.0 / std::sqrt(2.0);

    H << s , s, s, -s;

    Eigen::Matrix2cd I = Eigen::Matrix2cd::Identity();

    this->kronProd = (this->targets[0] == 0) ? H : I;

    for (int i = 1; i < numOfQubits; i++) {
        if (i == this->targets[0]) {
            this->kronProd = kroneckerProduct(H, this->kronProd).eval();
        } else {
            this->kronProd = kroneckerProduct(I, this->kronProd).eval();
        }
    }
}

void HadamardGate::apply (StateVector& state) {
    state = this->kronProd * state;
}