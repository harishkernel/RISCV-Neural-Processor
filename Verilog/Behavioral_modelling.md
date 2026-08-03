## Continous

- assignments of data to o/p are continous using `assign` keyword

## Procedural

- implemented using `always` or `initial`
- when change in `sensitivity list = @(x, y)` if either of them changes
- the subsequent block gets executed

```text
reg out;
input s, a;
assign sbar ~= s;
always @(a, s)
    output = a & sbar;
```