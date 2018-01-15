from distutils.core import setup, Extension

# C++ extension module - see test.cc
extension_mod = Extension("test", ["testmodule.cc", "test.cc"])

setup(name = "test", ext_modules=[extension_mod])
