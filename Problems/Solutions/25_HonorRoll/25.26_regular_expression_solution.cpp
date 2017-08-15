// Copyright (c) 2013 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	bool IsMatchHere(const string& regex, int regex_index, const string& s, int s_index)
	{
		// Case (1.): empy regex. Matches all strings.
		if (regex_index == regex.size())
			return true;

		// Case (2.): $ in regex. Only valid at the end of regex, and only passes if we are at the end of string.
		if (regex_index == regex.size() - 1 && regex[regex_index] == '$')
			return s_index == s.size();

		// Case (3.): '*' match. Test for instance of the character, two instances and so forth, until the end of the string.
		if (regex.size() - regex_index >= 2 && regex[regex_index + 1] == '*')
		{
			// i is the next element after the match.
			for (int i = s_index + 1; i < s.size() && (regex[regex_index] == '.' || regex[regex_index] == s[i - 1]); ++i)
			{
				// Continue matching here.
				if (IsMatchHere(regex, regex_index + 2, s, i))
					return true;
			}
			// * also matches no instances of the match character, so attempt match past the '*'
			return IsMatchHere(regex, regex_index + 2, s, s_index);
		}

		// Case (4.): single character match.
		return s_index < s.size() && (regex[regex_index] == '.' || regex[regex_index] == s[s_index]) && IsMatchHere(regex, regex_index + 1, s, s_index + 1);
	}

	bool IsMatch(const string& regex, const string& s)
	{
		// Case (2.): '^' at the start of regex means we must match only from the start of the string.
		if (regex.front() == '^')
			return IsMatchHere(regex, 1, s, 0);

		// Look for a match at any position within the string.
		// NOTE the <= operator here, to allow testing for the $ operator.
		for (int i = 0; i <= s.size(); ++i)
		{
			if (IsMatchHere(regex, 0, s, i))
				return true;
		}
		return false;
	}
}
