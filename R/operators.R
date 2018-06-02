################################################################################

#' Title
#'
#' @param call 
#' @param val 
#'
#' @return
#' @export
#'
#' @examples
`%*<-%` <- function(call, val) {
  
  infos_call <- interpret_call(substitute(call), val, "multiply")
  
  if (typeof(infos_call$x) == "integer") assert_int_ish(val)
  
  do.call(infos_call[[1]], infos_call[-1])
  
  invisible()
}

################################################################################
