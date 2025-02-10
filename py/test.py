import pyblokus


if __name__ == "__main__":
    match = pyblokus.BlokusMatch(4)
    match.newGame()

    moves = match.getMovesFromPos(0)
    print(moves[0])

    success = match.playMove(pyblokus.iShapeType, 0, 0, 0, 1)
    print(success)

    state = match.getState()

    print(state)
