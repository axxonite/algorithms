// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	// This is my own solution, instead of the book's. I find this one far easier to understand. I should do a run through to see if there's any
	// additional bugs in this version, however.
	vector<string> JustifyText( const vector<string>& words, size_t l )
	{
		// Fit as many words as possible on each line of text. Once a line is filled, distribute the spaces between the words.
		vector<string> result;
		for ( int index = 0; index < words.size(); )
		{
			int start = index; // start is index of first word on the line.
			int lineLength = words[index++].size(); // lineLength is number of characters on the line. Start with one word.
			while ( index < words.size() && ( lineLength + words[index].size() + 1 ) <= l )
				lineLength += words[index++].size() + 1; // Add the size of the word on the line, plus one blank.

			int remainingBlanks = l - lineLength; // Remaining blanks to distribute.
			string line = words[start];
			if ( index == words.size() || index - start <= 1 )
			{
				// if this is the last line, or there is only one word on the line, distribute all the blanks at the end of the word.
				for ( int i = start + 1; i < index; ++i )
					line += " " + words[i];
				line.append( remainingBlanks, ' ' );
			}
			else
			{
				// Distribute blanks to the words, aka if there's 12 blanks and 4 words, distribute the 12 spaces in the 3 gaps between the 4 words..
				// If the blanks don't divide evenly, then add one blank to the first n words, with n being the remainder of the division of blanks and gaps.
				// Aka, 11 blanks and 3 gaps, 11 % 3 = 2. Add 2 extra blanks to the first 2 words, so we have 4, 4, 3 as the spacing.
				int blanksPerGap = 1 + remainingBlanks / ( index - start - 1 );
				int gapsWithAddedBlank = remainingBlanks % ( index - start - 1 );
				// i represents the ith gap between words.
				for ( int i = 0; i < index - start - 1; ++i )
				{
					line.append( blanksPerGap + ( i < gapsWithAddedBlank ? 1 : 0 ), ' ' ); // Add gap spaces, then next word.
					line += words[start + i + 1];
				}
			}

			result.emplace_back( line );
		}
		return result;
	}
}