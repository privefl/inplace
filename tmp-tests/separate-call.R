address <- data.table::address

setMethod('[', signature(x = "super_vector"), function(x, i) i + 1)


setClass("super_vector", representation(data = "numeric"))
x2 <- new("super_vector", data = x)
address(x)
address(x2)
address(x2@data)

x2[10:11, ]

tmp <- pryr::call_tree(quote(x[ind]))


pryr:::tree
tmp <- substitute(x[ind])

pryr:::tree(tmp)
stringr::str_dup("  ", 0)
label <- "()"
as.list(tmp)
children <- vapply(as.list(tmp), pryr::tree, character(1), level = level + 
                     1, width = width - 3)

separate_call <- function(call) {
  call.sep <- as.list(substitute(call))
  svec <- new("super_vector", data = get(deparse(call.sep[[2]]), envir = parent.frame()))
  print(address(svec@data))
  call.sep[[2]] <- as.name("svec")
  eval(as.call(call.sep))
}
address(x)
separate_call(x[2:3])



tmp <- as.list(substitute(x[2:3]))

mget(c(deparse(tmp[[2]]), deparse(tmp[[3]])))
class(tmp[[2]])
tmp[[2]] <- as.name("svex")
eval(as.call(tmp))


separate_call <- function(call) {
  call.sep <- as.list(substitute(call))
  parent_env <- parent.frame()
  x   <- eval(call.sep[[2]], parent_env)
  ind <- eval(call.sep[[3]], parent_env)
  list(x, ind)
}
x <- 1:10
ind <- 2:3
separate_call(x[ind])
separate_call(x[1:2])
