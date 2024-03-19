#mohamed ayman afifi 20230618
#moaaz ahmed 20230408
#Ali atef 20230236

#convert from decimal to octal
#insert 468 expect 724
def digit_octal(num):
	octal = ""
	digit = 0
	num1 = int(num)
	while num1 > 0:
	   	digit = num1 % 8
	   	octal = str(digit) + octal
	   	num1 = num1 // 8
	return(octal)

#convert from decimal to binary
#insert 82 expect 1010010
def digit_bin(num):
	bin = ""
	num1 = int(num)
	digit = 0
	while num1 > 0:
	   	digit = num1 % 2
	   	bin = str(digit) + bin
	   	num1 = num1 // 2
	return(bin)

#convert from decimal to hexdecimal
#insert 1234 expect 4D2
def digit_hex(num):
	s = "0123456789ABCDEF"
	hex = ""
	digit = ""
	num1 = int(num)
	index = 0
	while num1 > 0:
	   	index = num1 % 16
	   	digit = s[index]
	   	hex = str(digit) + hex
	   	num1 = num1 // 16
	return(hex)

#convert from binary to decimal
#insert 1010010 expect 82 
def bin_digit(bin):
	total = 0
	str_bin = str (bin)
	for digit in bin:
	   	total = total * 2 + int(digit)
	return (total)

#convert from binary to octal
#insert 111000011 expect 703
def bin_octal(bin):
	digit = bin_digit(bin)
	return(digit_octal(digit))

#convert from binary to hexdecimal
#insert 1000010101111 expect 10AF
def bin_hex(bin):
	digit = bin_digit(bin)
	return(digit_hex(digit))

#convert from octal to decimal
#insert 724 expect 468
def octal_digit(octal):
	decimal = 0
	power = 0
	octal = str(octal)
	for digit in reversed(octal):
		decimal += int(digit) * (8 ** power) 
		power += 1
	return(decimal)

#convert from hexdecimal to decimal
#insert 4D2 expect 1234
def hex_digit(hex):
	decimal = 0
	power = 0
	s ="0123456789ABCDEF"
	hex = str(hex)
	hex = hex.upper()
	for digit in reversed(hex):
		digit = s.index(digit)
		decimal += int(digit) * (16 ** power) 
		power += 1
	return(decimal)

#convert from hexdecimal to binary
#insert 10AF expect 1000010101111
def hex_bin(hex):
	digit = hex_digit(hex)
	return(digit_bin(digit))

#convert from octal to binary
#insert 703 expect 111000011
def octal_bin(octal):
	digit = octal_digit(octal)
	return(digit_bin(digit))

#convert from hexdecimal to octal
#insert 23E expect 1076
def hex_octal(hex):
	digit = hex_digit(hex)
	return(digit_octal(digit))

#convert from octal to hexdecimal
#insert 1076 expect 23E
def octal_hex(octal):
	digit = octal_digit(octal)
	return(digit_hex(digit))

#main finction
while(True):
	i = input("** numbering system converter **\n A) insert a new number\n B) Exit program\n")
	if(i == "B"):
		break
	elif(i == "A"):
		num = input(" Please insert a number\n")
		while(True):
			num_type = input("** Please select the base you want to convert a number from**\nA) Decimal\nB) Binary\nC) octal\nD) hexadecimal\n")
			if(num_type == "A" or num_type == "B" or num_type == "C" or num_type =="D"):
				break
			else:
				print("Please select a valid choice")
		while(True):
			convert_type = input("** Please select the base you want to convert a number to **\nA) Decimal\nB) Binary\nC) octal\nD) hexadecimal\n")
			if(convert_type == "A" or convert_type == "B" or convert_type == "C" or convert_type =="D"):
				break
			else:
				print("Please select a valid choice")
		if(num_type == convert_type):
			print(num)
		elif(num_type == "A" and convert_type == "B"):
			print(digit_bin(num))
		elif(num_type == "A" and convert_type == "C"):
			print(digit_octal(num))
		elif(num_type == "A" and convert_type == "D"):
			print(digit_hex(num))
		elif(num_type == "B" and convert_type == "A"):
			print(bin_digit(num))
		elif(num_type == "B" and convert_type == "C"):
			print(bin_octal(num))
		elif(num_type == "B" and convert_type == "D"):
			print(bin_hex(num))
		elif(num_type == "C" and convert_type == "A"):
			print(octal_digit(num))
		elif(num_type == "C" and convert_type == "B"):
			print(octal_bin(num))
		elif(num_type == "C" and convert_type == "D"):
			print(octal_hex(num))
		elif(num_type == "D" and convert_type == "A"):
			print(hex_digit(num))
		elif(num_type == "D" and convert_type == "B"):
			print(hex_bin(num))
		elif(num_type == "D" and convert_type == "C"):
			print(hex_octal(num))
	else:
		print(" please select a valid choice")
	