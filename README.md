# CIS165_Lab7- Min and Max

## Initial Plan
[REWRITE IN YOUR OWN WORDS. Draft based on my code:]
- Input: integers typed by the user, ended by the sentinel -99 (`SENTINEL`).
- Variables: `number` (current input), `largest`, `smallest`, `count` (how many real values were entered), and an array `values` of size `MAX_ENTRIES` to hold them.
- Steps: read the first number. If it is -99, print "No data values were entered." Otherwise set `largest` and `smallest` to that first number. Then loop while the number is not -99 and the array is not full: store the number, compare it to `largest` and `smallest`, and read the next number.
- Checks: -99 is tested before anything is stored or compared. The loop also stops if the array fills up.
- Output: the values entered, then the largest and smallest with labels, or the no-data message.

[KEEP ONLY IF TRUE: I wrote a first version of the code before writing this plan, then revised it.]

## Compile and Run
```
g++ -std=c++17 -Wall -Wextra min_max.cpp -o min_max
./min_max
```
[OR: describe how you ran it in OnlineGDB with C++17 selected.]

## Test Records
| # | Input | Expected | Actual output | Match? |
|---|---|---|---|---|
| 1 | 8, 3, 12, -99 | Smallest 3, largest 12 | [FILL IN] | [ ] |
| 2 | -8, -3, -12, -99 | Smallest -12, largest -3 | [FILL IN] | [ ] |
| 3 | 5, -99 | Smallest 5, largest 5 | [FILL IN] | [ ] |
| 4 | 0, 0, -99 | Smallest 0, largest 0 | [FILL IN] | [ ] |
| 5 | -99 | No-data message | [FILL IN] | [ ] |
| 6 (mine) | -3, 0, -7, -99 | Smallest -7, largest 0 | [FILL IN] | [ ] |

**Test 6 checks:** that a real 0 can be the largest value when every other entry is negative. It would fail if `largest` started at 0 and was never taken from the data.

**Errors fixed:** [Describe any bug you hit and the rerun. If you ran my corrected version only, write "None." If you ran your original first, you may have seen `-99` at the end of the values list, a `Largest A` typo, and a placeholder no-data message, which I fixed by only storing real values and correcting the labels.]

**Final check:** [Keep only if true: I recompiled and reran the final source before the final commit. I made no temporary test changes / I restored ___.]

## Explanation of My Code

**Tracing one series (-3, 0, -7, -99):**
- -3 is read first. It is not -99, so `largest = -3` and `smallest = -3`.
- The loop starts: `values[0] = -3`, `count = 1`. No extrema change.
- 0 is read, stored as `values[1]`. 0 > -3, so `largest = 0`.
- -7 is read, stored as `values[2]`. -7 < -3, so `smallest = -7`.
- -99 is read. The loop condition `number != SENTINEL` is false, so the loop ends and the program prints the values, largest 0, and smallest -7.

**How -99 stays out of the calculations:** The loop condition checks `number != SENTINEL` before the body runs. When -99 is read, the loop ends before it is stored or compared.

**Why initializing both to zero is wrong:** Zero may not be in the series. For -8, -3, -12, `largest` would stay 0, which was never entered. For an all-positive series, `smallest` would stay 0. Starting both from the first real value makes sure the answers come from the data.

**Empty series vs. a series containing zero:** I check whether the first number is -99. If it is, the series is empty and I print the no-data message. A series like `0, -99` starts with 0, so it is processed normally and gives smallest 0 and largest 0.

**Array note:** The array only supports displaying the values entered. The min/max logic does not depend on it.
