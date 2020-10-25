# Notes
> List of notes I take while solving the problems of lab-1 contest

- [x] Full Synergy Team
- [x] Wizard Party

## 1. Full Synergy Team
> The problem is simple..We need to get team with maximum length that each member in the team (directly connected) with all his team's members

1. Generate all possible subset (team possible)
2. For each team
 - for each team member
    1. Check if he is connected with all other team members
    2. If: there is a member of that team not connected with all other members
      - Invalid team
    3. Else:
      - Valid team..maximize currect length of the team so far

  

### Notes

- to generate all the subsets (possible team) efficently, you can use power set method 
- I have already explained powerset method in this [video](https://youtu.be/DvBjwKGTSDE), [GeeksForGeeks tutorial](https://www.geeksforgeeks.org/power-set/)

### FOR NERDs

- This problem is called *Max Clique* problem which is defined as complete subgraph with maximum length
- This problem has an efficient way of solving it, I have already implemented before [here](https://github.com/AbdallahHemdan/cp__training/blob/master/Graphs__utilities/Max%20Clique.cpp)
