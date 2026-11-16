1. The goal is to transfer all disks from the source peg to the destination peg using an auxiliary peg. Before moving the largest disk, all $(n-1\$) disks above it must be moved to the auxiliary peg, leaving the destination peg empty for the largest disk.

2. Moving these $(n-1\$) disks requires at least $(F(n-1)\$) moves. Moving the largest disk to the destination then requires one additional move.

3. The $(n-1\$) smaller disks must then be transferred from the auxiliary peg to the destination peg, requiring at least another $(F(n-1)\$) moves.

4. Therefore, the minimum number of moves satisfies
$$
F(n)\ge F(n-1)+1+F(n-1)=2F(n-1)+1.
$$
5. Repeatedly applying this inequality, starting with $(F(0)=0\$), gives $(F(n)\$ge 2^n-1\).

6. Thus, transferring $(n\$) disks requires at least $(2^n-1\$) moves.
