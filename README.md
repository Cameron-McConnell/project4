Create an integer array of size 5 to store horse positions
  Initialize all values to 0

Seed the random number generator

While no horse has won:
  For each horse (0–4):
    Call advance(horseNum, horses) to possibly move the horse forward
  For each horse (0–4):
    Call printLane(horseNum, horses) to display the horse’s position
    Call isWinner(horseNum, horses) to check for a winner
    If a horse has won, display a winning message
  Pause execution until the user presses Enter

End the program

advance()
Randomly determines whether a horse advances one position

printLane()
Displays a single horse’s track using dots and the horse number

isWinner()
Checks whether a horse has reached the end of the track
