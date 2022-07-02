# Chess
Chess using Minimax Algorithm with Alpha-Beta Pruning
## About Players
  * Black Player Generates random moves
    * Refer to ***humanPlayer*** class for Random moves generation implementaion
  * White Player Generates moves using MiniMax Algorithm
    * Refer to ***Hell Bishop's*** Class for the MiniMax Implementation
    
## About Hell Bishop's Class Functions used in Algorithm

### Function is based on weights assigned to each piece on the chess board. 
* The function which decides that which move is to be selected from a given list of possible moves is ***decideMove***.
  #### Decide Move Function
  * This function, calls function ***getindex*** to decide a move from a given list of moves.
  * This function initially sets ***moveindex*** (the index from the list of moves that is to be selected) to -1 and sets alpha to minimum and beta to maximum which further will be used in alpha-beta pruning.
  #### Minimax Function
* Minimax function implements the minimax algorithm with alpha beta pruning in recursive manner. Minimax function has the base case of depth equals to 0 from where it calls the function **evaluate**. MiniMax Function contains a loop which traverses the entire list of possible moves. It applies each move one by one and for each move it checks all possible moves of the opponent. And when we hit the leaf nodes i.e., depth becomes 0, it calls the function ***evaluate***.

* The recursion works in such manner that after applying each move, the minimax function calls itself again, decreasing depth by 1 and sending black as the player. This means that we are one level down in the tree and now its black turn to pick its move. 
 
  #### Evaluate Function
  * The Function computes the sum of the entire board based on the weights of pieces and returns the sum.
  * The function is combination of Piece count and weightages it is inspired from hand-crafted evaluation function.

Note:
If max depth is not passed from chess::playGame() as a parameter then by default depth 3 will be used as maximum depth for our minimax algorithm.

