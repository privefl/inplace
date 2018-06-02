// [[Rcpp::depends(RcppArmadillo)]]
#include <RcppArmadillo.h>
using namespace Rcpp;

// [[Rcpp::export]]
void timesTwo(arma::vec& x) {
  x *= 2;
}

// [[Rcpp::export]]
void timesTwo2(arma::rowvec& x) {
  x *= 2;
}

// [[Rcpp::export]]
void timesTwo3(NumericVector& x) {
  
  int n = x.size();
  for (int i = 0; i < n; i++) {
    x[i] *= 2;
  }
}

// [[Rcpp::export]]
void timesTwo4(NumericVector& x) {
  
  NumericVector::iterator it;
  for(it = x.begin(); it != x.end(); ++it) {
    *it *= 2;
  }
}

/*** R
address <- pryr::address

x <- c(1, 2)
print(address(x))
timesTwo(x)
print(x)
print(address(x))

timesTwo3(x)
print(x)
print(address(x))
timesTwo4(x)
print(x)
print(address(x))

y <- rnorm(1e8)
microbenchmark::microbenchmark(
  y <- y * 2,
  timesTwo(y),
  timesTwo2(y),
  timesTwo3(y),
  timesTwo4(y),
  times = 20
)
*/
