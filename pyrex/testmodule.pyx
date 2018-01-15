# grab symbol 'test' from header file
cdef extern from "test.h":
	char* test(char* s)

# call grabbed test from within Python
def test_fn(s):
	return test(s)
