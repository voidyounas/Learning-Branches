def main():
    try:
        num = int(input("Enter numerator: "))
        den = int(input("Enter denominator: "))

        result = num / den
        print("Result:", result)

    except ZeroDivisionError:
        print("Cannot divide by zero.")
    except ValueError:
        print("Invalid input. Please enter integers only.")
    except Exception as e:
        print("An error occurred:", e)

if __name__ == "__main__":
    main()
