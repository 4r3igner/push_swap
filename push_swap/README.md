```markdown
# Push_swap: The Turk Hybrid

A highly optimized sorting algorithm designed to sort data on a stack, with a limited set of instructions, using the lowest possible number of actions. This implementation leverages a **Greedy Cost Analysis** (Turk Algorithm) paired with a **Binary Search Tree (BST)** for pre-indexation.

## 🚀 Performance Metrics
Validated against 100 random tests for each set size:

| Stack Size | 42 Project Requirement | This Implementation (Median) |
| :--- | :--- | :--- |
| **100 numbers** | < 700 moves | **537 moves** |
| **500 numbers** | < 5500 moves | **5097 moves** |

---

## 🧠 How It Works

The algorithm operates using a "Push-to-B, then Push-to-A" lifecycle, governed by a cost-minimization strategy.

### 1. Pre-Indexation (BST)
Before sorting begins, the raw integers are inserted into a **Binary Search Tree**. 
* **Purpose:** To assign a relative rank (index) to each number from `0` to `N-1`.
* **Benefit:** This simplifies mathematical comparisons and allows the cost engine to work with predictable magnitudes rather than massive integer values.

### 2. The Depletion Phase (A → B)
The algorithm pushes all but three nodes from Stack A into Stack B.
* **Targeting:** For every node in A, it identifies a "target node" in B (the closest smaller value).
* **Cost Analysis:** It calculates the "price" of moving a node to the top of A and its target to the top of B.
* **Synergy Optimization:** It prioritizes moves where both stacks can rotate in the same direction, using `rr` or `rrr` to "hide" the movement of one stack inside the other.

### 3. The "Sort Three" Anchor
When exactly three nodes remain in Stack A, a specialized hard-coded sort is triggered to order them in maximum 2 moves.

### 4. The Restoration Phase (B → A)
Nodes are pushed back from B to A by finding the "closest larger" target in A. This ensures the stack remains sorted as it grows.

### 5. Final Alignment
Once all nodes are in A, a final rotation sequence ensures that the smallest number (index 0) is at the top.

---

## 🛠️ Instructions Supported
| Op | Description |
| :--- | :--- |
| `sa`/`sb` | Swap the first 2 elements at the top of stack |
| `pa`/`pb` | Push the first element from one stack to the other |
| `ra`/`rb` | Shift up all elements of a stack by 1 |
| `rra`/`rrb`| Shift down all elements of a stack by 1 |
| `rr`/`rrr` | Simultaneous `r`/`rr` on both stacks |

---

## 💻 Usage

### Compilation
```bash
make
```

### Running the Sort
```bash
ARG="4 67 3 87 23"
./push_swap $ARG
```

### Visualizing Move Count
```bash
./push_swap $ARG | wc -l
```

### Verifying with Checker
```bash
./push_swap $ARG | ./checker_linux $ARG
```

---

## 📂 File Structure
* `target.c`: Logic for identifying target nodes in the opposite stack.
* `engine.c`: The cost calculation and cheapest move selector.
* `bst_controls.c`: Binary Search Tree implementation for indexation.
* `utils_2.c`: Execution of optimized synergy rotations (`rr`, `rrr`).

---
```
