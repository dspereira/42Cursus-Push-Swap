# 42Cursus-Push-Swap

## Installation / Usage

This project is designed to work on Linux and macOS.

### push_swap
Clone repo:
```shell
git clone git@github.com:dspereira/42Cursus-Push-Swap.git push_swap && cd push_swap
```

Build:
```shell
make
```

Usage example:
```shell
./push_swap [list of numbers]
```
Example:
```shell
 ./push_swap 3 2 1 0
```

### checker
Build:
```shell
make checker
```
Usage example:
```shell
./push_swap [list of numbers] | ./checker [list of numbers]
```
Examples:
```shell
./push_swap 3 2 1 0 | ./checker 3 2 1 0
```
```shell
ARG="3 2 1 0"; ./push_swap $ARG | ./checker $ARG
```

## Example
![push_swap](https://github.com/dspereira/42Cursus-Push-Swap/blob/main/example.png)

## License
This project is licensed under the [MIT License](https://github.com/dspereira/42Cursus-Push-Swap/blob/main/LICENSE).
