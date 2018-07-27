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
			if ( result >= target ) // If the result already exceeds our target, then we don't need to proceed further.
			{
				return false;
			}

			//int remainingInt = FindRemainingInt( digits, index );
			operands.emplace_back( 0 ); // Start a new operand.

			// If the difference between our result and our target is already larger than the remaining digits, then we can't add a + here (or a *?)
			// this doesn't make sense. we would be adding a product of other elements, so we can certainly add a bigger number than the number composed of all following digits.
			// furthermore, if the following digits happen to all be 111111, then we could form a 1*1*1*1 product with these, so the lower bound for what number we could add here is 
			// actually 1.
			// sounds like a bug to me.
			//if ( target - result <= remainingInt )
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

	int EvaluateExpression2(vector<string>& values, string& operators)
	{
		int product = stoi(values[0]), sum = 0;
		for (int i = 0; i < operators.size(); ++i)
		{
			if (operators[i] == '*')
				product *= stoi(values[i + 1]);
			else
			{
				sum += product;
				product = stoi(values[i + 1]);
			}
		}
		sum += product;
		return sum;
	}

	bool ExpressionSynthesis2(const vector<int>& digits, int target, int index, vector<string>& values, string& operators)
	{
		if (index == digits.size())
		{
			return EvaluateExpression2(values, operators) == target;
		}
		if (values.back() != "")
		{
			int result = EvaluateExpression2(values, operators);
			if (result >= target)
				return false;
			operators.push_back('+');
			values.emplace_back("");
			if (ExpressionSynthesis2(digits, target, index, values, operators))
				return true;
			operators.back() = '*';
			if (ExpressionSynthesis2(digits, target, index, values, operators))
				return true;
			operators.pop_back();
			values.pop_back();
		}
		values.back() += '0' + digits[index];
		if (ExpressionSynthesis2(digits, target, index + 1, values, operators))
			return true;
		values.back().pop_back();
		return false;
	}

	bool ExpressionSynthesis2(const vector<int>& digits, int target)
	{
		vector<string> values;
		string operators;
		values.emplace_back("");
		return ExpressionSynthesis2(digits, target, 0, values, operators);
	}
}