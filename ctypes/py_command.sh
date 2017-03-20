
import ctypes

# ---------------------- #
# Load `sqrt' from dynlib. 

dyn = ctypes.CDLL('./dynlib.so')
sqrt = dyn.sqrt

sqrt.argtypes = [ctypes.c_double] # default: None
sqrt.restype  =  ctypes.c_double  # default: c_int

print( "sqrt(5) = %f." % sqrt(5), '\n' )

# ---------------------- #
# Using Struct.

class Point(ctypes.Structure):
    _fields_ = [("x", ctypes.c_float), ("y", ctypes.c_float)]

p = Point()
p.x, p.y = 2, 1

reflect_y = dyn.reflect_over_yaxis
reflect_y.argtypes = [ ctypes.POINTER(Point)] 
reflect_y(p)

print( " x = %f\n" % p.x, "y = %f" % p.y )
