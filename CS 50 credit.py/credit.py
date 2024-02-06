# TODO


from cs50 import get_string

def is_valid_card(number):
    # Checking the length of the card number
    if len(number) not in [13, 15, 16]:  # Check that the card number is the correct length
        return "INVALID"

    # Checking the checksum
    total = 0
    for i in range(len(number) - 1, -1, -1):
        digit = int(number[i])
        if (len(number) - i) % 2 == 0:
            digit *= 2
            digit = digit // 10 + digit % 10
        total += digit

    if total % 10 != 0:
        return "INVALID"

   # Checking the card type
    if number[:2] in ["34", "37"]:# Check that the card number matches American Express (34 or 37)
        return "AMEX"
    elif number[:2] in ["51", "52", "53", "54", "55"]:  # Checking if the card number matches MasterCard (51-55)
        return "MASTERCARD"
    elif number[0] == "4": # Check that the card number matches Visa (starts with 4)
        return "VISA"
    else:  # If the card number does not match any type
        return "INVALID"

def main():
    number = get_string("Number: ")
    card_type = is_valid_card(number)  # Validation of the card number and its type
    print(card_type)

if __name__ == "__main__":
    main()
