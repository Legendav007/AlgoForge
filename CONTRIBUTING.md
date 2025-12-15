# Contribution Guidelines

Welcome to **AlgoForge**!
AlgoForge is a mentored open-source repository created as part of the **Winter of Open Source** initiative. The goal of this project is to build a high-quality collection of frequently used **algorithms and data structures** while helping contributors learn clean coding practices and open-source collaboration.

We encourage contributions from all skill levels.

---

## How to Contribute to AlgoForge

### Step 1: Fork the Repository

1. Fork this repository to your GitHub account.
2. Clone your forked repository to your local machine:

```bash
git clone https://github.com/your-username/AlgoForge.git
```

---

### Step 2: Choose an Algorithm

1. Browse the existing folders and check whether the algorithm you want to add already exists.
2. If it exists, add your implementation to the **same category folder**.
3. If it does not exist, you may create a new folder with an appropriate name.
4. Create an **Issue** describing the algorithm you want to add and wait until it is assigned.

---

### Step 3: Language Requirements

Contributions are encouraged in the following languages:

* **C++**
* **Java**
* **Python**

Guidelines:

* You may contribute in one or more languages
* Code must be correct, efficient, and readable
* Follow standard coding practices for the chosen language

---

### Step 4: Code Structure

For each algorithm, the folder may contain:

1. `algorithm_name.cpp`
2. `algorithm_name.java`
3. `algorithm_name.py`
4. `README.md` (optional but recommended)

   * Brief explanation of the algorithm
   * Time and space complexity

Each file should:

* Contain a clear implementation of the algorithm
* Include a small demonstration or example usage (where applicable)

#### Example Structure

```cpp
// C++ Example
#include <iostream>
using namespace std;

void algorithm() {
    // algorithm logic
}

int main() {
    algorithm();
    return 0;
}
```

```java
// Java Example
class Main {
    static void algorithm() {
        // algorithm logic
    }

    public static void main(String[] args) {
        algorithm();
    }
}
```

```python
# Python Example
def algorithm():
    # algorithm logic
    pass

if __name__ == "__main__":
    algorithm()
```

---

### Step 5: Update Roadmap.md

After creating your Pull Request:

* Check the corresponding algorithm in **Roadmap.md**
* If no relevant item exists, add a new checkbox under the appropriate section
* Add a **hyperlink** to the folder containing your implementation

> Note: The checklist should be updated **after your PR is merged**.

---

### Step 6: Submit a Pull Request

1. Push your changes to your forked repository
2. Open a Pull Request to the `main` branch

Ensure that:

* The PR description clearly explains the contribution
* Code follows proper naming conventions
* Files are placed in the correct folders
* Roadmap is updated correctly

Mentors will review your PR and may request changes before merging.

---

## Important Notes

* Avoid duplicate algorithms
* Write clean, readable code with meaningful variable names
* Add comments where necessary
* Be respectful and open to feedback

---

Thank you for contributing to **AlgoForge**.
Learn, build, and grow together through open source!
