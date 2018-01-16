import pybindgen
import sys

mod = pybindgen.Module('TestModule')

mod.add_include('"test.h"')

## no params no return
# mod.add_function('test_func', None, [])

## return value and multiple params
# modd.add_function('test_func', pybindgen.retval('int'), [pybindgen.param('int', 'a'), pybindgen.param('int', 'b')])

## param and return pointer
mod.add_function('test_func', pybindgen.retval('char*', caller_owns_return=False), [pybindgen.param('char*', 'txt', transfer_ownership=False)])

mod.generate(sys.stdout)
