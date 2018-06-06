################################################################################

OPS <- setNames(c("multiply", "add", "substract", "divide"), 
                c('*', '+', '-', '/'))

################################################################################

stop2 <- function(...) stop(sprintf(...), call. = FALSE)

################################################################################

assert_for_int <- function(x, val, op) {
  
  if (typeof(x) == "integer") {
    
    if (op == '/') {
      stop2("Division is not allowed for type integer.")
    } else {
      if (any(trunc(val) != val)) 
        stop2("'%s' should have integer values only.", deparse(substitute(val)))
    }
    
  }
}

################################################################################
