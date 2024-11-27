def find_subsets(arr, target, index=0, current_subset=[]):
    # If the target sum is achieved, print the current subset
    if target == 0:
        print(current_subset)
        return
    
    # If we've considered all elements or the target becomes negative, stop
    if index >= len(arr) or target < 0:
        return

    # Include the current element in the subset and recurse
    find_subsets(arr, target - arr[index], index + 1, current_subset + [arr[index]])

    # Exclude the current element from the subset and recurse
    find_subsets(arr, target, index + 1, current_subset)


arr = [3, 34, 4, 12, 5, 2]  # set of numbers
target = 9  # Target sum

print(f"Subsets of {arr} with sum {target}:")
find_subsets(arr, target)

/*
Subsets of [3, 34, 4, 12, 5, 2] with sum 9:
[3, 4, 2]
[4, 5]

*/
