bst_exe = executable('main.cpp.executable', 
    sources: ['main.cpp'],
    dependencies: bst,
    install : true)


test_bst_node_exe = executable('test_BSTNode.cpp.executable', 
    sources: ['test_BSTNode.cpp'], 
    dependencies : [bst, gtest_dep, util])
test('my BSTNode test', test_bst_node_exe)

test_bst_iterator_exe = executable('test_BSTIterator.cpp.executable', 
    sources: ['test_BSTIterator.cpp'], 
    dependencies : [bst, gtest_dep, util])
test('my BSTIterator test', test_bst_iterator_exe)

test_bst_exe = executable('test_BST.cpp.executable', 
    sources: ['test_BST.cpp'], 
    dependencies : [bst, gtest_dep, util])
test('my BST test', test_bst_exe)
