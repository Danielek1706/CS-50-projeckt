# TODO

def get_int (prompt):

# A function that takes an integer from the user.
    while True:
        try:
            return int(input(prompt))
        except ValueError:
            print("Invalid input. Please enter a positive integer.")


height = get_int("Height: ")

# Check that the specified height is between 1 and 8
while height < 1 or height > 8:
    print("Height must be between 1 and 8")
    height = get_int("Height: ")



# Generating a double pyramid and displaying it
for i in range(1, height + 1):
    spaces = " " * (height - i)

    # Generation of '#' blocks to the left and right of the space for each level
    blocks_left = "#" * i
    blocks_right = "#" * i

    # Displaying the current level of the double pyramid with corresponding intervals
    print(spaces + blocks_left + "  " + blocks_right)

