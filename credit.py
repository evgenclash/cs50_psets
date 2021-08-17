import re

def main():
	while True:
		a = int(input('Enter your creditcard:'))
		if len(str(a)) <17 and len(str(a))>12:
			break
	answer = checks(a)
	if answer== "valid":
		if len(str(a))==15:
			final = typy_card(a)
		if len(str(a))==13 or 16:
			final = visa_master(a)
	else:
		final = "Invalid"
	

	print (final)



def typy_card(b):
	# pattern = re.compile("34")
	# ans = pattern.match(str(b))
	ans = re.match("34", str(b))
	ans1 = re.match("37", str(b))
	if ans:
		print("Found")
		a = "American Express"
	elif ans1:
		print("found")
		a = "American Express"
	else:
		a= "invalid"
	return a


def checks(card):
	numbers = []
	for i in str(card):
		numbers.append(i) 
	sum = 0
	fnum = []
	for i in range(0,len(str(card)),2):
		fnum.append(int(numbers[i])*2)
	for i in range(1,len(str(card)),2):
		fnum.append(int(numbers[i]))
	for i in range(0,len(str(card))):
		if fnum[i]>9:
			tmp = fnum[i]
			a = tmp % 10
			b = tmp // 10
			sum = sum + a + b
		else:
			sum = sum + fnum[i]
	final_digit = sum % 10
	if final_digit == 0:
		result = "valid"
	else:
	 	result = "invalid"
	return result

def visa_master(b):
	ans = re.match("4", str(b))
	ans1 = re.match("51", str(b))
	ans2 = re.match("52", str(b))
	ans3 = re.match("53", str(b))
	ans4 = re.match("54", str(b))
	ans5 = re.match("55", str(b))
	if ans:
		answer = "visa"
	elif ans1:
		answer = "Mastercard"
	elif ans2:
		answer = "Mastercard"
	elif ans3:
		answer = "Mastercard"
	elif ans4:
		answer = "Mastercard"
	elif ans5:
		answer = "Mastercard"
	else:
		answer = "Invalid"
	
	return answer

main()