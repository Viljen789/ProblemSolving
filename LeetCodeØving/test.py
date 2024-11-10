import binascii
 
def toHex(word):
    return int(str(binascii.hexlify(word), 'ascii'), 16)
 
def toString(word):
    return str(binascii.unhexlify(hex(word)[2:]), 'ascii')

def encrypt(message, key):return toHex(bytes(message, encoding = 'ascii'))^toHex(bytes(key, encoding = 'ascii'))
def decrypt(code, key):return toString(toHex(bytes(key, encoding = 'ascii'))^code);

from random import *
def main():
    msg =  input("Hva er meldingen: ")
    key = str(randint(1,1000)*randint(1,1000))
    print(f"Krypto: {encrypt(msg, key)}")
    print(f"Melding: {decrypt(encrypt(msg, key), key)}")


def getKey():
    
    msg1 =  input("Hva er melding 1: ")
    msg2 =  input("Hva er melding 2: ")
    key = str(randint(1,1000)*randint(1,1000))
    print(f"Krypto 1: {encrypt(msg1, key)}")
    print(f"Krypto 2: {encrypt(msg2, key)}")
    enc = msg1^key
    enc2 = msg2^key
    print(f"xor av begge: {encrypt(msg1, key)^encrypt(msg2, key)^toHex(bytes(msg1, encoding = 'ascii'))}")
    print(f"and av begge: {encrypt(msg1, key)&encrypt(msg2, key)^encrypt(msg2, key)}")
    print(f"Key: {key}")

getKey()
    

