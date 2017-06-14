##################################################################
#								 #
#	BlowfishDecrypt			        		 #
#								 #
#	Author: Juice						 #
#								 #
#	Description: An implementation of blowfish decryption    #
#								 #				
#	Created 6/11/17 for iD Tech Camps			 #
#								 #
##################################################################

from Crypto.Cipher import Blowfish
import os

#Open the file we encrypted to last time
file = open('encryptedText.txt','rb')
file_text = file.read()
file.close()

#Get the init_vector used last time by grabbing the first block of the text file
block_size = Blowfish.block_size
init_vector = file_text[:block_size]

#Using same key as before to decrypt!
key = 'iD Tech Rocks!'.encode()

#Making same cipher as last time
cipher = Blowfish.new(key,Blowfish.MODE_CBC,init_vector)

#Decrypt the file text
bytePlainText = cipher.decrypt(file_text[block_size:])
plainText = bytePlainText.decode('utf-8') #Put it in a format the output can understand

print(plainText)

os.system('pause')
