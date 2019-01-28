
Given a collection of integers that might contain duplicates, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:

> Input: [1,2,2]  
> Output:  
> [  
>  [2],  
>  [1],  
>  [1,2,2],  
>  [2,2],  
>  [1,2],  
>  []  
> ] 


**Difficulty**:Medium
**Category**:  
*****

# Analyze
这道题目在`78 Subsets`的基础上添加了处理重复元素的部分，所以在这个位置需要对重复元素进程处理，需要保证不能有重复的子集出现在回答中。    