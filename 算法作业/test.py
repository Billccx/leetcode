import numpy as np
norm = np.ones((32, 2)) * np.array([56, 56]) / 10
print(norm.shape)

a=np.random.rand(32,21,2)
print(a.shape)
print(np.linalg.norm(a,axis=-1))