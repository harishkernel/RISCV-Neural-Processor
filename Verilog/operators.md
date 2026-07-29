# Bitwise operators 

## i) Unary operators(used left of operand)

- y = \&a (AND all bits of a), 
- y = \~a (NOT all bits of a), 
- y = \~\&a (NAND all bits of a), 
- y = \~|a (NOR all bits of a), 
- y = ^a (XOR all bits of a)

ex: a = 5'b10101 (5 binary, '10101')

## ii) Binary operators

- Used between two operands
- a = 3'b101, b = 3'b110

Y = (a \~^ b) - binary XNOR

## iii) Arithmetic operators

- a = 3'b101, b = 3'b100
- Y = a + b, a * b, a - b

## iv) Relational Operators

- Compares two values and returns (true: 1'b1 / false: 1'b0)
- a > b, a >= b, a < b
- NO a <= b operator in verilog (
    use a > b || a == b (or) 
    !(a > b)
)

## v) Equality operator

- ==, != (as same in other programming languages)
- ===, !== (checks each bitwise equality)

## vi) Concatenation operator {, , ......}

- combines multiples bits of data
- ex: {2'b11, a, 1'b0} - can also combine unknown values
- ex: a = 4'b1010, b = 4'b1100, c = {a, b} // c = 8'b10101100

## vii) Replication operator {N{...}}

- concats N times
- ex: x = {4{1'b1}} => 4'b1111
