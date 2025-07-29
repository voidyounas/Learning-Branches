import random
import time

scoreboard = []

def welcome():
    print("Welcome to the Number Guessing Game!")
    print("Try to guess the number between 1 and 100.")
    print("You have 10 tries. Good luck!\n")

def get_username():
    name = input("Enter your name: ")
    return name

def play_game():
    number = random.randint(1, 100)
    attempts = 10
    guesses = []

    while attempts > 0:
        try:
            guess = int(input(f"Attempts left {attempts}. Enter your guess: "))
        except ValueError:
            print("Please enter a valid number.")
            continue

        guesses.append(guess)
        if guess == number:
            print(f"Correct! You guessed it in {len(guesses)} tries.")
            return len(guesses)
        elif guess < number:
            print("Too low.")
        else:
            print("Too high.")

        attempts -= 1

    print(f"Sorry! The number was {number}.")
    return None

def update_scoreboard(name, score):
    if score:
        scoreboard.append((name, score))
        scoreboard.sort(key=lambda x: x[1])
        if len(scoreboard) > 5:
            scoreboard.pop()

def show_scoreboard():
    print("\n--- Scoreboard ---")
    for i, entry in enumerate(scoreboard, 1):
        print(f"{i}. {entry[0]} - {entry[1]} tries")
    print("------------------\n")

def main():
    welcome()
    while True:
        name = get_username()
        score = play_game()
        update_scoreboard(name, score)
        show_scoreboard()

        again = input("Play again? (y/n): ").lower()
        if again != 'y':
            print("Thanks for playing!")
            break
        print("\nRestarting...\n")
        time.sleep(1)

if __name__ == "__main__":
    main()
