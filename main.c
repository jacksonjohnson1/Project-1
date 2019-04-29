#include<stdio.h>
#include<stdlib.h>
//The viewer will be presented with 2 options to decide which cipher they would like to use, either rotation or substitution, then a further 
//2 options in each cipher electing encryption or decryption, resulting in a total of 6 options.

int
main ()
{
  int control, rotate, sub;                         //Variables initialised to control selection between & in the ciphers
  printf
    ("Do you want use a Substitution cipher or Rotation cipher?\nFor rotation press 1 & for substitution press 2: "); 
  scanf ("%d", &control);                           //reads the integer then assigns it to variable control
  if (control == 1)                                 //if the assigned value to 'control' is equal to 1 then rotation occurs
    {
      printf
	("Do you want to decrypt or encrypt?\nFor encryption press 1 & for decryption press 2: ");
      scanf ("%d", &rotate);                        //reads the integer then assigns it to variable rotate
      if (rotate == 1)                              //if the assigned value to 'rotate' is equal to 1 then the encryption occurs
	{

	  char message[100], ch;                        //message is an array with a byte size of 100 & ch is an initialised char datatype that will hold a value
	  int i, turn = 1;                              //2 integers, i has no value because it will be used in our 'for' loops later, turn is the number of rotations in the cipher

	  printf ("Enter a message to encrypt (must be in capital letters): ");
	  scanf ("%s", message);                        //reads the string of message


	  for (i = 0; message[i] != '\0'; ++i)   
	    {
	      ch = message[i];                          //ch is now assigned the value of message[i]

	     if (ch >= 'A' && ch <= 'Z')                //conditions of if ch is greater than or equal 'A' and ch is less than or equal to 'Z'
		{
		  ch = ch + turn;                           //turn is added to ch and this new value is reassigned to ch

		  if (ch > 'Z')
		    {
		      ch = ch - 'Z' + 'A' - 1;              //Keeps parameters within A-Z
		    }

		  message[i] = ch;                          //message[i] is now assigned the value of ch
		}
	    }

	  printf ("Encrypted message: %s", message);    //prints the encryption from the string of message

	  return 0;
	}
      if (rotate == 2);                             //if the assigned value to 'rotate' is equal to 2 then the decryption occurs
      {
	char message[100], ch;
	int i, turn = 1;                                //2 integers, i has no value because it will be used in our 'for' loops later, turn is the number of rotations in the cipher

	printf ("Enter a message to decrypt (must be in capital letters): ");
	scanf ("%s", message);                          //reads the message and puts into the string of message


	for (i = 0; message[i] != '\0'; ++i)
	  {
	    ch = message[i];                            //ch is now assigned the value of message[i]

	    if (ch >= 'A' && ch <= 'Z')                 //conditions of if ch is greater than or equal 'A' and ch is less than or equal to 'Z'
	      {
		ch = ch - turn;                             //turn is subtracted away from ch and this new value is reassigned to ch

		if (ch < 'A')
		  {
		    ch = ch + 'Z' - 'A' + 1;                //Keeps parameters within A-Z
		  }

		message[i] = ch;                            //message[i] is now assigned the value of ch
	      }
	  }

	printf ("Decrypted message: %s", message);      //prints the decryption from the string of message

	return 0;
      }
    }
    if (control == 2){                              //if the assigned value to 'control' is equal to 2 then substitution occurs
        printf ("Do you want to encrypt or decrypt?\nFor encryption press 1 & for decryption press 2: ");
      scanf ("%d", &sub);                           //reads the integer then assigns it to variable 'sub'
    if (sub == 1)                                   //if the assigned value to 'sub' is equal to 1 then the encryption occurs
    {
      int a, i, b, c, index;	                    //variables to be re-initialised in the code
      char file[a];		                            //Array file with an int variable 'a' which will be assigned an integer value to correspond to the number of characters in the text
      char alf[26] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";	//Array alf of size 26 bytes to accomodate the alphabet ranging from A-Z
      char subst[26] = "KEIJUTVHPSNCFAMWGDZQXYBROL";//Array subst of size 26 bytes to accomodate the alphabet ranging from A-Z
      char letter;                                  //char datatype storing value used in the loops for reassignments

      printf ("What do you want to encrypt (message must be in capital letters): ");
      scanf ("%s", file);
      printf ("Number of characters: ");
      scanf ("%d", &a);                             //reads the integer then assigns it to variable 'a'
      printf ("Encryption: ");                      //This is here for when the encryption has occured so it looks more presentable

      for (i = 0; i < a; i++)                       //conditional for loop that exits once i is greater than the number of characters
	{
	  letter = file[i];                             //letter is assigned value of file of size int i
	  for (b = 0; b < 26; b++)                      //conditional for loop which b will equal the number of characters
	    {
	      if (alf[b] == letter)                     //this will happen once a = b effectively, because i will have the value of a and file has been assigned to letter, then alf[b] will be equal to letter
		{
		  index = b;                                //index is now assigned the value of b which is equal to a
		}
	      else
		{
		  file[i] = subst[index];                   //final reassignment to get it back to the beginning
		}
	      for (c = 0; c < a; c++)
		{
		  printf ("%c", file[c]);
		}
	      return 0;
	    }
	  if (sub == 2)
	    {
	      int a, i, b, c, index;	                  //variables to be re-initialised in the code
	      char file[a];                               //Array file with an int variable 'a' which will be assigned an integer value to correspond to the number of characters in the text
	      char alf[26] = "KEIJUTVHPSNCFAMWGDZQXYBROL";//For decryption purposes alf and subst have been switched as it is just the reversal of before
	      char subst[26] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";//For decryption purposes alf and subst have been switched as it is just the reversal of before
	      char letter;                                //char datatype storing value used in the loops for reassignments

	      printf
		("What do you want to decrypt (message must be in capital letters): ");
	      scanf ("%s", file);
	      printf ("Number of characters: ");
	      scanf ("%d", &a);                          //reads the integer then assigns it to variable 'a'
	      printf ("Decryption: ");                   //This is here for when the encryption has occured so it looks more presentable

	      for (i = 0; i < a; i++)                    //conditional for loop that exits once i is greater than the number of characters (a)
		{
		  letter = file[i];                          //letter is assigned value of file of size int i
		  for (b = 0; b < 26; b++)                   //conditional for loop which b will equal the number of characters
		    {
		      if (alf[b] == letter)                  //this will happen once a = b effectively, because i will have the value of a and file has been assigned to letter, then alf[b] will be equal to letter
			{
			  index = b;                             //index is now assigned the value of b which is equal to a
			}
		      else
			{
			  file[i] = subst[index];                //final reassignment to get it back to the beginning
			}
		      for (c = 0; c < a; c++)
			{
			  printf ("%c", file[c]);
			}
		      return 0;
		    }
		}
	    }
	}
    }
}
}