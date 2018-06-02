#include <accessors.h>

template <class C_VEC>
void multiply(C_VEC x, double val) {
  
  size_t n = x.size();
  for (size_t i = 0; i < n; i++) {
    x[i] *= val;
  }
}

// [[Rcpp::export]]
void multiply_all(NumericVector& x, double val) {
  multiply(x, val);
}

// [[Rcpp::export]]
void multiply_sub(NumericVector& x,
                  const NumericVector& ind_elem,
                  double val) {
  
  multiply(VecAcc<REALSXP, double>(x, ind_elem), val);
}

/*** R
address <- data.table::address
x <- 2:4 + 0
address(x)
multiply_all(x, 5)
x
address(x)
multiply_sub(x, 1, -1)
x
address(x)

mat <- matrix(1:4 + 0, 2)
address(mat)
multiply_sub(mat, 1:2, 2)
mat
address(mat)
*/
