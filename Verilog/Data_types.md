# Number Specifications

- Numbers in verilog are by default `decimal`
- Numbers can be represented as `decimal`, `binary`, `octal`, `hexadecimal`

## SIZED: with base format

- SYNTAX: \<size> \<base_format> \<number>
- Base format: {b -  binary, d - decimal, o - octal, h - hexa}
- Ex: 16'h16ad; // hexadecimal
- Ex: 32'h12F5_DCB5; // `_` seperates 16 bit numbers
- Numbers without base format = DECIMAL by default