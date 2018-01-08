//
// Created by Yurii Shyrma on 03.01.2018
//

#ifndef LIBND4J_SVD_H
#define LIBND4J_SVD_H

#include <ops/declarable/helpers/helpers.h>
#include "NDArray.h"

namespace nd4j {
namespace ops {
namespace helpers {


template<typename T>
class SVD {

    public:
    
    NDArray<T> _M;
    NDArray<T> _S;
    NDArray<T> _U;
    NDArray<T> _V;
    
    int _diagSize;

    bool _transp;
    bool _calcU;
    bool _calcV;
    bool _fullUV;

    /**
    *  constructor
    */
    SVD(const NDArray<T>& matrix, const bool calcV, const bool calcU, const bool fullUV);

    void deflation1(int col1, int shift, int ind, int size);
    
    void deflation2(int col1U , int col1M, int row1W, int col1W, int ind1, int ind2, int size);
    
    void deflation(int col1, int col2, int ind, int row1W, int col1W, int shift);    
    
    T secularEq(const T diff, const NDArray<T>& col0, const NDArray<T>& diag, const NDArray<T> &permut, const NDArray<T>& diagShifted, const T shift);

    void calcSingVals(const NDArray<T>& col0, const NDArray<T>& diag, const NDArray<T>& permut, NDArray<T>& singVals, NDArray<T>& shifts, NDArray<T>& mus);

};

    



}
}
}


#endif //LIBND4J_SVD_H