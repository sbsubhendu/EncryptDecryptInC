# EncryptDecryptInC
This is example of encryption and decryption in C language

1. Problem Definition:
This problem deals with the concept of encryption and decryption. Encryption is the process of converting a meaningful, readable string into some other string which may be difficult to understand with the help of another string called key. Decryption is the process of getting the original string back from the encrypted string using the same key. Encryption is performed by adding corresponding characters of message string and key, while decryption is done by subtracting the key from the encrypted string. The string for encryption or decryption and the key has to be read from the files specified by the user, and user will specify whether encryption or decryption has to be done.
2. Analysis:
(i)Inputs: The problem requires 3 input- 
•	user’s choice whether he wants to perform encryption or decryption,
•	the name of the file which contains the message to be encrypted or decrypted, and
•	the name of the file which contains the key that will be used for encryption or decryption.
(ii) Output: The output of the program will be the encrypted or decryption based on the user’s choice.
(iii) Constraints: There are three constraints to this problem-
•	User’s choice should be valid
•	The file containing the message should be present.
•	The file containing the key should be present.

3. Design: 
First, the user will be presented with a menu with two options- encryption or decryption. If his choice is invalid, he will be asked to enter his choice again. This process will continue until he inputs a valid choice.
Then, the user will be asked to enter the name of the two files, ie, the message file and the key file. If anyone of the files or both are missing, appropriate message will be displayed.
The message and the key will be read from the respective files and stored in a local variable. 
The length of the key and the message string will be matched. If the length of key is less than the length of message, then some of the characters from the key will be attached to the end of the key so that message and the key are of equal lengths.
Now depending on the user’s choice, the function for encryption or decryption will be called, passing the message string and the key as parameters to the function.
4. Implementation:
The program consists of three functions-
•	encrypt()- this function accepts two parameters, i.e., the message string to be encrypted and the key. It adds the corresponding characters from both strings and produces the output. The output is saved in a file Output.txt and also displayed to the user.
•	decrypt()- this function also accepts two parameters, i.e., the message string to be decrypted and the key. It subtracts the corresponding characters of key from the message and produces the output. The output is saved in a file Output.txt and also displayed to the user.
•	main()- this function performs all other tasks, i.e., presenting the user with a menu, validating the choice, accepting the name of two files and checking if they are present, and matching the length of the message string and key and adjusting the length of key if not matched, and finally calling encrypt() or decrypt() based on user choice.
5. Testing:
The following tests were performed to verify the correctness of the program. The images show the output of the tests. 
i.	When asked to enter the choice, invalid choice was entered.
  

ii.	Valid choice was entered, the name of key file was correctly entered but name of message file was wrongly entered.
       

iii.	This time, the name of message file was correctly entered but key file was wrongly entered.
 



iv.	A valid choice was entered but the name of both files were entered incorrectly.
 

v.	A valid choice for encryption was given, and the two files names were also entered correctly.
 

vi.	A valid choice for decryption was entered and the two file names were also correctly entered.
 
