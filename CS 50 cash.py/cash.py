# TODO


from cs50 import get_float

# Main function of the programme
def main():
    # Collecting the number of cents from the user
    cents = get_cents()

    # Calculation of the number of quarters
    quarters = calculate_quarters(cents)
    cents = cents - quarters * 25

    # Calculating the number of dimes
    dimes = calculate_dimes(cents)
    cents = cents - dimes * 10

    # Calculating the number of nickels
    nickels = calculate_nickels(cents)
    cents = cents - nickels * 5

    # Calculating the number of pennies
    pennies = calculate_pennies(cents)
    cents = cents - pennies * 1

    # Adding up all the coins
    total = quarters + dimes + nickels + pennies

    # Displaying the result
    print(total)

# Function to collect the number of cents from the user
def get_cents():
    while True:
        change = get_float("Change owed: ")
        if change >= 0:
            break
    cents = round(change * 100)
    return cents

# Function to calculate the number of quarters
def calculate_quarters(cents):
    count = 0
    while cents >= 25:
        cents = cents - 25
        count += 1
    return count

# Function to calculate the number of dimes
def calculate_dimes(cents):
    count = 0
    while cents >= 10:
        cents = cents - 10
        count += 1
    return count

# Function to calculate the number of nickels
def calculate_nickels(cents):
    count = 0
    while cents >= 5:
        cents = cents - 5
        count += 1
    return count

# Function to calculate the number of pennies
def calculate_pennies(cents):
    count = 0
    while cents >= 1:
        cents = cents - 1
        count += 1
    return count

# Running the programme if it's a master file
if __name__ == "__main__":
    main()




