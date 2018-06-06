#' In-place operators
#'
#' @param x Variable.
#' @param value Value.
#'
#' @return `NULL` (invisibly).
#' 
#' @name inplace-op
#'
#' @examples
#' mat <- matrix(1:4, 2)
#' mat
#' mat %+<-% 2
#' mat
NULL

################################################################################

#' @rdname inplace-op
#' @export
`%*<-%` <- function(x, value) {
  
  infos_call <- interpret_call(substitute(x), value, "multiply")
  
  assert_for_int(infos_call$x, value, '*')
  
  do.call(infos_call[[1]], infos_call[-1])
  
  invisible()
}

################################################################################

#' @rdname inplace-op
#' @export
`%+<-%` <- function(x, value) {
  
  infos_call <- interpret_call(substitute(x), value, "add")
  
  assert_for_int(infos_call$x, value, '+')
  
  do.call(infos_call[[1]], infos_call[-1])
  
  invisible()
}

################################################################################

#' @rdname inplace-op
#' @export
`%-<-%` <- function(x, value) {
  
  infos_call <- interpret_call(substitute(x), value, "substract")
  
  assert_for_int(infos_call$x, value, '-')
  
  do.call(infos_call[[1]], infos_call[-1])
  
  invisible()
}

################################################################################

#' @rdname inplace-op
#' @export
`%/<-%` <- function(x, value) {
  
  infos_call <- interpret_call(substitute(x), value, "divide")
  
  assert_for_int(infos_call$x, value, '/')
  
  do.call(infos_call[[1]], infos_call[-1])
  
  invisible()
}

################################################################################
