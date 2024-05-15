def ulam_sequence(n):
    ulam = [1, 2]  # Start with the initial Ulam numbers
    while len(ulam) < n:  # Generate more Ulam numbers until we have n
        count = {}  # Dictionary to store the count of sums
        for i in range(len(ulam)):
            for j in range(i + 1, len(ulam)):
                s = ulam[i] + ulam[j]
                if s not in count:
                    count[s] = 0
                count[s] += 1
        min_sum = float('inf')
        for num, freq in count.items():
            if freq == 1 and num > ulam[-1] and num < min_sum:
                min_sum = num
        ulam.append(min_sum)  # Add the smallest sum that appears exactly once
    return ulam

# Example usage:
n = 10
print(ulam_sequence(n))
