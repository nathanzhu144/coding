

def jump_game_greedy(arr):
    mem = [False for i in arr]

    mem[0] = True

    max_so_far = 0

    for i in range(arr):
        if i > max_so_far:
            break
        
        
