# push_swap
Sort a random list of integers using the smallest number of moves, 2 stacks and a limited set of operations. 
You start with two empty stacks: a and b. You are given a random list of integers via command line arguments. 

Only these moves are allowed:

| instructions  | Description   |
|:-------------:|---------------|
| sa            | swap first two elements of stack A |
| sb            | swap first two elements of stack B |
| ss            | sa and sb at the same time |
| pa            | pops the first elememt on B and puts it on top of A |
| pb            | pops the first elememt on A and puts it on top of B |
| ra            | rotates stuck A up by one|
| rb            | rotates stuck B up by one |
| rr            | rotates both A and B up by one |
| rra           | rotates stuck A down by one |
| rrb           | rotates stuck B down by one |
| rrr           | rotates both A and B down by one |
## Visualizer
![Image alt](https://github.com/osmosx/push_swap/blob/main/img/push_swap.gif)
## Usage
Run ```make```.

The **push_swap** program is used in the same way
```c
  ./push_swap 5 2 3 1 4
```
You can run the two together using:
```c
  ARG=`ruby -e "puts (0..100).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker -v $ARG
```
