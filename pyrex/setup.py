from distutils.core import setup
from distutils.extension import Extension
from Pyrex.Distutils import build_ext

# run 'setup.py build_ext –inplace' and then you can 'import testmodule; testmodule.test_fn'
setup(
	name = "test",
	ext_modules=[ Extension("testmodule", ["testmodule.pyx", "test.cc"]) ],
	cmdclass = {'build_ext': build_ext}
)
