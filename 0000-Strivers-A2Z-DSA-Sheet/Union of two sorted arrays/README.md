# Union of two sorted arrays

## Problem Statement
<p>Given two sorted arrays <strong>nums1</strong> and <strong>nums2</strong>, return an array that contains the <strong>union</strong> of these two arrays. The elements in the union must be in ascending order.</p><p><br></p><p>The union of two arrays is an array where all values are distinct and are present in either the first array, the second array, or both.</p>

## Examples
<p class="tuf-text-14">Example 1</p><div class="tuf-example text-new_secondary"><p><strong>Input</strong>: nums1 = [1, 2, 3, 4, 5], nums2 = [1, 2, 7]</p><p><strong>Output</strong>: [1, 2, 3, 4, 5, 7]</p><p><strong>Explanation</strong>:</p><p>The elements 1, 2 are common to both, 3, 4, 5 are from nums1 and 7 is from nums2</p></div><br><br><p class="tuf-text-14 ">Example 2</p><div class="tuf-example text-new_secondary"><p><strong>Input</strong>: nums1 = [3, 4, 6, 7, 9, 9], nums2 = [1, 5, 7, 8, 8]</p><p><strong>Output</strong>: [1, 3, 4, 5, 6, 7, 8, 9]</p><p><strong>Explanation</strong>:</p><p>The element 7 is common to both, 3, 4, 6, 9 are from nums1 and 1, 5, 8 is from nums2</p></div><br><br><p class="tuf-text-14 ">Constraints</p><div class="tuf-dark-content-box"><ul><li>1 &lt;= nums1.length, nums2.length &lt;= 1000</li><li>-10<sup>4</sup> &lt;= nums1[i] , nums2[i] &lt;= 10<sup>4</sup></li><li>Both nums1 and nums2 are sorted in non-decreasing order</li></ul></div><br><br>

