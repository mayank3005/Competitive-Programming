Graphs : 
####### Dijkstra's algo works only when the distance/cost is monotonic.

Dijkstra may or may not work for negative edges . 

      A
     / \
    B---C 

if A->B is 5 and A->C is 6 and B->C is -2 , dijkstra will fail.

-- Since Dijkstra follows a Greedy Approach, once a node is marked as visited it cannot be reconsidered even if there is another path with less cost or distance. This issue arises only if there exists a negative weight or edge in the graph.
