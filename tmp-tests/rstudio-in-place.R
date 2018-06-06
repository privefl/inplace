library(compiler)
enableJIT(0)

address <- data.table::address
addr0 <- address(X <- 1:4)
X2 <- X
identical(address(X2), addr0)
X[1] <- X[1] * 1L
identical(address(X), addr0)
identical(address(X2), addr0)

address <- pryr::address
X <- runif(4)
addr0 <- address(X)
X[1:0] <- X[1:0] + 0L
identical(address(X), addr0)

system.time(x <- rep(1, 1e8))
pryr::refs(x)
print(system.time(x[1] <- 1))
print(system.time(x[1] <- 1))


x <- runif(1e8)
pryr::refs(x)
system.time(x[[1]] <- 1)
system.time(x[[1]] <- 1)
f <- function() {
  x <- runif(1e8)
  pryr::refs(x)
  print(system.time(x[[1]] <- 1))
  print(system.time(x[[1]] <- 1))
}

f()
