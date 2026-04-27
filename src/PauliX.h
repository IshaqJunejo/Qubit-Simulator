#ifndef PAULIX_H
#define PAULIX_H

#include "Gate.h"
#include "QubitRegister.h"

class PauliX : public Gate {
    private:
    //

    public:
    PauliX (int index);

    void apply (StateVector& state) override;
};

#endif