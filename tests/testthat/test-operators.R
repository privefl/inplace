################################################################################

context("test-operators.R")

################################################################################

test_mat <- function(x, val) {
  
  call_x   <- deparse(substitute(x))
  call_val <- deparse(substitute(val))
  addr0 <- address(X)
  
  assign <- sprintf("X2 <- X; %s <- %s",
                    sub("^X", "X2", call_x),
                    paste(call_x, op, call_val))
  
  eval(parse(text = assign), parent.frame())
  expect_false(isTRUE(
    eval(all.equal(X, X2), parent.frame())
  ))
  
  assign <- sprintf("%s %%%s<-%% %s", call_x, op, call_val)
  eval(parse(text = assign), parent.frame())
  expect_true(eval(all.equal(X, X2), parent.frame()))
  expect_true(eval(identical(data.table::address(X), addr0), parent.frame()))
}

X <- matrix(rnorm(256, mean = 0, sd = 10), 16)

ind <- 1:5
op <- "*"
test_mat(X[ind], 2)

################################################################################

test_that("works for type double", {
  
  for (test_acc in TEST.ACCS) {
    
    test_acc(X[])
    test_acc(X[1, ])
    test_acc(X[cbind(1:5, 1:5)])
    
    for (ind in list(1:5, -(1:5), c(TRUE, FALSE, TRUE))) {
      
      test_mat(X[ind, ], rnorm(1))
      test_mat(X[, 1], rnorm(1))
      test_mat(X[, 1], rnorm(nrow(X)))
      test_mat(X[1, 1])
      test_mat(X[ind, 1])
      test_mat(X[, ind])
      test_mat(X[1, ind])
      test_mat(X[ind, ind])
    }
    
  }
})

################################################################################
