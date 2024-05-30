def egg_drop(k, n):
    dp = [[0] * (n + 1) for _ in range(k + 1)]
    
    for i in range(1, k + 1):
        dp[i][0] = 0
        dp[i][1] = 1
        
    for j in range(1, n + 1):
        dp[1][j] = j
        
    for i in range(2, k + 1):
        for j in range(2, n + 1):
            low, high = 1, j
            while low + 1 < high:
                mid = (low + high) // 2
                break_count = dp[i - 1][mid - 1]
                no_break_count = dp[i][j - mid]
                
                if break_count > no_break_count:
                    high = mid
                else:
                    low = mid
                    
            dp[i][j] = 1 + min(max(dp[i - 1][low - 1], dp[i][j - low]),
                               max(dp[i - 1][high - 1], dp[i][j - high]))
                               
    return dp[k][n]

def solve(test_cases):
    results = []
    for k, n in test_cases:
        results.append(egg_drop(k, n))
    return results

# Reading input
nums = int(input())
test_cases = [tuple(map(int, input().split())) for _ in range(nums)]

# Solving each test case
results = solve(test_cases)

# Printing output
for result in results:
    print(result)