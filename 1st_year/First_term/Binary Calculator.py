# Ali Atef 20230236
# Moaaz Ahmed 2023040
#Mohamed Ayman Afifi 20230618


def check_valid_input(binary_number):

    """Checks if the input is a valid binary number."""
    stop = False
    for i in binary_number:
        if i == "0" or i == "1":
            continue
        else:
            print("please insert a valid binary number")
            stop = True
            break

    if stop == True:
        return False


def first_complement(binary_number):
    first_comp = []
    for i in range(len(binary_number)):
        first_comp.append(binary_number[i])

    for i in range(len(first_comp)):
        if first_comp[i] == "0":
            first_comp[i] = "1"
        else:
            first_comp[i] = "0"

    # printing the one's complement....
    print("the one's complement of the binary number is: ", end="")
    for i in first_comp:
        print(i, end="")
    print()


def addition(first_binary_number, second_binary_number):
    # checking if the number of digits are equal....
    if len(binary_number) != len(second_binary_number):

        if len(first_binary_number) > len(second_binary_number):
            second_binary_number = "0" * (len(first_binary_number) - len(second_binary_number)) + second_binary_number
        else:
            first_binary_number = "0" * (len(second_binary_number) - len(first_binary_number)) + first_binary_number

    # adding the binary numbers....
    result = ""
    bit_sum = 0
    carry = 0
    for i in range(len(first_binary_number) - 1, -1, -1):
        bit_sum = int(first_binary_number[i]) + int(second_binary_number[i]) + carry
        result = str(bit_sum % 2) + result
        carry = bit_sum // 2

    if carry == 1:
        result = "1" + result

    # printing the result....
    print("the result of the addition is: " + result)


def second_complement(binary_number):
    binary_number_reversed = binary_number[::-1]
    # computing the two's complement....
    second_complement_reversed = []
    for i in range(len(binary_number_reversed)):
        if binary_number_reversed[i] == "1":
            second_complement_reversed.append("1")
            i += 1

            while i < len(binary_number_reversed):
                if binary_number_reversed[i] == "1":
                    second_complement_reversed.append("0")

                else:
                    second_complement_reversed.append("1")

                i += 1

            break

        else:
            second_complement_reversed.append("0")

    second_complement = second_complement_reversed[::-1]

    # printing the two's complement....
    print("the two's complement of the binary number is: ", end="")
    for i in second_complement:
        print(i, end="")
    print()


def subtraction(first_binary_number, second_binary_number):
    # checking if the number of digits are equal....
    if len(first_binary_number) != len(second_binary_number):

        if len(first_binary_number) > len(second_binary_number):
            second_binary_number = "0" * (len(first_binary_number) - len(second_binary_number)) + second_binary_number
        else:
            first_binary_number = "0" * (len(second_binary_number) - len(first_binary_number)) + first_binary_number

    # computing the subtraction....
    result = ""
    bit_sub = 0
    carry = 0
    for i in range(len(binary_number) - 1, -1, -1):
        bit_sub = int(binary_number[i]) - int(second_binary_number[i]) - carry
        if bit_sub < 0:
            bit_sub = bit_sub + 2
            carry = 1
        else:
            carry = 0
        result = str(bit_sub) + result

    #printing the result....
    print("the result of the subtraction is " + result)


while True:

    # menu1....
    print("*binary calculator*")
    print("A) Insert new numbers")
    print("B) Exit")
    print("please select a choice (A/B)")
    stop = False
    restart = False
    choice_menu1 = input()
    while True:
        if choice_menu1 == "A" or choice_menu1 == "a":
            break

        elif choice_menu1 == "B" or choice_menu1 == "b":
            print("Exiting the program. Goodbye!")
            stop = True
            break
        else:
            print(" please select a valid choice")
            restart = True

            break

    if restart == True:
        continue

    if stop == True:
        break

    # getting the binary number from the user....
    binary_number = input("Enter the binary number: ")

    # checking if the binary number is valid....
    if check_valid_input(binary_number) == False:
        continue

    # menu2....
    print("please select the operation")
    print("A) Compute one's complement")
    print("B) Compute two's complement")
    print("C) Addition")
    print("D) Subtraction")
    print("please select a choice (A/B/C/D)")

    #getting the operation from the user....
    choice_menu2 = input()

    # first choice....
    if choice_menu2.upper() == "A":

        # computing the one's complement....
        first_complement(binary_number)
        continue


    # second choice....
    elif choice_menu2.upper() == "B":
        # computing the two's complement....
        second_complement(binary_number)
        continue


    elif choice_menu2.upper() in ["C", "D"]:

        # getting the second binary number from the user....
        second_binary_number = input("Enter the second binary number: ")

        # checking if the second binary number is valid....
        if check_valid_input(second_binary_number) == False:
            continue

        # third choice....
        if choice_menu2.upper() == "C":
            # adding the binary numbers....
            addition(binary_number, second_binary_number)
            continue

        # fourth choice....
        elif choice_menu2.upper() == "D":
            #subtracting the binary numbers....
            subtraction(binary_number, second_binary_number)
            continue
    else:
        print("please select a valid choice")
        continue