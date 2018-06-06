/******************************************************************************/

#include <accessors.h>

/******************************************************************************/

#define ON_MAT_ROW(RTYPE, CTYPE) {                                             \
  Matrix<RTYPE> x2(x);                                                         \
  Vector<RTYPE> val2(val);                                                     \
  add_mat1_mult(x2, val2);                                                     \
  break;                                                                       \
}

#define ON_MAT_COL(RTYPE, CTYPE) {                                             \
  Matrix<RTYPE> x2(x);                                                         \
  Vector<RTYPE> val2(val);                                                     \
  add_mat2_mult(x2, val2);                                                     \
  break;                                                                       \
}

/******************************************************************************/

template <int RTYPE>
void add_mat1_mult(Matrix<RTYPE>& x, const Vector<RTYPE>& val) {
  
  myassert(x.nrow() == val.size(), ERROR_DIM);
  int i, j, n = x.nrow(), m = x.ncol();
  
  for (j = 0; j < m; j++)
    for (i = 0; i < n; i++)
      x(i, j) += val[i];
}

template <int RTYPE>
void add_mat2_mult(Matrix<RTYPE>& x, const Vector<RTYPE>& val) {
  
  myassert(x.ncol() == val.size(), ERROR_DIM);
  int i, j, n = x.nrow(), m = x.ncol();
  
  for (j = 0; j < m; j++)
    for (i = 0; i < n; i++)
      x(i, j) += val[j];
}

/******************************************************************************/

// [[Rcpp::export]]
void add_sweep1(SEXP x, SEXP val) {
  
  DISPATCH(ON_MAT_ROW)
}

// [[Rcpp::export]]
void add_sweep2(SEXP x, SEXP val) {
  
  DISPATCH(ON_MAT_COL)
}

/******************************************************************************/
