echo "too few args and too many args"
./fillit
./fillit hauki on kala
echo "error checks"
./fillit error_5x5
./fillit error_42
./fillit error_blokcs
./fillit error_blocks2
./fillit error_blocksonly
./fillit error_crap
./fillit error_empty
./fillit error_lines
./fillit error_longline
./fillit error_newlineonly
./fillit error_noblocks
./fillit error_onelongline
./fillit error_shape
./fillit error_starrtnewline
./fillit error_stuck
./fillit error_test27
./fillit 2in1
./fillit bigpc
./fillit bigpcsqrd
./fillit dblnl
./fillit invpcsize
./fillit smpc
./fillit notsqrd
./fillit inv1pc
./fillit emptypc
./fillit nlatbgn
./fillit nonalchars
./fillit nonlatend
./fillit nonlbtwpc
./fillit plus27pcs
./fillit rejectfile
echo error checks finished
echo valid tests
./fillit easytest
echo 333 validtest 333
./fillit validtest
echo 333 validtest2 333
./fillit validtest2
echo 333 validtest3 333
./fillit validtest3
echo 333 fulleasy 333
./fillit fulleasy
echo 333 fullhard 333
./fillit fullhard
echo 333 two_squares 333
./fillit two_squares
echo 333 horizontal 333
./fillit horizontal
echo 333 random 333
./fillit random
echo 333 square 333
./fillit square
echo 333 test1 333
./fillit test1
echo 333 test2 333
./fillit test2
echo 333 test3 333
./fillit test3
echo 333 test4 333
./fillit test4
echo 333 test5 333
./fillit test5
echo 333 test6 333
./fillit test6
echo 333 test7 333
./fillit test7
echo 333 test8 333
./fillit test8
echo 333 test9 333
./fillit test9
echo 333 test10 333
./fillit test10
echo 333 test11 333
./fillit test11
echo 333 test12 333
./fillit test12
echo 333 test13 333
./fillit test13
echo 333 test14 333
./fillit test14
echo 333 test26 333
./fillit test26
echo 333 vertical 333
./fillit vertical
echo speed tests
time ./fillit test1.prm
time ./fillit test7.prm
time ./fillit test11
echo TA-DAA!!
