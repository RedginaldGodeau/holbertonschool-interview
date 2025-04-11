#!/usr/bin/python3

def isWinner(x, nums):
    """Determines the winner of a game played between Maria and Ben.

    The game is played over x rounds. In each round, a set of consecutive
    integers starting from 1 up to and including n is considered.
    Maria and Ben take turns choosing a prime number from the set and
    removing that number and its multiples from the set.
    The player that cannot make a move loses the game.
    Maria always goes first and both players play optimally.

    Args:
        x (int): The number of rounds.
        nums (list): A list of integers representing the upper limit (n)
            for each round.

    Returns:
        str: The name of the player that won the most rounds ("Maria" or "Ben").
             Returns None if the winner cannot be determined.
    """
    def get_primes(n):
        """Generates a list of prime numbers up to n.

        This function uses the Sieve of Eratosthenes algorithm to efficiently
        find all prime numbers up to a given limit n.

        Args:
            n (int): The upper limit for prime number generation.

        Returns:
            list: A list of prime numbers up to n.
        """
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

    for _ in range(x):
        n = nums[_]
        primes = get_primes(n)
        if not primes:
            ben_wins += 1
            continue

        nums_set = list(range(1, n + 1))
        moves = 0
        turn = 0  # 0 for Maria, 1 for Ben

        while True:
            possible_moves = [p for p in primes if p in nums_set]
            if not possible_moves:
                if turn == 0:
                    ben_wins += 1
                else:
                    maria_wins += 1
                break

            move = possible_moves[0]
            nums_set = [num for num in nums_set if num % move != 0]
            turn = 1 - turn
            moves += 1

    if maria_wins > ben_wins:
        return "Maria"
    elif ben_wins > maria_wins:
        return "Ben"
    else:
        return None

if __name__ == "__main__":
    x = 3
    nums = [4, 5, 1]
    print("Winner: {}".format(isWinner(x, nums)))
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

    for _ in range(x):
        n = nums[_]
        primes = get_primes(n)
        if not primes:
            ben_wins += 1
            continue

        nums_set = list(range(1, n + 1))
        moves = 0
        turn = 0  # 0 for Maria, 1 for Ben

        while True:
            possible_moves = [p for p in primes if p in nums_set]
            if not possible_moves:
                if turn == 0:
                    ben_wins += 1
                else:
                    maria_wins += 1
                break

            move = possible_moves[0]
            nums_set = [num for num in nums_set if num % move != 0]
            turn = 1 - turn
            moves += 1

    if maria_wins > ben_wins:
        return "Maria"
    elif ben_wins > maria_wins:
        return "Ben"
    else:
        return None

if __name__ == "__main__":
    x = 3
    nums = [4, 5, 1]
    print("Winner: {}".format(isWinner(x, nums)))
