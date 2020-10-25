for((i=1;;i++));do
	echo $i
	./gen $i > in
	diff <(./a < in) <(./brute < in) || break
done
