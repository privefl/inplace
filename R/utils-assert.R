################################################################################

stop2 <- function(...) stop(sprintf(...), call. = FALSE)

################################################################################

assert_int_ish <- function(x) {
  if (any(trunc(x) != x))
    stop2("'%s' should have integer values only.", deparse(substitute(x)))
}

################################################################################

assert_atomic <- function(x) {
  if (!is.atomic(x) || is.null(x))
    stop2("'%s' should be atomic.", deparse(substitute(x)))
}

assert_numeric <- function(x) {
  if (!is.numeric(x)) stop2(GET_ERROR_TYPE())
} 

################################################################################
