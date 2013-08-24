/*
	Write a method to replace all spaces in a string with '%20'. 
	You may assume that the string has sufficient space at the 
	end of the string to hold the additional characters, and 
	that you are given the "true" length of the string. 
	(Note: if implementing in Java, please use a character array 
	so you can perform this operation in place.)
	EXAMPLE
	Input  : "Mr John Smith    "
	Output: "Mr%20John%20Smith"
*/
// replace src with dest in str
void ReplaceSpace(char str[], char ch, char dest[]);

void TestReplaceSpace();