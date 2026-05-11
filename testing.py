import numpy as np

def rayleigh_quotient(m1: np.ndarray, v1: np.ndarray) -> float:
    numerator = np.dot(v1.T, m1 @ v1)
    denominator = np.dot(v1.T, v1)
    return numerator / denominator

# Testing
m1 = np.array([
    [1, 2, 3],
    [4, 5, 6],
    [7, 8, 9]
])

v1 = np.array([4, 5, 6])

print(rayleigh_quotient(m1, v1))

# Inner product logic correct, rayleigh quotient had mismatch. Check if it is fixed now.