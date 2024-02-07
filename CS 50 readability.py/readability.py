# TODO

from cs50 import get_string

def main():
    # Downloading a text from the user
    text = get_string("Text: ")

# Function for counting letters in a text
    count_letters = 0
    for char in text:
        if char.isalpha():  # Checking if a character is a letter
            count_letters += 1

# Function for counting words in a text
    count_words = len(text.split())# Divides the text into words and returns the length of the word list

# Function for counting sentences in the text
    count_sentences = 0
    for char in text:
        if char in ['.', '!', '?']: # Checking if a character is the end of a sentence
            count_sentences += 1

# Calculation of average number of letters per 100 words (L) and average number of sentences per 100 words (S)
    L = (count_letters / count_words) * 100
    S = (count_sentences / count_words) * 100

# Calculation of Coleman-Liau readability grade
    grade = round(0.0588 * L - 0.296 * S - 15.8)#Round is used to round numbers

# Function to count sentences in the text
    if grade < 1:
        print("Before Grade 1")
    elif grade >= 16:
        print("Grade 16+")
    else:
        print(f"Grade {grade}")

if __name__ == "__main__":
    main()
