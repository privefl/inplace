/******************************************************************************/

#include <accessors.h>

/******************************************************************************/

#define ON_VEC(RTYPE, CTYPE) {                                                 \
  add_vec_one< Vector<RTYPE>, CTYPE >(x, as<CTYPE>(val));                      \
  break;                                                                       \
}

#define ON_SUB_VEC(RTYPE, CTYPE) {                                             \
  Vector<RTYPE> x2(x);                                                         \
  add_vec_one(VecAcc<RTYPE, CTYPE>(x2, i), as<CTYPE>(val));                    \
  break;                                                                       \
}

#define ON_SUB_MAT(RTYPE, CTYPE) {                                             \
  Matrix<RTYPE> x2(x);                                                         \
  add_mat_one(MatAcc<RTYPE, CTYPE>(x2, i, j), as<CTYPE>(val));                 \
  break;                                                                       \
}

/******************************************************************************/

template <class C_VEC, typename CTYPE>
void add_vec_one(C_VEC x, CTYPE val) {
  
  int i, n = x.size();
  
  for (i = 0; i < n; i++) 
    x[i] += val;
}

template <int RTYPE, typename CTYPE>
void add_mat_one(MatAcc<RTYPE, CTYPE> x, CTYPE val) {
  
  int i, j, n = x.nrow(), m = x.ncol();
  
  for (j = 0; j < m; j++)
    for (i = 0; i < n; i++)
      x(i, j) += val;
}

/******************************************************************************/

// [[Rcpp::export]]
void add_all_one(SEXP x, SEXP i, SEXP j, SEXP val) {
  
  myassert(i == R_NilValue && j == R_NilValue, ERROR_FATAL);
  
  DISPATCH(ON_VEC)
}

// [[Rcpp::export]]
void add_subvec_one(SEXP x, const NumericVector& i, SEXP j, SEXP val) {
  
  myassert(j == R_NilValue, ERROR_FATAL);
  
  DISPATCH(ON_SUB_VEC)
}

// [[Rcpp::export]]
void add_submat_one(SEXP x, 
                         const IntegerVector& i, 
                         const IntegerVector& j, 
                         SEXP val) {
  
  DISPATCH(ON_SUB_MAT)
}

/******************************************************************************/
