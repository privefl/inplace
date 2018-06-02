#ifndef ACC_H
#define ACC_H

/******************************************************************************/

#include <utils.h>

using namespace Rcpp;
using std::size_t;


/******************************************************************************/

template <int RTYPE, typename T>
class VecAcc : public Vector<RTYPE> {
public:
  VecAcc(Vector<RTYPE>& vec, 
         const NumericVector& elem_ind)
    : Vector<RTYPE>(vec) {
      
      size_t ind, k;
      size_t LIM = vec.size();
      size_t n = elem_ind.size();
      std::vector<size_t> elem_ind2(n);
      for (k = 0; k < n; k++) {
        ind = static_cast<size_t>(elem_ind[k] - 1);
        myassert(ind < LIM, ERROR_BOUNDS);
        elem_ind2[k] = ind;
      }
      _elem_ind = elem_ind2;
    }
  
  inline T& operator[](size_t k) {
    // https://stackoverflow.com/a/32087373/6103040
    return Vector<RTYPE>::operator[](_elem_ind[k]);
  }
  
  size_t size() const { return _elem_ind.size(); }
  
protected:
  std::vector<size_t> _elem_ind;
};

/******************************************************************************/

template <int RTYPE, typename T>
class MatAcc : public Matrix<RTYPE> {
public:
  MatAcc(Matrix<RTYPE>& mat,
         const IntegerVector& row_ind,
         const IntegerVector& col_ind)
    : Matrix<RTYPE>(mat) {
      
      size_t ind, i, j;
      
      size_t LIM_N = mat.nrow();
      size_t n = row_ind.size();
      std::vector<size_t> row_ind2(n);
      for (i = 0; i < n; i++) {
        ind = static_cast<size_t>(row_ind[i] - 1);
        myassert(ind < LIM_N, ERROR_BOUNDS);
        row_ind2[i] = ind;
      }
      _row_ind = row_ind2;
      
      size_t LIM_M = mat.ncol();
      size_t m = col_ind.size();
      std::vector<size_t> col_ind2(m);
      for (j = 0; j < m; j++) {
        ind = static_cast<size_t>(col_ind[j] - 1);
        myassert(ind < LIM_M, ERROR_BOUNDS);
        col_ind2[j] = ind;
      }
      _col_ind = col_ind2;
    }
  
  inline T& operator()(size_t i, size_t j) {
    // https://stackoverflow.com/a/32087373/6103040
    return Matrix<RTYPE>::operator()(_row_ind[i], _col_ind[j]);
  }
  
  size_t nrow() const { return _row_ind.size(); }
  size_t ncol() const { return _col_ind.size(); }
  
protected:
  std::vector<size_t> _row_ind;
  std::vector<size_t> _col_ind;
};

/******************************************************************************/

#endif // ACC_H