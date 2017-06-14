##################################################################
#								 #
#	BlowfishEncrypt			        		 #
#								 #
#	Author: Juice						 #
#								 #
#	Description: An implementation of blowfish encryption    #
#								 #				
#	Created 6/11/17 for iD Tech Camps			 #
#								 #
##################################################################

from Crypto.Cipher import Blowfish
from Crypto import Random

block_size = Blowfish.block_size

key = 'iD Tech Rocks!'.encode() #can be any size; would likely also be random
init_vector = Random.new().read(block_size) #creates a random number of size block_size
#The initialization vector is used as a "starting point" for the encryption algorithm; it ensures that patterns don't appear in the ciphertext

cipher = Blowfish.new(key,Blowfish.MODE_CBC,init_vector) #makes a new cipher, which can be used to encrypt and decrypt

#Open a new file to save everything to
file = open('encryptedText.txt','wb')
file.write(init_vector) #Write our init_vector to the file to help decrypt it later

quit = False

#Continue until user quits
while(quit != True):
    print('Enter text to be encrypted, or q to quit: ',end='')
    plaintext = input()

    if (plaintext!='q'):
        #Compute "padding" to make our input text divisible by block_size
        remainder = len(plaintext)%block_size
        padding = ' '*(block_size-remainder-1) + '\n'

        file.write(cipher.encrypt((plaintext+padding).encode()))
        #Blowfish requires that the input is divisible by the block_size, so I wrote some code that adds "padding" to make the plaintext the right size
    else:
        quit = True

file.close()
