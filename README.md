[![Travis build status](https://travis-ci.org/privefl/inplace.svg?branch=master)](https://travis-ci.org/privefl/inplace)
[![AppVeyor build status](https://ci.appveyor.com/api/projects/status/github/privefl/inplace?branch=master&svg=true)](https://ci.appveyor.com/project/privefl/inplace)
[![Coverage status](https://codecov.io/gh/privefl/inplace/branch/master/graph/badge.svg)](https://codecov.io/github/privefl/inplace?branch=master)
 
# inplace

In-place operators for R

## Example

```{r}
# devtools::install_github("privefl/inplace")
# or install.packages("inplace")
library(inplace)

address <- data.table::address
mat <- matrix(rnorm(5e7), 1e4)
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

# Also works with subset
mat[1:2, 1:2] %*<-% 2
mat[1:5, 1:5]
stopifnot(address(mat) == addr0)

## SWEEPS
means <- colMeans(mat)
system.time(
  mat2 <- sweep(mat, 2, means, '-')
)
# modification in-place
system.time(
  sweep2_in_place(mat, means, '-')
)
stopifnot(identical(mat, mat2))
stopifnot(address(mat) == addr0)
```

## Beware

If many names points to the same object, they will be all modified, which is not the default behaviour of base R.

```{r}
(X <- runif(4))
X2 <- X

X %*<-% 2
X
X2
```
