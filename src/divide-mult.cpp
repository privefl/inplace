/******************************************************************************/

#include <accessors.h>

/******************************************************************************/

#define ON_VEC(RTYPE, CTYPE) {                                                 \
  divide_vec_mult< Vector<RTYPE>, RTYPE >(x, val);                           \
  break;                                                                       \
}

#define ON_SUB_VEC(RTYPE, CTYPE) {                                             \
  Vector<RTYPE> x2(x);                                                         \
  Vector<RTYPE> val2(val);                                                     \
  divide_vec_mult(VecAcc<RTYPE, CTYPE>(x2, i), val2);                        \
  break;                                                                       \
}

#define ON_SUB_MAT(RTYPE, CTYPE) {                                             \
  Matrix<RTYPE> x2(x);                                                         \
  Vector<RTYPE> val2(val);                                                     \
  divide_mat_mult(MatAcc<RTYPE, CTYPE>(x2, i, j), val2);                     \
  break;                                                                       \
}

/******************************************************************************/

template <class C_VEC, int RTYPE>
void divide_vec_mult(C_VEC x, const Vector<RTYPE>& val) {

  myassert(x.size() == val.size(), ERROR_DIM);
  int i, n = x.size();
  
  for (i = 0; i < n; i++) 
    x[i] /= val[i];
}

template <int RTYPE, typename CTYPE>
void divide_mat_mult(MatAcc<RTYPE, CTYPE> x, const Vector<RTYPE>& val) {
  
  myassert(x.size() == val.size(), ERROR_DIM);
  int i, j, k = 0, n = x.nrow(), m = x.ncol();
  
  for (j = 0; j < m; j++)
    for (i = 0; i < n; i++)
      x(i, j) /= val[k++];
}

/******************************************************************************/

// [[Rcpp::export]]
void divide_all_mult(SEXP x, SEXP i, SEXP j, SEXP val) {
  
  myassert(i == R_NilValue && j == R_NilValue, ERROR_FATAL);
  
  DISPATCH(ON_VEC)
}

// [[Rcpp::export]]
void divide_subvec_mult(SEXP x, const NumericVector& i, SEXP j, SEXP val) {
  
  myassert(j == R_NilValue, ERROR_FATAL);
  
  DISPATCH(ON_SUB_VEC)
}

// [[Rcpp::export]]
void divide_submat_mult(SEXP x,
                          const IntegerVector& i,
                          const IntegerVector& j,
                          SEXP val) {
  
  DISPATCH(ON_SUB_MAT)
}

/******************************************************************************/
