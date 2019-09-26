kdt_exe = executable('main2.cpp.executable', 
    sources: ['main2.cpp'],
    dependencies: kdt,
    install : true)

efficiency_exe = executable('efficiencyTest.cpp.executable', 
    sources: ['efficiencyTest.cpp'],
    dependencies: kdt,
    install : true)

test_point_exe = executable('test_Point.cpp.executable', 
    sources: ['test_Point.cpp'], 
    dependencies : [kdt, gtest_dep, util])
test('my Point test', test_point_exe, timeout: 180)

test_kdt_exe = executable('test_KDT.cpp.executable', 
    sources: ['test_KDT.cpp'], 
    dependencies : [kdt, gtest_dep, util])
test('my KDT test', test_kdt_exe, timeout: 180)
