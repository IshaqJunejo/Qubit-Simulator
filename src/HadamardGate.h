#ifndef HADAMARDGATE_H
#define HADAMARDGATE_H

#include <unsupported/Eigen/KroneckerProduct>
#include "QubitRegister.h"
#include "Gate.h"

class HadamardGate : public Gate {
    private:
    Eigen::MatrixXcd kronProd;

    void initKroneckerProduct (int numQ);
    
    public:
    HadamardGate (int index, int numQ);

    void apply (StateVector& state) override;
};

#endif