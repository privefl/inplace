################################################################################

# Transform negative or boolean indices to positive indices
transform_ind <- function(k, lim) {
  
  # if (missing(k))
  #   return(seq_len(lim))
  
  if (is.character(k))
    stop2("Character subsetting is not allowed.")
  
  res <- seq_len(lim)[k]
  
  if (any(is.na(res)))
    stop2("Error when subsetting (missing values? out of bounds?)")
  
  res
}

transform_i_only <- function(i, x) {
  
  if (is.logical(i))
    stop2("Logical vector subsetting is not allowed")
  
  if (!isTRUE(all(i > 0)))
    stop2("Only positive vector subsetting is allowed")
  
  if (is.matrix(i)) {
    if (is.matrix(x)) {
      n <- nrow(x)
      m <- ncol(x)
      i <- (transform_ind(i[, 2], m) - 1) * n + transform_ind(i[, 1], n)
    } else {
      stop2("This type of accessor is only available for matrices.")
    }
  }
  
  i
}

################################################################################

is_missing_name <- function(name) {
  identical(as.character(name), "")
}

address <- data.table::address

interpret_call <- function(call, val, op) {
  
  call_list <- as.list(call)
  call_len <- length(call_list)
  print(call_len)
  print(call_list)
  parent_env <- parent.frame(n = 2)
  
  i <- j <- NULL
  
  if (call_len == 1) {                        ## x
    
    acc_append <- "all"
    x <- eval(call_list[[1]], parent_env)
    
  } else if (call_len == 3) {    
    
    x <- eval(call_list[[2]], parent_env)
    
    if (is_missing_name(call_list[[3]])) {    ## x[]
      acc_append <- "all"
    } else {                                  ## x[i]
      acc_append <- "subvec"
      i <- transform_i_only(eval(call_list[[3]], parent_env), x)
    }
    
  } else if (call_len == 4) {                 ## x[i, j] / x[, j] / x[i, ]
    
    acc_append <- "submat"
    x <- eval(call_list[[2]], parent_env)
    stopifnot(is.matrix(x))
    
    if (!is_missing_name(call_list[[3]]))
      i <- transform_ind(eval(call_list[[3]], parent_env), nrow(x))
    
    if (!is_missing_name(call_list[[4]]))
      j <- transform_ind(eval(call_list[[4]], parent_env), ncol(x))
    
    if (is.null(i) && is.null(j)) {           ## x[,] -> same as x[]
      acc_append <- "all"
    }
    
  } else if (call_len > 4) {
    
    stop2("This is not yet available for arrays.")
    
  } else {
    
    stop2(GET_ERROR_FATAL())
    
  }
  
  
  if (length(val) == 1) {
    val_append <- "one"
  } else {
    assert_lengths(x, val)
    dim(val) <- dim(x)
    val_append <- "mult"
  }
  
  list(
    fun = paste(op, acc_append, val_append, sep = "_"),
    x = x,
    i = i,
    j = j, 
    val = val
  )
}

x <- 1:5
addr0 <- address(x)
tmp <- interpret_call(substitute(x), 2, "multiply")
do.call(tmp[[1]], tmp[-1])
x
stopifnot(address(x) == addr0)

`%*<-%` <- function(call, val) {
  
  infos_call <- interpret_call(substitute(call), val, "multiply")
  print(infos_call)
  
  if (typeof(infos_call$x) == "integer") assert_int_ish(val)
  
  do.call(infos_call[[1]], infos_call[-1])
  
  invisible()
}

x <- 1:10
addr0 <- address(x)
x %*<-% 2
x
stopifnot(address(x) == addr0)
x[] %*<-% 3
x
stopifnot(address(x) == addr0)
x[] %*<-% 2.5

x <- 1:10 + 0
addr0 <- address(x)
x %*<-% 2
x
stopifnot(address(x) == addr0)
x[] %*<-% 3
x
stopifnot(address(x) == addr0)
x[] %*<-% 2.5
x
stopifnot(address(x) == addr0)

x
x[1] %*<-% 2
x


x <- matrix(1:4, 2)
x[1] %*<-% 2
x
x %*<-% 2
x
x[,] %*<-% 2
x
x[1, 1:2] %*<-% 3
x
