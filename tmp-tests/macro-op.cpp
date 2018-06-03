#include <Rcpp.h>
using namespace Rcpp;

#define OP *

#define CALL times

// [[Rcpp::export]]
NumericVector timesTwo(NumericVector x) {
  return x OP 2;
}


// // [[Rcpp::export]]
// NumericVector timesTwo2(NumericVector x) {
//   return CALLTwo(x);
// }

/*** R
timesTwo(42)
*/
