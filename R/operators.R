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
NULL

################################################################################

#' @rdname inplace-op
#' @export
`%*<-%` <- function(x, value) {
  
  infos_call <- interpret_call(substitute(x), value, "multiply")
  
  if (typeof(infos_call$x) == "integer") assert_int_ish(value)
  
  do.call(infos_call[[1]], infos_call[-1])
  
  invisible()
}

################################################################################

#' @rdname inplace-op
#' @export
`%+<-%` <- function(x, value) {
  
  infos_call <- interpret_call(substitute(x), value, "add")
  
  if (typeof(infos_call$x) == "integer") assert_int_ish(value)
  
  do.call(infos_call[[1]], infos_call[-1])
  
  invisible()
}

################################################################################
