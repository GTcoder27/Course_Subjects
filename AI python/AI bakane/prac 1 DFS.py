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

def get_user_input(prompt):  
    while True:  
        try:  
            value = int(input(prompt + " (0 for right, 1 for left): "))  
            if value in (0, 1):  
                return value  
            else:  
                print("Invalid input. Enter 0 or 1.")  
        except ValueError:  
            print("Invalid input. Please enter a number.")  

def main():  
    print("Enter the initial state:")  
    man = get_user_input("Man's position")  
    tiger = get_user_input("Tiger's position")  
    cow = get_user_input("Cow's position")  
    grass = get_user_input("Grass's position")  
    initial_state = (man, tiger, cow, grass)  

    print("\nEnter the goal state:")  
    man_goal = get_user_input("Man's position")  
    tiger_goal = get_user_input("Tiger's position")  
    cow_goal = get_user_input("Cow's position")  
    grass_goal = get_user_input("Grass's position")  
    goal_state = (man_goal, tiger_goal, cow_goal, grass_goal)  

    visited_states = set()  
    solution_path = solve_dfs(initial_state, goal_state, [], visited_states)  

    if solution_path:  
        print("\nSolution Path:")  
        for step in solution_path:  
            man, tiger, cow, grass = ["left" if x == 1 else "right" for x in step]  
            print(f"Man: {man}, Tiger: {tiger}, Cow: {cow}, Grass: {grass}")  
    else:  
        print("No solution found.")  

if __name__ == "__main__":  
    main()
