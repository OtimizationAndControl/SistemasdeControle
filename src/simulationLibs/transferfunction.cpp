#include "transferfunction.h"

template <class UsedType>
void TransferFunction<UsedType>::initTfNumber()
{
    this->TF = new Polynom<UsedType> *[nRowsTF];
    for (unsigned i = 0; i < nRowsTF; i++)
        this->TF[i] = new Polynom<UsedType> [nColsTF];
}

template <class UsedType>
void TransferFunction<UsedType>::c2dConversion()
{

}

template <class UsedType>
TransferFunction<UsedType>::TransferFunction(std::string num, std::string den,
                                             unsigned rows  , unsigned cols)
{
    Matrix<UsedType> Num(num), Den(den);
    nRowsTF = rows;
    nColsTF = cols;
    this->initTfNumber();
    sampleTime = 0.1;

    unsigned cont = 1;
    for(unsigned i = 0; i < nRowsTF; i++)
        for (unsigned j = 0; j < nColsTF; j++)
        {
            this->TF[i][j].init(Num.getLine(cont), Den.getLine(cont));
            cont++;
        }
}

template <class UsedType>
TransferFunction<UsedType>::TransferFunction(unsigned rows, unsigned cols)
{
    nRowsTF = rows;
    nColsTF = cols;
    this->initTfNumber();
    sampleTime = 0.1;
}

template <class UsedType>
Polynom<UsedType> TransferFunction<UsedType>::operator ()(unsigned row, unsigned col)
{
    Polynom<UsedType> Ret(this->TF[row-1][col-1].getNum(),
                          this->TF[row-1][col-1].getDen());

    return Ret;
}

template <class UsedType>
void TransferFunction<UsedType>::operator ()(unsigned row, unsigned col, Polynom<UsedType> P)
{
    this->TF[row-1][col-1] = P;
}

template <class UsedType>
void TransferFunction<UsedType>::operator =(TransferFunction TF)
{
    this->sampleTime = TF.sampleTime;
    this->timeSimulation = TF.timeSimulation;
    this->nRowsTF = TF.nRowsTF;
    this->initTfNumber();

    for(unsigned i = 0; i < this->nRowsTF; i++)
        for(unsigned j = 0; j < this->nRowsTF; j++)
            this->TF[i][j] = TF.TF[i][j];
}

template <class UsedType>
void TransferFunction<UsedType>::printTF()
{
    for(unsigned i = 0; i < nRowsTF; i++)
        for(unsigned j = 0; j < nColsTF; j++)
        {
            this->TF[i][j].setVar('s');
            this->TF[i][j].print();
        }
}


template <class UsedType>
UsedType TransferFunction<UsedType>::sim(UsedType x)
{

}


template <class UsedType>
Matrix<UsedType> TransferFunction<UsedType>::sim(Matrix<UsedType> x)
{

}

template <class UsedType>
Matrix<UsedType> TransferFunction<UsedType>::sim(UsedType lsim, UsedType lmax, UsedType step)
{

}

//template class TransferFunction<int>;
template class TransferFunction<float>;
template class TransferFunction<double>;
