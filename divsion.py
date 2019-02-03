# polynomial division, modulo and gc


# input: coefficients of polynomials as a lists u, v != 0
# in order u[0] = free coefficient of u(x), ....
# returns polynomials q, r such that u = vq + r(rest)
# lengthu >= length v >= 0
def poly_divide(u, v):
	m =   len(u) - 1
	n =   len(v) - 1
	q = [0] * (m - n + 1)
	lim = m - n
	for k in range(lim, -1, -1):
		q[k] = u[n + k] / v[n]
		for j in range(n + k - 1, k - 1, -1):
			u[j] = u[j] - q[k] * v[j - k]
	return q, u[:n]
	
	
# polynomial u modulo v
def poly_mod(u, v):
	return poly_divide(u, v)[1]

def poly_gcd(u, v):
	if not any(v): return u
	else: return poly_gcd(v, poly_mod(u, v))

print(poly_divide([0, 0, 0, 0], [1, 1]))
print (poly_gcd([1, 1, 1], [1, 1, 1]))


