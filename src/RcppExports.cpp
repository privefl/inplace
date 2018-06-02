// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <Rcpp.h>

using namespace Rcpp;

// GET_ERROR_TYPE
const char* const GET_ERROR_TYPE();
RcppExport SEXP _inplace_GET_ERROR_TYPE() {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    rcpp_result_gen = Rcpp::wrap(GET_ERROR_TYPE());
    return rcpp_result_gen;
END_RCPP
}
// GET_ERROR_DIM
const char* const GET_ERROR_DIM();
RcppExport SEXP _inplace_GET_ERROR_DIM() {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    rcpp_result_gen = Rcpp::wrap(GET_ERROR_DIM());
    return rcpp_result_gen;
END_RCPP
}
// GET_ERROR_BOUNDS
const char* const GET_ERROR_BOUNDS();
RcppExport SEXP _inplace_GET_ERROR_BOUNDS() {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    rcpp_result_gen = Rcpp::wrap(GET_ERROR_BOUNDS());
    return rcpp_result_gen;
END_RCPP
}
// GET_ERROR_FATAL
const char* const GET_ERROR_FATAL();
RcppExport SEXP _inplace_GET_ERROR_FATAL() {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    rcpp_result_gen = Rcpp::wrap(GET_ERROR_FATAL());
    return rcpp_result_gen;
END_RCPP
}
// multiply_all_one
void multiply_all_one(SEXP x, SEXP i, SEXP j, SEXP val);
RcppExport SEXP _inplace_multiply_all_one(SEXP xSEXP, SEXP iSEXP, SEXP jSEXP, SEXP valSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< SEXP >::type x(xSEXP);
    Rcpp::traits::input_parameter< SEXP >::type i(iSEXP);
    Rcpp::traits::input_parameter< SEXP >::type j(jSEXP);
    Rcpp::traits::input_parameter< SEXP >::type val(valSEXP);
    multiply_all_one(x, i, j, val);
    return R_NilValue;
END_RCPP
}
// multiply_subvec_one
void multiply_subvec_one(SEXP x, const NumericVector& i, SEXP j, SEXP val);
RcppExport SEXP _inplace_multiply_subvec_one(SEXP xSEXP, SEXP iSEXP, SEXP jSEXP, SEXP valSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< SEXP >::type x(xSEXP);
    Rcpp::traits::input_parameter< const NumericVector& >::type i(iSEXP);
    Rcpp::traits::input_parameter< SEXP >::type j(jSEXP);
    Rcpp::traits::input_parameter< SEXP >::type val(valSEXP);
    multiply_subvec_one(x, i, j, val);
    return R_NilValue;
END_RCPP
}
// multiply_submat_one
void multiply_submat_one(SEXP x, const IntegerVector& i, const IntegerVector& j, SEXP val);
RcppExport SEXP _inplace_multiply_submat_one(SEXP xSEXP, SEXP iSEXP, SEXP jSEXP, SEXP valSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< SEXP >::type x(xSEXP);
    Rcpp::traits::input_parameter< const IntegerVector& >::type i(iSEXP);
    Rcpp::traits::input_parameter< const IntegerVector& >::type j(jSEXP);
    Rcpp::traits::input_parameter< SEXP >::type val(valSEXP);
    multiply_submat_one(x, i, j, val);
    return R_NilValue;
END_RCPP
}

static const R_CallMethodDef CallEntries[] = {
    {"_inplace_GET_ERROR_TYPE", (DL_FUNC) &_inplace_GET_ERROR_TYPE, 0},
    {"_inplace_GET_ERROR_DIM", (DL_FUNC) &_inplace_GET_ERROR_DIM, 0},
    {"_inplace_GET_ERROR_BOUNDS", (DL_FUNC) &_inplace_GET_ERROR_BOUNDS, 0},
    {"_inplace_GET_ERROR_FATAL", (DL_FUNC) &_inplace_GET_ERROR_FATAL, 0},
    {"_inplace_multiply_all_one", (DL_FUNC) &_inplace_multiply_all_one, 4},
    {"_inplace_multiply_subvec_one", (DL_FUNC) &_inplace_multiply_subvec_one, 4},
    {"_inplace_multiply_submat_one", (DL_FUNC) &_inplace_multiply_submat_one, 4},
    {NULL, NULL, 0}
};

RcppExport void R_init_inplace(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
