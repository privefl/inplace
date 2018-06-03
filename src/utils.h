#ifndef UTILS_H
#define UTILS_H

/******************************************************************************/

#include <Rcpp.h>

/******************************************************************************/

const char* const ERROR_TYPE =
  "Only 'integer' and 'double' types are supported.";
const char* const ERROR_DIM =
  "Incompatibility between dimensions.";
const char* const ERROR_BOUNDS =
  "Subscript out of bounds.";
const char* const ERROR_FATAL = 
  "You shouldn't be here. Please report this issue.";

inline void myassert(bool cond, const char *msg) {
  if (!cond) throw Rcpp::exception(msg);
}

/******************************************************************************/

#define DISPATCH(CALL) {                                                       \
  switch(TYPEOF(x)) {                                                          \
  case INTSXP:                                                                 \
    CALL(INTSXP,  int)                                                         \
  case REALSXP:                                                                \
    CALL(REALSXP, double)                                                      \
  default:                                                                     \
    throw Rcpp::exception(ERROR_TYPE);                                         \
  }                                                                            \
}

/******************************************************************************/

#endif // UTILS_H