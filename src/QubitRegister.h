#ifndef QUBIT_REGISTER_H
#define QUBIT_REGISTER_H

#include <Eigen/Dense>

typedef std::complex<double> Complex;
typedef Eigen::VectorXcd StateVector;

class QubitRegister {
    private:
    int numOfQubits;
    StateVector state;
    void normalize();

    public:
    QubitRegister();
    QubitRegister(int size);
    void randomize();
    double probabilityOf(int n, bool target);
    void measure(int n);
    friend std::ostream & operator<<(std::ostream & out, const QubitRegister & other);
};

#endif