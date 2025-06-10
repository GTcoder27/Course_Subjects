import random
import keyboard

GRID_SIZE = int(input("Enter Wumpus World size (e.g., 4 for 4x4): "))

# Create grid
grid = [['.' for _ in range(GRID_SIZE)] for _ in range(GRID_SIZE)]

# Place pits
for _ in range(random.randint(3, 5)):
    x = random.randint(0, GRID_SIZE - 1)
    y = random.randint(0, GRID_SIZE - 1)
    if (x, y) != (0, 0) and grid[x][y] == '.':
        grid[x][y] = 'P'

# Place Wumpus
while True:
    x = random.randint(0, GRID_SIZE - 1)
    y = random.randint(0, GRID_SIZE - 1)
    if (x, y) != (0, 0) and grid[x][y] == '.':
        grid[x][y] = 'W'
        break

# Place Gold
while True:
    x = random.randint(0, GRID_SIZE - 1)
    y = random.randint(0, GRID_SIZE - 1)
    if (x, y) != (0, 0) and grid[x][y] == '.':
        grid[x][y] = 'G'
        break

# Starting position
agent_x, agent_y = 0, 0

# Function to print grid
def print_grid(show_all=False):
    for i in range(GRID_SIZE):
        for j in range(GRID_SIZE):
            if i == agent_x and j == agent_y:
                print('A', end=' ')
            else:
                if show_all:
                    print(grid[i][j], end=' ')
                else:
                    if grid[i][j] == 'G':
                        print('G', end=' ')
                    else:
                        print('.', end=' ')
        print()
    print()

# Function to check surroundings
def sense_environment(x, y):
    breeze = False
    stench = False
    directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]  # Up, Down, Left, Right
    for dx, dy in directions:
        nx, ny = x + dx, y + dy
        if 0 <= nx < GRID_SIZE and 0 <= ny < GRID_SIZE:
            if grid[nx][ny] == 'P':
                breeze = True
            elif grid[nx][ny] == 'W':
                stench = True
    if breeze:
        print("You feel a breeze.")
    if stench:
        print("You smell a stench.")

print("Use arrow keys (↑ ↓ ← →) to move. Press Esc to exit.\n")
print_grid()  # Initial grid before first move
sense_environment(agent_x, agent_y)

# Game loop
while True:
    event = keyboard.read_event()
    if event.event_type == keyboard.KEY_DOWN:
        key = event.name

        dx, dy = 0, 0
        if key == 'up':
            dx, dy = -1, 0
        elif key == 'down':
            dx, dy = 1, 0
        elif key == 'left':
            dx, dy = 0, -1
        elif key == 'right':
            dx, dy = 0, 1
        elif key == 'esc':
            print("Game exited.")
            break
        else:
            print("Invalid key! Use only ↑ ↓ ← →")
            continue

        new_x = agent_x + dx
        new_y = agent_y + dy

        if 0 <= new_x < GRID_SIZE and 0 <= new_y < GRID_SIZE:
            agent_x, agent_y = new_x, new_y
        else:
            print("Cannot move outside the grid!")
            continue

        # Check position after move
        if grid[agent_x][agent_y] == 'P':
            print_grid(show_all=True)
            print("You fell into a Pit! Game Over!")
            break
        elif grid[agent_x][agent_y] == 'W':
            print_grid(show_all=True)
            print("You met the Wumpus! Game Over!")
            break
        elif grid[agent_x][agent_y] == 'G':
            print_grid(show_all=True)
            print("You found the Gold! You Win!")
            break

        print_grid()
        sense_environment(agent_x, agent_y)
