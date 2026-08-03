# Syntax

## Case-sensitive

- input a; and input A; // are different
- reg and REG are different.

## Identifiers / Variables

- May begin `a-z` or `A-Z` or `_`
- can contain`$` but not startwith `$`

## Assign keyword

- as soon as RHS changes, LHS changes

```text
assign out = a&b;
```