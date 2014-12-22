#ifndef TRANSFERFUNCTION_H
#define TRANSFERFUNCTION_H
#include <src/simulationLibs/model.h>
#include <src/primitiveLibs/polynom.h>

template <class UsedType>
class TransferFunction : public Model<UsedType>
{
private:
    UsedType sampleTime, timeSimulation;
    unsigned nRowsTF, nColsTF;
    Polynom<UsedType> **TF;
    void initTfNumber();
    void c2dConversion();

public:
    TransferFunction(unsigned rows, unsigned cols);
    TransferFunction(std::string num, std::string den,
                     unsigned rows  , unsigned cols);

    Polynom<UsedType> operator()(unsigned row, unsigned col);
    void operator()(unsigned row, unsigned col, Polynom<UsedType> P);
    void operator= (TransferFunction TF);
    void printTF(); // Método Opcional

    UsedType sim(UsedType x);
    Matrix<UsedType> sim(Matrix<UsedType> x);
    Matrix<UsedType> sim(UsedType lsim, UsedType lmax, UsedType step);
};

#endif // TRANSFERFUNCTION_H
