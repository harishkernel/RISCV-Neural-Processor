# Basics

## Matrix Multiplication:
```python
for i in range(n):
    for j in range(n):
        for k in range(n):
            c[i][k] += a[i][j] * b[j][k]
```

- p(4 bit) * q(4 bit) = `16 AND gates`


### Adders

- Full Adder (A, B, Cin) -> O1, O2 (Output-bit1, Cout)
- also called 3->2 compressor

- efficiently done using `Dadda Multiplier`
- reduces the number of partial products