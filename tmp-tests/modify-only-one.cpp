#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]
void times_two_cpp(NumericVector& x) {
  for (int i = 0; i < x.size(); i++) {
    x[i] *= 2;
  }
}

/*** R
x <- runif(3)
x2 <- x
x
times_two_cpp(x)
x   ## OK
x2  ## don't want to modify x2

x[1] <- x[1] + 0
times_two_cpp(x)
x   ## OK
x2  ## OK

times_two_R <- function(x) {
  x[1] <- x[1] + 0
  times_two_cpp(x)
}
x <- runif(3)
x2 <- x
x
times_two_R(x)
x
x2

times_two_R2 <- function(x) {
  print(x_name <- deparse(substitute(x)))
  eval(parse(text = sprintf("%s[1] <- %s[1] + 0; times_two_cpp(%s)", 
                            x_name, x_name, x_name)), parent.frame())
}
x <- runif(3)
x2 <- x
x
times_two_R2(x)
x
x2

library(rlang)
times_two_R3 <- function(call) {
  print(quosure <- enquo(call))
  # parent_env <- get_env(quosure)
  # eval(expression(x[1] <- x[1] + 0), parent_env)
  # do.call("times_two_cpp", list(x = x), envir = parent_env)
}
x <- runif(3)
x2 <- x
x
tmp <- 
   times_two_R3(x)
x
x2
*/
