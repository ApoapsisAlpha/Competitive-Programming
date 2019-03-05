def f(y): print(y)
c = foo.__code__

code = type(c)(0, 3, 0, 0, c.co_code, c.co_consts[:5]+(f.__code__,), c.co_names, (), '', '', 0, '')

type(f)(code, globals())()