key = input()
length = int(input())
encrypted = input()

# Create the dictionary that maps letters to their positions in the key
key_dict = {}
for i in range(26):
	key_dict[key[i]] = i

# Decrypt the message
decrypted = ""
for x in encrypted:
	pos = key_dict[x]
	if pos == 25:
		decrypted += "A"
	else:
		decrypted += chr(ord('A') + pos + 1)

print(decrypted)
