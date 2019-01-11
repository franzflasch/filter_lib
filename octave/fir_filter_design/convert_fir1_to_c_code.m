printf('\nInclude the following code in your C program to use the filter:\n\n')

printf('float coeffs[] = { \n') 
for row_idx = 1:rows 
	printf('%5.16f,\n', coeffs(row_idx)) 
end;
printf('};\n\n'); 

printf('#define NR_TAPS %d\n', rows) 
