#include <Rcpp.h>
using namespace Rcpp;


// [[Rcpp::export]]
int size_rcpp(NumericVector x) {
  return x.size();
}

/*** R
size_rcpp(matrix(1:4, 2, 2))
*/
