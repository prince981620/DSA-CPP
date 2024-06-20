# using recursion 
- crate root Node
- root->left = recursion()
- root->right = recursion()

## assumption
i/p == -1 -> return NULL
i/p != -1 -> valid data

# lecvel order traversel

- push root into q
- store q.front into temp
- q.pop()
- print ans
- insert all child into q