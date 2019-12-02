echo "too few args and too many args"
./fillit
.fillit hauki on kala
echo "error checks"
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
./fillit validtest
./fillit validtest2
./fillit validtest3
echo speed tests
time ./fillit test1.prm
time ./fillit test7.prm
echo TA-DAA!!
