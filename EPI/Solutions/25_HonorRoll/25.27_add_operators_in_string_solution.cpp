// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	int Evaluate( vector<int>& operands, vector<char>& operators )
	{
		int term = operands[0], result = 0, operand = 1;
		for ( auto oper : operators )
		{
			if ( oper == '*' )
				term *= operands[operand++];
			else
			{
				result += term;
				term = operands[operand++];
			}
		}
		result += term;
		return result;
	}

	int FindRemainingInt( const vector<int>& digits, int index )
	{
		// Compute integer from index to the end of the string.
		int value = 0;
		for ( int i = index; i < digits.size(); ++i )
			value = value * 10 + digits[i];
		return value;
	}

	// Needless to say, this problem is tricky as hell.
	// Key insight here is to have a vector of operans and a vector of operators, which makes it easier to reference said operators and operands when evaluating the expression.
	bool ExpressionSynthesisHelper( const vector<int>& digits, int index, int target, vector<int>& operands, vector<char>& operators, bool lastWasOperator )
	{
		if ( index == digits.size() )
		{
			int result = Evaluate( operands, operators );
			return result == target;
		}

		// If we have not appended an operator on the last iteration, append operators.
		if ( !lastWasOperator )
		{
			int result = Evaluate( operands, operators );
			if ( result > target ) // If the result already exceeds our target, then we don't need to proceed further.
			{
				return false;
			}

			int remainingInt = FindRemainingInt( digits, index );
			operands.emplace_back( 0 ); // Start a new operand.

										// If the difference between our result and our target is already larger than the remaining digits, then we can't add a + here (or a *?)
			if ( target - result <= remainingInt )
			{
				operators.emplace_back( '+' );
				if ( ExpressionSynthesisHelper( digits, index, target, operands, operators, true ) )
					return true;
				operators.pop_back();
			}

			operators.emplace_back( '*' );
			if ( ExpressionSynthesisHelper( digits, index, target, operands, operators, true ) )
				return true;
			operators.pop_back();

			operands.pop_back();
		}

		// Append a digit to the operand.
		operands.back() = operands.back() * 10 + digits[index];
		if ( ExpressionSynthesisHelper( digits, index + 1, target, operands, operators, false ) )
			return true;
		// Don't forget to remove that digit later.
		operands.back() = operands.back() / 10;
		return false;
	}

	bool ExpressionSynthesis( const vector<int>& digits, int target )
	{
		vector<int> operands;
		vector<char> operators;
		operands.emplace_back( 0 );
		return ExpressionSynthesisHelper( digits, 0, target, operands, operators, true );
	}
}