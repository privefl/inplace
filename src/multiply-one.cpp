/******************************************************************************/

#include <accessors.h>

/******************************************************************************/

#define ON_VEC(RTYPE, CTYPE) {                                                 \
  multiply_one< Vector<RTYPE>, CTYPE >(x, as<CTYPE>(val));                     \
  break;                                                                       \
}

#define ON_SUB_VEC(RTYPE, CTYPE) {                                             \
  Vector<RTYPE> x2(x);                                                         \
  multiply_one(VecAcc<RTYPE, CTYPE>(x2, i), as<CTYPE>(val));                   \
  break;                                                                       \
}

#define ON_SUB_MAT(RTYPE, CTYPE) {                                             \
  Matrix<RTYPE> x2(x);                                                         \
  multiply_one(MatAcc<RTYPE, CTYPE>(x2, i, j), as<CTYPE>(val));                \
  break;                                                                       \
}

/******************************************************************************/

template <class C_VEC, typename CTYPE>
void multiply_one(C_VEC x, CTYPE val) {
  
  size_t n = x.size();
  for (size_t i = 0; i < n; i++) {
    x[i] *= val;
  }
}

/******************************************************************************/

// [[Rcpp::export]]
void multiply_all_one(SEXP x, SEXP i, SEXP j, SEXP val) {
  
  myassert(i == R_NilValue && j == R_NilValue, ERROR_FATAL);
  
  switch(TYPEOF(x)) {
  case INTSXP:
    ON_VEC(INTSXP,  int)
  case REALSXP:
    ON_VEC(REALSXP, double)
  default:
    throw Rcpp::exception(ERROR_FATAL);
  }
}

// [[Rcpp::export]]
void multiply_subvec_one(SEXP x, const NumericVector& i, SEXP j, SEXP val) {
  
  myassert(j == R_NilValue, ERROR_FATAL);
  
  switch(TYPEOF(x)) {
  case INTSXP:
    ON_SUB_VEC(INTSXP,  int)
  case REALSXP:
    ON_SUB_VEC(REALSXP, double)
  default:
    throw Rcpp::exception(ERROR_FATAL);
  }
}

// [[Rcpp::export]]
void multiply_submat_one(SEXP x, 
                         const IntegerVector& i, 
                         const IntegerVector&  j, 
                         SEXP val) {
  
  switch(TYPEOF(x)) {
  case INTSXP:
    ON_SUB_MAT(INTSXP,  int)
  case REALSXP:
    ON_SUB_MAT(REALSXP, double)
  default:
    throw Rcpp::exception(ERROR_FATAL);
  }
}

/******************************************************************************/
