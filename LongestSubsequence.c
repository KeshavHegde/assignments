/*Longest Subsequence with Consecutive Elements
Problem Statement:
Given an unsorted array of integers arr, find the length of the longest subsequence where the 
elements form a consecutive sequence (not necessarily contiguous).
Input:
• An integer array arr.
Output:
• An integer representing the length of the longest consecutive subsequence.
Example:
Input: arr = [100, 4, 200, 1, 3, 2]
Output: 4
Explanation: The longest consecutive subsequence is [1, 2, 3, 4]*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int LongestSubsequence(int *inputArray, int size) {
    int hash[100000] = {0}, sequence = 0;
    for (int i = 0; i < size; i++) {
        hash[inputArray[i]] = 1;
    }
    for (int i = 0; i < size; i++) {
        if (hash[inputArray[i] - 1] == 0) {
            int current = inputArray[i], count = 0;
            while (hash[current]) {
                count++;
                current++;
            }
            if (count > sequence) {
                sequence = count;
            }
        }
    }
    return sequence;
}

int main() {
    char input[200];
    scanf("%[^\n]", input);
    int inputArray[100], size = 0;
    char *ptr = strtok(input, "[, ]");

    while (ptr) {
        int element = atoi(ptr);
        inputArray[size] = element;
        ptr = strtok(NULL, "[, ]");
        size++;
    }

    int n = LongestSubsequence(inputArray, size);
    printf("%d", n);
    return 0;
}
