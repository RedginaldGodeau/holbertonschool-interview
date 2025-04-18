#!/usr/bin/python3
"""Making Change great again"""
import math


def makeChange(coins, total):
    """Given a pile of coins of different values"""
    if total < 0:
        return 0

    cointNeeded = 0

    while total > 0:
        if not coins:
            return -1

        greatest = max(coins)
        howManyTimeNeedToBeDivided = math.floor(total / greatest)

        if howManyTimeNeedToBeDivided == 0:
            coins.remove(greatest)
            continue

        total -= greatest * howManyTimeNeedToBeDivided
        cointNeeded += howManyTimeNeedToBeDivided
    return cointNeeded if total == 0 else -1
