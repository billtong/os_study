path=$1	# get the args one as path variable
if [ -z "$path" ]; then	# if there is no path then just set it as localpath
	path="."
fi
echo "Main files:"	# print out main files
hasMain=false	# set global variable hasMain as false
hasModule=false	# set global variable hasModuleFIle as false
hasOther=false	# set global variable hasOther as false
for f in `find $path -type f`; do
    full=`readlink -f $f`
    if (( `grep -c "^int main" $f` > 0 )); then	# to check if the file has string "int main"
		hasMain=true
		FPRINTF_COUNT=`grep -c "fprintf" $f`
        PRINTF_COUNT=$(( `grep -c "printf" $f` - $FPRINTF_COUNT ))
		printf "%s:%d,%d\n" $full $PRINTF_COUNT $FPRINTF_COUNT
    fi
done
if [ "$hasMain" = false ]; then
	echo "No main file"
fi
echo "Modules files:"

for f in `find $path -type f`; do
    full=`readlink -f $f`
    if (( `grep -c "^int init_module" $f` > 0 )); then	# to check if the file has string "int init_module"
		hasModule=true
        lineNumbers=`grep -n "printk" $f | cut -d : -f 1 | tr '\n' ','`
		lineNumbers=${lineNumbers%?}
		printf "%s:%s\n" $full $lineNumbers
    fi
done
if [ "$hasModule" = false ]; then
	echo "No module file"
fi
echo "Other files:"
for f in `find $path -type f`; do
    full=`readlink -f $f`
    if (( `grep -c "^int main" $f` == 0 )); then	# to check if the file don't have both "int main" and "initmodule"
		if (( `grep -c "^int init_module" $f` == 0 )); then
			hasOther=true
			printf "%s\n" $full
		fi
    fi
done
if [ "$hasOther" = false ]; then
	echo "No other file"
fi