################################################################################

stop2 <- function(...) stop(sprintf(...), call. = FALSE)

################################################################################

assert_lengths <- function(...) {
  lengths <- lengths(list(...))
  if (length(lengths) > 1) {
    if (any(diff(lengths) != 0))
      stop2(GET_ERROR_DIM())
  } else {
    stop2("You should check the lengths of at least two elements.")
  }
}

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
  if (!is.numeric(x)) stop2(GET_ERROR_DIM())
} 

################################################################################
