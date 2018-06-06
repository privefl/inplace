################################################################################

#' Sweep
#' 
#' @param x a matrix.
#' @param STATS the summary statistic which is to be swept out.
#' @param FUN the function to be used to carry out the sweep.
#' 
#' @return `NULL`, invisibly.
#' @name inplace-sweep
#' 
#' @examples 
#' x <- matrix(1:6, 2)
#' sweep(x, 2, 1:3)
#' x
#' sweep2_in_place(x, 1:3)
#' x
#' 
NULL

################################################################################

#' @rdname inplace-sweep
#' @export
sweep1_in_place <- function(x, STATS, FUN = c("-", "+", "*", "/")) {
  
  stopifnot(is.matrix(x))  ## add asserts -> make function
  
  op <- match.arg(FUN)
  assert_for_int(x, STATS, op)
  
  fun <- get(`if`(length(STATS) == 1,
                  sprintf("%%%s<-%%", op), 
                  sprintf("%s_sweep1", OPS[[op]])))
  fun(x, STATS)
  
  invisible()
}

################################################################################

#' @rdname inplace-sweep
#' @export
sweep2_in_place <- function(x, STATS, FUN = c("-", "+", "*", "/")) {
  
  stopifnot(is.matrix(x))
  
  op <- match.arg(FUN)
  assert_for_int(x, STATS, op)
  
  fun <- get(`if`(length(STATS) == 1,
                  sprintf("%%%s<-%%", op), 
                  sprintf("%s_sweep2", OPS[[op]])))
  fun(x, STATS)
  
  invisible()
}

################################################################################
