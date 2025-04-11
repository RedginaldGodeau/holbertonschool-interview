#!/usr/bin/python3


def isWinner(x, nums):
    """Determines the winner of a game played between Maria and Ben.

    Args:
        x (int): The number of rounds.
        nums (list): A list of integers representing the upper limit (n)
            for each round.

    Returns:
        str: The name of the player that won the most rounds ("Maria" or "Ben").
             Returns None if the winner cannot be determined.
    """
    if not nums or x <= 0:
        return None


if __name__ == "__main__":
    x = 3
    nums = [4, 5, 1]
    print("Winner: {}".format(isWinner(x, nums)))
    def get_primes(n):
        """Generates a list of prime numbers up to n."""
        primes = []
        if n < 2:
            return primes
        is_prime = [True] * (n + 1)
        is_prime[0] = is_prime[1] = False
        for i in range(2, int(n**0.5) + 1):
            if is_prime[i]:
                for j in range(i*i, n + 1, i):
                    is_prime[j] = False
        for i in range(2, n + 1):
            if is_prime[i]:
                primes.append(i)
        return primes

    maria_wins = 0
    ben_wins = 0

    for n_val in nums:
        primes = get_primes(n_val)
        if not primes:
            ben_wins += 1
            continue

        if n_val % 2 == 0:
            maria_wins += 1
        else:
            ben_wins += 1

    if maria_wins > ben_wins:
        return "Maria"
    elif ben_wins > maria_wins:
        return "Ben"
    else:
        return None
