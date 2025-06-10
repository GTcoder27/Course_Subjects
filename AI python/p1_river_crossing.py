def is_valid(state):
    bank1, bank2 = state
    for bank in [bank1, bank2]:
        if 'M' not in bank:
            if 'T' in bank and 'C' in bank:
                return False  # Tiger eats Cow
            if 'C' in bank and 'G' in bank:
                return False  # Cow eats Grass
    return True

def move(state, item):
    bank1, bank2 = state
    if 'M' in bank1:
        new_bank1 = bank1.copy()
        new_bank2 = bank2.copy()
        new_bank1.remove('M')
        new_bank2.append('M')
        if item != 'M':
            new_bank1.remove(item)
            new_bank2.append(item)
    else:
        new_bank1 = bank1.copy()
        new_bank2 = bank2.copy()
        new_bank2.remove('M')
        new_bank1.append('M')
        if item != 'M':
            new_bank2.remove(item)
            new_bank1.append(item)
    return (sorted(new_bank1), sorted(new_bank2))

def dfs(state, visited, path):
    bank1, bank2 = state
    if sorted(bank2) == ['C', 'G', 'M', 'T']:
        return path

    visited.add((tuple(bank1), tuple(bank2)))

    current_bank = bank1 if 'M' in bank1 else bank2
    for item in current_bank:
        next_state = move(state, item)
        if is_valid(next_state) and (tuple(next_state[0]), tuple(next_state[1])) not in visited:
            result = dfs(next_state, visited, path + [next_state])
            if result:
                return result
    return None

initial_state = (['M', 'T', 'C', 'G'], [])
solution = dfs(initial_state, set(), [initial_state])

for i, step in enumerate(solution):
    print(f"Step {i}: Bank1 = {step[0]}, Bank2 = {step[1]}")




