##################################################################
#								 #
#	SimplePassword			        		 #
#								 #
#	Author: Juice						 #
#								 #
#	Description: A simple hashing demonstration     	 #
#								 #				
#	Created 6/11/17 for iD Tech Camps			 #
#								 #
##################################################################

from Crypto.Hash import MD5

#Create a password, hash and store it
print('Enter a password for your new account: ',end='')
hash = MD5.new(input().encode('utf-8'))
passwd = hash.hexdigest()

print("\n--------------------------------------\n")

#Guess the password
passwordEntered = False;
while (passwordEntered != True):
    #Hash the entered password
    print('\nEnter the password: ',end='')
    hash = MD5.new(input().encode('utf-8'));
    entered = hash.hexdigest()

    #Compare the two passwords
    print('Comparing ' + entered + ' with the password, ' + passwd + '.')
    if (entered == passwd):
        #Quit if correct password
        print('Password entered! Quitting...')
        passwordEntered=True
    else:
        #Continue if incorrect
        print('Password incorrect! Guess again!')
        
