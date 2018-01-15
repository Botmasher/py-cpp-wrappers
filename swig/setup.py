from distutils.core import setup, Extension

extension_mod = Extension("_swigdemo", ["_swigdemo_module.cc", "test.cc"])

setup(name = "swigdemo", ext_modules=[extension_mod])