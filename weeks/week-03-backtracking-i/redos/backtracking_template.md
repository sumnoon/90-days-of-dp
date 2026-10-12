backtrack(state):
    if goal is reached:
        record the answer
        return

    for each choice:
        if choice is valid
            make the choice
            backtrack(next state)
            undo the choice