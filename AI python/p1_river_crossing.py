
def is_valid_state(state):  
    man, tiger, cow, grass = state  
    if tiger == cow and man != cow:  
        return False  
    if cow == grass and man != cow:  
        return False  
    return True  

def get_next_states(state):  
    man, tiger, cow, grass = state  
    next_states = []  

    new_state = (1 - man, tiger, cow, grass)  
    if is_valid_state(new_state):  
        next_states.append(new_state)  

    for i, item in enumerate([tiger, cow, grass], start=1):  
        if item == man:  
            new_state = list(state)  
            new_state[0] = 1 - man  
            new_state[i] = 1 - item  
            new_state = tuple(new_state)  
            if is_valid_state(new_state):  
                next_states.append(new_state)  

    return next_states  

def solve_dfs(state, goal_state, path, visited):  
    if state == goal_state:  
        return path + [goal_state]  

    visited.add(state)  

    for next_state in get_next_states(state):  
        if next_state not in visited:  
            result = solve_dfs(next_state, goal_state, path + [state], visited)  
            if result:  
                return result  
    return None  


def get_location(state):
    if state == 1:
        return "left"
    return "right"
 

def main():  
    print("Enter the initial state:")  
    man = int(input("Man's position"))
    tiger = int(input("Tiger's position"))  
    cow = int(input("Cow's position"))
    grass = int(input("Grass's position"))
    initial_state = (man, tiger, cow, grass)  

    print("\nEnter the goal state:")  
    man_goal = int(input("Man's position"))
    tiger_goal = int(input("Tiger's position")) 
    cow_goal = int(input("Cow's position"))
    grass_goal = int(input("Grass's position"))
    goal_state = (man_goal, tiger_goal, cow_goal, grass_goal)  

    visited_states = set()  
    solution_path = solve_dfs(initial_state, goal_state, [], visited_states)  

    if solution_path:  
        print("\nSolution Path:")  
        for step in solution_path:  
            man, tiger, cow, grass = step
            print(f"Man: {get_location(man)}, Tiger: {get_location(tiger)}, Cow: {get_location(cow)}, Grass: {get_location(grass)}")
    else:  
        print("No solution found.")  

        

if __name__ == "__main__":  
    main()
