a <- 1:10
b <- 2:11

cbind(a, b)
cbind.data.frame(a, b)

`%***%` <- function(x, y) {
  x + y
}

a %***% b
