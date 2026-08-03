# Number Specifications

- Numbers in verilog are by default `decimal`
- Numbers can be represented as `decimal`, `binary`, `octal`, `hexadecimal`

## SIZED: with base format

- SYNTAX: \<size> \<base_format> \<number>
- Base format: {b -  binary, d - decimal, o - octal, h - hexa}
- Ex: 16'h16ad; // hexadecimal
- Ex: 32'h12F5_DCB5; // `_` seperates 16 bit numbers
- Numbers without base format = DECIMAL by default


## Data types

- A hardware circuit can have 4 values

```text
0  - represents logic zero, false           (x < 0.8 V)
1  - represents logic one, true             (0.8V - 5V)
X  - unknown (0 / 1)
Z  - High Impedance, floating value         (any unconnected circuit can give high Z)
```


1. Net data type
    - Net (wire, trior, triand etc...)
2. Register data type
    - Register (reg, integer, real, time)

### Net data type

#### Wire
- used for continuos assignment
- wire a;
- wire [2:0] a; // a[2], a[1], a[0]


#### Register
- reg a;    // store 1 bit FF
- reg [3:0] a;  // stores 4, 1-bit-FF

#### Integer
- integer counter;
-   initial
-       counter = 1;

#### Real
- real float;
-   initial
-       float = 4e10;

#### Time
- u_int (64 bit wide)
- time sim_time;    // stores simulation time in ns


#### String
- each char = 1 byte (NOT 1 bit)
- char ~ ASCII, then converted to Binary 8 bit rep or 1 byte

Ex:
```text
module strings();
reg [8 * 28 : 0] string;

initial
begin
string = "hello world";
$display("%s\n", string);
end
endmodule
```
`O/p: hello world`