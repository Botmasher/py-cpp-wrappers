from mymodulegen import generate
module_fname = os.path.join("build", "test-module-binding.cc")
with open(module_fname, "wt") as file_:
	print("Generating file {}".format(module_fname))
	generate(file_)

## After build/test-module-binding.cc is generated
## then use it as a source file for the extension
testmodule = Extension('testmodule',
                     sources = [module_fname, 'test-module.cc'],
                     include_dirs=['.'])

## Setting up system to make sure module is found by Python runtime:
## 	$ python setup.py build
## 	$ export PYTHONPATH=build/lib.linux-x86_64-2.7/
