# 42Cursus-Push-Swap

This project is a core component of the 42 Lisboa curriculum, focusing on developing a program in C to implement the most efficient sorting algorithm possible, using only two stacks and a predefined set of operations.

The program begins with a stack filled with a list of numbers provided as input parameters. The goal is to sort this stack in ascending order using the help of a second stack and selecting the most efficient movements between the two stacks to achieve the sorting with the minimum possible number of operations. The program outputs all the movements performed.

Additionally, a checker program has been implemented. This checker receives the movements through standard input and the list of numbers as a parameter. It verifies whether the movements successfully sorted the stack. The output of the checker is either `OK` if the sorting is correct or `KO` if it is not.

For more informations see the project [subject](https://github.com/dspereira/42Cursus-Push-Swap/blob/main/subject.pdf).

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

## Movements
Note: a is the unsorted stack, and b is the auxiliary stack used to assist with sorting.

`sa (swap a)` : Swap the first 2 elements at the top of stack a.
Do nothing if there is only one or no elements.

`sb (swap b)` : Swap the first 2 elements at the top of stack b.
Do nothing if there is only one or no elements.

`ss` : sa and sb at the same time.

`pa (push a)` : Take the first element at the top of b and put it at the top of a.
Do nothing if b is empty.

`pb (push b)` : Take the first element at the top of a and put it at the top of b.
Do nothing if a is empty.

`ra (rotate a)` : Shift up all elements of stack a by 1.
The first element becomes the last one.

`rb (rotate b)` : Shift up all elements of stack b by 1.
The first element becomes the last one.

`rr` : ra and rb at the same time.

`rra (reverse rotate a)` : Shift down all elements of stack a by 1.
The last element becomes the first one.

`rrb (reverse rotate b)` : Shift down all elements of stack b by 1.
The last element becomes the first one.

`rrr` : rra and rrb at the same time.

## Example
![push_swap](https://github.com/dspereira/42Cursus-Push-Swap/blob/main/example.png)

## License
This project is licensed under the [MIT License](https://github.com/dspereira/42Cursus-Push-Swap/blob/main/LICENSE).
