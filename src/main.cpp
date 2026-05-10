#include <iostream>
#include "Circuit.h"

int main () {
    srand(time(0));

    int QNums;
    bool valid = false;

    std::cout << "+------------------------------------+\n";
    std::cout << "|     QUANTUM COMPUTER SIMULATOR     |\n";
    std::cout << "+------------------------------------+\n";

    do {
        std::cout << "Enter the number of Qubits you want to simulate (1 - 5):\t";
        while (!(std::cin >> QNums)) {
            std::cout << "Invalid input, please enter a valid input in range (1 - 5):\t";

            std::cin.clear();

            std::cin.ignore(1000, '\n');
        }

        if (QNums < 1) {
            std::cout << "Invalid Number of Qubits\n";
        } else if (QNums > 5) {
            std::cout << "Memory limitation, can't simulate large number of Qubits\n";
        } else {
            valid = true;
        }
    } while (!valid);

    std::cout << "\nINITIALIZING A QUANTUM CIRCUIT OF " << QNums << " QUBITS\n";
    Circuit QCircuit(QNums);

    // MENU
    /*
    Display Qubit
        Probability of ith Qubit
        State Vector
    Randomize
        Randomize
    Add Gate
        PauliX
        Hadamard
        CNOT
    Display Circuit
        Display Circuit
    Execute
        Execute
    Measure
        Measure
    Exit
    */

    int choice = 0;
    do {
        std::cout << "\nEnter your choice:\n";
        std::cout << "1 - Display Qubit Info\n";
        std::cout << "2 - Randomize\n";
        std::cout << "3 - Add Gate\n";
        std::cout << "4 - Display Circuit\n";
        std::cout << "5 - Execute\n";
        std::cout << "6 - Measure\n";
        std::cout << "Anything else - Exit\n\n";
        std::cout << "Your choice > ";

        while (!(std::cin >> choice)) {
            std::cout << "Invalid input:\n";
            std::cout << "Please enter an integer (1 - 6)\n";

            std::cin.clear();

            std::cin.ignore(1000, '\n');
        }

        if (choice == 1) {
            int infoID;

            std::cout << "\nWhich Info do you want to display?\n";
            std::cout << "1 - Probability of ith Qubit\n";
            std::cout << "2 - Display State Vector\n";

            std::cin >> infoID;

            if (infoID == 1) {
                int i;

                std::cout << "Enter \'i\':\t";
                std::cin >> i;

                QCircuit.displayQubitProb(i);
                std::cout << "\n";
            } else if (infoID == 2) {
                QCircuit.display();
                std::cout << "\n";
            } else {
                std::cout << "Invalid Info Choice selected\n";
            }
        } else if (choice == 2) {
            // Randomize
            QCircuit.randomize();
            QCircuit.display();
        } else if (choice == 3) {
            // Add Gate
            int option;
            std::cout << "\nWhich Gate do you want to add?\n";
            std::cout << "1 - Hadamard Gate\n";
            std::cout << "2 - PauliX Gate\n";
            std::cout << "3 - CNot Gate\n";
            std::cin >> option;

            int index;
            if (option == 1){
                std::cout << "Enter the index of Qubit\t";
                std::cin >> index;
                QCircuit.addGate('H',index);
            }
            else if (option == 2){
                std::cout << "Enter the index of Qubit\t";
                std::cin >> index;
                QCircuit.addGate('X', index);
            }
            else if (option == 3){
                int control,target;
                std::cout << "Enter the index of Control Qubit\t";
                std::cin >> control;
                std::cout << "Enter the index of  Target Qubit\t";
                std::cin >> target;
                QCircuit.addGate('C',control,target);
            }
            else{
                std::cout << "Invalid choice selected\n";
            }

        } else if (choice == 4) {
            // Display Circuit
            std::vector<std::string> gates_info = QCircuit.getGatesInfo();

            std::cout << "\nQuantum Circuit Gates\n";
            for (int i = 0; i < gates_info.size(); i++) {
                std::cout << "Gate no: " << i << "\t" << gates_info[i] << "\n";
            }
            if (gates_info.size() == 0) {
                std::cout << "No Gates Added Yet\n";
            }
        } else if (choice == 5) {
            // Execute
            QCircuit.execute();
            QCircuit.display();
        } else if (choice == 6) {
            // Measure
            QCircuit.measure();
            QCircuit.display();
        } else {
            // Exit
            std::cout << "INITIALIZING EXIT SEQUENCE!\n";
            choice = 7;
        }
    } while (choice >= 1 && choice <= 6);

    return 0;
}