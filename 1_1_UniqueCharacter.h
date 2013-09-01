
/*
	Implement an algorithm to determine if a string has all unique characters. 
	What if you cannot use additional data structures?
*/

// 256个char字母
const int CHAR_NUM = 256;

/*
 * Using Hash to determine that a char is unique
*/
bool IsStringUniqueChar(char str[]);

/*
 * Using bitmap
*/
bool IsStringUniqueChar2(char str[]);

// unsigned char的长度为8
const int CHAR_LENGTH = 8;

// Setbit 
#define SETBIT(arr, num) \
	(arr[num / CHAR_LENGTH] |= (1 << (num % CHAR_LENGTH)))
// ClearBit
#define CLRBIT(arr, num) \
	(arr[num / CHAR_LENGTH] &= (~(((unsigned char)1) << (num % CHAR_LENGTH))))
// GetBit
#define GETBIT(arr, num) \
	((arr[num / CHAR_LENGTH] >> (num % CHAR_LENGTH)) & 1)
// ByteNum
#define BYTENUM(num) \
	((num % CHAR_LENGTH == 0) ? (num / CHAR_LENGTH) : (num / CHAR_LENGTH + 1))

void TestBitMap();

/*
 * brute force	
*/
bool IsStringUniqueChar3(char str[]);

/*
 * sort, then iterator the str
*/
bool IsStringUniqueChar4(char str[]);


void TestUniqueCharacer();