# Kadane's Algorithm

## Problem Statement
<p>Given an integer array <strong>nums</strong>, find the subarray with the largest sum and return the sum of the elements present in that subarray.</p><p><br></p><p>A subarray is a contiguous non-empty sequence of elements within an array.</p>

## Examples
<p class="tuf-text-14">Example 1</p><div class="tuf-example text-new_secondary"><p><strong>Input</strong>: nums = [2, 3, 5, -2, 7, -4]</p><p><strong>Output</strong>: 15</p><p><strong>Explanation</strong>: </p><p>The subarray from index 0 to index 4 has the largest sum = 15</p></div><br><br><p class="tuf-text-14 ">Example 2</p><div class="tuf-example text-new_secondary"><p><strong>Input</strong>: nums = [-2, -3, -7, -2, -10, -4]</p><p><strong>Output</strong>: -2</p><p><strong>Explanation</strong>: </p><p>The element on index 0 or index 3 make up the largest sum when taken as a subarray</p></div><br><br><p class="tuf-text-14 ">Constraints</p><div class="tuf-dark-content-box"><ul><li>1 &lt;= nums.length &lt;= 10<sup>5</sup></li><li>-10<sup>4</sup> &lt;= nums[i] &lt;= 10<sup>4</sup></li></ul></div><br><br>

