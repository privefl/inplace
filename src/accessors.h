#ifndef ACC_H
#define ACC_H

/******************************************************************************/

#include <utils.h>

using namespace Rcpp;

/******************************************************************************/

template <int RTYPE, typename CTYPE>
class VecAcc : public Vector<RTYPE> {
public:
  VecAcc(Vector<RTYPE>& vec, 
         const NumericVector& elem_ind)
    : Vector<RTYPE>(vec) {
      
      _elem_ind = elem_ind - 1;
    }
  
  inline CTYPE& operator[](int k) {
    // https://stackoverflow.com/a/32087373/6103040
    return Vector<RTYPE>::operator[](_elem_ind[k]);
  }
  
  int size() const { return _elem_ind.size(); }
  
protected:
  IntegerVector _elem_ind;
};

/******************************************************************************/

template <int RTYPE, typename CTYPE>
class MatAcc : public Matrix<RTYPE> {
public:
  MatAcc(Matrix<RTYPE>& mat,
         const IntegerVector& row_ind,
         const IntegerVector& col_ind)
    : Matrix<RTYPE>(mat) {
      
      _row_ind = row_ind - 1;
      _col_ind = col_ind - 1;
    }
  
  inline CTYPE& operator()(int i, int j) {
    // https://stackoverflow.com/a/32087373/6103040
    return Matrix<RTYPE>::operator()(_row_ind[i], _col_ind[j]);
  }
  
  int nrow() const { return _row_ind.size(); }
  int ncol() const { return _col_ind.size(); }
  int size() const { return this->nrow() * this->ncol(); }
  
protected:
  IntegerVector _row_ind;
  IntegerVector _col_ind;
};

/******************************************************************************/

#endif // ACC_H