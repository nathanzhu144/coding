/**
*  znathan 4/20/2018
*  
*  This is an implementation of an efficient way to solve the stock-span problem
*  in O(n) time instead of O(n^2) time with the use of a stack.  
*
*  The stack keeps track of the list of highest stock prices relevant to each current
*  stock span calculation.
*  
*  Ex. Days      0    1    2    3    4    5 
*      Prices   100   80   60   70  71  102
*
*
*      On day 2 the stack will look like this:
*
*                   |  2  | 
*                   |  1  |
*                   |  0  |
*
*      The array of stock spans should look like this {1, 1, 1, ?, ?, ?}
*
*
*      On day 3 the stack will look like this:
*
*                   |  3  | 
*                   |  1  |
*                   |  0  |
*
*      The array of stock spans should look like this {1, 1, 1, 2, ?, ?}
*
*
*      On day 4 the stack will look like this:
*
*                   |  4  | 
*                   |  1  |
*                   |  0  |
*
*      The array of stock spans should look like this {1, 1, 1, 2, 3, ?}
*    
*
*      On day 5 the stack will look like this:
*
*                   |  5  | 
*
*      The array of stock spans should look like this {1, 1, 1, 2, 3, 6}
*/
#include <iostream>
#include <stack>

 

void calculate_span(int price[], int n, int S[])
{
    S[0] = 1;                                  //first day always has a span of 1

    std::stack<int> st;  
    st.push(0);                                //st is an index of days, keeps track of largest elements

    for(int i = 1; i < n; ++i){
        while(!st.empty() && price[st.top()] <= price[i])
            st.pop();

        if(st.empty())
            S[i] = i + 1;
        else
            S[i] = i - st.top();

        st.push(i);
    }
}
 
// A utility function to print elements of array
void print_array(int arr[], int n)
{
    for (int i = 0; i < n; i++)
      std::cout << arr[i] << " ";
}
 
// Driver program to test above function
int main()
{
    int price[] = {10, 4, 5, 90, 120, 80};
    int n = sizeof(price)/sizeof(price[0]);
    int S[n];
 
    // Fill the span values in array S[]
    calculate_span(price, n, S);
 
    // print the calculated span values
    std::cout << "stock span of array {10, 4, 5, 90, 120, 80} is ";
    print_array(S, n);
    std::cout << std::endl;


    int price2[] = {100, 80, 60, 70, 71, 102};
    int n2 = sizeof(price2)/sizeof(price2[0]);
    int S2[n2];
    calculate_span(price2, n2, S2);

    std::cout << "stock span of array {100, 80, 60, 70, 71, 102} is ";
    print_array(S2, n2);
    std::cout << std::endl;

 
    return 0;
}