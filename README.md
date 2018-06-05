[![Travis build status](https://travis-ci.org/privefl/inplace.svg?branch=master)](https://travis-ci.org/privefl/inplace)
[![AppVeyor build status](https://ci.appveyor.com/api/projects/status/github/privefl/inplace?branch=master&svg=true)](https://ci.appveyor.com/project/privefl/inplace)
[![Coverage status](https://codecov.io/gh/privefl/inplace/branch/master/graph/badge.svg)](https://codecov.io/github/privefl/inplace?branch=master)
 
# inplace

In-place operators for R

This is under development.

## Example

```{r}
# devtools::install_github("privefl/inplace")
library(inplace)

address <- data.table::address
mat <- matrix(rnorm(2e8), 1e4)
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
```
