# devtools::install_github("privefl/inplace")
library(inplace)

address <- data.table::address
mat <- matrix(rnorm(2e7), 1e4)
addr0 <- address(mat)
mat[1:5, 1:5]

# copy
system.time(
  mat2 <- mat * 2
)
mat2[1:5, 1:5]

# modification in-place
system.time(
  mat %*<-% 2
)
mat[1:5, 1:5]
stopifnot(address(mat) == addr0)

mat[1:4, 1:4]
mat[1:2, 1:2] %*<-% 2
mat[1:4, 1:4]
mat[1:2, 1:2] %*<-% 1:4
mat[1:4, 1:4]

mat[1:2, 1:2] %+<-% 1:4
mat[1:4, 1:4]
