1. The goal is move all the disks from source to destination using temporary pegs. To move largest disk from source to destination first needs to put all n - 1 disks in temporary first then largest disk can be moved. The largest disk cannot move until all the disk on top of it is moved. And it can only move to a empty peg.
2. To remove n - 1 disks we need F(n - 1) moves to remove the top n - 1 disks first then largest disk will be moved to destination
3. After that n - 1 disks will again need to be moved to destination using F(n - 1) moves
4. So total move requires F(n - 1) + F(n - 1) + 1 which is less or equal to F(n) i.e. F(n) >= 2 * F(n - 1) + 1. Which can be calculated is 2ⁿ − 1
5. So, this way, its proved that total move required to move n disks is at least 2ⁿ − 1
