<img width="1519" alt="alog" src="https://user-images.githubusercontent.com/43186742/97775896-f7a2ed80-1b6c-11eb-9396-4753cb5ad678.png">


solutions for contests and labs for CMP302_A6 course (algorithms course) for Cairo University Faculty of Engineering: where you can find the solutions after the contest is done

> you should add your solutions under a folder with your name 
and this folder should be under the contest folder.
example
```
contest1/mahboub
```


### CMP302-Fall2020-Lab1

#### 1. Full Synergy Team
> The problem is simple..We need to get team with maximum length that each member in the team (directly connected) with all his team's members

1. Generate all possible subset (team possible) using power-set
2. For each team
 - for each team member
    1. Check if he is connected with all other team members
    2. If: there is a member of that team not connected with all other members
      - Invalid team
    3. Else:
      - Valid team..maximize currect length of the team so far

  

#### Notes

- to generate all the subsets (possible team) efficently, you can use power set method 
- I have already explained powerset method in this [video](https://youtu.be/DvBjwKGTSDE), [GeeksForGeeks tutorial](https://www.geeksforgeeks.org/power-set/)

#### FOR NERDs

- This problem is called *Max Clique* problem which is defined as complete subgraph with maximum length
- This problem has an efficient way of solving it, I have already implemented before [here](https://github.com/AbdallahHemdan/cp__training/blob/master/Graphs__utilities/Max%20Clique.cpp)


### 2. Wizard Party
> Simply the problem ask you to check if there is a cycle pass throght all nodes exactly on

1. Generate all possible combination of number from (1 to n -1)
2. Append 0 to the first (since it's our start node)
3. Push pack 0 to the end (since it's our end node)
4. For each cycle check if the current cycle is exists
 1. Loop for each 2 nodes in the cycle check if their is an edge between them
 2. If: a cycle exists
  - Terminate (no need to continue..we already got a solution)
 3. Else: 
  - Continue processing

#### Notes

-  to generate all the permutions of an array u can use `next_permutation`
- For more info about next_permutation check [this](https://www.geeksforgeeks.org/find-the-next-lexicographically-greater-word-than-a-given-word/) link

```cpp
do{
 // put your logic here
}while(next_permutaion(arr.begin(), arr.end());
```
#### Study Resources

- [Recursion I](https://leetcode.com/explore/featured/card/recursion-i/)

- [Recursion II](https://leetcode.com/explore/learn/card/recursion-ii/)

