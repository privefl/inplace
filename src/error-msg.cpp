/******************************************************************************/

#include <inplace/utils.h>

/******************************************************************************/

// [[Rcpp::export]]
const char* const GET_ERROR_TYPE() {
  return ERROR_TYPE;
}

// [[Rcpp::export]]
const char* const GET_ERROR_DIM() {
  return ERROR_DIM;
}

// [[Rcpp::export]]
const char* const GET_ERROR_BOUNDS() {
  return ERROR_BOUNDS;
}

// [[Rcpp::export]]
const char* const GET_ERROR_FATAL() {
  return ERROR_FATAL;
}

/******************************************************************************/

/*** R
GET_ERROR_TYPE()
GET_ERROR_DIM()
GET_ERROR_BOUNDS()
GET_ERROR_FATAL()
*/