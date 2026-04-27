// #include <vector>
#include <cmath>
#include <Eigen/Dense>
#include <cstdlib>
#include <ctime>
#include <stdexcept>
#include "QubitRegister.h"

typedef std::complex<double> Complex;
typedef Eigen::VectorXcd StateVector;

// Constructors
QubitRegister::QubitRegister () : numOfQubits(1) {
    state = StateVector::Zero(2);
    state(0) = 1.0;
}

QubitRegister::QubitRegister (int size) : numOfQubits(size) {
    state = StateVector::Zero(1 << size);
    state(0) = 1.0;
}

// implementing the randomize() function
void QubitRegister::randomize(){
    double random;
    for (int i = 0; i < (1 << numOfQubits); i++){
        random = rand() % 100;
        random /= 99;
        state(i) = random;
    }

    normalize();
}

// Implementing the normalize function
void QubitRegister::normalize(){
    double sum = 0;

    for (int i = 0; i < (1 << numOfQubits); i++){
        sum += std::norm(state(i));
    }
    sum = std::sqrt(sum);
    for (int i = 0; i < (1 << numOfQubits); i++){
        state(i) = state(i) / sum;
    }
}


double QubitRegister::probabilityOf(int n, bool target) {
    if (n < 0 || n >= numOfQubits)
        throw std::invalid_argument("Invalid qubit index");

    double prob = 0.0;
    int indent = (target)? 0 : (1 << n);

    for (int i = 0; i < (1 << numOfQubits); i++) {
        if (((i - indent) >> n) & 1) {
            prob += std::norm(state(i));
        }
    }

    return prob;
}

void QubitRegister::measure(int n) {
    if (n < 0 || n >= numOfQubits) 
        throw std::invalid_argument("Invalid qubit index");

    double prob = probabilityOf(n, true);

    double random = (rand() % 100) / 99.0;
    int indent = (random > prob)? (1 << n) : 0;

    for (int i = 0; i < (1 << numOfQubits); i++) {
        if (((i - indent) >> n) & 1) {
            state(i) = 0.0;
        }
    }

    normalize();
}

// Get a reference to the State Vector
StateVector& QubitRegister::getState() {
    return this->state;
}

// operator overloading
std::ostream& operator<<(std::ostream& out, const QubitRegister& other) {
    for (int i = 0; i < (1 << other.numOfQubits); i++){
        out << std::norm(other.state(i)) << std::endl;
    }

    return out;
}