# File: CS112_A1_T3_20230618_20230043_20230605
# Author 0f problem 1 and 2 is: Adham Hamdy hamed abdulhamid
# ID: 20230043
# Author of problem 3 and 4 is: Mohamed Ayman Afifi Elafifi
# ID: 20230618
# Author of problem 5 and 6 is: Mohamed Mokhtar ibrahim atiaa
# ID: 20230605

# Date : 27/2/2024
########################################################################

# function check the input is digit and between 0 and 100
def checkInput(m): 
    while True:
        if not m.isnumeric():
            m = input("Invalid Input! Please enter an integer number between 0 and 100: ")
        else:
            mark =float(m)
            if mark < 0 or mark > 100:
                m = input("Invalid Input! Please enter an integer number between 0 and 100: ")
            else:
                return mark

#function check the grades
def gradeCalc(mark):
    if mark >= 90: 
        return "A+"
    elif 90 > mark >= 85:  
        return "A"
    elif 85 > mark >= 80: 
        return "B+"
    elif 80 > mark >= 75: 
        return "B"
    elif 75 > mark >= 70: 
        return "C+"
    elif 70 > mark >= 65: 
        return "C"
    elif 65 > mark >= 60: 
        return "D+"
    elif 55 > mark >= 50:
        return "D"
    elif mark < 50:
        return "F"

#main function for problem 1
def problem1():
    print("***Welcome to grade calculator***")
    mark = input("Enter your grade: ")
    carrryMark = float(checkInput(mark))
    grade = gradeCalc(carrryMark)
    print("Your Grade Is: ", grade)
def countDigits(n):  
    carry = int(n)  
    cnt = 0 
    while carry > 0:
        carry //= 10 
        cnt += 1
    return cnt

#function check the input is a number
def _checkInput(p):
    while (not p.isnumeric()):
        p = input("Invalid Input! Please enter an integer number: ") 
    return int(p) 

#main function for problem 2

def problem2():  
    
    print("***Welcome to Armstrong number checker***")  
    summation = 0  
    num = str(input("Enter an integer number: "))  
    carryNum =_checkInput(num) 
    numI = carryNum
    numOfDigits = countDigits(numI) 
    while numI > 0: 
        digit = numI % 10 
        summation += pow(digit, numOfDigits) 
        numI //= 10 
    if summation == carryNum:
        print(f"Armstrong Number... Sum =  {summation} & Num =  {carryNum}") 
    else: 
        print(f"Not Armstrong Number... Sum = {summation} & Num = {carryNum}")

# main functin for problem 3
def problem3():
    while True:
        str_n = input("please insert postive  integer number : ")
        if not str_n.isdigit():
            print("Please enter a valid number.")
        else:
            n = int(str_n)
            if n <= 0:
                print("Please enter a positive number.")
            else:
                break
    pi = 0
    for i in range(1, n+1):
        pi += ((-1)**(i+1))*(1/(2*i-1))
    print(f"pi/4 now equal :{pi}")
    print(f"pi now equal :{4*pi}")

# Main Function for Problem 4
def problem4():
    str = input("enter message you want to Encryption : ")

    for i in str:
        if i in " ":
            print(i, end="")
        elif i in "z":
            print('a', end="")
        elif i in 'Z':
            print('A', end="")
        elif i in '9':
            print('1', end="")
        else:
            print(chr(ord(i) + 1), end="")
    print("")

#function to compare between two list
def lists_are_equal(list1, list2):
    list1_c = list1
    list2_c = list2
    if len(list1_c) != len(list2_c):
        return False
    for i in list1_c:
        if i in list2_c:
            list2_c.remove(i)
        else:
            return False

    return True

#main function for problem 5
def problem5():
    list_a = input("Enter the elements of the first list separated by spaces: ").split()
    list_b = input("Enter the elements of the second list separated by spaces: ").split()
    if lists_are_equal(list_a, list_b):
        print(f"The lists : {list_a} and {list_b} are equal.")
    else:
        print(f"The lists : {list_a} and {list_b} are not equal.")

#make list of factors of the number
def get_factors_of_pos_number(number):
    factors = []
    for i in range(1, number + 1):
        if number % i == 0:
            factors.append(i)
    return factors

#main function for problem 6
def problem6():
    positive_integer_s = input("Enter a positive integer: ")
    positive_integer = _checkInput(positive_integer_s)
    result = get_factors_of_pos_number(positive_integer)
    print(f"The factors of {positive_integer} are: {result}")

# Calling functions one after another
#main loop
while True:
    user_choice =input("Please enter the number of the task you want to solve from [1 : 6]\n(any thing else progrom will exit): ")

    if user_choice == "1":
        problem1()
    elif user_choice == "2":
        problem2()
    elif user_choice == "3":
        problem3()
    elif user_choice == "4":
        problem4()
    elif user_choice == "5":
        problem5()
    elif user_choice == "6":
        problem6()
    else:
        break
