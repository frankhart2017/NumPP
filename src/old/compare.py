import numpy as np
import time

start = time.time()

a = np.zeros([100, 100, 100, 100, 100])

stop = time.time()

print(stop - start)

# 6000 times faster than serial numpp
