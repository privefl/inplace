x <- 1:10
x[1:2] <- 3:4
.Last.value  ## 3:4
x[1:2] <- 1
.Last.value  ## 1
x[1:2] = 2
.Last.value  ## 2


x[1:2] <- x[1:2] * 2
.Last.value  ## 4:8

1:10 * 1:2
