#include "stdafx.h"
#include "Strings.h"

using namespace std;

// ----------------------------------------------------------
// 7.1 INTERCONVERT STRINGS AND INTEGERS
string IntToString(int x)
{
	// Build the string one digit at a time using % 10 and / 10 to convert the value. Build the string from the left, then reverse it at the end, so we don't end up having to move the string's contents.
	// Don't forget to add the negative sign at the start of the string, if required.
	// O(n)
	return string();
}

int StringToInt(const string& s)
{
	// Go over each character from left to right. On each iteration, multiply the partial result by 10 and add the character. Keep track of the negative sign at the beginning.
	return 0;
}

// ----------------------------------------------------------
// 7.2 BASE CONVERSION
string ConvertToBase(const string& s, int b1, int b2)
{
	// Convert to integer using sum and multiply, then convert to base b2 using modulus and division. Handle negative sign.
	// O(n(1+log of b2(b1)) - the derivation of this is tricky.
	return string();
}

// ----------------------------------------------------------
// 7.3 COMPUTE THE SPREADSHEET COLUMN ENCODING
int ComputeSpreadSheetEncoding(const string& s)
{
	// We are converting from a number that is base 26. But A is ONE, not zero. Convert to integer as in 7.1, but using base 26 instead.
	return 0;
}

// ----------------------------------------------------------
// 7.4 REPLACE AND REMOVE
int ReplaceAndRemove(int size, char s[])
{
	// Remove b's and pack the string on the first string, keeping note of what the final length of the string will be. Then expand the a's starting from right to left, assigning from the predetermined end of the final string.
	return 0;
}

// ----------------------------------------------------------
// 7.5 TEST PALINDROMICITY
bool TestPalindromicity(const string& s)
{
	// Iterate through string, comparing first character with last character, until the two indices cross or are equal.Make sure to skip non-alphanumeric characters and to perform a case insensitive comparison.
	return false;
}

// ----------------------------------------------------------
// 7.6 REVERSE ALL WORDS IN A SENTENCE
string ReverseWordsInSentence(const string& s)
{
	// Reverse the entire string, then reverse individual words. 
	return string();
}

// ----------------------------------------------------------
// 7.7 COMPUTE ALL MNEMONICS FOR A PHONE NUMBER
vector<string> ComputeAllMnenomics(const string& s)
{
	// Start with last number in the string and loop n times (n being how many characters map to this digit), in each iteration add the character to the string. Then recursively call itself, passing in partial result and
	// number divided by 10. When the number is <10 we have a complete result that we can add to the list.
	// O(4^n*n) - tricky.
	return vector<string>();
}

// ----------------------------------------------------------
// 7.8 THE LOOK AND SAY PROBLEM
string LookAndSaySequence(int n)
{
	// Parse string from right to left, compare with previous entry; if its the same, increase running count, if it's different, insert count and value, and reset count. Process until entire string has been consumed.
	// Do this n times, processing the result from the previous iteration.
	// O(n*2^n).
	return string();
}

// ----------------------------------------------------------
// 7.9 CONVERT FROM ROMAN TO DECIMAL
int ConvertRomanDecimal(const string& s)
{
	// Start from the right, if symbol after current one is greater than it, subtract the current symbol, otherwise add it. This is exploiting the idea that by adding the symbol to the right, we have already done the work
	// to add the difference of the larger symbol with the smaller one: we simply subtract the difference.
	// The code given doesn't even test most of the edge cases... and I would never write the code this way. It's quite confusing.
	return 0;
}

// ----------------------------------------------------------
// 7.10 COMPUTE ALL VALID IP ADDRESSES
vector<string> ComputeValidIpAddresses(const string& s)
{
	// Use three nested loops to iteration over the possible positions of each of the 3 dots. Take note of the fact a valid integer cannot start with 0 unless it is just 0. Dots cannot be less than 2 positions apart.
	// And don't forget the number should be <= 255. Also take note of the fact a dot cannot be more than 3 spaces from another dot, and stop any loop as soon as we hit a bad number.
	// Pay more attention to the constraints on the string.
	// Surprising, thit is O(1) because the algorithm always takes the same amount of time.
	return vector<string>();
}

// ----------------------------------------------------------
// 7.11 WRITE A STRING SINUSOIDALLY
string WriteSinusoidally(const string& s)
{
	// Do three passes, in first add every 1 + i * 4 character, in second add every 0 + i * 2 character, in third add every 3 + i * 4 character.
	return string();
}

// ----------------------------------------------------------
// 7.12 IMPLEMENT RUN-LENGTH ENCODING
string DecodeRLE(const string& s)
{
	// This is trivial. Keep the value, then the count, and add as many characters as are in the count.
	return string();
}

string EncodeRLE(const string& s)
{
	// Trivial as well. Keep track of the previous value encountered. If the same, increment count, otherwise, add value and count to string and reset count. Similar to 7.8. At the end of loop, make sure to insert the value
	// and count of the last element.
	return string();
}

// ----------------------------------------------------------
// 7.13 FIND THE FIRST OCCURENCE OF A SUBSTRING
int FindSubstring(const string& text, const string& search)
{
	// This requires prior knowledge of string search algorithms. Rabin-Karp would be one, and ideally, I should study another one,
	// Rabin-Karp works by computing a rolling hash for the pattern, and for each part of the text matching the size of the pattern. The hash allows trivial rejection of parts of the text that do not match the pattern;
	// an explicit compare of the text with the pattern still needs to be done if the hashes match. The key is in using a rolling hash - such a hash makes it more efficient to update the hash by effectively moving the 
	// window of substrings included in the hash, effectively subtracting the value of the first letter in the match and adding the value of a new letter at the end. By using a modulus q with a suitable large number such that
	// q*26 is just less than the size of an integer, we minimize collisions.
	return -1;
}
