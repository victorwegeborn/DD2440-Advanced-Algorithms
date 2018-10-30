# Project 1: TSP 2D

[Problem description on Kattis](https://kth.kattis.com/problems/tsp)


## Input
Your program should take as input a single TSP instance. It will be run several times, once for every test case. The time limit is per test case.

The first line of standard input contains an integer $1≤N≤1000$, the number of points. The following $N$ lines each contain a pair of real numbers $x,y$ giving the coordinates of the $N$ points. All numbers in the input have absolute value bounded by $10^6$.

The distance between two points is computed as the Euclidean distance between the two points, rounded to the nearest integer.

## Output
Standard output should consist of $N$ lines, the $i$’th of which should contain the (0-based) index of the $i$’th point visited.

## Score
Let $Opt$ be the length of an optimal tour, ValVal be the length of the tour found by your solution, and $Naive$ be the length of the tour found by the algorithm below. Define $x=(Val−Opt)/(Naive−Opt)$. (In the special case that$ Naive=Opt$, define $x=0$ if $Val=Opt$, and $x=∞$ if $Val>Opt$.)

The score on a test case is $0.02x$. Thus, if your tour is optimal, you will get 11 point on this test case. If your score is halfway between $Naive$ and $Opt$, you get roughly 0.14 points. The total score of your submission is the sum of your score over all test cases. There will be a total of 5050 test cases. Thus, an implementation of the algorithm below should give a score of at least 11 (it will get 0.02 points on most test cases, and 1.0 points on some easy cases where it manages to find an optimal solution).
