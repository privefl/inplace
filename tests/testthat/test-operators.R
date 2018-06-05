################################################################################

context("test-operators.R")

################################################################################

address <- data.table::address

r <- function(n, type) {
  x <- rnorm(n, mean = 100, sd = 10)
  `if`(type == "integer", round(x), x)
}

################################################################################

test_that("in-place operators work in common cases", {
  
  test_fun <- function(x, val) {
    
    call_x   <- deparse(substitute(x))
    call_val <- deparse(substitute(val))
    addr0 <- address(X)
    
    assign <- sprintf("{X2 <- X; %s <- %s}",
                      sub("^X", "X2", call_x),
                      paste(call_x, op, call_val))
    
    eval(parse(text = assign), parent.frame())
    stopifnot(!(eval(parse(text = "identical(X, X2)"), parent.frame())))
    
    assign <- sprintf("%s %%%s<-%% %s", call_x, op, call_val)
    eval(parse(text = assign), parent.frame())
    expect_true(eval(identical(X, X2), parent.frame()))
    expect_true(eval(identical(data.table::address(X), addr0), parent.frame()))
  }
  
  for (type in c("double", "integer")) {
    
    OPS <- c('*', '/', '-', '+')
    if (type == "integer") OPS <- setdiff(OPS, '/')
    
    for (op in OPS) {
      
      for (dim_X in list(NULL, c(8, 32))) {
        
        X <- rnorm(256, mean = 0, sd = 10)
        dim(X) <- dim_X
        
        one_val  <- r(1, type)
        five_val <- r(5, type)
        
        test_fun(X, one_val)
        test_fun(X[], one_val)
        test_fun(X[1:5], five_val)
        test_fun(X[6:10], five_val)
        
        if (is.matrix(X)) {
          
          n_val <- r(nrow(X), type)
          m_val <- r(ncol(X), type)
          
          test_fun(X[2, ],   one_val)
          test_fun(X[2, ],   m_val)
          test_fun(X[1:5, ], rep(m_val, 5))
          
          test_fun(X[, 2],   one_val)
          test_fun(X[, 2],   n_val)
          test_fun(X[, 1:5], rep(n_val, 5))
          
          test_fun(X[2, 2], one_val)
          test_fun(X[cbind(1:5, 1:5)], one_val)
          test_fun(X[cbind(1:5, 1:5)], five_val)
          
          for (ind in list(1:5, -(1:5), c(TRUE, FALSE, TRUE))) {
            
            test_fun(X[ind,    ], one_val)
            test_fun(X[ind,   2], one_val)
            test_fun(X[   , ind], one_val)
            test_fun(X[  2, ind], one_val)
            test_fun(X[ind, ind], one_val)
            
          }
          
        }
        
      }
      
    } 
    
  }
  
})

################################################################################
