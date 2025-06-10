import random

class WumpusWorld:
    """
    Manages the game logic, state, and visualization for the Wumpus World problem.
    """

    def __init__(self, size=4):
        """Initializes the game environment."""
        self.size = size
        self.agent_pos = [0, 0]  # Agent starts at the top-left corner (row, col)
        
        # Game elements' positions will be stored as tuples (row, col)
        self.wumpus_pos = None
        self.gold_pos = None
        self.pit_pos = set()

        # Game state flags
        self.game_over = False
        self.game_won = False
        
        # Set up the board
        self._place_elements()

    def _place_elements(self):
        """
        Randomly places the Wumpus, Gold, and 3 Pits on the grid,
        ensuring the starting cell (0, 0) is safe.
        """
        # Get all possible cells except the starting one
        possible_cells = [(r, c) for r in range(self.size) for c in range(self.size) if (r, c) != (0, 0)]
        
        # Randomly choose 5 unique cells for 1 Wumpus, 1 Gold, and 3 Pits
        chosen_cells = random.sample(possible_cells, 5)
        
        self.wumpus_pos = chosen_cells[0]
        self.gold_pos = chosen_cells[1]
        self.pit_pos = set(chosen_cells[2:])

    def display_grid(self, reveal=False):
        """
        Displays the current state of the grid.
        - During gameplay (reveal=False), only the agent's position is shown.
        - At the end (reveal=True), all elements are shown.
        """
        print("\n" + "="*15)
        for r in range(self.size):
            row_str = ""
            for c in range(self.size):
                if self.agent_pos == [r, c]:
                    row_str += "[A] "
                elif reveal:
                    if (r, c) == self.wumpus_pos:
                        row_str += "[W] "
                    elif (r, c) == self.gold_pos:
                        row_str += "[G] "
                    elif (r, c) in self.pit_pos:
                        row_str += "[P] "
                    else:
                        row_str += "[-] "
                else:
                    row_str += "[-] "
            print(row_str)
        print("="*15)

    def move(self, direction):
        """
        Moves the agent based on user input and checks grid boundaries.
        """
        r, c = self.agent_pos
        
        if direction == 'up':
            r -= 1
        elif direction == 'down':
            r += 1
        elif direction == 'left':
            c -= 1
        elif direction == 'right':
            c += 1

        # Check for wall collision
        if 0 <= r < self.size and 0 <= c < self.size:
            self.agent_pos = [r, c]
            print(f"Agent moved {direction} to {self.agent_pos}")
        else:
            print("Ouch! You hit a wall. 🧱")

    def _check_status(self):
        """
        Checks the agent's current cell for game-ending conditions.
        """
        agent_pos_tuple = tuple(self.agent_pos)
        
        if agent_pos_tuple == self.wumpus_pos:
            print("\nOh no! You were eaten by the Wumpus! 👹")
            self.game_over = True
        elif agent_pos_tuple in self.pit_pos:
            print("\nAaaaaah! You fell into a pit! 💀")
            self.game_over = True
        elif agent_pos_tuple == self.gold_pos:
            print("\nCongratulations! You found the gold! 🏆")
            self.game_over = True
            self.game_won = True
            
    def play(self):
        """
        Starts and manages the main game loop.
        """
        print("--- Welcome to Wumpus World! ---")
        print("Commands: 'up', 'down', 'left', 'right' to move. 'quit' to exit.")
        print("Find the Gold [G] while avoiding the Wumpus [W] and Pits [P].")
        
        while not self.game_over:
            self.display_grid()
            command = input("Enter your move: ").lower().strip()

            if command in ['up', 'down', 'left', 'right']:
                self.move(command)
                self._check_status()
            elif command == 'quit':
                print("Exiting game. Better luck next time!")
                break
            else:
                print("Invalid command. Please try again.")

        # Game over sequence
        if self.game_over:
            print("\n--- GAME OVER ---")
            self.display_grid(reveal=True)

# --- Main execution block ---
if __name__ == "__main__":
    game = WumpusWorld()
    game.play()


    