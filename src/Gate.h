#ifndef GATE_H
#define GATE_H

#include <vector>
#include "QubitRegister.h"

class Gate {
    protected:
    std::vector<int> targets;

    public:
    Gate ();

    virtual void apply (StateVector& state) = 0;
};

#endif