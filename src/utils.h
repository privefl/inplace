#ifndef UTILS_H
#define UTILS_H

#include <Rcpp.h>

const char* const ERROR_TYPE =
  "Only 'integer' and 'double' types are supported.";
const char* const ERROR_DIM =
  "Incompatibility between dimensions.";
const char* const ERROR_BOUNDS =
  "Subscript out of bounds.";

inline void myassert(bool cond, const char *msg) {
  if (!cond) throw Rcpp::exception(msg);
}

#endif // UTILS_H