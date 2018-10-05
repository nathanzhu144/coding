/** 
 * Nathan Zhu 0-1 knapsack DP August 2nd, 2018. 9:28 am in Beijing China.
 * http://oucsace.cs.ohiou.edu/~razvan/courses/cs4040/lecture16.pdf
 * 
 * ///////////////////////////////
 * //      Problem spec         //
 * ///////////////////////////////
 * 
 * There are n items,                      x1, x2, x3, ... xN-1, xN.
 * Each item has a weight                  w1, w2, w3, ... wN-1, wN.
 * We get a profit from selling each item, p1, p2, p3, ... pN-1, pN.
 * 
 * Of each item, we can either take the item or not take the item.
 * 
 * We can only choose (1) or not choose (0) each item, and we seek to
 * maximize total profits, while keeping within the weight constraint.
 * 
 * //////////////////////////////
 * //      Conceptual          //
 * //////////////////////////////
 * 
 * KNAP(1, n, M) denote the 0/1 Knapsack problem, choosing objects
 * from [1..n] under the capacity constraint of M.
 * 
 * If (x1, x2, ...,xN) is an optimal solution for 
 * the problem KNAP(1, n, M), then:
 * 
 *    1. if xN is 0, we do not choose the n-th object, then
 *       (x1, x2, ...,xN-1) must be an optimal solution of
 *       KNAP(1, n-1, M).
 * 
 *    2. if xN is 1, we choose the nth object, then 
 *       (x1, x2, ...xN-1) must be an optimal solution of
 *       KNAP(1, n-1, M - wN)
 * 
 * 
 * //////////////////////////////
 * //      Implementation      //
 * //////////////////////////////
 * 
 * Let C[n, M] be the total profits of the optimal solution for 
 * KNAP(1, n, M).
 * 
 * Let C[n, M] = max( profits for case 1, profits for case 2 ),
 *             = max( C[n - 1, M], C[n - 1, M - wN] + pN )
 * 
 * For example, if n = 4, weight constraint is (M) is 9, 
 *             w4 is 4, p4 is 2, then
 * 
 *             C[4, 9] = max( C[3, 9], C[3, 9 - 4] + 2).  
 * 
 * This can be done in a 2d table.  
 * 
 * 
 * Let C[i, m] be a cell in the table C, which represents the 
 * total profits of the optimal solution for the problem 
 * KNAP(1, i, m), which is the subproblem of selecting items
 * in [1..i] subject to the capacity constraint m.
 * 
 * Then, C[i, m] = max( C[i - 1, m], C[i - 1, m - wM] + pM)
 * 
 * 
 * Boundary conditions
 *
 * */