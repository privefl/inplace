
x <- matrix(runif(1e8), 1e4)
y <- rowMeans(x)
system.time(
  tmp <- sweep(x, 2, y, '*')
)

system.time(
  sweep2_in_place(x, y, '*')
)
stopifnot(identical(x, tmp))

system.time(
  tmp <- sweep(x, 2, 1)
)

system.time(
  sweep2_in_place(x, 1)
)
stopifnot(identical(x, tmp))


# do scale with always center and maybe sd