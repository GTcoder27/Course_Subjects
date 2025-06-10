def bayes_theorem():
  """
  Calculates the probability that a six was actually rolled given that a
  person, who tells the truth 75% of the time, reports a six.

  This function corresponds to the following scenario:
  - A die is rolled.
  - A person observes the result. This person tells the truth 3/4 of the time
    and lies 1/4 of the time. When they lie, they pick one of the other
    5 numbers at random.
  - The person reports that the number is a "six".
  - We want to find the probability that the roll was actually a "six".
  """
  # P(A): Probability that the roll is a six.
  p_is_six = 1.0 / 6.0
  # P(~A): Probability that the roll is not a six.
  p_is_not_six = 5.0 / 6.0

  # Probability the person tells the truth.
  p_truth = 0.75
  # Probability the person lies.
  p_lie = 0.25

  # P(B|A): Probability the person SAYS "six" given it IS a six.
  # This happens if they tell the truth.
  p_says_six_given_is_six = p_truth

  # P(B|~A): Probability the person SAYS "six" given it is NOT a six.
  # This happens if they lie AND pick "six" from the 5 other possibilities.
  p_says_six_given_is_not_six = p_lie * (1.0 / 5.0)

  # P(B): Total probability of the person saying "six".
  # This is the sum of them saying "six" when it is a six and when it is not.
  p_says_six = (p_says_six_given_is_six * p_is_six) + \
               (p_says_six_given_is_not_six * p_is_not_six)

  # Bayes' Theorem: P(A|B) = [P(B|A) * P(A)] / P(B)
  # The probability it IS a six given the person SAYS it's a six.
  p_is_six_given_says_six = (p_says_six_given_is_six * p_is_six) / p_says_six

  return p_is_six_given_says_six

# This block ensures the code runs only when the script is executed directly.
if __name__ == "__main__":
    result = bayes_theorem()
    # Use an f-string to format the output to 4 decimal places and as a percentage.
    print(f"Probability that it actually is a six: {result:.4f} ({result * 100:.2f}%)")






    